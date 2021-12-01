#工程名字Goods_Project
project(Goods_Project)
#新建名字为operation的动态库,包含先对路径下的两个源文件
add_library(operations SHARED ./src/goods.cpp ./src/function.cpp)
#为库指定头文件的路径
target_include_directories(operations PUBLIC ./include)
#用main.cpp创建可执行文件outcome
add_executable(outcome ./src/main.cpp)
#连接库到可执行文件上
target_link_libraries(outcome operations)