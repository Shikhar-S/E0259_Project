#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main(){
	int N; cin>>N;
	for(int n=0; n<N; n++){
		int a, b; cin>>a>>b;
		if(gcd(a,b)==1)
			cout << "Finite" << endl;
		else
			cout << "Infinite" << endl;
	}
	return 0;
}
