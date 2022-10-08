#include <iostream>

using namespace std;

int main()
{
    int n, x = 0;
    cin >> n;
    string statement;
    for (int i = 0; i < n; i++)
    {
        cin >> statement;
        if (statement[0] == '+' || statement[statement.length() - 1] == '+')
        {
            x++;
        }
        else if (statement[0] == '-' || statement[statement.length() - 1] == '-')
        {
            x--;
        }
    }
    cout << x;

    return 0;
}