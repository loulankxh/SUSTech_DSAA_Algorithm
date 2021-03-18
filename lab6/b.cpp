//#include <iostream>
//int n;
////struct node{
////    int last, next,visit;
////    node() {last = -1; next = -1;visit=0;}
////};
//struct edge{
//    int to,next;
//    edge(){next=-1;}
//};
//edge edges[200005];
//int head[100005];//某个点的最后一条相邻边
//int visit[100005];//某个节点是否被访问过
//int depths[100005];//节点的深度
//int cnt=0;
//void init(){
//    cnt=0;
//    for(int i=0;i<100005;i++){
//        head[i]=-1;
//        visit[i]=0;
//    }
//}
////void build(int a,int b){
////    nodes[b].next=nodes[a].last;
////    nodes[a].last=b;
////    nodes[a].next=nodes[b].last;//点（在父节点的位置）的next会乱
////    nodes[b].last=a;
////}
////void dfs(int x){
////    nodes[x].visit=1;
////    for(int i=nodes[x].last;i!=-1;i=nodes[i].next){
////}
//void build(int a,int b){
//    edges[cnt].to=b;
//    edges[cnt].next=head[a];
//    head[a]=cnt++;
//    edges[cnt].to=a;
//    edges[cnt].next=head[b];
//    head[b]=cnt++;
//}
//void dfs(int x,int d){
//    visit[x]=1;
//    depths[x]=d;
//    for(int i=head[x];i!=-1;i=edges[i].next){
//        if(visit[edges[i].to]);
////            depth=depth>d?depth:d;//遍历过了
////这样去找最深的深度
//        else{
//            dfs(edges[i].to,d+1);//这样去确定深度而不是找一个地方对depth++
//            //好好理解这种逻辑！
//        }
//    }
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%d",&n);
//        int a,b;
//        init();
//        for(int i=1;i<n;i++){
//            scanf("%d%d",&a,&b);
//            build(a,b);
//        }
//        dfs(1,0);
//        for(int i=1;i<=n;i++){
//            printf("%d ",depths[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}