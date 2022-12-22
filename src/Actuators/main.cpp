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

static int THRESHOLD_X = 250;
static int THRESHOLD_Z = 1000;


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
                // Case 1: Init
                case Init:
                // Initialize Motorcontroller
                // Check conditions 
                    currentState = Idle;
                break; 

                // Case 2: Idle mode
                case Idle:
                
                //if(Follow_start)
                //{
                    currentState = Follow;
                //}
                
                break;

                // Case 3: Follow mode
                case Follow:
                //ROS_INFO("From main I post:[%f]",operatorZ);
                    if (operatorID == 1)
                    {
                        pioneer.drive(operatorX, operatorZ);
                        
                        // if (operatorZ >= THRESHOLD_Z && operatorX >= THRESHOLD_X)
                        // {
                        //     pioneer.strafeRight();
                        //     ROS_INFO("strafe right");

                        // }
                        // else if (operatorZ >= THRESHOLD_Z && operatorX <= -THRESHOLD_X)
                        // {
                        //     pioneer.strafeLeft();
                        //     ROS_INFO("strafe left");

                        // }
                        // else if (operatorZ >= THRESHOLD_Z)
                        // {
                        //     pioneer.driveForward();
                        //     ROS_INFO("forward");

                        // }
                        // else if(operatorX >= THRESHOLD_X)
                        // {
                        //     pioneer.turnRight();
                        //     ROS_INFO("right");
                        // }
                        // else if(operatorX <= -THRESHOLD_X)
                        // {
                        //     pioneer.turnLeft();
                        //     ROS_INFO("left");
                        // }
                        // // backwards drive not working at the moment
                        // else if(operatorZ <= 1000.0 && operatorID == 1)
                        // {
                        //     pioneer.driveBackwards();
                        //     ROS_INFO("From backward:[%f]",operatorZ);
                        // }
                    }
                    else
                    {
                        pioneer.resetDrive();
                    }
                    // Check if obstacle is detected
                //    if (usData <= 128)
                //   {
                //      currentState = Obstacle;
                //   }
                break;

                case Obstacle:
                    // stop motors
            //      if(usData > 128)
            //     {
            //        case = Follow;
            //   }
                    break;
                

            };
        }    //        ROS_INFO("From main I post:[%i]",currentState);
        ros::spinOnce();
        //loop_rate.sleep();
    };
 
    return 0;
}


bool isUSObjectDetected(usStruct usFunctionData)
{
    if (usData.left || usData.leftCorner || usData.leftFront || usData.rightFront || usData.rightCorner || usData.right ||usData.rear == true)
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
