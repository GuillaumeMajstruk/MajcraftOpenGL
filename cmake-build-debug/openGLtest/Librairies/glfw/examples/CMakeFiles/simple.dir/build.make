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
include openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/depend.make

# Include the progress variables for this target.
include openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/flags.make

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/simple.c.obj: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/flags.make
openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/simple.c.obj: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/includes_C.rsp
openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/simple.c.obj: ../openGLtest/Librairies/glfw/examples/simple.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/simple.c.obj"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simple.dir\simple.c.obj   -c C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\examples\simple.c

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/simple.c.i"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\examples\simple.c > CMakeFiles\simple.dir\simple.c.i

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/simple.c.s"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\examples\simple.c -o CMakeFiles\simple.dir\simple.c.s

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/flags.make
openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj: ../openGLtest/Librairies/glfw/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && C:\MinGW\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\examples\glfw.rc CMakeFiles\simple.dir\glfw.rc.obj

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/flags.make
openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/includes_C.rsp
openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: ../openGLtest/Librairies/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simple.dir\__\deps\glad_gl.c.obj   -c C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\deps\glad_gl.c

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\deps\glad_gl.c > CMakeFiles\simple.dir\__\deps\glad_gl.c.i

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\deps\glad_gl.c -o CMakeFiles\simple.dir\__\deps\glad_gl.c.s

# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.c.obj" \
"CMakeFiles/simple.dir/glfw.rc.obj" \
"CMakeFiles/simple.dir/__/deps/glad_gl.c.obj"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/simple.c.obj
openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj
openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj
openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/build.make
openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/src/libglfw3.a
openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/linklibs.rsp
openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/objects1.rsp
openGLtest/Librairies/glfw/examples/simple.exe: openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable simple.exe"
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\simple.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/build: openGLtest/Librairies/glfw/examples/simple.exe

.PHONY : openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/build

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/clean:
	cd /d C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples && $(CMAKE_COMMAND) -P CMakeFiles\simple.dir\cmake_clean.cmake
.PHONY : openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/clean

openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\m416099\CLionProjects\Majcraft2 C:\Users\m416099\CLionProjects\Majcraft2\openGLtest\Librairies\glfw\examples C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples C:\Users\m416099\CLionProjects\Majcraft2\cmake-build-debug\openGLtest\Librairies\glfw\examples\CMakeFiles\simple.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : openGLtest/Librairies/glfw/examples/CMakeFiles/simple.dir/depend
