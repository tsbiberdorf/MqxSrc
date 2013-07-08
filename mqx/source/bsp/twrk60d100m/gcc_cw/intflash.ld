ENTRY(__boot)


/* 
using both, gnulib & ewl symbols
_cfm - to keep vectors.c variables
__init_hardware - must be used from bsp.a, not from librt.a
*/
EXTERN(_cfm __init_hardware)


MEMORY
{
    vectorrom   (RX): ORIGIN = 0x00000000, LENGTH = 0x00000400
    cfmprotrom  (R): ORIGIN = 0x00000400, LENGTH = 0x00000020
    rom         (RX): ORIGIN = 0x00000420, LENGTH = 0x0007FBE0  /* Code + Const data */
    ram         (RW): ORIGIN = 0x1FFF0000, LENGTH = 0x00020000  /* SRAM - RW data */
    
    /* kernel space starts after RAM variables (Location of MQX Kernel data + MQX heap) */
    end_of_kd   (RW): ORIGIN = 0x2000FFF0, LENGTH = 0x00000000
    
    /* Boot stack reused by MQX Kernel data */
    bstack      (RW): ORIGIN = 0x2000FA00, LENGTH = 0x00000200  /* Boot stack */
    end_bstack  (RW): ORIGIN = 0x2000FC00, LENGTH = 0x00000000  /* Boot stack end address requires 4B alignment */
}


SECTIONS
{
    __INTERNAL_SRAM_BASE  = 0x1FFF0000;
    __INTERNAL_SRAM_SIZE  = 0x00020000;
    
    __INTERNAL_FLASH_BASE = 0x00000000;
    __INTERNAL_FLASH_SIZE = 0x00080000;
    
    __INTERNAL_FLEXNVM_BASE = 0;
    __INTERNAL_FLEXNVM_SIZE = 0;
    
    __EXTERNAL_MRAM_BASE  = 0x70000000;
    __EXTERNAL_MRAM_SIZE  = 0x00080000;
    __EXTERNAL_MRAM_ROM_BASE = 0x70000000;
    __EXTERNAL_MRAM_ROM_SIZE = 0x00000000;
    __EXTERNAL_MRAM_RAM_BASE = 0x70000000;
    __EXTERNAL_MRAM_RAM_SIZE = 0x00080000;
    
    __EXTERNAL_LCD_BASE = 0x60000000;
    __EXTERNAL_LCD_SIZE = 0x1FFFF;
    __EXTERNAL_LCD_DC_BASE = 0x60010000;
    
    /* MQX link time configurations */
    __DEFAULT_PROCESSOR_NUMBER = 1;
    __DEFAULT_INTERRUPT_STACK_SIZE = 1024;
    __KERNEL_DATA_VERIFY_ENABLE = 0;    /* Test SDRAM read/write */
    
    /* Flashx configurations */
    __FLASHX_SECT_SIZE = 0x800;
    
    .vectors :
    {
        __vector_table = .;
        __VECTOR_TABLE_ROM_START = __vector_table;
        KEEP(*(.vectors_rom))
        . = ALIGN (0x4); 
    } > vectorrom
    
    .cfmprotect :
    {
        KEEP(*(.cfmconfig))
        . = ALIGN (0x4);
    } > cfmprotrom
    
    .text :
    {
        *(KERNEL)
        *(S_BOOT)
        *(IPSUM)
        *(.text*)
        *(.eh_frame)
        
        KEEP (*(.init))
        KEEP (*(.fini))

        . = ALIGN(0x4);
        *(.rodata*)
        . = ALIGN(0x4);
        *(.rdata*)
        . = ALIGN(0x4);
        *(.exception)
        . = ALIGN(0x4);
        __exception_table_start__ = .;
        __exception_table_end__ = .;
        __sinit__ = .;
    } > rom
    
    .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } > rom
    .ARM : {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > rom
    
    .ctors :
    {
        __CTOR_LIST__ = .;
        /* gcc uses crtbegin.o to find the start of
        the constructors, so we make sure it is
        first.  Because this is a wildcard, it
        doesn't matter if the user does not
        actually link against crtbegin.o; the
        linker won't look for a file to match a
        wildcard.  The wildcard also means that it
        doesn't matter which directory crtbegin.o
        is in.  */
        KEEP (*crtbegin.o(.ctors))
        /* We don't want to include the .ctor section from
        from the crtend.o file until after the sorted ctors.
        The .ctor section from the crtend file contains the
        end of ctors marker and it must be last */
        KEEP (*(EXCLUDE_FILE (*crtend.o ) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
        __CTOR_END__ = .;
    } > rom
    
    .dtors :
    {
        __DTOR_LIST__ = .;
        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o ) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
        __DTOR_END__ = .;
    } > rom
    
    .preinit_array :
    {
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*))
        PROVIDE_HIDDEN (__preinit_array_end = .);
    } > rom
    
    .init_array :
    {
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } > rom
    
    .fini_array :
    {
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array*))
        PROVIDE_HIDDEN (__fini_array_end = .);
    } > rom

    /* create _etext symbol which keep 
    relocation(execution) address of "code" end */
    _etext :
    {
        . = ALIGN(0x10);
        _etext = .; 
    } > rom
    
    .data : AT(_etext)
    {
        . = ALIGN(128);
        /* create _sdata symbol which keep 
        relocation(execution) address of data start */
        _sdata = .;
        __VECTOR_TABLE_RAM_START = .;
        KEEP(*(.vectors_ram))
        
        . = ALIGN(512);
        __BDT_BASE = .;
        *(.usb_bdt)
        __BDT_END = .;
        
        . = ALIGN(0x4);
        *(.exception)
        . = ALIGN(0x4);
        __exception_table_start__ = .;
        __exception_table_end__ = .;
        
        __START_DATA = .;
        *(.data*)
        __END_DATA = .;
        
        __START_SDATA = .;
        *(.sdata*)
        __END_SDATA = .;
        
        __SDA_BASE  = .;
        __SDA_BASE_ = __SDA_BASE;
        
        . = ALIGN(0x10);
        /* create _edata symbol which keep 
        relocation(execution) address of data end */
        _edata = .;
    } > ram
    
    .bss : 
    {
        . = ALIGN(0x10);
        __START_SBSS = .;
        *(.sbss*)
        *(SCOMMON)
        __END_SBSS = .;
        
        __START_BSS = .;
        __bss_start__ = __START_BSS;
        *(.bss*)
        *(COMMON)
        __END_BSS = .;
        __bss_end__ = __END_BSS;
        . = ALIGN(0x10);
    } > ram
    
    /* move "location counter" to next relocated address */
    . = ALIGN(0x10);
    
   .kernel_data : 
    {
        __KERNEL_DATA_START = ALIGN(0x10);
    }
    .end_of_kernel_data :
    {
        __KERNEL_DATA_END = .;
        __KERNEL_AREA_END = .;
    } > end_of_kd
    
    .boot_stack :
    {
        _stack_end = .;
    } > bstack
    
    .end_of_boot_stack :
    {
        _stack_addr  = .;
        _estack = _stack_addr;
        __SP_INIT = _stack_addr;
        __BOOT_STACK_ADDRESS = .;
    } > end_bstack
    
    /* fill "__S_romp" table with memory region(s) to perform "rom to ram copy" */
    _romp_at = _etext + SIZEOF(.data);
    .romp : AT(_romp_at)
    {
        __S_romp = _romp_at;
        LONG(_etext); /* source (rom) address */
        LONG(_sdata); /* target (ram) address */
        LONG(_edata - _sdata); /* size */
        /* null terminated */
        LONG(0);
        LONG(0);
        LONG(0);
    }
    
    /* user flash area starts here */
    _flashx_start = _etext + SIZEOF(.data) + SIZEOF(.romp);
    
    _flashx_start = __INTERNAL_FLASH_BASE + __FLASHX_SECT_SIZE;
    /* flashx working area spans across the whole rest of Flash memory */
    __FLASHX_START_ADDR = ((_flashx_start + __FLASHX_SECT_SIZE - 1) / __FLASHX_SECT_SIZE) * __FLASHX_SECT_SIZE;
    __FLASHX_END_ADDR = __INTERNAL_FLASH_BASE + __INTERNAL_FLASH_SIZE;
    
    _end = .;
}


