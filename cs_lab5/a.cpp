//#include <iostream>
//#include <algorithm>
//using namespace std;
//long long ans=0;
//struct node{
//    int start,end,id;
//    node(){start=end=id;}
//};
//node ns[500005];
//int com(node a,node b){
//    return a.end<b.end;
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int n;
//        scanf("%d",&n);
//        ans=0;
//        for(int i=1;i<=n;i++){
//            scanf("%d %d",&ns[i].start,&ns[i].end);
//            ns[i].id=i;
//        }
//        sort(ns+1,ns+n+1,com);
//
//        int next=-1;
//        for(int i=1;i<=n;i++){
//            if(ns[i].start>next){//不能等于
//                next=ns[i].end;
//                ans++;
//            }
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}