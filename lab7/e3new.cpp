#include <iostream>
#include <fstream>
using namespace std;
struct node{
    int left,right,diff,rh,lh,fa,h,num;long long val;//diff=lh-rh,num=rnum+lnum+1(itself)
    node(){left=right=val=diff=rh=lh=fa=h=0;num=1;}
};
node ns[100005];
long long values[100005];
int root=0;
void check1(int child,int fa){
    if(ns[child].val<ns[fa].val)ns[fa].left=child;
    else ns[fa].right=child;
}
void updateOne(int u){
    int rh=0,lh=0;
    ns[u].num=1;
    if (ns[u].right != 0){
        rh = ns[ns[u].right].h + 1;
        ns[u].num+=ns[ns[u].right].num;
    }
    if (ns[u].left != 0){
        lh = ns[ns[u].left].h + 1;
        ns[u].num+=ns[ns[u].left].num;
    }
    ns[u].h=rh>lh?rh:lh;ns[u].rh=rh;ns[u].lh=lh;
}
void balance(int u){
    int t1,t2,t3;
    if(ns[u].lh-ns[u].rh==2){//left
        t1=ns[u].left;t2=ns[t1].right;t3=ns[u].fa;
        if(ns[ns[u].left].lh>=ns[ns[u].left].rh){//left-left
            ns[u].left=t2;if(t2>0)ns[t2].fa=u;
            ns[t1].right=u;ns[u].fa=t1;
            if(t3==0)root=t1;
            else check1(t1,t3);
            ns[t1].fa=t3;
            if(t2>0)updateOne(t2);updateOne(u);updateOne(t1);//顺序会有影响
        }
        else{//left-right
            ns[t1].right=ns[t2].left;if(ns[t2].left>0)ns[ns[t2].left].fa=t1;
            ns[u].left=ns[t2].right;if(ns[t2].right>0)ns[ns[t2].right].fa=u;
            ns[t2].left=t1;ns[t1].fa=t2;
            ns[t2].right=u;ns[u].fa=t2;
            if(t3==0)root=t2;
            else check1(t2,t3);
            ns[t2].fa=t3;
            updateOne(u);updateOne(t1);updateOne(t2);
        }
    }
    else{//right
        t1=ns[u].right;t2=ns[t1].left;t3=ns[u].fa;
        if(ns[ns[u].right].rh>=ns[ns[u].right].lh){//right-right
            ns[u].right=t2;if(t2>0)ns[t2].fa=u;
            ns[t1].left=u;ns[u].fa=t1;
            if(t3==0)root=t1;
            else check1(t1,t3);
            ns[t1].fa=t3;
            if(t2>0)updateOne(t2);updateOne(u);updateOne(t1);
        }
        else{//right-left
            ns[t1].left=ns[t2].right;if(ns[t2].right>0)ns[ns[t2].right].fa=t1;
            ns[u].right=ns[t2].left;if(ns[t2].left>0)ns[ns[t2].left].fa=u;
            ns[t2].right=t1;ns[t1].fa=t2;
            ns[t2].left=u;ns[u].fa=t2;
            if(t3==0)root=t2;
            else check1(t2,t3);
            ns[t2].fa=t3;
            updateOne(u);updateOne(t1);updateOne(t2);
        }
    }
}
void insert(int loca,int u){
    if(u==0) root=loca;
    else if(ns[u].val<=ns[loca].val){
        if(ns[u].right==0){
            ns[u].right=loca;
            ns[loca].fa=u;
        }
        else {
            insert(loca,ns[u].right);
        }
    }
    else{
        if(ns[u].left==0){
            ns[u].left=loca;
            ns[loca].fa=u;
        }
        else insert(loca,ns[u].left);
    }
    updateOne(u);//h rh lh rnum lnum
    if(abs(ns[u].rh-ns[u].lh)==2)balance(u);
    return;
}
long long succesor(long long val,int u){
    int ans=0;
    while(u!=0){
        if(ns[u].val<=val)u=ns[u].right;
        else{//>
            ans=u;
            u=ns[u].left;
        }
    }
    return ans;
}
void delete1(long long val,int u){
    if(ns[u].val<val){
        delete1(val,ns[u].right);
        updateOne(u);
        if(abs(ns[u].rh-ns[u].lh)==2)balance(u);
    }
    else if(ns[u].val>val){
        delete1(val,ns[u].left);
        updateOne(u);
        if(abs(ns[u].rh-ns[u].lh)==2)balance(u);
    }
    else{//==
        int v=u,flag=0;//case 2,3
        if(ns[u].right>0){
            flag=1;
            v=succesor(val,u);
            ns[u].val=ns[v].val;
            if(ns[v].right>0)ns[ns[v].right].fa=ns[v].fa;
            if(ns[v].val<ns[ns[v].fa].val)ns[ns[v].fa].left=ns[v].right;
            else ns[ns[v].fa].right=ns[v].right;
        }
        else if(ns[u].left>0){
            ns[ns[u].left].fa=ns[u].fa;
            if(ns[u].fa>0)check1(ns[u].left,ns[u].fa);
            else root=ns[u].left;
        }
        else{//leaf
            if(ns[u].val<ns[ns[u].fa].val)ns[ns[u].fa].left=0;
            else ns[ns[u].fa].right=0;
        }
        int v1=ns[v].fa;
        while(v1!=ns[u].fa){
            updateOne(v1);
            if(abs(ns[v1].rh-ns[v1].lh)==2)balance(v1);
            v1=ns[v1].fa;
        }
    }
}
int kthMIN(int k){//logn
    int u=root;
    while(k>0){

        if(k>ns[ns[u].left].num){
            k-=ns[ns[u].left].num+1;
            if(k>0)u=ns[u].right;
        }
        else{
            if(ns[u].left>0)u=ns[u].left;
            else return u;
        }
    }
    return u;
}
int main(){
//    ofstream ofs;
    int m,k,k1;
//    ofs.open( "C:\\Users\\lan\\Desktop\\1.in.txt");
//    freopen("1.in", "r", stdin);
    scanf("%d%d",&m,&k);
    for(int i=1;i<=m;i++) scanf("%lld", &values[i]);
    for(int i=1;i<=m;i++) {
        ns[i].val=values[i];
        insert(i,root);
        if (i - k >= 0) {
            scanf("%d",&k1);
            printf("%lld\n", ns[kthMIN(k1)].val);
            delete1(ns[i - k + 1].val,root);
        }
    }
    return 0;
}