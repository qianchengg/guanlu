// JZXT001.cpp : ���� DLL �ĳ�ʼ�����̡�
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
void MenuNewMdl();//�˵��Ķ�������
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

 static uiCmdAccessState UsrAccessDefault(uiCmdAccessMode access_mode)//���ʿ��ƺ���
{

	return (ACCESS_AVAILABLE);

}
//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CJZXT001App

BEGIN_MESSAGE_MAP(CJZXT001App, CWinApp)
END_MESSAGE_MAP()


// CJZXT001App ����

CJZXT001App::CJZXT001App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CJZXT001App ����

CJZXT001App theApp;


// CJZXT001App ��ʼ��

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
	//��Ӷ�������
	status=ProCmdActionAdd("����ȫ�¶�������",(uiCmdCmdActFn)MenuNewMdl,
		uiCmdPrioDefault,UsrAccessDefault,PRO_B_TRUE,PRO_B_TRUE,&uiCmdNewMdl);	
	//��Ӳ˵���ť���½�ģ�͡�
	status=ProMenubarmenuPushbuttonAdd("File","NewMdl","New Mdl",
		"Usr Button For New Mdl","File.psh_working_dir",PRO_B_TRUE,uiCmdNewMdl,Msg);

	 
	return 0;
}
extern "C" void user_terminate( )
{
	 
}

void MenuNewMdl()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());//����ģʽ�л�
	CNewMdlDlg dlg;
	dlg.DoModal();
}
 