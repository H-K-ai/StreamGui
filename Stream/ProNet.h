#pragma once


// CProNet �Ի���

class CProNet : public CPropertyPage
{
	DECLARE_DYNAMIC(CProNet)

public:
	CProNet();
	virtual ~CProNet();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_NET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
