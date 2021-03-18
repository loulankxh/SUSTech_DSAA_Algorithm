//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//long long ans;
//int v[100010];
//int* merge_sort(int* arr,int l,int r){//可以指定数组哪些位数有效
//    if(l==r) return arr+l;
//    int mid=l+((r-l)>>1);
//    merge_sort(arr,l,mid);
//    merge_sort(arr,mid+1,r);
//    int me[r-l+1];
//    int i=l,j=mid+1;
//    int count=mid-l+1;
//    long long sum=0;//注意！
//    for(int i=0;i<=mid-l;i++){
//        sum+=arr[l+i];
//    }
//    for(int k=0;k<=r-l;k++){
//        if(i<=mid&&(j>r||arr[j]>arr[i])){
//            me[k]=arr[i];
//            sum-=arr[i];
//            i++;
//            count--;
//        }
//        else{
//            me[k]=arr[j];
//            ans+=(long long)arr[j]*count;
//            ans+=sum;
//            j++;
//        }
//    }
//    for(int i=0;i<=r-l;i++){
//        arr[l+i]=me[i];
//    }
//    return arr+l;
//}
//void test(){
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        scanf("%d",&v[i]);
//    }
//    merge_sort(v,0,n-1);
//    printf("%lld",ans);
//}
//int main() {
//    test();
//    return 0;
//}