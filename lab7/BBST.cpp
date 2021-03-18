//#include <iostream>
//struct node{
//    int left,right,val,lh,rh,fa,h;
//    node(){left=right=val=lh=rh=fa=h=0;}
//};
//node nodes[100005];
//int root=0;
//void balance(int);
//void insert(int loca){
//    int u=root,val=nodes[loca].val;
//    while(root>0){
//        if(nodes[u].val<=val){
////            nodes[u].rh++;深度不一定增加，但子节点数增加（用update更新深度）
//            if(nodes[u].right==0){
//                nodes[u].right=loca;
//                nodes[loca].fa=u;
//                break;
//            }
//            else u=nodes[u].right;
//        }
//        else{//>
////            nodes[u].lh++;
//            if(nodes[u].left==0){
//                nodes[u].left=loca;
//                nodes[loca].fa=u;
//                break;
//            }
//            else u=nodes[u].left;
//        }
//    }
//    if(root==0) root=loca;
//    balance(loca);
//}
//void check1(int temp,int tmp){
//    if(nodes[temp].val<nodes[tmp].val)nodes[tmp].left=temp;
//    else nodes[tmp].right=temp;
//}
//void update(int u) {
//    while (u != root) {
//        if (nodes[u].right != 0)nodes[u].rh = nodes[nodes[u].right].h + 1;//child exist
//        if (nodes[u].left != 0)nodes[u].lh = nodes[nodes[u].left].h + 1;
//        u = nodes[u].fa;
//    }
//}
//void balance(int u){//思考如何修正（修正了根但leaf还是不平衡）
//    //？？？每次insert一个点，从leaf往上搜索，找到第一个不平衡的结点修正即可
//    //插入点的父亲平衡，不代表父亲的父亲平衡（同理，要一直往上递归到根）
//    int temp=0,tmp=0;
//    while(u!=root){
//        if(abs(nodes[nodes[u].fa].lh-nodes[nodes[u].fa].rh)==2){
//            if(nodes[nodes[u].fa].lh-nodes[nodes[u].fa].rh==2){//
//                 tmp=nodes[nodes[u].fa].fa;
//                 if(nodes[u].lh-nodes[u].rh>=0){//left-left
//                        temp=nodes[u].fa;
//                        nodes[nodes[u].right].fa=temp;
//                        nodes[temp].left=nodes[u].right;
//                        nodes[u].right=temp;
//                        nodes[temp].fa=u;
//                        nodes[u].fa=tmp;
//                        if(tmp==0)root=u;//root change
//                        else check1(u,tmp);
//                 }
//                 else{//left-right
//                         temp=nodes[u].right;
//                         nodes[nodes[temp].left].fa=u;
//                         nodes[u].right=nodes[temp].left;
//                         nodes[nodes[temp].right].fa=nodes[u].fa;
//                         nodes[nodes[u].fa].left=nodes[temp].right;
//                         nodes[temp].right=nodes[u].fa;
//                         nodes[nodes[u].fa].fa=temp;
//                         nodes[temp].left=u;
//                         nodes[u].fa=temp;
//                         nodes[temp].fa=tmp;
//                         if(tmp==0)root=temp;
//                         else check1(temp,tmp);
//                         if(nodes[u].right!=0)nodes[u].rh=nodes[nodes[u].right].h+1;
//                         if(nodes[nodes[temp].right].left!=0)nodes[nodes[temp].right].lh=nodes[nodes[nodes[temp].right].left].h+1;
//                         //update(temp)无法涉及到
//                    }
//                }
//            else{//-2
//                tmp=nodes[nodes[u].fa].fa;
//                if(nodes[u].rh-nodes[u].lh>=0){//right-right
//                    temp=nodes[u].fa;
//                    nodes[nodes[u].left].fa=temp;
//                    nodes[temp].right=nodes[u].left;
//                    nodes[u].left=temp;
//                    nodes[temp].fa=u;
//                    nodes[u].fa=tmp;//tmp==0 也可以
//                    if(tmp==0)root=u;
//                    else check1(u,tmp);
//                }
//                else{//right-left
//                    temp=nodes[u].left;
//                    nodes[nodes[temp].right].fa=u;
//                    nodes[u].left=nodes[temp].right;
//                    nodes[nodes[temp].left].fa=nodes[u].fa;
//                    nodes[nodes[u].fa].right=nodes[temp].left;
//                    nodes[temp].left=nodes[u].fa;
//                    nodes[nodes[u].fa].fa=temp;
//                    nodes[temp].right=u;
//                    nodes[u].fa=temp;
//                    nodes[temp].fa=tmp;
//                    if(tmp==0)root=temp;
//                    else check1(temp,tmp);
//                    if(nodes[u].left!=0)nodes[u].lh=nodes[nodes[u].left].h+1;
//                    if(nodes[nodes[temp].left].right!=0)nodes[nodes[temp].left].rh=nodes[nodes[nodes[temp].left].right].h+1;
//                    //update(temp)无法涉及到
//                }
//            }
//            update(temp);
//            break;
//        }
//        u=nodes[u].fa;
//        }
//    }
//int succesor(int val){
//    int u=root,ans=0;//ans==0 不存在
//    while(u!=0){
//        if(nodes[u].val<=val)u=nodes[u].right;//注意这里不能找到相等的自己（故之前安排方向  左：<  右：>=）
//        else{//>
//            ans=u;
//            u=nodes[u].left;
//        }
//    }
//    return ans;
//}
//void delete1(int val){
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
//        }//不可能有左子树
//        else {
//            if(nodes[v].val<nodes[nodes[v].fa].val)nodes[nodes[v].fa].left=0;
//            else nodes[nodes[v].fa].right=0;
//        }
//    }
//    else if(nodes[u].left>0){
//        if(nodes[u].val<nodes[nodes[u].fa].val)nodes[nodes[u].fa].left=nodes[u].left;
//        else nodes[nodes[u].fa].right=nodes[u].left;
//    }
//    else {
//        if(nodes[u].val<nodes[nodes[u].fa].val)nodes[nodes[u].fa].left=0;
//        else nodes[nodes[u].fa].right=0;
//    }
//}
//int main(){
//    return 0;
//}