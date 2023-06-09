################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../DIO_Program.c \
../EINT_Program.c \
../LCD.c \
../LED_Program.c \
../SSEG_Program.c \
../SW_Program.c \
../traggic_light.c 

OBJS += \
./DIO.o \
./DIO_Program.o \
./EINT_Program.o \
./LCD.o \
./LED_Program.o \
./SSEG_Program.o \
./SW_Program.o \
./traggic_light.o 

C_DEPS += \
./DIO.d \
./DIO_Program.d \
./EINT_Program.d \
./LCD.d \
./LED_Program.d \
./SSEG_Program.d \
./SW_Program.d \
./traggic_light.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


