# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = E:/cmake/bin/cmake.exe

# The command to remove a file.
RM = E:/cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:/code/myos/start

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:/code/myos/start/build

# Include any dependencies generated for this target.
include source/kernel/CMakeFiles/kernel.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/kernel/CMakeFiles/kernel.dir/compiler_depend.make

# Include the progress variables for this target.
include source/kernel/CMakeFiles/kernel.dir/progress.make

# Include the compile flags for this target's objects.
include source/kernel/CMakeFiles/kernel.dir/flags.make

source/kernel/CMakeFiles/kernel.dir/init/start.S.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/init/start.S.obj: ../source/kernel/init/start.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object source/kernel/CMakeFiles/kernel.dir/init/start.S.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/kernel.dir/init/start.S.obj -c E:/code/myos/start/source/kernel/init/start.S

source/kernel/CMakeFiles/kernel.dir/init/start.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing ASM source to CMakeFiles/kernel.dir/init/start.S.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E E:/code/myos/start/source/kernel/init/start.S > CMakeFiles/kernel.dir/init/start.S.i

source/kernel/CMakeFiles/kernel.dir/init/start.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling ASM source to assembly CMakeFiles/kernel.dir/init/start.S.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S E:/code/myos/start/source/kernel/init/start.S -o CMakeFiles/kernel.dir/init/start.S.s

source/kernel/CMakeFiles/kernel.dir/core/task.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/core/task.c.obj: ../source/kernel/core/task.c
source/kernel/CMakeFiles/kernel.dir/core/task.c.obj: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/kernel/CMakeFiles/kernel.dir/core/task.c.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/core/task.c.obj -MF CMakeFiles/kernel.dir/core/task.c.obj.d -o CMakeFiles/kernel.dir/core/task.c.obj -c E:/code/myos/start/source/kernel/core/task.c

source/kernel/CMakeFiles/kernel.dir/core/task.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/core/task.c.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/code/myos/start/source/kernel/core/task.c > CMakeFiles/kernel.dir/core/task.c.i

source/kernel/CMakeFiles/kernel.dir/core/task.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/core/task.c.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/code/myos/start/source/kernel/core/task.c -o CMakeFiles/kernel.dir/core/task.c.s

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj: ../source/kernel/cpu/cpu.c
source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj -MF CMakeFiles/kernel.dir/cpu/cpu.c.obj.d -o CMakeFiles/kernel.dir/cpu/cpu.c.obj -c E:/code/myos/start/source/kernel/cpu/cpu.c

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/cpu/cpu.c.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/code/myos/start/source/kernel/cpu/cpu.c > CMakeFiles/kernel.dir/cpu/cpu.c.i

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/cpu/cpu.c.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/code/myos/start/source/kernel/cpu/cpu.c -o CMakeFiles/kernel.dir/cpu/cpu.c.s

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj: ../source/kernel/cpu/irq.c
source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj -MF CMakeFiles/kernel.dir/cpu/irq.c.obj.d -o CMakeFiles/kernel.dir/cpu/irq.c.obj -c E:/code/myos/start/source/kernel/cpu/irq.c

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/cpu/irq.c.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/code/myos/start/source/kernel/cpu/irq.c > CMakeFiles/kernel.dir/cpu/irq.c.i

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/cpu/irq.c.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/code/myos/start/source/kernel/cpu/irq.c -o CMakeFiles/kernel.dir/cpu/irq.c.s

source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj: ../source/kernel/dev/time.c
source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj -MF CMakeFiles/kernel.dir/dev/time.c.obj.d -o CMakeFiles/kernel.dir/dev/time.c.obj -c E:/code/myos/start/source/kernel/dev/time.c

source/kernel/CMakeFiles/kernel.dir/dev/time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/dev/time.c.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/code/myos/start/source/kernel/dev/time.c > CMakeFiles/kernel.dir/dev/time.c.i

source/kernel/CMakeFiles/kernel.dir/dev/time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/dev/time.c.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/code/myos/start/source/kernel/dev/time.c -o CMakeFiles/kernel.dir/dev/time.c.s

source/kernel/CMakeFiles/kernel.dir/init/init.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/init/init.c.obj: ../source/kernel/init/init.c
source/kernel/CMakeFiles/kernel.dir/init/init.c.obj: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object source/kernel/CMakeFiles/kernel.dir/init/init.c.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/init/init.c.obj -MF CMakeFiles/kernel.dir/init/init.c.obj.d -o CMakeFiles/kernel.dir/init/init.c.obj -c E:/code/myos/start/source/kernel/init/init.c

source/kernel/CMakeFiles/kernel.dir/init/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/init/init.c.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/code/myos/start/source/kernel/init/init.c > CMakeFiles/kernel.dir/init/init.c.i

source/kernel/CMakeFiles/kernel.dir/init/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/init/init.c.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/code/myos/start/source/kernel/init/init.c -o CMakeFiles/kernel.dir/init/init.c.s

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj: ../source/kernel/tools/klib.c
source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj -MF CMakeFiles/kernel.dir/tools/klib.c.obj.d -o CMakeFiles/kernel.dir/tools/klib.c.obj -c E:/code/myos/start/source/kernel/tools/klib.c

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/klib.c.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/code/myos/start/source/kernel/tools/klib.c > CMakeFiles/kernel.dir/tools/klib.c.i

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/klib.c.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/code/myos/start/source/kernel/tools/klib.c -o CMakeFiles/kernel.dir/tools/klib.c.s

source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj: ../source/kernel/tools/log.c
source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj -MF CMakeFiles/kernel.dir/tools/log.c.obj.d -o CMakeFiles/kernel.dir/tools/log.c.obj -c E:/code/myos/start/source/kernel/tools/log.c

source/kernel/CMakeFiles/kernel.dir/tools/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/log.c.i"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/code/myos/start/source/kernel/tools/log.c > CMakeFiles/kernel.dir/tools/log.c.i

source/kernel/CMakeFiles/kernel.dir/tools/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/log.c.s"
	cd E:/code/myos/start/build/source/kernel && E:/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/code/myos/start/source/kernel/tools/log.c -o CMakeFiles/kernel.dir/tools/log.c.s

# Object files for target kernel
kernel_OBJECTS = \
"CMakeFiles/kernel.dir/init/start.S.obj" \
"CMakeFiles/kernel.dir/core/task.c.obj" \
"CMakeFiles/kernel.dir/cpu/cpu.c.obj" \
"CMakeFiles/kernel.dir/cpu/irq.c.obj" \
"CMakeFiles/kernel.dir/dev/time.c.obj" \
"CMakeFiles/kernel.dir/init/init.c.obj" \
"CMakeFiles/kernel.dir/tools/klib.c.obj" \
"CMakeFiles/kernel.dir/tools/log.c.obj"

# External object files for target kernel
kernel_EXTERNAL_OBJECTS =

source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/init/start.S.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/core/task.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/init/init.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:/code/myos/start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable kernel"
	cd E:/code/myos/start/build/source/kernel && x86_64-elf-ld $(kernel_OBJECTS) $(kernel_EXTERNAL_OBJECTS) -m elf_i386 -T E:/code/myos/start/source/kernel/kernel.lds -o E:/code/myos/start/build/source/kernel/kernel.elf
	cd E:/code/myos/start/build/source/kernel && x86_64-elf-objcopy -S kernel.elf E:/code/myos/start/../image/kernel.elf
	cd E:/code/myos/start/build/source/kernel && x86_64-elf-objdump -x -d -S -m i386 E:/code/myos/start/build/source/kernel/kernel.elf > kernel_dis.txt
	cd E:/code/myos/start/build/source/kernel && x86_64-elf-readelf -a E:/code/myos/start/build/source/kernel/kernel.elf > kernel_elf.txt

# Rule to build all files generated by this target.
source/kernel/CMakeFiles/kernel.dir/build: source/kernel/kernel
.PHONY : source/kernel/CMakeFiles/kernel.dir/build

source/kernel/CMakeFiles/kernel.dir/clean:
	cd E:/code/myos/start/build/source/kernel && $(CMAKE_COMMAND) -P CMakeFiles/kernel.dir/cmake_clean.cmake
.PHONY : source/kernel/CMakeFiles/kernel.dir/clean

source/kernel/CMakeFiles/kernel.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" E:/code/myos/start E:/code/myos/start/source/kernel E:/code/myos/start/build E:/code/myos/start/build/source/kernel E:/code/myos/start/build/source/kernel/CMakeFiles/kernel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/kernel/CMakeFiles/kernel.dir/depend

