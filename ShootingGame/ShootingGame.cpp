#include "framework.h"
#include "ShootingGame.h"

using namespace std;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
HWND                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SHOOTINGGAME, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);

    HWND hWnd = InitInstance(hInstance, nCmdShow);

    // 애플리케이션 초기화를 수행합니다:
    /*if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }*/
 
    //초기화 : 디버그창 띄우기
    START_DEBUG_CONSOLE();
    cout << endl << "//////////////슈팅 게임 프로그램 시작//////////////" << endl;

    InitGraphic(hWnd, 0, 0, 480, 800);       //그래픽 초기화
    Time::Init();                               //델타 타임 초기화


    MSG msg;

    // 기본 메시지 루프입니다:
    while (true)
    {
        //윈도우 메세지 처리
        //PeekMessage
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) == TRUE)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (msg.message == WM_QUIT)                         //윈도우창을 끄면 내부동작(디버그창)이 멈추도록(꺼지도록) 설정
            {                                                   //WM_QUIT >> 윈도우창의 X버튼을 누름(윈도우 창을 끔)
                break;
            }
        } 

        //게임 동작 코드
        Clear(0, 0, 0);                                   //화면 클리어

        Time::Update();                                         //델타 타임 업데이트

        ObjectManager::Update();                                //게임 객체 업데이트
        ObjectManager::Draw();                                  //게임 객체 생성

        Render();                                               //렌더링
    }

    //종료하기
    STOP_DEBUG_CONSOLE();

    ObjectManager::Clear();                                     //게임 객체 전체 삭제
    ExitGraphic();                                              //그래픽 삭제

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_Jet));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_Jet));

    return RegisterClassExW(&wcex);
}


HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, 
                             szTitle, 
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, 
                             0, 
                             CW_USEDEFAULT, 
                             0, 
                             nullptr, 
                             nullptr, 
                             hInstance, 
                             nullptr);

   if (hWnd==nullptr)
   {
      return nullptr;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return hWnd;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            //윈도우 화면을 다시 렌더링해서 장면 복구하기
            Render();

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
