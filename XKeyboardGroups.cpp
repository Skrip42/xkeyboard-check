#include "XKeyboardGroups.h"

XKeyboardGroups::XKeyboardGroups(XkbDescRec* kbdDescPtr, Display* display)
{
    XkbGetNames(display, XkbGroupNamesMask, kbdDescPtr);
    XkbGetNames(display, XkbSymbolsNameMask, kbdDescPtr);

    const Atom* groupAtoms = kbdDescPtr->names->groups;
    Atom curGroupAtom;

    for (int i = 0; i < XkbNumKbdGroups; i++) {
        if ((curGroupAtom = groupAtoms[i]) != None) {
            char* groupName = XGetAtomName(display, curGroupAtom);
            _names.push_back(groupName);
        }
    }

    Atom symNameAtom = kbdDescPtr->names->symbols;

    parseSymbol(XGetAtomName(display, symNameAtom));
}

void XKeyboardGroups::parseSymbol(char* symbols)
{
    char c;
    for (long unsigned int i = 0; i <= _names.size(); i++) {
        std::string part = "";
        while ((c = *symbols++) && c != '+') {
            part += c;
        }
        if (i) _fullSigns.push_back(part);
    }
    for (auto &part: _fullSigns) {
        std::string shortPart;
        for (auto c = part.begin(); c != part.end() && *c != '(' && *c != ':'; ++c) {
            shortPart += *c;
        }
        _shortSigns.push_back(shortPart);
    }
}

std::string XKeyboardGroups::getFullSign(int group_number)
{
    return _fullSigns.at(group_number);
}

std::string XKeyboardGroups::getShortSign(int group_number)
{
    return _shortSigns.at(group_number);
}

std::string XKeyboardGroups::getName(int group_number)
{
    return _names.at(group_number);
}
