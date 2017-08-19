#include <iostream>
#include "simple.h"
using namespace tinyxml2;
using namespace std;

/**
 * simplexml 构造函数
 * @param xmlpath xml路径
 */
Simplexml::Simplexml(char* xmlpath){
    this->xmlpath=xmlpath;
    simpleDoc->LoadFile("");
    cout<<xmlpath;
//    simpleEle=simpleDoc->RootElement();
}

/**
 * 获得元素的text
 * @return
 */
const char* Simplexml::getText() const {
    return simpleEle->GetText();
}
