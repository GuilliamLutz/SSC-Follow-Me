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
#include <visionClass.cpp>
#include <visionClass.h>


////////////////////////////////////////////////////////////////////////////////
// namespaces
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Define ROS publishers


////////////////////////////////////////////////////////////////////////////////
// function prototypes


////////////////////////////////////////////////////////////////////////////////
// memberfunction run()

int main (int argc, char **argv)
{
    ros::init(argc, argv, "oakD_topic");
    ros::NodeHandle nh;
    Vision nc = Vision(&nh);
    ros::spin();
}

////////////////////////////////////////////////////////////////////////////////
// functions