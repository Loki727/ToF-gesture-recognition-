################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/DSP/Source/ControllerFunctions/ControllerFunctions.c 

C_DEPS += \
./CMSIS/DSP/Source/ControllerFunctions/ControllerFunctions.d 

OBJS += \
./CMSIS/DSP/Source/ControllerFunctions/ControllerFunctions.o 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/DSP/Source/ControllerFunctions/%.o: ../CMSIS/DSP/Source/ControllerFunctions/%.c CMSIS/DSP/Source/ControllerFunctions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\drivers" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\device" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\utilities" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\component\uart" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\component\serial_manager" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\component\lists" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\board" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\startup" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS\DSP\Include" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS\DSP\PrivateInclude" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS\DSP\Source\DistanceFunctions" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\drivers" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\device" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\utilities" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\component\uart" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\component\serial_manager" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\component\lists" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\board" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\startup" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS\DSP\Include" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS\DSP\PrivateInclude" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\CMSIS\DSP\Source\DistanceFunctions" -I"C:\Users\MaxxOleksy\Documents\MCUXpressoIDE_11.9.0_2144\workspace\ToF\source" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CMSIS-2f-DSP-2f-Source-2f-ControllerFunctions

clean-CMSIS-2f-DSP-2f-Source-2f-ControllerFunctions:
	-$(RM) ./CMSIS/DSP/Source/ControllerFunctions/ControllerFunctions.d ./CMSIS/DSP/Source/ControllerFunctions/ControllerFunctions.o

.PHONY: clean-CMSIS-2f-DSP-2f-Source-2f-ControllerFunctions

