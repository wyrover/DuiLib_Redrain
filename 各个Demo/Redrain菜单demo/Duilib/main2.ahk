
    ;SetTimer, Alert1, 500
    Gui +LastFound
    maindlg_hwnd := show_maindlg()
    If maindlg_hwnd is not integer
        MsgBox %maindlg_hwnd%

    ExitApp
return




_Exit:
    DestoryMainDlg(maindlg_hwnd)
    ExitApp
return

Alert1:
    MsgBox, 222
return


F1::
    MsgBox, 1111


show_maindlg()
{
    static first_call := true
    local hModule, maindlg_hwnd
    if (first_call) {
        first_call := false
        hModule := DllCall("LoadLibrary", "Str", "Duilib-vc8-demo.dll")
        if (!hModule) {
            ExitApp    
        }
    }

    maindlg_hwnd := DLLCall("Duilib-vc8-demo.dll\show_maindlg")

    if (ErrorLevel != 0 or maindlg_hwnd = 0) {
        return 0
    }

    return maindlg_hwnd
}

DestoryMainDlg(hwnd)
{
    if (hwnd != 0) {
        DllCall("DestroyWindow", "UInt", hwnd)
    }
}
