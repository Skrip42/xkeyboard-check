README
======


Description
-----------
xkeboard-check is small comand line programm for check current keyboard layout and mods key.

Compilation and installation
----------------------------
- `git clone https://github.com/Skrip42/xkeyboard-check.git`
- `cd ./xkeyboard-check`
- `make`
- `make install`

Usage
-----

- `xkeyboard-check locale` print current locale
- `xkeyboard-check available_mods` print list of available mods
- `xkeyboard-check active_mods` print current active mods
- `xkeyboard-check modname`, where modname id mod name gets from `xkeyboard-check available_mods`, check active status of modname

for example, I check the activity status of `CapsLock`:
I can type `xkeyboard-check available_mods` and get a list of available mode keys:
`Alt
 AltGr
 Control
 Hyper
 LevelThree
 Lock
 Meta
 NumLock
 Shift
 Super`
obviously, `Lock` is the` CapsLock` key, I can type `xkeyboard-check active_mods` with` CapsLock` in action to make sure.
Then I can type `xkeyboard-check Lock` to check the status of CapsLock activity.
