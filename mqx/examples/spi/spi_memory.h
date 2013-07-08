#ifndef __spi_memory_h__
#define __spi_memory_h__
/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: spi_memory.h$
* $Version : 3.8.1.0$
* $Date    : Sep-25-2012$
*
* Comments:
*
*   This file contains definitions for the SPI memory example.
*
*END************************************************************************/


/* Number of bytes used for addressing within memory */
#define SPI_MEMORY_ADDRESS_BYTES       3

/* Memory page size - maximum bytes per write */
#define SPI_MEMORY_PAGE_SIZE           0x0100   

/* The SPI serial memory instructions */
#define SPI_MEMORY_WRITE_STATUS        0x01
#define SPI_MEMORY_WRITE_DATA          0x02
#define SPI_MEMORY_READ_DATA           0x03
#define SPI_MEMORY_WRITE_LATCH_DISABLE 0x04
#define SPI_MEMORY_READ_STATUS         0x05
#define SPI_MEMORY_WRITE_LATCH_ENABLE  0x06
#define SPI_MEMORY_CHIP_ERASE          0xC7


/* Funtion prototypes */

extern void    memory_chip_erase (MQX_FILE_PTR spifd);
extern void    memory_set_write_latch (MQX_FILE_PTR spifd, boolean enable);
extern void    memory_set_protection (MQX_FILE_PTR spifd, boolean protect);
extern uint_8  memory_read_status (MQX_FILE_PTR spifd);
extern void    memory_write_byte (MQX_FILE_PTR spifd, uint_32 addr, uchar data);
extern uint_8  memory_read_byte (MQX_FILE_PTR spifd, uint_32 addr);
extern uint_32 memory_write_data (MQX_FILE_PTR spifd, uint_32 addr, uint_32 size, uchar_ptr data);
extern uint_32 memory_read_data (MQX_FILE_PTR spifd, uint_32 addr, uint_32 size, uchar_ptr data);


#endif
