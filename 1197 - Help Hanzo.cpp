#include<bits/stdc++.h>
using namespace std;
#define lint long long int
const lint mxN=46342;
lint prime[mxN],pCnt;
bitset<mxN>pmark;
void sieve(){
	lint lim=sqrt(mxN*1.0)+2;
	pmark[0]=pmark[1]=1;
	prime[pCnt++]=2;
	prime[pCnt++]=3;
	for(lint i=4;i<mxN;i+=2){
		pmark[i]=1;
	}
	for(lint i=9;i<mxN;i+=6){
		pmark[i]=1;
	}
	for(lint i=5;i<mxN;i+=6){
		if(!pmark[i]){
			prime[pCnt++]=i;
			if(i<=lim){
				for(lint j=i*i;j<mxN;j+=i*2){
					pmark[j]=1;
				}
			}
		}
		if(!pmark[i+2]){
			lint x=i+2;
			prime[pCnt++]=x;
			if(x<=lim){
				for(lint j=x*x;j<mxN;j+=2*x){
					pmark[j]=1;
				}
			}
		}
	}
}
lint segsieve(lint l,lint r){
	lint ret=0;
	lint P[r-l+1];
	for(lint i=0;i<r-l+1;i++)P[i]=1;
	for(lint i=0;i<pCnt&&prime[i]*prime[i]<=r;i++){
		lint p=prime[i];
		for(lint j=max(p*p,(l+p-1)/p*p);j<=r;j+=p){
			P[j-l]=0;
		}
	}
	if(l==1)P[0]=0;
	for(lint i=0;i<r-l+1;i++)ret+=P[i];
	return ret;
}
int main(){
	sieve();
	lint t,tc=0;
	scanf("%lld",&t);
	while(t--){
		lint a,b;
		scanf("%lld %lld",&a,&b);
		lint ans=segsieve(a,b);
		printf("Case %lld: %lld\n",++tc,ans);
	}
	return 0;
}
