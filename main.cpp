#include <iostream>
#include "tinyxml2/simple.h"
using namespace std;
using namespace tinyxml2;
int main(){
    XMLDocument* doc;
    doc->LoadFile("example.xml");
//    XMLElement *root=doc->RootElement();
//    cout<<root->GetText();
//	Simplexml* simplexml=new Simplexml("/home/woody/桌面/TinyXML2-simple/example.xml");
//    simplexml
    cout<<"finished";
	return 0;
}