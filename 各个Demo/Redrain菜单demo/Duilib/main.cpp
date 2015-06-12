#include "duilib.h"


/*
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    ::CoInitialize(NULL);

    CPaintManagerUI::SetInstance(hInstance);

	CFrameWnd *pFrame = new CFrameWnd(_T("Main_dlg.xml"));
    pFrame->Create(NULL, _T("Redrain²Ëµ¥Demo"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
    pFrame->ShowModal();

    delete pFrame;
    ::CoUninitialize();
    return 0;
}
*/


BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
                      )
{
    return TRUE;
}

CFrameWnd* g_maindlg;


extern "C" __declspec(dllexport) HWND __stdcall init_maindlg(HWND parent, int x, int y, int width, int height)
{
    CDuiRect rect(x, y, x + width, y + height);    
    HMODULE dll_handle = GetModuleHandle(L"Duilib-vc8-demo.dll");
    CPaintManagerUI::SetInstance((HINSTANCE)dll_handle);

    g_maindlg = new CFrameWnd(_T("Main_dlg.xml"));
    HWND maindlg_hwnd = g_maindlg->Create(parent, _T("Redrain²Ëµ¥Demo"), UI_WNDSTYLE_CHILD, NULL, 0, 0, 800, 600);
    g_maindlg->ShowWindow(TRUE);
    //::SetWindowPos(maindlg_hwnd, NULL, rect.left, rect.top, rect.GetWidth(), rect.GetHeight(), SWP_NOZORDER | SWP_NOACTIVATE);
   // delete g_maindlg;  
    return maindlg_hwnd;
}


extern "C" __declspec(dllexport) HWND __stdcall show_maindlg()
{
  
    HMODULE dll_handle = GetModuleHandle(L"Duilib-vc8-demo.dll");
    CPaintManagerUI::SetInstance((HINSTANCE)dll_handle);

    g_maindlg = new CFrameWnd(_T("Main_dlg.xml"));
    HWND maindlg_hwnd = g_maindlg->Create(NULL, _T("Redrain²Ëµ¥Demo"), UI_WNDSTYLE_FRAME, UI_WNDSTYLE_EX_FRAME);
    g_maindlg->ShowModal();
    //::SetWindowPos(maindlg_hwnd, NULL, rect.left, rect.top, rect.GetWidth(), rect.GetHeight(), SWP_NOZORDER | SWP_NOACTIVATE);
    delete g_maindlg;  
    return maindlg_hwnd;
}
