#include <iostream>

using namespace std;

int main()
{
    long long a, b, n, count = 0;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if ((a * 10 + j) % b == 0)
            {
                a = a * 10 + j;
                count++;
                break;
            }
        }
    }
    if (count == n)
    {
        cout << a;
    }
    else
    {
        cout << -1;
    }

    return 0;
}