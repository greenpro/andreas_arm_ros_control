#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>

#define PI (3.141592)
#define UPPER_LIMIT (PI)
#define LOWER_LIMIT (-PI)

//ros::Publisher feedback;
ros::Publisher simulator;
ros::Publisher usb;

void callback(const std_msgs::Float64::ConstPtr& msg)
{
    if (msg->data > UPPER_LIMIT || msg->data < LOWER_LIMIT)
    {
        //std_msgs::String msgfb;
        //msgfb.data = "Value is out of range";
        //feedback.publish(msgfb);

        ROS_INFO("The value %f sent to the epsilon motor is out of the valid range of %f to %f.", msg->data, UPPER_LIMIT, LOWER_LIMIT);

        return;
    }

    simulator.publish(msg);
    usb.publish(msg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "epsilonMotor");

    // Incoming messages
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("epsilonMotor", 1000, callback);

    // Outgoing messages
    //feedback  = nh.advertise<std_msgs::Float64>("epsilonFeedback", 1000);
    simulator = nh.advertise<std_msgs::Float64>("andreas_arm/epsilon_position_controller/command",   1000);
    usb       = nh.advertise<std_msgs::Float64>("usb",           1000);

    ros::spin();

    return 0;
}
