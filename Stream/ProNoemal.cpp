// ProNoemal.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Stream.h"
#include "ProNoemal.h"
#include "afxdialogex.h"


// CProNoemal �Ի���

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


// CProNoemal ��Ϣ�������


BOOL CProNoemal::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_EName.SetWindowTextW(m_pstream[0]); //��ʾ��������ѡ���кŵ����ԣ�����ֵCString���ͣ�
	m_CStyle.SetWindowTextW(m_pstream[1]);
	m_IP.SetWindowTextW(m_pstream[2]);
	m_ERich.SetWindowTextW(m_pstream[3]);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
