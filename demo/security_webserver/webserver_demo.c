                /**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
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
* $FileName: webserver_demo.c$
* $Version : 3.8.29.0$
* $Date    : Aug-2-2012$
*
* Comments:
*
*   
*
*END************************************************************************/


#include <mqx.h>
#include <bsp.h>
#include <rtcs.h>
#include <ipcfg.h>
#include <httpd.h>
#include <httpd_types.h>
#include <tfs.h>
#include "security_private.h"
#include "security_public.h"
#include "security.h"

#error This demo is obsolete and has known issues. It is not supported in MQX 4.0.1 and will be removed in future MQX version.
#error For HTTP server example please see %MQX_ROOT%\rtcs\examples\httpdsrv.

#if !BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif

#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif

#if !ENABLE_ADC
#error This application requires BSPCFG_ENABLE_ADC defined non-zero in user_config.h. Please recompile BSP with this option.
#endif

extern const HTTPD_CGI_LINK_STRUCT cgi_lnk_tbl[];
extern const TFS_DIR_ENTRY tfs_data[];

enum {
   MAIN_TASK=1,
   IO_TASK
};

void Main_Task(uint_32);
void io_task(uint_32);




#if PSP_MQX_CPU_IS_MCF51CN

const TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
    /* Task Index,  Function,  Stack,  Priority,    Name,       Attributes,             Param,  Time Slice */
    {MAIN_TASK,     Main_Task,  1700,     8,        "Main",     MQX_AUTO_START_TASK,    0,      0           },
    {IO_TASK,       io_task,     500,     7,        "IO poll",  0,                      0,      0           },
    {0}
};

#else // PSP_MQX_CPU_IS_MCF51CN

const TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
    /* Task Index,  Function,  Stack,  Priority,    Name,       Attributes,             Param,  Time Slice */
    {MAIN_TASK,     Main_Task,  3000,     8,        "Main",     MQX_AUTO_START_TASK,    0,      0           },
    {IO_TASK,       io_task,    1000,     7,        "IO poll",  0,                      0,      0           },
    {0}
};

#endif // PSP_MQX_CPU_IS_MCF51CN



const HTTPD_ROOT_DIR_STRUCT root_dir[] =
{
    { "", "tfs:" },
    { 0, 0 }
};



void Main_Task(uint_32 initial_data)
{
   HTTPD_STRUCT *    server;
   int_32            error;
   
#if RTCSCFG_ENABLE_IP6
   IPCFG6_GET_ADDR_DATA    data[RTCSCFG_IP6_IF_ADDRESSES_MAX];
   char prn_addr6[sizeof "ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255"];
   uint_32 n=0,i=0;
#endif   

   SEC_Initialize();
 
   _task_create(0, IO_TASK, 0); // start io task

   SEC_InitializeNetworking(5, 6, 4, DEMOCFG_ENABLE_DHCP);

   /* Set up Trival File System to server webpages */            
   if ((error = _io_tfs_install("tfs:", tfs_data)) != 0) 
   {
      printf("\nTFS install returned: %08x\n", error);
   }



#if RTCSCFG_ENABLE_IP6
        server = httpd_server_init_af((HTTPD_ROOT_DIR_STRUCT*)root_dir, "\\mqx.html",AF_INET6);

        if(server)
        {
            HTTPD_SET_PARAM_CGI_TBL(server, (HTTPD_CGI_LINK_STRUCT*)cgi_lnk_tbl); 
            httpd_server_run(server);
        }
        else
        {
            printf("Error: Server IPv6 init error.\n");
        }

        /* 
        **  For information purpose only. 
        **  You can see generated and assigned IPv6 address.
        */
        n=0;
        while(!ipcfg6_get_addr_info_n (BSP_DEFAULT_ENET_DEVICE, n,&data[n]))
        {
            n++;
        }   
	    i=0;
  	    while(i<n)
  	    {
  	        if(inet_ntop(AF_INET6,&data[i].ip_addr, prn_addr6, sizeof(prn_addr6)))
		    {
		        printf("IP6 : %s \n",prn_addr6);
            }
            i++;
        }
#endif

#if RTCSCFG_ENABLE_IP4

    server = httpd_server_init((HTTPD_ROOT_DIR_STRUCT*)root_dir, "\\mqx.html");

    if(server)
    {
        HTTPD_SET_PARAM_CGI_TBL(server, (HTTPD_CGI_LINK_STRUCT*)cgi_lnk_tbl);
    #if HTTPDCFG_POLL_MODE
        while (1) 
        {
              /* Poll Webserver */
            httpd_server_poll(server, -1);
        }
    #else
        httpd_server_run(server);
        _task_block();
    #endif    
    }
    else
    {
        printf("Error: Server IPv4 init error.\n");
        _task_block();
    }
#endif
    
    _task_block();

}

/* Security task */
void io_task(uint_32 temp) {
   while (1) {
      Input_Poll();
      _time_delay(200);
   }
}
