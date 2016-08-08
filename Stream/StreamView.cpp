
// StreamView.cpp : CStreamView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

	ON_MESSAGE(WM_USER+100,OnAdd_event_ok)                   //�Զ�����Ϣ

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

// CStreamView ����/����

CStreamView::CStreamView()
	: CFormView(CStreamView::IDD)
	, m_clsProSheet(_T("����"))
	, m_iStreamNum(0)
	, m_iSelect(-1)
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CStreamView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	dlg.m_pStreamName = m_pStreamName;  //�趨��ӶԻ�����������֮������ݴ��ݣ�����һ���ڴ�
	m_clsProSheet.m_normal.m_pstream = m_pStreamName;//�趨����ҳ��������֮������ݴ��ݣ�����һ���ڴ�
	m_hwnd = this->m_hWnd;
	dlg.m_pHwnd = &m_hwnd;    //��view�еľ�����ݸ���ӶԻ���ʹ���ܹ�������Ϣ����
	m_bInOk = 1;                      //��ǣ���ʼ���ɹ�����Ϊ�棬OnSize��Ϣ������������

	CRect rect;
	m_List.GetWindowRect(&rect);
	m_List.InsertColumn(0,_T("���"),LVCFMT_LEFT,rect.Width()/8,0);
	m_List.InsertColumn(1,_T("������"),LVCFMT_LEFT,rect.Width()/8,1);
	m_List.InsertColumn(2,_T("������"),LVCFMT_LEFT,rect.Width()/8,2);
	m_List.InsertColumn(3,_T("����ַ"),LVCFMT_LEFT,2*rect.Width()/8,3);
	m_List.InsertColumn(4,_T("��ע"),LVCFMT_LEFT,3*rect.Width()/8,4);
	m_List.SetExtendedStyle(m_List.GetStyle()|LVS_EX_FULLROWSELECT);//�˺���ʹ�õ����ĳ��ȫ��
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


// CStreamView ���

#ifdef _DEBUG
void CStreamView::AssertValid() const
{
	CFormView::AssertValid();
}

void CStreamView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CStreamDoc* CStreamView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStreamDoc)));
	return (CStreamDoc*)m_pDocument;
}
#endif //_DEBUG


// CStreamView ��Ϣ�������


void CStreamView::OnFileAdd()
{
	// TODO: �ڴ���������������
	dlg.DoModal();
}
LRESULT  CStreamView::OnAdd_event_ok(WPARAM wParam, LPARAM lParam)
{
	CString m_str;//��ʱ���������ڽ���ֵ��ʾ���������б���
	m_str.Format(_T("%d"),m_iStreamNum);//��������ֵ��ʽ������Ϊ�ַ���
	m_List.InsertItem(m_iStreamNum,m_str);//ָʾ��Ҫ�������
	m_List.SetItemText(m_iStreamNum,1,m_pStreamName[0]);//����¼��ӵ�ָ����������
	m_List.SetItemText(m_iStreamNum,2,m_pStreamName[1]);//����¼��ӵ�ָ����������
	m_List.SetItemText(m_iStreamNum,3,m_pStreamName[2]);//����¼��ӵ�ָ����������
	m_List.SetItemText(m_iStreamNum,4,m_pStreamName[3]);//����¼��ӵ�ָ����������
	m_iStreamNum++;//��¼������һ
	return 1;
}

void CStreamView::OnFileMru()
{
	// TODO: �ڴ���������������
	m_pStreamName[0] = m_List.GetItemText(m_iSelect,1);
	m_pStreamName[1] = m_List.GetItemText(m_iSelect,2);
	m_pStreamName[2] = m_List.GetItemText(m_iSelect,3);
	m_pStreamName[3] = m_List.GetItemText(m_iSelect,4);
	
	m_clsProSheet.DoModal();
}


void CStreamView::OnRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*************�ж������е�����һ��*************/
	for(int i = 0;i < m_iStreamNum;i++)
		if( m_List.GetItemState(i,TCIS_BUTTONPRESSED) == 1)
		{
			m_iSelect = i;//������굥�����к�
			break;
		}
		/*************�ж������е�����һ��*************/

		/******************�Ҽ�������Ϣ�˵�******************/
		POINT point;
		::GetCursorPos(&point);   //�õ���굱ǰ����
		CMenu m_Menu,*m_PupMenu;  //����Menu��
		m_Menu.LoadMenuW(IDR_MAINFRAME);//�õ��˵�����
		m_PupMenu = m_Menu.GetSubMenu(0);//�õ��˵�����һ���˵�
		m_PupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,point.x,point.y,this->GetParent(),0);//�����˵���
		/******************�Ҽ�������Ϣ�˵�******************/
	*pResult = 0;
}


void CStreamView::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i = 0;i < m_iStreamNum;i++)
		if(m_List.GetItemState(i,TCIS_BUTTONPRESSED) == 1)
		{
			m_iSelect = i;//������굥�����к�
			break;
		}
	*pResult = 0;
}


void CStreamView::OnFileDelete()
{
	// TODO: �ڴ���������������
	if(m_iSelect >= 0)  //��û��ѡ���κ��У���ִ������ɾ�����
	{
		CString m_str;
		m_List.DeleteItem(m_iSelect);//ɾ��ѡ����

		/***��ѡ����ɾ���󣬺�����кŽ��б��***/
		for(int i = m_iSelect;i < m_iStreamNum;i++)
		{
			m_str.Format(_T("%d"),i);
			m_List.SetItemText(i,0,m_str);
		}
		/***��ѡ����ɾ���󣬺�����кŽ��б��***/

		m_iSelect = -1;//��ѡ�б�����
		m_iStreamNum--;//ɾ������������һ
	}
}


void CStreamView::OnFileSdelete()
{
	// TODO: �ڴ���������������
	m_List.DeleteAllItems();//ɾ��ȫ����
	m_iSelect = -1;
	m_iStreamNum = 0;
}


void CStreamView::OnUpdateFileMru(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(m_iSelect < 0)pCmdUI->Enable(0);
	else pCmdUI->Enable(1);
}


void CStreamView::OnUpdateFileDelete(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(m_iSelect < 0)pCmdUI->Enable(0);//ʹ�˵���ʧЧ
	else pCmdUI->Enable(1);
}


void CStreamView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	if(m_bInOk)//���Ѿ���ʼ���ɹ���ִ���������
	{
		/****ʹ��List�ؼ�����������Ĵ�С�ı���ı�****/
		//RECT rect;
		//m_List.GetWindowRect(&rect);
		//m_List.ScreenToClient(&rect);
		//rect.right = cx;
		//rect.bottom = cy;
		//m_List.MoveWindow(&rect);
		///****ʹ��List�ؼ�����������Ĵ�С�ı���ı�****/

		///****ʹ��List�е��п������������Ĵ�С�ı���ı�****/
		//CRect crect;
		//this->GetClientRect(&crect);//�õ���ǰ�ͻ����Ĵ�С
		//m_List.SetColumnWidth(0,crect.Width()/8);//�����еĿ��
		//m_List.SetColumnWidth(1,crect.Width()/8);//�����еĿ��
		//m_List.SetColumnWidth(2,crect.Width()/8);//�����еĿ��
		//m_List.SetColumnWidth(3,2*crect.Width()/8);//�����еĿ��
		//m_List.SetColumnWidth(4,3*crect.Width()/8);//�����еĿ��
	}
	// TODO: �ڴ˴������Ϣ����������
}
