//****************************************************************************
// TITLE        Main System ROS wrapper
// DESCRIPTION	implementation of main program to gather sensor info trough their classes and make the data ROS ready
// FILE			main.cpp
// AUTHOR		R. Schonewille
// DATE			25-nov-2022
// ***************************************************************************

#include "ros/ros.h"
#include "visionClass.h"
//#include "straigtfollow/US.h"
#include "MotorControl.h"

int operatorID;
float operatorX;
float operatorY;
float operatorZ;
//int usData;
personCoordinates xyzStruct; 

enum caseStates {Init, Idle, Follow, Obstacle};

int main(int argc,char **argv)
{
    ros::init(argc, argv, "StateMachine");
    ros::NodeHandle n;

    Vision oakD =  Vision(&n);
    Motorcontrol pioneer = Motorcontrol(&n);
    //us us1 = new us();
    ros::Rate loop_rate(10);

    caseStates currentState = Init;
    
    while (ros::ok())
    {
        // Obstacle detected
       // usData = us1.getUsData();
        // Persoon met ID 1 volgen
        xyzStruct = oakD.getXYZCoordinates();
        operatorID = oakD.getPersonID();

        
        //if (operatorID == 1)
        //{
            operatorX = xyzStruct.x;
            operatorY = xyzStruct.y;
            operatorZ = xyzStruct.z;
        //}
        // else
        // {
        //     operatorX = 0;
        //     operatorY = 0;
        //     operatorZ = 0;
        // }

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
            ROS_INFO("From main I post:[%f]",operatorZ);
                if (operatorZ >= 2000.0)
                {
                    pioneer.driveForward();
                    ROS_INFO("From main I post:[%f]",operatorZ);

                }
                else if(operatorZ <= 500.0)
                {
                    pioneer.driveBackward();
                    ROS_INFO("From main I post:[%f]",operatorZ);
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
            //        ROS_INFO("From main I post:[%i]",currentState);
        ros::spinOnce();
        //loop_rate.sleep();
    };
 
    return 0;
}

