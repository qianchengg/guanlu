#pragma once
#include "afxwin.h"
#include "Resource.h"

// CNewMdlDlg �Ի���

class CNewMdlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNewMdlDlg)

public:
	CNewMdlDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewMdlDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	double m_edit1;
	double m_edit2;
	double m_edit3;
	double m_edit4;
	double m_edit5;
	double m_edit6;
	double m_edit7;
	double m_edit8;
	double m_edit9;
	//double m_edit10;
	afx_msg void OnBnClickedOk();
	ProError /*CNewMdlDlg::*/UserFamtable(ProMdl model,ProCharName inname,ProType mdtype);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	//afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString m_name;
};
