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
#include "math.h"

// typical values: TURN_SPEED > 0.4, DRIVE_SPEED > 0.5
static float TURN_SPEED = 0.3;
static float DRIVE_SPEED = 0.3;
static float SPEED_LIMIT = 1;
static int MINIMAL_DISTANCE = 1000;

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
        x = -1.5 * atan(x/z);


        // if (x > SPEED_LIMIT) 
        // {
        //     x = 0.5;
        // }

        z = (z - MINIMAL_DISTANCE) * Z_SPEED;

        if (z <= 0)
        {
            z = 0;
        }
        else if ((z) > SPEED_LIMIT) 
        {
            z = SPEED_LIMIT;
        }

        driveMsg.linear.x = z;
        driveMsg.angular.z = x;
        motor_pub.publish(driveMsg);
    }
};
