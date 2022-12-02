//****************************************************************************
// TITLE        visionClass
// DESCRIPTION	Class definition for a vision sensor
// FILE			visionClass.h
// AUTHOR		R. Schonewille
// DATE			25-nov-2022
// ***************************************************************************

#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
using namespace std;

// Vision Class

class Vision
{
private:
    //ros variable
    ros::Subscriber vision_sub;

	// private variables
	char cameraID = 'None';
	int cameraXResolution = 720;
    int cameraYResolution = 1080;
    float objectID = 2;
    float xpersonCoordinate = 0;
    float ypersonCoordinate = 0;
    float zpersonCoordinate = 0;

public:   
	// constructors
    // Ros vision subscriber 
    Vision(ros::NodeHandle *nh)
    {  
        vision_sub = nh->subscribe("/VisionData", 1000, &Vision::callback_data, this);
    }

    // Member functions for visionClass

    //Setters
    void setCameraID(char cameraID)
    {
       this-> cameraID = cameraID; 
    }

    void setCameraResolution(int cameraXResolution, int cameraYResolution)
    {
        this-> cameraXResolution = cameraXResolution,
        this-> cameraYResolution = cameraYResolution;
    }

    void setObjectID(float objectID)
    {
        this-> objectID = objectID;
    }

    void setXYZCoordinates(float xpersonCoordinate, float ypersonCoordinate, float zpersonCoordinate)
    {
       this-> xpersonCoordinate = xpersonCoordinate,
       this-> ypersonCoordinate = ypersonCoordinate,
       this-> zpersonCoordinate = zpersonCoordinate;       
    }

     //Getters
    void getCameraResolution(int& cameraXResolution, int& cameraYResolution)
    {
        cameraXResolution = this-> cameraXResolution;
        cameraYResolution = this-> cameraYResolution;
    }

    void getObjectID(float& objectID)
    {
        objectID = this-> objectID;
    }

    void getXYZCoordinates(float& xpersonCoordinate, float& ypersonCoordinate, float& zpersonCoordinate)
    {
        xpersonCoordinate = this-> xpersonCoordinate;
        ypersonCoordinate = this-> ypersonCoordinate;
        zpersonCoordinate = this-> zpersonCoordinate;
    }
    //Callback for ROS
    void callback_data(const std_msgs::Float32MultiArray::ConstPtr& msg)
    {
        this -> objectID = msg->data[0];
   //    ROS_INFO("I heard: [%f]", msg->data[0]);
    }

};

