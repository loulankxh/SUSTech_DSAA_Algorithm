#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int val;//如果没有其他构造方法，val默认为0
    node* next=NULL,* l=NULL,* r=NULL;
    node(int a){val=a;}
//    node(){val=0;}
};
//node dd[31];
// 必须要有node(){val=0;}的无参构造方法（如果什么都不做，系统会自动配一个）
int pi[2005];
long long ans=0;
void dfs(node* top, int d){
    if(top->r==NULL){//叶子结点
        ans+=d*top->val;
        return;
    }
    dfs(top->l,d+1);
    dfs(top->r,d+1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d", &n);
        ans=0;
        for (int i = 0; i < n; i++)scanf("%d", &pi[i]);
        if(n==1)printf("%d\n",pi[0]);
        else{
            sort(pi, pi + n);
            node* head=new node(pi[0]);
            node* curr=head;
            for(int i=1;i<n;i++){
                curr->next=new node(pi[i]);
                curr=curr->next;
            }
            int tmp1=0;
            node* top=NULL,* tmp2=NULL,* cur=NULL,* cur1=NULL,* a=head,* b=head->next;//两根及以上
            for(int i=0;i<=n-2;i++){//总共进行的操作数
                tmp1=a->val+b->val;
                tmp2=new node(tmp1);
                cur1=b;//防止一次循环都没进得去
                cur=b->next;
                while(cur!=NULL&&cur->val<tmp1){
                    cur1=cur;
                    cur=cur->next;
                }
                cur1->next=tmp2;
                tmp2->next=cur;
                tmp2->l=a;tmp2->r=b;//建树：左右孩子
                a=b->next;b=a->next;
                if(i==n-2)top=a;
            }
            dfs(top,0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}