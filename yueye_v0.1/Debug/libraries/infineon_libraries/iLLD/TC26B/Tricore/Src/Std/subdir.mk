################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.o 

COMPILED_SRCS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.src 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/%.src: ../libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/%.c libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/subdir.mk
	@echo '正在构建文件： $<'
	@echo '正在调用： TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb "-fD:/infineon/ojbk/yueye_v0.1/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=1 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo '已结束构建： $<'
	@echo ' '

libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/%.o: ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/%.src libraries/infineon_libraries/iLLD/TC26B/Tricore/Src/Std/subdir.mk
	@echo '正在构建文件： $<'
	@echo '正在调用： TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo '已结束构建： $<'
	@echo ' '


