#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m, t, o1 = 0, e1 = 0, o2 = 0, e2 = 0;

        cin >> n;
        while (n--)
            cin >> t, o1 += t % 2, e1 += (t % 2 == 0);
        cin >> m;
        while (m--)
            cin >> t, o2 += t % 2, e2 += (t % 2 == 0);

        cout << o1 * o2 + e1 * e2 << '\n';
    }

    return 0;
}

//      *   *  *****  *   *  *   *
//     *   *  *      **  *  *   *
//    *****  *****  * * *  *   *
//   *   *      *  *  **  *   *
//  *   *  *****  *   *   ***
//     *****  *****  *****
//    *      *   *  *
//   *      *****  *
//  *      *  *   *
//  ***** *   *   *****
