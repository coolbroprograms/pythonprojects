#include <iostream>

using namespace std;

int main()
{
    int t, n, flag;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        int x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (x[i] <= x[i + 1])
                flag = 1;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}