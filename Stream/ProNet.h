#pragma once


// CProNet 对话框

class CProNet : public CPropertyPage
{
	DECLARE_DYNAMIC(CProNet)

public:
	CProNet();
	virtual ~CProNet();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_NET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
