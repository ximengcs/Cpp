#include "Maneger_Car.h"
#include <ctime>
#include <cstdlib>

extern long long system_time;

Car Maneger_Car::random_car(int n_car, int dis) {//接受前面车辆,dis:环境中的距离
	srand(time(nullptr));
	Car::Direct to_direct_rand = Car::Direct(rand() % 4);
	Car::Direct cur_direct_rand = Car::Direct(rand() % 4);
	while (to_direct_rand == cur_direct_rand) {
		to_direct_rand = Car::Direct(rand() % 4);
	}
	Car car(to_direct_rand, cur_direct_rand, dis+n_car);
	car.set_distance(n_car);
	car.set_time(system_time);
	car.set_start_time(0);
	car.set_move(false);
	return car;
}

Car Maneger_Car::random_car(Car::Direct d, int n_car, int dis) {
	srand(time(nullptr));
	Car::Direct to_direct_rand = Car::Direct(rand() % 4);
	Car::Direct cur_direct_rand = d;
	while (to_direct_rand == cur_direct_rand) {
		to_direct_rand = Car::Direct(rand() % 4);
	}
	Car car(to_direct_rand, cur_direct_rand, dis + n_car);
	car.set_distance(n_car);
	car.set_time(system_time);
	car.set_start_time(system_time);
	car.set_move(false);
	return car;
}

Maneger_Car::Maneger_Car() {
	rate_car = 50;  //50%
}

int Maneger_Car::get_rate() {
	return rate_car;
}
void Maneger_Car::set_rate(int rate) {
	rate_car = rate;
}