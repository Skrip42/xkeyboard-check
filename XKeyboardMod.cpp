#include <iostream>
#include "XKeyboardMod.h"

XKeyboardMod::XKeyboardMod(XkbDescRec* kbdDescPtr, Display* display)
{
    _mod["Shift"] = ShiftMask;
    _mod["Lock"] = LockMask;
    _mod["Control"] = ControlMask;

    XkbGetNames(display, XkbVirtualModNamesMask, kbdDescPtr);

    const Atom* virtualModNamesMask = kbdDescPtr->names->vmods;
    Atom curVirtualModAtom;

    std::string modName;
    char modMask;
    for (int i = 0; i < XkbNumVirtualMods; i++) {
        if ((curVirtualModAtom = virtualModNamesMask[i]) != None) {
            modName = XGetAtomName(display, curVirtualModAtom);
            modMask = kbdDescPtr->server->vmods[i];
            if (modMask) {
                _mod[modName] = modMask;
            }
        }
    }
}

StringVector XKeyboardMod::getAvailableMods()
{
    StringVector availableMods;

    for (auto &it: _mod) {
        availableMods.push_back(it.first);
    }

    return availableMods;
}

char XKeyboardMod::getModMask(std::string modName)
{
    return _mod[modName];
}

StringCharMap XKeyboardMod::getModsMask()
{
    return _mod;
}
