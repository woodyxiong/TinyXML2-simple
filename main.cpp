#include <iostream>
#include "tinyxml2/simple.h"
using namespace std;
using namespace tinyxml2;
const char* xmlpath="example.xml";
const char* xmlpathError="errorExample.xml";
void parseTinyXML();
void parseSimple();
int main(){
//    parseTinyXML();
    parseSimple();

	return 0;
}

void parseTinyXML(){
    XMLDocument* doc=new XMLDocument;
    int status=doc->LoadFile(xmlpathError);
    if(status!=0)
        cout<<"open failed"<<endl;
    XMLElement *root=doc->RootElement();
    XMLElement *user=root->FirstChildElement("user");
    while(user){
        string elename=user->GetText();
        if(elename.compare("user0")==0){
            XMLElement *email=user->FirstChildElement("email");
            while(email){
                XMLElement *dizhi=doc->NewElement("dizhi");
                email->InsertEndChild(dizhi);
                email=email->NextSiblingElement();
            }
            break;
        }
        user=user->NextSiblingElement();
    }
    doc->SaveFile(xmlpathError);
}

void parseSimple(){
    try {
        Simplexml* simplexml;
        simplexml=new Simplexml(xmlpathError);
        cout<<"class1\n";
        simplexml->next("class1");//将头指针向子节点移动
        cout<<simplexml->child("student",0)->text()<<endl;
        cout<<simplexml->child("student",1)->text()<<endl;
        cout<<simplexml->child("student",2)->text()<<endl;
        cout<<simplexml->child("student",3)->text()<<endl;
        cout<<simplexml->child("student",4)->text()<<endl;

        cout<<"class2\n";
        simplexml->previous();//将头指针向父节点移动
        simplexml->next("class2");//将头指针向子节点移动
        cout<<simplexml->child("student",0)->text()<<endl;
        cout<<simplexml->child("student",1)->text()<<endl;
        cout<<simplexml->child("student",2)->text()<<endl;
        cout<<simplexml->child("student",3)->text()<<endl;
        cout<<simplexml->child("student",4)->text()<<endl;
        delete simplexml;
    }catch (string e){
        cout<<e<<endl;
    }
}