#include <iostream>
#include <string>
#include <json.h>

using namespace std;

int main()
{
    Json::Value root;
    root["name"] = "bob";
    root["age"] = 18;
    root["index"] = "23";
    string city = "city";
    root[city] = "Xi'an";

    string name = root["name"].asString();
    cout << "name: " << name << endl;
    int age = root["age"].asInt();
    cout << "age: " << age << endl;
    string age1 = root["age"].asString(); //right
    cout << "age1: " << age1 << endl;
    string index = root["index"].asString();
    cout << "index: " << index << endl;
    //int index1 = root["index"].asInt(); //error
    //cout << "index1: " << index1 << endl;
    cout << endl;


    std::string stringa = root.toStyledString(); //将JSON值格式化为带缩进和换行符的字符串
    std::cout << "StringA: " << stringa << std::endl;

    Json::StyledWriter writer;
    std::string stringb = writer.write(root); //将JSON值以美化的方式格式化为带缩进和换行符的字符串
    std::cout << "StringB: " << stringb << std::endl;

    Json::FastWriter fastwriter;
    std::string stringc = fastwriter.write(root); //将JSON值以紧凑的方式格式化为带缩进和换行符的字符串
    std::cout << "StringC: " << stringc << std::endl;


    Json::Value data;
    Json::Reader reader;
    reader.parse(stringa, data, true); //将JSON字符串解析成C++中的JSON数据结构，并保留注释信息
    //reader.parse(stringc, data);
    name = data["name"].asString();
    cout << "name: " << name << endl;
    age = data["age"].asInt();
    cout << "age: " << age << endl;


    return 0;
}
