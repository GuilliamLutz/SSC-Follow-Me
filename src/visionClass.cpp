//****************************************************************************
// TITLE        visionClass
// DESCRIPTION	Class function implementation for a vision sensor
// FILE			visionClass.cpp
// AUTHOR		R. Schonewille
// DATE			25-nov-2022
// ***************************************************************************


#include "visionClass.h"
#include "ros.h"
#include "std_msgs/String.h"

// Constructors for visionClass

    Vision::Vision() //Constructor with preset values 
    {
       this-> cameraID = '0';

       this-> cameraXResolution = 720,
       this-> cameraYResolution = 1080;

       this-> xpersonCoordinate = 0,
       this-> ypersonCoordinate = 0,
       this-> zpersonCoordinate = 0;

       this-> boundingboxHPosition = 0,
       this-> boundingboxVPosition = 0;
    }

    Vision::Vision(char cameraID, int cameraXResolution, int cameraYResolution, float xpersonCoordinate, float ypersonCoordinate,
         float zpersonCoordinate, float boundingboxHPosition, float boundingboxVPosition)
    {
       this-> cameraID = cameraID;

       this-> cameraXResolution = cameraXResolution,
       this-> cameraYResolution = cameraYResolution;

       this-> xpersonCoordinate = xpersonCoordinate,
       this-> ypersonCoordinate = ypersonCoordinate,
       this-> zpersonCoordinate = zpersonCoordinate;

       this-> boundingboxHPosition = boundingboxHPosition,
       this-> boundingboxVPosition = boundingboxVPosition;
    }

    Vision(ros::NodeHandle *nh)
    {
        vision_sub = nh->subscribe("/vision_data", 1000,&Vision::callback_data,this);
    }
   

// Member functions for visionClass
    //Setters

    void Vision::setCameraID(char cameraID)
    {
       this-> cameraID = cameraID; 
    }

    void Vision::setCameraResolution(int cameraXResolution, int cameraYResolution)
    {
        this-> cameraXResolution = cameraXResolution,
        this-> cameraYResolution = cameraYResolution;
    }

    void Vision::setObjectID(int objectID)
    {
        this-> objectID = objectID;
    }

    void Vision::setXYZCoordinates(float xpersonCoordinate, float ypersonCoordinate, float zpersonCoordinate)
    {
       this-> xpersonCoordinate = xpersonCoordinate,
       this-> ypersonCoordinate = ypersonCoordinate,
       this-> zpersonCoordinate = zpersonCoordinate;       
    }

    //Getters

    void Vision::getCameraResolution(int& cameraXResolution, int& cameraYResolution)
    {
        cameraXResolution = this-> cameraXResolution;
        cameraYResolution = this-> cameraYResolution;
    }

    void Vision::getObjectID(int& objectID)
    {
        objectID = this-> objectID;
    }

    void Vision::getXYZCoordinates(float& xpersonCoordinate, float& ypersonCoordinate, float& zpersonCoordinate)
    {
        xpersonCoordinate = this-> xpersonCoordinate;
        ypersonCoordinate = this-> ypersonCoordinate;
        zpersonCoordinate = this-> zpersonCoordinate;
    }

    //ROS functions

    void callback_data(const std_msgs::String& msg)
    {
        cameraID = msg.data;
    }
