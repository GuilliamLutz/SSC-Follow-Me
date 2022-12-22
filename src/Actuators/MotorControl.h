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

// typical values: TURN_SPEED > 0.4, DRIVE_SPEED > 0.5
static float TURN_SPEED = 0.3;
static float DRIVE_SPEED = 0.3;
static float SPEED_LIMIT = 0.5;

static float Z_SPEED = 0.0006;
static float X_SPEED = 0.001;


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
        driveMsg.linear.x = DRIVE_SPEED;
        driveMsg.angular.z = 0;
        motor_pub.publish(driveMsg);
    }

    void driveBackwards()
    {
        driveMsg.linear.x = -0.2;
        motor_pub.publish(driveMsg);
    }

    void turnRight()
    {
        driveMsg.angular.z = -TURN_SPEED;
        motor_pub.publish(driveMsg);
    }
    
     void turnLeft()
    {
        driveMsg.angular.z = TURN_SPEED;
        motor_pub.publish(driveMsg);
    }

    void resetDrive()
    {
        driveMsg.linear.x = 0;
        driveMsg.angular.z = 0;
        motor_pub.publish(driveMsg);
    }

    void strafeLeft() 
    {
        driveMsg.linear.x = DRIVE_SPEED;
        driveMsg.angular.z = TURN_SPEED;
        motor_pub.publish(driveMsg);
    }

    void strafeRight()
    {
        driveMsg.linear.x = DRIVE_SPEED;
        driveMsg.angular.z = -TURN_SPEED;
        motor_pub.publish(driveMsg);
    }

    void drive(float x, float z) 
    {
        z = z - 1000;
        if (z <= 0)
        {
            z = 0;
            x = -x * X_SPEED * 3;
            if (x > SPEED_LIMIT)
            {
                x = SPEED_LIMIT;
            }
        }
        else 
        {
            x = -x * X_SPEED;
        }
        if ((z * Z_SPEED) > SPEED_LIMIT) 
        {
            z = SPEED_LIMIT;
        }
        else
        {
            z = z * Z_SPEED;
        }
        driveMsg.linear.x = z;
        driveMsg.angular.z = x;
        motor_pub.publish(driveMsg);
    }
};
