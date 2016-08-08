
// StreamView.h : CStreamView 类的接口
//

#pragma once

#include "resource.h"
#include "AddDlg.h"
#include "afxcmn.h"
#include "PropSheet.h"


class CStreamView : public CFormView
{
protected: // 仅从序列化创建
	CStreamView();
	DECLARE_DYNCREATE(CStreamView)

public:
	enum{ IDD = IDD_STREAM_FORM };

// 特性
public:
	CStreamDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	afx_msg LRESULT OnAdd_event_ok(WPARAM wParam, LPARAM lParam);
	virtual ~CStreamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // StreamView.cpp 中的调试版本
inline CStreamDoc* CStreamView::GetDocument() const
   { return reinterpret_cast<CStreamDoc*>(m_pDocument); }
#endif

