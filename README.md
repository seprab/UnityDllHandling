# UnityDllHandling

This repository serves as a sample project for demonstrating the integration of managed and native DLLs within a Unity project. It encompasses solutions for both native and managed DLLs developed in Visual Studio, alongside a Unity project that utilizes these DLLs.

The goal is to expand this repository with additional examples and documentation to aid in understanding DLL integration within Unity environments.

## How to Test

Follow these steps to build the DLLs and test them in the Unity Editor.

### 1. Building the DLLs

The process to build DLLs varies between Windows and macOS. Ensure you follow the instructions corresponding to your operating system.

#### On Windows

1. Open the `*.sln` files located within the project directory using Visual Studio.
2. Compile the DLLs by selecting `Build Solution` from the `Build` menu.

#### On Mac

Execute the following command in the terminal to compile the native DLL:

```bash
g++ -dynamiclib UnityDllHandling/NativeDll/NativeDll/dllmain.cpp -o UnityDllHandling/UnityProject/Assets/Plugins/Native/MacOS/NativeDll.dylib
```

Ensure the target directory exists before running the command. If not, create it using:
```bash
mkdir -p UnityDllHandling/UnityProject/Assets/Plugins/Native/MacOS/
```

### 2. Testing in the Unity Editor

To verify the DLLs are working correctly within Unity, perform the following steps:
1. Navigate to `Assets/Scenes/` and open `RunThisScene.unity`.
2. Enter play mode by clicking the play button.
3. Observe the output on the screen, which should display:
```
Is the managed DLL working? True
Is the Native DLL working? True
```
This confirms that both the managed and the native DLLs are correctly integrated and functioning within your Unity project.