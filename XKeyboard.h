#ifndef xKeyboard
#define xKeyboard

#include <map>
#include <string>
#include <vector>
#include <X11/Xlib.h>
#include <iostream>
#include "XKeyboardGroups.h"
#include "XKeyboardMod.h"

typedef std::vector<std::string> StringVector;

class XKeyboard
{
    public:
        XKeyboard();
        ~XKeyboard();
        StringVector getActiveMods();
        StringVector getAvailableMods();
        std::string getCurrentLocale();
        std::string getCurrentLocaleShortSign();
        std::string getCurrentLocaleFullSign();
        bool checkMod(std::string);
        bool isAvailableMod(std::string);
    private:
        XKeyboardGroups* _groups;
        XKeyboardMod* _mods;
        Display* _display;
        XkbStateRec getState();
        unsigned char getModMask();
        unsigned char getCurrentGroup();
};


#endif //xKeyboard
