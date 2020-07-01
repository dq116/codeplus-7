#include <iostream>
#include <cstdlib>
using namespace std;

int n_max = 2e6;
int *a = (int *)malloc(sizeof(int) * n_max);
int k;
int n = 2;

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

int main()
{

    cin >> k;

    bool r = f2();
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
