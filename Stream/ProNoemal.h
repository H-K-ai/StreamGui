#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CProNoemal �Ի���

class CProNoemal : public CPropertyPage
{
	DECLARE_DYNAMIC(CProNoemal)

public:
public:
	CString* m_pstream;
	CProNoemal();
	virtual ~CProNoemal();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_NOMAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EName;
	CComboBox m_CStyle;
	CIPAddressCtrl m_IP;
	CEdit m_ERich;
	virtual BOOL OnInitDialog();
};
