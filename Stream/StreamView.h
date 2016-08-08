
// StreamView.h : CStreamView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "AddDlg.h"
#include "afxcmn.h"
#include "PropSheet.h"


class CStreamView : public CFormView
{
protected: // �������л�����
	CStreamView();
	DECLARE_DYNCREATE(CStreamView)

public:
	enum{ IDD = IDD_STREAM_FORM };

// ����
public:
	CStreamDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	afx_msg LRESULT OnAdd_event_ok(WPARAM wParam, LPARAM lParam);
	virtual ~CStreamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CPropSheet m_clsProSheet;
	CAddDlg dlg;
public:
	HWND m_hwnd;
	int m_iSelect;
	int m_iStreamNum;
	afx_msg void OnFileAdd();
	CListCtrl m_List;
	bool m_bInOk;
	CString m_pStreamName[4];
	afx_msg void OnFileMru();
	afx_msg void OnRclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnFileDelete();
	afx_msg void OnFileSdelete();
	afx_msg void OnUpdateFileMru(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileDelete(CCmdUI *pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // StreamView.cpp �еĵ��԰汾
inline CStreamDoc* CStreamView::GetDocument() const
   { return reinterpret_cast<CStreamDoc*>(m_pDocument); }
#endif

