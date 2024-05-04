#ifndef MULTILEVELSCHEDULINGPROBLEM_MULTILEVELSCHEDULING_H
#define MULTILEVELSCHEDULINGPROBLEM_MULTILEVELSCHEDULING_H

//头文件的加载
#include <iostream>
#include <vector>

//命名空间
using namespace std;

//编写作业结构体
typedef struct Course
{
    int id;//作业标记
    int time;//作业运行需要的时间
} Course;

//编写机器结构体
typedef struct Machine
{
    vector<Course> array;
    int machineTime = 0;
} Machine;


//函数的声明
void multilevelScheduling(const int id[], const int time[], int len);
void toCompare(Course *course, int len);
void swap(Course *course, int i, int j);
void toPrint(Machine *machine);
void courseTask(Course *course, Machine *machine, int len);
int fineCourse(Machine *machine);
#endif //MULTILEVELSCHEDULINGPROBLEM_MULTILEVELSCHEDULING_H
