//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//#include <cstring>
//using namespace std;
//long long ans;
//int an[1000001];
//void test(){//每个数可以不止用一次
//    int n;
//    long long m;
//    scanf("%d%lld",&n,&m);
//    for(int i=1;i<=n;i++){
//        scanf("%d",&an[i]);
//    }
//    if(m==0){
//        int x=lower_bound(an+1,an+n+1,0)-an;
//        int y=upper_bound(an+1,an+n+1,0)-an;
//        for(int i=x;i<=n&&i<y;i++){
//            ans+=n-i;
//        }
//        printf("%lld",ans);
//    }
//    else{//m!=0
//        int gap1,gap2,me;
//        for(int i=1;i<=n;){//i不要++
//            if(an[i]==0);
//            else  if(m%an[i]==0&&m/an[i]>=an[i]){//an[i]>0不一定成立，故不能换不等号
//                me=m/an[i];
//                gap1=(upper_bound(an+1,an+n+1,an[i])-lower_bound(an+1,an+n+1,an[i]));
//                if(me==an[i]){
//                    ans+=gap1*(gap1-1)/2;
//                }
//                else{
//                    gap2=(upper_bound(an+1,an+n+1,me)-lower_bound(an+1,an+n+1,me));
////                if(find(an+1,an+n+1,m/an[i]))
////                    if(gap2!=0)//找到了    //问题不大
//                    ans+=gap1*gap2;
//
//                }
//            }
//            i=upper_bound(an+1,an+n+1,an[i])-an;//n+1越界//不是last，应该是i
//        }
//        printf("%lld",ans);
//    }
//}
//int main() {
//    test();
//    return 0;
//}
//




