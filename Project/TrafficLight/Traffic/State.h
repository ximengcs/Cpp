/*
实时状态S

红灯状态
绿灯状态
黄灯状态

*/
#ifndef STATE_H_
#define STATE_H_
#include <vector>
#include "Car.h"
class State {
	enum {//默认时间参数
		TIME = 1000,		//时间基数
		RED_DEFAULT = 60,	//红灯默认时间
		GREEN_DEFAULT = 60,	//绿灯默认时间
		YELLOW_DEFAULT = 3,	//黄灯默认时间

		RED_MIN = 10,		//最小红灯时间
		GREEN_MIN = 10,		//最小绿灯时间
		YELLOW_MIN = 3,		//最小黄灯时间

		RED_MAX = 99,		//最大红灯时间
		GREEN_MAX = 99,		//最大绿灯时间
		YELLOW_MAX = 3,		//最大黄灯时间
	};

private:
	//实时时间:-----------------------------------交通灯
	double red;		//红灯 
	double green;	//绿灯
	double yellow;	//黄灯

	//最大时间，当前设置时间
	double red_max;		//最大红灯时间
	double green_max;		//最大绿灯时间
	double yellow_max;		//最大黄灯时间


	//人行道实时时间:左-右--------------------------------------人行道
	double red_p;		//红灯-人-左-右
	double green_p;		//绿灯-人-左-右
	double red_max_p;	//最大红灯时间
	double green_max_p;	//最大绿灯时间

	//车辆
	std::vector<Car> left_queue;
	std::vector<Car> right_queue;
	std::vector<Car> top_queue;
	std::vector<Car> bottom_queue;

	//车辆
	std::vector<Car> left_queue_2;
	std::vector<Car> right_queue_2;
	std::vector<Car> top_queue_2;
	std::vector<Car> bottom_queue_2;

public:
	~State(){}

	void init();

	double get_red_time() { return red; }
	double get_green_time() { return green; }
	double get_yellow_time() { return yellow; }

	double get_red_max_time() { return red_max; }
	double get_green_max_time() { return green_max; }
	double get_yellow_max_time() { return yellow_max; }

	bool set_red_time(double r);
	bool set_green_time(double g);
	bool set_yellow_time(double y);

	bool set_red_max_time(double r);
	bool set_green_max_time(double g);
	bool set_yellow_max_time(double y);

	std::vector<Car>& get_car_left();
	std::vector<Car>& get_car_right();
	std::vector<Car>& get_car_top();
	std::vector<Car>& get_car_bottom();

	std::vector<Car>& get_car_left_2();
	std::vector<Car>& get_car_right_2();
	std::vector<Car>& get_car_top_2();
	std::vector<Car>& get_car_bottom_2();

	void show();	//显示所有状态，(测试)
};

#endif