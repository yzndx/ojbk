################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.o 

COMPILED_SRCS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.src 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/IfxPsi5_Psi5.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/%.src: ../libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/%.c libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/subdir.mk
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb "-fD:/infineon/ojbk/yueye_v0.1/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=1 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo '�ѽ��������� $<'
	@echo ' '

libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/%.o: ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/%.src libraries/infineon_libraries/iLLD/TC26B/Tricore/Psi5/Psi5/subdir.mk
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo '�ѽ��������� $<'
	@echo ' '


