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

struct usStruct
{          
    bool left;
    bool leftCorner;     
    bool lefFront;
    bool rightFront;
    bool rightCorner;
    bool right;   
    bool rear; 
    bool error;  
};

// US Class
class us
{

private:
    //ros variable
    ros::Subscriber us_sub;

	// private variables
    int sensorValue;
    int compare;
    bool usTemp[8];    
    usStruct usValues;

public:   
	// constructors
    // Ros vision subscriber 
    us(ros::NodeHandle *nh)
    {  
        us_sub = nh->subscribe("/objDetectedTopic", 1000, &us::callback_data, this);
    }
    
     //Getters
    usStruct getSensorValue()
    {
        return usValues;
    }
    
    //Callback for ROS
    void callback_data(const std_msgs::UInt8& msg)
    {
        fillStruct(msg.data);
    }

    // fill usStruct with sensor values
    void fillStruct(int data)
    {
        compare = 128;

        // splits data integer into array of bools
        for (int i = 0; i < 8; i++)
        {
            if (compare <= data)
            {
                usTemp[i] = true;
                data = data - compare;
            }
            else
            {
                usTemp[i] = false;
            }
            compare = compare / 2;
        }

        usValues.left = usTemp[0];
        usValues.leftCorner = usTemp[1];
        usValues.lefFront = usTemp[2];
        usValues.rear = usTemp[3];
        usValues.right = usTemp[4];
        usValues.rightCorner = usTemp[5];
        usValues.rightFront = usTemp[6];
        usValues.error = usTemp[7];
    }
};


