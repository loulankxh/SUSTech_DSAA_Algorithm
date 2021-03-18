//#include <iostream>
//#include <cstring>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//string s1,s2;
//long long ss1[100005],ss2[100005];
//long long toHash(int l){//不同长度l的hash可以相互借鉴（l+1->l）
//    //但关键是本题需要讨论的长度是二分做，不是连续的
//    long long pow=1;
////    ss1[0]+=s1[0];
////    ss2[0]+=s2[0];
//    ss1[0]=s1[0];//要解决上一次的干扰！
//    ss2[0]=s2[0];
//    for(int i=1;i<l;i++){
//        ss1[0]*=10;
//        ss1[0]+=s1[i];
////        ss1[0]%=59;貌似要用自然溢出？
//        ss2[0]*=10;
//        ss2[0]+=s2[i];
//        pow*=10;
//    }
//    int l1=s1.length()-l,l2=s2.length()-l;
//    for(int i=0;i<l1||i<l2;i++){
//        if(i<l1)ss1[i+1]=(ss1[i]-s1[i]*pow)*10+s1[i+l];
//    }
//    sort(ss1,ss1+l1+1);
//    return pow;
//}
//int check(int l){
//    long long pow=toHash(l);
//    int l1=s1.length()-l,l2=s2.length()-l;
//    for(int i=0;i<=l2;i++){
//        if(binary_search(ss1,ss1+l1+1,ss2[i])){
//            return 1;
//        }
//        ss2[i+1]=(ss2[i]-s2[i]*pow)*10+s2[i+l];
//    }
//    return 0;
//}
//int search(int l,int r){
//    int mid=0;
//    while(l<r){
//        mid=l+((r-l)>>1);//变r或l要看目标是>符合还是<符合
//        if(check(mid)) l=mid;//有这个长度的//
//        else r=mid-1;//没有这个长度的
//    }
//    return l;//出去还要check一次
//}
//int main(){
//    cin>>s1>>s2;
//    int len1=s1.length(),len2=s2.length();
//    int len=len1>len2?len2:len1;
//    int ans=search(1,len);
//    if(ans==1&&!check(1))printf("%d",0);//保证返回值一定是满足的
//    else printf("%d",ans);
//    return 0;
//}