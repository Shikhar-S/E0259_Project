#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define takeline cin.ignore();
#define sc second
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		ll i,j,k,l,n;
		cin>>n;
		char ar[n+1];
		cin>>ar;
		if(ar[0]=='1'||ar[n-1]=='1'){
			cout<<(2*n)<<endl;
			continue;
		}
		ll mx=0,c=0;
		for(i=0;i<n;i++){
			c++;
			if(ar[i]=='1'){
				mx=max(mx,c+max(n-i,i+1));
			}
		}
	//	cout<<mx<<endl;
		c=0;
		for(i=n-1;i>=0;i--){
			c++;
			if(ar[i]=='1'){
				//cout<<i<<" "<<c+max(n-i,i+1)<<endl;
				mx=max(mx,c+max(n-i,i+1));
			}
		}
		//cout<<mx<<endl;
		c=0;
		for(i=0;i<n;i++){
			if(ar[i]=='1') c++;
		}
		mx=max(mx,c+n);
		cout<<mx<<endl;
	}
	return 0;
}