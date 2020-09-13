#include <windows.h>

//设置颜色
void setcolor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}

//设置光标位置
void setpos(int x, int y)
{
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

//隐藏光标
void hide_console(void) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 1, 0 };
	SetConsoleCursorInfo(console, &cci);
}

//显示光标
void show_console(void) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 1, 1 };
	SetConsoleCursorInfo(console, &cci);
}

//设置控制台大小
void set_console_size(int length, int kidth) {
	char result[] = "mode con: cols=    lines=   ";
	if (length < 10) {
		result[15] = length + 48;
	}
	else if (length < 100) {
		result[15] = (length) / 10 + 48;
		result[16] = (length) % 10 + 48;
	}
	else if (length < 1000) {
		result[15] = (length) / 100 + 48;
		result[16] = ((length) % 100) / 10 + 48;
		result[17] = (length) % 10 + 48;
	}
	if (kidth < 10) {
		result[25] = kidth + 48;
	}
	else if (kidth < 100) {
		result[25] = (kidth) / 10 + 48;
		result[26] = (kidth) % 10 + 48;
	}
	else if (kidth < 1000) {
		result[25] = (kidth) / 100 + 48;
		result[26] = ((kidth) % 100) / 10 + 48;
		result[27] = (kidth) % 10 + 48;
	}
	system(result);
}