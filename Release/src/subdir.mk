################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AllEdgeReader.cpp \
../src/DeltasReader.cpp \
../src/Edge.cpp \
../src/FileRow.cpp \
../src/FixEdgeReader.cpp \
../src/Node.cpp \
../src/NodeContainer.cpp \
../src/NodeReader.cpp \
../src/Reader.cpp \
../src/SvgGenerator.cpp \
../src/main.cpp 

OBJS += \
./src/AllEdgeReader.o \
./src/DeltasReader.o \
./src/Edge.o \
./src/FileRow.o \
./src/FixEdgeReader.o \
./src/Node.o \
./src/NodeContainer.o \
./src/NodeReader.o \
./src/Reader.o \
./src/SvgGenerator.o \
./src/main.o 

CPP_DEPS += \
./src/AllEdgeReader.d \
./src/DeltasReader.d \
./src/Edge.d \
./src/FileRow.d \
./src/FixEdgeReader.d \
./src/Node.d \
./src/NodeContainer.d \
./src/NodeReader.d \
./src/Reader.d \
./src/SvgGenerator.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


