// ProNet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Stream.h"
#include "ProNet.h"
#include "afxdialogex.h"


// CProNet �Ի���

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


// CProNet ��Ϣ�������


BOOL CProNet::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	RECT rect;
	this->GetWindowRect(&rect);
	rect.right -= 50;
	this->MoveWindow(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
