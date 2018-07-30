//#include <math.h>
//#include <time.h>
//#include <windows.h>
//#include <conio.h>
//#include"omp.h" 
//#include <stdio.h>
//#define p 3.1416
//
//float x[8];
//float y[8];
//
//void put_in();
//void re_bit();
//void butterfly1();
//void butterfly2();
//void butterfly3();
//
//int main()
//{
//
//
//    double run_time;
//    _LARGE_INTEGER time_start;  //��ʼʱ��  
//    _LARGE_INTEGER time_over;   //����ʱ��  
//    double dqFreq;      //��ʱ��Ƶ��  
//    LARGE_INTEGER f;    //��ʱ��Ƶ��  
//    QueryPerformanceFrequency(&f);
//    dqFreq = (double)f.QuadPart;
//    QueryPerformanceCounter(&time_start);   //��ʱ��ʼ������
//
//    put_in();
//    re_bit();
//    butterfly1();
//    butterfly2();
//    butterfly3();
//
//
//    QueryPerformanceCounter(&time_over);    //��ʱ����������  
//    run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
//
//
//    printf(" �������Ϊ��\n");
//    for (int i = 0; i < 8; i++)
//        printf(" %f+j%f ", x[i], y[i]);
//    printf("\n\n");
//    //getchar();
//
//    printf("\nrun_time��%fus\n", run_time);
//    system("pause");
//    return 0;
//}
//void put_in()
//{
//    int i;
//    printf(" ��������Ϊ��\n");
//    for (i = 0; i < 8; i++)
//    {
//        x[i] = i;
//        y[i] = i;
//    }
//    for (i = 0; i < 8; i++)
//    {
//        printf(" %f+j%f ", x[i], y[i]);
//    }
//    printf("\n\n");
//}
//void re_bit()
//{
//    float q11, q12, q21, q22;
//    printf("��������֮�������Ϊ��\n");
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
//        printf(" %f+j%f ", x[i], y[i]);
//    }
//    printf("\n\n");
//}
//void butterfly1()
//{
//    float u, v;
//    int m1 = 1;//��һ����ÿ����Ⱥ���������������ÿ����Ⱥ��1�������
//    int m2 = 2 * m1;//��һ���е�Ⱥ���ȡ���Ϊ2
//    int m3 = 4;//��һ���еĵ�Ⱥ��������Ϊ4��
//
//               //����ÿ����Ⱥ��˵
//    for (int j = 0; j < m3; j++)
//    {
//        int m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//
//                        //����ÿ����Ⱥ��ÿ���������˵
//        for (int r = 0; r < m1; r++)
//        {
//            int k1 = m4 + r;   //��������������ڱ�
//            int k2 = k1 + m1;  //��������������ڱ�
//            u = x[k2] * cos(2 * p * r / m2) + y[k2] * sin(2 * p * r / m2);
//            v = y[k2] * sin(2 * p * r / m2) - x[k2] * cos(2 * p * r / m2);
//            x[k2] = x[k1] - u;
//            y[k2] = y[k1] - v;
//            x[k1] = x[k1] + u;
//            y[k1] = y[k1] + v;
//        }
//    }
//}
//void butterfly2()
//{
//    float u, v;
//    int m1 = 2;//�ڶ�����ÿ����Ⱥ���������������ÿ����Ⱥ��2�������
//    int m2 = 2 * m1;//�ڶ����е�Ⱥ���ȡ���Ϊ4
//    int m3 = 2;//�ڶ����еĵ�Ⱥ��������Ϊ2��
//
//               //����ÿ����Ⱥ��˵
//    for (int j = 0; j < m3; j++)
//    {
//        int m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//
//                        //����ÿ����Ⱥ��ÿ���������˵
//        for (int r = 0; r < m1; r++)
//        {
//            int k1 = m4 + r;   //��������������ڱ�
//            int k2 = k1 + m1;  //��������������ڱ�
//            u = x[k2] * cos(2 * p * r / m2) + y[k2] * sin(2 * p * r / m2);
//            v = y[k2] * sin(2 * p * r / m2) - x[k2] * cos(2 * p * r / m2);
//            x[k2] = x[k1] - u;
//            y[k2] = y[k1] - v;
//            x[k1] = x[k1] + u;
//            y[k1] = y[k1] + v;
//        }
//    }
//}
//void butterfly3()
//{
//    float u, v;
//    int m1 = 4;//��������ÿ����Ⱥ���������������ÿ����Ⱥ��4�������
//    int m2 = 2 * m1;//�������е�Ⱥ���ȡ���Ϊ8
//    int m3 = 1;//�ڶ����еĵ�Ⱥ��������Ϊ1��
//
//               //����ÿ����Ⱥ��˵
//    for (int j = 0; j < m3; j++)
//    {
//        int m4 = j * m2;//��Ⱥַ����ÿ����Ⱥ���ϽǱ��
//
//
//                        //����ÿ����Ⱥ��ÿ���������˵
//        for (int r = 0; r < m1; r++)
//        {
//            int k1 = m4 + r;   //��������������ڱ�
//            int k2 = k1 + m1;  //��������������ڱ�
//
//            u = x[k2] * cos(2 * p * r / m2) + y[k2] * sin(2 * p * r / m2);
//            v = y[k2] * sin(2 * p * r / m2) - x[k2] * cos(2 * p * r / m2);
//            x[k2] = x[k1] - u;
//            y[k2] = y[k1] - v;
//            x[k1] = x[k1] + u;
//            y[k1] = y[k1] + v;
//        }
//    }
//}