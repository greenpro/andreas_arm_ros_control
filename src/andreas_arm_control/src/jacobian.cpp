#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <pluginlib/class_loader.h>
#include <std_msgs/Float64.h>

#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/planning_interface/planning_interface.h>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/kinematic_constraints/utils.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/PlanningScene.h>

#include <boost/scoped_ptr.hpp>

#include <iostream>

#define PLANNING_GROUP "arm"

using namespace std;

ros::Publisher   alphaPub;
ros::Publisher    betaPub;
ros::Publisher   gammaPub;
ros::Publisher   deltaPub;
ros::Publisher epsilonPub;
ros::Publisher    zetaPub;

void callback(const geometry_msgs::Pose::ConstPtr& msg)
{
    cout << "hit" << endl;
    ROS_INFO("Hit");
    moveit::planning_interface::MoveGroupInterface moveGroup(PLANNING_GROUP);

    double x = msg->position.x;
    double y = msg->position.y;
    double z = msg->position.z;

    double roll  = msg->orientation.x;
    double pitch = msg->orientation.y;
    double yaw   = msg->orientation.z;

    moveGroup.setPositionTarget(   x,     y,   z, "epsilon_link");
    moveGroup.setRPYTarget(     roll, pitch, yaw, "epsilon_link");

    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool success = moveGroup.plan(plan);
    ROS_INFO_NAMED("Jacobian", "Planning %s", success ? "done" : "failed");

    if (!success)
        return;

    vector<double> joints = moveGroup.getCurrentJointValues();
    
    std_msgs::Float64 alphaMsg;
    std_msgs::Float64 betaMsg;
    std_msgs::Float64 gammaMsg;
    std_msgs::Float64 deltaMsg;
    std_msgs::Float64 epsilonMsg;
    std_msgs::Float64 zetaMsg;
    
    alphaMsg.data   = joints[0];
    betaMsg.data    = joints[1];
    gammaMsg.data   = joints[2];
    deltaMsg.data   = joints[3];
    epsilonMsg.data = joints[4];
    zetaMsg.data    = joints[5];

    ROS_INFO_NAMED("Jacobian", "Alpha   %f", joints[0]);
    ROS_INFO_NAMED("Jacobian", "Beta    %f", joints[0]);
    ROS_INFO_NAMED("Jacobian", "Gamma   %f", joints[0]);
    ROS_INFO_NAMED("Jacobian", "Delta   %f", joints[0]);
    ROS_INFO_NAMED("Jacobian", "Epsilon %f", joints[0]);
    ROS_INFO_NAMED("Jacobian", "Zeta    %f", joints[0]);

    alphaPub.publish(    alphaMsg);
    betaPub.publish(      betaMsg);
    gammaPub.publish(    gammaMsg);
    deltaPub.publish(    deltaMsg);
    epsilonPub.publish(epsilonMsg);
    zetaPub.publish(      zetaMsg);
}

int main(int argc, char **argv)
{
    cout << "starting" << endl;
    ros::init(argc, argv, "jacobian");
    
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("moveto", 1000, callback);
    cout << "1" << endl;

    alphaPub   = nh.advertise<std_msgs::Float64>(  "alphaMotor", 1000);
    betaPub    = nh.advertise<std_msgs::Float64>(   "betaMotor", 1000);
    gammaPub   = nh.advertise<std_msgs::Float64>(  "gammaMotor", 1000);
    deltaPub   = nh.advertise<std_msgs::Float64>(  "deltaMotor", 1000);
    epsilonPub = nh.advertise<std_msgs::Float64>("epsilonMotor", 1000);
    zetaPub    = nh.advertise<std_msgs::Float64>(   "zetaMotor", 1000);
    cout << "2" << endl;

    cout << "asdf" << endl;
    ros::spin();

    return 0;
}
