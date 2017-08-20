#include "tinyxml2.h"
using namespace tinyxml2;
class Simplexml;
class Simplexml{
public:
    Simplexml(const char* xmlpath);
    ~Simplexml();

    Simplexml child(char* name);
	const char* text() const;
	const char* name() const;
	void setText(char* text);

private:
    const char* xmlpath;
    XMLDocument *simpleDoc;
    XMLElement *simpleEle;
    char *simpleElename;
};
 