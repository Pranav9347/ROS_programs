#include<sstream>
#include<iostream>
#include<cstdio>
#include<std_msgs/String.h>
#include<bits/stdc++.h>
#include<string>
#include<ros/ros.h>

using namespace std;
//Function prototypes:
void custom(const string& message);
void cb(const std_msgs::String::ConstPtr& msg);

//Global declaration of node_name to avoid passing to functions
string node_name;
//global publisher object to use in custom()
ros::Publisher publ ;

void main(int argc, char** argv)
{
   /* class x
   {
        public:
        void cb(const std_msgs::String::ConstPtr& ptr)
        {
            cout<<(ptr->data.c_str())<<endl;
        }
        void unsub(void){
    sub.shutdown();//tried unsubbing and resubbing
        }
   };*/
    //taking node_name from user
  cout << "Enter your node name: ";
  getline(cin, node_name);

  ros::init(argc, argv, node_name);
  ros::NodeHandle n;

    //Publishing and subscribing to the same topic
  ros::Subscriber subs = n.subscribe("tpc", 1000, cb);
  publ = n.advertise<std_msgs::String>("tpc", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    string msg;
    cout << "your message: ";
    getline(cin, msg);
    //sending message to get published
    custom(msg);

    ros::spinOnce();//for callbacks
    loop_rate.sleep();
  }

}
void custom(const string& message)
{
  std_msgs::String msg;
  //string concatenation
  msg.data = "[" + node_name + "] " + message;
  publ.publish(msg);
}
void cb(const std_msgs::String::ConstPtr& msg)
{
  cout<<("%s %s", node_name.c_str(), msg->data.c_str())<<endl;
}
