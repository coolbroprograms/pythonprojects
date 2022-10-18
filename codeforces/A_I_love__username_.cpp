#include <iostream>

using namespace std;

int main()
{
    int n, x, max = 0, min, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i == 0)
        {
            max = x;
            min = x;
        }
        else if (x > max)
        {
            max = x;
            count++;
        }
        else if (x < min)
        {
            min = x;
                count++;
            
        }
    }
    cout << count;

    return 0;
}