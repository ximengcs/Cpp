/*
环境

车道:
	左队列：
	右队列：
	上队列：
	下队列：
十字路口大小:
人行道长度：
*/

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "Para.h"
#include "State.h"
#include "Reward.h"
#include "Maneger_Car.h"
#include <vector>
#include "tool.h"
class Environment {
private:

	State state; //实时状态：交通灯时间，车辆，人数
	Maneger_Car manager_car;
	Reward reward;

	Para para;

	std::vector<Car> wait_dispose;

	int a_to_b;	//十字路口长度：从左侧斑马线到右侧斑马线长度
	int footwalk;	//人行道长度
	int left_road; //左侧道路长度
	int right_road;
	int top_road;
	int bottom_road;

	void run_time();//时间进入下一个时间
	void run_car();
	void run_people();

	int l = para.car_stream_left;
	int r = para.car_stream_right;
	int t = para.car_stream_top;
	int b = para.car_stream_bottom;

public:

	Para orig_para;
	int get_cross();
	int get_footwalk();
	int get_left_road() { return left_road; }
	int get_right_road() { return right_road; }
	int get_top_road() { return top_road; }
	int get_bottom_road() { return bottom_road; }
	std::vector<Car>& get_wait_dispose() { return wait_dispose; }
	Para& get_para() { return para; }

	State& get_state();

	bool car_can_run(Car::Direct d);

	Reward& get_reward();
	void set_Reward(Reward reward);

	void init(Para para);//初始化

	void create_car();//随机生成车辆

	void run();	//运行一秒：将交通灯时间+-,将车辆运行至下一状态，如果车辆完成则记录

	Maneger_Car& get_maneget_car();

	void show();
};


#endif ENVIRONMENT_H_