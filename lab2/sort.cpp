#include <cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <iostream>
using namespace std;
int* merge_sort(int* arr,int l,int r){//没有返回值也可以
    if(l==r) return arr+l;
    int mid=l+((r-l)>>1);//这个l+(r-l)>>1是变成（l+r-l）>>1了吗？
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    int me[r-l+1];
    int i=l,j=mid+1;
    for(int k=0;k<=r-l;k++){
//        int i=l,j=mid+1;这里会死循环
        if(i<=mid&&(j>r||arr[j]>arr[i])){
            me[k]=arr[i];
            i++;
        }
        else{
            me[k]=arr[j];
            j++;
        }
    }
    for(int i=0;i<=r-l;i++){
        arr[l+i]=me[i];
    }
    return arr+l;
}
int partition(int* arr,int l,int r){
    int size=r-l+1;
    int p=rand()%size;//rand返回0~RAND_MAX(0x7fff)
    int L=0,R=r-l;
    int a[r-l+1];
    for(int i=l;i<=r;i++){
//        if(i==p)a[p-l]=arr[p];
        //P的位置可以改变！！不知道比它大/小的数的个数！
        if(i!=p+l){//p+l!! //排除下标不等但值相等的情况
            if(arr[i]<arr[p+l])a[L++]=arr[i];//p+l!
            else a[R--]=arr[i];
        }
    }
    a[L]=arr[p+l];
    for(int i=l;i<=r;i++){
        arr[i]=a[i-l];
    }
    return L+l;//L+l!!
}
void quick_sort(int* arr,int l,int r){
    //法一
//    int p=partition(arr,l,r);
//    if(p>l+1)quick_sort(arr,l,p-1);
//    if(p+1<r)quick_sort(arr,p+1,r);
//法二
    if(l<r){
        int p=partition(arr,l,r);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,r);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
       quick_sort(arr,0,n-1);
        for(int i=0;i<n;i++){
            printf("%d",arr[i]);
        }
    }
}