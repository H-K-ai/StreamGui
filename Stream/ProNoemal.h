#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CProNoemal 对话框

class CProNoemal : public CPropertyPage
{
	DECLARE_DYNAMIC(CProNoemal)

public:
public:
	CString* m_pstream;
	CProNoemal();
	virtual ~CProNoemal();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_NOMAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EName;
	CComboBox m_CStyle;
	CIPAddressCtrl m_IP;
	CEdit m_ERich;
	virtual BOOL OnInitDialog();
};
