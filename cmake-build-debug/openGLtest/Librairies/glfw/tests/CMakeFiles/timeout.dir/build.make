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
CMAKE_SOURCE_DIR = C:\Users\m416099\CLionProjects\Majcraft2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug

# Include any dependencies generated for this target.
include openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/depend.make

# Include the progress variables for this target.
include openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/progress.make

# Include the compile flags for this target's objects.
include openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/flags.make

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/timeout.c.obj: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/flags.make
openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/timeout.c.obj: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/includes_C.rsp
openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/timeout.c.obj: ../openGLtest/Librairies/glfw/tests/timeout.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/timeout.c.obj"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\timeout.dir\timeout.c.obj   -c C:\Users\m416099\CLionProjects\Majcraft2.0\openGLtest\Librairies\glfw\tests\timeout.c

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/timeout.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/timeout.c.i"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\m416099\CLionProjects\Majcraft2.0\openGLtest\Librairies\glfw\tests\timeout.c > CMakeFiles\timeout.dir\timeout.c.i

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/timeout.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/timeout.c.s"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\m416099\CLionProjects\Majcraft2.0\openGLtest\Librairies\glfw\tests\timeout.c -o CMakeFiles\timeout.dir\timeout.c.s

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.obj: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/flags.make
openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.obj: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/includes_C.rsp
openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.obj: ../openGLtest/Librairies/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\timeout.dir\__\deps\glad_gl.c.obj   -c C:\Users\m416099\CLionProjects\Majcraft2.0\openGLtest\Librairies\glfw\deps\glad_gl.c

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\m416099\CLionProjects\Majcraft2.0\openGLtest\Librairies\glfw\deps\glad_gl.c > CMakeFiles\timeout.dir\__\deps\glad_gl.c.i

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\m416099\CLionProjects\Majcraft2.0\openGLtest\Librairies\glfw\deps\glad_gl.c -o CMakeFiles\timeout.dir\__\deps\glad_gl.c.s

# Object files for target timeout
timeout_OBJECTS = \
"CMakeFiles/timeout.dir/timeout.c.obj" \
"CMakeFiles/timeout.dir/__/deps/glad_gl.c.obj"

# External object files for target timeout
timeout_EXTERNAL_OBJECTS =

openGLtest/Librairies/glfw/tests/timeout.exe: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/timeout.c.obj
openGLtest/Librairies/glfw/tests/timeout.exe: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.obj
openGLtest/Librairies/glfw/tests/timeout.exe: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/build.make
openGLtest/Librairies/glfw/tests/timeout.exe: openGLtest/Librairies/glfw/src/libglfw3.a
openGLtest/Librairies/glfw/tests/timeout.exe: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/linklibs.rsp
openGLtest/Librairies/glfw/tests/timeout.exe: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/objects1.rsp
openGLtest/Librairies/glfw/tests/timeout.exe: openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable timeout.exe"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\timeout.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/build: openGLtest/Librairies/glfw/tests/timeout.exe

.PHONY : openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/build

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/clean:
	cd /d C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests && $(CMAKE_COMMAND) -P CMakeFiles\timeout.dir\cmake_clean.cmake
.PHONY : openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/clean

openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\m416099\CLionProjects\Majcraft2.0 C:\Users\m416099\CLionProjects\Majcraft2.0\openGLtest\Librairies\glfw\tests C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests C:\Users\m416099\CLionProjects\Majcraft2.0\cmake-build-debug\openGLtest\Librairies\glfw\tests\CMakeFiles\timeout.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : openGLtest/Librairies/glfw/tests/CMakeFiles/timeout.dir/depend

