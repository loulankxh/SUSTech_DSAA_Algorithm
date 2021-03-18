//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//#include <cstring>
//using namespace std;
//int ans;
//int an[1000001];
//void test(){//每种组合只计数一次，但一个数可以用于不同的组合
//    int n;
//    long long m;
//    scanf("%d%lld",&n,&m);
//    for(int i=1;i<=n;i++){
//        scanf("%d",&an[i]);
//    }
//    if(m==0){
//        int x=lower_bound(an+1,an+n+1,0)-an;//下标为0 要删掉！
//        int y=upper_bound(an+1,an+n+1,0)-an;
//        int gap1=y-x;//0
//        int gap2=0;//不=0也会出问题？
////        for(int i=y;i<=n;){
////            gap2++;
////            i=upper_bound(an+1,an+n+1,an[i])-an;
////        }
//        for(int i=1;i<=n;i++){//更快其实
//            //0与小于0的数组合也是符合规定的！
//            if(an[i]!=an[i-1]&&an[i]!=0)gap2++;
//        }
//        if(gap1>0){
//            if(gap1>1)ans=gap2+1;
//            else ans=gap2;
//        }
//        printf("%d",ans);
//    }
//    else{//m!=0
//        int gap1,gap2;//me可能会爆,即使有可能me不在an[]里（an[]不会爆）
//        long long me;
//        for(int i=1;i<=n;){//i不要++
//            if(an[i]==0);
//            else  if(m%an[i]==0&&m/an[i]>=an[i]){//an[i]>0不一定成立，故不能换不等号
//                me=m/an[i];
//                gap1=(upper_bound(an+1,an+n+1,an[i])-lower_bound(an+1,an+n+1,an[i]));
//                if(me==an[i]){
//                    if(gap1>=2)ans++;//条件放上面else会出问题
//                }
//                else{
//                    gap2=(upper_bound(an+1,an+n+1,me)-lower_bound(an+1,an+n+1,me));
////                if(find(an+1,an+n+1,m/an[i]))
////                    if(gap2!=0)//找到了    //问题不大
//                    if(gap2>0)ans++;
//                }
//            }
//            i=upper_bound(an+1,an+n+1,an[i])-an;//n+1越界//不是last，应该是i
//        }
//        printf("%d",ans);
//    }
//}
//int main() {
//    test();
//    return 0;
//}
//
