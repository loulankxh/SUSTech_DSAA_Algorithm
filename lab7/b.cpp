//#include <iostream>
//int n=100005;
//bool flag=true;
//struct node{
////    node* father,*left,*right;//是不是里面只能出现地址而不能出现node这种结构体？
//    int father,left,right,value;
//    node(){father=left=right=value=0;}//NULL与nullptr有什么区别？
//
//};
//node nodes[100005];
//int queue[100005];
//int rear=0,front=0,stop=0;
//void initial(){
//    flag=true;
//    rear=front=stop=0;
//    for(int i=0;i<100005;i++)nodes[i].left=nodes[i].right=nodes[i].father=nodes[i].value=0;//不一定有左右节点
//    //故上一次的输入可能会影响到下一次
//}
//int relation(int a,int b){
//    if(a>b)return 1;
//    else if(a==b)return 0;
//    else return -1;
//}
//int fingRoot(){
//    for(int i=1;i<=n;i++){
//        if(nodes[i].father==0)return i;
//    }
//    return 0;
//}
//bool  judge(int root,int me){
//    if(nodes[root].left!=0){
//        if(stop) return false;
//        if((me==1&&nodes[root].value<nodes[nodes[root].left].value)||(me==-1&&nodes[root].value>nodes[nodes[root].left].value))
//            return false;//不合法情况
//        if(me==0)me=relation(nodes[root].value,nodes[nodes[root].left].value);//要求变精细
//        queue[rear++]=nodes[root].left;//注意不是++rear,就是这里错了欸
//        //不能把右节点放在左节点里面讨论，错误：没有左节点但有右节点（正确情况下不会错，但错误情况下会）
//    }
//    else stop=1;
//    if(nodes[root].right!=0){
//        if(stop) return false;
//        if((me==1&&nodes[root].value<nodes[nodes[root].right].value)||(me==-1&&nodes[root].value>nodes[nodes[root].right].value))
//            return false;//不合法情况
//        if(me==0)me=relation(nodes[root].value,nodes[nodes[root].right].value);
//        queue[rear++]=nodes[root].right;
//    }
//    else stop=1;
//    if(front<rear) return judge(queue[front++],me);
//    return true;//到最终也没有被中止（没有遇到不合法的情况）
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    for(int k=1;k<=t;k++){
//        initial();
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++){
//            scanf("%d",&(nodes[i].value));
//        }
//        int a=0,b=0;
//        for(int i=1;i<n;i++){
//            scanf("%d%d",&a,&b);
//            if(flag&&nodes[a].left==0){
//                nodes[a].left=b;
//                nodes[b].father=a;
//            }
//            else if(flag&&nodes[a].right==0){
//                nodes[a].right=b;
//                nodes[b].father=a;
//            }
//            else{
//                flag=false;
////                break;不能break，否则没有读完的输入会干扰下一次
//            }
//        }
//        int root=0,me=0;
//        if(flag&&n>1){
//            root=fingRoot();
//            if(nodes[root].left!=0){//不完整。错误情况可能第一个left就为空
//                flag=judge(root,me);
//            }
//            else flag=false;//n>1前提
//        }
//        if(flag) printf("Case #%d: YES\n",k);
//        else printf("Case #%d: NO\n",k);
//    }
//    return 0;
//}