#include <iostream> // C++ I/O
#include <string>   // C++ string
#include <fstream>  // File I/O
#include <sstream>  // String stream I/O
#include <iomanip>  // C++ I/O manipulator

#include <cstdlib> // C library
#include <cstdio>  // C I/O
#include <ctime>   // C time
#include <cmath>   // Math library
#include <cstring> // C strings

#include <vector>    // Vector
#include <queue>     // Queue
#include <stack>     // Stack
#include <map>       // Map
#include <set>       // Set
#include <bitset>    // Bitset
#include <algorithm> // Algorithms

using namespace std;

#define INF 0x3f3f3f3f
#define EPS 1e-8

typedef long long ll;
typedef unsigned long long ull;

#define memclr(_var) memset(_var, 0, sizeof(_var))
#define maximize(_var, _cur) _var = max(_var, _cur)
#define minimize(_var, _cur) _var = min(_var, _cur)
#define reps(_var, _begin, _end, _step) for (int _var = (_begin); _var <= (_end); _var += (_step))
#define reps_(_var, _end, _begin, _step) for (int _var = (_end); _var >= (_begin); _var -= (_step))
#define rep(_var, _begin, _end) reps(_var, _begin, _end, 1)
#define rep_(_var, _end, _begin) reps_(_var, _end, _begin, 1)

inline int read()
{
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

const int MAXN = 310;
int res[MAXN][MAXN];

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = read();

    rep (i, 1, n)
    {
        if (i & 1)
            rep (j, 1, n)
                res[i][j] = (i - 1) * n + j;
        else
            rep (j, 1, n)
                res[i][n - j + 1] = (i - 1) * n + j;
    }    

    rep (j, 1, n)
    {
        rep (i, 1, n)
            printf("%d ", res[i][j]);
        putchar('\n');
    }

    return 0;
}