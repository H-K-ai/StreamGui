
// StreamView.cpp : CStreamView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Stream.h"
#endif

#include "StreamDoc.h"
#include "StreamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStreamView

IMPLEMENT_DYNCREATE(CStreamView, CFormView)

BEGIN_MESSAGE_MAP(CStreamView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()

	ON_MESSAGE(WM_USER+100,OnAdd_event_ok)                   //自定义消息

	ON_COMMAND(ID_FILE_ADD, &CStreamView::OnFileAdd)
	ON_COMMAND(ID_FILE_MRU, &CStreamView::OnFileMru)

	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CStreamView::OnRclickList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CStreamView::OnClickList1)

	ON_COMMAND(ID_FILE_DELETE, &CStreamView::OnFileDelete)
	ON_COMMAND(ID_FILE_SDELETE, &CStreamView::OnFileSdelete)

	ON_UPDATE_COMMAND_UI(ID_FILE_MRU, &CStreamView::OnUpdateFileMru)
	ON_UPDATE_COMMAND_UI(ID_FILE_DELETE, &CStreamView::OnUpdateFileDelete)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CStreamView 构造/析构

CStreamView::CStreamView()
	: CFormView(CStreamView::IDD)
	, m_clsProSheet(_T("属性"))
	, m_iStreamNum(0)
	, m_iSelect(-1)
{
	// TODO: 在此处添加构造代码

}

CStreamView::~CStreamView()
{
}

void CStreamView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BOOL CStreamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CStreamView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	dlg.m_pStreamName = m_pStreamName;  //设定添加对话框与主界面之间的数据传递，共用一块内存
	m_clsProSheet.m_normal.m_pstream = m_pStreamName;//设定属性页与主界面之间的数据传递，共用一块内存
	m_hwnd = this->m_hWnd;
	dlg.m_pHwnd = &m_hwnd;    //将view中的句柄传递给添加对话框，使得能够发送消息到此
	m_bInOk = 1;                      //标记，初始化成功后置为真，OnSize消息就能正常运行

	CRect rect;
	m_List.GetWindowRect(&rect);
	m_List.InsertColumn(0,_T("序号"),LVCFMT_LEFT,rect.Width()/8,0);
	m_List.InsertColumn(1,_T("流名称"),LVCFMT_LEFT,rect.Width()/8,1);
	m_List.InsertColumn(2,_T("流类型"),LVCFMT_LEFT,rect.Width()/8,2);
	m_List.InsertColumn(3,_T("流地址"),LVCFMT_LEFT,2*rect.Width()/8,3);
	m_List.InsertColumn(4,_T("备注"),LVCFMT_LEFT,3*rect.Width()/8,4);
	m_List.SetExtendedStyle(m_List.GetStyle()|LVS_EX_FULLROWSELECT);//此函数使得点击的某行全亮
}

void CStreamView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CStreamView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CStreamView 诊断

#ifdef _DEBUG
void CStreamView::AssertValid() const
{
	CFormView::AssertValid();
}

void CStreamView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CStreamDoc* CStreamView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStreamDoc)));
	return (CStreamDoc*)m_pDocument;
}
#endif //_DEBUG


// CStreamView 消息处理程序


void CStreamView::OnFileAdd()
{
	// TODO: 在此添加命令处理程序代码
	dlg.DoModal();
}
LRESULT  CStreamView::OnAdd_event_ok(WPARAM wParam, LPARAM lParam)
{
	CString m_str;//临时变量，用于将数值显示在主界面列表中
	m_str.Format(_T("%d"),m_iStreamNum);//将整形数值格式化输入为字符型
	m_List.InsertItem(m_iStreamNum,m_str);//指示将要插入的行
	m_List.SetItemText(m_iStreamNum,1,m_pStreamName[0]);//将记录添加到指定的行列中
	m_List.SetItemText(m_iStreamNum,2,m_pStreamName[1]);//将记录添加到指定的行列中
	m_List.SetItemText(m_iStreamNum,3,m_pStreamName[2]);//将记录添加到指定的行列中
	m_List.SetItemText(m_iStreamNum,4,m_pStreamName[3]);//将记录添加到指定的行列中
	m_iStreamNum++;//记录总数加一
	return 1;
}

void CStreamView::OnFileMru()
{
	// TODO: 在此添加命令处理程序代码
	m_pStreamName[0] = m_List.GetItemText(m_iSelect,1);
	m_pStreamName[1] = m_List.GetItemText(m_iSelect,2);
	m_pStreamName[2] = m_List.GetItemText(m_iSelect,3);
	m_pStreamName[3] = m_List.GetItemText(m_iSelect,4);
	
	m_clsProSheet.DoModal();
}


void CStreamView::OnRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	/*************判断鼠标点中的是哪一行*************/
	for(int i = 0;i < m_iStreamNum;i++)
		if( m_List.GetItemState(i,TCIS_BUTTONPRESSED) == 1)
		{
			m_iSelect = i;//返回鼠标单击的行号
			break;
		}
		/*************判断鼠标点中的是哪一行*************/

		/******************右键弹出消息菜单******************/
		POINT point;
		::GetCursorPos(&point);   //得到鼠标当前坐标
		CMenu m_Menu,*m_PupMenu;  //定义Menu类
		m_Menu.LoadMenuW(IDR_MAINFRAME);//得到菜单项栏
		m_PupMenu = m_Menu.GetSubMenu(0);//得到菜单栏得一级菜单
		m_PupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,point.x,point.y,this->GetParent(),0);//弹出菜单项
		/******************右键弹出消息菜单******************/
	*pResult = 0;
}


void CStreamView::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	for(int i = 0;i < m_iStreamNum;i++)
		if(m_List.GetItemState(i,TCIS_BUTTONPRESSED) == 1)
		{
			m_iSelect = i;//返回鼠标单机的行号
			break;
		}
	*pResult = 0;
}


void CStreamView::OnFileDelete()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iSelect >= 0)  //若没有选中任何行，则不执行下面删除语句
	{
		CString m_str;
		m_List.DeleteItem(m_iSelect);//删除选中行

		/***将选中行删除后，后面的行号进行变更***/
		for(int i = m_iSelect;i < m_iStreamNum;i++)
		{
			m_str.Format(_T("%d"),i);
			m_List.SetItemText(i,0,m_str);
		}
		/***将选中行删除后，后面的行号进行变更***/

		m_iSelect = -1;//将选中标记清除
		m_iStreamNum--;//删除后将总行数减一
	}
}


void CStreamView::OnFileSdelete()
{
	// TODO: 在此添加命令处理程序代码
	m_List.DeleteAllItems();//删除全部行
	m_iSelect = -1;
	m_iStreamNum = 0;
}


void CStreamView::OnUpdateFileMru(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if(m_iSelect < 0)pCmdUI->Enable(0);
	else pCmdUI->Enable(1);
}


void CStreamView::OnUpdateFileDelete(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if(m_iSelect < 0)pCmdUI->Enable(0);//使菜单项失效
	else pCmdUI->Enable(1);
}


void CStreamView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	if(m_bInOk)//若已经初始化成功，执行下面语句
	{
		/****使得List控件随着主界面的大小改变而改变****/
		//RECT rect;
		//m_List.GetWindowRect(&rect);
		//m_List.ScreenToClient(&rect);
		//rect.right = cx;
		//rect.bottom = cy;
		//m_List.MoveWindow(&rect);
		///****使得List控件随着主界面的大小改变而改变****/

		///****使得List中的列宽度随着主界面的大小改变而改变****/
		//CRect crect;
		//this->GetClientRect(&crect);//得到当前客户区的大小
		//m_List.SetColumnWidth(0,crect.Width()/8);//设置列的宽度
		//m_List.SetColumnWidth(1,crect.Width()/8);//设置列的宽度
		//m_List.SetColumnWidth(2,crect.Width()/8);//设置列的宽度
		//m_List.SetColumnWidth(3,2*crect.Width()/8);//设置列的宽度
		//m_List.SetColumnWidth(4,3*crect.Width()/8);//设置列的宽度
	}
	// TODO: 在此处添加消息处理程序代码
}
