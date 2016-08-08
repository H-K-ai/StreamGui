// ProNet.cpp : 实现文件
//

#include "stdafx.h"
#include "Stream.h"
#include "ProNet.h"
#include "afxdialogex.h"


// CProNet 对话框

IMPLEMENT_DYNAMIC(CProNet, CPropertyPage)

CProNet::CProNet()
	: CPropertyPage(CProNet::IDD)
{

}

CProNet::~CProNet()
{
}

void CProNet::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProNet, CPropertyPage)
END_MESSAGE_MAP()


// CProNet 消息处理程序


BOOL CProNet::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	RECT rect;
	this->GetWindowRect(&rect);
	rect.right -= 50;
	this->MoveWindow(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
