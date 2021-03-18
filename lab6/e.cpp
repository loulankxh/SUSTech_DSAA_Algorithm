//#include <iostream>
//int head[100005];
//int cnt=0;
//struct edge{
//    int to,next,visit;
//    edge(){to=-1,next=-1,visit=0;}
//};
//edge edges[100005];
//int ans=0;
//struct node{
//    int red,blue,visit;
//    node(){red=0;blue=0;visit=0;}
//};
//node nodes[100005];
//void init(){
//    ans=0;
//    cnt=0;
//    for(int i=0;i<100005;i++){
//        head[i]=-1;
//        nodes[i].visit=0;
//        nodes[i].blue=0;
//        nodes[i].red=0;
//    }
//}
//void build(int a,int b){
//    edges[cnt].to=b;
//    edges[cnt].next=head[a];
//    head[a]=cnt++;
//    edges[cnt].to=a;
//    edges[cnt].next=head[b];
//    head[b]=cnt++;
//}
//void dfs(int x,int re,int bl){
//    nodes[x].visit=1;
//    for(int i=head[x];i!=-1;i=edges[i].next){
//        if(nodes[edges[i].to].visit);
////            if(i==head[x]){//x:叶子结点
//        else{
//            dfs(edges[i].to,re,bl);
//            nodes[x].red+=nodes[edges[i].to].red;
//            nodes[x].blue+=nodes[edges[i].to].blue;
//        }
//    }
//    bool flag=(re==nodes[x].red&&nodes[x].blue==0)||(bl==nodes[x].blue&&nodes[x].red==0);
//    if(x!=1&&flag)ans++;//node1上方没有边了
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        init();
//        int n;
//        scanf("%d",&n);
//        int a=0,b=0;
//        for(int i=0;i<n-1;i++){
//            scanf("%d%d",&a,&b);
//            build(a,b);
//        }
//        int colour=0,re=0,bl=0;
//        for(int i=1;i<=n;i++){//结点从1开始
//            scanf("%d",&colour);
//            if(colour==1){
//                nodes[i].red=1;
//                re++;
//            }
//            else if(colour==2){
//                nodes[i].blue=1;
//                bl++;
//            }
////            else{//为0的结点初始化也不能漏——不如全放到init里面去
////                nodes[i].blue=0;
////                nodes[i].red=0;
////            }
//        }
//        dfs(1,re,bl);
//        printf("%d\n",ans);
//    }
//    return 0;
//}