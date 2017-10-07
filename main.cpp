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
    int status=doc->LoadFile(xmlpath);
    if(status!=0)
        cout<<"open failed"<<endl;
    XMLElement *root=doc->RootElement();
    XMLElement *user=root->FirstChildElement("user");
    while(user){
        string elename=user->GetText();
        if(elename.compare("user0")==0){
            cout<<user->GetText()<<endl;
            root->DeleteChild(user);
            break;
        }
        user=user->NextSiblingElement();
    }
    doc->SaveFile(xmlpath);
}

void parseSimple(){
    try {
        Simplexml* simplexml;
        simplexml=new Simplexml(xmlpathError);
//        simplexml->addNode("asdf");
//        simplexml->child("asdf")->attr("123","123");
        simplexml->child("asdf")->addNode("asdf");
        simplexml->child("asdf")->child("asdf")->attr("123","123");
        simplexml->save();

        delete simplexml;
    }catch (string e){
        cout<<e<<endl;
    }

}