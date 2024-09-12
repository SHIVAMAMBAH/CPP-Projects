## Notepad Clone

Notepad is one of the simplest Text editor of Windows which is written in windows API. In, so I have tried to make a clone of the Notepad in WIN32 API.

## API Reference

#### WIN32 API

WIN32 API is a windows API which allows us to directly communicate with the Windows OS at LOW LEVEL.

It is mainly used to write System level Programming, Legacy Software Maintenance, Security and Penetration testing, Embedded System and IoT, Game Development.
##  
- In this folder we are going to make a NOTEPAD Clone from the very beginning.
- We will be using the VS code for the development.
- The WIN32 API is used for making the Clone and C++ language has been used.
- You can study about the [WIN32 API](https://learn.microsoft.com/en-us/windows/win32/api/) from the official documentation.

##  
- There is no need to install the any library from the outside, you just need a text editor and c++ compiler to start.
- You can start by including the "windows.h" header file in the code.
## Usage/Examples
```C++
#include<windows.h>
```
- WIN32 API is used for making Graphical Windows based application. Since it is a Windows application.
- The entry point is the **WinMain** function.
- **int** is the return type of the **WinMain** function.
- **WINAPI** is a MACRO that defines the calling convention for the function.
- **Calling Function** specifies how the function should be called at the assembly level including how parameters are passed and how the stack is cleaned up. WINAPI is defined as _stdcall which is the standard calling convention used by the WINDOW API.
- Different parameters in the fuction:
  - **HINSTANCE hInst** : This is a handle to the current instance of the application. It is used by the OS to identify the application. We typically pass this handle when creating windows and other resources.
  - **HINSTANCE hPrevinst** : This parameter was used in 16-bit windows to differentiate between instances of the same application. In modern 32-bit and 64-bit windows, this parameter is always NULL, as each application runs in its own address space, so its no longer needed.
  - **LPSTR args**: This is a pointer to a null terminated string that contains the command-line arguments passed to the application excluding the program name.
  - **int nCmdShow**: This parameter specifies how the window should be shown initially. It can take values like:
                     - **SW_SHOWNORMAL**: Shows the normal window
                     - **SW_SHOWMINIMIZED**: Shows the window minimized
                     - **SW_SHOWMAXIMIZED** : Shows the window maximized
## Usage/Examples
```C++
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevinst, LPSTR args, int nCmdShow)
```
