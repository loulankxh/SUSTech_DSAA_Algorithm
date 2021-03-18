//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//int num[3010];
//long long ans=0;//会自动初始化吗？
//void test(){
//    int n,m;
//    scanf("%d%d",&n,&m);
////    while(n--)
//    for(int i=0;i<n;i++){
//        scanf("%d",&num[i]);
//    }
//    sort(num,num+n);//i<j<k只是为了防止重复，排完序后再做不会受到此条件的限制
//    //不能用while(n--)否则此时n==0了
//    int me=0,count2=1,count3=1;
////    int count1=1,count2=1,count3=1;
//    for(int i=0;i<=n-3;i++){
//        me=m-num[i];
//        if(me>=2){
//            for(int j=i+1;j<=n-2;j++){//枚举前两个数的位置，不受三个数是否一样或者一个数的多个个数的影响(多个出现不一定要在一次算出，然后跳过)
//                int k=n-1;
//                while((long long)num[j]+num[k]!=me&&j<=k-2){//还是可能会爆
//                    if((long long)num[j]+num[k]<me)j++;
//                    else if((long long)num[j]+num[k]>me)k--;//else不能漏！
//                }
//                if((long long)num[j]+num[k]==me){//否则j==k-1且不等me，无解
//                    count2=count3=1;
//                    while(num[j]==num[j+1]&&j<k-1){//两个数，把重复的数放在一种情况里面讨论完毕还是比较好判断,之后的就跳过了
//                        //如果对第一个数就这样处理会比较麻烦，所以第一个数还是枚举吧——还是tle了，，，
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
//                if(j>=k-1)break;//即时break否则不是n2的了
//            }
////            while(num[i]==num[i+1]){
////                count1++;
////                i++;
////            }
////            if()//分类讨论：三个数一样；开头的两个数一样；但后两者可能会有重合；后两个数一样——太麻烦了，还要讨论一个数的多个个数
//
//        }
//    }
//    printf("%lld",ans);
//}
//int main() {
//    test();
//    return 0;
//}