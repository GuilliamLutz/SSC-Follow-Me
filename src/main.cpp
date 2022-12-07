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
#include "usClass.h"


////////////////////////////////////////////////////////////////////////////////
// namespaces
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Define ROS publishers
int testvalue = 0;

////////////////////////////////////////////////////////////////////////////////
// function prototypes


////////////////////////////////////////////////////////////////////////////////
// memberfunction run()

int main (int argc, char **argv)
{
        ros::init(argc, argv, "usSystem");
        ros::NodeHandle nh;

        us Us1 = us(&nh);
        us.getTestValue(testvalue);
        ROS_INFO("[%i]",testvalue);
     
        ros::spin();
}

////////////////////////////////////////////////////////////////////////////////
// functions