#include "action.h"

bool Action::act(Environment& en, Q_Table& q_table) {
	Reward reward;
	reward.init();
	int* Q = q_table.get_Q();
	reward.add_c_l_r(*Q);
	reward.add_c_t_p(*(Q + 2));
	reward.add_p_l_r(*(Q + 1));
	reward.add_p_t_p(*(Q + 3));
	en.set_Reward(reward);
	return true;
}

bool Action::Q_Learning(Environment& en) {
	State& state = en.get_state();
	Reward& reward = en.get_reward();

	int _r = 0;
	int _g = 0;

	double tmp = (1 - a) * state.get_red_max_time() + a * (reward.get_c_l_r() + y * state.get_red_max_time());
	_r = state.get_red_max_time() - tmp;
	state.set_red_max_time(tmp);

	tmp = (1 - a) * state.get_green_max_time() + a * (reward.get_c_t_p() + y * state.get_green_max_time());
	_g = state.get_green_max_time() - tmp;
	state.set_green_max_time(tmp);

	reward.init();
	reward.add_c_l_r(_r);
	reward.add_c_t_p(_g);
	/*tmp = (1 - a) * state.get_red_max_time() + a * (reward.get_p_t_p() + y * state.get_red_max_time());
	state.set_red_max_time(tmp);
	tmp = (1 - a) * state.get_green_max_time() + a * (reward.get_p_t_p() + y * state.get_green_max_time());
	state.set_green_max_time(tmp);*/

	/*tmp = (1 - a) * state.get_red_max_time() + a * (reward.get_c_t_p() + y * state.get_red_max_time());
	state.set_red_max_time(tmp);
	tmp = (1 - a) * state.get_green_max_time() + a * (reward.get_c_t_p() + y * state.get_green_max_time());
	state.set_green_max_time(tmp);*/

	/*tmp = (1 - a) * state.get_red_max_time() + a * (reward.get_p_l_r() + y * state.get_red_max_time());
	state.set_red_max_time(tmp);
	tmp = (1 - a) * state.get_green_max_time() + a * (reward.get_p_l_r() + y * state.get_green_max_time());
	state.set_green_max_time(tmp);*/

	return true;
}