// JZXT001.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "JZXT001.h"
#include "ProMenu.h" 
#include "ProUtil.h"
#include "ProMenubar.h"
#include "ProWindows.h"
#include "ProMdl.h"
#include "ProDimension.h"
#include "ProFamtable.h"
#include "proFaminstance.h"
#include <ProToolkit.h>
#include <ProWindows.h>
#include <ProMdl.h>
#include <ProObjects.h>
#include <ProMessage.h>
#include <ProMenu.h>
#include "NewMdlDlg.h"
void MenuNewMdl();//菜单的动作函数
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

 static uiCmdAccessState UsrAccessDefault(uiCmdAccessMode access_mode)//访问控制函数
{

	return (ACCESS_AVAILABLE);

}
//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CJZXT001App

BEGIN_MESSAGE_MAP(CJZXT001App, CWinApp)
END_MESSAGE_MAP()


// CJZXT001App 构造

CJZXT001App::CJZXT001App()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CJZXT001App 对象

CJZXT001App theApp;


// CJZXT001App 初始化

BOOL CJZXT001App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
extern "C" int user_initialize()
{
	ProError         status;
	ProFileName      Msg;
	uiCmdCmdId       uiCmdNewMdl;
	ProStringToWstring(Msg,"message.txt");
	//添加动作函数
	status=ProCmdActionAdd("建立全新对象命令",(uiCmdCmdActFn)MenuNewMdl,
		uiCmdPrioDefault,UsrAccessDefault,PRO_B_TRUE,PRO_B_TRUE,&uiCmdNewMdl);	
	//添加菜单按钮【新建模型】
	status=ProMenubarmenuPushbuttonAdd("File","NewMdl","New Mdl",
		"Usr Button For New Mdl","File.psh_working_dir",PRO_B_TRUE,uiCmdNewMdl,Msg);

	 
	return 0;
}
extern "C" void user_terminate( )
{
	 
}

void MenuNewMdl()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());//用于模式切换
	CNewMdlDlg dlg;
	dlg.DoModal();
}
 