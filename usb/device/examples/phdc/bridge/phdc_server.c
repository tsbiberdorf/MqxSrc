/**HEADER********************************************************************
* 
* Copyright (c) 2009 Freescale Semiconductor;
* All Rights Reserved                       
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
* $FileName: phdc_server.c$
* $Version : 3.8.6.0$
* $Date    : Sep-19-2012$
*
* Comments:
*
*END************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "phdc_server.h"
/*****************************************************************************
 * Constant and Macro's 
 *****************************************************************************/
_enet_address enet_local  = ENET_ENETADDR;
_ip_address   enet_ipaddr = ENET_IPADDR;
_ip_address   enet_ipmask = ENET_IPMASK;
/*****************************************************************************
 * Global Functions Prototypes
 *****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/
char Phdc_Task_Name[] = "PhdcSrv";
extern uint_8* abort_msg;
/*****************************************************************************
 * Local Types - None
 *****************************************************************************/

/*****************************************************************************
 * Local Functions Prototypes
 *****************************************************************************/

/*****************************************************************************
 * Local Variables 
 *****************************************************************************/
static USB_CLASS_CALLBACK g_phdcsrv_callback = NULL;
/* accept() function returns the new socket descriptor for the 
   accepted connection */
static uint_32 g_newsock = SOCK_UNINITIALIZED_VAL;
static boolean g_shutdown_connection = FALSE;

/*****************************************************************************
 * Local Functions
 *****************************************************************************/

/*****************************************************************************
 * Global Functions
 *****************************************************************************/
/******************************************************************************
 *
 *   @name        PhdcSrv_Task
 *
 *   @brief       This task empowers server to accepts connections from 
 *                new clients
 *
 *   @param       None
 *
 *   @return      None
 *****************************************************************************/
void PhdcSrv_Task(uint_32 param)
{
    _enet_handle ehandle;
    _rtcs_if_handle   ihandle;
    uint_32           error;

    /* a pointer to a sockaddr structure representing the 
       address to bind to */
    sockaddr_in    laddr;
    /* returns a file descriptor for the socket created for TCP */
    uint_32 listensock;
    /* a pointer to a sockaddr structure to receive the 
       client's address information*/
    sockaddr_in    raddr; 
    uint_16 rlen = sizeof(raddr);
    error = RTCS_create(); 
    if (error) 
    {
        #if _DEBUG
            printf("\nRTCS failed to initialize, error = %lX", error);
        #endif
        return;
    } 
      
    error = ENET_initialize(ENET_DEVICE, enet_local, 0, &ehandle);
    if (error) 
    {
        #if _DEBUG
            printf("\nENET initialize: %s", ENET_strerror(error));
        #endif  
        return;
    } 
      
    error = RTCS_if_add(ehandle, RTCS_IF_ENET, &ihandle);
    if (error) 
    {
        #if _DEBUG
            printf("\nIF add failed, error = %lx", error);
        #endif
        return; 
    }
    
    error = RTCS_if_bind(ihandle, enet_ipaddr, enet_ipmask);
    if (error) 
    {
        #if _DEBUG
            printf("\nIF bind failed, error = %lx", error);
        #endif  
        return;
    }
    
    /* Preapre a socket for communication with PHDC client */
    laddr.sin_family      = AF_INET;
    laddr.sin_port        = PHDC_SIN_PORT;
    laddr.sin_addr.s_addr = INADDR_ANY;
             
    /* Create TCP socket */
    listensock = socket(PF_INET, SOCK_STREAM, 0);
    if (listensock == RTCS_HANDLE_ERROR) 
    {
        #if _DEBUG
            printf("\nCreate stream socket failed");
        #endif
        return; 
    }

    /* Bind TCP socket */
    error = bind(listensock, &laddr, sizeof(laddr));
    if (error != RTCS_OK) 
    {
        #if _DEBUG
            printf("\nStream bind failed - 0x%x", error);
        #endif  
        return;
    } 
        
   /* Listen on TCP port */
    error = listen(listensock, 10); 
    if (error != RTCS_OK) 
    {
        #if _DEBUG
            printf("\nListen failed - 0x%x", error);
        #endif  
        return;
    }  
    
    while(g_shutdown_connection == FALSE)
    {
        #if _DEBUG
            printf("Waiting for client...\n"); 
        #endif
        
        g_newsock = accept(listensock, &raddr, &rlen);      
        if (g_newsock == RTCS_HANDLE_ERROR) 
        {
            #if _DEBUG
                printf("Accept failed, error 0x%x\n",   
                    RTCS_geterror(listensock));
            #endif                  
            continue;
        }       
        
        #if _DEBUG
            printf("Connection from %ld.%ld.%ld.%ld, port %d at socket 0x%x\n",
                (raddr.sin_addr.s_addr >> 24) & 0xFF,
                (raddr.sin_addr.s_addr >> 16) & 0xFF,
                (raddr.sin_addr.s_addr >>  8) & 0xFF,
                raddr.sin_addr.s_addr        & 0xFF,
                raddr.sin_port, g_newsock); 
        #endif  
        if(g_phdcsrv_callback != NULL)
        {
            g_phdcsrv_callback(BRIDGE_CONNECTION_ESTABLISHED,NULL,NULL);
        }
        _task_block();
    }
    
    shutdown(listensock, FLAG_CLOSE_TX);
    _task_abort(param);
}

/******************************************************************************
 *
 *   @name        Ethernet_Bridge_Init
 *
 *   @brief       This function initializes the Ethernet Bridge Interface and
 *                binds PHDC to RTCS library and creates a Socket
 *
 *   @param       None
 *
 *   @return      None
 *****************************************************************************/
void Ethernet_Bridge_Init(USB_CLASS_CALLBACK  callback)
{
    g_phdcsrv_callback = callback;  
}

/******************************************************************************
 *
 *   @name        Ethernet_Bridge_Open
 *
 *   @brief       Recv Data from PHDC client
 *
 *   @param       buff_ptr : address to receive data IN
 *                size :  size of data to recv
 *
 *   @return      None
 *****************************************************************************/
void Ethernet_Bridge_Open(uint_32 param)
{
    return;
}

/******************************************************************************
 *
 *   @name        Ethernet_Bridge_Recv
 *
 *   @brief       Recv Data from PHDC client
 *
 *   @param       buff_ptr : address to receive data IN
 *                size :  size of data to recv
 *
 *   @return      None
 *****************************************************************************/
void Ethernet_Bridge_Recv(uint_8_ptr buff_ptr, uint_32 size)
{   
    int_32 err;

    if(g_newsock == SOCK_UNINITIALIZED_VAL)
        return;
    
    err = recv(g_newsock, buff_ptr, size, 0); 
    if(err < RTCS_OK)  
    {
        if(err == -1)
        {
            g_newsock = SOCK_UNINITIALIZED_VAL;
            shutdown(g_newsock, FLAG_CLOSE_TX);
            Ethernet_Close_Connection();
        }
        else
        {
            #if _DEBUG
                printf("ETHERNET_BRIDGE_RECV ERROR: 0x%x\n", err);
            #endif
        }   
        return;
    }
    
    if(g_phdcsrv_callback != NULL)
    {
        USB_APP_EVENT_DATA_RECIEVED data_recv;
        data_recv.buffer_ptr = buff_ptr;
        data_recv.size = err;
        g_phdcsrv_callback(BRDIGE_DATA_RECEIVED, &data_recv, NULL);
    }
    
    return;
}

/******************************************************************************
 *
 *   @name        Ethernet_Bridge_Send
 *
 *   @brief       Send Data to PHDC client
 *
 *   @param       buff_ptr : address to send OUT data from
 *                size :  size of data to send
 *
 *   @return      None
 *****************************************************************************/
void Ethernet_Bridge_Send(uint_8_ptr buff_ptr, uint_32 size)
{   
    int_32 err;

    if(g_newsock == SOCK_UNINITIALIZED_VAL)
        return;
        
    err = send(g_newsock, buff_ptr, size, 0);

    if(err != size)
    {
        if(err == -1)
        {
            g_newsock = SOCK_UNINITIALIZED_VAL;
            shutdown(g_newsock, FLAG_CLOSE_TX);
            Ethernet_Close_Connection();
        }
        else
        {
            #if _DEBUG
                printf("Ethernet Bridge Send Failed\n");
                printf("Data to Send: %d Data Sent: %d\n", size, err);
            #endif              
        }           
        return;
    }
    
    if(g_phdcsrv_callback != NULL)
    {
        USB_APP_EVENT_DATA_RECIEVED data_send;
        data_send.buffer_ptr = buff_ptr;
        data_send.size = err;

        g_phdcsrv_callback(BRDIGE_DATA_SEND,&data_send, NULL);
    }
    return;
}

/******************************************************************************
 *
 *   @name        Ethernet_Close_Connection
 *
 *   @brief       Send Data to PHDC client
 *
 *   @param       buff_ptr : address to send OUT data from
 *                size :  size of data to send
 *
 *   @return      None
 *****************************************************************************/
void Ethernet_Close_Connection(void)
{   
    _task_id phdcsrv_task_id;  
    
    if(g_newsock != SOCK_UNINITIALIZED_VAL)
    {
        Ethernet_Bridge_Send(abort_msg, ABORT_MESSAGE_SIZE);
        shutdown(g_newsock, FLAG_CLOSE_TX); 
        g_newsock = SOCK_UNINITIALIZED_VAL;
    }
    
    if(g_phdcsrv_callback != NULL)
    {
        g_phdcsrv_callback(BRIDGE_CONNECTION_TERMINATED,NULL,NULL);
    }

    phdcsrv_task_id = _task_get_id_from_name(Phdc_Task_Name);
    if(phdcsrv_task_id == MQX_NULL_TASK_ID)
    {
        #if _DEBUG
            printf("TASK NOT FOUND IN TASK TEMPLATE\n");
        #endif
        return;
    }
    /* make PhdcSrv_Task ready as its in blocked state */
    _task_ready(_task_get_td(phdcsrv_task_id));
}

/* EOF */
