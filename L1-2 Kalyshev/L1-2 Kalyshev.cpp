// L1-2 Kalyshev.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "L1-2 Kalyshev.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_L12KALYSHEV, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L12KALYSHEV));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L12KALYSHEV));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_L12KALYSHEV);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		HPEN hPen_stvol;
		HPEN hPen_crona;
		HPEN hPen_crona_dark;
		HPEN hPen_sun;
		HPEN hPen_cloud;
		HPEN hPen_line;
		HPEN hPen_wood;
		HPEN hPen_white;
		HBRUSH hBrush_line;
		HBRUSH hBrush_crona;
		HBRUSH hBrush_crona_dark;
		HBRUSH hBrush_sun;
		HBRUSH hBrush_cloud;
		HBRUSH hBrush_wood;
		HBRUSH hBrush_wood_lite;
		HBRUSH hBrush_red_car;
		HBRUSH hBrush_black_car;
		HBRUSH hBrush_white;
		hPen_line = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		hPen_stvol = CreatePen(PS_SOLID, 20, RGB(119, 38, 19));
		hPen_crona = CreatePen(PS_SOLID, 20, RGB(27, 111, 12));
		hPen_crona_dark = CreatePen(PS_SOLID, 20, RGB(12, 45, 1));
		hPen_sun = CreatePen(PS_SOLID, 5, RGB(214, 228, 0));
		hPen_cloud = CreatePen(PS_SOLID, 5, RGB(145, 173, 255));
		hPen_wood = CreatePen(PS_SOLID, 1, RGB(132, 77, 44));
		hPen_white = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
		hBrush_crona = CreateSolidBrush(RGB(27, 111, 12));
		hBrush_crona_dark = CreateSolidBrush(RGB(12, 45, 1));
		hBrush_sun = CreateHatchBrush(HS_CROSS, RGB(214, 228, 0));
		hBrush_cloud = CreateSolidBrush(RGB(145, 173, 255));
		hBrush_wood = CreateSolidBrush(RGB(132, 77, 44));
		hBrush_wood_lite = CreateSolidBrush(RGB(173, 107, 55));
		hBrush_line = CreateSolidBrush(RGB(255, 255, 255));
		hBrush_red_car = CreateSolidBrush(RGB(255, 0, 0));
		hBrush_black_car = CreateSolidBrush(RGB(0, 0, 0));
		hBrush_white = CreateSolidBrush(RGB(255, 255, 255));

		// TODO: Добавьте сюда любой код прорисовки, использующий HDC...

		// Крыша
		POINT poly[4];
		poly[0].x = 150;
		poly[0].y = 350;
		poly[1].x = 275;
		poly[1].y = 250;
		poly[2].x = 400;
		poly[2].y = 350;
		SelectObject(hdc, hBrush_wood_lite);
		Polygon(hdc, poly, 3);
		MoveToEx(hdc, 150, 350, NULL);
		LineTo(hdc, 275, 250);
		LineTo(hdc, 400, 350);
		// Дом
		RECT rect_house = { 150, 350, 400, 525 };
		FillRect(hdc, &rect_house, hBrush_wood);
		LineTo(hdc, 400, 525);
		LineTo(hdc, 150, 525);
		LineTo(hdc, 150, 350);
		LineTo(hdc, 400, 350);
		// Окно
		RECT rect_window = { 225, 400, 325, 475 };
		FillRect(hdc, &rect_window, hBrush_cloud);
		MoveToEx(hdc, 225, 400, NULL);
		LineTo(hdc, 225, 475);
		LineTo(hdc, 325, 475);
		LineTo(hdc, 325, 400);
		LineTo(hdc, 225, 400);
		// Рама
		MoveToEx(hdc, 275, 400, NULL);
		LineTo(hdc, 275, 475);
		MoveToEx(hdc, 275, 425, NULL);
		LineTo(hdc, 325, 425);

		// Ёлка
		MoveToEx(hdc, 500, 400, NULL);
		LineTo(hdc, 525, 375);
		LineTo(hdc, 550, 400);
		LineTo(hdc, 500, 400);
		MoveToEx(hdc, 475, 450, NULL);
		LineTo(hdc, 525, 400);
		LineTo(hdc, 575, 450);
		LineTo(hdc, 475, 450);
		MoveToEx(hdc, 450, 525, NULL);
		LineTo(hdc, 525, 450);
		LineTo(hdc, 600, 525);
		LineTo(hdc, 450, 525);

		// Деревце

		//Ствол
		SelectObject(hdc, hPen_stvol);
		MoveToEx(hdc, 700, 525, NULL);
		LineTo(hdc, 700, 350);
		//Крона
		SelectObject(hdc, hPen_crona);
		SelectObject(hdc, hBrush_crona);
		Ellipse(hdc, 650, 250, 750, 450);
		SelectObject(hdc, hPen_crona_dark);
		SelectObject(hdc, hBrush_crona_dark);
		Ellipse(hdc, 672, 380, 690, 400);
		Ellipse(hdc, 722, 330, 740, 350);
		Ellipse(hdc, 692, 280, 710, 300);

		// Солнышко
		SelectObject(hdc, hPen_sun);
		SelectObject(hdc, hBrush_sun);
		Ellipse(hdc, 50, 50, 150, 150);

		// Облако
		SelectObject(hdc, hPen_cloud);
		SelectObject(hdc, hBrush_cloud);
		Ellipse(hdc, 300, 50, 500, 150);
		Ellipse(hdc, 350, 100, 550, 200);
		Ellipse(hdc, 450, 100, 650, 194);
		Ellipse(hdc, 420, 30, 660, 130);

		// Лучи
		SelectObject(hdc, hPen_sun);
		MoveToEx(hdc, 60, 150, NULL);
		LineTo(hdc, 40, 200);
		MoveToEx(hdc, 100, 160, NULL);
		LineTo(hdc, 100, 220);
		MoveToEx(hdc, 145, 150, NULL);
		LineTo(hdc, 175, 200);
		MoveToEx(hdc, 160, 125, NULL);
		LineTo(hdc, 200, 160);

		// Машина
		//Кузов
		POINT poly1[11];
		poly1[0].x = 100;
		poly1[0].y = 800;
		poly1[1].x = 500;
		poly1[1].y = 800;
		poly1[2].x = 500;
		poly1[2].y = 740;
		poly1[3].x = 490;
		poly1[3].y = 740;
		poly1[4].x = 490;
		poly1[4].y = 650;
		poly1[5].x = 240;
		poly1[5].y = 650;
		poly1[6].x = 220;
		poly1[6].y = 720;
		poly1[7].x = 110;
		poly1[7].y = 720;
		poly1[8].x = 110;
		poly1[8].y = 740;
		poly1[9].x = 100;
		poly1[9].y = 740;
		poly1[10].x = 100;
		poly1[10].y = 800;
		SelectObject(hdc, hPen_line);
		SelectObject(hdc, hBrush_red_car);
		Polygon(hdc, poly1, 11);

		//Стекла
		POINT poly2[5];
		poly2[0].x = 240;
		poly2[0].y = 720;
		poly2[1].x = 255;
		poly2[1].y = 660;
		poly2[2].x = 470;
		poly2[2].y = 660;
		poly2[3].x = 470;
		poly2[3].y = 720;
		poly2[4].x = 240;
		poly2[4].y = 720;
		SelectObject(hdc, hPen_line);
		SelectObject(hdc, hBrush_cloud);
		Polygon(hdc, poly2, 5);

		MoveToEx(hdc, 300, 660, NULL);
		LineTo(hdc, 300, 720);
		MoveToEx(hdc, 400, 660, NULL);
		LineTo(hdc, 400, 720);
		//Колеса
		SelectObject(hdc, hBrush_black_car);
		Ellipse(hdc, 130, 740, 230, 840);
		Ellipse(hdc, 370, 740, 470, 840);

		//1
		SelectObject(hdc, hPen_line);
		int x1_1 = 800, y1_1 = 100;
		int x2_1 = 950, y2_1 = 0;
		int i_1 = 0;
		do {
			MoveToEx(hdc, x1_1, y1_1, NULL);
			LineTo(hdc, x2_1, y2_1);
			x1_1 = x1_1 + 6;
			y2_1 = y2_1 + 6;
			i_1++;
		} while (i_1 < 15);

		//2
		int x1_2 = 1000, y1_2 = 100;
		int x2_2 = 1200, y2_2 = 0;
		int i_2 = 0;
		do {
			MoveToEx(hdc, x1_2, y1_2, NULL);
			LineTo(hdc, x2_2, y2_2);
			x1_2 = x1_2 + 7;
			x2_2 = x2_2 - 7;
			i_2++;
		} while (i_2 < 15);

		//3
		int x1_3 = 1300, y1_3 = 100;
		int x2_3 = 1300, y2_3 = 0;
		int i_3 = 0;
		do {
			MoveToEx(hdc, x1_3, y1_3, NULL);
			LineTo(hdc, x2_3, y2_3);
			y1_3 = y1_3 - 5;
			x2_3 = x2_3 + 5;
			i_3++;
		} while (i_3 < 15);

		//4
		int x1_4 = 800, y1_4 = 400;
		int x2_4 = 800, y2_4 = 300;
		int i_4 = 0;
		do {
			MoveToEx(hdc, x1_4, y1_4, NULL);
			LineTo(hdc, x2_4, y2_4);
			x1_4 = x1_4 + 6;
			x2_4 = x2_4 + 6;
			y1_4 = y1_4 + 2;
			y2_4 = y2_4 - 2;
			i_4++;
		} while (i_4 < 15);

		//5
		int x1_5 = 1000, y1_5 = 400;
		int x2_5 = 1000, y2_5 = 300;
		int i_5 = 0;
		do {
			MoveToEx(hdc, x1_5, y1_5, NULL);
			LineTo(hdc, x2_5, y2_5);
			x1_5 = x1_5 + 6;
			x2_5 = x2_5 + 6;
			y1_5 = y1_5 - 8;
			y2_5 = y2_5 + 8;
			i_5++;
		} while (i_5 < 15);

		//6
		int x1_6 = 1300, y1_6 = 300;
		int x2_6 = 1350, y2_6 = 400;
		int i_6 = 0;
		do {
			MoveToEx(hdc, x1_6, y1_6, NULL);
			LineTo(hdc, x2_6, y2_6);
			x1_6 = x1_6 + 4;
			y1_6 = y1_6 + 4;
			y2_6 = y2_6 - 8;
			i_6++;
		} while (i_6 < 19);

		//7
		int x1_7 = 800, y1_7 = 600;
		int x2_7 = 800, y2_7 = 800;
		int i_7 = 0;
		do {
			MoveToEx(hdc, x1_7, y1_7, NULL);
			LineTo(hdc, x2_7, y2_7);
			x1_7 = x1_7 - 8;
			y1_7 = y1_7 + 8;
			x2_7 = x2_7 + 8;
			y2_7 = y2_7 - 8;
			i_7++;
		} while (i_7 < 15);

		//8
		int x1_8 = 1000, y1_8 = 600;
		int x2_8 = 1000, y2_8 = 800;
		int i_8 = 0;
		do {
			MoveToEx(hdc, x1_8, y1_8, NULL);
			LineTo(hdc, x2_8, y2_8);
			y1_8 = y1_8 + 14;
			x2_8 = x2_8 + 14;
			i_8++;
		} while (i_8 < 15);

		//9
		int x1_9 = 1300, y1_9 = 600;
		int x2_9 = 1300, y2_9 = 800;
		int i_9 = 0;
		do {
			MoveToEx(hdc, x1_9, y1_9, NULL);
			LineTo(hdc, x2_9, y2_9);
			y2_9 = y2_9 - 8;
			x1_9 = x1_9 - 8;
			y1_9 = y1_9 + 8;
			i_9++;
		} while (i_9 < 15);

		//10
		int x1_10 = 1500, y1_10 = 100;
		int x2_10 = 1700, y2_10 = 100;
		int i_10 = 0;
		do {
			MoveToEx(hdc, x1_10, y1_10, NULL);
			LineTo(hdc, x2_10, y2_10);
			y1_10 = y1_10 - 4;
			y2_10 = y2_10 + 4;
			i_10++;
		} while (i_10 < 15);

		// Infiniti
		SelectObject(hdc, hPen_line);
		Ellipse(hdc, 1500, 500, 1700, 600);
		SelectObject(hdc, hBrush_white);
		SelectObject(hdc, hPen_white);
		Ellipse(hdc, 1525, 515, 1675, 575);
		POINT infi1[4];
		infi1[0].x = 1600;
		infi1[0].y = 525;
		infi1[1].x = 1655;
		infi1[1].y = 585;
		infi1[2].x = 1545;
		infi1[2].y = 585;
		SelectObject(hdc, hPen_line);
		SelectObject(hdc, hBrush_black_car);
		Polygon(hdc, infi1, 3);
		POINT infi[4];
		infi[0].x = 1600;
		infi[0].y = 535;
		infi[1].x = 1635;
		infi[1].y = 615;
		infi[2].x = 1565;
		infi[2].y = 615;
		SelectObject(hdc, hPen_white);
		SelectObject(hdc, hBrush_white);
		Polygon(hdc, infi, 3);

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

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
