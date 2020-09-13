#include "Q_Table.h"

void Q_Table::init() {
	Q[0][0] = 0;
	Q[0][1] = 0;
	Q[1][0] = 0;
	Q[1][1] = 0;
}
void Q_Table::update(Reward reward) {

}

int* Q_Table::get_Q() {
	return (int *)Q;
}

//计算q表;Q表会随着环境的变化而变化
void Q_Table::calculate(Environment en) {
	State& state = en.get_state();
	left_car_full = double(state.get_car_left().size()+ state.get_car_left_2().size())/en.get_left_road();
	right_car_full = double(state.get_car_right().size()+ state.get_car_right_2().size()) / en.get_right_road();
	top_car_full = double(state.get_car_top().size()+state.get_car_top_2().size()) / en.get_top_road();
	bottom_car_full = double(state.get_car_bottom().size()+state.get_car_bottom_2().size()) / en.get_bottom_road();
	double car_average = 
		(left_car_full+right_car_full+top_car_full+bottom_car_full)/4;  //车辆平均饱和度
	
	init();
	if (left_car_in) {
		if (left_average_time > all_average_time) { //平均行驶时间大于总的
			Q[1][0] += 1; //增加绿灯时间
		}
		else if (left_average_time < all_average_time) {
			Q[1][0] += -1; //减少绿灯时间
		}
		if (left_wait_time > all_wait_time) { //平均等待时间过长
			Q[0][0] += -1; //减少红灯时间
		}
		else if (left_wait_time < all_wait_time) {
			Q[0][0] += 1;	//增加红灯时间
		}
	}
	if (right_car_in) {
		if (right_average_time > all_average_time) { //平均行驶时间大于总的
			Q[1][0] += 1; //增加绿灯时间
		}
		else if (right_average_time < all_average_time) {
			Q[1][0] += -1; //减少绿灯时间
		}
		if (right_wait_time > all_wait_time) { //平均等待时间过长
			Q[0][0] += -1; //减少红灯时间
		}
		else if (right_wait_time < all_wait_time) {
			Q[0][0] += 1;	//增加红灯时间
		}
	}
	if (top_car_in) {
		if (top_average_time > all_average_time) { //平均行驶时间大于总的
			Q[0][0] += 1; //增加绿灯时间
		}
		else if (top_average_time < all_average_time) {
			Q[0][0] += -1; //减少绿灯时间
		}
		if (top_wait_time > all_wait_time) { //平均等待时间过长
			Q[1][0] += -1; //减少红灯时间
		}
		else if (top_wait_time < all_wait_time) {
			Q[1][0] += 1;	//增加红灯时间
		}
	}
	if (bottom_car_in) {
		if (bottom_average_time > all_average_time) { //平均行驶时间大于总的
			Q[0][0] += 1; //增加绿灯时间
		}
		else if (bottom_average_time < all_average_time) {
			Q[0][0] += -1; //减少绿灯时间
		}
		if (bottom_wait_time > all_wait_time) { //平均等待时间过长
			Q[1][0] += -1; //减少红灯时间
		}
		else if (bottom_wait_time < all_wait_time) {
			Q[1][0] += 1;	//增加红灯时间
		}
	}
	/*
	if (left_car_in) {
		if (left_car_full > car_average) {
			Q[0][0] += -1;	//红灯减小
			Q[1][0] += 1;	//绿灯增长
		}
		else if (left_car_full == car_average) {
			Q[0][0] += 0;	//红灯不变
			Q[1][0] += 0;	//绿灯不变
		}
		else {
			Q[0][0] += 1;	//红灯增长
			Q[1][0] += -1;	//绿灯减小
		}
	}

	if (right_car_in) {
		if (right_car_full > car_average) {
			Q[0][0] += -1;	//红灯减小
			Q[1][0] += 1;	//绿灯增长
		}
		else if (right_car_full == car_average) {
			Q[0][0] += 0;	//红灯不变
			Q[1][0] += 0;	//绿灯不变
		}
		else {
			Q[0][0] += 1;	//红灯增长
			Q[1][0] += -1;	//绿灯减小
		}
	}

	if (top_car_in) {
		if (top_car_full > car_average) {
			Q[1][0] += -1;	//红灯减小
			Q[0][0] += 1;	//绿灯增长
		}
		else if (top_car_full == car_average) {
			Q[1][0] += 0;	//红灯不变
			Q[0][0] += 0;	//绿灯不变
		}
		else {
			Q[1][0] += 1;	//红灯增长
			Q[0][0] += -1;	//绿灯减小
		}
	}

	if (bottom_car_in) {
		if (bottom_car_full > car_average) {
			Q[1][0] += -1;	//红灯减小
			Q[0][0] += 1;	//绿灯增长
		}
		else if (bottom_car_full == car_average) {
			Q[1][0] += 0;	//红灯不变
			Q[0][0] += 0;	//绿灯不变
		}
		else {
			Q[1][0] += 1;	//红灯增长
			Q[0][0] += -1;	//绿灯减小
		}
	}

	*/
	//等待时间过长 -> 减少红灯时间
	//平均行驶时间过长 -> 增加绿灯时间
	//if (left_people_full > people_average) {
	//	Q[0][1] += -1;	//红灯减小
	//	Q[1][1] += 1;	//绿灯增长
	//}
	//else if (left_car_full == car_average) {
	//	Q[0][1] += 0;	//红灯不变
	//	Q[1][1] += 0;	//绿灯不变
	//}
	//else {
	//	Q[0][1] += 1;	//红灯增长
	//	Q[1][1] += -1;	//绿灯减小
	//}

	//if (right_people_full > people_average) {
	//	Q[0][1] += -1;	//红灯减小
	//	Q[1][1] += 1;	//绿灯增长
	//}
	//else if (right_car_full == car_average) {
	//	Q[0][1] += 0;	//红灯不变
	//	Q[1][1] += 0;	//绿灯不变
	//}
	//else {
	//	Q[0][1] += 1;	//红灯增长
	//	Q[1][1] += -1;	//绿灯减小
	//}

	//if (top_people_full > people_average) {
	//	Q[0][0] += -1;	//红灯减小
	//	Q[1][0] += 1;	//绿灯增长
	//}
	//else if (top_people_full == car_average) {
	//	Q[0][0] += 0;	//红灯不变
	//	Q[1][0] += 0;	//绿灯不变
	//}
	//else {
	//	Q[0][0] += 1;	//红灯增长
	//	Q[1][0] += -1;	//绿灯减小
	//}

	//if (bottom_people_full > people_average) {
	//	Q[0][0] += -1;	//红灯减小
	//	Q[1][0] += 1;	//绿灯增长
	//}
	//else if (bottom_people_full == car_average) {
	//	Q[0][0] += 0;	//红灯不变
	//	Q[1][0] += 0;	//绿灯不变
	//}
	//else {
	//	Q[0][0] += 1;	//红灯增长
	//	Q[1][0] += -1;	//绿灯减小
	//}
}