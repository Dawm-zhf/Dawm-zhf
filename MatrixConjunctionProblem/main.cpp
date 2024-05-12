#include "MatrixConjunction.h"
#include <iostream>

int main()
{
    int m[N][N];
    int s[N][N];
    int p[] = {30,35,15, 2,10,20,25};
    matrixConjunction(m, s, p, N-1);
    cout << "最小代价对应的矩阵连乘顺序:" << endl;
    toPrint(1, 6, s);

    return 0;
}