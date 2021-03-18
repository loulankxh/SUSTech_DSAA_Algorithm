//#include <iostream>
//int price[100005];
//long long n,i1,m,k;int flag=0;
//long long updateP(long long day){
//    day--;long long cur=0;
//    long long tmp;
//    for(int i=0;i<m;i++){
//        tmp=k*day;
//        if(price[i]>tmp)cur+=price[i]-tmp;
//        else cur+=(price[i]-1)%k+1;//price==k
//    }
//    return cur;
//}
//long long binary(){
//    long long r=1e11+1,l=1,me;
//    while(l<r){
//        me=(l+r)>>1;
//        long long pay=updateP(me), h1=n+(me-1)*i1,h2=h1+i1;
//        if(pay<=h2){
//            if(pay<=h1)flag=1;//morning
//            else flag=0;//reset
//            r=me;
//        }
//        else l=me+1;
//    }
//    return l;
//}
//int main(){
//    scanf("%lld%lld%lld%lld",&n,&i1,&m,&k);
//    for(int i=0;i<m;i++){
//        scanf("%d",&price[i]);
//    }
//    long long ans=binary();printf("%lld ",ans);
//    if(flag)printf("morning");
//    else printf("evening");
//    return 0;
//}