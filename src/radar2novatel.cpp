#include <ros/ros.h>
#include <tf/tf.h>
//退出用：ctrl+z
int main(int argc, char** argv){
//初始化
    ros::init(argc, argv, "radar2novatel");
    ros::NodeHandle node;
     tf::Vector3 rotation_axis(0,0,1);//参数（0,0,1），表示绕Z轴旋转
// std::cout<<"旋转轴rotation_axis："<<"("<<rotation_axis[0]<<","<<rotation_axis[1]<<","<<rotation_axis[2]<<")"<<std::endl;
// 由旋转轴和旋转角来估计四元数
    tf::Quaternion body2novatel(0,0,0,1);//x,y,z,w
    int angle=93.76+180;
    body2novatel.setRotation(rotation_axis,angle*M_PI/180);//表示从body到novatel坐标系
    std::cout<<std::setprecision(21)<<"从body坐标系转换到novatel坐标系，得到的四元数(qw,qx,qy,qz)->"<<"("<<body2novatel[3]<<","<<body2novatel[0]<<","<<body2novatel[1]<<","<<body2novatel[2]<<")"<<std::endl;
//输出的时候，w,x,y,z
    // std::cout<<std::setprecision(21)<<"radar2body输出的四元数:"<<"("<<radar2body[3]<<","<<radar2body[0]<<","<<radar2body[1]<<","<<radar2body[2]<<")"<<std::endl;
//输出的时候，w,x,y,z


  //  std::cout<<"--------------------"<<std::endl;

//定义旋转轴
  //  tf::Vector3 rotation_axis(0,0,1);//参数（0,0,1），表示绕Z轴旋转
// std::cout<<"旋转轴rotation_axis："<<"("<<rotation_axis[0]<<","<<rotation_axis[1]<<","<<rotation_axis[2]<<")"<<std::endl;
// 由旋转轴和旋转角来估计四元数
    tf::Quaternion pandar2novatel(-0.001207789928129342,0.000505180464169112,0.9999696784805524,0.007676467656966332);//x,y,z,w
   // body2novatel.setRotation(rotation_axis,M_PI/2);//表示从body到novatel坐标系
//std::cout<<std::setprecision(21)<<"从body坐标系转换到novatel坐标系，得到的四元数:"<<"("<<body2novatel[3]<<","<<body2novatel[0]<<","<<body2novatel[1]<<","<<body2novatel[2]<<")"<<std::endl;
//输出的时候，w,x,y,z
    tf::Quaternion radar2novatel(0,0,0.706241266854645943774,-0.707971237404136921612);//x,y,z,w，
   // std::cout<<std::setprecision(21)<<"radar2body输出的四元数:"<<"("<<radar2body[3]<<","<<radar2body[0]<<","<<radar2body[1]<<","<<radar2body[2]<<")"<<std::endl;
//输出的时候，w,x,y,z
    tf::Quaternion radar2pandar;//x,y,z,w，输出的毫米波雷达在novatel坐标系下的四元数
    radar2pandar=radar2novatel*pandar2novatel.inverse();//两个四元数相乘得到从radar2novatel的四元数
    std::cout<<std::setprecision(21)<<"radar2novatel输出的四元数:"<<"("<<radar2pandar[3]<<","<<radar2pandar[0]<<","<<radar2pandar[1]<<","<<radar2pandar[2]<<")"<<std::endl;
//输出的时候，w,x,y,z

   //double novatel2pandar_t=0.9149999999999999;
  // double novatel2conti=-0.330;

   //std::cout<<novatel2pandar_t-novatel2conti<<std::endl;



return 0;
};
