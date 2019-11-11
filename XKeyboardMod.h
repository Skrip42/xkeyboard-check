#ifndef xKeyboardMod
#define xKeyboardMod

#include <string>
#include <map>
#include <vector>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

typedef std::map<std::string, unsigned char> StringCharMap;
typedef std::vector<std::string> StringVector;

class XKeyboardMod
{
    public:
        XKeyboardMod(XkbDescRec*, Display*);
        StringVector getAvailableMods();
        StringCharMap getModsMask();
        char getModMask(std::string);
    private:
        StringCharMap _mod;
};
#endif //XKeyboardMod
