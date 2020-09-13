/*
回报

*/

#ifndef REWARD_H_
#define REWARD_H_

class Reward {
private:
	int experience[2][2];

public:
	Reward(){}

	void init();

	int get_c_l_r();	//车辆-左右
	int get_c_t_p();	//车辆-左右
	int get_p_l_r();	//车辆-左右
	int get_p_t_p();	//车辆-左右

	void add_c_l_r(int n = 1);	//车辆-左右
	void add_c_t_p(int n = 1);	//车辆-左右
	void add_p_l_r(int n = 1);	//车辆-左右
	void add_p_t_p(int n = 1);	//车辆-左右
};

#endif