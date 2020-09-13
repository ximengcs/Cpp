#include "View.h"


using namespace std;
void View::chart() {
	int x = 630;
	int y = 370;
	int x_0 = x+30;
	int y_0 = y-15;
	int space = 30;
	int shell = wait_time.size()/400+1;
	int last = 0;
	int count = 0;
	static int last_shell = 1;
	setlinecolor(CHART_REAL_LINE); //折线颜色
	
	for (std::vector<double>::iterator it = wait_time.begin(); it < wait_time.end();) {
		line(x_0+count, y_0-last*3, x_0+count+1, (y_0-*it * 3));
		last = *it;
		count++;
		for (int i = 0; i < shell; i++)
			if (it < wait_time.end())
				it++;
	}

	static int last_x = x_0;
	static int last_y = y_0;
	wchar_t buf[10] = { 0 };
	swprintf(buf, 100, L"%.2f", wait_time.back());
	settextcolor(CHART_NUMBER); //折线数字字体颜色
	//清理上一次的位置
	for (int i = last_x; i < last_x+50; i++) {
		for (int j = last_y; j < last_y+25; j++) {
			putpixel(i, j, *(bg + j * HEIGHT + i));
		}
	}

	last_x = x_0 + count;
	last_y = y_0 - last * 3;
	outtextxy(last_x, last_y, buf);

	if (shell > last_shell) {
		last_shell = shell;
		//清空
		for (int i = 600; i < WIDTH; i++) {
			for (int j = 0; j < 400; j++) {
				putpixel(i, j, *(bg + j * HEIGHT + i));
			}
		}
	}
}

void View::chart(std::vector<double> wait_time_n) {
	int x = 30;
	int y = 370;
	int x_0 = x + 30;
	int y_0 = y - 15;
	int space = 30;
	int shell = wait_time_n.size() / 400 + 1;
	int last = 0;
	int count = 0;
	static int last_shell = 1;
	setlinecolor(CHART_REAL_LINE); //折线颜色

	int start_count = 0;
	bool start_show = false;
	for (std::vector<double>::iterator it = wait_time_n.begin(); it < wait_time_n.end();) {
		if (start_count++ == 0) {
			last = *it;
			it++;
			continue;
		}
		if (last <= *it && start_show == false) {
			last = *it;
			it++;
			continue;
		}
		else
			start_show = true;

		if (last == *it) {
			it++;
			continue;
		}

		line(x_0 + count, y_0 - last * 3, x_0 + count + 1, (y_0 - *it * 3));
		last = *it;
		count++;
		for (int i = 0; i < shell; i++)
			if (it < wait_time_n.end())
				it++;
	}

	static int last_x = x_0;
	static int last_y = y_0;
	wchar_t buf[10] = { 0 };
	swprintf(buf, 100, L"%.2f", wait_time_n.back());
	settextcolor(CHART_NUMBER); //折线数字字体颜色

	last_x = x_0 + count;
	last_y = y_0 - last * 3;
	outtextxy(last_x, last_y, buf);
}

void View::chart(double cheat_last_number, int cheat_learn_times) {
	
}

void View::show_info(int x, int y, double car_full, int car_num, double a_time, int rate, int red_max, int green_max) {
	BeginBatchDraw();
	
	settextstyle(20, 10, _T("Console"));
	setbkcolor(FONT_BG);
	settextcolor(FONT_C);

	wchar_t buf[10] = { 0 };
	swprintf(buf, 100, L"%.2f", car_full);
	outtextxy(239+y, 28+x, buf);
	//

	swprintf(buf, 100, L"%d", car_num);
	outtextxy(200 + y, 90 + x, buf);

	swprintf(buf, 100, L"%.2f", a_time > 0? a_time : 0);
	outtextxy(305 + y, 152 + x, buf);

	swprintf(buf, 100, L"%d", rate);
	outtextxy(450 + y, 90 + x, buf);

	swprintf(buf, 100, L"%d", red_max);
	settextcolor(RED);
	outtextxy(390 + y, 28 + x, buf);
	swprintf(buf, 100, L"%d", green_max);
	settextcolor(GREEN);
	outtextxy(390 + 30 + y, 28 + x, buf);
	swprintf(buf, 100, L"%d", 3);
	settextcolor(YELLOW);
	outtextxy(390 + 60 + y, 28 + x, buf);

	chart();

	show_a_e();

	EndBatchDraw();
}
void View::show_light() {
	setbkcolor(LIGHT);

	State& state = en.get_state();
	double red = state.get_red_time();
	double yellow = state.get_yellow_time();
	double green = state.get_green_time();
	//相对于左来说
	settextstyle(30, 20, _T("黑体"));
	wchar_t buf[10];
	swprintf(buf, 100, L"%d", int(red));
	settextcolor(LIGHT_RED);
	outtextxy(531, 32, buf);
	outtextxy(531, 32+200, buf);
	settextcolor(LIGHT_GREEN);
	outtextxy(531, 32+400+106, buf);
	outtextxy(531, 32 + 600+106, buf);

	swprintf(buf, 100, L"%d", int(green));
	settextcolor(LIGHT_GREEN);
	outtextxy(531, 32 + 106, buf);
	outtextxy(531, 32 + 200 + 106, buf);
	settextcolor(LIGHT_RED);
	outtextxy(531, 32 + 400, buf);
	outtextxy(531, 32 + 600, buf);

	//黄灯
	swprintf(buf, 100, L"%d", int(yellow));
	settextcolor(LIGHT_YELLOW);
	outtextxy(531, 32 + 59, buf);
	outtextxy(531, 32 + 200 + 59, buf);
	settextcolor(LIGHT_YELLOW);
	outtextxy(531, 32 + 400 + 59, buf);
	outtextxy(531, 32 + 600 + 59, buf);
}

void View::show_a_e() {
	
	setfillcolor(AGENT_TITLE_BG);
	setlinecolor(AGENT_ARTICLE_LINE);
	fillrectangle(672 + 85, 672 + 35, 672 + 80 + 85, 672 + 35 + 30);//第5格
	fillrectangle(672 + 85, 672 + 35 + 35, 672 + 80 + 85, 672 + 35 + 35 + 30);//第6格

	fillrectangle(672 + 290 + 85, 672 + 35, 672 + 80 + 85 + 290, 672 + 35 + 30);//第5格
	fillrectangle(672 + 290 + 85, 672 + 35 + 35, 672 + 80 + 85 + 290, 672 + 35 + 35 + 30);//第6格


	settextstyle(20, 12, _T("Console"));
	setbkcolor(AGENT_BG);
	//Agent
	settextcolor(FONT_C);
	wchar_t buf[10] = { 0 };
	swprintf(buf, 100, L"%.1f", a);
	outtextxy(600 + 10 + 30+130, 400 + 12 + 50 + 18, buf);
	swprintf(buf, 100, L"%.1f", y);
	outtextxy(600 + 10 + 30 + 130, 400 + 12 + 50 +40+ 18, buf);
	swprintf(buf, 100, L"%d", agent.get_learn_times());
	outtextxy(600 + 10 + 30 + 130+5, 400 + 12 + 50 + 40 + 18+40, buf);
	
	//Q
	int* Q = agent.get_Q().get_Q();
	swprintf(buf, 100, L"%+d", Q != NULL ? *Q : 0);
	outtextxy(672 + 85+30, 672+5+35, buf);
	swprintf(buf, 100, L"%+d", Q != NULL ? *(Q+2) : 0);
	outtextxy(672 + 85 + 30, 672+35+40, buf);

	//Reward
	Reward& r = en.get_reward();
	swprintf(buf, 100, L"%+d", r.get_c_l_r());
	outtextxy(672 + 85 + 30+ 290, 672 + 5 + 35, buf);
	swprintf(buf, 100, L"%+d", r.get_c_t_p());
	outtextxy(672 + 85 + 30 + 290, 672 + 35 + 40, buf);
}

void View::init_an() {
	// 初始化图形模式
	initgraph(WIDTH, HEIGHT);

	BeginBatchDraw();

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			putpixel(j, i, BG);
		}
	}
	setbkcolor(FONT_BG);
	settextcolor(FONT_DIRECT_BIG);
	create_kj(0, 0);
	settextstyle(40, 30, _T("华为中宋"));
	outtextxy(17, 27, _T("  "));
	outtextxy(17, 77, _T("东"));
	outtextxy(17, 127, _T("  "));
	create_kj(200, 0);
	settextstyle(40, 30, _T("华为中宋"));
	outtextxy(17, 27+200, _T("  "));
	outtextxy(17, 77+200, _T("西"));
	outtextxy(17, 127+200, _T("  "));
	create_kj(400, 0);
	settextstyle(40, 30, _T("华为中宋"));
	outtextxy(17, 27+400, _T("  "));
	outtextxy(17, 77 + 400, _T("南"));
	outtextxy(17, 127 + 400, _T("  "));
	create_kj(600, 0);
	settextstyle(40, 30, _T("华为中宋"));
	outtextxy(17, 27+600, _T("  "));
	outtextxy(17, 77+600, _T("北"));
	outtextxy(17, 127+600, _T("  "));

	//折线图背景
	for (int i = 12; i < 400; i++) {
		for (int j = 600+12; j < 600+588; j++) {
			putpixel(j, i, LINE_CHART_BG);
		}
	}
	setfillcolor(CHART_LINE);
	bar(600 + 50 + 10, 12 + 10, 600 + 50 + 10 + 3, 350 + 10);
	bar(600 + 50 + 10, 350 + 7, 600 + 50 + 10 + 5 + 500, 350 + 10);

	int x = 630;
	int y = 370;
	int space = 30;
	settextstyle(25, 15, _T("Consoles"));
	settextcolor(CHART_RATE_VALUE_COLOR);
	outtextxy(x, y-10, _T("0"));
	outtextxy(x, y-10-15-space, _T("10"));
	outtextxy(x, y-10-15-space*2, _T("20"));
	outtextxy(x, y-10-15-space*3, _T("30"));
	outtextxy(x, y-10-15-space*4, _T("40"));
	outtextxy(x, y-10-15-space*5, _T("50"));
	outtextxy(x, y-10-15-space*6, _T("60"));
	outtextxy(x, y-10-15-space*7, _T("70"));
	outtextxy(x, y-10-15-space*8, _T("80"));
	outtextxy(x, y-10-15-space*9, _T("90"));
	outtextxy(x-15, y-10-15-space*10, _T("100"));
	settextcolor(CHART_CAR_AV);
	outtextxy(x, y-10-15-space*11, _T("汽车平均行驶时间(S)"));
	POINT points[3] = { {1160,350}, {1170,358}, {1160,366} };
	solidpolygon(points, 3);


	int x_0 = x + 30;
	int y_0 = y - 15;
	
	bar(x_0, y_0 - space * 1, x_0 + 12, y_0 - (space) * 1 - 3);
	bar(x_0, y_0 - space * 2, x_0 + 12, y_0 - (space) * 2 - 3);
	bar(x_0, y_0 - space * 3, x_0 + 12, y_0 - (space) * 3 - 3);
	bar(x_0, y_0 - space * 4, x_0 + 12, y_0 - (space) * 4 - 3);
	bar(x_0, y_0 - space * 5, x_0 + 12, y_0 - (space) * 5 - 3);
	bar(x_0, y_0 - space * 6, x_0 + 12, y_0 - (space) * 6 - 3);
	bar(x_0, y_0 - space * 7, x_0 + 12, y_0 - (space) * 7 - 3);
	bar(x_0, y_0 - space * 8, x_0 + 12, y_0 - (space) * 8 - 3);
	bar(x_0, y_0 - space * 9, x_0 + 12, y_0 - (space) * 9 - 3);
	bar(x_0, y_0 - space * 10, x_0 + 12, y_0 - (space) * 10 - 3);


	//agent
	setfillcolor(AGENT_BG);
	setlinecolor(AGENT_BG_LINE);
	fillrectangle(600 + 12, 400 + 12, 600 + 12 + 280, 400 + 12 + 180);
	fillrectangle(600 + 12 + 290, 400 + 12, 600 + 12 + 290 + 280, 400 + 12 + 180);
	fillrectangle(600 + 12, 400 + 12 + 180 + 10, 600 + 12 + 280, 400 + 12 + 180 + 180 + 10);
	fillrectangle(600 + 12 + 290, 400 + 12 + 180 + 10, 600 + 12 + 290 + 280, 400 + 12 + 180 + 180 + 10);


	setfillcolor(AGENT_TITLE_BG);
	setlinecolor(AGENT_TITLE_BG_LINE);
	fillrectangle(600 + 12+90, 400 + 12+20, 600 + 12 + 280-90, 400 + 12 + 60);
	fillrectangle(600 + 12 + 240 + 90, 400 + 12 + 20, 600 + 12 + 290 + 50 + 280 - 90, 400 + 12 + 60);
	fillrectangle(600 + 12 + 90, 400 + 12 + 180 + 10 + 20, 600 + 12 + 280 - 90, 400 + 12 + 180 + 10 + 60);
	fillrectangle(600 + 12 + 290 + 90, 400 + 12 + 180 + 10 + 20, 600 + 12 + 280 + 290 - 90, 400 + 12 + 180 + 10 + 60);

	settextcolor(AGENT_FONT);
	setbkcolor(AGENT_FONT_BG);
	outtextxy(600 + 12+90+12, 400 + 12 + 20+7,  _T("Agent"));
	outtextxy(600 + 12 + 245 + 90 + 12, 400 + 12 + 20 + 7, _T("Environment"));
	outtextxy(600 + 12 + 90 + 12, 400 + 12 + 180 + 10 + 20 + 7, _T(" Q表 "));
	outtextxy(600 + 12 + 90 + 12 - 5 + 290, 400 + 12 + 180 + 10 + 20 + 7, _T("Reward"));

	setlinecolor(AGENT_ARTICLE_LINE);
	line(600 + 12 +20, 400 + 12 + 60+30, 600 + 12 + 280-20, 400 + 12 + 60 + 30);
	line(600 + 12 +20, 400 + 12 + 60+40+30, 600 + 12 + 280-20, 400 + 12 + 60 + 40+30);
	line(600 + 12 +20, 400 + 12 + 60+40+40+30, 600 + 12 + 280-20, 400 + 12 + 60 + 40+40+30);

	fillrectangle(672, 672, 672+80, 672+30);//第一格
	fillrectangle(672, 672+35, 672+80, 672+35+30);//第2格
	fillrectangle(672, 672+35+35, 672+80, 672 + 35 + 35+30);//第3格
	fillrectangle(672+85, 672, 672+80 + 85, 672+30);//第4格
	fillrectangle(672 + 85, 672 + 35, 672+80 + 85, 672 + 35 + 30);//第5格
	fillrectangle(672 + 85, 672 + 35 + 35, 672+80 + 85, 672 + 35 + 35 + 30);//第6格

	settextcolor(AGENT_INNER_TITLE_FONT);
	settextstyle(20, 10, _T("Consoles"));
	setbkcolor(AGENT_FONT_BG);
	outtextxy(672+10, 672+3, _T("Action"));
	outtextxy(672+85+15, 672+3, _T("State"));
	outtextxy(672+20, 672+3+35, _T("红灯"));
	outtextxy(672+20, 672+3+35+35, _T("绿灯"));

	//reard
	
	fillrectangle(672 + 290, 672, 672 + 80 + 290, 672 + 30);//第一格
	fillrectangle(672 + 290, 672 + 35, 672 + 80 + 290, 672 + 35 + 30);//第2格
	fillrectangle(672 + 290, 672 + 35 + 35, 672 + 80 + 290, 672 + 35 + 35 + 30);//第3格
	fillrectangle(672 + 290 + 85, 672, 672 + 80 + 85 + 290, 672 + 30);//第4格
	fillrectangle(672 + 290 + 85, 672 + 35, 672 + 80 + 85 + 290, 672 + 35 + 30);//第5格
	fillrectangle(672 + 290 + 85, 672 + 35 + 35, 672 + 80 + 85 + 290, 672 + 35 + 35 + 30);//第6格
	
	outtextxy(672 + 10 + 290, 672 + 3, _T("Action"));
	outtextxy(672 + 85 + 15 + 290, 672 + 3, _T("Time"));
	outtextxy(672 + 20 + 290, 672 + 3 + 35, _T("红灯"));
	outtextxy(672 + 20 + 290, 672 + 3 + 35 + 35, _T("绿灯"));

	settextcolor(AGENT_FONT);
	setbkcolor(AGENT_BG);
	outtextxy(600 + 12 + 30, 400 + 12 + 50 + 18, _T("学习率α:"));
	outtextxy(600 + 12 + 30, 400 + 12 + 50 + 18 + 40, _T("折扣率γ:"));
	outtextxy(600 + 12 + 30, 400 + 12 + 50 + 18 + 80, _T("试错学习次数:"));

	//保存背景
	bg = new COLORREF[WIDTH * HEIGHT];
	if (bg == NULL) {
		exit(0);
	}
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			*(bg + j * HEIGHT + i) = getpixel(i, j);
		}
	}

	data_analysis();
	show_a_e();

	EndBatchDraw();
}

void View::create_kj(int x, int y) {
	for (int i = 5+x; i < 200+x; i++) {
		for (int j = 5+y; j < 600+y; j++) {
			putpixel(j, i, PART_BG);
		}
	}

	//公路
	for (int i = 12+x; i < 188+x; i++) {
		for (int j = 12+y; j < 88+y; j++) {
			putpixel(j, i, FONT_BG);
		}
	}
	//交通灯
	for (int i = 12 + x; i < 188 + x; i++) {
		for (int j = 12+500 + y; j < 88+500 + y; j++) {
			putpixel(j, i, LIGHT_BG);
		}
	}

	//交通灯
	setfillcolor(LIGHT);
	setlinecolor(LIGHT_LINE);
	fillcircle(549,45+x,25);
	fillcircle(549,100+x,25);
	fillcircle(549,155+x,25);

	//
	for (int i = 12 + x; i < 188/3 + x; i++) {
		for (int j = 12 + 100 + y; j < 188 + 100 + y; j++) {
			putpixel(j, i, FONT_BG);
		}
	}
	settextstyle(20, 10, _T("黑体"));
	outtextxy(12 + 5 + 100 + y, 12 + 15+ x, _T("公路饱和度:"));
	for (int i = 12 + x + 188/3; i < 188 / 3*2 + x; i++) {
		for (int j = 12 + 100 + y; j < 188 + 100 + y; j++) {
			putpixel(j, i, FONT_BG);
		}
	}
	outtextxy(12 + 5 + 100 + y, 12 + 15 + x + 188 / 3, _T("车辆数:"));
	for (int i = 12 + x+188 / 3*2; i < 188 + x; i++) {
		for (int j = 12 + 100 + y; j < 188 + 200 + y; j++) {
			putpixel(j, i, FONT_BG);
		}
	}
	outtextxy(12 + 5 + 100 + y, 12 + 15 + x + 188 / 3 * 2, _T("车辆平均行驶时间:"));
	//
	for (int i = 12 + x; i < 188 / 3 + x; i++) {
		for (int j = 12 + 100+188 + y; j < 188 + 200 + 100 + y; j++) {
			putpixel(j, i, FONT_BG);
		}
	}
	outtextxy(12 + 100 + 188 + y+5, 12 + x+15, _T("最大值:"));
	for (int i = 12 + x + 188 / 3; i < 188 / 3 * 2 + x; i++) {
		for (int j = 12 + 100 + 188 + y; j < 188 + 200 + 100 + y; j++) {
			putpixel(j, i, FONT_BG);
		}
	}
	outtextxy(12 + 100 + 188 + y + 5, 12 + x + 15 + 188 / 3, _T("生成车辆几率:"));
	for (int i = 12 + x + 188 / 3 * 2; i < 188 + x; i++) {
		for (int j = 12 + 100 + 188 + y; j < 188 + 200 + 100 + y; j++) {
			putpixel(j, i, FONT_BG);
		}
	}
}

void View::calculate_time() {
	double left_wait_time = left_num!=0?double(left) / left_num:0;
	double right_wait_time = right_num!=0?double(right) / right_num:0;
	double top_wait_time = top_num!=0?double(top) / top_num:0;
	double bottom_wait_time = bottom_num!=0?double(bottom) / bottom_num:0;
	wait_time.push_back((left_wait_time + right_wait_time +
		top_wait_time + bottom_wait_time) / 4);
}

void View::data_analysis() {
	std::vector<Car>& wait = en.get_wait_dispose();
	for (std::vector<Car>::iterator it = wait.begin(); it < wait.end(); it++) {
		if (it->get_cur() == Car::Direct::left) {
			left += system_time - it->get_time();
			left_wait += it->get_start_time() - it->get_time();
			left_num++;
		}
		else if (it->get_cur() == Car::Direct::right) {
			right += system_time - it->get_time();
			right_wait += it->get_start_time() - it->get_time();
			right_num++;
		}
		else if (it->get_cur() == Car::Direct::top) {
			top += system_time - it->get_time();
			top_wait += it->get_start_time() - it->get_time();
			top_num++;
		}
		else if (it->get_cur() == Car::Direct::bottom) {
			bottom += system_time - it->get_time();
			bottom_wait += it->get_start_time() - it->get_time();
			bottom_num++;
		}
	}
	wait.clear();
	int rate = en.get_maneget_car().get_rate();
	State& state = en.get_state();
	calculate_time();
	///show_test();
	
	//show_final();

	/*show_info(0, 0, left_car_full, left_num, double(left) / left_num, rate, state.get_red_max_time(), state.get_green_max_time());
	show_info(200, 0, right_car_full, right_num, double(right) / right_num, rate, state.get_red_max_time(), state.get_green_max_time());
	show_info(400, 0, top_car_full, top_num, double(top) / top_num, rate, state.get_green_max_time(), state.get_red_max_time());
	show_info(600, 0, bottom_car_full, bottom_num, double(bottom) / bottom_num, rate, state.get_green_max_time(), state.get_red_max_time());

	show_light();*/

}

void View::scan_chart(int n) {
	// 初始化图形模式
	initgraph(612, 424);
	BeginBatchDraw();

	for (int i = 12; i < 400; i++) {
		for (int j = 12; j < 588; j++) {
			putpixel(j, i, LINE_CHART_BG);
		}
	}
	setfillcolor(CHART_LINE);
	bar(50 + 10, 12 + 10, 50 + 10 + 3, 350 + 10);
	bar(50 + 10, 350 + 7, 50 + 10 + 5 + 500, 350 + 10);

	int x = 30;
	int y = 370;
	int space = 30;
	settextstyle(25, 15, _T("Consoles"));
	settextcolor(CHART_RATE_VALUE_COLOR);
	outtextxy(x, y - 10, _T("0"));
	outtextxy(x, y - 10 - 15 - space, _T("10"));
	outtextxy(x, y - 10 - 15 - space * 2, _T("20"));
	outtextxy(x, y - 10 - 15 - space * 3, _T("30"));
	outtextxy(x, y - 10 - 15 - space * 4, _T("40"));
	outtextxy(x, y - 10 - 15 - space * 5, _T("50"));
	outtextxy(x, y - 10 - 15 - space * 6, _T("60"));
	outtextxy(x, y - 10 - 15 - space * 7, _T("70"));
	outtextxy(x, y - 10 - 15 - space * 8, _T("80"));
	outtextxy(x, y - 10 - 15 - space * 9, _T("90"));
	outtextxy(x - 15, y - 10 - 15 - space * 10, _T("100"));
	settextcolor(CHART_CAR_AV);
	outtextxy(x, y - 10 - 15 - space * 11, _T("汽车平均行驶时间(S)"));
	POINT points[3] = { {1160-600,350}, {1170 - 600,358}, {1160 - 600,366} };
	solidpolygon(points, 3);

	chart(past_wait_time.at(current_code-1)); //right
	//chart(past_wait_time.at(current_code - 1).back(), en.get_para().times); //cheat

	EndBatchDraw();
	_getch();
	closegraph();
}

void View::show_menu() {
	cout << " 编号 |  车流量(每小时)  | 学习率 | 折扣率 | 学习次数    |    红 黄 绿 | 汽车平均行驶时间 | 汽车平均等待时间" << "   ";
}

void View::reflesh_menu() {
	setpos(111, 0);
	if(menu_choice == 1)
		setcolor(7, 1);
	else
		setcolor(7, 8);
	cout << "  查看  ";
	setpos(111, 1);
	if (menu_choice == 2)
		setcolor(7, 1);
	else
		setcolor(7, 8);
	cout << "  添加  ";
	setpos(110, 2);
	setcolor(7, 0);
	cout << "          ";
}

void View::reflesh_menu_2() {
	setpos(111, 0);
	if (menu_choice_2 == 1)
		setcolor(7, 1);
	else
		setcolor(7, 8);
	cout << "  预设  ";
	setpos(111, 1);
	if (menu_choice_2 == 2)
		setcolor(7, 1);
	else
		setcolor(7, 8);
	cout << "  手动  ";
	setpos(111, 2);
	if (menu_choice_2 == 3)
		setcolor(7, 1);
	else
		setcolor(7, 8);
	cout << "  返回  ";
	setcolor(7, 0);
}

void View::show_final(bool n) {
	setpos(0, code*2+1);
	stringstream result;
	std::vector<std::array<char, 120>> v;
	result << "  ";
	result.width(6);
	result.fill(' ');
	result.setf(ios::left);
	result << ' '; //code
	code++;

	Para tmp = en.orig_para;
	result.width(5);
	result << ' ';
	result.width(5);
	result << ' ';
	result.width(5);
	result << ' ';
	result.width(5);
	result << " ";

	result.width(8);
	result << "  ";

	result.width(8);
	result << "  "; 

	result.width(9);
	result << "      "; 

	result << "  学习后：";

	result << int(en.get_state().get_red_max_time()) << "  " << 3 << " " << int(en.get_state().get_green_max_time()) << "       ";

	double l = left_num == 0 ? 0 : double(left) / left_num;
	double r = right_num == 0 ? 0 : double(right) / right_num;
	double t = top_num == 0 ? 0 : double(top) / top_num;
	double b = bottom_num == 0 ? 0 : double(bottom) / bottom_num;
	result << int((l + r + t + b) / 4) << "            ";

	l = left_num == 0 ? 0 : double(left_wait) / left_num;
	r = right_num == 0 ? 0 : double(right_wait) / right_num;
	t = top_num == 0 ? 0 : double(top_wait) / top_num;
	b = bottom_num == 0 ? 0 : double(bottom_wait) / bottom_num;

	result << int((l + r + t + b)) / 4 << endl;

	for (array<char, 120> a; result.getline(&a[0], 120, '\n'); ) {
		v.push_back(a);
	}

	for (auto& a : v) {
		std::cout << &a[0] << '\n';
		past_data.push_back(&a[0]);
	}
}

void View::show_final() {
	setpos(0, code*2);
	stringstream result;
	std::vector<std::array<char, 120>> v;
	result << "  ";
	result.width(6);
	result.fill(' ');
	result.setf(ios::left);
	result << code;

	Para tmp = en.orig_para;
	result.width(5);
	result << tmp.car_stream_left;
	result.width(5);
	result << tmp.car_stream_right;
	result.width(5);
	result << tmp.car_stream_top;
	result.width(5);
	result << tmp.car_stream_bottom << " ";

	result.width(8);
	result << a << "  ";

	result.width(8);
	result << y << "  ";

	result.width(4);
	result << en.orig_para.times*10;////
	result << "  学习前：";
	result << int(en.get_state().get_red_max_time()) << "  " << 3 << " " << int(en.get_state().get_green_max_time()) << "       ";

	double l = left_num == 0 ? 0 : double(left) / left_num;
	double r = right_num == 0 ? 0 : double(right) / right_num;
	double t = top_num == 0 ? 0 : double(top) / top_num;
	double b = bottom_num == 0 ? 0 : double(bottom) / bottom_num;
	result << int((l + r + t + b) / 4) << "            ";

	l = left_num == 0 ? 0 : double(left_wait) / left_num;
	r = right_num == 0 ? 0 : double(right_wait) / right_num;
	t = top_num == 0 ? 0 : double(top_wait) / top_num;
	b = bottom_num == 0 ? 0 : double(bottom_wait) / bottom_num;

	result << int((l + r + t + b) / 4) << endl;

	for (array<char, 120> a; result.getline(&a[0], 120, '\n'); ) {
		v.push_back(a);
	}

	for (auto& a : v) {
		std::cout << &a[0] << '\n';
		past_data.push_back(&a[0]);
	}
}

void View::refresh_scanf_code() {
	if (current_code == 0)
		return;
	setpos(0, current_code);
	setcolor(7, 1);
	cout << "  " << current_code << "  ";
	setcolor(7, 0);
}

void View::clear_scanf_code() {
	setpos(0, current_code);
	setcolor(7, 0);
	cout << "  " << current_code << "  ";
}

void View::reset() {
	if(wait_time.size() != 0)
		past_wait_time.push_back(wait_time);
	wait_time.clear();
	left = 0;
	right = 0;
	top = 0;
	bottom = 0; //过马路行驶时间
	left_wait = 0;
	right_wait = 0;
	top_wait = 0;
	bottom_wait = 0;
	left_num = 0;
	right_num = 0;
	top_num = 0;
	bottom_num = 0;
}

void View::show()
{
	using namespace std;
	cout << endl;
	cout.width(20);
	cout << "left_car_full:";
	cout.width(5);
	cout << left_car_full << endl;
	cout.width(20);
	cout << "right_car_full:";
	cout.width(5);
	cout << right_car_full << endl;
	cout.width(20);
	cout << "top_car_full:";
	cout.width(5);
	cout << top_car_full << endl;
	cout.width(20);
	cout << "bottom_car_full:";
	cout.width(5);
	cout << bottom_car_full << endl;
	cout << endl;
	std::vector<Car>& wait = en.get_wait_dispose();
	for (std::vector<Car>::iterator it = wait.begin(); it < wait.end(); it++) {
		if (it->get_cur() == Car::Direct::left) {
			left += system_time - it->get_time();
			left_num++;
		}
		else if (it->get_cur() == Car::Direct::right) {
			right += system_time - it->get_time();
			right_num++;
		}
		else if (it->get_cur() == Car::Direct::top) {
			top += system_time - it->get_time();
			top_num++;
		}
		else if (it->get_cur() == Car::Direct::bottom) {
			bottom += system_time - it->get_time();
			bottom_num++;
		}
	}
	wait.clear();
	if (left_num > 0) {
		cout << "left车辆总行驶时间:" << left << endl;
		cout << "left总车辆:" << left_num << endl;
		cout << "left车辆平均行驶时间:" << left / left_num << endl;
	}
	if (right_num > 0) {
		cout << "right车辆总行驶时间:" << right << endl;
		cout << "right总车辆:" << right_num << endl;
		cout << "right车辆平均行驶时间:" << right / right_num << endl;
	}
	if (top_num > 0) {
		cout << "top车辆总行驶时间:" << top << endl;
		cout << "top总车辆:" << top_num << endl;
		cout << "top车辆平均行驶时间:" << top / top_num << endl;
	}
	if (bottom_num > 0) {
		cout << "bottom车辆总行驶时间:" << bottom << endl;
		cout << "bottom总车辆:" << bottom_num << endl;
		cout << "bottom车辆平均行驶时间:" << bottom / bottom_num << endl;
	}
	cout << "总的车辆平均行驶时间：" << 
		(((left_num>0) ? (left / left_num) : 0) + 
			((right_num>0) ? (right / right_num) : 0) + 
			((top_num>0) ? (top / top_num) : 0) + 
			((bottom_num>0) ? (bottom / bottom_num) : 0 ))/ 4 << endl;
}

void View::init() {
	// 初始化图形模式
	initgraph(WIDTH, HEIGHT);

	BeginBatchDraw();
	//画第一次图
	//草地
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j < 600; j++) {
			putpixel(left + i, top + j, GREEN);
		}
	}

	//画十字路口
	for (int i = 199; i < 400; i++) {
		for (int j = 0; j < 600; j++) {
			putpixel(top + j, left + i, LIGHTGRAY);
		}
	}
	for (int i = 199; i < 400; i++) {
		for (int j = 0; j < 600; j++) {
			putpixel(left + i, top + j, LIGHTGRAY);
		}
	}

	//斑马线
	for (int i = 204; i < 397; i%11 == 0 ? i += 7 : i++) {
		for (int j = 159; j < 180; j++) {
			putpixel(top + j, left + i, BLACK);
		}
	}
	for (int i = 204; i < 397; i % 11 == 0 ? i += 7 : i++) {
		for (int j = 419; j < 440; j++) {
			putpixel(top + j, left + i, BLACK);
		}
	}
	for (int i = 204; i < 397; i % 11 == 0 ? i += 7 : i++) {
		for (int j = 159; j < 180; j++) {
			putpixel( left + i, top + j, BLACK);
		}
	}
	for (int i = 204; i < 397; i % 11 == 0 ? i += 7 : i++) {
		for (int j = 419; j < 440; j++) {
			putpixel(left + i, top + j, BLACK);
		}
	}

	for (int i = 298; i < 302; i % 11 == 0 ? i += 7 : i++) {
		for (int j = 0; j < 160; j++) {
			putpixel(left + i, top + j, WHITE);
		}
	}
	for (int i = 298; i < 302; i % 11 == 0 ? i += 7 : i++) {
		for (int j = 0; j < 160; j++) {
			putpixel(top + j, left + i,  WHITE);
		}
	}
	for (int i = 298; i < 302; i % 11 == 0 ? i += 7 : i++) {
		for (int j = 439; j < 600; j++) {
			putpixel(left + i, top + j, WHITE);
		}
	}
	for (int i = 298; i < 302; i % 11 == 0 ? i += 7 : i++) {
		for (int j = 439; j < 600; j++) {
			putpixel(top + j, left + i,  WHITE);
		}
	}
	EndBatchDraw();
	//保存背景
	bg = new COLORREF[WIDTH* HEIGHT];
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			*(bg+i* WIDTH+ j) = getpixel(i, j);
		}
	}
}

void View::display() {
	std::vector<Car>& left_queue = en.get_state().get_car_left();
	std::vector<Car>& right_queue = en.get_state().get_car_right();
	std::vector<Car>& top_queue = en.get_state().get_car_top();
	std::vector<Car>& bottom_queue = en.get_state().get_car_bottom();

	std::vector<Car>& left_queue_2 = en.get_state().get_car_left_2();
	std::vector<Car>& right_queue_2 = en.get_state().get_car_right_2();
	std::vector<Car>& top_queue_2 = en.get_state().get_car_top_2();
	std::vector<Car>& bottom_queue_2 = en.get_state().get_car_bottom_2();

	int tmp = 0;
	for (std::vector<Car>::iterator it = left_queue.begin(); it < left_queue.end(); it++) {
		tmp = it->get_distance();
		tmp = (tmp >= 0 ? tmp : -tmp)-2;
		if (it->get_move()) {
			for (int l = 0; l < 40;) {
				for (int i = 0; i < 20; i++) { //擦除
					for (int j = 0; j < 30; j++) {
						putpixel((120 + tmp * 40) + j + l, 360 + i, *(bg + (360 + i) * WIDTH + (120 + tmp * 40) + j + l));
					}
				}
				
				l++;
				for (int i = 0; i < 20; i++) { //画车
					for (int j = 0; j < 30; j++) {
						putpixel((120 + tmp * 40) + j + l, 360 + i, BLUE);
					}
				}
			}
		}
		it->set_move(false);
	}
	// 关闭图形模式
	//closegraph();
}
