#ifndef MULTILEVELSCHEDULINGPROBLEM_MULTILEVELSCHEDULING_H
#define MULTILEVELSCHEDULINGPROBLEM_MULTILEVELSCHEDULING_H

//ͷ�ļ��ļ���
#include <iostream>
#include <vector>

//�����ռ�
using namespace std;

//��д��ҵ�ṹ��
typedef struct Course
{
    int id;//��ҵ���
    int time;//��ҵ������Ҫ��ʱ��
} Course;

//��д�����ṹ��
typedef struct Machine
{
    vector<Course> array;
    int machineTime = 0;
} Machine;


//����������
void multilevelScheduling(const int id[], const int time[], int len);
void toCompare(Course *course, int len);
void swap(Course *course, int i, int j);
void toPrint(Machine *machine);
void courseTask(Course *course, Machine *machine, int len);
int fineCourse(Machine *machine);
#endif //MULTILEVELSCHEDULINGPROBLEM_MULTILEVELSCHEDULING_H
