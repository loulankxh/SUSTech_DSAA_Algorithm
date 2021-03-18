//#include <iostream>
//long long s1,s2,s3,end;
//long long t1,t2,t3;int flag;
//long long check(long long s,long long end){
//    long long count=0;
//    while(s!=end){
//        s=s*s%2147483231;
//        count++;
//    }
//    return count;
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%lld%lld%lld%lld",&s1,&s2,&s3,&end);
//        t1=check(s1,end);t2=check(s2,end);t3=check(s3,end);
//        long long min=t1>t2?t2:t1;
//        min=min>t3?t3:min;
//        while(t1>min){
//            t1--;
//            s1=s1*s1%2147483231;
//        }
//        while(t2>min){
//            t2--;
//            s2=s2*s2%2147483231;
//        }
//        while(t3>min){
//            t3--;
//            s3=s3*s3%2147483231;
//        }
//        flag=0;
//        for(long long i=0;1;i++){
//            if(s1==s2&&s2==s3)break;
//            s1=s1*s1%2147483231;
//            s2=s2*s2%2147483231;
//            s3=s3*s3%2147483231;
//        }
//        printf("%lld\n",s1);
//    }
//    return 0;
//}