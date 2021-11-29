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
 * @file talker.cpp
 * @author Siddharth Telang (stelang@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/turtlebot_walker/walker.hpp"

Walker::Walker(ros::NodeHandle *nh_) {
  nh = nh_;
  init();
}

Walker::~Walker() {
  delete nh;
}

void lidarCallback(const sensor_msgs::LaserScan::ConstPtr &msg) {
ROS_INFO_STREAM("Received scan");
}

void Walker::init() {
    nh->param<int>("publish_rate", rate, 100);
    nh->param<std::string>("topic", topic, "/scan");
    lidar_sub = nh->subscribe(topic, 100, &Walker::lidarCallback, this);
}

void Walker::start_walking() {
  ros::Rate loop_rate(rate);
  while (ros::ok()) {
    ros::spinOnce();
    loop_rate.sleep();
  }
}

