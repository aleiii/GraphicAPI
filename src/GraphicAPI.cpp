// GraphicAPI.cpp : 定义应用程序的入口点。
//

//#include "framework.h"
#include "GraphicAPI.h"
#include "GraphicDraw.h"

#define MAX_LOADSTRING 100
#define WIN_WIDTH   1200
#define WIN_HEIGHT  800

using namespace ALEI;
// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int, HWND&);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void MY_PAINT_MISSION(HDC hdc);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	//HINSTANCE hInstance = GetModuleHandle(0);
	//int nCmdShow = 10;
    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GRAPHICAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
	HWND hWnd;

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow, hWnd))
    {
        return FALSE;
    }

	HDC hdc = GetDC(hWnd);
    // TODO: 在此处放置代码。
	// MY_PAINT_MISSION(hdc);

	
	//ALEI::line(hdc, 100, 100, 200, 300);
	//ALEI::circle(hdc, 150, 150, 100, 3*pi/4, 2*pi);
	//ALEI::ellipse(hdc, 400, 400, 100, 50);

	//用线段画一个矩形
	ALEI::line(hdc, 500, 200, 600, 200);
	ALEI::line(hdc, 500, 250, 600, 250);
	ALEI::line(hdc, 500, 200, 500, 250);
	ALEI::line(hdc, 600, 200, 600, 250);
	ALEI::Flood_Fill_4(hdc, 550, 210, RGB(255,255,255), RGB(255,0,0));

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAPHICAPI));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GRAPHICAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    // wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GRAPHICAPI);
	// 菜单栏
	wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, HWND &hWnd)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, WIN_WIDTH, WIN_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    //case WM_COMMAND:
    //    {
    //        int wmId = LOWORD(wParam);
    //        // 分析菜单选择:
    //        switch (wmId)
    //        {
    //        case IDM_ABOUT:
    //            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
    //            break;
    //        case IDM_EXIT:
    //            DestroyWindow(hWnd);
    //            break;
    //        default:
    //            return DefWindowProc(hWnd, message, wParam, lParam);
    //        }
    //    }
    //    break;
    //case WM_PAINT:
    //    {
		
    //        //PAINTSTRUCT ps;
    //        //HDC hdc = BeginPaint(hWnd, &ps);
    //        //// TODO: 在此处添加使用 hdc 的任何绘图代码...

    //        //EndPaint(hWnd, &ps);
    //    }
    //    break;
	case WM_ERASEBKGND:
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//// “关于”框的消息处理程序。
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}

// 此处为绘图任务内容
void MY_PAINT_MISSION(HDC hdc) {
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
			SetPixel(hdc, i, j, RGB(255, 182, 193));
	}
	SetPixel(hdc, 200, 200, RGB(255, 0, 0));
}
