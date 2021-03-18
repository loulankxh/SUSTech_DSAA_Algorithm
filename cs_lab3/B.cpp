//#include <iostream>
//#include <cstring>
//using namespace std;
//string num[400005];
//long long sum[25];//10的i-1次方位上对应的值，从1开始
//int count[15],countAll[15];//从1开始
//long long power[25];//10的i次方，从0开始
//long long ans=0;
//int main(){
//    power[0]=1;
//    for(int i=1;i<24;i++){
//        power[i]=10*power[i-1]%998244353;
//    }
//    int n;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        cin>>num[i];
//        count[num[i].length()]++;//位数为i的数字的出现次数
//    }
//    countAll[10]=count[10];
//    for(int i=9;i>0;i--){
//        countAll[i]=count[i]+countAll[i+1];//位数大于等于i的数字的出现次数
//    }
//    string x;
//    long long tmp=0,me=0,len=0,place=0;
//    for(int i=1;i<=n;i++){
//        x=num[i];len=x.length();
//        for(int j=len;j>=1;j--){//注意高位在前   10中1 是高位
//            tmp=x[j-1]-'0'; place=len+1-j;//在数字中低位置的在最右边
//            me=tmp*countAll[place];//长度大于等于length的词
//            sum[2*place]+=me; sum[2*place-1]+=me;
//            for(int k=1;k<place;k++)sum[place+k]+=2*tmp*count[k];//长度小于j的词
//        }
//    }
//    for(int i=0;i<24;i++){
//        ans+=power[i]*(sum[i+1]%998244353)%998244353;
//        ans%=998244353;
//    }
//    printf("%lld",ans);
//    return 0;
//}