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
    int status = simpleDoc->LoadFile(xmlpath);
    if(status==3){
        string str="can't find ";
        throw str+xmlpath;
    }
    simpleEle=simpleDoc->RootElement();
    _simpleEle=simpleEle;
}

/**
 * 返回下一个节点
 * @param name 节点名称
 * @param num 第num个几点，从0开始计算(默认参数)
 * @return
 */
Simplexml* Simplexml::next(char* name,int num){
    XMLElement *next=simpleEle->FirstChildElement(name);
    int i=0;
    while(next){
        string elename=next->Name();
        if(elename.compare(name)==0){
            if(i==num){
                this->simpleEle=next;
                this->_simpleEle=next;
                break;
            }
            i++;
        }
        next=next->NextSiblingElement();
    }
    return this;
}

/**
 * 回到实际节点
 * _simpleEle回到simpleEle
 */
void Simplexml::back() {
    _simpleEle=simpleEle;
}

/**
 * 返回下一个节点
 * @param name 节点名称
 * @param num 第num个几点，从0开始计算(默认参数)
 * @return
 */
Simplexml* Simplexml::child(char* name,int num){
    XMLElement *next=_simpleEle->FirstChildElement(name);
    int i=0;
    while(next){
        string elename=next->Name();
        if(elename.compare(name)==0){
            if(i==num){
                _simpleEle=next;
                break;
            }
            i++;
        }
        next=next->NextSiblingElement();
    }
    return this;
}

/**
 * 获得元素的text
 * @return
 */
const char* Simplexml::text(){
    const char* text=_simpleEle->GetText();
    this->back();
    return text;
}

/**
 * 获取元素的name
 * @return
 */
const char* Simplexml::name(){
    const char* name=_simpleEle->Name();
    this->back();
    return name;
}

/**
 * 设置text
 * @param text
 */
void Simplexml::text(const char* text){
    _simpleEle->SetText(text);
    back();
}

/**
 * 设置name
 * @param name
 */
void Simplexml::name(const char* name){
    _simpleEle->SetName(name);
    back();
}

/**
 * 读取属性值
 * @param name
 * @return
 */
const char* Simplexml::attr(const char *key){
    const char* name=_simpleEle->Attribute(key);
    this->back();
    return name;
}

/**
 * 设置属性值,后者为NULL即为删除属性
 * @param key
 * @param value
 */
void Simplexml::attr(const char* key,const char* value){
    if(value==NULL){
        _simpleEle->DeleteAttribute(key);
    }else{
        _simpleEle->SetAttribute(key,value);
        this->back();
    }
}







/**
 * 保存xml，不带参，直接保存原地址
 */
void Simplexml::save(){
    simpleDoc->SaveFile(xmlpath);
}

/**
 *
 * 保存xml，带参，另存为
 * @param path
 */
void Simplexml::save(char* path){
    simpleDoc->SaveFile(path);
}

/**
 * 析构函数
 */
Simplexml::~Simplexml(){
    delete simpleDoc;
    simpleDoc=NULL;
}
