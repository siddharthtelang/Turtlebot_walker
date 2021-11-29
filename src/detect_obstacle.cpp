/**
 * @file detect_obstacle.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/turtlebot_walker/obstacle_detector.hpp"

ObstacleDetector::ObstacleDetector() {}

ObstacleDetector:: ~ObstacleDetector () {}

std::string ObstacleDetector::isCloseToObstacle(const sensor_msgs::LaserScan::ConstPtr &msg) {
    std::string obs {};

    if (msg->ranges[2] < 1.0 || msg->ranges[358] < 1.0)
        obs = "front";
    
    else if (msg->ranges[20] < 0.5)
        obs = "left";
   
    else if  (msg->ranges[340] < 0.5)
        obs = "right";

    else if (msg->ranges[90] < 0.3)
        obs = "west";
    
    else if (msg->ranges[270] < 0.3)
        obs = "east";

    return obs;
}
