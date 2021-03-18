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
//node* head=NULL;
//node* location[100009];
//node* add(node* in,node* last){
//    if(last==NULL){
//        head=in;
//    }
//    else {
//        last->next=in;
//        in->top=last;
//    }
//    return in;
//}
//void change(int a,int b,int c,int d){
//    node* a1=location[a];
//    node* b1=location[b];
//    node* c1=location[c];
//    node* d1=location[d];
//    node* a1top=NULL;
//    bool flag=false;
//    if(a1==b1&&b1==c1&&c1==d1);
//    else{
//        if(b1->next==c1){
//            c1->top=d1;
//            b1->next=a1;
//            a1top=a1->top;
//            flag=true;
//        }
//        node* tmp1=b1->next;
//        b1->next->top=d1;
//        if(d1->next==NULL);
//        else d1->next->top=b1;
//        b1->next=d1->next;
//        d1->next=tmp1;
//        if(!flag)a1top=a1->top;
//        node* tmp2=a1top;
//        if(head==a1){
//            head=c1;
//        }
//        else a1top->next=c1;
//        c1->top->next=a1;
//        a1->top=c1->top;
//        c1->top=tmp2;
//    }
//}
//void test(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int n,m;
//        scanf("%d%d",&n,&m);
//        head=NULL;
//        node* last=head;
//        for(int i=0;i<n;i++){
//            node * in=new node;
//            cin>>in->num;
//            in->next=NULL;
//            in->top=NULL;
//            location[in->num]=in;
//            last=add(in,last);
//        }
//        while(m--){
//            int a,b,c,d;
//            scanf("%d%d%d%d",&a,&b,&c,&d);
//            change(a,b,c,d);
//        }
//        node* ans=head;
//        for(int i=0;i<n;i++){
//            printf("%d",ans->num);
//            if(i!=n-1)printf(" ");
//            ans=ans->next;
//        }
//        printf("\n");
//    }
//}
//int main() {
//    test();
//    return 0;
//}