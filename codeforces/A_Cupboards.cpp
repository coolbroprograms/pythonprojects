#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int l, r, l_close = 0, r_close = 0, l_open = 0, r_open = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        if (l)
            l_close++;
        else
            l_open++;

        if (r)
            r_close++;
        else
            r_open++;
    }
    if (l_close > l_open)
        ans += l_open;
    else 
        ans += l_close;
    if (r_close > r_open)
        ans += r_open;
    else 
        ans += r_close;
    cout<<ans;
    return 0;
}