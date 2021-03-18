//#include <iostream>
//#include <algorithm>
//using namespace std;
//string s1,s2;
//long long ss1[100005],ss2[100005];
//long long toHash(int l,int l1){
//    long long pow=1;
//    ss1[0]=s1[0];
//    ss2[0]=s2[0];
//    for(int i=1;i<l;i++){
//        ss1[0]*=131;//以10为底base过不了，最好用质数
//        ss1[0]+=s1[i];
//        ss2[0]*=131;
//        ss2[0]+=s2[i];
//        pow*=131;
//    }
//    for(int i=0;i<l1;i++){
//        if(i<l1)ss1[i+1]=(ss1[i]-s1[i]*pow)*131+s1[i+l];
//    }
//    sort(ss1,ss1+l1+1);
//    return pow;
//}
//int check(int l,int len1,int len2){
//    int l1=len1-l,l2=len2-l;
//    long long pow=toHash(l,l1);
//    for(int i=0;i<=l2;i++){
//        if(binary_search(ss1,ss1+l1+1,ss2[i])){
//            return 1;
//        }
//        ss2[i+1]=(ss2[i]-s2[i]*pow)*131+s2[i+l];
//    }
//    return 0;
//}
//int search(int l,int r,int len1,int len2){//找到不能满足的第一个
//    int mid=0;
//    while(l<r){//不能用=，会死循环——时间超限——除非对应r=mid-1
//        mid=l+((r-l)>>1);
//        if(check(mid,len1,len2)) {
//            l=mid+1;//不能写成mid(不管r是不是=mid-1)——死循环，TLE
//        }
//        else r=mid;
//    }
//    if(check(l,len1,len2))return l;//r一直没有被改变
//    else return l-1;
//}
//int main(){
//    cin>>s1>>s2;
//    int len1=s1.length(),len2=s2.length();
//    int len=len1>len2?len2:len1;
//    int ans=search(1,len,len1,len2);
//    printf("%d",ans);
//    return 0;
//}