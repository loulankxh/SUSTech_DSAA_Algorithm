#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
int arr1[12];
long long ans=0;
int N;
using namespace std;
//std:: map <long long, int> personel;
map<long long, long long> store;
long long cal(int n);
long long xunhuan(int n,int n0){//把第n0个数分割成n0-1份,n0=max n   // 对n0 >2 才有必要调用这个方法
    long long tmp=0;//使用局部变量，防止重复累加
    if(n>1){
        for(int i=0;i<=3;i++){
            if(i<=arr1[n0]){
                if(i==1&&1<=arr1[n0-n+1]){
                    arr1[n0]-=1;
                    if(arr1[n0]<=3*n-6){
                        arr1[n0-n+1]-=1;
                        tmp=(tmp+xunhuan(n-1,n0))%998244353;
                        arr1[n0-n+1]+=1;
                    }
                    arr1[n0]+=1;
                }
                if(3-i<=arr1[n0-n+1]){
                    arr1[n0]-=i;
                    if(arr1[n0]<=3*n-6){
                        arr1[n0-n+1]-=3-i;
                        tmp=(tmp+xunhuan(n-1,n0))%998244353;
                        arr1[n0-n+1]+=3-i;
                    }
                    arr1[n0]+=i;
                }
            }
            else break;
        }
//        for(int i=0;i<=4;i++){//第n个人对于第（n0-n+1）个人的得分
//            //类型4表示1：1
//            if(i==4) {
//                if(1<=arr1[n0]&&1<=arr1[n0-n+1]){
//                    arr1[n0-n+1]-=1;
//                    arr1[n0]-=1;
//                    if(arr1[n0]<=3*n-6)tmp=(tmp+xunhuan(n-1,n0))%998244353;//if: 有可能实现才往下进行
//                    arr1[n0]+=1;
//                    arr1[n0-n+1]+=1;
//                }
//            }
//            else {//i!=4
//                if(i<=arr1[n0]&&3-i<=arr1[n0-n+1]){
//                    arr1[n0-n+1]-=3-i;
//                    arr1[n0]-=i;
//                    if(arr1[n0]<=3*n-6)tmp=(tmp+xunhuan(n-1,n0))%998244353;
//                    arr1[n0]+=i;
//                    arr1[n0-n+1]+=3-i;
//                }
//            }
//        }
    }
    else if(arr1[n0]==0) {//临界点: n==1 //当前组合合法
        return cal(n0-1)%998244353;
    }
    return tmp;//前n-1项未固定时的所有可能路径
}
long long to28(int n){
    long long to28Num=0;
    for(int i=n;i>=1;i--){
        to28Num*=28;
        to28Num+=arr1[i];
    }
    return to28Num;
}
long long cal(int n){
    long long tmp=0;int arr2[12];//使用局部变量，防止全局变量反复变化，多处受影响
    for(int i=1;i<=n;i++)arr2[i]=arr1[i];
    sort(arr1+1,arr1+n+1);//排序，减少重复计算
    long long key=to28(n);
    map<long long, long long> :: iterator it;
    it=store.find(key);
    if(it==store.end()){//没找到
        if(arr1[n]<=3*n-3)tmp=xunhuan(n,n);
        store.insert(map<long long, long long>:: value_type(key,tmp));
    }
    else tmp=it->second%998244353;
    for(int i=1;i<=n;i++)arr1[i]=arr2[i];//排序之后要还原
    return tmp;
}
int main(){
    scanf("%d",&N);
    int limit=3*N-3,flag=0,boundary=0,sum=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&arr1[i]);
        if(arr1[i]>limit)flag=1;
        if(arr1[i]==limit)boundary++;
        sum+=arr1[i];
    }
    if(boundary>1||flag==1||sum<N*(N-1)||sum>N*(N-1)*3/2)printf("%d",0);//解决了N=0
    else{
        store.insert(map<long long, long long>:: value_type(84,1));// 0 vs 3
        store.insert(map<long long, long long>:: value_type(57,1));// 1 vs 2
        store.insert(map<long long, long long>:: value_type(29,1)); // 1 vs 1
        ans=cal(N);
        printf("%lld",ans);
    }
    return 0;
}