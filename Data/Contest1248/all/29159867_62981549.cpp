#include<bits/stdc++.h>
using namespace std;
int p[100010];
int q[100010];

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int even1 = 0;

        for(int i=0;i<n;i++){
            cin>>p[i];

            if(p[i]%2==0){
                even1++;
            }
        }

        int odd1 = n-even1;

        int m;
        cin>>m;

        int even2=0;

        for(int i=0;i<m;i++){
            cin>>q[i];

            if(q[i]%2==0){
                even2++;
            }
        }

        int odd2 = m-even2;

        long long ans = 1LL*even1*even2 + 1LL*odd1*odd2;

        cout<<ans<<endl;
    }
    
}