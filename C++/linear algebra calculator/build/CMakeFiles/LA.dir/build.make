# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build"

# Include any dependencies generated for this target.
include CMakeFiles/LA.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LA.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LA.dir/flags.make

CMakeFiles/LA.dir/src/Base.obj: CMakeFiles/LA.dir/flags.make
CMakeFiles/LA.dir/src/Base.obj: CMakeFiles/LA.dir/includes_CXX.rsp
CMakeFiles/LA.dir/src/Base.obj: ../src/Base.cpp
CMakeFiles/LA.dir/src/Base.obj: CMakeFiles/LA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LA.dir/src/Base.obj"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LA.dir/src/Base.obj -MF CMakeFiles\LA.dir\src\Base.obj.d -o CMakeFiles\LA.dir\src\Base.obj -c "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Base.cpp"

CMakeFiles/LA.dir/src/Base.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LA.dir/src/Base.i"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Base.cpp" > CMakeFiles\LA.dir\src\Base.i

CMakeFiles/LA.dir/src/Base.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LA.dir/src/Base.s"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Base.cpp" -o CMakeFiles\LA.dir\src\Base.s

CMakeFiles/LA.dir/src/Determinant.obj: CMakeFiles/LA.dir/flags.make
CMakeFiles/LA.dir/src/Determinant.obj: CMakeFiles/LA.dir/includes_CXX.rsp
CMakeFiles/LA.dir/src/Determinant.obj: ../src/Determinant.cpp
CMakeFiles/LA.dir/src/Determinant.obj: CMakeFiles/LA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LA.dir/src/Determinant.obj"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LA.dir/src/Determinant.obj -MF CMakeFiles\LA.dir\src\Determinant.obj.d -o CMakeFiles\LA.dir\src\Determinant.obj -c "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Determinant.cpp"

CMakeFiles/LA.dir/src/Determinant.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LA.dir/src/Determinant.i"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Determinant.cpp" > CMakeFiles\LA.dir\src\Determinant.i

CMakeFiles/LA.dir/src/Determinant.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LA.dir/src/Determinant.s"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Determinant.cpp" -o CMakeFiles\LA.dir\src\Determinant.s

CMakeFiles/LA.dir/src/Fraction.obj: CMakeFiles/LA.dir/flags.make
CMakeFiles/LA.dir/src/Fraction.obj: CMakeFiles/LA.dir/includes_CXX.rsp
CMakeFiles/LA.dir/src/Fraction.obj: ../src/Fraction.cpp
CMakeFiles/LA.dir/src/Fraction.obj: CMakeFiles/LA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LA.dir/src/Fraction.obj"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LA.dir/src/Fraction.obj -MF CMakeFiles\LA.dir\src\Fraction.obj.d -o CMakeFiles\LA.dir\src\Fraction.obj -c "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Fraction.cpp"

CMakeFiles/LA.dir/src/Fraction.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LA.dir/src/Fraction.i"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Fraction.cpp" > CMakeFiles\LA.dir\src\Fraction.i

CMakeFiles/LA.dir/src/Fraction.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LA.dir/src/Fraction.s"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Fraction.cpp" -o CMakeFiles\LA.dir\src\Fraction.s

CMakeFiles/LA.dir/src/Matix.obj: CMakeFiles/LA.dir/flags.make
CMakeFiles/LA.dir/src/Matix.obj: CMakeFiles/LA.dir/includes_CXX.rsp
CMakeFiles/LA.dir/src/Matix.obj: ../src/Matix.cpp
CMakeFiles/LA.dir/src/Matix.obj: CMakeFiles/LA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LA.dir/src/Matix.obj"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LA.dir/src/Matix.obj -MF CMakeFiles\LA.dir\src\Matix.obj.d -o CMakeFiles\LA.dir\src\Matix.obj -c "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Matix.cpp"

CMakeFiles/LA.dir/src/Matix.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LA.dir/src/Matix.i"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Matix.cpp" > CMakeFiles\LA.dir\src\Matix.i

CMakeFiles/LA.dir/src/Matix.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LA.dir/src/Matix.s"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\src\Matix.cpp" -o CMakeFiles\LA.dir\src\Matix.s

# Object files for target LA
LA_OBJECTS = \
"CMakeFiles/LA.dir/src/Base.obj" \
"CMakeFiles/LA.dir/src/Determinant.obj" \
"CMakeFiles/LA.dir/src/Fraction.obj" \
"CMakeFiles/LA.dir/src/Matix.obj"

# External object files for target LA
LA_EXTERNAL_OBJECTS =

libLA.dll: CMakeFiles/LA.dir/src/Base.obj
libLA.dll: CMakeFiles/LA.dir/src/Determinant.obj
libLA.dll: CMakeFiles/LA.dir/src/Fraction.obj
libLA.dll: CMakeFiles/LA.dir/src/Matix.obj
libLA.dll: CMakeFiles/LA.dir/build.make
libLA.dll: CMakeFiles/LA.dir/linklibs.rsp
libLA.dll: CMakeFiles/LA.dir/objects1.rsp
libLA.dll: CMakeFiles/LA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library libLA.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LA.dir/build: libLA.dll
.PHONY : CMakeFiles/LA.dir/build

CMakeFiles/LA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LA.dir/clean

CMakeFiles/LA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator" "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator" "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build" "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build" "E:\My Programs\Projetc_NewBie\C++\linear algebra calculator\build\CMakeFiles\LA.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LA.dir/depend

