#include <iostream>
#include <conio.h>
#include "State.h"
#include "Car.h"
#include "agent.h"
#include "action.h"
#include "View.h"
#include "Maneger_Car.h"
#include "Data.h"
#include "Para.h"
#include "tool.h"
using namespace std;

extern bool left_car_in = false; //
extern bool right_car_in = false; //
extern bool top_car_in = false; //
extern bool bottom_car_in = false; //
extern bool car_finish = false;
extern long long system_time = 0;      //时间

extern bool left_car_away = false; //
extern bool right_car_away = false; //
extern bool top_car_away = false; //
extern bool bottom_car_away = false; //

void init(Agent& agent, Environment& environment, View& view, Para para); //初始化
void run(Agent& agent, Environment& environment, long& times, View& view);
void calculate(Agent& agent, Environment& environment, View& view, Para para);
void reset(Agent& agent, Environment& environment, View& view, Para para);

void test();

int main()
{
    //test();
    set_console_size(120, 30);

    Agent agent;
    Environment environment;
    View view(agent, environment);
    view.show_menu();
    view.reflesh_menu();
    while (1) {
        view.reflesh_menu();
        
        int ch = _getch();
        switch(ch) {
        case 'w': //上
            if (view.menu_choice == 2)
                view.menu_choice = 1;
            view.reflesh_menu();
            break;
        case 's': //下
            if (view.menu_choice == 1)
                view.menu_choice = 2;
            view.reflesh_menu();
            break;
        case 13: //回车
            if (view.menu_choice == 1) { //确认查看
                view.refresh_scanf_code();
                int q = 1;
                while (q) {
                    int ch_s = _getch();
                    switch (ch_s) {
                    case 'w':
                        view.clear_scanf_code();
                        if(view.current_code > 1)
                            view.current_code--;
                        view.refresh_scanf_code();
                        break;
                    case 's':
                        view.clear_scanf_code();
                        if (view.current_code < view.code-1)
                            view.current_code++;
                        view.refresh_scanf_code();
                        break;
                    case 13:
                        view.scan_chart(view.current_code);
                        break;
                    case 27:
                        view.clear_scanf_code();
                        q = 0;
                        break;
                    }

                }
            }
            else { //确认添加
                int q = 1;
                while(q) {
                    view.reflesh_menu_2();
                    int ch_2 = _getch();
                    switch (ch_2) {
                    case 'w': //预设
                        if (view.menu_choice_2 > 1)
                            view.menu_choice_2--;
                        view.reflesh_menu_2();
                        break;
                    case 's': //手动
                        if (view.menu_choice_2 < 3)
                            view.menu_choice_2++;
                        view.reflesh_menu_2();
                        break;
                    case 13:  //返回
                        if (view.menu_choice_2 == 1) { //预设数据-----------------
                            Para para(153, 150, 140, 103, 100);
                            calculate(agent, environment, view, para);
                            Para para2(76, 187, 216, 165, 100);
                            calculate(agent, environment, view, para2);
                            Para para3(357, 531, 300, 753, 100);
                            calculate(agent, environment, view, para3);
                            Para para4(250, 61, 258, 152, 100);
                            calculate(agent, environment, view, para4);
                            Para para5(683, 779, 774, 1070, 100);
                            calculate(agent, environment, view, para5);
                            Para para6(131, 176, 315, 137, 100);
                            calculate(agent, environment, view, para6);
                            Para para7(124, 162, 101, 236, 100);
                            calculate(agent, environment, view, para7);
                            Para para8(144, 217, 183, 174, 100);
                            calculate(agent, environment, view, para8);
                            Para para9(299, 265, 219, 447, 100);
                            calculate(agent, environment, view, para9);
                            //----------------------------------------------------
                        }
                        else if (view.menu_choice_2 == 2) { //手动输入
                            setpos(0, view.code+1);
                            int stream_1, stream_2, stream_3, stream_4;
                            int times_learn;
                            double a_;
                            double y_;
                            cout << "请输入:\t车流量:";
                            cin >> stream_1 >> stream_2 >> stream_3 >> stream_4;
                            cout << "\t学习次数:";
                            cin >> times_learn;
                            cout << "\t学习率:";
                            cin >> a_;
                            cout << "\t折扣率:";
                            cin >> y_;
                            Para para(stream_1, stream_2, stream_3, stream_4, times_learn);
                            calculate(agent, environment, view, para);

                            setpos(0, view.code);

                            for (int i = 0; i < 10; i++) {
                                cout.width(119);
                                cout.fill(' ');
                                cout << " " << endl;
                            }
                            q = 0;
                        }else if(view.menu_choice_2 == 3)
                            q = 0;
                    }
                }
            }
            break;
        }
    }

    return 0;
}

void test() {
    Agent agent;
    Environment environment;
    View view(agent, environment);
    Para para(357, 531, 300, 753, 100);
    calculate(agent, environment, view, para);
}

//传递参数计算
void calculate(Agent& agent, Environment& environment, View& view, Para para) {
    reset(agent, environment, view, para);
    long times = 0;
    for (int i = 0; i < 1000; i++) {
        run(agent, environment, times, view);
        view.data_analysis();
    }
    system_time = 0;
    view.show_final();  //显示数据
    while (times < para.times) {
        run(agent, environment, times, view);  //运行:agent根据环境的状态采取行动,环境可以返回一个回报进入下一个状态
        view.data_analysis(); //显示

        left_average_time = view.get_l_a_time();
        right_average_time = view.get_r_a_time();
        top_average_time = view.get_t_a_time();
        bottom_average_time = view.get_b_a_time();
        all_average_time = view.get_a_time();
        left_wait_time = view.get_l_w_time();
        right_wait_time = view.get_r_w_time();
        top_wait_time = view.get_t_w_time();
        bottom_wait_time = view.get_b_w_time();
        all_wait_time = view.get_w_time();
    }
    
    view.show_final(true);  //显示数据
    view.reset();       //重置
}

void init(Agent& agent, Environment& environment, View& view, Para para) {
    left_car_in = false;
    right_car_in = false;
    top_car_in = false; //
    bottom_car_in = false;
    car_finish = false;

    agent.init();
    environment.init(para);
}

void run(Agent& agent, Environment& environment, long& times, View& view) {
    //环境运行到下一时间步
    environment.run();

    //每有一辆车经过公路agent就采取行动一次
    //车辆经过时从队列消失
    if (left_car_in || right_car_in || top_car_in || bottom_car_in) {
        times++;
        agent.act(environment); //agent采取行动
        left_car_in = false;
        right_car_in = false;
        top_car_in = false;
        bottom_car_in = false;
    }
}

void reset(Agent& agent, Environment& environment, View& view, Para para) {
    system_time = 0;
    agent.init();
    environment.init(para);

    left_car_in = false; //
    right_car_in = false; //
    top_car_in = false; //
    bottom_car_in = false; //

    left_car_away = false; //
    right_car_away = false; //
    top_car_away = false; //
    bottom_car_away = false; //

    left_car_full = 0;
    right_car_full = 0;
    top_car_full = 0;
    bottom_car_full = 0;

    left_people_full = 0;
    right_people_full = 0;
    top_people_full = 0;
    bottom_people_full = 0;
}