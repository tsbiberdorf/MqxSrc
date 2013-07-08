#ifndef __mcc_h__
#define __mcc_h__
/**HEADER********************************************************************
* 
* Copyright (c) 2013 Freescale Semiconductor;
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
* $FileName: mcc.h$
* $Version : 3.8.1.0$
* $Date    : Aug-1-2012$
*
* Comments:
*
*   This file contains the source for the common definitions for the
*   MCC pingpong example
*
*END************************************************************************/

#define MAIN_TTN               (10)
#define RESPONDER_TTN          (11)

#define MCC_MQX_NODE_A5        (0)
#define MCC_MQX_NODE_M4        (0)

#define MCC_MQX_SENDER_PORT    (1)
#define MCC_MQX_RESPONDER_PORT (2)

typedef struct the_message
{
   uint_32  DATA;
} THE_MESSAGE, _PTR_ THE_MESSAGE_PTR;

#endif
