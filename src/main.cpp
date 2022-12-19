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
#include <chrono>
#include <thread>

////////////////////////////////////////////////////////////////////////////////
// namespaces
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Define ROS publishers
usStruct testvalue;

////////////////////////////////////////////////////////////////////////////////
// function prototypes


////////////////////////////////////////////////////////////////////////////////
// memberfunction run()

int main (int argc, char **argv)
{
        ros::init(argc, argv, "usSystem");
        ros::NodeHandle nh;
        
        us Us1 = us(&nh);

        while(ros::ok())
        {
                testvalue = Us1.getSensorValue();
                
                ROS_INFO("left [%i]",testvalue.left);
                ROS_INFO("leftCorner [%i]",testvalue.leftCorner);
                ROS_INFO("lefFront [%i]",testvalue.lefFront);
                ROS_INFO("rightFront [%i]",testvalue.rightFront);
                ROS_INFO("rightCorner [%i]",testvalue.rightCorner);
                ROS_INFO("right [%i]",testvalue.right);
                ROS_INFO("rear [%i]",testvalue.rear);
                ROS_INFO("error [%i]",testvalue.error);
                ROS_INFO("-----------------------------");
                
                ros::spinOnce();

                std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        
}

////////////////////////////////////////////////////////////////////////////////
// functions
