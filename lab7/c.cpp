//#include <iostream>
//long long l[100010];int n=0;long long ans=0;
//void insert(int t,long long val){
//    l[t]=val;
//    while(t/2>0&&l[t/2]>val){
//        l[t/2]=l[t/2]^l[t];
//        l[t]^=l[t/2];
//        l[t/2]^=l[t];
//        t=t/2;
//    }
//}
//long long deleteMin(int num){
//    long long a=l[1];
//    l[1]=l[num];
//    int t=1;
//    while((2*t<num&&l[t]>l[2*t])||(2*t+1<num&&l[t]>l[2*t+1])){
//        if((2*t+1<num&&l[2*t]>l[2*t+1])){//2*t+1<num（两者都成立）关系不能省
//            l[t]=l[t]^l[2*t+1];
//            l[2*t+1]^=l[t];
//            l[t]^=l[2*t+1];
//            t=2*t+1;
//        }
//        else{
//            l[t]=l[t]^l[2*t];
//            l[2*t]^=l[t];
//            l[t]^=l[2*t];
//            t=2*t;
//        }
//    }
//    return a;
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%d",&n);
//        ans=0;
//        int p;
//        for(int i=1;i<=n;i++){
//            scanf("%d",&p);
//            insert(i,p);
//        }
//        int num=n;
//        long long me=0;//me有可能会爆！欸果然
//        while(num>1){//num>=2时
//            me=deleteMin(num--)+deleteMin(num);//num-=1;delete num &num-1//不是me+!!!会重复累加
//            insert(num,me);//insert num-1
//            ans+=me;
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}