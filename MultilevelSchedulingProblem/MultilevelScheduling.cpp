#include "MultilevelScheduling.h"


void multilevelScheduling(const int id[], const int time[], int len)
{
    /*
     * 使用贪心算法的思想实现多机调度问题
     * */

    /*
     * 题目描述：
     *      假设有N个作业需要需要被处理，并且有m台相同的机器可以使用，每一个作业都可以在任意一台机器上运行，
     *    但是一但开始处理，未完成之前不允许中断或者拆分到其他机器上处理。
     *      目标：找到一种作业调度方案，使得这n个作业能够在尽可能短的时间内有m台机器加工处理完成
     * */

    /*
     * 算法思路：
     *      使用贪心的算法的思想，优先处理
     * */
    //创建作业结构体数组
    Course course[len];

    //定义机器结构体数组
    Machine machine[3];


    //作业结构体初始化
    for (int i=0; i<len; i++)
    {
        course[i].id = id[i];
        course[i].time = time[i];
    }

    //排序:按照time属性对数组进行排序
    toCompare(course, len);

    //按照贪心的思想，对作业进行分配
    courseTask(course, machine, len);

    //将最终的结果输出
    toPrint(machine);
}

//作业分配函数
void courseTask(Course *course, Machine *machine, int len)
{
    for (int i=0; i<len; i++)
    {
        Course temp = course[i];
        int num = fineCourse(machine);
        machine[num].machineTime += temp.time;
        machine[num].array.push_back(temp);
    }
}

//排序函数
void toCompare(Course *course, int len)
{
    for (int i=0;i<len;i++)
    {
        for (int j=0;j<len;j++)
        {
            if(course[i].time>course[j].time)
            {
                swap(course, i, j);
            }
        }
    }
}

//交换函数
void swap(Course *course, int i, int j)
{
    Course temp;
    temp = course[i];
    course[i] = course[j];
    course[j] = temp;
}


//信息输出函数
void toPrint(Machine machine[])
{
    //1号机器的作业安排
    cout << "1号机器的安排" << endl;
    for (Course & element : machine[0].array)
    {
        cout << element.id << "\t";
    }
    cout << endl;
    //2号机器的作业安排
    cout << "2号机器的安排" << endl;
    for (Course & element : machine[1].array)
    {
        cout << element.id << "\t";
    }
    cout << endl;
    //3号机器的作业安排
    cout << "3号机器的安排" << endl;
    for (Course & element : machine[2].array)
    {
        cout << element.id << "\t";
    }
    cout << endl;
}
//寻找最小值函数
int fineCourse(Machine *machine)
{
    int min = machine[0].machineTime;

    for (int i=0; i<3; i++)
    {
        if(machine[i].machineTime<min)
        {
            min = i;
        }
    }

    return min;
}