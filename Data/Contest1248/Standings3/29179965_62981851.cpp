#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	long long sum1=0;
	for(int i=0;i<(n/2);i++){
		sum1+=a[i];
	}
	long long sum2=0;
	for(int i=n/2;i<n;i++){
		sum2+=a[i];
	}
	cout<<sum1*sum1+sum2*sum2<<endl;
	return 0;
} 