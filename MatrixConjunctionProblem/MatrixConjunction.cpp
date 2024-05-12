#include "MatrixConjunction.h"

/*
 * 问题：矩阵连乘
 * 问题描述：
 *      给定一个矩阵链 <A1, A2, ..., An>，其中每个矩阵 Ai 的维数是 pi-1 x pi（表示 Ai 有 pi-1 行和 pi 列）。矩阵链的连乘结果是从 A1
 *  开始，依次乘以 A2，A3，...，直到 An。因为矩阵乘法满足结合律，所以矩阵链的连乘可以有多种不同的计算顺序。
 *
 *      问题的目标是找到一种计算顺序，使得总的计算量（即数乘次数）达到最小。这里的计算量通常通过数乘次数来衡量，因为数乘是矩阵乘法中最耗时的操作。
 * */

/*
 * 使用动态规划的思路解决矩阵连乘问题
 * */

void matrixConjunction(int m[][N], int s[][N], const int *p, int n)
{
    for (int i=1; i<=n; i++) //当矩阵链中只有一个矩阵的时候，代价为0
    {
        m[i][i] = 0;
    }

    for (int r=2; r<=n; r++) //r代表矩阵链的长度
    {
        for (int i=1;i<=n-r+1;i++)
        {
            int j = i+(r-1);
            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;

            for (int k=i+1;k<j;k++) //寻找最小代价
            {
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (t < m[i][j])
                {
                    s[i][j] = k;
                    m[i][j] = t;
                }
            }
        }

    }
}

void toPrint(int i, int j, int s[][N]) //通过递归的方法输出最佳连乘顺序
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(" ;
        toPrint(i, s[i][j], s);
        toPrint(s[i][j]+1, j, s);
        cout << ")";
    }
}