################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Sources/GPIO.obj: ../Sources/GPIO.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/GPIO.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/adc.obj: ../Sources/adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/adc.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/circbuff.obj: ../Sources/circbuff.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/circbuff.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/data.obj: ../Sources/data.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/data.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/delay.obj: ../Sources/delay.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/delay.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/fan_ctrl_lm96063.obj: ../Sources/fan_ctrl_lm96063.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/fan_ctrl_lm96063.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/i2c.obj: ../Sources/i2c.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/i2c.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/init.obj: ../Sources/init.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/init.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/log.obj: ../Sources/log.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/log.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.obj: ../Sources/main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/main.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ping_i2c.obj: ../Sources/ping_i2c.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/ping_i2c.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pmbus.obj: ../Sources/pmbus.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/pmbus.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/protocol.obj: ../Sources/protocol.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/protocol.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart.obj: ../Sources/uart.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Sources/uart.d" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


