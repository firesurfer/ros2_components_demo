cmake_minimum_required(VERSION 2.8.3)

set(WORKSPACE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
include(findPackageInWorkspace.cmake)


project(ros2_components_demo)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -g")
endif()

option(LocalBuild "LocalBuild" OFF)
if(LocalBuild)
MESSAGE("Doing a local build")
findPackageInWorkspace(ros2_components_msg)
findPackageInWorkspace(ros2_components)
findPackageInWorkspace(kairo3_msgs)
findPackageInWorkspace(kairo3_components)
findPackageInWorkspace(ros2_simple_logger)
endif()

find_package(ament_cmake REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rmw REQUIRED)
find_package(rmw_implementation_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros2_components REQUIRED)
find_package(ros2_components_msg REQUIRED)
find_package(ros2_simple_logger REQUIRED)


#Needed for QT
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    	${rclcpp_INCLUDE_DIRS}
    	${rmw_INCLUDE_DIRS}
    	${rmw_implementation_INCLUDE_DIRS}
    	${std_msgs_INCLUDE_DIRS}
    	${Qt5Core_INCLUDE_DIRS}
	${ros2_components_INCLUDE_DIRS}
	${ros2_components_msg_INCLUDE_DIRS}
	${ros2_simple_logger_INCLUDE_DIRS}
	${CMAKE_CURRENT_SOURCE_DIR}/src/demo
)
#Get source files
file(GLOB SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/demo/*.c*"
)
add_library(ros2_components_demo${target_suffix}
    ${SRC_FILES}
)
add_executable(demo_parameter_server
		${CMAKE_CURRENT_SOURCE_DIR}/src/exec/parameter_server.cpp)
add_executable(demo_server
		${CMAKE_CURRENT_SOURCE_DIR}/src/exec/server.cpp)
add_executable(demo_client
		${CMAKE_CURRENT_SOURCE_DIR}/src/exec/client.cpp)
            MESSAGE(${ros2_components_LIBRARIES})
target_link_libraries(ros2_components_demo${target_suffix}
 	${ros2_components_LIBRARIES}
    	${rclcpp_LIBRARIES}
    	${rmw_LIBRARIES}
    	${rmw_implementation_LIBRARIES}
    	${std_msgs_LIBRARIES}
	${ros2_simple_logger_LIBRARIES}
    	-pthread
    	Qt5::Core
)

target_link_libraries(demo_parameter_server${target_suffix}
    ${rclcpp_LIBRARIES}
    ${rmw_LIBRARIES}
    ${rmw_implementation_LIBRARIES}
    ${std_msgs_LIBRARIES}
${ros2_simple_logger_LIBRARIES}
    -pthread
    Qt5::Core

)

target_link_libraries(demo_server${target_suffix}
    ${ros2_components_LIBRARIES}
${ros2_components_msg_LIBRARIES}
    ros2_components_demo${target_suffix}
    ${rclcpp_LIBRARIES}
    ${rmw_LIBRARIES}
    ${rmw_implementation_LIBRARIES}
    ${std_msgs_LIBRARIES}
${ros2_simple_logger_LIBRARIES}
    -pthread
    Qt5::Core
   

)


target_link_libraries(demo_client${target_suffix}
	ros2_components_demo${target_suffix}
	${ros2_components_LIBRARIES}
${ros2_components_msg_LIBRARIES}
    	${rclcpp_LIBRARIES}
   	${rmw_LIBRARIES}
    	${rmw_implementation_LIBRARIES}
    	${std_msgs_LIBRARIES}
    	-pthread
    	Qt5::Core

    
)

install(TARGETS demo_parameter_server${target_suffix} DESTINATION bin)
install(TARGETS demo_server${target_suffix} DESTINATION bin)
install(TARGETS demo_client${target_suffix} DESTINATION bin)


ament_package()
