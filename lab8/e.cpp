//#include <iostream>
//struct edge{
//    int u,v,next;
//    edge(){u=v=next=0;}
//};
//edge e[400005];
//int head[200005];int visit[200005];int stack[200005];int tree[200005];int deg[200005];
//int num=1,top=-1,size=0;
//void init(int n){
//    num=1;top=-1;size=0;
//    for(int i=0;i<=n;i++)deg[i]=stack[i]=visit[i]=head[i]=tree[i]=0;//stack要初始化，因为一开始有其他的作用
//}
//void add(int u,int v){
//    e[num].u=u;e[num].v=v;e[num].next=head[u];head[u]=num++;
//}
//void insert(int val){
//    tree[++size]=val;int t=size;
//    while(t/2>0&&tree[t/2]<tree[t]){
//        tree[t/2]^=tree[t];
//        tree[t]^=tree[t/2];
//        tree[t/2]^=tree[t];
//        t=t/2;
//    }
//}
//void deleteMax(){
//    stack[++top]=tree[1];
//    int t=1;tree[1]=tree[size--];
//    while(((long long)2*t<=(long long)size&&tree[2*t]>tree[t])||((long long)2*t<(long long)size&&tree[2*t+1]>tree[t])){
//        if((long long)2*t<(long long)size&&tree[2*t+1]>tree[2*t]){
//            tree[2*t+1]^=tree[t];
//            tree[t]^=tree[2*t+1];
//            tree[2*t+1]^=tree[t];
//            t=2*t+1;
//        }
//        else{
//            tree[2*t]^=tree[t];
//            tree[t]^=tree[2*t];
//            tree[2*t]^=tree[t];
//            t=2*t;
//        }
//    }
//}
//void BFS(){
//    int u;
//    while(size>0){//tn=size+1
//        u=tree[1];deleteMax();
//        for(int i=head[u];i!=0;i=e[i].next){
//            deg[e[i].v]--;
//            if(!visit[e[i].v]&&deg[e[i].v]==0){
//                visit[e[i].v]=1;
//                insert(e[i].v);
//            }
//        }
//    }
//}
//void fastRead(int& in){
//    in=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9')ch=getchar();
//    while(ch>='0'&&ch<='9')
//    {
//        in*=10;
//        in+=ch-'0';
//        ch=getchar();
//    }
//}
//int main(){
//    int t,n,m,u,v;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%d%d",&n,&m);init(n);
//        for(int i=0;i<m;i++){
//            fastRead(u);fastRead(v);
//            deg[u]++;
//            add(v,u);//想清楚谁在谁前
//        }
//        for(int i=1;i<=n;i++){
//            if(deg[i]==0){
//                insert(i);
//                visit[i]=1;
//            }
//        }
//        BFS();
//        while(top>=0)printf("%d ",stack[top--]);//top=size+1//故最好是++top  initial=-1
//        printf("\n");
//    }
//    return 0;
//}