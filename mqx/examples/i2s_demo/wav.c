/*
**************************************************************************
*
* $FileName: wav.c$
* $Version : 3.8.6.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains code for operations with WAVE files 
*
*END************************************************************************/

#include <mqx.h>
#include <fio.h>
#include "wav.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*FUNCTION****************************************************************
* 
* Function Name    : GetWaveHeader
* Returned Value   : Zero if everything is ok, non zero otherwise
* Comments         :
*    This function reads wave file header and saves it into struct for
*    further usage.
*
*END*********************************************************************/

_mqx_int GetWaveHeader
   (
    /* [IN] file to read header from */
    char_ptr filename, 
                       
    /* [OUT] header pointer to save header to */
    WAVE_FILE_HEADER_PTR header
   )
{  
   FILE_PTR file;
   uchar def[] = {sizeof(header->CHUNK_DESCRIPTOR.ChunkSize), 0};
   WAVE_CHUNK_DESCRIPTOR_PTR ch_des = &(header->CHUNK_DESCRIPTOR);
   WAVE_FMT_SUBCHUNK_PTR fmt_sch = &(header->FMT_SUBCHUNK);
   WAVE_DATA_SUBCHUNK_PTR data_sch = &(header->DATA_SUBCHUNK);
   uint_32 retval = 0;
   file = fopen(filename, "rb");
   if (file == NULL)
   {
      return(-1);
   }
   /* First chunk (descriptor) */
   retval = fread(&(ch_des->ChunkID), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   ch_des->ChunkID[4] = '\0'; 
   retval = fread(&(ch_des->ChunkSize), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      _mem_swap_endian(def, &(ch_des->ChunkSize));
   }
   retval = fread(&(ch_des->Format), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   ch_des->Format[4] = '\0';
   /* Second chunk (format) */
   retval = fread(&(fmt_sch->Subchunk1ID), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   fmt_sch->Subchunk1ID[4] = '\0';
   retval = fread(&(fmt_sch->Subchunk1Size), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(fmt_sch->Subchunk1Size);
      _mem_swap_endian(def, &(fmt_sch->Subchunk1Size));
   }
   retval = fread(&(fmt_sch->AudioFormat), 1, 2, file);
   if (retval < 2)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(fmt_sch->AudioFormat);
      _mem_swap_endian(def, &(fmt_sch->AudioFormat));
   }
   retval = fread(&(fmt_sch->NumChannels), 1, 2, file);
   if (retval < 2)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(fmt_sch->NumChannels);
      _mem_swap_endian(def, &(fmt_sch->NumChannels));
   }
   retval = fread(&(fmt_sch->SampleRate), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(fmt_sch->SampleRate);
      _mem_swap_endian(def, &(fmt_sch->SampleRate));
   }
   retval = fread(&(fmt_sch->ByteRate), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(fmt_sch->ByteRate);
      _mem_swap_endian(def, &(fmt_sch->ByteRate));
   }
   retval = fread(&(fmt_sch->BlockAlign), 1, 2, file);
   if (retval < 2)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(fmt_sch->BlockAlign);
      _mem_swap_endian(def, &(fmt_sch->BlockAlign));
   }
   retval = fread(&(fmt_sch->BitsPerSample), 1, 2, file);
   if (retval < 2)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(fmt_sch->BitsPerSample);
      _mem_swap_endian(def, &(fmt_sch->BitsPerSample)); 
   }
   retval = fread(&(data_sch->Subchunk2ID), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Third chunk (data) */
   data_sch->Subchunk2ID[4] = '\0';
   retval = fread(&(data_sch->Subchunk2Size), 1, 4, file);
   if (retval < 4)
   {
       return(-1); 
   }
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(data_sch->Subchunk2Size);
      _mem_swap_endian(def, &(data_sch->Subchunk2Size));
   }
   fclose(file);
   return(0);
}


/*FUNCTION****************************************************************
* 
* Function Name    : SetWaveHeader
* Returned Value   : Zero if everything is ok, non zero otherwise
* Comments         :
*    This function creates header according to format and writes it into
*    output file.
*
*END*********************************************************************/

_mqx_int SetWaveHeader
   (
    /* [IN] format (length_in_seconds:sampling_freq:bit_depth:channels) */
    char_ptr format, 
    
    /* [OUT] header pointer to save header */
    WAVE_FILE_HEADER_PTR header, 
    
    /* [IN] file for writing */
    char_ptr filename
   )
{
   int_32 values[4];
   uint_32 tmp32 = 0;
   uint_16 tmp16 = 0;
   uint_8 i = 0;
   char_ptr tmp;
   FILE_PTR file_ptr;
   uchar def[] = {0, 0};
   uint_32 retval = 0;
   WAVE_CHUNK_DESCRIPTOR_PTR ch_des = &(header->CHUNK_DESCRIPTOR);
   WAVE_FMT_SUBCHUNK_PTR fmt_sch = &(header->FMT_SUBCHUNK);
   WAVE_DATA_SUBCHUNK_PTR data_sch = &(header->DATA_SUBCHUNK);
   file_ptr = fopen(filename, "w");   
   if (file_ptr == NULL)
   {
      return(-1);
   }
   tmp = strtok(format, ":");
   while ((tmp != NULL) || (i < 4))
   {
      values[i] = atoi(tmp);
      if ((values[i] <= 0) || (values[i] == INT_MAX))
      {
         return(-2);
      }  
      tmp = strtok(NULL, ":");
      i++;
   }
   /* Fill header */
   strcpy(ch_des->ChunkID, "RIFF");
   strcpy(ch_des->Format, "WAVE");
   strcpy(fmt_sch->Subchunk1ID, "fmt ");
   fmt_sch->Subchunk1Size = 16;
   fmt_sch->AudioFormat = 1;
   fmt_sch->NumChannels = values[3];
   fmt_sch->SampleRate = values[1];
   fmt_sch->BitsPerSample = values[2];
   fmt_sch->ByteRate = fmt_sch->SampleRate * fmt_sch->NumChannels * fmt_sch->BitsPerSample/8;
   fmt_sch->BlockAlign = fmt_sch->NumChannels * fmt_sch->BitsPerSample/8;
   strcpy(data_sch->Subchunk2ID, "data");
   data_sch->Subchunk2Size = values[0] * fmt_sch->SampleRate * fmt_sch->NumChannels * fmt_sch->BitsPerSample/8;
   ch_des->ChunkSize = 4 + (8 + fmt_sch->Subchunk1Size) + (8 + data_sch->Subchunk2Size);
   
   /* Write header to file */
   /* Chunk descriptor  ("RIFF" string)*/
   retval = fwrite(&(ch_des->ChunkID), 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Chunk size */
   tmp32 = ch_des->ChunkSize;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp32);
      _mem_swap_endian(def, &(tmp32));
   }
   retval = fwrite(&tmp32, 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Format ("WAVE" string) */
   retval = fwrite(&(ch_des->Format), 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Format subchunk */
   retval = fwrite(&(fmt_sch->Subchunk1ID), 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Subchunk size */
   tmp32 = fmt_sch->Subchunk1Size;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp32);
      _mem_swap_endian(def, &(tmp32));
   }
   retval = fwrite(&tmp32, 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /*  Audio format */
   tmp16 = fmt_sch->AudioFormat;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp16);
      _mem_swap_endian(def, &(tmp16));
   }
   retval = fwrite(&tmp16, 1, 2, file_ptr);
   if (retval < 2)
   {
       return(-1); 
   }
   /* Number of channels */
   tmp16 = fmt_sch->NumChannels;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp16);
      _mem_swap_endian(def, &(tmp16));
   }
   retval = fwrite(&tmp16, 1, 2, file_ptr);
   if (retval < 2)
   {
       return(-1); 
   }
   /* Sample rate */
   tmp32 = fmt_sch->SampleRate;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp32);
      _mem_swap_endian(def, &(tmp32));
   }
   retval = fwrite(&tmp32, 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Byte rate */
   tmp32 = fmt_sch->ByteRate;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp32);
      _mem_swap_endian(def, &(tmp32));
   }
   retval = fwrite(&tmp32, 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Block align */
   tmp16 = fmt_sch->BlockAlign;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp16);
      _mem_swap_endian(def, &(tmp16));
   }
   retval = fwrite(&tmp16, 1, 2, file_ptr);
   if (retval < 2)
   {
       return(-1); 
   }
   /* Bit depth */
   tmp16 = fmt_sch->BitsPerSample;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp16);
      _mem_swap_endian(def, &(tmp16));
   }
   retval = fwrite(&tmp16, 1, 2, file_ptr);
   if (retval < 2)
   {
       return(-1); 
   }
   /* Data subchunk */
   retval = fwrite(&(data_sch->Subchunk2ID), 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   /* Subchunk size */
   tmp32 = data_sch->Subchunk2Size;
   if (PSP_ENDIAN == MQX_BIG_ENDIAN)
   {
      def[0] = sizeof(tmp32);
      _mem_swap_endian(def, &(tmp32));
   }
   retval = fwrite(&tmp32, 1, 4, file_ptr);
   if (retval < 4)
   {
       return(-1); 
   }
   fclose(file_ptr);
   return(0);
}
/* EOF */
