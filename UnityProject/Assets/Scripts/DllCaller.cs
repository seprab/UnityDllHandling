using System;
using System.Runtime.InteropServices;
using UnityEngine;
using System.Text;
public class DllCaller : MonoBehaviour
{
    const string nativeDll = "NativeDll";

    [DllImport(nativeDll)]
    private static extern int IsItWorking();

    [DllImport(nativeDll)]
    private static extern IntPtr HelloWorld();
    
    [DllImport(nativeDll)]
    private static extern void MyPluginWork();

    StringBuilder sb = new StringBuilder();

    void Start()
    {
        ManagedDll.ClassObject managedTest = new ManagedDll.ClassObject();
        sb.Append($"Is the managed DLL working? {managedTest.IsItWorking()==1}");
        sb.Append($"\nIs the native DLL working? {IsItWorking()==1}");


        MyPluginWork();
    }
    void OnGUI()
    {
        GUI.Label(new Rect(10, 10, 250, 250), sb.ToString());
    }
}
