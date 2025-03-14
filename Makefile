# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12/Aircraft/Laminar Research/Beechcraft Baron 58/plugins/aspenEvo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12/Aircraft/Laminar Research/Beechcraft Baron 58/plugins/aspenEvo"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12/Aircraft/Laminar Research/Beechcraft Baron 58/plugins/aspenEvo/CMakeFiles" "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12/Aircraft/Laminar Research/Beechcraft Baron 58/plugins/aspenEvo//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12/Aircraft/Laminar Research/Beechcraft Baron 58/plugins/aspenEvo/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named aspenEvo

# Build rule for target.
aspenEvo: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 aspenEvo
.PHONY : aspenEvo

# fast build rule for target.
aspenEvo/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/build
.PHONY : aspenEvo/fast

src/datarefs.o: src/datarefs.cpp.o
.PHONY : src/datarefs.o

# target to build an object file
src/datarefs.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/datarefs.cpp.o
.PHONY : src/datarefs.cpp.o

src/datarefs.i: src/datarefs.cpp.i
.PHONY : src/datarefs.i

# target to preprocess a source file
src/datarefs.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/datarefs.cpp.i
.PHONY : src/datarefs.cpp.i

src/datarefs.s: src/datarefs.cpp.s
.PHONY : src/datarefs.s

# target to generate assembly for a file
src/datarefs.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/datarefs.cpp.s
.PHONY : src/datarefs.cpp.s

src/device.o: src/device.cpp.o
.PHONY : src/device.o

# target to build an object file
src/device.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/device.cpp.o
.PHONY : src/device.cpp.o

src/device.i: src/device.cpp.i
.PHONY : src/device.i

# target to preprocess a source file
src/device.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/device.cpp.i
.PHONY : src/device.cpp.i

src/device.s: src/device.cpp.s
.PHONY : src/device.s

# target to generate assembly for a file
src/device.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/device.cpp.s
.PHONY : src/device.cpp.s

src/globals.o: src/globals.cpp.o
.PHONY : src/globals.o

# target to build an object file
src/globals.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/globals.cpp.o
.PHONY : src/globals.cpp.o

src/globals.i: src/globals.cpp.i
.PHONY : src/globals.i

# target to preprocess a source file
src/globals.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/globals.cpp.i
.PHONY : src/globals.cpp.i

src/globals.s: src/globals.cpp.s
.PHONY : src/globals.s

# target to generate assembly for a file
src/globals.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/globals.cpp.s
.PHONY : src/globals.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/textureLoader.o: src/textureLoader.cpp.o
.PHONY : src/textureLoader.o

# target to build an object file
src/textureLoader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/textureLoader.cpp.o
.PHONY : src/textureLoader.cpp.o

src/textureLoader.i: src/textureLoader.cpp.i
.PHONY : src/textureLoader.i

# target to preprocess a source file
src/textureLoader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/textureLoader.cpp.i
.PHONY : src/textureLoader.cpp.i

src/textureLoader.s: src/textureLoader.cpp.s
.PHONY : src/textureLoader.s

# target to generate assembly for a file
src/textureLoader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/aspenEvo.dir/build.make CMakeFiles/aspenEvo.dir/src/textureLoader.cpp.s
.PHONY : src/textureLoader.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... aspenEvo"
	@echo "... src/datarefs.o"
	@echo "... src/datarefs.i"
	@echo "... src/datarefs.s"
	@echo "... src/device.o"
	@echo "... src/device.i"
	@echo "... src/device.s"
	@echo "... src/globals.o"
	@echo "... src/globals.i"
	@echo "... src/globals.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/textureLoader.o"
	@echo "... src/textureLoader.i"
	@echo "... src/textureLoader.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

