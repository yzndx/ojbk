################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Atom.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Cmu.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Dpll.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tbu.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tim.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tom.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Atom.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Cmu.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Dpll.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tbu.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tim.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tom.o 

COMPILED_SRCS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm.src \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Atom.src \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Cmu.src \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Dpll.src \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tbu.src \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tim.src \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tom.src 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Atom.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Cmu.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Dpll.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tbu.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tim.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/IfxGtm_Tom.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/%.src: ../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/%.c libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/subdir.mk
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb "-fD:/infineon/ojbk/yueye_v0.1/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=1 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file="$(@:.src=.d)" --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo '�ѽ��������� $<'
	@echo ' '

libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/%.o: ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/%.src libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Std/subdir.mk
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo '�ѽ��������� $<'
	@echo ' '

