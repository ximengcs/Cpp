#ifndef TOOL_H_
#define TOOL_H_

//设置颜色
void setcolor(unsigned short ForeColor, unsigned short BackGroundColor);

//设置光标位置
void setpos(int x, int y);

//隐藏光标
void hide_console(void);

//显示光标
void show_console(void);

//设置控制台大小
void set_console_size(int length, int kidth);
#endif