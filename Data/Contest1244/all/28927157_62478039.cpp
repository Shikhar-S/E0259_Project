#include<bits/stdc++.h>
using namespace std;




int main(int argc, char *argv[]){
    
    long long n,p,w,d;cin>>n>>p>>w>>d;
    
    long long MAX = w*n;
    if(p > MAX){
        cout<<-1;
        return 0;
    }
    long long x = 0;
    long long y = 0;
    long long z = 0;
    
    for(int i = 0;i<1234567;i++){
        if(p - i*d < 0){
            cout<<-1;
            return 0;
        }
        if( (p-i*d)%w == 0 ){
            x = (p-i*d)/w;
            y = i;
            z = n -x - y;
            if(z < 0){
                cout<<-1;
            }else{
                cout<<x<<" "<<y<<" "<<z;
            }
            return 0;
        }
    }
    cout<<-1;

   
    return 0;
}