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
CMAKE_SOURCE_DIR = "E:\My Programs\Projetc_NewBie\C++\Inventory Management System"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\build"

# Include any dependencies generated for this target.
include CMakeFiles/operations.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/operations.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/operations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/operations.dir/flags.make

CMakeFiles/operations.dir/src/goods.cpp.obj: CMakeFiles/operations.dir/flags.make
CMakeFiles/operations.dir/src/goods.cpp.obj: CMakeFiles/operations.dir/includes_CXX.rsp
CMakeFiles/operations.dir/src/goods.cpp.obj: ../src/goods.cpp
CMakeFiles/operations.dir/src/goods.cpp.obj: CMakeFiles/operations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\My Programs\Projetc_NewBie\C++\Inventory Management System\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/operations.dir/src/goods.cpp.obj"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/operations.dir/src/goods.cpp.obj -MF CMakeFiles\operations.dir\src\goods.cpp.obj.d -o CMakeFiles\operations.dir\src\goods.cpp.obj -c "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\src\goods.cpp"

CMakeFiles/operations.dir/src/goods.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operations.dir/src/goods.cpp.i"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\src\goods.cpp" > CMakeFiles\operations.dir\src\goods.cpp.i

CMakeFiles/operations.dir/src/goods.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operations.dir/src/goods.cpp.s"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\src\goods.cpp" -o CMakeFiles\operations.dir\src\goods.cpp.s

CMakeFiles/operations.dir/src/function.cpp.obj: CMakeFiles/operations.dir/flags.make
CMakeFiles/operations.dir/src/function.cpp.obj: CMakeFiles/operations.dir/includes_CXX.rsp
CMakeFiles/operations.dir/src/function.cpp.obj: ../src/function.cpp
CMakeFiles/operations.dir/src/function.cpp.obj: CMakeFiles/operations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\My Programs\Projetc_NewBie\C++\Inventory Management System\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/operations.dir/src/function.cpp.obj"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/operations.dir/src/function.cpp.obj -MF CMakeFiles\operations.dir\src\function.cpp.obj.d -o CMakeFiles\operations.dir\src\function.cpp.obj -c "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\src\function.cpp"

CMakeFiles/operations.dir/src/function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operations.dir/src/function.cpp.i"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\src\function.cpp" > CMakeFiles\operations.dir\src\function.cpp.i

CMakeFiles/operations.dir/src/function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operations.dir/src/function.cpp.s"
	D:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\src\function.cpp" -o CMakeFiles\operations.dir\src\function.cpp.s

# Object files for target operations
operations_OBJECTS = \
"CMakeFiles/operations.dir/src/goods.cpp.obj" \
"CMakeFiles/operations.dir/src/function.cpp.obj"

# External object files for target operations
operations_EXTERNAL_OBJECTS =

liboperations.dll: CMakeFiles/operations.dir/src/goods.cpp.obj
liboperations.dll: CMakeFiles/operations.dir/src/function.cpp.obj
liboperations.dll: CMakeFiles/operations.dir/build.make
liboperations.dll: CMakeFiles/operations.dir/linklibs.rsp
liboperations.dll: CMakeFiles/operations.dir/objects1.rsp
liboperations.dll: CMakeFiles/operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\My Programs\Projetc_NewBie\C++\Inventory Management System\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library liboperations.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\operations.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/operations.dir/build: liboperations.dll
.PHONY : CMakeFiles/operations.dir/build

CMakeFiles/operations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\operations.dir\cmake_clean.cmake
.PHONY : CMakeFiles/operations.dir/clean

CMakeFiles/operations.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\My Programs\Projetc_NewBie\C++\Inventory Management System" "E:\My Programs\Projetc_NewBie\C++\Inventory Management System" "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\build" "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\build" "E:\My Programs\Projetc_NewBie\C++\Inventory Management System\build\CMakeFiles\operations.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/operations.dir/depend

