//****************************************************************************
// TITLE        uwbClass
// DESCRIPTION	Class definition for using ultrawideband dev kit of PoZyX
// FILE		uwbClass.h
// AUTHOR	R. Schonewille
// DATE		2-dec-2022
// ***************************************************************************

#pragma once
#include <ros/ros.h>
#include <geometry_msgs/Point32.h>
using namespace std;

// Vision Class

class uwb
{
private:
    //ros variable
        ros::Subscriber uwb_sub;

    // private variables
        float xpersonCoordinate = 0;
        float ypersonCoordinate = 0;
        float tagId = 0;

public:   
	// constructors
    // Ros vision subscriber 
    uwb(ros::NodeHandle *nh)
    {  
        uwb_sub = nh->subscribe("/pozyx_positioning", 1000, &uwb::callback_data, this);
    }

    // Member functions for visionClass

    //Setters
    void setTagId(float tagId)
    {
       this-> tagId = tagId; 
    }

    void setXYCoordinates(float xpersonCoordinate, float ypersonCoordinate)
    {
       this-> xpersonCoordinate = xpersonCoordinate,
       this-> ypersonCoordinate = ypersonCoordinate,      
    }

     //Getters
    void tagId(float& tagId)
    {
        tagId = this-> tagId;
    }

    void getXYCoordinates(float& xpersonCoordinate, float& ypersonCoordinate)
    {
        xpersonCoordinate = this-> xpersonCoordinate;
        ypersonCoordinate = this-> ypersonCoordinate;
    }
    //Callback for ROS
    void callback_data(const geometry_msgs::Point32::ConstPtr& msg)
    {
        this -> tagId = msg->data[0];
        setTagId(msg->data[0]);
        
        this -> xpersonCoordinate = msg->data[0];
        this -> ypersonCoordinate = msg->data[0];
        setXYCoordinates(msg->data[1],msg->data[2]);
        
   //    ROS_INFO("I heard: [%f]", msg->data[0]);
    }

};

