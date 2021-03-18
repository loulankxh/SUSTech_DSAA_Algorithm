//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//int arr[20000009];
//int front=0,rear=0;
//void enQueue(int x){
//    arr[rear]=x;
//    rear++;
//}
//void deQueue(){
//    front++;
//}
//char a[10];
//int main() {
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        scanf("%s",a);//为什么a为char,scanf("%s",a)会导致n骤变为0
//%s   %c有什么区别
//为什么不用取址符号
//char  string   char[]的读入方法
//        if(a[0]=='E'){//string   char如何比较地址？内容？
//            int x;
//            scanf("%d",&x);
//            enQueue(x);
//        }
//        else if(a[0] =='D')deQueue();
//        else printf("%d\n",arr[front]);
//    }
//    if(front==rear);
//    else{
//        for(int i=front;i<rear;i++){
//            printf("%d ",arr[i]);
//        }
//    }
//    return 0;
//}