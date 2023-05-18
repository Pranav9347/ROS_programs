#include<ros/ros.h>//angular brackets for header files which comes in_built in the compiler
#include<std_msgs/String.h>
#include "auv_pkg/custom.h"//"" for header files in the current directory
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(int argc, char **argv)
{
ros::init(argc,argv,"Publisher2");
ros::NodeHandle nh;
ros::Publisher pub = nh.advertise<auv_pkg::custom>("new_data",1000);
ros::Rate loop_rate(10);
cout<<"Node has been initialized"<<endl;
while(ros::ok())
{
auv_pkg::custom msg;
string message;
cout<<"Ready to take input\n";
getline(cin,message);
cout<<"\" "<<message<<" \""<<" will be sent\n";
msg.name = message;;
pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
}
return 0;
}
