#include <iostream>
#include <Windows.h>

#ifdef _WIN32
void test_drawing()
{

    /* hide console window */
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    /* Calling GetDC with argument 0 retrieves the desktop's DC */
    HDC hDC_Desktop = GetDC(0);

    /* Draw a simple blue rectangle on the desktop */
    RECT rect = { 20, 20, 200, 200 };
    LOGBRUSH lb;
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(0, 255, 0);
    lb.lbHatch = 0;
    HGDIOBJ  pen = CreatePen(PS_COSMETIC, 5, RGB(0, 255, 0));
    HGDIOBJ  old;
    while (true)
    {
        for (int i = 100; i < 500; i++)
        {
            SetPixel(hDC_Desktop, i, i, RGB(0, 255, 0));
            old = SelectObject(hDC_Desktop, pen);
            MoveToEx(hDC_Desktop, 0, 0, NULL);
            LineTo(hDC_Desktop, 1000, 1000);
            // ReleaseDC(NULL, hDC_Desktop);
            SelectObject(hDC_Desktop, old);
            Sleep(1);
        }

        Sleep(1);
    }
    DeleteObject(pen); //you must delete GDI object!
    Sleep(5000);

}
#endif

void main()
{
    std::cout << "doing some shizz" << std::endl;
    #ifdef _WIN32
    test_drawing();
    #endif
}