#include <iostream>
#include "tinyxml2/simple.h"
using namespace std;
using namespace tinyxml2;
const char* xmlpath="example.xml";
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
        string elename=user->Name();
        if(elename.compare("user")==0){
            cout<<user->Name()<<endl;
            break;
        }
        user=user->NextSiblingElement();
    }
}

void parseSimple(){
	Simplexml* simplexml=new Simplexml(xmlpath);
    cout<<simplexml->child("user",1)->child("email")->text();
//    cout<<simplexml->child("user",2).text();
}