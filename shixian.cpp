#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "json/json.h"
#include "json/json-forwards.h"
#include "shixian.hpp"
#include <ctime>
using namespace std;
using namespace Json;

void add_user()
{
    ifstream ifs("/home/flora/Desktop/test.json");
    Value root;
    Value new_user;
    Value user_time;
    ifs >> root;
    ifs.close();
    string user_name;
    cin >> user_name;
    time_t now = time(0); // 把 now 转换为字符串形式
    char *dt = ctime(&now);
    new_user["time"].append(dt);
    root[user_name] = new_user;
    StyledWriter writer;
    string output = writer.write(root);
    ofstream ofs("/home/flora/Desktop/test.json");
    // 写入格式化后带格式的字符串
    ofs << output;
    // 关闭文件
    ofs.close();
}

void add_time()
{ // 读取 json 文件
    ifstream ifs("/home/flora/Desktop/test.json");
    Value root;
    Value user_time;
    ifs >> root;
    ifs.close();
    // Value root;
    time_t now = time(0); // 把 now 转换为字符串形式
    char *dt = ctime(&now);
    root["yjb"]["time"].append(dt);
    StyledWriter writer;
    string output = writer.write(root);
    ofstream ofs("/home/flora/Desktop/test.json");
    // 写入格式化后带格式的字符串
    ofs << output;
    // 关闭文件
    ofs.close();
}
void read_json()
{
    // 读，打开test.json
    ifstream ifs("/home/flora/Desktop/test.json");
    Reader rd;
    Value root;
    // 将json数据解析到root里面
    rd.parse(ifs, root);
    // cout<<root;
    // 判断解析的root value类是否是Array
    if (root.isArray())
    {
        // size方法判断
        for (unsigned i = 0; i < root.size(); ++i)
        {
            Value item = root[i];
            // 对类型进行判断，并对对应的类型进行输出
            if (item.isInt())
            {
                cout << item.asInt() << " ,";
            }
            else if (item.isString())
            {
                cout << item.asString() << " ,";
            }
            else if (item.isBool())
            {
                cout << item.asBool() << " ,";
            }
            else if (item.isArray())
            {
                for (unsigned j = 0; j < item.size(); ++j)
                {
                    cout << item[j].asString() << ", ";
                }
            }
            else if (item.isObject())
            {
                // Return a list of the member names.
                Value::Members keys = item.getMemberNames();
                for (int k = 0; k < keys.size(); ++k)
                {
                    cout << keys.at(k) << "," << item[keys[k]];
                }
            }
            cout << endl;
        }
    }
}
void read_txt()
{
    //read
   
    //cout<<canshu1<<endl<<canshu2<<endl<<canshu3<<endl;
}