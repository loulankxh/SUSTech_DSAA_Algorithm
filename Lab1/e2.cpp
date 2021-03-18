#include <cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <iostream>
#include <cstring>
using namespace std;
long long place[2][100010];
long long search(long long right,long long left,int n,int turn1,int turn2){
    if(left==right)return left;
    long long mid=(left+right)>>1;
    int a=mid%n,b=mid/n;
    if(mid<abs(place[0][a]+(long long)b*turn1)+abs(place[1][a]+(long long)b*turn2)) return search(right,mid+1,n,turn1,turn2);
    return search(mid,left,n,turn1,turn2);
}
void test(){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int x=x2-x1,y=y2-y1;
    place[0][0]=x;
    place[1][0]=y;
    int n;
    scanf("%d",&n);
    string du;
    cin>>du;
    char s;
    for(int i=1;i<=n;i++){
        s=du[i-1];
        if(s=='U')y++;
        else if(s=='D')y--;
        else if(s=='L')x--;
        else if(s=='R')x++;
        place[0][i]=x;
        place[1][i]=y;
    }
    int turn1=place[0][n]-place[0][0],turn2=place[1][n]-place[1][0];
    long long result=search(1e14,1,n,turn1,turn2);
    if(result<abs(place[0][result%n]+(long long)(result/n)*turn1)+abs(place[1][result%n]+(long long)(result/n)*turn2))
        printf("%d",-1);
    else printf("%lld",result);
}
int main(){
    test();
    return 0;
}