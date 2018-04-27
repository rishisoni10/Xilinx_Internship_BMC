################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
startup_msp432p401r_ccs.obj: ../startup_msp432p401r_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="startup_msp432p401r_ccs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

system_msp432p401r.obj: ../system_msp432p401r.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx" --include_path="C:/ti/simplelink_msp432_sdk_1_40_00_28/source/ti/devices/msp432p4xx/driverlib" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib/Include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/rsoni/Desktop/MSP432_bridge_lib" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="system_msp432p401r.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


