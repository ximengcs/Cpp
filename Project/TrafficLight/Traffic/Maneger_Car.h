/*
生成汽车
*/

#ifndef CREATE_CAR_H_
#define CREATE_CAR_H_

#include "Car.h"

class Maneger_Car {
private:
	int rate_car; //车辆出现几率
public:
	Maneger_Car();
	~Maneger_Car(){}

	Car random_car(int n_car, int dis); //随机生成汽车
	Car random_car(Car::Direct d, int n_car, int dis); //随机某方向生成汽车
	int get_rate();
	void set_rate(int rate);
};

#endif