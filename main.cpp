#include <iostream>    //读写io c++标准库
#include <fstream>     //读写文件 c++标准库
#include <string>      //字符串类 c++标准库
#include <sstream>     //字符串流 c++标准库
#include "json/json.h" //jsoncpp的头文件
#include "json/json-forwards.h"
#include "shixian.hpp"
#include <ctime>
using namespace std;
using namespace Json;

void writeJson()
{ // 定义Value对象
    Value root;
    // 使用append方法向Value包装器li填充数据
    root.append("zyt");
    // root.append(time(0));//root.append(170);//root.append(false); // 基于当前系统的当前日期/时间
    time_t now = time(0); // 把 now 转换为字符串形式
    char *dt = ctime(&now);
    // 又定义一个subArray的Value对象
    Value usr_time;
    usr_time.append(dt);
    // subArray.append("sabo");
    // 将subArray对象增加到root里面
    root.append(usr_time);
    // Value obj;//定义键值对//obj["sex"] = "man";//obj["girlfriend"] = "Hancock";//将obj对象的键值对增加到root里面 //root.append(obj);
#if 1
    // 对上面数据格式序列化使用toStyledString方法得到带格式的字符串
    string json = root.toStyledString();
#else
    // 得到不带格式的字符串
    FastWriter w;
    // 通过write方法得到不带换行符的字符串
    string json = w.write(root);
#endif
    // 写文件
    // write  ->  ostream
    // read   ->  ifstream
    // 将json数据写入test.json
    ofstream ofs("/home/flora/Desktop/test.json", ios::app);
    // 写入格式化后带格式的字符串
    ofs << json;
    // 关闭文件
    ofs.close();
}
int main()
{
    ifstream txt_user("/home/flora/Desktop/user.txt");
    string str_user;
    string canshu1, canshu2, canshu3;
    txt_user >> canshu1 >> canshu2 >> canshu3;
    txt_user.close();
    return 0;
}