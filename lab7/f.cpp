//#include <iostream>
//struct node{
//    int val,right,left,rh,lh,h,fa;
//    node(){val=right=left=rh=lh=h=fa=0;}
//};
//node ns[80005];
//int root0=0,root1=0;
//long long ans=0;
//void check1(int child,int fa){
//    if(ns[child].val<ns[fa].val)ns[fa].left=child;
//    else ns[fa].right=child;
//}
//void updateOne(int u){
//    int rh=0,lh=0;
//    if (ns[u].right != 0)rh = ns[ns[u].right].h + 1;
//    if (ns[u].left != 0)lh = ns[ns[u].left].h + 1;
//    ns[u].h=rh>lh?rh:lh;ns[u].rh=rh;ns[u].lh=lh;
//}
//void balance(int u,int sele){
//    int t1,t2,t3;
//    if(ns[u].lh-ns[u].rh==2){//left
//        t1=ns[u].left;t2=ns[t1].right;t3=ns[u].fa;
//        if(ns[ns[u].left].lh>=ns[ns[u].left].rh){//left-left
//            ns[u].left=t2;if(t2>0)ns[t2].fa=u;
//            ns[t1].right=u;ns[u].fa=t1;
//            if(t3==0){
//                if(sele)root1=t1;
//                else root0=t1;
//            }
//            else check1(t1,t3);
//            ns[t1].fa=t3;
//        }
//        else{//left-right
//            ns[t1].right=ns[t2].left;if(ns[t2].left>0)ns[ns[t2].left].fa=t1;
//            ns[u].left=ns[t2].right;if(ns[t2].right>0)ns[ns[t2].right].fa=u;
//            ns[t2].left=t1;ns[t1].fa=t2;
//            ns[t2].right=u;ns[u].fa=t2;
//            if(t3==0){
//                if(sele)root1=t2;
//                else root0=t2;
//            }
//            else check1(t2,t3);
//            ns[t2].fa=t3;
//        }
//    }
//    else{//right
//        t1=ns[u].right;t2=ns[t1].left;t3=ns[u].fa;
//        if(ns[ns[u].right].rh>=ns[ns[u].right].lh){//right-right
//            ns[u].right=t2;if(t2>0)ns[t2].fa=u;
//            ns[t1].left=u;ns[u].fa=t1;
//            if(t3==0){
//                if(sele)root1=t1;
//                else root0=t1;
//            }
//            else check1(t1,t3);
//            ns[t1].fa=t3;
//        }
//        else{//right-left
//            ns[t1].left=ns[t2].right;if(ns[t2].right>0)ns[ns[t2].right].fa=t1;
//            ns[u].right=ns[t2].left;if(ns[t2].left>0)ns[ns[t2].left].fa=u;
//            ns[t2].right=t1;ns[t1].fa=t2;
//            ns[t2].left=u;ns[u].fa=t2;
//            if(t3==0){
//                if(sele)root1=t2;
//                else root0=t2;
//            }
//            else check1(t2,t3);
//            ns[t2].fa=t3;
//        }
//    }
//    updateOne(t1);if(t2>0)updateOne(t2);updateOne(u);
//}
//void insert(int loca,int u,int sele){
//    if(u==0) {
//        if(sele==0) root0=loca;
//        else root1=loca;
//    }
//    else if(ns[u].val<=ns[loca].val){
//        if(ns[u].right==0){
//            ns[u].right=loca;
//            ns[loca].fa=u;
//        }
//        else insert(loca,ns[u].right,sele);
//    }
//    else{
//        if(ns[u].left==0){
//            ns[u].left=loca;
//            ns[loca].fa=u;
//        }
//        else insert(loca,ns[u].left,sele);
//    }
//    updateOne(u);//h rh lh rnum lnum
//    if(abs(ns[u].rh-ns[u].lh)==2)balance(u,sele);
//    return;
//}
//void delete1(int u,int sele){
//    int v=u;//case 2,3
//    if(ns[u].right>0){
//        int uc=ns[u].right,val=ns[u].val;
//    while(uc!=0){
//        if(ns[uc].val<=val){
//            if(ns[uc].val==val){
//                v=uc;
//                break;
//            }
//            uc=ns[uc].right;
//        }
//        else{//>
//            v=uc;
//            uc=ns[uc].left;
//        }
//    }
//    ns[u].val=ns[v].val;
//    if(ns[v].right>0)ns[ns[v].right].fa=ns[v].fa;
//    if(ns[v].val<ns[ns[v].fa].val)ns[ns[v].fa].left=ns[v].right;
//    else ns[ns[v].fa].right=ns[v].right;
//    }
//    else if(ns[u].left>0){
//        ns[ns[u].left].fa=ns[u].fa;
//        if(ns[u].fa>0)check1(ns[u].left,ns[u].fa);
//        else {
//            if(sele)root1=ns[u].left;
//            else root0=ns[u].left;
//        }
//    }
//    else{//leaf
//        if(ns[u].fa>0){
//            if(ns[u].val<ns[ns[u].fa].val)ns[ns[u].fa].left=0;
//            else ns[ns[u].fa].right=0;
//        }
//        else{
//            if(sele)root1=0;
//            else root0=0;
//        }
//    }
//    int v1=ns[v].fa;
//    while(v1!=0){
//        updateOne(v1);
//        if(abs(ns[v1].rh-ns[v1].lh)==2)balance(v1,sele);
//        v1=ns[v1].fa;
//    }
//}
//void cal(int val,int u,int sele){//sele在哪个树上做操作
//    int min=0,max=0,flag=1,u1=u;
//    while(u!=0){
//        if(ns[u].val<val)u=ns[u].right;
//        else if(ns[u].val>val){//>
//            max=u;
//            u=ns[u].left;
//        }
//        else{
//            flag=0;
//            max=min=u;
//            break;
//        }
//    }
//    while(flag&&u1!=0){
//        if(ns[u1].val>val)u1=ns[u1].left;
//        else {//<  此时不可能=
//            min=u1;
//            u1=ns[u1].right;
//        }
//    }
//    int l1=ns[max].val-val,l2=val-ns[min].val;
//    if(min!=0&&(max==0|l1>=l2)){
//        ans+=l2;
//        delete1(min,sele);
//    }
//    else{
//        ans+=l1;
//        delete1(max,sele);
//    }
//}
//int main(){
//    int n;
//    scanf("%d",&n);
//    int a=0;
//    for(int i=1;i<=n;i++){
//        scanf("%d%d",&a,&ns[i].val);
//        if(a==0){//pets
//            if(root1==0)insert(i,root0,0);
//            else{
//                cal(ns[i].val,root1,1);
//            }
//        }
//        else{//adoptors
//            if(root0==0)insert(i,root1,1);
//            else{
//                cal(ns[i].val,root0,0);
//            }
//        }
//    }
//    printf("%lld",ans);
//    return 0;
//}