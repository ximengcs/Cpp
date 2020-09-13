/*
汽车类

汽车速度：
汽车行驶方向：

*/

#ifndef CAR_H_
#define CAR_H_

class Car {
public:
	enum Direct{top, bottom, left, right};
	enum {DEFAULT_SPEED = 3}; // 3m/s

private:
	Direct to_direct;	//汽车行驶方向
	Direct cur_direct;	//汽车当前方向
	int speed;		//汽车速度
	int distance;	//距离人行道距离
	int time;	//汽车到达时间
	int start_time; //汽车启动时间
	int distance_opposite;	//距离目的地对面距离

	bool is_move;
public:
	Car(Direct to, Direct cur, int dis, int speed = DEFAULT_SPEED);
	~Car(){}

	Direct get_to();	//获取行驶方向
	Direct get_cur();	//获取当前方向
	int get_speed();		//获取汽车速度
	int get_distance();
	int get_time();
	int get_distance_oppesite();

	bool set_to(Direct d);	//设置行驶方向
	bool set_cur(Direct d);	//设置当前方向
	void set_distance(int dis);
	void set_distance_oppesite(int dis);
	void set_time(int time);
	void set_start_time(int time);
	int get_start_time() { return start_time; }
	bool get_move() { return is_move; }
	void set_move(bool m) { is_move = m; }

	void show();
};

#endif