#include <iostream>
#include <sstream>
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
        //无法找到文件
        string str="can't find \n";
        throw str+xmlpath;
    }else if(status==7||status==16){
        //有语法错误
        string str=" has syntax error\n";
        throw xmlpath+str;
    }else if(status==17){
        //根元素name为空
        string str="The name of rootelement is empty\n";
        throw str;
    }
    simpleEle=simpleDoc->RootElement();
    listNode=new ListNode;
    listNode->deepth=0;
    listNode->element=simpleEle;
    listNode->next=NULL;
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
    bool isFound=false;
    while(next){
        string elename=next->Name();
        if(elename.compare(name)==0){
            if(i==num){
                isFound=true;
                this->simpleEle=next;
                this->_simpleEle=next;
                //链表重新赋值
                ListNode *rootList=new ListNode;
                rootList->element=simpleEle;
                rootList->deepth=listNode->deepth+1;
                rootList->next=listNode;
                this->listNode=rootList;
                break;
            }
            i++;
        }
        next=next->NextSiblingElement();
    }
    if(!isFound){
        //没有找到节点
        stringstream ss1;
        ss1<<num;
        string str2=ss1.str();
        string str="The ";
        throw str+name+"("+str2+") is NULL\n";
    }
    return this;
}


/**
 * 将头指针返回到上一个节点
 */
void Simplexml::previous(){
    ListNode *temp=listNode;
    if(listNode->next==NULL){
        string str="The previous node is NULL\n";
        throw str;
    }
    this->listNode=listNode->next;
    this->simpleEle=this->listNode->element;
    this->_simpleEle=this->listNode->element;
    delete temp;
    temp=NULL;
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
Simplexml* Simplexml::child(const char* name,int num){
    XMLElement *next=_simpleEle->FirstChildElement(name);
    _simpleEle=NULL;
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
    if(_simpleEle==NULL){
        //节点为空
        stringstream ss1;
        ss1<<num;
        string str2=ss1.str();
        string str="The ";
        throw str+name+"("+str2+") is NULL\n";
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
 * 获得当前节点的深度
 * @return
 */
int Simplexml::getDeepth(){
    return this->listNode->deepth;
}


/**
 * 保存xml，不带参，直接保存原地址
 */
void Simplexml::save(){
    int status = simpleDoc->SaveFile(xmlpath);
    if(status!=0){
        string str1="save ";
        string str2=" failed\n";
        throw str1+xmlpath+str2;
    }
}

/**
 *
 * 保存xml，带参，另存为
 * @param path
 */
void Simplexml::save(char* path){
    int status=simpleDoc->SaveFile(path);
    if(status!=0){
        string str1="save ";
        string str2=" failed\n";
        throw str1+path+str2;
    }
}

/**
 * 析构函数
 */
Simplexml::~Simplexml(){
    delete simpleDoc;
    delete listNode;
    simpleDoc=NULL;
    listNode=NULL;
}
