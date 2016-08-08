#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CAddDlg 对话框

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddDlg();

// 对话框数据
	enum { IDD = IDD_ADD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
