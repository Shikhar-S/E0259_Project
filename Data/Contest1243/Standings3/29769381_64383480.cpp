#include<bits/stdc++.h>
using namespace std;
char s[10004], t[10004], c1[5], c2[5];
int main()
{
    int ts, n;
    scanf("%d", &ts);
    while(ts--)
    {
        scanf("%d %s %s", &n, s, t);
        int cnt= 0;
        for(int i=0; i<n && cnt<=3; i++)
            if(s[i]!=t[i])
            {
                c1[cnt]= s[i];
                c2[cnt]= t[i];
                cnt++;
            }
        if(!cnt || (cnt==2 && c1[0]==c1[1] && c2[0]==c2[1]))printf("Yes\n");
        else printf("No\n");
    }return 0;
}
