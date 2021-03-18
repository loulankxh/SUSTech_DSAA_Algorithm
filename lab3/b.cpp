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
//void change(int a,int b,int c,int d){//关联atop与c,ctop与a,dnext与b,bnext与d（时刻注意是否之前的操作会导致这些改变）
//    node* a1=location[a];
//    node* b1=location[b];//node* 不能连在一起写？
//    node* c1=location[c];
//    node* d1=location[d];
//    node* a1top=NULL;
//    bool flag=false;
//    if(b1->next==c1){
//        c1->top=d1;
//        b1->next=a1;
//        a1top=a1->top;
//        flag=true;
//    }
//    node* tmp1=b1->next;//不只要改被移动的点，其周围得点也要修改
//    b1->next->top=d1;//有可能修改了a1的top,b1->next=a1;
//    if(d1->next==NULL);
//    else d1->next->top=b1;
//    b1->next=d1->next;
//    d1->next=tmp1;
//    if(!flag)a1top=a1->top;//否则现在a1->top已经变成d1了
//    node* tmp2=a1top;
//    if(head==a1){//不会影响，最多只改了a1的top
//        head=c1;
//    }
//    else a1top->next=c1;
//    c1->top->next=a1;
//    a1->top=c1->top;
//    c1->top=tmp2;
//}
//void test(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int n,m;
//        scanf("%d%d",&n,&m);
//        head=NULL;//多个test case要初始化
//        node* last=head;
//        for(int i=0;i<n;i++){
//            node * in=new node;
//            cin>>in->num;
//            in->next=NULL;
//            in->top=NULL;
//            location[in->num]=in;//用数组存起来，O(1)的查找
//            last=add(in,last);
//        }
//        while(m--){
//            int a,b,c,d;
//            scanf("%d%d%d%d",&a,&b,&c,&d);
//            change(a,b,c,d);
//        }
//        node* ans=head;
//        for(int i=0;i<n;i++){
//            printf("%d",ans->num);//这一次的空格会导致下一个test case格式错误
//            if(i!=n-1)printf(" ");
//            ans=ans->next;
//        }
//        printf("\n");//多个test cases
//    }
//}
//int main() {
//    test();
//    return 0;
//}