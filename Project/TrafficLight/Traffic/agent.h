/*
智能体agent

*/

#ifndef AGENT_H_
#define AGENT_H_

#include "Q_Table.h"
#include "action.h"
#include "Environment.h"
#include "Reward.h"
#include "Q_Table.h"
class Agent {
private:
	Action action;
	Q_Table q_table;

	int learn_times = 0;

public:
	Agent(){}
	~Agent(){}

	Q_Table& get_Q() { return q_table; }

	int get_learn_times() { return learn_times; }
	void init();//初始化
	bool act(Environment& en);	//根据环境算出Q表采取行动
	bool update_q_table(Reward re);//更新Q表
};

#endif