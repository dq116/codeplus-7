#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;

ll k;
int n = 2;
int n_max = 2e6;
int low = 2;
int high = n_max;
int mid;
int *a = (int *)malloc(sizeof(int) * n_max);

int find_first_zero(int begin, int end)
{
    int first_zero = -1;
    for (int i = begin; i < end; i++)
    {
        if (a[i] == 0)
        {
            first_zero = i;
            break;
        }
    }
    return first_zero;
}

bool f2()
{
    int counter = 0;
    n = 2;
    int begin = 1;
    int end = n + 1;
    while (n <= n_max)
    {
        int first_zero = find_first_zero(begin, end);
        if (first_zero == -1)
        {
            n += 1;
            begin = end;
            end += 1;
            continue;
        }

        a[first_zero] = first_zero;
        counter += 1;
        if ((a[n] == n) && (counter == n + k))
        {
            for (int i = 1; i < first_zero; i++)
            {
                a[i] -= 1;
            }

            return true;
        }
        for (int i = 1; i < first_zero; i++)
        {
            a[i] -= 1;
        }
        begin = 1;
    }
    return false;
}
ll total_times(int n)
{
    ll c = 0;
    ll x = -1;
    for (int i = n; i >= 1; i--)
    {
        x = c / i + 1;
        a[i] = (i)-c % i;
        c += x;
    }

    return c;
}
bool f3(int low, int high)
{
    while (low <= high)
    {
        mid = (low + high) / 2;
        ll c = total_times(mid);
        if (c < mid + k)
            low = mid + 1;
        else if (c > mid + k)
        {
            high = mid - 1;
        }
        else
            return true;
    }
    return false;
}

int main()
{
    cin >> k;
    bool r = -1;
    if (k <= 1e6)
        r = f2();
    else
    {
        r = f3(low, high);
        n = mid;
    }
    if (r)
    {
        cout << n << endl;
        for (int i = 1; i < n + 1; i++)
        {
            cout << a[i] << ' ';
        }
    }
    else
    {

        cout << "Daydream!" << endl;
    }
}
