#include <cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <iostream>
#include <cstring>
using namespace std;
long long ans;
void test(){
    //2 4 6 8 10 12 14 16 18 20 22 24:1+2+1+3+1+2+1+4+1+2+1+3=22
    //5 10 15 20 25:6
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;//数据类型要注意啊
        scanf("%lld",&n);//2:60,5:30
        long long x=n/2,y=n/5;
//        int x=n/2,y=n/5;//会爆啊
        long long t=0,f=0;
//         int t,f;//这样会累积？
        while(x!=0){
            t+=x;
            x/=2;
        }
        while(y!=0){
            f+=y;
            y/=5;
        }
        if(t>f)ans=f;
        else ans=t;
        printf("%lld\n",ans);//换行
    }
}
int main() {
    test();
    return 0;
}