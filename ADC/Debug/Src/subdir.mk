################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_program.c \
C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src/GPIO_program.c \
C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src/NVIC_program.c \
C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src/RCC_program.c \
C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src/STK_progrm.c \
C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src/TIMER1_program.c \
C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src/USART_program.c \
../Src/main.c 

OBJS += \
./Src/ADC_program.o \
./Src/GPIO_program.o \
./Src/NVIC_program.o \
./Src/RCC_program.o \
./Src/STK_progrm.o \
./Src/TIMER1_program.o \
./Src/USART_program.o \
./Src/main.o 

C_DEPS += \
./Src/ADC_program.d \
./Src/GPIO_program.d \
./Src/NVIC_program.d \
./Src/RCC_program.d \
./Src/STK_progrm.d \
./Src/TIMER1_program.d \
./Src/USART_program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/ADC_program.o: ../Src/ADC_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/ADC_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/GPIO_program.o: C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src/GPIO_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GPIO_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/NVIC_program.o: C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src/NVIC_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/NVIC_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/RCC_program.o: C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src/RCC_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/RCC_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STK_progrm.o: C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src/STK_progrm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STK_progrm.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/TIMER1_program.o: C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src/TIMER1_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/TIMER1_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/USART_program.o: C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src/USART_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/USART_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/RCC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/GPIO/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/NVIC/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/SYSTICK/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/USART/Src" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Inc" -I"C:/Users/dell/STM32CubeIDE/workspace_1.4.0/TIMER1/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

