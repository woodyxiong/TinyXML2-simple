#include "tinyxml2.h"
using namespace tinyxml2;
class Simplexml;
class Simplexml{
public:
    Simplexml(const char* xmlpath);
    ~Simplexml();

    //实际节点向下寻找
    Simplexml* next(char* name,int num=0);
    //回到实际节点
    void back();

    //运算子节点
    Simplexml* child(char* name,int num=0);

    //子节点操作
	const char* text();
	const char* name();

    //保存xml
    void save();
    void save(char* path);


private:
    const char* xmlpath;        //xml路径
    XMLDocument *simpleDoc;     //文档树

    XMLElement *simpleEle;      //当前的xmlelement
    XMLElement *_simpleEle;     //当前操作的xmlelement
};
 