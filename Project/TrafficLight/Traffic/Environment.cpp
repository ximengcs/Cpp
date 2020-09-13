#include "Environment.h"
#include "ctime"
#include "cstdlib"

#include <iostream>
using namespace std;
extern long long system_time;
extern bool left_car_in; //是否有车到来
extern bool right_car_in; //是否有车到来
extern bool top_car_in; //是否有车到来
extern bool bottom_car_in; //是否有车到来

extern bool left_car_away; //
extern bool right_car_away; //
extern bool top_car_away; //
extern bool bottom_car_away; //

extern double left_car_full;
extern double right_car_full;
extern double top_car_full;
extern double bottom_car_full;

void Environment::run_time() {
	system_time++; //时间加一秒	

	if (state.get_red_time() != 0) {		//当前状态为红灯
		state.set_red_time(int(state.get_red_time())-1); //红灯减一秒
		if (state.get_red_time() == 0) //减之后为0秒
			state.set_yellow_time(int(state.get_yellow_max_time()));//设置黄灯
	}
	else if (state.get_green_time() != 0) {	//当前状态为绿灯
		state.set_green_time(int(state.get_green_time())-1);
		if (state.get_green_time() == 0)
			state.set_red_time(int(state.get_red_max_time()));
	}
	else if (state.get_yellow_time() != 0) {	//当前状态为黄灯
		state.set_yellow_time(int(state.get_yellow_time())-1);
		if (state.get_yellow_time() == 0)
			state.set_green_time(int(state.get_green_max_time()));
	}
}

void Environment::run_car() {
	std::vector<Car>& left_queue = state.get_car_left();
	std::vector<Car>& right_queue = state.get_car_right();
	std::vector<Car>& top_queue = state.get_car_top();
	std::vector<Car>& bottom_queue = state.get_car_bottom();
	
	std::vector<Car>& left_queue_2 = state.get_car_left_2();
	std::vector<Car>& right_queue_2 = state.get_car_right_2();
	std::vector<Car>& top_queue_2 = state.get_car_top_2();
	std::vector<Car>& bottom_queue_2 = state.get_car_bottom_2();

	//首先清理上次完成的车辆
	if (left_queue.size() > 0 && car_can_run(Car::Direct::left)) { //左侧车道
		if (left_queue.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(left_queue.front());
			left_queue.erase(left_queue.begin());
			left_car_away = true;
		}
		for (std::vector<Car>::iterator it = left_queue.begin(); it < left_queue.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地,
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}
	if (left_queue_2.size() > 0 && car_can_run(Car::Direct::left)) { //左侧车道
		if (left_queue_2.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(left_queue_2.front());
			left_queue_2.erase(left_queue_2.begin());
		}
		for (std::vector<Car>::iterator it = left_queue_2.begin(); it < left_queue_2.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地,
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}

	if (right_queue.size() > 0 && car_can_run(Car::Direct::right)) { //右侧车道
		if (right_queue.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(right_queue.front());
			right_queue.erase(right_queue.begin());
			right_car_away = true;
		}
		for (std::vector<Car>::iterator it = right_queue.begin(); it < right_queue.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}

	if (right_queue_2.size() > 0 && car_can_run(Car::Direct::right)) { //右侧车道
		if (right_queue_2.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(right_queue_2.front());
			right_queue_2.erase(right_queue_2.begin());
		}
		for (std::vector<Car>::iterator it = right_queue_2.begin(); it < right_queue_2.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}

	if (top_queue.size() > 0 && car_can_run(Car::Direct::top)) { //上侧车道
		if (top_queue.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(top_queue.front());
			top_queue.erase(top_queue.begin());
			top_car_away = true;
		}
		for (std::vector<Car>::iterator it = top_queue.begin(); it < top_queue.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}

	if (top_queue_2.size() > 0 && car_can_run(Car::Direct::top)) { //上侧车道
		if (top_queue_2.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(top_queue_2.front());
			top_queue_2.erase(top_queue_2.begin());
		}
		for (std::vector<Car>::iterator it = top_queue_2.begin(); it < top_queue_2.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}

	if (bottom_queue.size() > 0 && car_can_run(Car::Direct::bottom)) { //下侧车道
		if (bottom_queue.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(bottom_queue.front());
			bottom_queue.erase(bottom_queue.begin());
			bottom_car_away = true;
		}
		for (std::vector<Car>::iterator it = bottom_queue.begin(); it < bottom_queue.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}

	if (bottom_queue_2.size() > 0 && car_can_run(Car::Direct::bottom)) { //下侧车道
		if (bottom_queue_2.begin()->get_distance_oppesite() <= 0) { //已经到达目的地
			wait_dispose.push_back(bottom_queue_2.front());
			bottom_queue_2.erase(bottom_queue_2.begin());
		}
		for (std::vector<Car>::iterator it = bottom_queue_2.begin(); it < bottom_queue_2.end(); it++) {
			if (!it->get_move())
				it->set_start_time(system_time);
			it->set_move(true);
			it->set_distance(it->get_distance() - 1);
			if (it->get_distance() <= 0 && it->get_distance_oppesite() > 0) { //如果还没到目的地
				it->set_distance_oppesite(it->get_distance_oppesite() - it->get_speed());
			}
			else {
				it->set_distance_oppesite(it->get_distance_oppesite() - 1);
			}
		}
	}
}

void Environment::run_people() {

}

State& Environment::get_state() {
	return state;
}

int Environment::get_cross() {
	return 0;
}

int Environment::get_footwalk() {
	return 0;
}

Reward& Environment::get_reward() {
	return reward;
}

void Environment::run() {
	//环境运行一秒
	create_car();
	run_time();
	run_car();//车辆到下一状态
}

void Environment::init(Para p) {
	wait_dispose.clear();
	manager_car.set_rate(50);
	state.init();
	reward.init();
	left_road = 50;
	right_road = 50;
	top_road = 50;
	bottom_road = 50;
	footwalk = 20;
	a_to_b = 20;
	orig_para = p;
	/*int d = 0;
	int max = 0;
	int t = p.car_stream_left;
	while (t < 1000) {
		d++;
		t *= 10;
	}
	if (d > max)
		max = d;
	t = p.car_stream_right;
	d = 0;
	while (t < 1000) {
		d++;
		t *= 10;
	}
	if (d > max)
		max = d;
	t = p.car_stream_top;
	d = 0;
	while (t < 1000) {
		d++;
		t *= 10;
	}
	if (d > max)
		max = d;
	t = p.car_stream_bottom;
	d = 0;
	while (t < 1000) {
		d++;
		t *= 10;
	}
	if (d > max)
		max = d;
	
	while (d > 0) {
		p.car_stream_left *= 10;
		p.car_stream_right *= 10;
		p.car_stream_top *= 10;
		p.car_stream_bottom *= 10;
		d--;
	}*/
	para = p;

	/*l = para.car_stream_left;
	r = para.car_stream_right;
	t = para.car_stream_top;
	b = para.car_stream_bottom;*/
}

void Environment::create_car() {
	std::vector<Car>& left_queue = state.get_car_left();
	std::vector<Car>& right_queue = state.get_car_right();
	std::vector<Car>& top_queue = state.get_car_top();
	std::vector<Car>& bottom_queue = state.get_car_bottom();

	std::vector<Car>& left_queue_2 = state.get_car_left_2();
	std::vector<Car>& right_queue_2 = state.get_car_right_2();
	std::vector<Car>& top_queue_2 = state.get_car_top_2();
	std::vector<Car>& bottom_queue_2 = state.get_car_bottom_2();

	/*if (system_time % 3600 == 0) {
		l = para.car_stream_left;
		r = para.car_stream_right;
		t = para.car_stream_top;
		b = para.car_stream_bottom;
	}*/

	//if (l > 0) {
	//	l--;
	//	Car tmp = manager_car.random_car(Car::Direct::left, left_queue.size(), a_to_b);
	//	if (tmp.get_to() == Car::Direct::right)
	//		left_queue.push_back(tmp);
	//	else
	//		left_queue_2.push_back(tmp);
	//	//left_car_in = true;
	//}
	//if (r > 0) {
	//	r--;
	//	Car tmp = manager_car.random_car(Car::Direct::right, right_queue.size(), a_to_b);
	//	if (tmp.get_to() == Car::Direct::left)
	//		right_queue.push_back(tmp);
	//	else
	//		right_queue_2.push_back(tmp);
	//	//right_car_in = true;
	//}
	//if (t > 0) {
	//	t--;
	//	Car tmp = manager_car.random_car(Car::Direct::top, top_queue.size(), a_to_b);
	//	if (tmp.get_to() == Car::Direct::bottom)
	//		top_queue.push_back(tmp);
	//	else
	//		top_queue_2.push_back(tmp);
	//	//top_car_in = true;
	//}
	//if (b > 0) {
	//	b--;
	//	Car tmp = manager_car.random_car(Car::Direct::bottom, bottom_queue.size(), a_to_b);
	//	if (tmp.get_to() == Car::Direct::top)
	//		bottom_queue.push_back(tmp);
	//	else
	//		bottom_queue_2.push_back(tmp);
	//	//bottom_car_in = true;
	//}
	
	if (system_time%3600 == 0) {
		int i = 0;
		int end = para.car_stream_left/100;
		while (i < end) { //左
			Car tmp = manager_car.random_car(Car::Direct::left, left_queue.size(), a_to_b);
			if (tmp.get_to() == Car::Direct::right)
				left_queue.push_back(tmp);
			else
				left_queue_2.push_back(tmp);
			left_car_in = true;
			i++;
		}

		i = 0;
		end = para.car_stream_right / 100;
		while (i < end) { //右
			Car tmp = manager_car.random_car(Car::Direct::right, right_queue.size(), a_to_b);
			if (tmp.get_to() == Car::Direct::left)
				right_queue.push_back(tmp);
			else
				right_queue_2.push_back(tmp);
			right_car_in = true;
			i++;
		}

		i = 0;
		end = para.car_stream_top / 100;
		while (i < end) { //上
			Car tmp = manager_car.random_car(Car::Direct::top, top_queue.size(), a_to_b);
			if (tmp.get_to() == Car::Direct::bottom)
				top_queue.push_back(tmp);
			else
				top_queue_2.push_back(tmp);
			top_car_in = true;
			i++;
		}

		i = 0;
		end = para.car_stream_top / 100;
		while (i < end) { //下
			Car tmp = manager_car.random_car(Car::Direct::bottom, bottom_queue.size(), a_to_b);
			if (tmp.get_to() == Car::Direct::top)
				bottom_queue.push_back(tmp);
			else
				bottom_queue_2.push_back(tmp);
			bottom_car_in = true;
			i++;
		}
	}
	
	/*int r_l = double(para.car_stream_left)/3600*1000;
	int r_r = double(para.car_stream_right)/3600*1000;
	int r_t = double(para.car_stream_top)/3600*1000;
	int r_b = double(para.car_stream_bottom)/3600*1000;*/
	/*srand(time(nullptr));
	if (rand() % 100 > manager_car.get_rate()) {
		Car tmp = manager_car.random_car(Car::Direct::left, left_queue.size(), a_to_b);
		if (tmp.get_to() == Car::Direct::right)
			left_queue.push_back(tmp);
		else
			left_queue_2.push_back(tmp);
		left_car_in = true;
	}
	if (rand() % 100 > manager_car.get_rate()) {
		Car tmp = manager_car.random_car(Car::Direct::right, right_queue.size(), a_to_b);
		if (tmp.get_to() == Car::Direct::left)
			right_queue.push_back(tmp);
		else
			right_queue_2.push_back(tmp);
		right_car_in = true;
	}
	if (rand() % 100 > manager_car.get_rate()) {
		Car tmp = manager_car.random_car(Car::Direct::top, top_queue.size(), a_to_b);
		if (tmp.get_to() == Car::Direct::bottom)
			top_queue.push_back(tmp);
		else
			top_queue_2.push_back(tmp);
		top_car_in = true;
	}
	if (rand() % 100 > manager_car.get_rate()) {
		Car tmp = manager_car.random_car(Car::Direct::bottom, bottom_queue.size(), a_to_b);
		if (tmp.get_to() == Car::Direct::top)
			bottom_queue.push_back(tmp);
		else
			bottom_queue_2.push_back(tmp);
		bottom_car_in = true;
	}*/
}

Maneger_Car& Environment::get_maneget_car() {
	return manager_car;
}

void Environment::show() {
	using namespace std;

	setpos(0, 0);
	hide_console();

	state.show();
}
void Environment::set_Reward(Reward reward) {
	this->reward = reward;
}


bool Environment::car_can_run(Car::Direct d) {
	double red = state.get_red_time();
	double green = state.get_green_time();
	double yellow = state.get_yellow_time();

	if (d == Car::Direct::left || d == Car::Direct::right) {
		if (green != 0)
			return true;
		else
			return false;
	}else if (d == Car::Direct::top || d == Car::Direct::bottom) {
		if (red != 0)
			return true;
		else
			return false;
	}
	else
		return false;
}