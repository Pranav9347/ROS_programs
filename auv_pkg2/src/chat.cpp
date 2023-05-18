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
    class x
   {
        public:
        void cb(const std_msgs::String::ConstPtr& ptr)
        {
            cout<<(ptr->data.c_str())<<endl;
        }
        void unsub(void){
    sub.shutdown();
        }
   };
    string name;
    cout<<"Enter node name: ";
    cin>>name;
ros::init(argc,argv,name);
ros::NodeHandle nh;
ros::Publisher pub = nh.advertise<auv_pkg::custom>("tpc",1000);
     x var;
ros::Subscriber sub = nr.subscribe("chatter", 1000, &x::cb, &var);
//ros::Subscriber sub = nh.subscribe("data",1000,cb);
ros::Rate loop_rate(10);
cout<<"Node has been initialized"<<endl;

while(ros::ok())
{
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
}

return 0;
}
