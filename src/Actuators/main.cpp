//****************************************************************************
// TITLE        Main System ROS wrapper
// DESCRIPTION	implementation of main program to gather sensor info trough their classes and make the data ROS ready
// FILE			main.cpp
// AUTHOR		R. Schonewille
// DATE			25-nov-2022
// ***************************************************************************

#include "ros/ros.h"
#include "visionClass.h"
#include "usClass.h"
#include "MotorControl.h"

int operatorID;
float operatorX = 0;
float operatorY = 0;
float operatorZ = 0;
usStruct usData;
personCoordinates xyzStruct;


enum caseStates {Init, Idle, Follow, Obstacle};


///proto's
bool isErrorUSDetected(struct usStruct usFunctionData);
bool isUSObjectDetected(struct usStruct usFuctionData);

int main(int argc,char **argv)
{
    ros::init(argc, argv, "StateMachine");
    ros::NodeHandle n;

    Vision oakD =  Vision(&n);
    Motorcontrol pioneer = Motorcontrol(&n);
    us us100s = us(&n);

    caseStates currentState = Init;
    
    while (ros::ok())
    {
        // Obstacle detected
        usData = us100s.getSensorValue();
        // Persoon met ID 1 volgen
        xyzStruct = oakD.getXYZCoordinates();
        operatorID = oakD.getPersonID();
        operatorX = xyzStruct.x;
        operatorY = xyzStruct.y;
        operatorZ = xyzStruct.z;

        if (isUSObjectDetected(usData) && !isErrorUSDetected(usData))
        {
            pioneer.resetDrive();
            ROS_INFO("Drive are set to 0, object detected within 30cm range");
        }
        else
        {

            switch(currentState)
            {
                // Case 1: Init (currently obsolete)
                case Init:
                // Initialize Motorcontroller
                // Check conditions 
                    currentState = Idle;
                break; 

                // Case 2: Idle mode (currently obsolete)
                case Idle:
                
                //if(Follow_start)
                //{
                    currentState = Follow;
                //}
                
                break;

                // Case 3: Follow mode
                case Follow:
                    if (operatorID == 1)
                    {
                        pioneer.drive(operatorX, operatorZ);
                    }
                    else
                    {
                        pioneer.resetDrive();
                    }
                break;

            }
        }  
        ros::spinOnce();
    }
 
    return 0;
}


bool isUSObjectDetected(usStruct usFunctionData)
{
    if (usData.left || usData.leftCorner || usData.leftFront || usData.rightFront || usData.rightCorner || usData.right || usData.rear)
    {
        return true;
    }
    else return false;
}

bool isErrorUSDetected(usStruct usFunctionData)
{
    if(usData.error == true)
    {
        return true;
    }
    else return false;

    
}
