################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./startup_msp432p401r_ccs.obj" \
"./system_msp432p401r.obj" \
"./Sources/GPIO.obj" \
"./Sources/adc.obj" \
"./Sources/circbuff.obj" \
"./Sources/data.obj" \
"./Sources/delay.obj" \
"./Sources/fan_ctrl_lm96063.obj" \
"./Sources/i2c.obj" \
"./Sources/init.obj" \
"./Sources/log.obj" \
"./Sources/main.obj" \
"./Sources/ping_i2c.obj" \
"./Sources/pmbus.obj" \
"./Sources/protocol.obj" \
"./Sources/uart.obj" \
"../msp432p401r.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Sources/subdir_vars.mk
-include subdir_rules.mk
-include Sources/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
MSP432_BMC.out \

EXE_OUTPUTS__QUOTED += \
"MSP432_BMC.out" \

BIN_OUTPUTS += \
MSP432_BMC.txt \

BIN_OUTPUTS__QUOTED += \
"MSP432_BMC.txt" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "MSP432_BMC.out" secondary-outputs

# Tool invocations
MSP432_BMC.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP432 Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power="all" --define=__MSP432P401R__ --define=ccs -g --gcc --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"MSP432_BMC.map" --heap_size=2048 --stack_size=2048 --cinit_hold_wdt=off -i"C:/ti/ccsv7/ccs_base/arm/include" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="MSP432_BMC_linkInfo.xml" --rom_model -o "MSP432_BMC.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

MSP432_BMC.txt: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP432 Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armhex" --memwidth=8 --romwidth=8 --ti_txt -o "MSP432_BMC.txt" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "startup_msp432p401r_ccs.obj" "system_msp432p401r.obj" "Sources\GPIO.obj" "Sources\adc.obj" "Sources\circbuff.obj" "Sources\data.obj" "Sources\delay.obj" "Sources\fan_ctrl_lm96063.obj" "Sources\i2c.obj" "Sources\init.obj" "Sources\log.obj" "Sources\main.obj" "Sources\ping_i2c.obj" "Sources\pmbus.obj" "Sources\protocol.obj" "Sources\uart.obj" 
	-$(RM) "startup_msp432p401r_ccs.d" "system_msp432p401r.d" "Sources\GPIO.d" "Sources\adc.d" "Sources\circbuff.d" "Sources\data.d" "Sources\delay.d" "Sources\fan_ctrl_lm96063.d" "Sources\i2c.d" "Sources\init.d" "Sources\log.d" "Sources\main.d" "Sources\ping_i2c.d" "Sources\pmbus.d" "Sources\protocol.d" "Sources\uart.d" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

