#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int pens = a/c + bool(a%c);
        int pencils = b/d + bool(b%d);
        int all = pens+pencils;
        if (all > k)
            puts("-1");
        else printf("%d %d\n", pens, pencils);
    }

	return 0;
}
