#ifndef xKeyboardGroups
#define xKeyboardGroups

//#include <iostream>
#include <string>
#include <vector>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

typedef std::vector<std::string> StringVector;

class XKeyboardGroups
{
    public:
        XKeyboardGroups(XkbDescRec*, Display*);
        std::string getFullSign(int);
        std::string getShortSign(int);
        std::string getName(int);
    private:
        StringVector _names;
        StringVector _fullSigns;
        StringVector _shortSigns;
        void parseSymbol(char*);
};

#endif //XKeyboardGroups

