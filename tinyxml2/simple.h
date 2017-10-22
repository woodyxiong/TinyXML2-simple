#include "tinyxml2.h"
using namespace tinyxml2;
class ListNode{
//头指针移动的链表
public:
    XMLElement *element;
    ListNode *next;
    int deepth;
    ~ListNode(){
        //逐个销毁
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};
class Simplexml{
public:
    Simplexml(const char* xmlpath);
    ~Simplexml();

    //头指针向下寻找
    Simplexml* next(char* name,int num=0);
    void previous();
    //将行为指针回到头指针
    void back();

    //运算子节点
    Simplexml* child(const char* name,int num=0);

    //子节点操作
    //name
	const char* text();
    void text(const char* text);
    //name
    const char *name();
    void name(const char* name);
    //attribute 增删改查
    const char* attr(const char *key);
    void attr(const char* key,const char* value);

    //增加节点
    void addNode(const char* name,bool isFirst=true);
    //删除节点
    void deleteNode(const char* name,int num=0);

    //获得当前节点的深度
    int getDeepth();

    //保存xml
    void save();
    void save(char* path);


private:
    const char* xmlpath;        //xml路径
    XMLDocument *simpleDoc;     //文档树

    ListNode *listNode;         //走过的路径

    XMLElement *simpleEle;      //当前的xmlelement
    XMLElement *_simpleEle;     //当前操作的xmlelement
};
