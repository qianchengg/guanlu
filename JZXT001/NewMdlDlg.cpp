// NewMdlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JZXT001.h"
#include "NewMdlDlg.h"
#include "afxdialogex.h"
#include <ProSolid.h>
#include <ProParameter.h>
#include <ProAsmcomp.h>
#include <ProModelitem.h>
ProMdl*instmdl;
// CNewMdlDlg 对话框

IMPLEMENT_DYNAMIC(CNewMdlDlg, CDialogEx)

CNewMdlDlg::CNewMdlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewMdlDlg::IDD, pParent)
	, m_edit1(850)
	, m_edit2(18)
	, m_edit3(42)
	, m_edit4(3)
	, m_edit5(5)
	, m_edit6(8)
	, m_edit7(20)
	, m_edit8(8)
	, m_edit9(178)
	, m_name(_T(""))
{

}

CNewMdlDlg::~CNewMdlDlg()
{
}

void CNewMdlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	//DDX_Text(pDX, IDC_EDIT3, m_edit3);
	//DDX_Text(pDX, IDC_EDIT4, m_edit4);
	//DDX_Text(pDX, IDC_EDIT5, m_edit5);
	//DDX_Text(pDX, IDC_EDIT6, m_edit6);
	//DDX_Text(pDX, IDC_EDIT7, m_edit7);
	//DDX_Text(pDX, IDC_EDIT8, m_edit8);
	//DDX_Text(pDX, IDC_EDIT9, m_edit9);
	//DDX_Text(pDX, IDC_EDIT10, m_edit10);
	DDX_Text(pDX, IDC_EDIT10, m_name);
}


BEGIN_MESSAGE_MAP(CNewMdlDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNewMdlDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CNewMdlDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewMdlDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CNewMdlDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CNewMdlDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CNewMdlDlg 消息处理程序

//定义浇道数据结构
typedef struct userdata{
	ProFaminstance*fam_inst;//族表子零件变量
	ProFamtable fam_table;//族表变量
	double dataL; 
	double dataL1; 
	//double dataL2; 
	//double dataL3; 
	//double dataL4;
	//double dataH1; 
	//double dataH2; 
	//double dataH3; 
	//double dataR; 
}UserData;

ProError UsrActivateCurrentWindow()
{
	int window_id;
	ProError status;
	status=ProWindowCurrentGet(&window_id);
	status=ProWindowActivate(window_id);
	return status;
}
	
//设置族表中子零件参数值
ProError UserFamtableItemAct(ProFamtableItem*fam_item,ProError filt_status,ProAppData appdata)//三个输入的参数
{
	UserData*data=(UserData*)appdata;
	ProCharName item_name,ditem_name;
	int  status;
	ProParamvalue item_val;
	ProParamvalueType item_type;
	double dbl_value;
	
	
//获得当前的族表项目名称
	ProWstringToString(item_name,fam_item->string);
//获得族表子零件项目的值
	ProFaminstanceValueGet(data->fam_inst,fam_item,&item_val);
//获取族表子零件项目的类型
	//ProParamvalueTypeGet(&item_val,&item_type);

//如果族表中参数为“L1”将data->dataL1赋给子零件该参数
	strcpy(ditem_name,"R");
	if(strcmp(ditem_name,item_name)==0)
	{
		dbl_value=data->dataL;
		ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
		ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);//最后一个输入项有问题？
	}

	strcpy(ditem_name,"H");
	if(strcmp(ditem_name,item_name)==0)
	{
		dbl_value=data->dataL1;
		ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
		ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	}


	//strcpy(ditem_name,"L2");
	//if(strcmp(ditem_name,item_name)==0)
	//{
	//	dbl_value=data->dataL2;
	//	ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
	//	ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	//}


	//strcpy(ditem_name,"L3");
	//if(strcmp(ditem_name,item_name)==0)
	//{
	//	dbl_value=data->dataL3;
	//	ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
	//	ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	//}


	//strcpy(ditem_name,"L4");
	//if(strcmp(ditem_name,item_name)==0)
	//{
	//	dbl_value=data->dataL4;
	//	ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
	//	ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	//}

	//strcpy(ditem_name,"H1");
	//if(strcmp(ditem_name,item_name)==0)
	//{
	//	dbl_value=data->dataH1;
	//	ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
	//	ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	//}

	//strcpy(ditem_name,"H2");
	//if(strcmp(ditem_name,item_name)==0)
	//{
	//	dbl_value=data->dataH2;
	//	ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
	//	ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	//}

	//strcpy(ditem_name,"H3");
	//if(strcmp(ditem_name,item_name)==0)
	//{
	//	dbl_value=data->dataH3;
	//	ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
	//	ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	//}


	//strcpy(ditem_name,"R");
	//if(strcmp(ditem_name,item_name)==0)
	//{
	//	dbl_value=data->dataR;
	//	ProParamvalueSet(&item_val,(void*)&dbl_value,PRO_PARAM_DOUBLE);
	//	ProFaminstanceValueSet(data->fam_inst,fam_item,&item_val);
	//}
	
 
	return (PRO_TK_NO_ERROR);

}

//在族表中创建子零件，赋值，并显示之
ProError CNewMdlDlg::UserFamtable(ProMdl model,ProCharName inname,ProType mdtype)//输入的inname为族表子实例名称？？
{
	ProFamtable *p_famtable;
	ProFaminstance *p_inst;
	int status;
	UserData UsrData;
	ProName inst_name;
	int windowid;
	

//为变量p_famtable分配内存
	p_famtable=(ProFamtable *)malloc(sizeof(ProFamtable));

//初始化族表
	ProFamtableInit(model,p_famtable);//注意输入的model
	UsrData.fam_table=*p_famtable;

//初始化族表子零件
	ProStringToWstring(inst_name,inname);
	p_inst=(ProFaminstance*)malloc(sizeof(ProFaminstance));
	ProFaminstanceInit(inst_name,p_famtable,p_inst);
	UsrData.fam_inst=p_inst;
	ProFaminstanceAdd(p_inst);
    ProObjectwindowCreate(inst_name,mdtype,&windowid);//同时显示多个对象时可用此函数

//参数赋值??
	UpdateData(TRUE);
	UsrData.dataL=m_edit1;
	UsrData.dataL1=m_edit2;
 //   UsrData.dataL2=m_edit3;
 //   UsrData.dataL3=m_edit4;
	//UsrData.dataL4=m_edit5;
 //   UsrData.dataH1=m_edit6;
 //   UsrData.dataH2=m_edit7;
 //   UsrData.dataH3=m_edit8;
	//UsrData.dataR=m_edit9;
  /*  UsrData.dataH4=m_edit8;
    UsrData.dataH5=m_edit9;
    UsrData.dataR1=m_edit10;
*/
	

//设置族表访问函数
	ProFamtableItemVisit(p_famtable,(ProFamtableItemAction)UserFamtableItemAct,NULL,(ProAppData)&UsrData);
//为族表子零件分配内存
	instmdl=(ProMdl*)malloc(sizeof(ProMdl));

//在族表中建立子零件
	ProFaminstanceCreate(p_inst,instmdl);//instmdl为out,子实例模型的句柄
	ProFaminstanceRemove(p_inst);
//显示子零件
	ProSolidDisplay((ProSolid)*instmdl);
	ProWindowRepaint(windowid);//重载当前屏幕
	ProWindowActivate(windowid);
	return (PRO_TK_NO_ERROR);
}


//设置新的参数值
void ParamUpdate(double strtmp,char *Name,ProModelitem *modelitem)
{
    wchar_t ParamName,*NewValue;
	ProParameter param;
	ProParamvalue value;
    ProStringToWstring(&ParamName,Name);
	ProParameterInit(modelitem,&ParamName,&param);
    //获得参数值
	ProParameterValueGet(&param, &value);
     
    	      value.value.d_val=strtmp;
	   
	//新的参数值设置
	ProParameterValueSet(&param, &value);
}









void CNewMdlDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ProFamilyName name;
	ProMdl part;
	ProCharName JZname,JZinname;
	ProModelitem *modelitem;
	char*m_name1;

	UpdateData(TRUE);
    strcpy(JZname,"PRT0001");
	m_name1=(LPSTR)(LPCTSTR)m_name;
	strcpy(JZinname,m_name1);
	ProStringToWstring(name,JZname);
	ProMdlRetrieve(name,PRO_MDL_PART,&part);
	UserFamtable(part,JZinname,PRO_PART);
	
    CDialogEx::OnCancel();
	 
}


void CNewMdlDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnCancel();
}

//尺寸更新
void CNewMdlDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	ProMdl   model;
    ProModelitem modelitem;
	ProMdlCurrentGet(&model);
	ProMdlToModelitem(model,&modelitem);
    ParamUpdate(m_edit1,"L",&modelitem);
	ParamUpdate(m_edit2,"L1",&modelitem);
	ParamUpdate(m_edit3,"L2",&modelitem);
    ParamUpdate( m_edit4,"L3",&modelitem);
	ParamUpdate(m_edit5,"L4",&modelitem);
    ParamUpdate( m_edit6,"H1",&modelitem);
	ParamUpdate(m_edit7,"H2",&modelitem);
	ParamUpdate(m_edit8,"H3",&modelitem);
	ParamUpdate(m_edit9,"R",&modelitem);
     
	ProSolidRegenerate ((ProSolid)model,PRO_REGEN_NO_FLAGS);
	ProWindowRepaint(PRO_VALUE_UNUSED);
	UpdateData(FALSE);
}




//装配
ProError UserAssembleByDatums(ProAssembly asm_model,ProSolid comp_model)
{
	ProError status;
	ProMatrix identity_matrix = {{ 1.0, 0.0, 0.0, 0.0 }, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, 
								{0.0, 0.0, 0.0, 1.0}};	
	ProAsmcompconstraint constraint;//装配约束
	ProAsmcompconstraint*constraints;//装配约束组
	ProSelection asm_sel, comp_sel;
	ProAsmcomp asmcomp;
	ProMdl asmcomp_model;//装配体中用于定位的元件，即下面程序中select的元件
	ProIdTable c_id_table;
	c_id_table[0] = -1;
	int i;
	ProName asm_datums[3],comp_datums[3];
	ProSelection* sels;
    int 		nb_sel;
	ProAsmcomppath asmcomp_modelpath;
	ProModelitem asm_datum,comp_datum;
	


	ProStringToWstring(asm_datums[0],"JZ1TOPKE");
	ProStringToWstring(asm_datums[1],"JZ1RIGHTKE");
	//ProStringToWstring(asm_datums[2],"CESHI");

	ProStringToWstring(comp_datums[0],"TOP");
	ProStringToWstring(comp_datums[1],"RIGHT");
	ProStringToWstring(comp_datums[2],"FRONT");

    ProAsmcompAssemble (asm_model, comp_model, identity_matrix, &asmcomp);//将零件添加到组件初始位置
	ProArrayAlloc(0,sizeof(ProAsmcompconstraint),1,(ProArray*)&constraints);////分配装配约束数组

    status=ProSelect ("surface",1,NULL,NULL,NULL,NULL,&sels,&nb_sel);//选择一个零件prt_or_asm
	if (status != PRO_TK_NO_ERROR)
	return status;
	
	ProSelectionUnhighlight(sels[0]);
	if (status == PRO_TK_NO_ERROR)
    {
       if (nb_sel > 0)
       {
		   ProSelectionAsmcomppathGet(sels[0],&asmcomp_modelpath);
		   ProAsmcomppathMdlGet (&asmcomp_modelpath,(ProMdl*)&asmcomp_model);
	   }
	}

	for(i=0;i<2;i++)//i=3
	{
		ProModelitemByNameInit(asmcomp_model,PRO_SURFACE,asm_datums[i],&asm_datum);
		ProModelitemByNameInit(comp_model,PRO_SURFACE,comp_datums[i],&comp_datum);
		ProSelectionAlloc(&asmcomp_modelpath,&asm_datum,&asm_sel);
		ProSelectionAlloc(NULL,&comp_datum,&comp_sel);
		ProAsmcompconstraintAlloc(&constraint);
		ProAsmcompconstraintTypeSet(constraint,PRO_ASM_ALIGN);
		ProAsmcompconstraintAsmreferenceSet(constraint,asm_sel,PRO_DATUM_SIDE_YELLOW);
		ProAsmcompconstraintCompreferenceSet(constraint,comp_sel,PRO_DATUM_SIDE_YELLOW);
		ProArrayObjectAdd((ProArray*)&constraints,-1,1,&constraint);      
	}
	ProModelitemByNameInit(comp_model,PRO_SURFACE,comp_datums[2],&comp_datum);//
	ProSelectionAlloc(NULL,&comp_datum,&comp_sel);//
	ProSelectionCopy(sels[0], &asm_sel);//
	ProAsmcompconstraintAlloc(&constraint);//
    ProAsmcompconstraintTypeSet(constraint,PRO_ASM_ALIGN);//
	ProAsmcompconstraintAsmreferenceSet(constraint,asm_sel,PRO_DATUM_SIDE_YELLOW);//
	ProAsmcompconstraintCompreferenceSet(constraint,comp_sel,PRO_DATUM_SIDE_YELLOW);//
	ProArrayObjectAdd((ProArray*)&constraints,-1,1,&constraint);//
	
	
	status=ProAsmcompConstraintsSet(NULL,&asmcomp,constraints);
	if(status==	PRO_TK_NO_ERROR	)//检测返回值 test
	{
		AfxMessageBox(_T("youwenti"));
	}

	ProArrayFree ((ProArray*)&constraints);
	ProSelectionFree (&comp_sel);
    ProSelectionFree (&asm_sel);
	 
    ProSolidRegenerate ((ProSolid)asmcomp.owner,PRO_REGEN_CAN_FIX);//PRO_REGEN_CAN_FIX
	 

	return (PRO_TK_NO_ERROR);
}



//void CNewMdlDlg::OnBnClickedButton2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	ProAssembly asm_model;//当前装配体
//	ProFamilyName name;
//	ProMdl part;
//	ProCharName JZinname;
//
//    ProMdlCurrentGet((ProMdl*)&asm_model);
//	strcpy(JZinname,"yanweicao2");//yanweicao2
//	ProStringToWstring(name,JZinname);
//	ProMdlRetrieve(name,PRO_MDL_PART,&part);
//	UserAssembleByDatums(asm_model, (ProSolid)part);
//	ProWindowRepaint(PRO_VALUE_UNUSED);
//	ProTreetoolRefresh (asm_model);////模型树显示刷新
//
//
//}



ProError UserAssembleByDatums1(ProAssembly asm_model,ProSolid comp_model)
{
	ProError status;
    ProName comp_datums [3];
    ProMatrix identity_matrix = {{ 1.0, 0.0, 0.0, 0.0 }, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, 
								{0.0, 0.0, 0.0, 1.0}};	
    ProAsmcomp asmcomp;
    ProAsmcompconstraint* constraints;
    ProAsmcompconstraint constraint;
    int i;
    ProBoolean interact_flag = PRO_B_FALSE;
    ProModelitem asm_datum, comp_datum;
    ProSelection asm_sel, comp_sel;
    ProAsmcomppath comp_path;
    ProIdTable c_id_table;
    c_id_table [0] = -1;


	ProStringToWstring (comp_datums [0], "FRONT");
    ProStringToWstring (comp_datums [1], "TOP");
	ProStringToWstring (comp_datums [2], "RIGHT");
	ProAsmcompAssemble (asm_model, comp_model, identity_matrix, &asmcomp);
	ProArrayAlloc (0, sizeof (ProAsmcompconstraint), 1,(ProArray*)&constraints);
	for (i = 0;i < 3;i++)
   {
//Find the component datum
    status = ProModelitemByNameInit (comp_model, PRO_SURFACE,comp_datums [i], &comp_datum);
//Allocate the references
    ProSelectionAlloc (NULL, &comp_datum, &comp_sel);
    int n_sel;  
    ProSelection *sel;
    status = ProSelect ("datum,surface", 1, NULL, NULL, NULL, NULL, &sel, &n_sel);
    if (status!= PRO_TK_NO_ERROR || n_sel < 0)
    return (PRO_TK_USER_ABORT);
    ProSelectionCopy(sel[0], &asm_sel);
//Allocate and fillthe constraint.
    ProAsmcompconstraintAlloc (&constraint);
    ProAsmcompconstraintTypeSet (constraint, PRO_ASM_ALIGN);//ALIGN
    ProAsmcompconstraintAsmreferenceSet (constraint, asm_sel,PRO_DATUM_SIDE_YELLOW);
	ProAsmcompconstraintCompreferenceSet (constraint, comp_sel,PRO_DATUM_SIDE_YELLOW);
    ProArrayObjectAdd ((ProArray*)&constraints, -1, 1, &constraint);
   }
    ProAsmcompConstraintsSet (NULL, &asmcomp, constraints);
	ProSolidRegenerate ((ProSolid)asmcomp.owner,PRO_REGEN_CAN_FIX);

	return (PRO_TK_NO_ERROR);
}

void CNewMdlDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ProAssembly asm_model;//当前装配体
	ProFamilyName name;
	ProMdl part;
	ProCharName JZinname;

    ProMdlCurrentGet((ProMdl*)&asm_model);
	strcpy(JZinname,"12");//yanweicao2
	ProStringToWstring(name,JZinname);
	ProMdlRetrieve(name,PRO_MDL_PART,&part);
	UserAssembleByDatums1(asm_model, (ProSolid)part);
	ProWindowRepaint(PRO_VALUE_UNUSED);
	ProTreetoolRefresh (asm_model);////模型树显示刷新
}
