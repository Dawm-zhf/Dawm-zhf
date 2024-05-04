#include "MultilevelScheduling.h"
using namespace std;
int main()
{

    int id[] = {1,2,3,4,5,6,7};
    int time[] = {2,14,4,16,6,5,3};
    int len = sizeof(id)/sizeof(id[0]);
    multilevelScheduling(id, time, len);
    return 0;
}