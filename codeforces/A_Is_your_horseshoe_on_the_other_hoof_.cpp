#include <iostream>

using namespace std;

int main()
{
    int a[4], x, flag, count = 0, k = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        flag = 0;
        for (int i = 0; i < count; i++)
        {
            if (a[i] == x)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            k++;
        a[count] = x;
        count++;
    }
    cout << 4 - k;
    return 0;
}
