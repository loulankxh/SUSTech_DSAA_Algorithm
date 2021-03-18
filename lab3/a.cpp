//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//struct node{
//    int coefficient,exponent;
//    node* next;
//};
//node* head=NULL;
//
//node* add(node* in,node* last){//in,last都是地址，可以导致原变量变化
//    if(last==NULL){
//        head=in;
//    }
//    else last->next=in;
//    return in;
////    last=in;//这个局部变量的值没有被返回到外面。。。（可以通过地址关联；但地址变量本身不关联）
//}
//node* find(int x,node* lastt2){//可以
//    node* cur=lastt2;
//    while(cur!=NULL){
//        if(cur->exponent<x)cur=cur->next;
//        else return cur;//去外面判断>=
//    }
//    return NULL;
//}
//node* insert(node* in,node* lastt){//lastt:从第一个元素开始（现在的head）;除了head,之后传入的lastt都一定在in前面（上一次的i）
//    node* last=lastt;
//    while(lastt!=NULL&&lastt->exponent<in->exponent){//不是cur->next!=NULL!!
//        last=lastt;
//        lastt=lastt->next;
//    }
//    if(lastt==NULL){
//        last->next=in;//cur=in这样只是修改了复制品的地址，没用！
//        //此时last不能为NULL，之前一定add了元素进去过，head不为NULL
//        lastt=in;
//    }
//    else{
//        if(lastt->exponent==in->exponent)lastt->coefficient+=in->coefficient;
//        else{//>  要返回到上一层的cur
//            if(lastt==head){//!!!不能漏了，last还未与lastt区分开，而且都是head（遍历的起点）
//                in->next=head;
//                head=in;
//                lastt=in;
//            }
//            else{
//                in->next=lastt;
//                last->next=in;
//                lastt=in;
//            }
//        }
//    }
//    return lastt;
//}
//void test(){//简化：exponent是递增的，不用每次从头开始递增
//    int t;
//    scanf("%d",&t);;
//    while(t--){
//        head=NULL;
//        int n;
//        scanf("%d",&n);
//        node* last=head;
//        while(n--){
//            node *in=new node;
//            cin>>in->coefficient>>in->exponent;
////            scanf("%d%d",in->coefficient,in->exponent);//为啥不能被读入？
//////            node in;//在整个while循环里面，其实始终都用的是一个地址？使得链表之前赋好的值也在变化？？？
//            in->next=NULL;
//            last=add(in,last);
//        }
//        int m;
//        scanf("%d",&m);
//        node* lastt=head;
//        while(m--){
////            node in;
////            in.next=NULL;
////            scanf("%d%d",&in.coefficient,&in.exponent);
//            node *in=new node;
//            in->next=NULL;
//            cin>>in->coefficient>>in->exponent;
//            lastt=insert(in,lastt);
//        }
//        int q;
//        scanf("%d",&q);
//        node* lastt2=head;
//        while(q--){
//            int query;
//            scanf("%d",&query);
//            //            lastt2=find(query,lastt2);写这里lastt2==NULL是也会被带进去
//            if(lastt2!=NULL){
//                lastt2=find(query,lastt2);//写这里可能也会出现空指针
//                if(lastt2==NULL)printf("%d ",0);
//                else if(lastt2->exponent==query)printf("%d ",lastt2->coefficient);
//                else printf("%d ",0);
//            }
//            else printf("%d ",0);
//        }
//    }
//}
//int main() {
//    test();
//    return 0;
//}