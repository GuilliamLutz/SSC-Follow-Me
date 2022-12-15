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
personCoordinates teststruct;
int personIDTest = 0;


////////////////////////////////////////////////////////////////////////////////
// function prototypes


////////////////////////////////////////////////////////////////////////////////
// memberfunction run()

int main (int argc,char **argv)
{
        ros::init(argc, argv, "visionSystem");
        ros::NodeHandle nh;
        Vision oakD = Vision(&nh);
        while(ros::ok())
          {
           //     teststruct = oakD.getXYZCoordinates();
                personIDTest = oakD.getPersonID();
                teststruct = oakD.getXYZCoordinates();
                ROS_INFO("[%i]",personIDTest);  
                ROS_INFO("From main I post x value:[%f]",teststruct.x);
                ROS_INFO("From main I post y value:[%f]",teststruct.y);
                ROS_INFO("From main I post z value:[%f]",teststruct.z);
               
                ros::spinOnce();
          }       
}

////////////////////////////////////////////////////////////////////////////////
// functions