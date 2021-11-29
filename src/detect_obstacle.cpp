/**
 * MIT License
 *
 * Copyright (c) 2021 Siddharth Telang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
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

ObstacleDetector:: ~ObstacleDetector() {}

std::string ObstacleDetector::isCloseToObstacle
                    (const sensor_msgs::LaserScan::ConstPtr &msg) {
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
