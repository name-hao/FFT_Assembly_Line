//#include <thread>
//#include <atomic> 
//#include <chrono>
//#include <iostream>
//#include <condition_variable> 
//#include <string>
//#include <vector>
//#include <iomanip>
//#include "concurrent_queue.h"
//using namespace std;
//using namespace std::chrono;
//using std::string;
//using std::vector;
//using std::mutex;
//using std::condition_variable;
//using std::thread;
//using std::ref;
//using namespace moodycamel;
//
//bool f1_input{true}, f1_out{ false },
//     f2_input{ true }, f2_out{ false },
//     f3_input{ true }, f3_out{ false };
//
//ConcurrentQueue<int> buffer1_2(100);
//ConcurrentQueue<int> buffrt2_3(100);
//
//float x[8], y[8];
//const float p = 3.1416;
//
//decltype(high_resolution_clock::now()) time_begin, time_end;
//
//void butterfly1()
//{
//    time_begin = high_resolution_clock::now();
//    while (true)
//    {
//        //�����ݵ�ʱ������д���
//        if (f1_input)
//        {
//            f1_input = false;
//            f1_out = false;
//            //��ʼ��������
//            float u, v;
//            int m1 = 1;//��һ����ÿ����Ⱥ���������������ÿ����Ⱥ��1�������
//            int m2 = 2 * m1;//��һ���е�Ⱥ���ȡ���Ϊ2
//            int m3 = 4;//��һ���еĵ�Ⱥ��������Ϊ4��
//
//                       //����ÿ����Ⱥ��˵
//            for (int j = 0; j < m3; j++)
//            {
//                int m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//
//                                //����ÿ����Ⱥ��ÿ���������˵
//                for (int r = 0; r < m1; r++)
//                {
//                    int k1 = m4 + r;   //��������������ڱ�
//                    int k2 = k1 + m1;  //��������������ڱ�
//                    u = x[k2] * cos(2 * p * r / m2) + y[k2] * sin(2 * p * r / m2);
//                    v = y[k2] * sin(2 * p * r / m2) - x[k2] * cos(2 * p * r / m2);
//                    x[k2] = x[k1] - u;
//                    y[k2] = y[k1] - v;
//                    x[k1] = x[k1] + u;
//                    y[k1] = y[k1] + v;
//                }
//            }
//
//            //���������f1_out = true;
//            f1_out = true;
//            //���������룬���˳��߳�
//            return;
//        }
//        
//    }
//}
//void butterfly2()
//{
//    while (true)
//    {
//        //���f1���������f2�ɽ�������,����Կ�ʼ��������
//        if (f1_out && f2_input)
//        {
//            f2_input = false;
//            f2_out = false;
//            float u, v;
//            int m1 = 2;//�ڶ�����ÿ����Ⱥ���������������ÿ����Ⱥ��2�������
//            int m2 = 2 * m1;//�ڶ����е�Ⱥ���ȡ���Ϊ4
//            int m3 = 2;//�ڶ����еĵ�Ⱥ��������Ϊ2��
//
//                       //����ÿ����Ⱥ��˵
//            for (int j = 0; j < m3; j++)
//            {
//                int m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//
//                                //����ÿ����Ⱥ��ÿ���������˵
//                for (int r = 0; r < m1; r++)
//                {
//                    int k1 = m4 + r;   //��������������ڱ�
//                    int k2 = k1 + m1;  //��������������ڱ�
//                    u = x[k2] * cos(2 * p * r / m2) + y[k2] * sin(2 * p * r / m2);
//                    v = y[k2] * sin(2 * p * r / m2) - x[k2] * cos(2 * p * r / m2);
//                    x[k2] = x[k1] - u;
//                    y[k2] = y[k1] - v;
//                    x[k1] = x[k1] + u;
//                    y[k1] = y[k1] + v;
//                }
//            }
//            //��������󣬸���״ֵ̬
//            f2_input = true;
//            f2_out = true;
//            //���������룬���˳��߳�
//            if (!f1_input)
//            {
//                return;
//            }
//        }
//    }
//}
//void butterfly3()
//{
//    while (true)
//    {
//        //���f2���������f3�ɽ������룬��ʼ��������
//        if (f2_out && f3_input)
//        {
//            f3_out = false;
//            f3_input = false;
//            float u, v;
//            int m1 = 4;//��������ÿ����Ⱥ���������������ÿ����Ⱥ��4�������
//            int m2 = 2 * m1;//�������е�Ⱥ���ȡ���Ϊ8
//            int m3 = 1;//�ڶ����еĵ�Ⱥ��������Ϊ1��
//
//                       //����ÿ����Ⱥ��˵
//            for (int j = 0; j < m3; j++)
//            {
//                int m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//
//                                //����ÿ����Ⱥ��ÿ���������˵
//                for (int r = 0; r < m1; r++)
//                {
//                    int k1 = m4 + r;   //��������������ڱ�
//                    int k2 = k1 + m1;  //��������������ڱ�
//
//                    u = x[k2] * cos(2 * p * r / m2) + y[k2] * sin(2 * p * r / m2);
//                    v = y[k2] * sin(2 * p * r / m2) - x[k2] * cos(2 * p * r / m2);
//                    x[k2] = x[k1] - u;
//                    y[k2] = y[k1] - v;
//                    x[k1] = x[k1] + u;
//                    y[k1] = y[k1] + v;
//                }
//            }
//            //���������ݣ��Ϳ�ʼ��������
//            f3_input = true;
//            f3_out = true;
//            //this_thread::sleep_for(chrono::microseconds(100));
//            //���������룬���˳��߳�
//            if (!f1_input)
//            {
//                time_end = high_resolution_clock::now();
//                return;
//            }
//        }
//    }
//}
//void put_in()
//{
//    int i;
//    cout << " ��������Ϊ��" << endl;
//    for (i = 0; i < 8; i++)
//    {
//        x[i] = i;
//        y[i] = i;
//    }
//    for (i = 0; i < 8; i++)
//    {
//        cout << fixed << setprecision(6) << setw(10) << x[i] << " + " << setiosflags(ios::right) << setw(10) << y[i] << "j   ";
//        if (i % 4 == 3)
//        {
//            cout << endl;
//        }
//    }
//    cout << endl << endl;
//}
//void re_bit()
//{
//    float q11, q12, q21, q22;
//    cout << "��������֮�������Ϊ��" << endl;
//
//    q11 = x[1];
//    q12 = y[1];
//    x[1] = x[4];
//    y[1] = y[4];
//    x[4] = q11;
//    y[4] = q12;
//
//    q21 = x[3];
//    q22 = y[3];
//    x[3] = x[6];
//    y[3] = y[6];
//    x[6] = q21;
//    y[6] = q22;
//
//    for (int i = 0; i < 8; i++)
//    {
//        cout << fixed << setprecision(6) << setw(10) << x[i] << " + " << setiosflags(ios::right) << setw(10) << y[i] << "j   ";
//        if (i % 4 == 3)
//        {
//            cout << endl;
//        }
//    }
//    cout << endl << endl;
//}
//int main()
//{
//    put_in();
//    re_bit();
//    thread level_1(butterfly1), level_2(butterfly2), level_3(butterfly3);
//
//    level_1.join();
//    level_2.join();
//    level_3.join();
//
//    cout << " �������Ϊ��" << endl;
//    for (int i = 0; i < 8; i++)
//    {
//        cout << fixed << setprecision(6) << setw(10) << x[i] << " + " << setiosflags(ios::right) << setw(10) << y[i] << "j   ";
//        if (i % 4 == 3)
//        {
//            cout << endl;
//        }
//    }
//    cout << endl << endl;
//
//    cout << "����ʱ��: " << duration_cast<microseconds>(time_end - time_begin).count() << "΢��" << endl;
//    system("pause");
//    return 0;
//}