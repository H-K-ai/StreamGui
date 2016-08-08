#pragma once
#include "pronoemal.h"
#include "pronet.h"
#include "ProNet.h"
#include "ProNoemal.h"


// CPropSheet

class CPropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropSheet)

public:
	CPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPropSheet();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CProNoemal m_normal;
	CProNet m_net;
};


