//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//#include <cstring>
//using namespace std;
//int ans;
//void testb(){
//    int t,n;
//    scanf("%d%d",&t,&n);//空格？
//    int ts[t+1],ns[n+1];
//    for(int i=1;i<=t;i++){
//        scanf("%d",&ts[i]);
//    }
//    for(int i=1;i<=n;i++){
//        scanf("%d",&ns[i]);//数组也如此
//    }
//    for(int i=1;i<=t;i++){
//        ans=upper_bound(ns+1,ns+n+1,ts[i])-ns-1;
//        if(ans==0){
//            printf("%d\n",ts[i]);
//        }
//        else if(ns[ans]==ts[i]){
//            printf("%s\n","Meow");
//        }
//        else printf("%d\n",ts[i]-ns[ans]);
//    }
//}
//int main() {
//    testb();
//    return 0;
//}