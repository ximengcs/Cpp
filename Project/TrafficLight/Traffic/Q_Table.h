/*
Q表
*/

#ifndef Q_TABLE_H_
#define Q_TABLE_H_

#include "Reward.h"
#include "Environment.h"

extern double left_car_full;
extern double right_car_full;
extern double top_car_full;
extern double bottom_car_full;

extern double left_people_full;
extern double right_people_full;
extern double top_people_full;
extern double bottom_people_full;

extern double left_average_time;
extern double right_average_time;
extern double top_average_time;
extern double bottom_average_time;
extern double all_average_time;
extern double left_wait_time;
extern double right_wait_time;
extern double top_wait_time;
extern double bottom_wait_time;
extern double all_wait_time;

extern bool left_car_in; //是否有车到来
extern bool right_car_in; //是否有车到来
extern bool top_car_in; //是否有车到来
extern bool bottom_car_in; //是否有车到来

class Q_Table {
private:
	//Q值 : 1列：车辆红绿灯   2列：人行道红绿灯
	int Q[2][2];

public:
	void init(); //初始化
	void update(Reward reward); //更新Q表
	void calculate(Environment en);//根据当前环境计算Q表
	int* get_Q();
};

#endif