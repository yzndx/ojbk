################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/963_MahonyAhrd.c \
../code/all_int.c \
../code/flash.c \
../code/gps.c \
../code/isp200.c \
../code/key.c \
../code/math_2.c \
../code/menu.c \
../code/picture.c \
../code/pid.c \
../code/run.c \
../code/wifi.c \
../code/yaokong.c 

OBJS += \
./code/963_MahonyAhrd.o \
./code/all_int.o \
./code/flash.o \
./code/gps.o \
./code/isp200.o \
./code/key.o \
./code/math_2.o \
./code/menu.o \
./code/picture.o \
./code/pid.o \
./code/run.o \
./code/wifi.o \
./code/yaokong.o 

COMPILED_SRCS += \
./code/963_MahonyAhrd.src \
./code/all_int.src \
./code/flash.src \
./code/gps.src \
./code/isp200.src \
./code/key.src \
./code/math_2.src \
./code/menu.src \
./code/picture.src \
./code/pid.src \
./code/run.src \
./code/wifi.src \
./code/yaokong.src 

C_DEPS += \
./code/963_MahonyAhrd.d \
./code/all_int.d \
./code/flash.d \
./code/gps.d \
./code/isp200.d \
./code/key.d \
./code/math_2.d \
./code/menu.d \
./code/picture.d \
./code/pid.d \
./code/run.d \
./code/wifi.d \
./code/yaokong.d 


# Each subdirectory must supply rules for building sources it contributes
code/%.src: ../code/%.c code/subdir.mk
	@echo '正在构建文件： $<'
	@echo '正在调用： TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb "-fD:/infineon/ojbk/yueye_v0.1/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=1 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo '已结束构建： $<'
	@echo ' '

code/%.o: ./code/%.src code/subdir.mk
	@echo '正在构建文件： $<'
	@echo '正在调用： TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo '已结束构建： $<'
	@echo ' '


