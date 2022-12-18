//****************************************************************************
// TITLE        usClass
// DESCRIPTION	Class definition for using a set of 7 US-100 sesores integrated on Arduino board with pub
// FILE		    usClass.h
// AUTHOR	    R. Schonewille
// DATE		    2-dec-2022
// ***************************************************************************

#include <ros/ros.h>
#include <std_msgs/UInt8.h>
using namespace std;

// US Class

class us
{
private:
    //ros variable
    ros::Subscriber us_sub;

	// private variables
    bool errorDetected;
    int sensorValue;

public:   
	// constructors
    // Ros vision subscriber 
    us(ros::NodeHandle *nh)
    {  
        us_sub = nh->subscribe("/objDetectedTopic", 1000, &us::callback_data, this);
    }
    
     //Getters
    int getSensorValue()
    {
        return sensorValue;
    }

    bool getErrorDetected()
    {
        return errorDetected;
    }
    
    //Callback for ROS
    void callback_data(const std_msgs::UInt8& msg)
    {
        this -> sensorValue = msg.data;
        if (sensorValue % 2)
        {
            errorDetected = true;
            sensorValue--;
        }
        else 
        {
            errorDetected = false;
        }
    }

};

