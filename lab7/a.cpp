//#include <iostream>
//int nodes[150005][2];
//int qe[150005];
//int a[150005];
//int front=0,rear=0;
//int flag=1,flag2=1;
//void bfs(int x,int size){
//    if(nodes[x][0]!=0){
//        if(flag)qe[rear++]=nodes[x][0];
//        else {
//            flag2=0;
//            return;
//        }
//    }
//    else flag=0;
//    if(nodes[x][1]!=0){
//        if(flag)qe[rear++]=nodes[x][1];
//        else{
//            flag2=0;
//            return;
//        }
//    }
//    else flag=0;
//    if(front<size-1) bfs(qe[front++],size);//front<size-1否则死循环
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        flag=flag2=1;
//        front=rear=0;
//        int n;
//        scanf("%d",&n);
//        for(int i=1;i<=n;i++)a[i]=0;
//        for(int i=1;i<=n;i++){
//            scanf("%d%d",&nodes[i][0],&nodes[i][1]);
//            a[nodes[i][0]]=1;
//            a[nodes[i][1]]=1;
//        }
//        for(int i=1;i<=n;i++){
//            if(a[i]==0){
//                bfs(i,n);//没有说明谁是根！
//                //有孩子节点不代表其就是根！
//                break;
//            }
//        }
//        if(flag2)printf("Yes\n");
//        else printf("No\n");
//    }
//    return 0;
//}