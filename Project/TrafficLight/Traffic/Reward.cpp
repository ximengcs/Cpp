#include "Reward.h"

int Reward::get_c_l_r() {
	return experience[0][0];
}
int Reward::get_c_t_p() {
	return experience[1][0];
}
int Reward::get_p_l_r() {
	return experience[0][1];
}
int Reward::get_p_t_p() {
	return experience[1][1];
}

void Reward::add_c_l_r(int n) {
	experience[0][0] += n;
}
void Reward::add_c_t_p(int n) {
	experience[1][0] += n;
}
void Reward::add_p_l_r(int n) {
	experience[0][1] += n;
}
void Reward::add_p_t_p(int n) {
	experience[1][1] += n;
}

void Reward::init() {
	experience[0][0] = 0;
	experience[0][1] = 0;
	experience[1][0] = 0;
	experience[1][1] = 0;
}