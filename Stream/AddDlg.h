#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CAddDlg �Ի���

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddDlg();

// �Ի�������
	enum { IDD = IDD_ADD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	HWND* m_pHwnd;
	CString* m_pStreamName;

	CEdit m_EditName;
	CComboBox m_ComStyle;
	CIPAddressCtrl m_IP;
	CEdit m_EditRemark;

	afx_msg void OnBnClickedOk();
};
