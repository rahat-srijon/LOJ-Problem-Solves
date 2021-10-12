#include<bits/stdc++.h>
using namespace std;
#define lul long long unsigned
lul phi[5000001];
void phigen(){
	for(int i=0;i<5000001;i++)phi[i]=i;
	for(int i=2;i<5000001;i++){
		if(phi[i]==i){
			for(int j=i;j<5000001;j+=i){
				phi[j]-=phi[j]/i;
			}
		}
	}
	for(int i=1;i<5000001;i++){
		phi[i]=phi[i-1]+phi[i]*phi[i];
	}
}
int main(){
	phigen();
	int t,tc=1;
	scanf("%d",&t);
	while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",tc++,phi[b]-phi[a-1]);
    }
    return 0;
}
