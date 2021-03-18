//#include <iostream>
//struct edge{
//    int u,v,next;
//    edge(){u=v=next=0;}
//};
//edge e1[200005],e2[200005];int head1[200005];int head2[200005];int queue[200005];int v1[200005];int v2[200005];
//int num=1,f=0,r=0;
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
//void add(int u,int v){
//    e1[num].u=u;e1[num].v=v;e1[num].next=head1[u];head1[u]=num;
//    e2[num].u=v;e2[num].v=u;e2[num].next=head2[v];head2[v]=num++;
//}
//void DFSR(int x){
//    v2[x]=1;
//    for(int i=head2[x];i!=0;i=e2[i].next){
//        if(v2[e2[i].v]==0)DFSR(e2[i].v);
//    }
//    queue[r++]=x;
//}
//void DFS(int x){
//    v1[x]=1;
//    for(int i=head1[x];i!=0;i=e1[i].next){
//        if(v1[e1[i].v]==0)DFS(e1[i].v);
//    }
//}
//int main(){
//    int n,m,u,v;
//    fastRead(n);fastRead(m);
//    for(int i=1;i<=m;i++){
//        fastRead(u);fastRead(v);
//        add(u,v);
//    }
//    for(int i=1;i<=n;i++){
//        if(v2[i]==0)DFSR(i);
//    }
//    int flag=1;
//    DFS(queue[--r]);//最后一个
//    //并不是DFS遍历一遍全都访问过就行（没有按照算法，访问过！=不等于强连通）
//    for(int i=1;i<=n;i++){
//        if(v1[i]==0){
//            flag=0;
//            break;
//        }
//    }
//    if(flag)printf("Bravo");
//    else printf("ovarB");
//    return 0;
//}