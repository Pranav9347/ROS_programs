#include <ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
#include "auv_pkg/custom.h"
using namespace std;

void cb(const auv_pkg::custom::ConstPtr&);
int main(int argc, char** argv)
{
    ros::init(argc,argv,"Subscriber2");

    ros::NodeHandle nr;

    ros::Subscriber sub = nr.subscribe("new_data",1000,cb);

    ros::spin();

    return 0;
}
void cb(const auv_pkg::custom::ConstPtr& ptr)
{
    cout<<(ptr->name.c_str())<<endl;

}
