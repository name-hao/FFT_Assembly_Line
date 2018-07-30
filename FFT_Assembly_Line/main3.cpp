//#include <thread>
//#include <atomic> 
//#include <chrono>
//#include <iostream>
//#include <condition_variable> 
//#include <string>
//#include <vector>
//#include <iomanip>
//#include <array>
//#include <numeric>
//#include "concurrent_queue.h"
//using namespace std;
//using namespace std::chrono;
//using std::string;
//using std::vector;
//using std::array;
//using std::mutex;
//using std::condition_variable;
//using std::thread;
//using std::ref;
//using namespace moodycamel;
//
//typedef struct Node
//{
//    array<double, 8> x;
//    array<double, 8> y;
//    Node() :
//        x{ 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 },
//        y{ 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 }
//    {}
//}Node;
//
//vector<Node> allNodes{};
//size_t biggest_index{ 0 };
//ConcurrentQueue<int> buffer1_2(100);
//ConcurrentQueue<int> buffer2_3(100);
//
//double x[8], y[8];
//const double p = 3.1416;
//
//decltype(high_resolution_clock::now()) time_begin, time_end;
//
//void butterfly1()
//{
//    double u, v, cos_result, sin_result;
//    int i, m1, m2, m3, m4, j, r, k1, k2;
//    time_begin = high_resolution_clock::now();
//
//    while (true)
//    {
//        //�����ݵ�ʱ������д���
//        for (i = 0; i < allNodes.size(); i++)
//        {
//            //��ʼ����ÿ������
//            
//            m1 = 1;//��һ����ÿ����Ⱥ���������������ÿ����Ⱥ��1�������
//            m2 = 2 * m1;//��һ���е�Ⱥ���ȡ���Ϊ2
//            m3 = 4;//��һ���еĵ�Ⱥ��������Ϊ4��
//
//                       //����ÿ����Ⱥ��˵
//            for (j = 0; j < m3; j++)
//            {
//                m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//
//                                //����ÿ����Ⱥ��ÿ���������˵
//                for (r = 0; r < m1; r++)
//                {
//                    k1 = m4 + r;   //��������������ڱ�
//                    k2 = k1 + m1;  //��������������ڱ�
//                    cos_result = cos(2 * p * r / m2);
//                    sin_result = sin(2 * p * r / m2);
//                    u = allNodes[i].x[k2] * cos_result + allNodes[i].y[k2] * sin_result;
//                    v = allNodes[i].y[k2] * sin_result - allNodes[i].x[k2] * cos_result;
//                    allNodes[i].x[k2] = allNodes[i].x[k1] - u;
//                    allNodes[i].y[k2] = allNodes[i].y[k1] - v;
//                    allNodes[i].x[k1] = allNodes[i].x[k1] + u;
//                    allNodes[i].y[k1] = allNodes[i].y[k1] + v;
//                }
//            }
//            buffer1_2.enqueue(i);
//        }
//        //cout << "��һ���������" << endl;
//        return;
//    }
//}
//void butterfly2()
//{
//    int index{ 0 }, m1, m2, m3, m4, j, r, k1, k2;
//    bool result;
//    double u, v, cos_result, sin_result;
//    while (true)
//    {
//        result = buffer1_2.try_dequeue(index);
//        if (result)
//        {
//            //cout << endl << "ȡ����index: " << index << endl;
//            
//            m1 = 2;//�ڶ�����ÿ����Ⱥ���������������ÿ����Ⱥ��2�������
//            m2 = 2 * m1;//�ڶ����е�Ⱥ���ȡ���Ϊ4
//            m3 = 2;//�ڶ����еĵ�Ⱥ��������Ϊ2��
//
//                       //����ÿ����Ⱥ��˵
//            for (j = 0; j < m3; j++)
//            {
//                m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//                //����ÿ����Ⱥ��ÿ���������˵
//                for (r = 0; r < m1; r++)
//                {
//                    k1 = m4 + r;   //��������������ڱ�
//                    k2 = k1 + m1;  //��������������ڱ�
//                    cos_result = cos(2 * p * r / m2);
//                    sin_result = sin(2 * p * r / m2);
//                    u = allNodes[index].x[k2] * cos_result + allNodes[index].y[k2] * sin_result;
//                    v = allNodes[index].y[k2] * sin_result - allNodes[index].x[k2] * cos_result;
//                    allNodes[index].x[k2] = allNodes[index].x[k1] - u;
//                    allNodes[index].y[k2] = allNodes[index].y[k1] - v;
//                    allNodes[index].x[k1] = allNodes[index].x[k1] + u;
//                    allNodes[index].y[k1] = allNodes[index].y[k1] + v;
//                }
//            }
//            buffer2_3.enqueue(index);
//            if (index == biggest_index)
//            {
//                //cout << "�����������һ�����ݣ������˳�" << endl;
//                return;
//            }
//        }
//    }
//}
//void butterfly3()
//{
//    int index{ 0 }, m1, m2, m3, m4, k1, k2,j,r;
//    bool result;
//    double u, v, cos_result, sin_result;
//    while (true)
//    {
//        result = buffer2_3.try_dequeue(index);
//        if (result)
//        {
//            
//            m1 = 4;//��������ÿ����Ⱥ���������������ÿ����Ⱥ��4�������
//            m2 = 2 * m1;//�������е�Ⱥ���ȡ���Ϊ8
//            m3 = 1;//�ڶ����еĵ�Ⱥ��������Ϊ1��
//
//            //����ÿ����Ⱥ��˵
//            for (j = 0; j < m3; j++)
//            {
//                m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//                //����ÿ����Ⱥ��ÿ���������˵
//                for (r = 0; r < m1; r++)
//                {
//                    k1 = m4 + r;   //��������������ڱ�
//                    k2 = k1 + m1;  //��������������ڱ�
//                    cos_result = cos(2 * p * r / m2);
//                    sin_result = sin(2 * p * r / m2);
//                    u = allNodes[index].x[k2] * cos_result + allNodes[index].y[k2] * sin_result;
//                    v = allNodes[index].y[k2] * sin_result - allNodes[index].x[k2] * cos_result;
//                    allNodes[index].x[k2] = allNodes[index].x[k1] - u;
//                    allNodes[index].y[k2] = allNodes[index].y[k1] - v;
//                    allNodes[index].x[k1] = allNodes[index].x[k1] + u;
//                    allNodes[index].y[k1] = allNodes[index].y[k1] + v;
//                }
//            }
//            //���������һ�����ݣ������̣߳�ֹͣ��ʱ
//            if (index == biggest_index)
//            {
//                time_end = high_resolution_clock::now();
//                return;
//            }
//        }
//    }
//}
//void show_first_info()
//{
//    for (int i = 0; i < 8; i++)
//    {
//        cout << fixed << setprecision(6) << setw(10) << allNodes[0].x[i] << " + " << setiosflags(ios::right) << setw(10) << allNodes[0].y[i] << "j   ";
//        if (i % 4 == 3)
//        {
//            cout << endl;
//        }
//    }
//}
//void re_put()
//{
//    for (int i = 0; i < biggest_index+1; i++)
//    {
//        allNodes.emplace_back();
//    }
//    double q11, q12, q21, q22;
//    for (Node& node : allNodes)
//    {
//        q11 = node.x[1];
//        q12 = node.y[1];
//        node.x[1] = node.x[4];
//        node.y[1] = node.y[4];
//        node.x[4] = q11;
//        node.y[4] = q12;
//
//        q21 = node.x[3];
//        q22 = node.y[3];
//        node.x[3] = node.x[6];
//        node.y[3] = node.y[6];
//        node.x[6] = q21;
//        node.y[6] = q22;
//    }
//}
//void put_in()
//{
//    int num_of_nodes{ 0 };
//    cout << "���������Ϊ: ";
//    cin >> num_of_nodes;
//    for (int i = 0; i < num_of_nodes; i++)
//    {
//        allNodes.emplace_back();
//    }
//    cout << endl << "��������Ϊ��" << endl; 
//    show_first_info();
//    cout << endl << endl;
//}
//void re_bit()
//{
//    double q11, q12, q21, q22;
//    cout << "��������֮�������Ϊ��" << endl;
//    for (Node& node: allNodes )
//    {
//        q11 = node.x[1];
//        q12 = node.y[1];
//        node.x[1] = node.x[4];
//        node.y[1] = node.y[4];
//        node.x[4] = q11;
//        node.y[4] = q12;
//
//        q21 = node.x[3];
//        q22 = node.y[3];
//        node.x[3] = node.x[6];
//        node.y[3] = node.y[6];
//        node.x[6] = q21;
//        node.y[6] = q22;
//    }
//    show_first_info();
//    cout << endl << endl;
//}
//
//int main()
//{
//    put_in();
//    re_bit();
//    biggest_index = allNodes.size() - 1;
//    thread level_1(butterfly1), level_2(butterfly2), level_3(butterfly3);
//
//    level_1.join();
//    level_2.join();
//    level_3.join();
//
//    cout << "�������Ϊ��" << endl;
//    show_first_info();
//    cout << endl << endl;
//    cout << "����ʱ��: " << duration_cast<microseconds>(time_end - time_begin).count() << "΢��" << endl;
//    system("pause");
//    return 0;
//}