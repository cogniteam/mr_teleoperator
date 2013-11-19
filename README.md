mr_teleoperator
===============

<strong>Multi-robot teleoperation package collection</strong>

A collection  of teleoperation modules utilizing a joystick (XboX, PS) to control multiple robots.

This collection includes: 
<ul> 
  <li>
    Rqt plugin  for selecting and controling a specific robot.
  </li>
   <li>
   The node publishes a geometry_msgs/Twist message type.
   </li>
</ul> 


<strong>Example:</strong>

<code>
roslaunch mr_tools joystick_teleop.launch
</code>
