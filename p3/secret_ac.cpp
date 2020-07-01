#include <iostream>
#include <cstdlib>
#include <math.h>

#define ll long long
using namespace std;

ll k;
int n_max = 2e6;
int minimum = 2;
int maximum = n_max;
int mid;
int *a = (int *)malloc(sizeof(int) * n_max);

int judge(int n)
{

    ll r = n + k;
    ll x = -1;
    for (int i = 1; i < n + 1; i++)
    {
        x = ceil((double)r / (i + 1));
        a[i] = i - (r - 1) % (i + 1);
        r -= x;
        if (r == 0 && i == n)
            return 0;
        if (r == 0)
            return 1;
    }
    return -1;
}
bool f4(int minimum, int maximum)
{

    while (minimum <= maximum)
    {
        mid = (minimum + maximum) / 2;
        int r = judge(mid);
        if (r == -1)
            minimum = mid + 1;
        else if (r == 1)
        {
            maximum = mid - 1;
        }
        else
            return true;
    }
    return false;
}

int main()
{
    cin >> k;
    bool result = -1;
    result = f4(minimum, maximum);
    int n = mid;
    if (result)
    {
        cout << n << endl;
        for (int i = 1; i < n + 1; i++)
        {
            cout<<a[i]<<' ';
        }
    }
    else
    {
        cout << "Daydream!" << endl;
    }
}
