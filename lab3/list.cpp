#include <cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <iostream>
using namespace std;
struct node{
    int num;//初始化？
    node* next;
};
node* head=NULL;//如果不初始化会是野指针，用起来极大可能出错；*head代表什么？
//void add(node* in){
//    node* cur=head;//类型要匹配，指针与对象不一样
//    while(cur!=NULL){//直接cur->next会跳过第一个
//        cur=cur->next;
//    }
////    node* a=new node;
//    cur=in;//不是cur->next!
//}
//void insert(node* in,int i){
//    node* cur=head;//head:第一个；head->next：第二个
//    int place=1;//代表当前指针所指对象的位置
//    while(i>place){
//        place++;
//        cur=cur->next;
//    }
//    in=cur->next;
//    cur=in;//cur本身也是一个指针,当前指向的位置
//！！！
//不能这样写！：不能直接对一个地址赋值——改变了这个地址，结果是这一个变量（甚至知识这个变量的复制cur）改变了，原来的对象的指针还是指向了原先的地址
//只能通过cur->next来改变——把这一个地址（cur）和下一个地址关联起来,而不是给一个新的地址给cur变量，其实没有影响到原先的关系
//cur并没有和head关联起来，把head表示的地址赋值给cur，之后再修改cur不会影响到head
//可以用f复制品cur通过相同的地址实现地址传递，属性同时改变；但你改变了复制品的地址，原变量不会发生变化
//head的地方不能用->next,要用head直接赋值！


//    //避免指针指向自己——指向自己：相当于野指针了；但可以通过修改指向获得修正
//}
//void deleteNode(int i){
//    node* cur=head;
//    int place=1;//代表当前指针所指对象的位置
//    while(i>place){
//        place++;
//        cur=cur->next;//cur本身也是一个指针（属于前一个对象的next）,当前指向的位置
//    }
//    node* tmp=cur;
//    cur=cur->next;//cur不是当前对象的指针，而是指向当前对象的指针
//    free(tmp);
////    node* tmp=cur->next;
////    cur->next=cur->next->next;
////    free(tmp);
//}
//node* find(int x){
//    node* cur=head;
//    while(cur!=NULL){//cur->next会跳过第一个
//        if(cur->num==x)return cur;
//        cur=cur->next;
//    }
//    return NULL;
//}

void add(node* in){
    node* cur=head;
    if(head==NULL){//直接cur->next会跳过第一个
        head=in;
        return;
    }
    while(cur->next!=NULL){//add不要这么写，不然每一题都超限
        cur=cur->next;
    }
    cur->next=in;//不是cur!——修改了前一个的复制品的的地址，而不是建立了两者之间的关系
}
void insert(node* in,int i){//把其变成第i个，放在原来第i个前面
    node* cur=head;//head:第一个；head->next：第二个
    if(i==1){
        in->next=head;
        head=in;
        return;
    }
    int place=2;//代表前一个的指针所指的当前对象的位置
    while(i>place){
        place++;
        cur=cur->next;
    }
    in->next=cur->next;
    cur->next=in;//cur本身也是一个指针——当前对象前一个对象的地址
}
void deleteNode(int i){
    node* cur=head;
    if(i==1){
        head=head->next;
        return;
    }
    int place=2;//代表当前指针所指对象的位置
    while(i>place){//找到要删除对象的钱一个对象
        place++;
        cur=cur->next;
    }
    node* tmp=cur->next;
    cur->next=cur->next->next;//cur不是当前对象的指针，而是指向当前对象的指针
    free(tmp);
}
node* find(int x){
    node* cur=head;//find可以通过当前对象的cur地址使用——因为只是查找，不用改变
    while(cur!=NULL){//cur->next会跳过第一个
        if(cur->num==x)return cur;
        cur=cur->next;
    }
    return NULL;
}
//void update(int i,int x){
//}
//void traverse(){
//}
int main() {
    return 0;
}