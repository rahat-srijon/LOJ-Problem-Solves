#include<bits/stdc++.h>
using namespace std;
char P[8]="abcdefg";
int n,tab;
bool f=0;
vector<char>V;
void call(vector<char> V){
	printf("print( ");
	for(int i=0;i<n;i++){
		if(i)printf(", ");
		printf("%c",V[i]);
	}
	printf(" );\n");
}
void tabb(int c){
	for(int i=0;i<c;i++)printf("  ");
}
void sortt(int c){
	if(c==n){
		tabb(tab+1);
		call(V);
		return;
	}
	V.push_back(P[c]);
	for(int i=0;i<c;i++){
		tabb(++tab);
		printf("if(%c<%c)\n",V[i],V[c]);
	}
	sortt(c+1);
	for(int i=0;i<c;i++){
		tabb(--tab+1);
		printf("else\n");
		tab++;
		sortt(c+1);
		tab--;
	}
	V.pop_back();
}
void print(int n){
	printf("void print( ");
	for(int i=0;i<n;i++){
		if(i)printf(", ");
		printf("int %c",'a'+i);
	}
	printf(" ) {\n");
	printf("    printf(");
	for(int i=0;i<n;i++){
		if(i)printf(" ");
		printf("%%d");
	}
	printf("\\n\"");
	for(int i=0;i<n;i++){
		printf(", %c",'a'+i);
	}
	printf(" );\n}\n");
	printf("void sort( ");
	for(int i=0;i<n;i++){
		if(i)printf(", ");
		printf("int %c",'a'+i);
	}
	printf(" ) {\n");
	//vector<char>V;
	tab=0;
	sortt(0);
	printf("}\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		print(n);
	}
	return 0;
}
