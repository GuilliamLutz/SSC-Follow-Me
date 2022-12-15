
#pragma once
#include <ros/ros.h>
#include "geometry_msgs/Twist.h"


class Motorcontrol
{
private:
    ros::Publisher motor_pub;
    geometry_msgs::Twist forwardmsg;

public:
    Motorcontrol(ros::NodeHandle *nh)
    {
        motor_pub = nh->advertise<geometry_msgs::Twist>("/RosAria/cmd_vel", 10);
    }

    void driveForward()
    {
        forwardmsg.linear.x = 0.5;
        motor_pub.publish(forwardmsg);
    }

    void driveBackward()
    {
        
    }

    void resetDrive()
    {
        forwardmsg.linear.x = 0;
        motor_pub.publish(forwardmsg);
    }
};
