/*
数据

四条路车辆饱和度

四条斑马线饱和度

*/

extern double left_car_full = 0;
extern double right_car_full = 0;
extern double top_car_full = 0;
extern double bottom_car_full = 0;

extern double left_people_full = 0;
extern double right_people_full = 0;
extern double top_people_full = 0;
extern double bottom_people_full = 0;

extern double left_average_time = 0;
extern double right_average_time = 0;
extern double top_average_time = 0;
extern double bottom_average_time = 0;
extern double all_average_time = 0;
extern double left_wait_time = 0;
extern double right_wait_time = 0;
extern double top_wait_time = 0;
extern double bottom_wait_time = 0;
extern double all_wait_time = 0;


extern double a = 0.5;
extern double y = 1;

#ifndef DATA_H_
#define DATA_H_
#include "Environment.h"

void init_data() {

}

void update_data(Environment envrionment) {
	
}

#endif