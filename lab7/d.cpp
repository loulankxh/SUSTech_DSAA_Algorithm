//#include <iostream>
//long long ks[1005],s;
//int t,k;
//void update(long long val){
//    ks[1]=val;int t1=1;
//    while((2*t1<=k&&ks[2*t1]<ks[t1])||(2*t1+1<=k&&ks[2*t1+1]<ks[t1])){
//        if(2*t1+1<=k&&ks[2*t1+1]<ks[2*t1]){
//            ks[t1]=ks[2*t1+1]^ks[t1];
//            ks[2*t1+1]^=ks[t1];ks[t1]^=ks[2*t1+1];
//            t1=2*t1+1;
//        }
//        else{
//            ks[t1]=ks[2*t1]^ks[t1];
//            ks[2*t1]^=ks[t1];ks[t1]^=ks[2*t1];
//            t1=2*t1;
//        }
//    }
//}
//void insert(long long val,int t){
//    if(t<=k){
//        ks[t]=val;
//        while(t/2>0&&ks[t/2]>ks[t]){//小顶
//            ks[t]=ks[t/2]^ks[t];
//            ks[t/2]^=ks[t];ks[t]^=ks[t/2];
//            t=t/2;
//        }
//    }
//    else update(val);
//}
//long long getVal(long long n){
//    long long ans=n,i=1;
//    while(n>0){
//        ans+=n%10;
//        n/=10;
//    }
//    return ans;
//}
//int main(){
//    scanf("%d%d%lld",&t,&k,&s);
//    long long n;
////char* n;
//    for(int i=1;i<=t;i++){
//        n=s+i;
//        insert(getVal(n),i);
//        if(i%100==0){
//            s=ks[1];
//            printf("%lld ",s);
//        }
//
//    }
//    return 0;
//}