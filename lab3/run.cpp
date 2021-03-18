//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//struct node{
//    int num;
//    node* next;
//    node* top;
//};
//node* location[2000009];
//node* compare[2000009];
//node* add(node* in, node* last){
//    if(last==NULL);
//    else {
//        last->next=in;
//        in->top=last;
//    }
//    return in;
//}
//
//bool cmp(node* a, node* b) {
//    return a->num < b->num;//<=为什么会爆炸？
//}
//int deleteNOde(node* in){
//    int a=0,b=0;
//    if(in->top==NULL){
//        in->next->top=NULL;
//        b=abs(in->next->num-in->num);
//        free(in);
//        return b;
//    }
//    else if(in->next==NULL){
//        in->top->next=NULL;
//        a=abs(in->top->num-in->num);
//        free(in);
//        return a;
//    }
//    else{
//        a=abs(in->top->num-in->num);
//        b=abs(in->next->num-in->num);
//        in->top->next=in->next;
//        in->next->top=in->top;
//        free(in);
//        a=a>=b?b:a;
//        return a;
//    }
//}
//bool com(node* a,node* b){
//    if(a->num<=b->num)return  true;
//    else return false;
//}
//
//void test(){
//    int n;
//    scanf("%d",&n);
//    node* last=NULL;
//    for(int i=0;i<n;i++){
//        node* in=new node;
//        in->next=NULL;
//        in->top=NULL;
//        scanf("%d",&(in->num));
//        location[i]=in;
//        compare[i]=in;
//    }
//    sort(compare,compare+n, cmp);
//    for(int i=0;i<n;i++){
//        last=add(compare[i],last);
//    }
//    for(int i=0;i<n-1;i++){
//        printf("%d ",deleteNOde(location[i]));
//    }
//}
//int main() {
//    test();
//    return 0;
//}