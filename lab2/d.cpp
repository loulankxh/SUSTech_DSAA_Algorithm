//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//long long ans;
//int v[100010];
//void test(){//前后下标之差并不等于冒泡排序的移动次数（之前的数的冒泡排序会影响之后的数的起始位置）
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        scanf("%d",&v[i]);
//    }
////    for(int i=1;i<n;i++){//TLE
////        int k=i;
////        while(v[i]<v[i-1]){//在这里判断i>0,v会不会数组越界？
////            ans+=v[i]+v[i-1];
////            v[i]^=v[i-1];
////            v[i-1]^=v[i];
////            v[i]^=v[i-1];
////            i--;
////            if(i==0)break;
////        }
////        i=k;
////    }
//    printf("%lld",ans);
//}
//int main() {
//    test();
//    return 0;
//}
