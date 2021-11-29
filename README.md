[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
---
# turtlebot_walker
## Introduction
Simple Walker algorithm for TurtleBot3 with obstacle avoidance

## Assumptions/Dependencies
ROS Melodic

## Gazebo Simulation Map
Custom world used
 - worlds/map.world

## Building the package
1) Create a catkin workspace catkin_ws

2) Clone the turlebot3 package inside catkin_ws/src using 

``` 
git clone https://github.com/ROBOTIS-GIT/turtlebot3.git   
git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git    
```
Refer this [link](https://automaticaddison.com/how-to-launch-the-turtlebot3-simulation-with-ros/).

4) Clone the turtlebot_walker package
```
git clone https://github.com/siddharthtelang/turtlebot_walker.git

```
4) Go back to catkin_ws
```
cd catkin_ws
```
5) compile 

``` 
catkin build 
```

## How to run the code

1) Source the workspace

```
source devel/setup.bash
```

2) Launch the launchfile

```
roslaunch turtlebot_walker walker_avoid_obstacle.launch
```

3) With ROSBag enabled
 - update the directory argument in launch file rosbag_directory
```
roslaunch turtlebot_walker walker_avoid_obstacle.launch record_bag:=true rosbag_directory:='/home/siddharth/ENPM808X/catkin/src/turtlebot_walker/rosbag'
```


## Recording the bag file
- Set the record_bag param true in the launch file or while launching the launch file


## Recording bag file through command line
```
rosbag record -a -x '(.*)/camera(.*)' -O record_bag.bag -a --duration 30
```

## Running the bag file
```
rosbag play <bagfile_name> --pause
```

## Bag file and test videos
https://drive.google.com/drive/folders/1snH6yK4TECaIBBCA1JaZIra0Roafp13m?usp=sharing