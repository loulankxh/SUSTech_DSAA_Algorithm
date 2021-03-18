//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//int num[3010];
//long long ans=0;
//void test(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    for(int i=0;i<n;i++){
//        scanf("%d",&num[i]);
//    }
//    sort(num,num+n);
//    int me=0,count2=1,count3=1;
//    for(int i=0;i<=n-3;i++){
//        me=m-num[i];
//        if(me>=2){
//            for(int j=i+1;j<=n-2;j++){
//                int k=n-1;
//                while((long long)num[j]+num[k]!=me&&j<=k-2){
//                    if((long long)num[j]+num[k]<me)j++;
//                    else if((long long)num[j]+num[k]>me)k--;
//                }
//                if((long long)num[j]+num[k]==me){
//                    count2=count3=1;
//                    while(num[j]==num[j+1]&&j<k-1){
//                        count2++;
//                        j++;
//                    }
//                    if(num[j]==num[k]){
//                        ans+=(long long)count2*(count2+1)/2;
//                        j=k;
//                    }
//                    else{
//                        while(num[k]==num[k-1]&&k-1>j){
//                            count3++;
//                            k--;
//                        }
//                        ans+=(long long)count2*count3;
//                    }
//                }
//                if(j>=k-1)break;
//            }
//        }
//    }
//    printf("%lld",ans);
//}
//int main() {
//    test();
//    return 0;
//}