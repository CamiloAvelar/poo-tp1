# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/camilo/Documents/UFOP/19.1/POO/Trabalhos/inicial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/camilo/Documents/UFOP/19.1/POO/Trabalhos/inicial

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/camilo/Documents/UFOP/19.1/POO/Trabalhos/inicial/CMakeFiles /home/camilo/Documents/UFOP/19.1/POO/Trabalhos/inicial/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/camilo/Documents/UFOP/19.1/POO/Trabalhos/inicial/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

src/Desempregado.o: src/Desempregado.cpp.o

.PHONY : src/Desempregado.o

# target to build an object file
src/Desempregado.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Desempregado.cpp.o
.PHONY : src/Desempregado.cpp.o

src/Desempregado.i: src/Desempregado.cpp.i

.PHONY : src/Desempregado.i

# target to preprocess a source file
src/Desempregado.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Desempregado.cpp.i
.PHONY : src/Desempregado.cpp.i

src/Desempregado.s: src/Desempregado.cpp.s

.PHONY : src/Desempregado.s

# target to generate assembly for a file
src/Desempregado.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Desempregado.cpp.s
.PHONY : src/Desempregado.cpp.s

src/Empresa.o: src/Empresa.cpp.o

.PHONY : src/Empresa.o

# target to build an object file
src/Empresa.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Empresa.cpp.o
.PHONY : src/Empresa.cpp.o

src/Empresa.i: src/Empresa.cpp.i

.PHONY : src/Empresa.i

# target to preprocess a source file
src/Empresa.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Empresa.cpp.i
.PHONY : src/Empresa.cpp.i

src/Empresa.s: src/Empresa.cpp.s

.PHONY : src/Empresa.s

# target to generate assembly for a file
src/Empresa.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Empresa.cpp.s
.PHONY : src/Empresa.cpp.s

src/Endereco.o: src/Endereco.cpp.o

.PHONY : src/Endereco.o

# target to build an object file
src/Endereco.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Endereco.cpp.o
.PHONY : src/Endereco.cpp.o

src/Endereco.i: src/Endereco.cpp.i

.PHONY : src/Endereco.i

# target to preprocess a source file
src/Endereco.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Endereco.cpp.i
.PHONY : src/Endereco.cpp.i

src/Endereco.s: src/Endereco.cpp.s

.PHONY : src/Endereco.s

# target to generate assembly for a file
src/Endereco.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Endereco.cpp.s
.PHONY : src/Endereco.cpp.s

src/Operations.o: src/Operations.cpp.o

.PHONY : src/Operations.o

# target to build an object file
src/Operations.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Operations.cpp.o
.PHONY : src/Operations.cpp.o

src/Operations.i: src/Operations.cpp.i

.PHONY : src/Operations.i

# target to preprocess a source file
src/Operations.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Operations.cpp.i
.PHONY : src/Operations.cpp.i

src/Operations.s: src/Operations.cpp.s

.PHONY : src/Operations.s

# target to generate assembly for a file
src/Operations.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Operations.cpp.s
.PHONY : src/Operations.cpp.s

src/Pessoa.o: src/Pessoa.cpp.o

.PHONY : src/Pessoa.o

# target to build an object file
src/Pessoa.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Pessoa.cpp.o
.PHONY : src/Pessoa.cpp.o

src/Pessoa.i: src/Pessoa.cpp.i

.PHONY : src/Pessoa.i

# target to preprocess a source file
src/Pessoa.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Pessoa.cpp.i
.PHONY : src/Pessoa.cpp.i

src/Pessoa.s: src/Pessoa.cpp.s

.PHONY : src/Pessoa.s

# target to generate assembly for a file
src/Pessoa.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Pessoa.cpp.s
.PHONY : src/Pessoa.cpp.s

src/Populate.o: src/Populate.cpp.o

.PHONY : src/Populate.o

# target to build an object file
src/Populate.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Populate.cpp.o
.PHONY : src/Populate.cpp.o

src/Populate.i: src/Populate.cpp.i

.PHONY : src/Populate.i

# target to preprocess a source file
src/Populate.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Populate.cpp.i
.PHONY : src/Populate.cpp.i

src/Populate.s: src/Populate.cpp.s

.PHONY : src/Populate.s

# target to generate assembly for a file
src/Populate.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Populate.cpp.s
.PHONY : src/Populate.cpp.s

src/Util.o: src/Util.cpp.o

.PHONY : src/Util.o

# target to build an object file
src/Util.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Util.cpp.o
.PHONY : src/Util.cpp.o

src/Util.i: src/Util.cpp.i

.PHONY : src/Util.i

# target to preprocess a source file
src/Util.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Util.cpp.i
.PHONY : src/Util.cpp.i

src/Util.s: src/Util.cpp.s

.PHONY : src/Util.s

# target to generate assembly for a file
src/Util.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Util.cpp.s
.PHONY : src/Util.cpp.s

src/Vagas.o: src/Vagas.cpp.o

.PHONY : src/Vagas.o

# target to build an object file
src/Vagas.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Vagas.cpp.o
.PHONY : src/Vagas.cpp.o

src/Vagas.i: src/Vagas.cpp.i

.PHONY : src/Vagas.i

# target to preprocess a source file
src/Vagas.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Vagas.cpp.i
.PHONY : src/Vagas.cpp.i

src/Vagas.s: src/Vagas.cpp.s

.PHONY : src/Vagas.s

# target to generate assembly for a file
src/Vagas.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Vagas.cpp.s
.PHONY : src/Vagas.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... edit_cache"
	@echo "... src/Desempregado.o"
	@echo "... src/Desempregado.i"
	@echo "... src/Desempregado.s"
	@echo "... src/Empresa.o"
	@echo "... src/Empresa.i"
	@echo "... src/Empresa.s"
	@echo "... src/Endereco.o"
	@echo "... src/Endereco.i"
	@echo "... src/Endereco.s"
	@echo "... src/Operations.o"
	@echo "... src/Operations.i"
	@echo "... src/Operations.s"
	@echo "... src/Pessoa.o"
	@echo "... src/Pessoa.i"
	@echo "... src/Pessoa.s"
	@echo "... src/Populate.o"
	@echo "... src/Populate.i"
	@echo "... src/Populate.s"
	@echo "... src/Util.o"
	@echo "... src/Util.i"
	@echo "... src/Util.s"
	@echo "... src/Vagas.o"
	@echo "... src/Vagas.i"
	@echo "... src/Vagas.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

