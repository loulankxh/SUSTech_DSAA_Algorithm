//#include <iostream>
//struct node{
//    //lnum 与rnum记录左边右边的个数，不是比起大比起小的数的个数（balance里面要改,delete也是）
//    int left,right,lh,rh,fa,h,lnum,rnum;long long val;
//    node(){left=right=val=lh=rh=fa=h=lnum=rnum=0;}
//};
//node nodes[100005];
//long long values[100005];
//int kth[100005];
//int root=0;
//void balance(int);
//void update(int);
//void insert(int loca){
//    int u=root;long long val=nodes[loca].val;
//    while(root>0){
//        if(nodes[u].val<=val){
//            nodes[u].rnum++;
//            if(nodes[u].right==0){
//                nodes[u].right=loca;
//                nodes[loca].fa=u;
//                break;
//            }
//            else u=nodes[u].right;
//        }
//        else{//>
//            nodes[u].lnum++;
//            if(nodes[u].left==0){
//                nodes[u].left=loca;
//                nodes[loca].fa=u;
//                break;
//            }
//            else u=nodes[u].left;
//        }
//    }
//    if(root==0) root=loca;
//    update(loca);//除了balance里面，balance之前也要有目前的准确值
//    balance(loca);
//}
//void check1(int temp,int tmp){
//    if(nodes[temp].val<nodes[tmp].val)nodes[tmp].left=temp;
//    else nodes[tmp].right=temp;
//}
//void update(int u) {
//    while (u != 0) {
//        if (nodes[u].right != 0)nodes[u].rh = nodes[nodes[u].right].h + 1;
//        else nodes[u].rh=0;//要清理！否则保持原样
//        if (nodes[u].left != 0)nodes[u].lh = nodes[nodes[u].left].h + 1;
//        else nodes[u].lh=0;
//        nodes[u].h=nodes[u].rh>nodes[u].lh?nodes[u].rh:nodes[u].lh;//别忘了
//        u = nodes[u].fa;
//    }
//}
//void updateOne(int u){
//    if (nodes[u].right != 0)nodes[u].rh = nodes[nodes[u].right].h + 1;
//    else nodes[u].rh=0;//要清理！否则保持原样
//    if (nodes[u].left != 0)nodes[u].lh = nodes[nodes[u].left].h + 1;
//    else nodes[u].lh=0;
//    nodes[u].h=nodes[u].rh>nodes[u].lh?nodes[u].rh:nodes[u].lh;//别忘了
//}
//void balance(int u)      {
//    int temp=0,tmp=0;
//    while(u!=0){
//        if(abs(nodes[nodes[u].fa].lh-nodes[nodes[u].fa].rh)==2){
//            if(nodes[nodes[u].fa].lh-nodes[nodes[u].fa].rh==2){//
//                tmp=nodes[nodes[u].fa].fa;
//                if(nodes[u].lh-nodes[u].rh>=0){//left-left
//                    temp=nodes[u].fa;
//                    nodes[nodes[u].right].fa=temp;
//                    nodes[temp].left=nodes[u].right;
//                    nodes[temp].lnum=nodes[u].rnum;//此时还未修改
//                    nodes[u].right=temp;
//                    nodes[temp].fa=u;
//                    nodes[u].fa=tmp;
//                    nodes[u].rnum=nodes[temp].lnum+nodes[temp].rnum+1;//temp itself
//                    if(tmp==0)root=u;
//                    else check1(u,tmp);
//                    updateOne(nodes[u].right);
//                }
//                else{
//                    temp=nodes[u].right;
//                    nodes[nodes[temp].left].fa=u;
//                    nodes[u].right=nodes[temp].left;
//                    nodes[u].rnum=nodes[temp].lnum;//此时还未修改
//                    nodes[nodes[temp].right].fa=nodes[u].fa;
//                    nodes[nodes[u].fa].left=nodes[temp].right;
//                    nodes[nodes[u].fa].lnum=nodes[temp].rnum;//此时还未修改
//                    nodes[temp].right=nodes[u].fa;
//                    nodes[nodes[u].fa].fa=temp;
//                    nodes[temp].left=u;
//                    nodes[u].fa=temp;
//                    nodes[temp].fa=tmp;
//                    nodes[temp].lnum=nodes[u].lnum+nodes[u].rnum+1;//itself  u must exist
//                    nodes[temp].rnum=nodes[nodes[temp].right].lnum+nodes[nodes[temp].right].rnum+1;//itself  temp must exist
//                    if(tmp==0)root=temp;
//                    else check1(temp,tmp);
//                    updateOne(nodes[temp].right);
//                    updateOne(u);
//                }
//            }
//            else{//-2
//                tmp=nodes[nodes[u].fa].fa;
//                if(nodes[u].rh-nodes[u].lh>=0){
//                    temp=nodes[u].fa;
//                    nodes[nodes[u].left].fa=temp;
//                    nodes[temp].right=nodes[u].left;
//                    nodes[temp].rnum=nodes[u].lnum;//此时还未修改
//                    nodes[u].left=temp;
//                    nodes[temp].fa=u;
//                    nodes[u].fa=tmp;
//                    nodes[u].lnum=nodes[temp].lnum+nodes[temp].rnum+1;
//                    if(tmp==0)root=u;
//                    else check1(u,tmp);
//                }
//                else{//right-left
//                    temp=nodes[u].left;
//                    nodes[nodes[temp].right].fa=u;
//                    nodes[u].left=nodes[temp].right;
//                    nodes[u].lnum=nodes[temp].rnum;//此时还未修改
//                    nodes[nodes[temp].left].fa=nodes[u].fa;
//                    nodes[nodes[u].fa].right=nodes[temp].left;
//                    nodes[nodes[u].fa].rnum=nodes[temp].lnum;//此时还未修改
//                    nodes[temp].left=nodes[u].fa;
//                    nodes[nodes[u].fa].fa=temp;
//                    nodes[temp].right=u;
//                    nodes[u].fa=temp;
//                    nodes[temp].fa=tmp;
//                    nodes[temp].rnum=nodes[u].lnum+nodes[u].rnum+1;
//                    nodes[temp].lnum=nodes[nodes[temp].left].lnum+nodes[nodes[temp].left].rnum+1;//
//                    if(tmp==0)root=temp;
//                    else check1(temp,tmp);
//                    updateOne(nodes[temp].left);
//                    updateOne(u);
//                }
//            }
//            update(temp);
//            break;
//        }
//        u=nodes[u].fa;
//    }
//}
//long long succesor(long long val){
//    int u=root,ans=0;
//    while(u!=0){
//        if(nodes[u].val<=val)u=nodes[u].right;
//        else{//>
//            ans=u;
//            u=nodes[u].left;
//        }
//    }
//    return ans;
//}
//void update2(int u){
//    while(u!=0){
//        if(nodes[u].left>0)nodes[u].lnum=nodes[nodes[u].left].lnum+nodes[nodes[u].left].rnum;
//        else nodes[u].lnum=0;
//        if(nodes[u].right>0)nodes[u].rnum=nodes[nodes[u].right].lnum+nodes[nodes[u].right].rnum;
//        else nodes[u].rnum=0;
//        u=nodes[u].fa;
//    }
//}
//void delete1(long long val){
//    int u=root;
//    while(nodes[u].val!=val){
//        if(nodes[u].val<=val)u=nodes[u].right;
//        else u=nodes[u].left;
//    }
//    int v=0;
//    if(nodes[u].right>0){
//        v=succesor(val);
//        nodes[u].val=nodes[v].val;
//        if(nodes[v].right>0){
//            if(nodes[v].val<nodes[nodes[v].fa].val)nodes[nodes[v].fa].left=nodes[v].right;
//            else nodes[nodes[v].fa].right=nodes[v].right;
//            nodes[nodes[v].right].fa=nodes[v].fa;
//        }//不可能有左子树
//        else {
//            if(nodes[v].val<nodes[nodes[v].fa].val)nodes[nodes[v].fa].left=0;
//            else nodes[nodes[v].fa].right=0;
//        }
//        update2(nodes[v].fa);
//    }
//    else if(nodes[u].left>0){
//        if(nodes[u].val<nodes[nodes[u].fa].val)nodes[nodes[u].fa].left=nodes[u].left;
//        else nodes[nodes[u].fa].right=nodes[u].left;
//        nodes[nodes[u].left].fa=nodes[u].fa;
//        update2(nodes[u].fa);
//    }
//    else {
//        if(nodes[u].val<nodes[nodes[u].fa].val)nodes[nodes[u].fa].left=0;
//        else nodes[nodes[u].fa].right=0;
//        update2(nodes[u].fa);
//    }
//}
//int kthMIN(int k){
//    int u=root;
//    while(k>0){
//        if(k>nodes[u].lnum){
//            k-=nodes[u].lnum+1;//u本身
//            if(k>0)u=nodes[u].right;
//        }
//        else{
//            if(k==nodes[u].lnum)return nodes[u].left;
//            u=nodes[u].left;
//        }
//    }
//    return u;//没有 left 只有right  case one
//}
//int main(){
//    int m,k,k1;
//    scanf("%d%d",&m,&k);
//    for(int i=1;i<=m;i++) scanf("%lld", &values[i]);
//    for(int i=1;i<=m-k+1;i++) scanf("%d",&kth[i]);
//    for(int i=1;i<=m;i++) {
//        nodes[i].val=values[i];
//        insert(i);
//        if (i - k >= 0) {
//            k1=kth[i-k+1];
//            printf("%lld\n", nodes[kthMIN(k1)].val);//这样读入会交错
//            delete1(nodes[i - k + 1].val);
//        }
//    }
////    for(int i=1;i<=m;i++) {
////        scanf("%lld", &nodes[i].val);
////        insert(i);
////        if (i - k >= 0) {
////            scanf("%d", &k1);
////            printf("%lld\n", nodes[kthMIN(k1)].val);//这样读入会交错
////            delete1(nodes[i - k + 1].val);
////        }
////    }
//    return 0;
//}