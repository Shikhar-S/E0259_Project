#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b)!=1)cout<<"Infinite\n";
       else cout<<"Finite\n";
    }
    return 0;
}
