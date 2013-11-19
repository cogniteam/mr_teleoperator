cmake_minimum_required(VERSION 2.8.3)
project(mr_tools)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  tf
)

find_package(Boost REQUIRED COMPONENTS system)

catkin_package()

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(mr_teleoperator src/MrTeleoperator.cpp)

add_executable(joystick_publisher src/Joystick.cpp)

target_link_libraries(joystick_publisher
  ${catkin_LIBRARIES}
)

target_link_libraries(mr_teleoperator
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

install(TARGETS mr_teleoperator joystick_publisher
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)