/**HEADER********************************************************************
*
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: sh_audio.c$
* $Version : 3.8.3.0$
* $Date    : Aug-9-2012$
*
* Comments:
*
*   This file contains the MQX shell commands for audio devices.
*
*END************************************************************************/
#include "sh_audio.h"
#include "sd_card.h"
#include "wav.h"
#include "shell.h"
#include <string.h>
#include <hwtimer.h>
#include "audio_speaker.h"

/******************************************************************************
* Global variables
*****************************************************************************/
FILE_PTR file_ptr;
extern volatile AUDIO_STREAM_DEVICE_STRUCT audio_stream;
extern char  device_direction;  /* audio speaker or audio microphone */
extern uint_32                                 packet_size;
extern USB_AUDIO_STREAM_DESC_FORMAT_TYPE_PTR   frm_type_desc;
extern uint_8                                  audio_state;
extern uint_8                                  sd_card_state;
extern uint_8                                  file_open_count;
extern HWTIMER                                 audio_timer;
/******************************************************************************
* Local variables
*****************************************************************************/
extern AUDIO_COMMAND audio_com;
extern uint_8 wav_buff[MAX_ISO_PACKET_SIZE];
/******************************************************************************
*   @name        Shell_play
*
*   @brief       Servers the play command
*
*   @param       None
*
*   @return      None
*
******************************************************************************
* This function is used to play an audio wav file
*****************************************************************************/
int_32 Shell_play(int_32 argc, char_ptr argv[])
{
    boolean print_usage, shorthelp = FALSE;
    uint_8 bSamFreqType_index;
    print_usage = Shell_check_help_request (argc, argv, &shorthelp);

    if (!print_usage)
    {
        WAVE_FILE_HEADER header;
        if (argc > 1)
        {
            /* stop the current file playing */
            if(AUDIO_PLAYING == audio_state)
            {
                audio_state = AUDIO_IDLE;
                hwtimer_stop(&audio_timer);
            }
            /* check the device is connected */
            if ((USB_DEVICE_INUSE != audio_stream.DEV_STATE)||(device_direction != USB_AUDIO_DEVICE_DIRECTION_IN))
            {
                printf("  Error: Audio Speaker is not connected\n");
                return (SHELL_EXIT_ERROR);
            }
            if (FillWaveHeader(argv[1], &header) != 0)
            {
                printf("  Error: Unable to open file: %s\n", argv[1]);
                return (SHELL_EXIT_ERROR);
            }
            if (strcmp(header.CHUNK_DESCRIPTOR.Format, "WAVE"))
            {
                printf("  Error: File is not WAVE file.\n");
                return (SHELL_EXIT_ERROR);
            }
            if (strcmp(header.FMT_SUBCHUNK.Subchunk1ID, "fmt "))
            {
                printf("  Error: File does not contain format subchunk.\n");
            }
            if (BYTESWAP16(header.FMT_SUBCHUNK.AudioFormat) != 1)
            {
                printf("  Error: File is compressed (not PCM).\n");
                return (SHELL_EXIT_ERROR);
            }
            if (strcmp(header.DATA_SUBCHUNK.Subchunk2ID, "data"))
            {
                printf("  Error: File does not contain data subchunk.\n");
                return (SHELL_EXIT_ERROR);
            }
            file_ptr = fopen(argv[1], "r");
            if (file_ptr == NULL)
            {
                printf("  Unable to open file: %s\n", argv[1]);
                return (SHELL_EXIT_ERROR);
            }
            file_open_count ++;
            printf("Audio file properties:\n");
            printf("   - Sample rate      : %d Hz\n", BYTESWAP32(header.FMT_SUBCHUNK.SampleRate));
            printf("   - Sample size      : %d bits\n", BYTESWAP16(header.FMT_SUBCHUNK.BitsPerSample));
            printf("   - Number of channels : %d channels\n", BYTESWAP16(header.FMT_SUBCHUNK.NumChannels));
            /* Compare the sample rate */
            for (bSamFreqType_index =0; bSamFreqType_index < frm_type_desc->bSamFreqType; bSamFreqType_index++)
            {
                if (((frm_type_desc->tSamFreq[3*bSamFreqType_index + 2] << 16) |
                            (frm_type_desc->tSamFreq[3*bSamFreqType_index + 1] << 8)  |
                            (frm_type_desc->tSamFreq[3*bSamFreqType_index] << 0)) == BYTESWAP32(header.FMT_SUBCHUNK.SampleRate))
                {
                    packet_size = USB_Audio_Get_Packet_Size(frm_type_desc,bSamFreqType_index);
                    break;
                }
            }
            if (bSamFreqType_index == frm_type_desc->bSamFreqType)
            {
                printf("  The audio device doesn't support that audio sample rate \n");
                return (SHELL_EXIT_ERROR);
            }
            /* Compare the bits sample number */
            if (frm_type_desc->bBitResolution != BYTESWAP16(header.FMT_SUBCHUNK.BitsPerSample))
            {
                printf("  The audio device doesn't support that audio bit sample number \n");
                return (SHELL_EXIT_ERROR);
            }
            /* Compare the channel number */
            if (frm_type_desc->bNrChannels != BYTESWAP16(header.FMT_SUBCHUNK.NumChannels))
            {
                printf("  The audio device doesn't support that audio channel number \n");
                return (SHELL_EXIT_ERROR);
            }
            fseek(file_ptr, WAVE_HEADER_SIZE, IO_SEEK_SET);
            audio_state = AUDIO_PLAYING;
            printf("  Playing...\n");
            hwtimer_start(&audio_timer);
        }
        else
        {
            if (AUDIO_PLAYING == audio_state)
            {
                printf("  The file is playing...\n");
            }
            else if (AUDIO_PAUSE == audio_state)
            {
                audio_state = AUDIO_PLAYING;
                hwtimer_start(&audio_timer);
                printf("  Playing...\n");
            }
            else if (AUDIO_IDLE == audio_state)
            {
                printf("  Not enough parameters.\n");
            }
        }
    }
    else
    {
        if (shorthelp)
        {
            printf("%s <filename>\n", argv[0]);
        }
        else
        {
            printf("Usage: %s <filename>\n", argv[0]);
            printf("   filename      = wav file to play\n");
        }
    }
    return(SHELL_EXIT_SUCCESS);
}
/******************************************************************************
*   @name        Shell_pause
*
*   @brief       Servers the pause command
*
*   @param       None
*
*   @return      None
*
******************************************************************************
* This function is used to pause the current playing file
*****************************************************************************/
int_32 Shell_pause_audio(int_32 argc, char_ptr argv[])
{
    boolean print_usage, shorthelp = FALSE;
    print_usage = Shell_check_help_request (argc, argv, &shorthelp);

    if (!print_usage)
    {
        if (argc > 1)
        {
            printf("  Error: This command doesn't need parameters\n");
            return (SHELL_EXIT_ERROR);
        }
        else
        {
            if(AUDIO_PLAYING == audio_state)
            {
                audio_state = AUDIO_PAUSE;
                printf("  Paused...\n");
                hwtimer_stop(&audio_timer);
            }
            else if (AUDIO_IDLE == audio_state)
            printf("  No file is playing!\n");
        }
    }

    if (print_usage)
    {
        if (shorthelp)
        {
            printf("%s\n", argv[0]);
        }
        else
        {
            printf("Usage: %s\n", argv[0]);
        }
    }
    return(SHELL_EXIT_SUCCESS);
}

/******************************************************************************
*   @name        Shell_mute
*
*   @brief       Servers the mute command
*
*   @param       None
*
*   @return      None
*
******************************************************************************
* This function is used to mute the audio device
*****************************************************************************/
int_32 Shell_mute(int_32 argc, char_ptr argv[])
{
    boolean         print_usage, shorthelp = FALSE;
    print_usage = Shell_check_help_request (argc, argv, &shorthelp);

    if (!print_usage)
    {
        if (argc > 1)
        {
            printf("  Error: This command doesn't need parameters\n");
            return (SHELL_EXIT_ERROR);
        }
        else
        {
            audio_mute_command();
        }
    }

    if (print_usage)
    {
        if (shorthelp)
        {
            printf("%s\n", argv[0]);
        }
        else
        {
            printf("Usage: %s\n", argv[0]);
        }
    }
    return(SHELL_EXIT_SUCCESS);
}

/******************************************************************************
*   @name        Shell_increase_volume
*
*   @brief       Servers the increase volume command
*
*   @param       None
*
*   @return      None
*
******************************************************************************
* This function is used to increase volume of the audio device
*****************************************************************************/
int_32 Shell_increase_volume(int_32 argc,char_ptr argv[])
{
    boolean         print_usage = FALSE, shorthelp = FALSE;
    print_usage = Shell_check_help_request (argc, argv, &shorthelp);
    if (!print_usage)
    {
        if (argc > 1)
        {
            printf ("  Error: Channel parameter is too large\n");
            return (SHELL_EXIT_ERROR);
        }
        else
        {
            audio_increase_volume_command();
        }
    }
    else
    {
        if (shorthelp)
        {
            printf("%s\n", argv[0]);
        }
        else
        {
            printf("Usage: %s\n", argv[0]);
        }
    }

    return(SHELL_EXIT_SUCCESS);
}

/******************************************************************************
*   @name        Shell_decrease_volume
*
*   @brief       Servers the decrease volume command
*
*   @param       None
*
*   @return      None
*
******************************************************************************
* This function is used to decrease volume of the audio device
*****************************************************************************/
int_32 Shell_decrease_volume(int_32 argc,char_ptr argv[])
{
    boolean         print_usage = TRUE, shorthelp = FALSE;
    volatile static uint_16         cur_volume, min_volume;
    print_usage = Shell_check_help_request (argc, argv, &shorthelp);
    if (!print_usage)
    {
        if (argc > 1)
        {
            printf ("  Error: Channel parameter is too large\n");
            return (SHELL_EXIT_ERROR);
        }
        else
        {
            audio_decrease_volume_command();
        }
    }
    else
    {
        if (shorthelp)
        {
            printf("%s\n", argv[0]);
        }
        else
        {
            printf("Usage: %s\n", argv[0]);
        }
    }

    return(SHELL_EXIT_SUCCESS);
}
/* EOF */
