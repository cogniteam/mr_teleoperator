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

#add_executable(velocity_dispatcher src/VelocityDispatcher.cpp)
add_executable(joystick_teleoperator src/Joystick.cpp)

#target_link_libraries(velocity_dispatcher ${catkin_LIBRARIES})
target_link_libraries(joystick_teleoperator ${catkin_LIBRARIES})

#############
## Install ##
#############

install(TARGETS joystick_teleoperator
	RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch/
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)