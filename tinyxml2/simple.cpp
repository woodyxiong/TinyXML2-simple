#include <iostream>
#include "simple.h"
using namespace tinyxml2;
using namespace std;

/**
 * simplexml 构造函数
 * new 出simpledoc
 * @param xmlpath xml路径
 */
Simplexml::Simplexml(const char* xmlpath){
    //赋值给路径
    this->xmlpath=xmlpath;

    //初始化simpleDoc,simpleEle
    simpleDoc=new XMLDocument();
    simpleDoc->LoadFile(xmlpath);
    simpleEle=simpleDoc->RootElement();

    //赋值给simpleElename
    int size=sizeof(simpleEle->Name());
    simpleElename = new char[++size];
    strcpy(simpleElename,simpleEle->Name());
}

/**
 * 获得元素的text
 * @return
 */
const char* Simplexml::text() const {
    if(simpleEle->GetText()==NULL){
        cout<<simpleElename<<" text is null";
    }
    return simpleEle->GetText();
}

/**
 * 获取元素的name
 * @return
 */
const char* Simplexml::name() const{
    if(simpleEle->Name()==NULL){
        cout<<simpleElename<<" name is null";
    }
    return simpleEle->Name();
}

/**
 * 下一个子节点
 * @param name
 * @return Simplexml
 */
Simplexml Simplexml::child(char* name){
    XMLElement *next=simpleEle->FirstChildElement("user");
    while(next){
        string elename=next->Name();
        if(elename.compare(name)==0){
            simpleEle=next;
            break;
        }
        next=next->NextSiblingElement();
    }
    return *this;
}


/**
 * 析构函数
 */
Simplexml::~Simplexml(){
    delete simpleDoc;
    simpleDoc=NULL;
}
