# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug

# Include any dependencies generated for this target.
include tests/googletest-build/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include tests/googletest-build/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include tests/googletest-build/googlemock/CMakeFiles/gmock.dir/flags.make

tests/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: tests/googletest-build/googlemock/CMakeFiles/gmock.dir/flags.make
tests/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: tests/googletest-build/googlemock/CMakeFiles/gmock.dir/includes_CXX.rsp
tests/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: tests/googletest-src/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj"
	cd /d C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gmock.dir\src\gmock-all.cc.obj -c C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-src\googlemock\src\gmock-all.cc

tests/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /d C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-src\googlemock\src\gmock-all.cc > CMakeFiles\gmock.dir\src\gmock-all.cc.i

tests/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /d C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-src\googlemock\src\gmock-all.cc -o CMakeFiles\gmock.dir\src\gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.obj"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmockd.a: tests/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj
lib/libgmockd.a: tests/googletest-build/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmockd.a: tests/googletest-build/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\..\lib\libgmockd.a"
	cd /d C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean_target.cmake
	cd /d C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/googletest-build/googlemock/CMakeFiles/gmock.dir/build: lib/libgmockd.a

.PHONY : tests/googletest-build/googlemock/CMakeFiles/gmock.dir/build

tests/googletest-build/googlemock/CMakeFiles/gmock.dir/clean:
	cd /d C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean.cmake
.PHONY : tests/googletest-build/googlemock/CMakeFiles/gmock.dir/clean

tests/googletest-build/googlemock/CMakeFiles/gmock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-src\googlemock C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock C:\Users\48660\CLionProjects\Saper_Projekt_Gusvald\cmake-build-debug\tests\googletest-build\googlemock\CMakeFiles\gmock.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/googletest-build/googlemock/CMakeFiles/gmock.dir/depend

