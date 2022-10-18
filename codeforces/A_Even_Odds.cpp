#include <iostream>

using namespace std;

int main()
{
    long long mid, n, k;
    cin >> n >> k;
    if (n % 2)
        mid = n / 2 + 1;
    else
        mid = n / 2;
    if (k <= mid)
        cout << 2 * k - 1;
    else
        cout << 2 * (k - mid);
    return 0;
}