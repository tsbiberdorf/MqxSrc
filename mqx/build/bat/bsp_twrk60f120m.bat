@echo off

rem convert path to backslash format
set MQXROOTDIR=%1
set MQXROOTDIR=%MQXROOTDIR:/=\%
set OUTPUTDIR=%2
set OUTPUTDIR=%OUTPUTDIR:/=\%
set TOOL=%3

rem remove processor expert files if exists
IF EXIST %OUTPUTDIR%\Generated_Code rd /S /Q %OUTPUTDIR%\Generated_Code
IF EXIST %OUTPUTDIR%\Sources rd /S /Q %OUTPUTDIR%\Sources

rem copy common files
IF NOT EXIST %OUTPUTDIR% mkdir %OUTPUTDIR%
IF NOT EXIST %OUTPUTDIR%\.. mkdir %OUTPUTDIR%\..
IF NOT EXIST %OUTPUTDIR%\Generated_Code mkdir %OUTPUTDIR%\Generated_Code
copy %MQXROOTDIR%\config\common\maximum_config.h %OUTPUTDIR%\..\maximum_config.h /Y
copy %MQXROOTDIR%\config\common\small_ram_config.h %OUTPUTDIR%\..\small_ram_config.h /Y
copy %MQXROOTDIR%\config\common\smallest_config.h %OUTPUTDIR%\..\smallest_config.h /Y
copy %MQXROOTDIR%\config\common\verif_enabled_config.h %OUTPUTDIR%\..\verif_enabled_config.h /Y
copy %MQXROOTDIR%\config\twrk60f120m\user_config.h %OUTPUTDIR%\..\user_config.h /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\bsp.h %OUTPUTDIR%\bsp.h /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\bsp_cm.h %OUTPUTDIR%\bsp_cm.h /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\bsp_rev.h %OUTPUTDIR%\bsp_rev.h /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\init_lpm.h %OUTPUTDIR%\init_lpm.h /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\PE_LDD.h %OUTPUTDIR%\Generated_Code\PE_LDD.h /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\PE_Types.h %OUTPUTDIR%\Generated_Code\PE_Types.h /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\twrk60f120m.h %OUTPUTDIR%\twrk60f120m.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx.h %OUTPUTDIR%\mqx.h /Y
copy %MQXROOTDIR%\mqx\source\io\adc\adc.h %OUTPUTDIR%\adc.h /Y
copy %MQXROOTDIR%\mqx\source\io\adc\adc_conf.h %OUTPUTDIR%\adc_conf.h /Y
copy %MQXROOTDIR%\mqx\source\io\adc\kadc\adc_kadc.h %OUTPUTDIR%\adc_kadc.h /Y
copy %MQXROOTDIR%\mqx\source\io\adc\kadc\adc_mk60.h %OUTPUTDIR%\adc_mk60.h /Y
copy %MQXROOTDIR%\mqx\source\io\can\flexcan\kflexcan.h %OUTPUTDIR%\kflexcan.h /Y
copy %MQXROOTDIR%\mqx\source\io\cm\cm.h %OUTPUTDIR%\cm.h /Y
copy %MQXROOTDIR%\mqx\source\io\cm\cm_kinetis.h %OUTPUTDIR%\cm_kinetis.h /Y
copy %MQXROOTDIR%\mqx\source\io\crc\crc_kn.h %OUTPUTDIR%\crc_kn.h /Y
copy %MQXROOTDIR%\mqx\source\io\debug\iodebug.h %OUTPUTDIR%\iodebug.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\enet.h %OUTPUTDIR%\enet.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\enet_rev.h %OUTPUTDIR%\enet_rev.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\enet_wifi.h %OUTPUTDIR%\enet_wifi.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\ethernet.h %OUTPUTDIR%\ethernet.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\macnet\macnet_1588.h %OUTPUTDIR%\macnet_1588.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\macnet\macnet_mk60.h %OUTPUTDIR%\macnet_mk60.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\macnet\macnet_rev.h %OUTPUTDIR%\macnet_rev.h /Y
copy %MQXROOTDIR%\mqx\source\io\enet\phy\phy_ksz8041.h %OUTPUTDIR%\phy_ksz8041.h /Y
copy %MQXROOTDIR%\mqx\source\io\esdhc\esdhc.h %OUTPUTDIR%\esdhc.h /Y
copy %MQXROOTDIR%\mqx\source\io\flashx\flashx.h %OUTPUTDIR%\flashx.h /Y
copy %MQXROOTDIR%\mqx\source\io\flashx\freescale\flash_ftfe.h %OUTPUTDIR%\flash_ftfe.h /Y
copy %MQXROOTDIR%\mqx\source\io\flashx\freescale\flash_mk60.h %OUTPUTDIR%\flash_mk60.h /Y
copy %MQXROOTDIR%\mqx\source\io\gpio\io_gpio.h %OUTPUTDIR%\io_gpio.h /Y
copy %MQXROOTDIR%\mqx\source\io\gpio\kgpio\io_gpio_kgpio.h %OUTPUTDIR%\io_gpio_kgpio.h /Y
copy %MQXROOTDIR%\mqx\source\io\hwtimer\hwtimer.h %OUTPUTDIR%\hwtimer.h /Y
copy %MQXROOTDIR%\mqx\source\io\hwtimer\hwtimer_pit.h %OUTPUTDIR%\hwtimer_pit.h /Y
copy %MQXROOTDIR%\mqx\source\io\i2c\i2c.h %OUTPUTDIR%\i2c.h /Y
copy %MQXROOTDIR%\mqx\source\io\i2c\i2c_ki2c.h %OUTPUTDIR%\i2c_ki2c.h /Y
copy %MQXROOTDIR%\mqx\source\io\io_dun\io_dun.h %OUTPUTDIR%\io_dun.h /Y
copy %MQXROOTDIR%\mqx\source\io\io_mem\io_mem.h %OUTPUTDIR%\io_mem.h /Y
copy %MQXROOTDIR%\mqx\source\io\io_null\io_null.h %OUTPUTDIR%\io_null.h /Y
copy %MQXROOTDIR%\mqx\source\io\lpm\lpm.h %OUTPUTDIR%\lpm.h /Y
copy %MQXROOTDIR%\mqx\source\io\lpm\lpm_kinetis.h %OUTPUTDIR%\lpm_kinetis.h /Y
copy %MQXROOTDIR%\mqx\source\io\lwgpio\lwgpio.h %OUTPUTDIR%\lwgpio.h /Y
copy %MQXROOTDIR%\mqx\source\io\lwgpio\lwgpio_kgpio.h %OUTPUTDIR%\lwgpio_kgpio.h /Y
copy %MQXROOTDIR%\mqx\source\io\nandflash\nandflash.h %OUTPUTDIR%\nandflash.h /Y
copy %MQXROOTDIR%\mqx\source\io\nandflash\nfc\nfc.h %OUTPUTDIR%\nfc.h /Y
copy %MQXROOTDIR%\mqx\source\io\pcb\io_pcb.h %OUTPUTDIR%\io_pcb.h /Y
copy %MQXROOTDIR%\mqx\source\io\pcb\mqxa\pcb_mqxa.h %OUTPUTDIR%\pcb_mqxa.h /Y
copy %MQXROOTDIR%\mqx\source\io\pcb\mqxa\pcbmqxav.h %OUTPUTDIR%\pcbmqxav.h /Y
copy %MQXROOTDIR%\mqx\source\io\pccard\apccard.h %OUTPUTDIR%\apccard.h /Y
copy %MQXROOTDIR%\mqx\source\io\pccard\pccardflexbus.h %OUTPUTDIR%\pccardflexbus.h /Y
copy %MQXROOTDIR%\mqx\source\io\pcflash\apcflshpr.h %OUTPUTDIR%\apcflshpr.h /Y
copy %MQXROOTDIR%\mqx\source\io\pcflash\ata.h %OUTPUTDIR%\ata.h /Y
copy %MQXROOTDIR%\mqx\source\io\pcflash\pcflash.h %OUTPUTDIR%\pcflash.h /Y
copy %MQXROOTDIR%\mqx\source\io\pipe\io_pipe.h %OUTPUTDIR%\io_pipe.h /Y
copy %MQXROOTDIR%\mqx\source\io\rtc\krtc.h %OUTPUTDIR%\krtc.h /Y
copy %MQXROOTDIR%\mqx\source\io\rtc\krtc_ext.h %OUTPUTDIR%\krtc_ext.h /Y
copy %MQXROOTDIR%\mqx\source\io\rtc\rtc.h %OUTPUTDIR%\rtc.h /Y
copy %MQXROOTDIR%\mqx\source\io\sai\int\sai_int_prv.h %OUTPUTDIR%\sai_int_prv.h /Y
copy %MQXROOTDIR%\mqx\source\io\sai\sai.h %OUTPUTDIR%\sai.h /Y
copy %MQXROOTDIR%\mqx\source\io\sai\sai_audio.h %OUTPUTDIR%\sai_audio.h /Y
copy %MQXROOTDIR%\mqx\source\io\sai\sai_ksai.h %OUTPUTDIR%\sai_ksai.h /Y
copy %MQXROOTDIR%\mqx\source\io\sdcard\sdcard.h %OUTPUTDIR%\sdcard.h /Y
copy %MQXROOTDIR%\mqx\source\io\sdcard\sdcard_esdhc\sdcard_esdhc.h %OUTPUTDIR%\sdcard_esdhc.h /Y
copy %MQXROOTDIR%\mqx\source\io\sdcard\sdcard_spi\sdcard_spi.h %OUTPUTDIR%\sdcard_spi.h /Y
copy %MQXROOTDIR%\mqx\source\io\serial\serial.h %OUTPUTDIR%\serial.h /Y
copy %MQXROOTDIR%\mqx\source\io\serial\serl_kuart.h %OUTPUTDIR%\serl_kuart.h /Y
copy %MQXROOTDIR%\mqx\source\io\spi\spi.h %OUTPUTDIR%\spi.h /Y
copy %MQXROOTDIR%\mqx\source\io\spi\spi_dspi.h %OUTPUTDIR%\spi_dspi.h /Y
copy %MQXROOTDIR%\mqx\source\io\tchres\tchres.h %OUTPUTDIR%\tchres.h /Y
copy %MQXROOTDIR%\mqx\source\io\tfs\tfs.h %OUTPUTDIR%\tfs.h /Y
copy %MQXROOTDIR%\mqx\source\io\timer\qpit.h %OUTPUTDIR%\qpit.h /Y
copy %MQXROOTDIR%\mqx\source\io\timer\timer_lpt.h %OUTPUTDIR%\timer_lpt.h /Y
copy %MQXROOTDIR%\mqx\source\io\timer\timer_qpit.h %OUTPUTDIR%\timer_qpit.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb\if_dev_ehci.h %OUTPUTDIR%\if_dev_ehci.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb\if_dev_khci.h %OUTPUTDIR%\if_dev_khci.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb\if_host_ehci.h %OUTPUTDIR%\if_host_ehci.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb\if_host_khci.h %OUTPUTDIR%\if_host_khci.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb\usb_bsp.h %OUTPUTDIR%\usb_bsp.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb_dcd\usb_dcd.h %OUTPUTDIR%\usb_dcd.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb_dcd\usb_dcd_kn.h %OUTPUTDIR%\usb_dcd_kn.h /Y
copy %MQXROOTDIR%\mqx\source\io\usb_dcd\usb_dcd_kn_prv.h %OUTPUTDIR%\usb_dcd_kn_prv.h /Y


goto tool_%TOOL%

rem cw10 files
:tool_cw10
IF NOT EXIST %OUTPUTDIR%\..\..\dbg mkdir %OUTPUTDIR%\..\..\dbg
IF NOT EXIST %OUTPUTDIR%\Generated_Code mkdir %OUTPUTDIR%\Generated_Code
for /R %MQXROOTDIR%\mqx\build\cw10\bsp_twrk60f120m\Generated_Code %%f in (*.h) do copy %%f %OUTPUTDIR%\Generated_Code\
IF NOT EXIST %OUTPUTDIR%\Sources mkdir %OUTPUTDIR%\Sources
for /R %MQXROOTDIR%\mqx\build\cw10\bsp_twrk60f120m\Sources %%f in (*.h) do copy %%f %OUTPUTDIR%\Sources\
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\cw\dbg\init_kinetis.tcl %OUTPUTDIR%\..\..\dbg\init_kinetis.tcl /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\cw\dbg\mass_erase_kinetis.tcl %OUTPUTDIR%\..\..\dbg\mass_erase_kinetis.tcl /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\cw\dbg\twrk60f120m.mem %OUTPUTDIR%\..\..\dbg\twrk60f120m.mem /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\cw\extmram.lcf %OUTPUTDIR%\extmram.lcf /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\cw\intflash.lcf %OUTPUTDIR%\intflash.lcf /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\cw\intram.lcf %OUTPUTDIR%\intram.lcf /Y
copy %MQXROOTDIR%\mqx\source\io\hmi\TSS\lib_cw\TSS_KXX_M4.a %OUTPUTDIR%\tss.a /Y
goto copy_end

rem iar files
:tool_iar
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\iar\intflash.icf %OUTPUTDIR%\intflash.icf /Y
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\iar\ram.icf %OUTPUTDIR%\ram.icf /Y
copy %MQXROOTDIR%\mqx\source\io\hmi\TSS\lib_iar\TSS_KXX_M4.a %OUTPUTDIR%\tss.a /Y
goto copy_end

rem cw10gcc files
:tool_cw10gcc
IF NOT EXIST %OUTPUTDIR%\Generated_Code mkdir %OUTPUTDIR%\Generated_Code
for /R %MQXROOTDIR%\mqx\build\cw10gcc\bsp_twrk60f120m\Generated_Code %%f in (*.h) do copy %%f %OUTPUTDIR%\Generated_Code\
IF NOT EXIST %OUTPUTDIR%\Sources mkdir %OUTPUTDIR%\Sources
for /R %MQXROOTDIR%\mqx\build\cw10gcc\bsp_twrk60f120m\Sources %%f in (*.h) do copy %%f %OUTPUTDIR%\Sources\
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\gcc_cw\intflash.ld %OUTPUTDIR%\intflash.ld /Y
goto copy_end

rem uv4 files
:tool_uv4
copy %MQXROOTDIR%\mqx\source\bsp\twrk60f120m\uv4\intflash.scf %OUTPUTDIR%\intflash.scf /Y
copy %MQXROOTDIR%\mqx\source\io\hmi\TSS\lib_uv4\TSS_KXX_M4.lib %OUTPUTDIR%\tss.lib /Y
goto copy_end

:copy_end

