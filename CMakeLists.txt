cmake_minimum_required(VERSION 3.0.2)
project(turtlebot_walker)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  message_generation
  laser_geometry
  tf
)

catkin_package(
 INCLUDE_DIRS include
)

include_directories(
include
  ${catkin_INCLUDE_DIRS}
)

add_executable(walker_node src/walker.cpp src/walker_node.cpp src/detect_obstacle.cpp)


target_link_libraries(walker_node
  ${catkin_LIBRARIES}
)