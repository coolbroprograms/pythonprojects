#include <iostream>

using namespace std;

int main()
{
    int n, x, max = 0, min = 0, max_i, min_i;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > max)
        {
            max = x;
            max_i = i;
        }
        if (!min)
        {
            min = x;
        }
        if (x < min)
        {
            min = x;
        }
        if (x == min)
        {
            min_i = i;
        }
    }
    if (max_i > min_i)
    {
        cout << max_i + (n - 1 - min_i) - 1;
    }
    else
    {
        cout << max_i + (n - 1 - min_i);
    }

    return 0;
}