//#include <iostream>
//#include <cstring>
//#include <math.h>
//using namespace std;
//string s,p;
//int next1[3340];
//int ans=0;
//void findNext(int l){
//    next1[0]=-1;
//    int k=-1,i=1;
//    while(i<l){
//        if(k==-1||s[i-1]==s[k]){
//            next1[i]=++k;
//            i++;
//        }
//        else k=next1[k];
//    }
//    //下面这种写法没有上面的优化，会时间超限
//
////    for(int i=1;i<l;i++){
////    int k=next1[i-1];
////    while(s[i]!=s[k+1]){
////        if(k==-1){//且此时还没有相等
////            next1[i]=-1;
////            break;
////        }
////        else k=next1[k];
////    }
////    if(s[i]==s[k+1])next1[i]=next1[k]+1;//排除是因为k==-1而break掉的情况
////    }
//
////改————改了之后时间不超限了
////    for(int i=1;i<l;i++){
////    int k=next1[i-1];
////    while(k==-1||s[i-1]!=s[k]){
////        if(k==-1){//且此时还没有相等
////            next1[i]=0;
////            break;
////        }
////        else k=next1[k];
////    }
////    if(s[i-1]==s[k])next1[i]=k+1;//排除是因为k==-1而break掉的情况
////    }
//}
//int kmp(int l,int p1){
//    int j=0;
//    for(int i=0;i<p1&&j<l;i++){
//        if(p[i]==s[j])j++;
//        else{
//            if(j!=0){//防止j为头元素i-- i++出现死循环或者数组越界
//                i--;
//                j=next1[j];
//            }
//        }
//    }
//    if(j==l)return 1;
//    else return 0;
//}
//int main(){
//     int N;
//     scanf("%d",&N);
//     while(N--){
//         cin>>s>>p;
//         int s1=s.length(),p1=p.length();
//         s1=ceil((double)s1/3);//要加double,否则s1/3直接向下取整
//         findNext(s1);
//         if(kmp(s1,p1))ans++;
//     }
//     printf("%d",ans);
//    return 0;
//}
