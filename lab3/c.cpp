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
//node* tail=NULL;
//node* add(node* in,node* last){//last：当前元素,当其是EOL时为空
//    if(last==NULL){//指在EOL
//        if(tail==NULL){//链表为空
//            head=tail=in;
//        }
//        else{
//            tail->next=in;
//            in->top=tail;
//            tail=in;
//        }
//    }
//    else {//一定指向具体元素
//        if(head==last){//插在第一个之前
//            last->top=in;
//            in->next=last;
//            head=in;
//        }
//        else{//last不在第一个
//            in->top=last->top;
//            last->top->next=in;
//            last->top=in;
//            in->next=last;
//        }
//    }
//    return last;//当前元素
//    //改变last,外面的不会改变！！！
//}
//node* deleteNode(node* last){//当前要删的元素
//    if(last==NULL);//删不掉EOL
//    else{//last是一个具体元素
//        if(head==last){//last是第一个
//            if(tail==last){//只有一个元素
//                node*  tmp=last;
//                head=tail=NULL;
//                last=last->next;//当前元素:EOL
//                free(tmp);
//            }
//            else{//至少两个元素
//                node* tmp=last;
//                last->next->top=NULL;
//                head=last->next;
//                last=last->next;//当前元素
//                free(tmp);
//            }
//        }
//        else{//当前元素不是第一个
//            node* tmp=last;
//            last->top->next=last->next;
//            if(tail==last)tail=last->top;//当前元素作为最后一个元素，后面是EOL，NULL
//            else last->next->top=last->top;
//            last=last->next;
//            free(tmp);
//        }
//    }
//    return last;//当前元素
//}
//node* replace(node* in,node* last){//当前被取代的元素
//    if(last==NULL){
//        if(tail==NULL){//链表为空
//            head=tail=in;
//        }
//        else{//不为空
//            tail->next=in;
//            in->top=tail;
//            tail=in;
//        }
//    }
//    else{
//        if(head==last)head=in;//头为空
//        else{//头指向具体元素
//            last->top->next=in;
//            in->top=last->top;
//        }
//        if(tail==last)tail=in;
//        else{//尾指向具体元素
//            last->next->top=in;
//            in->next=last->next;
//        }
//    }
//    last=in;
//    return last;
//}
//void test(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        head=tail=NULL;
//        node* cur=NULL;
//        int n;
//        scanf("%d",&n);
//        string s;
//        cin>>s;
//        for(int i=0;i<n;i++){
//            if(s[i]=='r'){
//                if(i<n-1&&!(s[i+1]=='r'||s[i+1]=='I'||s[i+1]=='H'||s[i+1]=='L'||s[i+1]=='x')){
//                    node* in=new node;
//                    in->top=NULL;
//                    in->next=NULL;
//                    in->num=s[i+1]-'0';
//                    cur=replace(in,cur);
//                    i++;
//                }
//            }
//            else if(s[i]=='I')cur=head;
//            else if(s[i]=='H'){
//                if(cur==NULL){
//                    if(tail==NULL);
//                    else cur=tail;
//                }
//                else{
//                    if(cur==head);
//                    else cur=cur->top;
//                }
//            }
//            else if(s[i]=='L'){
//                if(cur==NULL);
//                else cur=cur->next;
//            }
//            else if(s[i]=='x')cur=deleteNode(cur);
//            else{
//                node* in=new node;
//                in->top=NULL;
//                in->next=NULL;
//                in->num=s[i]-'0';
//                cur=add(in,cur);
//            }
//        }
//        node* h=head;
//        while(h!=NULL){
//            printf("%d",h->num);
//            h=h->next;
//        }
//        printf("\n");
//    }
//}
//int main() {
//    test();
//    return 0;
//}