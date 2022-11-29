#include <ros/ros.h>
#include <std_msgs/String.h>

class Vision {
    private:
    ros::Subscriber vision_subscriber;

    public:
    Vision(ros::NodeHandle *nh) 
    {
        
        vision_subscriber = nh->subscribe("/Vision", 1000, 
            &Vision::callback_data, this);
    }

    void callback_data(const std_msgs::String::ConstPtr& msg)
    {
        ROS_INFO("I heard: [%s]", msg->data.c_str());
    }

};

int main (int argc, char **argv)
{
    ros::init(argc, argv, "vision_topic");
    ros::NodeHandle nh;
    Vision nc = Vision(&nh);
    ros::spin();
}