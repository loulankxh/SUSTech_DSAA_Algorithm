#include <iostream>
#include <algorithm>
using namespace std;
int bi[26];
char alpha[500009];
int next1[500009];
void findKMP(int n){
    next1[0]=-1;
    int k=-1,i=1;
    while(i<=n){
        if(k==-1||alpha[i-1]==alpha[k]){
            next1[i]=++k;
            i++;
        }
        else k=next1[k];
    }
}
int main(){
    char a;
    for(int i=0;i<26;i++){
        scanf("%s",&a);//这样空格会被读出来
        bi[a-'a']=i;
    }
    scanf("%s",alpha);
    int m=0,n=0,l=0;
    for(int i=0;alpha[2*i+1]!='\0'&&alpha[2*i+2]!='\0';i++){
            alpha[i]=bi[alpha[i]-'a']+'a';//字符
            m++;
    }
    alpha[m]=bi[alpha[m]-'a']+'a';
    if(alpha[2*m+1]=='\0')n=2*m+1;
    else n=2*m+2;
       m++;
       l=n-m;
       findKMP(n);
       int tmp=next1[n];
       while(tmp>l)tmp=next1[tmp];
       printf("%d",n-tmp);//l=0不会出问题！
    return 0;
}