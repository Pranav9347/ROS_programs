#include<ros/ros.h>//angular brackets for header files which comes in_built in the compiler
#include<std_msgs/String.h>
#include "auv_pkg/custom.h"//"" for header files in the current directory
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void cb(const auv_pkg::custom::ConstPtr& ptr)
{
    cout<<(ptr->name.c_str())<<endl;
}

int main(int argc, char **argv)
{
    string name;
    cout<<"Enter node name: ";
    cin>>name;
ros::init(argc,argv,name);
ros::NodeHandle nh;
ros::Publisher pub = nh.advertise<auv_pkg::custom>("tpc",1000);
//ros::Subscriber sub = nh.subscribe("data",1000,cb);
ros::Rate loop_rate(10);
cout<<"Node has been initialized"<<endl;

while(ros::ok())
{
    int i=0;
    if(i==0)
    ros::Subscriber sub = nh.subscribe("data",1000,cb);
    auv_pkg::custom msg;
string message;
cout<<"Ready to take input\n";
getline(cin,message);
cout<<"\" "<<message<<" \""<<" will be sent\n";
msg.name = message;
pub.publish(msg);
ros::spin();
//sub.shutdown();
//sub = nh.subscribe("tpc",1000,cb);
ros::spinOnce();
loop_rate.sleep();
    i++;
}

return 0;
}