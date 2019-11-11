#include "XKeyboard.h"
#include <iostream>
#include <vector>

typedef std::vector<std::string> StringVector;

void printAvailableMods(XKeyboard* xkb)
{
    for (auto &it: xkb->getAvailableMods()) {
        std::cout << it << "\n";
    }
}

void printActiveMods(XKeyboard* xkb)
{
    for (auto &it: xkb->getActiveMods()) {
        std::cout << it << "\n";
    }
}

void printLocale(XKeyboard* xkb)
{
    std::cout << xkb->getCurrentLocaleShortSign() << "\n";
}

void printModActive(XKeyboard* xkb, std::string modName)
{
    std::cout << xkb->checkMod(modName);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    XKeyboard xkb;
    std::string command(argv[1]);
    if (command == "locale") {
        printLocale(&xkb);
    } else if (command == "available_mods") {
        printAvailableMods(&xkb);
    } else if (command == "active_mods") {
        printActiveMods(&xkb);
    } else if (xkb.isAvailableMod(command)) {
        printModActive(&xkb, command);
    }
    return EXIT_SUCCESS;
}
