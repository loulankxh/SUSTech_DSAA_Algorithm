//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//struct node{
//    int num,index;
//    node* next;
//    node* top;
//};
//node* head=NULL;
////node* tail=NULL;
//node* add(node* in,node* last){
//    if(last==NULL){
//        head=in;
////        tail=in;
//        in->top=in;//自己指向自己容易出问题
//        in->next=in;
//    }
//    else{
//        last->next=in;
//        head->top=in;
//        in->top=last;
//        in->next=head;
////        tail=in;
//    }
//    last=in;
//    return last;
//}
//node* deleteNode(int direction,int steps,node* last){
//    node* de=last;
//    if(direction==1){
//        while(steps--)de=de->next;
//    }
//    else{
//        while(steps--)de=de->top;
//    }
////    if(head==de)head=head->next;
//    de->top->next=de->next;
//    de->next->top=de->top;
//    return de;
//}
//void test(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int n,m,index=1;
//        scanf("%d%d",&n,&m);
//        node* cur=NULL;
////        head=NULL;//清零
//        for(int i=0;i<n;i++){
//            node* in=new node;
//            in->index=index++;
//            cin>>in->num;
//            cur=add(in,cur);
//        }
//        int a=0,b=0;
//        cur=head;
//        while(n>1){
//            a=(m-1)%n;//当前元素本身要被算进去，next方向
//            //n在其之前--会出错（while）
//            b=n-a;//top方向，只要n!=1不会出问题
//            if(a>=b){
//                node* now=deleteNode(-1,b,cur);
//                m=now->num;
//                cur=now->next;
//            }
//            else{
//                node* now=deleteNode(1,a,cur);
//                m=now->num;
//                cur=now->next;
//            }
//            n--;
//        }
//        printf("%d\n",cur->index);
//    }
//}
//int main() {
//    test();
//    return 0;
//}