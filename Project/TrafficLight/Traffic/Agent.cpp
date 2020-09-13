#include "agent.h"


void Agent::init() {
	q_table.init();
	learn_times = 0;
}

bool Agent::act(Environment& en) {
	learn_times++;
	q_table.calculate(en);
	//根据环境和Q表采取行动
	action.act(en, q_table);
	//从环境获取回报更新Q表
	//而进入下一个状态,更新状态
	action.Q_Learning(en);
	return true;
}

bool Agent::update_q_table(Reward re) {
	return true;
}