//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//pair<int,int> arr[2000009];//1000000000过大了,哎哟喂
//pair<int,int> arr1[2000009];
//int front=0,rear=0;
//void en(pair<int,int> x){
//    arr1[rear].first=x.first;
//    arr1[rear].second=x.second;
////    arr1[rear]=x;  地址？
//    rear++;
//}
//void de(){
//    front++;
//}
//int main(){
//    int m,num;
//    scanf("%d %d",&m,&num);
//    int n=0;
//    for(int i=0;num!=-1;i++){
//        arr[i].first=i;
//        arr[i].second=num;
//        scanf("%d",&num);
//        n++;
//    }
//    en(arr[0]);
//    int ans=0;
//    for(int i=1;i<n;i++){
//        if(arr1[front].first==i-m)de();
//        while (rear>front&&arr[i].second>arr1[rear-1].second)rear--;
//        en(arr[i]);
//        if(i>=m)ans^=arr1[front].second;
//        else if (i==m-1)ans =arr1[front].second;
//    }
//    printf("%d",ans);
//    return 0;
//}