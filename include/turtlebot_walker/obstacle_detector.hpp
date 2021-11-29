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
 * @file obstacle_detector.hpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
#include <sensor_msgs/LaserScan.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <memory>

class ObstacleDetector {
 public:
    /**
     * @brief Construct a new Obstacle Detector object
     * 
     */
    ObstacleDetector();
    /**
     * @brief Checks if obstacle is nearby
     * 
     * @param msg 
     * @return std::string 
     */
    std::string isCloseToObstacle(const sensor_msgs::LaserScan::ConstPtr &msg);
    /**
     * @brief Destroy the Obstacle Detector object
     * 
     */
    ~ObstacleDetector();
    int range = 10;
};
