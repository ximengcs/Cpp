#ifndef PARA_H_
#define PARA_H_

class Para {
public:
	int car_stream_left; //车流量
	int car_stream_right; //车流量
	int car_stream_top; //车流量
	int car_stream_bottom; //车流量
	int times; //学习次数
	Para(int left, int right, int top, int bottom, int t) : car_stream_left (left),
		car_stream_right(right), car_stream_top(top), car_stream_bottom(bottom), times(t){}
	Para() {}
};

#endif