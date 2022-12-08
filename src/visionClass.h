//****************************************************************************
// TITLE        visionClass
// DESCRIPTION	Class definition for a vision sensor
// FILE			visionClass.h
// AUTHOR		R. Schonewille
// DATE			25-nov-2022
// ***************************************************************************

#pragma once
#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
using namespace std;
struct personCoordinates {float x; float y; float z;};

// Vision Class

class Vision
{
private:
    //ros variable
    ros::Subscriber vision_sub;

	// private variables
    float personID = 0;
    struct personCoordinates personCoordinates;

public:
	// constructors
    // Ros vision subscriber 
    Vision();

    Vision(ros::NodeHandle *nh)
    {  
        vision_sub = nh->subscribe("/VisionData", 1000, &Vision::callback_data, this);
    }

    // Member functions for visionClass
     //Getters
    float getPersonID()
    {
        return this-> personID;
    }

    struct personCoordinates getXYZCoordinates()
    {
        return this-> personCoordinates;
    }
    //Callback for ROS
    void callback_data(const std_msgs::Float32MultiArray::ConstPtr& msg)
    {
        this -> personID = msg->data[0];
        this -> personCoordinates.x = msg->data[1];
        this -> personCoordinates.y = msg->data[2];
        this -> personCoordinates.z = msg->data[3];
       // setObjectID(msg->data[0]);
       //this->objectID = msg->data[0];
       //ROS_INFO("I heard: [%f]", msg->data[0]);
       // ROS_INFO("I heard: [%f]", aa);
    }
};

