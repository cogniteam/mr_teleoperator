^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package mr_tools
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.2.1 (2013-12-04)
------------------

0.2.0 (2013-12-04)
------------------
* Update teleoperator.launch
* install fixed
* 'joystick_publisher' node changed to 'joystick_teleoperator'
* Information and version updated
* tabs replaced by spaces
* - mr_tools uses VelocityDispatcher instead of mr_teleoperator
  - joystick_publisher now publishes geometry_msgs/Twist message directly
  - new launch file created
* CMakeLists updated
* deprecated
* VelocityDispatcher (replaces MrTeleoperator) created
* Joystick node publishes Twist message directly
* mr_tools launch install added in CMakeLists.txt
* Initial commit
* Contributors: Igor Makhtes, Tommy
