#include <iostream>
using namespace std;

int main()
{
    int n, x, sum = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
    }
    for (int i = 1; i <= 5; i++)
    {
        if ((sum + i) % (n + 1) != 1)
        {
            count++;
        };
    }
    cout << count;

    return 0;
}