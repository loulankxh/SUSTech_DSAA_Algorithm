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
//node* add(node* in,node* last){
//    if(last==NULL){
//        head=in;
//    }
//    else last->next=in;
//    return in;
//}
//node* find(int x,node* lastt2){
//    node* cur=lastt2;
//    while(cur!=NULL){
//        if(cur->exponent<x)cur=cur->next;
//        else return cur;
//    }
//    return NULL;
//}
//node* insert(node* in,node* lastt){
//    node* last=lastt;
//    while(lastt!=NULL&&lastt->exponent<in->exponent){
//        last=lastt;
//        lastt=lastt->next;
//    }
//    if(lastt==NULL){
//        last->next=in;
//        lastt=in;
//    }
//    else{
//        if(lastt->exponent==in->exponent)lastt->coefficient+=in->coefficient;
//        else{
//            if(lastt==head){
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
//void test(){
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
//            in->next=NULL;
//            last=add(in,last);
//        }
//        int m;
//        scanf("%d",&m);
//        node* lastt=head;
//        while(m--){
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
//            if(lastt2!=NULL){
//                lastt2=find(query,lastt2);
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