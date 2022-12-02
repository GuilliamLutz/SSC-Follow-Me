//****************************************************************************
// TITLE        usClass
// DESCRIPTION	Class definition for using a set of 7 US-100 sesores integrated on Arduino board with pub
// FILE		    usClass.h
// AUTHOR	    R. Schonewille
// DATE		    2-dec-2022
// ***************************************************************************

#include <ros/ros.h>
#include <geometry_msgs/Int16.h>
using namespace std;

// US Class

class us
{
private:
    //ros variable
        ros::Subscriber us_sub;

    // private variables
        bool errorDetected;
        bool usObjectDetected[7];
        bool byteValuesFromUS[8];
public:   
	// constructors
    // Ros vision subscriber 
    us(ros::NodeHandle *nh)
    {  
        us_sub = nh->subscribe("/objDetectedTopic", 1000, &us::callback_data, this);
    }

    // Member functions for visionClass

    //Setters
    void IntToByte(int intValue)
    {
        char bytes[sizeof intValue];
        std::copy(static_cast<const char*>(static_cast<const void*>(&x)),
          static_cast<const char*>(static_cast<const void*>(&x)) + sizeof intValue,
          bytes);

          this -> byteValuesFromUS[8] = bytes;
    }

    void determineObjectDetected(byte )
    {
 
    }
     //Getters
    
    
    //Callback for ROS
    void callback_data(const geometry_msgs::Int16& msg)
    {
         
    }

};

