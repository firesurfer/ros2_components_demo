cmake_minimum_required(VERSION 2.8.3)

project(ros2_components_msg)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -g")
endif()

find_package(ament_cmake REQUIRED)

find_package(builtin_interfaces REQUIRED)

find_package(rosidl_default_generators REQUIRED)



file(GLOB SERVICE_FILES
    "srv/*.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}_msgs
  #${MESSAGE_FILES}
  ${SERVICE_FILES}
  DEPENDENCIES builtin_interfaces
)

#target_link_libraries(${PROJECT_NAME}_msgs)

project(ros2_components)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -g")
endif()

find_package(ament_cmake REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rmw REQUIRED)
find_package(rmw_implementation_cmake REQUIRED)
find_package(std_msgs REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ros2_components
    ${CMAKE_CURRENT_SOURCE_DIR}/src/demo
    ${CMAKE_CURRENT_SOURCE_DIR}/src/exec
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${rclcpp_INCLUDE_DIRS}
    ${rmw_INCLUDE_DIRS}
    ${rmw_implementation_INCLUDE_DIRS}
    ${std_msgs_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
)
file(GLOB SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ros2_components/*.c*"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/demo/*.c*"
)
add_library(ros2_components${target_suffix}
    ${SRC_FILES}
)
add_executable(demo_parameter_server
		${CMAKE_CURRENT_SOURCE_DIR}/src/exec/parameter_server.cpp)
add_executable(demo_server
		${CMAKE_CURRENT_SOURCE_DIR}/src/exec/server.cpp)
add_executable(demo_client
		${CMAKE_CURRENT_SOURCE_DIR}/src/exec/client.cpp)

target_link_libraries(ros2_components
    ${rclcpp_LIBRARIES}
    ${rmw_LIBRARIES}
    ${rmw_implementation_LIBRARIES}
    ${std_msgs_LIBRARIES}
    -pthread
    Qt5::Core

)

target_link_libraries(demo_parameter_server
    ros2_components
    ${rclcpp_LIBRARIES}
    ${rmw_LIBRARIES}
    ${rmw_implementation_LIBRARIES}
    ${std_msgs_LIBRARIES}
    -pthread
    Qt5::Core

)

target_link_libraries(demo_server
    ros2_components
    ${rclcpp_LIBRARIES}
    ${rmw_LIBRARIES}
    ${rmw_implementation_LIBRARIES}
    ${std_msgs_LIBRARIES}
    -pthread
    Qt5::Core
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_generator_c.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_introspection_cpp.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_introspection_c.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_opensplice_cpp.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_opensplice_c.so


)


target_link_libraries(demo_client

    ros2_components
    ${rclcpp_LIBRARIES}
    ${rmw_LIBRARIES}
    ${rmw_implementation_LIBRARIES}
    ${std_msgs_LIBRARIES}
    -pthread
    Qt5::Core

    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_generator_c.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_introspection_cpp.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_introspection_c.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_opensplice_cpp.so
    ${CMAKE_CURRENT_BINARY_DIR}/libros2_components_msg_msgs__rosidl_typesupport_opensplice_c.so
)
file(GLOB INCLUDE_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*"
)
message(STATUS "FILES TO INSTALL (ROS2_COMPONENTS)")
message(STATUS ${INCLUDE_FILES})
install(FILES ${INCLUDE_FILES} DESTINATION include/ros2_components) 



ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})

ament_package()
