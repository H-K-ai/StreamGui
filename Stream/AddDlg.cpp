// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Stream.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// CAddDlg �Ի���

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddDlg::IDD, pParent)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditName);
	DDX_Control(pDX, IDC_COMBO1, m_ComStyle);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IP);
	DDX_Control(pDX, IDC_EDIT2, m_EditRemark);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddDlg ��Ϣ�������


void CAddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_EditName.GetWindowTextW(m_pStreamName[0]);
	m_ComStyle.GetWindowTextW(m_pStreamName[1]);
	m_IP.GetWindowTextW(m_pStreamName[2]);
	m_EditRemark.GetWindowTextW(m_pStreamName[3]);
	::SendMessage(*m_pHwnd,WM_USER+100,1,1);
	CDialogEx::OnOK();
}
