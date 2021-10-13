#include<bits/stdc++.h>
using namespace std;
#define lint long long int
lint L[1000001],H[1000001];
lint bigmod(lint b, lint p, lint m){
	lint r=1;
	while(p){
		if(p&1)r=(r*b)%m;
		b=(b*b)%m;
		p>>=1;
	}
	return r;
}
int main(){
	L[0]=1;
	H[0]=1;
	for(lint i=1;i<1000001;i++){
		L[i]=(L[i-1]*i)%1000003;
		H[i]=bigmod(L[i],1000001,1000003);
	}
	int t,tc=1;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		printf("Case %d: %lld\n",tc++,(((H[n-k]*H[k])%1000003)*L[n])%1000003);
	}
	return 0;
}
