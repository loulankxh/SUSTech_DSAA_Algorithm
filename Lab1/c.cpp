//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//#include <cstring>
//using namespace std;
//int ans;
//long long pow(long long n,int m,int num){
//    long long n0=1;
//    if(n==0||n==1)return 1;
//    else{
//        if(num==3){
//            for(int i=n;i>=2;i--){
//                n0*=i;//可能会爆(先乘后mod)——果然要改成long long
//                n0=n0%m;//可以这样使用a=f(a)
//            }
//        }
//        else{
//            for(int i=n;i>=2;i--){
//                n0*=i;
//                if(n0>=m)return 0;
//            }
//        }
//    }
//    if(num<3)n0=pow(n0,m,++num);
//    return  n0;
//}
//void test(){
//    long long n;
//    int m;
//    scanf("%lld%d",&n,&m);
//    if(m==1){
//        printf("%d\n",0);
//    }
//    else{
//        int num=1;
//        printf("%lld",pow(n,m,num));
//    }
//
//}
//int main() {
//    test();
//    return 0;
//}
