MazeSolver
==========

#Description

This program implements the ADC library as well as the Motor Driver library available on my github profile.
The purpose of the program is to navigate a two-wheeled robot with three IR sensors around a maze without 
hitting the walls.

The program uses a left-wall-following algorithm.  If the left IR sensor reads a voltage that is too high,
this means that the robot is too close to the wall and it steers away.  If the voltage drops too low, the robot will turn
slightly left and get back on course.  If the voltage drops so low that the robot doesn't even see a wall, it will make a 
sweeping left turn.  This is primarily intended to navigate left-hand turns.  It can occasionally create problems when 
the robot's oscillation becomes to large and it always uses the sweeping turn instead of the minor course-correct.
The fourth major directional change the robot uses is if the front sensor detects a wall.  The robot will then execute a 
right-hand "tank turn" to avoid driving into the wall, and continue following the maze.

##Important Notes

- The robot's sensors are incredibly tempermental.  They are very sensitive to the envronment's lighting.  In a dark 
room for example, the robot will always steer right to avoid the imaginary left and front walls.  If the light is too 
intense, the robot may never actually recognize the wall.

- Battery charge has a dramatic effect on the robot.  Not only will it change the voltage readings of the IR sensors, 
but it will also effect the turning radius of the robot because all turns are based on a number of clock cycles that
the turn command executes at a time.  Generally, this will make the robot much more jittery and course-correct much more 
often as the voltage drops.
