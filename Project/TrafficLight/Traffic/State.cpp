#include "State.h"
#include <iostream>

void State::init() {  //一边为红灯时另一边必为绿灯
	//交通灯
	red_max = RED_DEFAULT;
	green_max = GREEN_DEFAULT;
	yellow_max = YELLOW_DEFAULT;

	red = red_max;
	green = 0;
	yellow = 0;

	left_queue.clear();
	right_queue.clear();
	top_queue.clear();
	bottom_queue.clear();

	left_queue_2.clear();
	right_queue_2.clear();
	top_queue_2.clear();
	bottom_queue_2.clear();

}

bool State::set_red_time(double r) {
	this->red = r;
	return true;
}

bool State::set_green_time(double g) {
	this->green = g;
	return true;
}

bool State::set_yellow_time(double y) {
	this->yellow = y;
	return true;
}

bool State::set_red_max_time(double r) {
	if (r < RED_MIN || r > RED_MAX)//如果红灯时间超出最小最大范围
		return false;	//设置失败
	else {
		this->red_max = r;
		return true;
	}
}

bool State::set_green_max_time(double g) {
	if (g < GREEN_MIN || g > GREEN_MAX)
		return false;
	else {
		this->green_max = g;
		return true;
	}
}

bool State::set_yellow_max_time(double y) {
	if (y < YELLOW_MIN || y > YELLOW_MAX)
		return false;
	else {
		this->yellow_max = y;
		return true;
	}
}

std::vector<Car>& State::get_car_left() {
	return left_queue;
}

std::vector<Car>& State::get_car_right() {
	return right_queue;
}

std::vector<Car>& State::get_car_top() {
	return top_queue;
}
std::vector<Car>& State::get_car_bottom() {
	return bottom_queue;
}


std::vector<Car>& State::get_car_left_2() {
	return left_queue_2;
}

std::vector<Car>& State::get_car_right_2() {
	return right_queue_2;
}

std::vector<Car>& State::get_car_top_2() {
	return top_queue_2;
}
std::vector<Car>& State::get_car_bottom_2() {
	return bottom_queue_2;
}


void State::show() {
	using namespace std;
	cout.width(20);
	cout.setf(ios_base::left);
	cout << "当前状态：" << endl;
	cout.width(20);
	cout << "红灯：" << red << endl;
	cout.width(20);
	cout << "黄灯：" << yellow << endl;
	cout.width(20);
	cout << "绿灯：" << green << endl;

	cout << "当前最大状态：" << endl;
	cout.width(20);
	cout << "红灯：" << red_max << endl;
	cout.width(20);
	cout << "黄灯：" << yellow_max << endl;
	cout.width(20);
	cout << "绿灯：" << green_max << endl;

	cout << "车辆左:" << left_queue.size() << endl;
	//for (std::vector<Car>::iterator it = left_queue.begin(); it < left_queue.end(); it++) {
	//	it->show();
	//}
	cout << "车辆右:" << right_queue.size() << endl;
	cout << "车辆上:" << top_queue.size() << endl;
	cout << "车辆下:" << bottom_queue.size() << endl;
}