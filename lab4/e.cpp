//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//struct node{
//    int x=0,y=0;
//    int num=0;
//};
//node* arr[50009];//也可以用链表代替
//int top=-1;
//node* arr1[50009];//存下所有数
//void en(node* x){
//    top++;
//    arr[top]=x;
//}
//void de(){
//    if(top>-1)top--;
//}
//int check(node* x){
//    if(top!=-1){
//        if(arr[top]->num<x->num){
//            x->x=arr[top]->num;
//            de();
//            check(x);
//        }
//        else {
//            arr[top]->y=x->num;
//        }
//    }
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    for(int j=1;j<=t;j++){
//        top=-1;
//        int n;
//        scanf("%d",&n);
//        for(int i=0;i<n;i++){
//            node* n=new node;
//            scanf("%d",&(n->num));
//            arr1[i]=n;
//            check(n);
//            en(n);
//        }
//        printf("Case %d:\n",j);
//        for(int i=0;i<n;i++){
//            printf("%d %d\n",arr1[i]->x,arr1[i]->y);
//        }
//    }
//    return 0;
//}