/*
给定一个数组序列, 需要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：

区间中的最小数 * 区间所有数的和最后程序输出经过计算后的最大值即可，不需要输出具体的区间。如给定序列  [6 2 1]则根据上述公式, 可得到所有可以选定各个区间的计算值:

 

[6] = 6 * 6 = 36;

[2] = 2 * 2 = 4;

[1] = 1 * 1 = 1;

[6,2] = 2 * 8 = 16;

[2,1] = 1 * 3 = 3;

[6, 2, 1] = 1 * 9 = 9;

 

从上述计算可见选定区间 [6] ，计算值为 36， 则程序输出为 36。

区间内的所有数字都在[0, 100]的范围内;

解法：以第i个元素为最小值分别向两边扩大区间至最大，算出该元素与区间内所有数的和的
乘积f(i)，遍历所有元素，更新f(i)即可。
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int x[n];
        for (int i=0; i<n; i++)
            cin>>x[i];
        int max=0;
        for (int i=0; i<n; i++)
        {
            int j=i;
            int k=i-1;
            int sum1=0;
            while(x[i]<=x[j] && j<n)
            {
                sum1+=x[j];
                j++;
            }
            while(x[i]<=x[k] && k>=0)
            {
                sum1+=x[k];
                k--;
            }
            int temp=sum1;
            if (x[i]*temp>max)
                max=x[i]*temp;

        }
        cout << max << endl;
    }
    return 0;
}
