#ifndef UTF8_CONSOLE_H
#define UTF8_CONSOLE_H

#ifdef _WIN32
#include <windows.h>

// 初始化控制台为UTF-8编码
static void init_utf8_console(void) {
    // 设置控制台输入/输出为UTF-8编码
    SetConsoleCP(65001);         // 输入编码
    SetConsoleOutputCP(65001);   // 输出编码
    
    // 设置支持中文的字体（需要管理员权限）
    CONSOLE_FONT_INFOEX cfi = {0};
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, LF_FACESIZE, L"SimHei");  // 设置为黑体
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

#ifdef _MSC_VER
// MSVC 编译器
#pragma section(".CRT$XCU", long, read)
__declspec(allocate(".CRT$XCU")) static void (*utf8_init_ptr)(void) = init_utf8_console;
#else
// MinGW 编译器
static void __attribute__((constructor)) utf8_init(void) {
    init_utf8_console();
}
#endif

#else
// Linux/macOS平台的替代实现
#include <locale.h>

static void init_utf8_console(void) {
    setlocale(LC_ALL, "");  // 使用系统默认locale
}

#endif // _WIN32

#endif // UTF8_CONSOLE_H