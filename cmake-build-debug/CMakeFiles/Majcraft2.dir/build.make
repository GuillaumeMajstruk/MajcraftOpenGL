# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = C:\Users\m416099\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6183.77\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\m416099\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6183.77\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\m416099\CLionProjects\Majcraft2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Majcraft2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Majcraft2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Majcraft2.dir/flags.make

CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.obj: CMakeFiles/Majcraft2.dir/flags.make
CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.obj: CMakeFiles/Majcraft2.dir/includes_CXX.rsp
CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.obj: ../openGLtest/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Majcraft2.dir\openGLtest\main.cpp.obj -c C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\main.cpp

CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\main.cpp > CMakeFiles\Majcraft2.dir\openGLtest\main.cpp.i

CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\main.cpp -o CMakeFiles\Majcraft2.dir\openGLtest\main.cpp.s

CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.obj: CMakeFiles/Majcraft2.dir/flags.make
CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.obj: CMakeFiles/Majcraft2.dir/includes_CXX.rsp
CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.obj: ../openGLtest/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Majcraft2.dir\openGLtest\stb_image.cpp.obj -c C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\stb_image.cpp

CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\stb_image.cpp > CMakeFiles\Majcraft2.dir\openGLtest\stb_image.cpp.i

CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\stb_image.cpp -o CMakeFiles\Majcraft2.dir\openGLtest\stb_image.cpp.s

# Object files for target Majcraft2
Majcraft2_OBJECTS = \
"CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.obj" \
"CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.obj"

# External object files for target Majcraft2
Majcraft2_EXTERNAL_OBJECTS =

Majcraft2.exe: CMakeFiles/Majcraft2.dir/openGLtest/main.cpp.obj
Majcraft2.exe: CMakeFiles/Majcraft2.dir/openGLtest/stb_image.cpp.obj
Majcraft2.exe: CMakeFiles/Majcraft2.dir/build.make
Majcraft2.exe: openGLtest/Librairies/glfw/src/libglfw3.a
Majcraft2.exe: lib/libglew32d.dll.a
Majcraft2.exe: CMakeFiles/Majcraft2.dir/linklibs.rsp
Majcraft2.exe: CMakeFiles/Majcraft2.dir/objects1.rsp
Majcraft2.exe: CMakeFiles/Majcraft2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Majcraft2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Majcraft2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Majcraft2.dir/build: Majcraft2.exe

.PHONY : CMakeFiles/Majcraft2.dir/build

CMakeFiles/Majcraft2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Majcraft2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Majcraft2.dir/clean

CMakeFiles/Majcraft2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\m416099\CLionProjects\Majcraft2 C:\Users\m416099\CLionProjects\Majcraft2 C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles\Majcraft2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Majcraft2.dir/depend
