#pragma once

#ifdef _DEBUG
#   
#       pragma comment(lib, "../../../../../lib/x86/vc8_mtd/DuiLib_static_mtd.lib")
#  
#else
#   
#       pragma comment(lib, "../../../../../lib/x86/vc8_mt/DuiLib_static_mt.lib")
#   
#endif


class CFrameWnd: public WindowImplBase
{
public:
	explicit CFrameWnd(LPCTSTR pszXMLPath);

	LPCTSTR GetWindowClassName() const;
	CDuiString GetSkinFile();
	CDuiString GetSkinFolder();
	//UILIB_RESOURCETYPE GetResourceType() const;
	//LPCTSTR GetResourceID() const;

     void InitWindow();
     void Notify(TNotifyUI& msg);
	 LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	 // CControlUI* CreateControl(LPCTSTR pstrClassName);
private:
	CDuiString		m_strXMLPath;

	map<CDuiString,bool> m_MenuCheckInfo; //保存菜单的单选复选信息
};