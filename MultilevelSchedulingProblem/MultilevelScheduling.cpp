#include "MultilevelScheduling.h"


void multilevelScheduling(const int id[], const int time[], int len)
{
    /*
     * ʹ��̰���㷨��˼��ʵ�ֶ����������
     * */

    /*
     * ��Ŀ������
     *      ������N����ҵ��Ҫ��Ҫ������������m̨��ͬ�Ļ�������ʹ�ã�ÿһ����ҵ������������һ̨���������У�
     *    ����һ����ʼ����δ���֮ǰ�������жϻ��߲�ֵ����������ϴ���
     *      Ŀ�꣺�ҵ�һ����ҵ���ȷ�����ʹ����n����ҵ�ܹ��ھ����̵ܶ�ʱ������m̨�����ӹ��������
     * */

    /*
     * �㷨˼·��
     *      ʹ��̰�ĵ��㷨��˼�룬���ȴ���
     * */
    //������ҵ�ṹ������
    Course course[len];

    //��������ṹ������
    Machine machine[3];


    //��ҵ�ṹ���ʼ��
    for (int i=0; i<len; i++)
    {
        course[i].id = id[i];
        course[i].time = time[i];
    }

    //����:����time���Զ������������
    toCompare(course, len);

    //����̰�ĵ�˼�룬����ҵ���з���
    courseTask(course, machine, len);

    //�����յĽ�����
    toPrint(machine);
}

//��ҵ���亯��
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

//������
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

//��������
void swap(Course *course, int i, int j)
{
    Course temp;
    temp = course[i];
    course[i] = course[j];
    course[j] = temp;
}


//��Ϣ�������
void toPrint(Machine machine[])
{
    //1�Ż�������ҵ����
    cout << "1�Ż����İ���" << endl;
    for (Course & element : machine[0].array)
    {
        cout << element.id << "\t";
    }
    cout << endl;
    //2�Ż�������ҵ����
    cout << "2�Ż����İ���" << endl;
    for (Course & element : machine[1].array)
    {
        cout << element.id << "\t";
    }
    cout << endl;
    //3�Ż�������ҵ����
    cout << "3�Ż����İ���" << endl;
    for (Course & element : machine[2].array)
    {
        cout << element.id << "\t";
    }
    cout << endl;
}
//Ѱ����Сֵ����
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