## PrintScreenApp

*This app is inspired by lightshot. It is a little test-app I made in QT just to see what's really going on*

**alt + x** - takes a printscreen and displays it all over the screen, just like your image froze, activating selection using mouse
**Mouse selection** - select the part of the "frozen" screen that you want to have/show                                                  
**Mouse selection done** - when you let go of the mousebutton while selecting, the image is uploaded to imgur, the url to the img is then automatically copied to clipboard, and could be used by pasting it anywhere (for example using ctrl + v).

#To fix
* Giving better visual feedback when a screenshot is taken
* Make it work on secondary screens
* Make compatible on other systems than windows
* Implement autostart

Openssl needed.

Client-id from api.imgur needed.

Curl's not needed even if it is imported in the .pro file, QtNetwork has been used.
