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
 * @date 2021-11-29
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
  delete detect;
}

void Walker::init() {
    nh->param<int>("publish_rate", rate, 100);

    nh->param<std::string>("topic", topic, "/scan");

    this->vel_pub = this->nh->advertise<geometry_msgs::Twist>(
         "/cmd_vel", rate, this);

    this->lidar_sub = this->nh->subscribe("/scan",
                       rate, &Walker::lidarCallback, this);
}

void Walker::send_velocity(std::string obs) {
  geometry_msgs::Twist vel;
  if (obs != "")
    ROS_WARN("Obstacle Detected nearby");
  if (obs == "front") {
    vel.linear.x = 0.0;
    vel.angular.z = 0.5;
  } else if (obs == "right") {
    vel.linear.x = 0.0;
    vel.angular.z = 0.3;
  } else if (obs == "left") {
    vel.linear.x = 0.0;
    vel.angular.z = -0.3;
  } else if (obs == "west") {
    vel.linear.x = 0.1;
    vel.angular.z = -0.1;
  } else if (obs == "east") {
    vel.linear.x = 0.1;
    vel.angular.z = 0.1;
  } else {
    vel.linear.x = 0.3;
    vel.angular.z = 0.0;
  }
  vel_pub.publish(vel);
}

void Walker::lidarCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    std::string obs = detect->isCloseToObstacle(msg);
    send_velocity(obs);
}

void Walker::start_walking() {
  ros::Rate loop_rate(rate);
  while (ros::ok()) {
    ros::spinOnce();
    loop_rate.sleep();
  }
}

