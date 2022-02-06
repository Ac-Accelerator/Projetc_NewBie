project(LAC)
add_library(LA SHARED ./src/Base.cpp ./src/Determinant.cpp ./src/Fraction.cpp ./src/Matix.cpp )

target_include_directories(LA PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(LAC src/main.cpp)
target_link_libraries(LAC LA)
target_link_libraries (LAC -static gcc stdc++ winpthread -dynamic)