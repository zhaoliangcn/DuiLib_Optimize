#pragma once

namespace DuiLib
{
#define MAX_FONT_ID		30000
#define CARET_TIMERID	0x1999

	// 列表类型
	enum ListType
	{
		LT_LIST = 0,
		LT_COMBO,
		LT_TREE,
		LT_MENU,
	};

	// 鼠标光标定义
#define DUI_ARROW           32512
#define DUI_IBEAM           32513
#define DUI_WAIT            32514
#define DUI_CROSS           32515
#define DUI_UPARROW         32516
#define DUI_SIZE            32640
#define DUI_ICON            32641
#define DUI_SIZENWSE        32642
#define DUI_SIZENESW        32643
#define DUI_SIZEWE          32644
#define DUI_SIZENS          32645
#define DUI_SIZEALL         32646
#define DUI_NO              32648
#define DUI_HAND            32649

	// 消息类型
	enum DuiSig
	{
		DuiSig_end = 0, // [marks end of message map]
		DuiSig_lwl,     // LRESULT (WPARAM, LPARAM)
		DuiSig_vn,      // void (TNotifyUI)
	};

	// 核心控件
	class CControlUI;

	//针对TNotifyUI的性能优化
	//sType 和 sVirtualWnd 原本都是CDuiString字符串类型
	//TNotifyUI 这个消息基础结构是最常用的数据类型,适合使用基本数据类型和指针类型避免过多的拷贝构造函数调用

	// Structure for notifications to the outside world
	typedef struct tagTNotifyUI
	{
		//CDuiString sType;
		//CDuiString sVirtualWnd;
		WORD wType;
		unsigned int sVirtualWndNameHash;
		CControlUI* pSender;
		DWORD dwTimestamp;
		POINT ptMouse;
		WPARAM wParam;
		LPARAM lParam;		
	} TNotifyUI;

	class CNotifyPump;
	typedef void (CNotifyPump::*DUI_PMSG)(TNotifyUI& msg);  //指针类型

	union DuiMessageMapFunctions
	{
		DUI_PMSG pfn;   // generic member function pointer
		LRESULT(CNotifyPump::*pfn_Notify_lwl)(WPARAM, LPARAM);
		void (CNotifyPump::*pfn_Notify_vn)(TNotifyUI&);
	};

	//定义所有消息类型
	//////////////////////////////////////////////////////////////////////////

#define DUI_MSGTYPE_MENU                   (_T("menu"))  //1
#define DUI_MSGTYPE_LINK                   (_T("link"))  //2

#define DUI_MSGTYPE_TIMER                  (_T("timer"))  //3
#define DUI_MSGTYPE_CLICK                  (_T("click"))  //4
#define DUI_MSGTYPE_DBCLICK                (_T("dbclick"))  //5

#define DUI_MSGTYPE_RETURN                 (_T("return"))  //6
#define DUI_MSGTYPE_SCROLL                 (_T("scroll"))  //7

#define DUI_MSGTYPE_PREDROPDOWN            (_T("predropdown")) //8
#define DUI_MSGTYPE_DROPDOWN               (_T("dropdown"))//9
#define DUI_MSGTYPE_SETFOCUS               (_T("setfocus"))//10

#define DUI_MSGTYPE_KILLFOCUS              (_T("killfocus"))//11
#define DUI_MSGTYPE_ITEMCLICK 		   	   (_T("itemclick"))//12
#define DUI_MSGTYPE_ITEMRCLICK 			   (_T("itemrclick"))//13
#define DUI_MSGTYPE_TABSELECT              (_T("tabselect"))//14

#define DUI_MSGTYPE_ITEMSELECT 		   	   (_T("itemselect"))//15
#define DUI_MSGTYPE_ITEMEXPAND             (_T("itemexpand"))//16
#define DUI_MSGTYPE_WINDOWINIT             (_T("windowinit"))//17
#define DUI_MSGTYPE_WINDOWSIZE             (_T("windowsize"))//18
#define DUI_MSGTYPE_BUTTONDOWN 		   	   (_T("buttondown"))//19
#define DUI_MSGTYPE_MOUSEENTER			   (_T("mouseenter"))//20
#define DUI_MSGTYPE_MOUSELEAVE			   (_T("mouseleave"))//21

#define DUI_MSGTYPE_TEXTCHANGED            (_T("textchanged"))//22
#define DUI_MSGTYPE_HEADERCLICK            (_T("headerclick"))//23
#define DUI_MSGTYPE_ITEMDBCLICK            (_T("itemdbclick"))//24
#define DUI_MSGTYPE_SHOWACTIVEX            (_T("showactivex"))//25

#define DUI_MSGTYPE_ITEMCOLLAPSE           (_T("itemcollapse"))//26
#define DUI_MSGTYPE_ITEMACTIVATE           (_T("itemactivate"))//27
#define DUI_MSGTYPE_VALUECHANGED           (_T("valuechanged"))//28
#define DUI_MSGTYPE_VALUECHANGED_MOVE      (_T("movevaluechanged"))//29

#define DUI_MSGTYPE_SELECTCHANGED 		   (_T("selectchanged"))//30
#define DUI_MSGTYPE_UNSELECTED	 		   (_T("unselected"))//31

#define DUI_MSGTYPE_TREEITEMDBCLICK 		(_T("treeitemdbclick"))//32
#define DUI_MSGTYPE_CHECKCLICK				(_T("checkclick"))//33
#define DUI_MSGTYPE_TEXTROLLEND 			(_T("textrollend"))//34
#define DUI_MSGTYPE_COLORCHANGED		    (_T("colorchanged"))//35

#define DUI_MSGTYPE_LISTITEMSELECT 		   	(_T("listitemselect"))//36
#define DUI_MSGTYPE_LISTITEMCHECKED 		(_T("listitemchecked"))//37
#define DUI_MSGTYPE_COMBOITEMSELECT 		(_T("comboitemselect"))//38
#define DUI_MSGTYPE_LISTHEADERCLICK			(_T("listheaderclick"))//39
#define DUI_MSGTYPE_LISTHEADITEMCHECKED		(_T("listheaditemchecked"))//40
#define DUI_MSGTYPE_LISTPAGECHANGED			(_T("listpagechanged"))//41


	//extension message
#define DUI_MSGTYPE_RCLICK					(_T("rclick"))  //42
#define DUI_MSGTYPE_MCLICK					(_T("mclick"))  //43

#define DUI_WMSGTYPE_MENU                   (1)
#define DUI_WMSGTYPE_LINK                   (2)

#define DUI_WMSGTYPE_TIMER                  (3)
#define DUI_WMSGTYPE_CLICK                  (4)
#define DUI_WMSGTYPE_DBCLICK                (5)

#define DUI_WMSGTYPE_RETURN                 (6)
#define DUI_WMSGTYPE_SCROLL                 (7)

#define DUI_WMSGTYPE_PREDROPDOWN            (8)
#define DUI_WMSGTYPE_DROPDOWN               (9)
#define DUI_WMSGTYPE_SETFOCUS               (10)

#define DUI_WMSGTYPE_KILLFOCUS              (11)
#define DUI_WMSGTYPE_ITEMCLICK 		   		(12)
#define DUI_WMSGTYPE_ITEMRCLICK 			(13)
#define DUI_WMSGTYPE_TABSELECT              (14)

#define DUI_WMSGTYPE_ITEMSELECT 		   	(15)
#define DUI_WMSGTYPE_ITEMEXPAND             (16)
#define DUI_WMSGTYPE_WINDOWINIT             (17)
#define DUI_WMSGTYPE_WINDOWSIZE             (18)
#define DUI_WMSGTYPE_BUTTONDOWN 		   	(19)
#define DUI_WMSGTYPE_MOUSEENTER				(20)
#define DUI_WMSGTYPE_MOUSELEAVE				(21)

#define DUI_WMSGTYPE_TEXTCHANGED            (22)
#define DUI_WMSGTYPE_HEADERCLICK            (23)
#define DUI_WMSGTYPE_ITEMDBCLICK            (24)
#define DUI_WMSGTYPE_SHOWACTIVEX            (25)

#define DUI_WMSGTYPE_ITEMCOLLAPSE           (26)
#define DUI_WMSGTYPE_ITEMACTIVATE           (27)
#define DUI_WMSGTYPE_VALUECHANGED           (28)
#define DUI_WMSGTYPE_VALUECHANGED_MOVE      (29)

#define DUI_WMSGTYPE_SELECTCHANGED 			(30)
#define DUI_WMSGTYPE_UNSELECTED	 			(31)

#define DUI_WMSGTYPE_TREEITEMDBCLICK 		(32)
#define DUI_WMSGTYPE_CHECKCLICK				(33)
#define DUI_WMSGTYPE_TEXTROLLEND 			(34)
#define DUI_WMSGTYPE_COLORCHANGED		    (35)

#define DUI_WMSGTYPE_LISTITEMSELECT 		   	(36)
#define DUI_WMSGTYPE_LISTITEMCHECKED 			(37)
#define DUI_WMSGTYPE_COMBOITEMSELECT 			(38)
#define DUI_WMSGTYPE_LISTHEADERCLICK			(39)
#define DUI_WMSGTYPE_LISTHEADITEMCHECKED		(40)
#define DUI_WMSGTYPE_LISTPAGECHANGED			(41)
#define DUI_WMSGTYPE_RCLICK						(42)
#define DUI_WMSGTYPE_MCLICK						(43)


#define DUI_WMSGTYPE_CLICK_WPFAV            (44)
#define DUI_WMSGTYPE_CLICK_WPSET            (45)


#define DUI_WMSGTYPE_TABINDEXCHANGED			(46)
#define DUI_WMSGTYPE_TABCLOSED				(47)
#define DUI_WMSGTYPE_PAGERCHANGED			(48)
	//////////////////////////////////////////////////////////////////////////

	struct DUI_MSGMAP_ENTRY;
	struct DUI_MSGMAP
	{
#ifndef UILIB_STATIC
		const DUI_MSGMAP* (PASCAL* pfnGetBaseMap)();
#else
		const DUI_MSGMAP* pBaseMap;
#endif
		const DUI_MSGMAP_ENTRY* lpEntries;
	};

	//DUI_MSGMAP_ENTRY性能优化
	//去掉CDuiString类型的sMsgType
	//使用WORD类型的wMsgType
	//去掉CDuiString类型的sCtrlName
	//unsigned int保存sCtrlName的hash值
	//结构定义
	struct DUI_MSGMAP_ENTRY //定义一个结构体，来存放消息信息
	{
		//CDuiString sMsgType;          // DUI消息类型
		WORD wMsgType;
		//CDuiString sCtrlName;         // 控件名称
		unsigned int sCtrlNameHash;
		UINT       nSig;              // 标记函数指针类型
		DUI_PMSG   pfn;               // 指向函数的指针
		
	};

	//定义
#ifndef UILIB_STATIC
#define DUI_DECLARE_MESSAGE_MAP()                                         \
private:                                                                  \
	static const DUI_MSGMAP_ENTRY _messageEntries[];                      \
protected:                                                                \
	static const DUI_MSGMAP messageMap;                                   \
	static const DUI_MSGMAP* PASCAL _GetBaseMessageMap();                 \
	virtual const DUI_MSGMAP* GetMessageMap() const;                      \

#else
#define DUI_DECLARE_MESSAGE_MAP()                                         \
private:                                                                  \
	static const DUI_MSGMAP_ENTRY _messageEntries[];                      \
protected:                                                                \
	static  const DUI_MSGMAP messageMap;				                  \
	virtual const DUI_MSGMAP* GetMessageMap() const;                      \

#endif


	//基类声明开始
#ifndef UILIB_STATIC
#define DUI_BASE_BEGIN_MESSAGE_MAP(theClass)                              \
	const DUI_MSGMAP* PASCAL theClass::_GetBaseMessageMap()               \
	{ return NULL; }                                                  \
	const DUI_MSGMAP* theClass::GetMessageMap() const                     \
	{ return &theClass::messageMap; }                                 \
	UILIB_COMDAT const DUI_MSGMAP theClass::messageMap =                  \
	{  &theClass::_GetBaseMessageMap, &theClass::_messageEntries[0] };\
	UILIB_COMDAT const DUI_MSGMAP_ENTRY theClass::_messageEntries[] =     \
	{                                                                     \

#else
#define DUI_BASE_BEGIN_MESSAGE_MAP(theClass)                              \
	const DUI_MSGMAP* theClass::GetMessageMap() const                     \
	{ return &theClass::messageMap; }                                 \
	UILIB_COMDAT const DUI_MSGMAP theClass::messageMap =                  \
	{  NULL, &theClass::_messageEntries[0] };                         \
	UILIB_COMDAT const DUI_MSGMAP_ENTRY theClass::_messageEntries[] =     \
	{                                                                     \

#endif


	//子类声明开始
#ifndef UILIB_STATIC
#define DUI_BEGIN_MESSAGE_MAP(theClass, baseClass)                        \
	const DUI_MSGMAP* PASCAL theClass::_GetBaseMessageMap()               \
	{ return &baseClass::messageMap; }                                \
	const DUI_MSGMAP* theClass::GetMessageMap() const                     \
	{ return &theClass::messageMap; }                                 \
	UILIB_COMDAT const DUI_MSGMAP theClass::messageMap =                  \
	{ &theClass::_GetBaseMessageMap, &theClass::_messageEntries[0] }; \
	UILIB_COMDAT const DUI_MSGMAP_ENTRY theClass::_messageEntries[] =     \
	{                                                                     \

#else
#define DUI_BEGIN_MESSAGE_MAP(theClass, baseClass)                        \
	const DUI_MSGMAP* theClass::GetMessageMap() const                     \
	{ return &theClass::messageMap; }                                 \
	UILIB_COMDAT const DUI_MSGMAP theClass::messageMap =                  \
	{ &baseClass::messageMap, &theClass::_messageEntries[0] };        \
	UILIB_COMDAT const DUI_MSGMAP_ENTRY theClass::_messageEntries[] =     \
	{                                                                     \

#endif


	//声明结束
#define DUI_END_MESSAGE_MAP()                                             \
	{ 0, 0, DuiSig_end, (DUI_PMSG)0 }                           \
	};                                                                        \


	//定义消息类型--执行函数宏
#define DUI_ON_MSGTYPE(msgtype, memberFxn)                                \
	{ msgtype, 0, DuiSig_vn, (DUI_PMSG)&memberFxn},                  \


	//定义消息类型--控件名称--执行函数宏
#define DUI_ON_MSGTYPE_CTRNAME(msgtype,ctrname,memberFxn)                 \
	{ msgtype, BKDRHash(ctrname), DuiSig_vn, (DUI_PMSG)&memberFxn },                \


	//定义click消息的控件名称--执行函数宏
#define DUI_ON_CLICK_CTRNAME(ctrname,memberFxn)                           \
	{ DUI_WMSGTYPE_CLICK, BKDRHash(ctrname), DuiSig_vn, (DUI_PMSG)&memberFxn },      \


	//定义selectchanged消息的控件名称--执行函数宏
#define DUI_ON_SELECTCHANGED_CTRNAME(ctrname,memberFxn)                   \
	{ DUI_WMSGTYPE_SELECTCHANGED,BKDRHash(ctrname),DuiSig_vn,(DUI_PMSG)&memberFxn }, \


	//定义killfocus消息的控件名称--执行函数宏
#define DUI_ON_KILLFOCUS_CTRNAME(ctrname,memberFxn)                       \
	{ DUI_WMSGTYPE_KILLFOCUS,BKDRHash(ctrname),DuiSig_vn,(DUI_PMSG)&memberFxn },     \


	//定义menu消息的控件名称--执行函数宏
#define DUI_ON_MENU_CTRNAME(ctrname,memberFxn)                            \
	{ DUI_WMSGTYPE_MENU,BKDRHash(ctrname),DuiSig_vn,(DUI_PMSG)&memberFxn },          \


	//定义与控件名称无关的消息宏

	//定义timer消息--执行函数宏
#define DUI_ON_TIMER()                                                    \
	{ DUI_WMSGTYPE_TIMER, 0, DuiSig_vn,(DUI_PMSG)&OnTimer },          \


	///
	//////////////END消息映射宏定义////////////////////////////////////////////////////


	//////////////BEGIN控件名称宏定义//////////////////////////////////////////////////
	///

#define  DUI_CTR_EDIT                            (_T("Edit"))
#define  DUI_CTR_LIST                            (_T("List"))
#define  DUI_CTR_TEXT                            (_T("Text"))

#define  DUI_CTR_COMBO                           (_T("Combo"))
#define  DUI_CTR_LABEL                           (_T("Label"))
#define  DUI_CTR_FLASH							 (_T("Flash"))

#define  DUI_CTR_BUTTON                          (_T("Button"))
#define  DUI_CTR_OPTION                          (_T("Option"))
#define  DUI_CTR_SLIDER                          (_T("Slider"))

#define  DUI_CTR_CONTROL                         (_T("Control"))
#define  DUI_CTR_ACTIVEX                         (_T("ActiveX"))
#define  DUI_CTR_GIFANIM                         (_T("GifAnim"))

#define  DUI_CTR_LISTITEM                        (_T("ListItem"))
#define  DUI_CTR_PROGRESS                        (_T("Progress"))
#define  DUI_CTR_RICHEDIT                        (_T("RichEdit"))
#define  DUI_CTR_CHECKBOX                        (_T("CheckBox"))
#define  DUI_CTR_COMBOBOX                        (_T("ComboBox"))
#define  DUI_CTR_DATETIME                        (_T("DateTime"))
#define  DUI_CTR_TREEVIEW                        (_T("TreeView"))
#define  DUI_CTR_TREENODE                        (_T("TreeNode"))

#define  DUI_CTR_CONTAINER                       (_T("Container"))
#define  DUI_CTR_TABLAYOUT                       (_T("TabLayout"))
#define  DUI_CTR_SCROLLBAR                       (_T("ScrollBar"))
#define  DUI_CTR_IPADDRESS                       (_T("IPAddress"))

#define  DUI_CTR_LISTHEADER                      (_T("ListHeader"))
#define  DUI_CTR_LISTFOOTER                      (_T("ListFooter"))
#define  DUI_CTR_TILELAYOUT                      (_T("TileLayout"))
#define  DUI_CTR_WEBBROWSER                      (_T("WebBrowser"))

#define  DUI_CTR_CHILDLAYOUT                     (_T("ChildLayout"))
#define  DUI_CTR_LISTELEMENT                     (_T("ListElement"))

#define  DUI_CTR_VERTICALLAYOUT                  (_T("VerticalLayout"))
#define  DUI_CTR_LISTHEADERITEM                  (_T("ListHeaderItem"))

#define  DUI_CTR_LISTTEXTELEMENT                 (_T("ListTextElement"))

#define  DUI_CTR_HORIZONTALLAYOUT                (_T("HorizontalLayout"))
#define  DUI_CTR_LISTLABELELEMENT                (_T("ListLabelElement"))

#define  DUI_CTR_ANIMATIONTABLAYOUT				 (_T("AnimationTabLayout"))

#define  DUI_CTR_LISTCONTAINERELEMENT            (_T("ListContainerElement"))

#define  DUI_CTR_TEXTSCROLL						 (_T("TextScroll"))

#define DUI_CTR_COLORPALETTE					  (_T("ColorPalette"))
	///
	//////////////END控件名称宏定义//////////////////////////////////////////////////

	}// namespace DuiLib

