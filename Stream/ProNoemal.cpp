// ProNoemal.cpp : 实现文件
//

#include "stdafx.h"
#include "Stream.h"
#include "ProNoemal.h"
#include "afxdialogex.h"


// CProNoemal 对话框

IMPLEMENT_DYNAMIC(CProNoemal, CPropertyPage)

CProNoemal::CProNoemal()
	: CPropertyPage(CProNoemal::IDD)
	, m_pstream(NULL)
{

}

CProNoemal::~CProNoemal()
{
}

void CProNoemal::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EName);
	DDX_Control(pDX, IDC_COMBO1, m_CStyle);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IP);
	DDX_Control(pDX, IDC_EDIT2, m_ERich);
}


BEGIN_MESSAGE_MAP(CProNoemal, CPropertyPage)
END_MESSAGE_MAP()


// CProNoemal 消息处理程序


BOOL CProNoemal::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_EName.SetWindowTextW(m_pstream[0]); //显示主界面中选定行号的属性（各项值CString类型）
	m_CStyle.SetWindowTextW(m_pstream[1]);
	m_IP.SetWindowTextW(m_pstream[2]);
	m_ERich.SetWindowTextW(m_pstream[3]);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
