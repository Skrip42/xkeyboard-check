#include "XKeyboard.h"
#include <cstring>
#include <cctype>
#include <cstdlib>

XKeyboard::XKeyboard()
{
    char* displayName = strdup("");
    int major = XkbMajorVersion;
    int minor = XkbMinorVersion;
    int eventCode;
    int errorReturn;
    int reasonReturn;

    _display = XkbOpenDisplay(
            displayName, &eventCode, &errorReturn, &major, &minor, &reasonReturn
    );

    XkbDescRec* kbdDescPtr = XkbAllocKeyboard();

    XkbGetControls(_display, XkbAllControlsMask, kbdDescPtr);
    XkbGetUpdatedMap(_display, XkbAllMapComponentsMask, kbdDescPtr);
    XkbGetNames(_display, XkbVirtualModNamesMask, kbdDescPtr);

    _groups = new XKeyboardGroups(kbdDescPtr, _display);
    _mods = new XKeyboardMod(kbdDescPtr, _display);
}

XkbStateRec XKeyboard::getState()
{
    XkbStateRec xkbState;
    XkbGetState(_display, XkbUseCoreKbd, &xkbState);
    return xkbState;
}

unsigned char XKeyboard::getModMask()
{
    return getState().compat_state;
}

StringVector XKeyboard::getActiveMods()
{
    StringVector activeMods;
    unsigned char modMask;
    modMask = getModMask();
    for(auto &it: _mods->getModsMask()) {
        if (it.second & modMask) activeMods.push_back(it.first); 
    };
    return activeMods;
}

bool XKeyboard::isAvailableMod(std::string modName)
{
    for (auto &it: _mods->getAvailableMods()) {
        if (modName == it) return true;
    }
    return false;
}

bool XKeyboard::checkMod(std::string modName)
{
    return _mods->getModMask(modName) & getModMask();
}

StringVector XKeyboard::getAvailableMods()
{
    return _mods->getAvailableMods();
}

unsigned char XKeyboard::getCurrentGroup()
{
    return getState().group;
}

std::string XKeyboard::getCurrentLocale()
{
    return _groups->getName(getCurrentGroup());
}

std::string XKeyboard::getCurrentLocaleFullSign()
{
    return _groups->getFullSign(getCurrentGroup());
}

std::string XKeyboard::getCurrentLocaleShortSign()
{
    return _groups->getShortSign(getCurrentGroup());
}

XKeyboard::~XKeyboard()
{
    XCloseDisplay(_display);
    _display = NULL;
}
