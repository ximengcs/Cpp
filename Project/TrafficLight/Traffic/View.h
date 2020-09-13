
#ifndef VIEW_H_
#define VIEW_H_
#include "agent.h"
#include "Environment.h"
#include <graphics.h>
#include <conio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <array>
extern double left_car_full;
extern double right_car_full;
extern double top_car_full;
extern double bottom_car_full;

extern double left_people_full;
extern double right_people_full;
extern double top_people_full;
extern double bottom_people_full;

extern long long system_time;

extern double a;
extern double y;

extern bool car_finish;
class View {
private:
	COLORREF BG = RGB(45, 45, 48); //大背景
	COLORREF FONT_DIRECT_BIG = RGB(185, 200, 200);//公路大字字体
	COLORREF PART_BG = RGB(62, 62, 62);//左侧(最大)小框背景
	COLORREF FONT_BG = RGB(30, 30, 30);//公路大字字体背景
	COLORREF FONT_C = RGB(190, 183, 255);//字体颜色

	COLORREF LIGHT_BG = RGB(45, 45, 45);//交通灯大框背景
	COLORREF LIGHT = RGB(0, 0, 0);//交通灯背景
	COLORREF LIGHT_LINE = RGB(67, 67, 70);//交通灯边框
	COLORREF LIGHT_RED = RED;//红灯
	COLORREF LIGHT_GREEN = GREEN;//绿灯
	COLORREF LIGHT_YELLOW = YELLOW;//黄灯

	COLORREF LINE_CHART_BG = RGB(30, 30, 30);//折线图背景
	COLORREF CHART_REAL_LINE = RGB(122, 192, 255);//折线颜色
	COLORREF CHART_NUMBER = RGB(254, 212, 0);//折线颜色
	COLORREF CHART_LINE = RGB(70, 201, 176);//折线图横纵坐标颜色
	COLORREF CHART_RATE_VALUE_COLOR = RGB(214, 157, 133);//折线图数标颜色
	COLORREF CHART_CAR_AV = RGB(190, 179, 230);//折线图汽车平均行驶时间颜色

	COLORREF AGENT_BG = RGB(51, 51, 55);//右侧小框（最大）背景
	COLORREF AGENT_BG_LINE = RGB(67, 67, 70);//右侧小框（最大）边框颜色 
	COLORREF AGENT_TITLE_BG = RGB(45, 45, 48);//右侧框内标题背景 
	COLORREF AGENT_TITLE_BG_LINE = RGB(67, 67, 70);//右侧框内标题边框
	COLORREF AGENT_FONT = RGB(185, 200, 200);//右侧框内标题字体
	COLORREF AGENT_FONT_BG = RGB(45, 45, 48);//右侧框内标题字体背景

	COLORREF AGENT_ARTICLE_LINE = RGB(156, 220, 254);//右侧框内正文线条颜色
	COLORREF AGENT_INNER_TITLE_FONT = RGB(185, 200, 200);//右侧框内标题字体颜色
	COLORREF AGENT_INNER_FONT = RGB(156, 220, 254);//右侧框内字体颜色



	double left = 0, right = 0, top = 0, bottom = 0; //过马路行驶时间
	double left_wait = 0, right_wait = 0, top_wait = 0, bottom_wait = 0;
	int left_num = 0, right_num = 0, top_num = 0, bottom_num = 0;

	int WIDTH = 600+600+10;
	int HEIGHT = 800;
	Agent& agent;
	Environment& en;
	COLORREF* bg;

	std::vector<double> wait_time; //当前
	std::vector<std::vector<double>> past_wait_time;	//过去
	std::vector<std::string> past_data;
public:
	int code = 1; // 数据编号
	int current_code = 1;  //查看的数据编号
	int menu_choice = 1;
	int menu_choice_2 = 1;

	View(Agent& a, Environment& e) :agent(a), en(e) {};
	~View() { delete bg; }
	void show();
	void display();
	void data_analysis();
	void create_kj(int x, int y);
	void show_info(int x, int y, double car_full, int car_num, double a_time, int rate, int red_max, int green_max);
	void show_light();
	void chart();
	void chart(std::vector<double> wait_time_n);
	void chart(double cheat_last_number, int cheat_learn_times);
	void calculate_time();
	void show_a_e();
	void init();
	void init_an();
	void show_final();
	void show_final(bool n);

	void show_menu();

	void reset();

	void reflesh_menu();

	void reflesh_menu_2();

	void scan_chart(int n);

	void refresh_scanf_code();

	void clear_scanf_code();

	double get_l_a_time() { return left; }
	double get_r_a_time() { return right; }
	double get_t_a_time() { return top; }
	double get_b_a_time() { return bottom; }

	double get_a_time() {
		return (double(left) / left_num + double(right) / right_num + double(top) / top_num
			+ double(bottom) / bottom_num) / 4;
	}

	double get_l_w_time() {
		return left_wait;
	}
	double get_r_w_time() { return right_wait; }
	double get_t_w_time() { return top_wait; }
	double get_b_w_time() { return bottom_wait; }

	double get_w_time() {
		return (double(left_wait) / left_num + double(right_wait) / right_num + double(top_wait) / top_num
			+ double(bottom_wait) / bottom_num) / 4;
	}
};

#endif