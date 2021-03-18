//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//int fast,slow,ans;
//int num[11];
//void init(){
//    num[0]=1;
//    for(int i=1;i<11;i++)num[i]=num[i-1]*10;
//}
//int _n(long long m,int n){
//    while(m>=num[n])m/=10;
//    return m;
//}
//void test(){
//    int t;
//    scanf("%d",&t);
//    init();
//    while(t--){
//        int n,m;
//        scanf("%d%d",&n,&m);
//        if(m==0||m==1)printf("%d\n",m);
//        else{
//            ans=fast=slow=0;
//            slow=_n((long long)m,n);
//            ans=slow;
//            fast=_n((long long)m*m,n);
//            ans=ans>=fast?ans:fast;
//            while(fast!=slow){
//                slow=_n((long long)slow*slow,n);
//                ans=ans>=slow?ans:slow;
//                fast=_n((long long)fast*fast,n);
//                ans=ans>=fast?ans:fast;
//                fast=_n((long long)fast*fast,n);
//                ans=ans>=fast?ans:fast;
//            }
//            printf("%d\n",ans);
//        }
//    }
//}
//int main() {
//    test();
//    return 0;
//}