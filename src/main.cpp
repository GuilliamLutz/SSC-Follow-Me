//****************************************************************************
// TITLE        Main System ROS wrapper
// DESCRIPTION	implementation of main program to gather sensor info trough their classes and make the data ROS ready
// FILE			main.cpp
// AUTHOR		R. Schonewille
// DATE			25-nov-2022
// ***************************************************************************
 
////////////////////////////////////////////////////////////////////////////////
// includes
#include <ros/ros.h>
#include "visionClass.h"


////////////////////////////////////////////////////////////////////////////////
// namespaces
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// testing
float testvalue = 1;

////////////////////////////////////////////////////////////////////////////////
// function prototypes


////////////////////////////////////////////////////////////////////////////////
// memberfunction run()

int main (int argc, char **argv)
{
        ros::init(argc, argv, "visionSystem");
        ros::NodeHandle nh;
        while(ros::ok())
        {
                Vision oakD(&nh);
                oakD.getObjectID(testvalue);
                ROS_INFO("From main I post:[%f]",testvalue);
                ros::spinOnce();
        }
}

////////////////////////////////////////////////////////////////////////////////
// functions