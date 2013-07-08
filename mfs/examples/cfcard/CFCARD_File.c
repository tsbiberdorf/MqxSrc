/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
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
* $FileName: CFCARD_File.c$
* $Version : 3.8.8.0$
* $Date    : Aug-2-2012$
*
* Comments:
*
*   This file contains the initialization  for Compact Flash card
*
*END************************************************************************/

#include "Shell_Task.h"
#include "CFCard_File.h"


/*TASK*-----------------------------------------------------------------
*
* Function Name  : CF_filesystem_install
* Returned Value : void
* Comments       : Install filesystem on given pccard file pointer
*
*END------------------------------------------------------------------*/
FS_STRUCT_PTR CF_filesystem_install( 
    MQX_FILE_PTR pccard_fp,
    char_ptr    partition_manager_name,
    char_ptr    file_system_name )
{
    uint_32                    partition_number;
    int_32                     error_code;
    FS_STRUCT_PTR  fs_ptr;

                              
    fs_ptr = _mem_alloc_system_zero(sizeof(FS_STRUCT));
    if (fs_ptr==NULL)
    {
        return NULL;
    }
    
    /* Open CF card */
    fs_ptr->DEV_FD_PTR = fopen("pcflasha:", (char_ptr) pccard_fp);
    if (fs_ptr->DEV_FD_PTR == NULL)
    {
        printf("Unable to open CF card.\n");
        return NULL;
    }
    
    /* Set block mode */
    error_code = ioctl(fs_ptr->DEV_FD_PTR, PCFLASH_IOCTL_SET_BLOCK_MODE, NULL);
    if (error_code != IO_OK)
    {
        printf("Block mode not enabled. Running in byte mode.\n");
    }
    
    /* Try to install partition manager */
    error_code = _io_part_mgr_install(fs_ptr->DEV_FD_PTR, partition_manager_name, 0);
    if (error_code != MFS_NO_ERROR)
    {
        printf("Error while initializing partition manager: %s\n", MFS_Error_text((uint_32)error_code));
        CF_filesystem_uninstall(fs_ptr);
        return NULL;
    }
    fs_ptr->PM_NAME = partition_manager_name;
    
    /* Open partition manager */
    fs_ptr->PM_FD_PTR = fopen(partition_manager_name, NULL);
    if (fs_ptr->PM_FD_PTR == NULL)
    {
        error_code = ferror(fs_ptr->PM_FD_PTR);
        printf("Error while opening partition manager: %s\n", MFS_Error_text((uint_32)error_code));
        CF_filesystem_uninstall(fs_ptr);
        return NULL;
    }
    
    /* Select partition */
    partition_number = 1;
    error_code = _io_ioctl(fs_ptr->PM_FD_PTR, IO_IOCTL_SEL_PART, &partition_number);
    
    if (error_code == MFS_NO_ERROR)
    {
        printf("Installing MFS over partition...\n");

        /* Validate partition */
        error_code = _io_ioctl(fs_ptr->PM_FD_PTR, IO_IOCTL_VAL_PART, NULL);
        if (error_code != MFS_NO_ERROR)
        {
            printf("Error while validating partition: %s\n", MFS_Error_text((uint32_t)error_code));
            printf("Not installing MFS.\n");
            CF_filesystem_uninstall(fs_ptr);
            return NULL;
        }
        
        /* Install MFS over partition */
        error_code = _io_mfs_install(fs_ptr->PM_FD_PTR, file_system_name, 0);
        if (error_code != MFS_NO_ERROR)
        {
            printf("Error initializing MFS over partition: %s\n", MFS_Error_text((uint_32)error_code));
        }
    }
    else
    {
        printf("Installing MFS over CF card driver...");
        
        /* Install MFS over CF card driver */
        error_code = _io_mfs_install(fs_ptr->DEV_FD_PTR, file_system_name, 0);
        if (error_code != MFS_NO_ERROR)
        {
            printf("Error initializing MFS: %s\n", MFS_Error_text((uint_32)error_code));
        }
    }
    
    /* Open file system */
    if (error_code == MFS_NO_ERROR)
    {
    	fs_ptr->FS_NAME = file_system_name;
    	fs_ptr->FS_FD_PTR = fopen(file_system_name, NULL);
    	error_code = ferror(fs_ptr->FS_FD_PTR);
    	if (error_code == MFS_NOT_A_DOS_DISK)
    	{
    	    printf("NOT A DOS DISK! You must format to continue.\n");
    	}
    	else if (error_code != MFS_NO_ERROR)
    	{
    	    printf("Error opening filesystem: %s\n", MFS_Error_text((uint_32)error_code));
    	    CF_filesystem_uninstall(fs_ptr);
    	    return NULL;
    	}
    	
    	printf("CF card installed to %s\n", file_system_name); 
    }
    else {
    	CF_filesystem_uninstall(fs_ptr);
    	return NULL;
    }
    
    return (pointer)fs_ptr;
}



/*TASK*-----------------------------------------------------------------
*
* Function Name  : CF_filesystem_uninstall
* Returned Value : void
* Comments       : Uninstall filesystem
*
*END------------------------------------------------------------------*/
void CF_filesystem_uninstall( FS_STRUCT_PTR  fs_ptr)
{
    int_32                     error_code;

    if (fs_ptr == NULL) {
        return;
    }
   
    /* Close filesystem */
    if ((fs_ptr->FS_FD_PTR != NULL) && (MQX_OK != fclose(fs_ptr->FS_FD_PTR)))
    {
        printf("Error while closing filesystem.\n");
    }
   
    /* Uninstall MFS */
    error_code = _io_dev_uninstall(fs_ptr->FS_NAME);
    if (error_code != MFS_NO_ERROR)
    {
        printf("Error while uninstalling filesystem.\n");
    }
    
    /* Close partition */
    if ((fs_ptr->PM_FD_PTR != NULL) && (MQX_OK != fclose(fs_ptr->PM_FD_PTR)))
    {
        printf("Error while closing partition.\n");
    }
    
    /* Unisnstall partition manager */
    error_code = _io_dev_uninstall(fs_ptr->PM_NAME);
    if (error_code != MFS_NO_ERROR)
    {
        printf("Error while uninstalling partition manager.\n");
    }
    
    /* Close CF card */
    if ((fs_ptr->DEV_FD_PTR != NULL) && (MQX_OK != fclose(fs_ptr->DEV_FD_PTR)))
    {
        printf("Unable to close CF card.\n");
    }
    
    _mem_free(fs_ptr);
}



/* EOF */
