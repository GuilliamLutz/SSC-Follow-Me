//****************************************************************************
// TITLE        motorcontroller
// DESCRIPTION	publisher for the drive msgs to send instructions to the rosaria package
// FILE			MotorControl.h
// AUTHOR		R. Schonewille, G. Lutz
// DATE			15--2022
// ***************************************************************************

#pragma once
#include <ros/ros.h>
#include "geometry_msgs/Twist.h"


class Motorcontrol
{
private:
    ros::Publisher motor_pub;
    geometry_msgs::Twist driveMsg;

public:
    Motorcontrol(ros::NodeHandle *nh)
    {
        motor_pub = nh->advertise<geometry_msgs::Twist>("/RosAria/cmd_vel", 10);
    }

    void driveForward()
    {
        driveMsg.linear.x = 0.5;
        motor_pub.publish(driveMsg);
    }

    void driveBackwards()
    {
        driveMsg.linear.x = -0.2;
        motor_pub.publish(driveMsg);
    }

    void turnRight()
    {
        driveMsg.angular.z = -0.4;
        motor_pub.publish(driveMsg);
    }
    
     void turnLeft()
    {
        driveMsg.angular.z = 0.4;
        motor_pub.publish(driveMsg);
    }

    void resetDrive()
    {
        driveMsg.linear.x = 0;
        driveMsg.angular.z = 0;
        motor_pub.publish(driveMsg);
    }
};
