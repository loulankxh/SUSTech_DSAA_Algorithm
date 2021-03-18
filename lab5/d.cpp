//#include <iostream>
//#include <cstring>
//#include <math.h>
//using namespace std;
//string s;
//int next1[200005];
//int findNext(string s,int len){
//    next1[0]=-1;
//    int k=-1,i=0;
//    while(i<len){//next1[len]——因为要确定s[len-1]的情况
//        if(k==-1||s[k]==s[i]){
//            next1[i+1]=++k;
//            i++;
//        }
//        else {
//            k=next1[k];
//        }
//    }
//    int ans=1;
//    return len-next1[len];//一个循环的字符串的长度
//}
//int main(){
//    int n;
//    scanf("%d",&n);
//    while(n--){
//        cin>>s;
//        int l=s.length();
//        int xunhuan=findNext(s,l);
//        int ans=0,rest=l%xunhuan,shang=l/xunhuan;
//        if(rest!=0||shang==1)ans=xunhuan-rest;//rest==0&&shang==1
//        printf("%d\n",ans);
//    }
//    return 0;
//}