//#include <iostream>
//int n,k;
//int depth(){
//    long long ans=0,tmp=1,diff=0,count=1;//在这里用int有可能tmp会爆
//    //然后导致溢出，时间超限
//    while(tmp<=n){
//        ans=tmp;
//        count*=k;
//        tmp=k*ans+1;
//    }
//    diff=n-ans;
//    ans=diff+count/k-(diff+k-1)/k;
//    return ans;
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%d%d",&n,&k);
//        printf("%lld\n",depth());
//    }
//    return 0;
//}