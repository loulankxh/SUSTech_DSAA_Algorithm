//#include <iostream>
//#include <algorithm>
//using namespace std;
//int pre[2000005],suf[2000005];
//struct node{
//    int num,id;
//    node(){num=id=0;};
////    bool operater < (const node &x) const{
////        return num<x.num;
////    }
////?怎么写
//};
//long ans=0;
//bool compare(node a, node b){
//    return a.num<b.num;
//}
//node ranking[2000005];
//int aNum[2000005];
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++) {
//        scanf("%d",&aNum[i]);
//        ranking[i].num=aNum[i];
//        ranking[i].id=i;
//    }
//    sort(ranking+1,ranking+n+1,compare);
//    for(int i=1;i<=n;i++){
//        if(n==1){ //i==i && i==n
//            pre[ranking[i].id]=suf[ranking[i].id]=0;
//        }
//        else if(i==1){
//            pre[ranking[i].id]=0;
//            suf[ranking[i].id]=ranking[i+1].id;
//        }
//        else if(i==n){
//            pre[ranking[i].id]=ranking[i-1].id;
//            suf[ranking[i].id]=0;
//        }
//        else{
//            pre[ranking[i].id]=ranking[i-1].id;
//            suf[ranking[i].id]=ranking[i+1].id;
//        }
//    }
//    int num1=0,num2=0;
//    for(int i=n;i>0;i--){
//        if(pre[i]>0&&suf[i]>0){
//            num1=aNum[i]-aNum[pre[i]];
//            num2=aNum[suf[i]]-aNum[i];
//            suf[pre[i]]=suf[i];
//            pre[suf[i]]=pre[i];
//            ans+=num1<num2?num1:num2;
//        }
//        else if(pre[i]==0&&suf[i]==0)ans+=aNum[i];//只剩一个,i==1
//        else if(pre[i]==0){
//            ans+=aNum[suf[i]]-aNum[i];
//            pre[suf[i]]=0;
//        }
//        else{//suf[i]==0
//            ans+=aNum[i]-aNum[pre[i]];
//            suf[pre[i]]=0;
//        }
//    }
//    printf("%lld",ans);
//    return 0;
//}