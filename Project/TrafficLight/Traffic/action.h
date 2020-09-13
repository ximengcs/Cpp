/*
行动

减少交通灯时间
增加交通灯时间
*/

#ifndef ACTION_H_
#define ACTION_H_
#include "Environment.h"
#include "Q_Table.h"

extern double a;
extern double y;

class Action {
public:
	bool act(Environment& en, Q_Table& q_table); //根据当前环境增加红灯时间

	bool Q_Learning(Environment& en);
};

#endif