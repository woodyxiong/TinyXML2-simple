#include "tinyxml2.h"
using namespace tinyxml2;
class Simplexml;
class Simplexml{
public:
    Simplexml(char* xmlpath);
    Simplexml child(char* name);
	const char* getText() const;
	void setText(char* text);

private:
    const char* xmlpath;
    XMLDocument *simpleDoc;
    XMLElement *simpleEle;
};
 