//****************************************************************************
// TITLE        visionClass
// DESCRIPTION	Class definition for a vision sensor
// FILE			visionClass.h
// AUTHOR		R. Schonewille
// DATE			25-nov-2022
// ***************************************************************************

#pragma once
#include <ros/ros.h>

// Vision Class

class Vision
{
private:
    //ros variable
    ros::Subscriber vision_sub;

	// private variables
	char cameraID;
	int cameraXResolution;
    int cameraYResolution;
    int objectID;
    float xpersonCoordinate;
    float ypersonCoordinate;
    float zpersonCoordinate;
    float boundingboxHPosition;
    float boundingboxVPosition;

public:   
	// constructors
	Vision();
	Vision(char cameraID, int cameraXResolution, int cameraYResolution, float xpersonCoordinate, float ypersonCoordinate,
         float zpersonCoordinate, float boundingboxHPosition, float boundingboxVPosition);                //Construct for OAK-D PRO with specific data from AI camera

	// member funtions
    void setCameraID(char cameraID);                            
    void setCameraResolution(int cameraXResolution, int cameraYResolution);
    void setObjectID(int objectID);
    void setXYZCoordinates(float xpersonCoordinate, float ypersonCoordinate, float zpersonCoordinate);
    void setDataPersonObjectSub(); //test function to see if object data can be set directly trough ros sub
    // void setBoundingboxPosition(float boundingboxHPosition, float boundingboxVPosition);

    void getCameraResolution(int& cameraXResolution, int& cameraYResolution );
    void getObjectID(int& objectID);
    void getXYZCoordinates(float& xpersonCoordinate, float& ypersonCoordinate, float& zpersonCoordinate);        
    // void getBoundingboxPosition(float& boundingboxHPosition, float& boundingboxVPosition);                                      
    
    //ros
    void callback_data();
};

