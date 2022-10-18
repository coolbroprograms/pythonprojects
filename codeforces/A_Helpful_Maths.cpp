#include <iostream>

using namespace std;

int main()
{
    int n_1 = 0, n_2 = 0, n_3 = 0;
    string in;
    cin >> in;
    for (int i = 0; i < in.length(); i += 2)
    {
        if (in[i] == '1')
            n_1++;
        if (in[i] == '2')
            n_2++;
        if (in[i] == '3')
            n_3++;
    }
    for (int i = 0; i < n_1 + n_2 + n_3; i++)
    {
        if (i != 0)
            cout << '+';
        if (i < n_1)
            cout << '1';
        else if (n_1 <= i && i < n_1 + n_2)
            cout << '2';
        else if (n_1 + n_2 <= i && i <= n_1 + n_2 + n_3)
            cout << '3';
    }
    return 0;
}
