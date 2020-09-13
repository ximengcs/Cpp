#include "Car.h"
#include <iostream>

Car::Car(Direct to, Direct cur, int dis, int s) {
	this->to_direct = to;
	this->cur_direct = cur;
	this->speed = s;
	this->distance_opposite = dis;
}

Car::Direct Car::get_to() {
	return to_direct;
}

Car::Direct Car::get_cur() {
	return cur_direct;
}

bool Car::set_to(Direct d) {
	to_direct = d;
	return true;
}

void Car::set_distance_oppesite(int dis) {
	distance_opposite = dis;
}

bool Car::set_cur(Direct d) {
	return true;
	cur_direct = d;
}

int Car::get_speed() {
	return speed;
}

int Car::get_distance_oppesite() {
	return distance_opposite;
}

int Car::get_distance() {
	return distance;
}
int Car::get_time() {
	return time;
}

void Car::set_start_time(int time) {
	start_time = time;
}

void Car::set_distance(int dis) {
	distance = dis;
}
void Car::set_time(int ti) {
	time = ti;
}

void Car::show() {
	using namespace std;
	cout << "汽车当前所在方向:" << cur_direct << "                                 " << endl;
	cout << "汽车行驶方向:" << to_direct << "                                 " << endl;
	cout << "汽车速度:" << speed << "                                 " << endl;
	cout << "汽车前方车辆数:" << distance << "                                 " << endl;
	cout << "汽车到达当前车道时间:" << time << "                                 " << endl;
	cout << "汽车和对面距离:" << distance_opposite << "                                 " << endl;
}