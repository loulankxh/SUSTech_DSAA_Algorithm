#include <iostream>
struct edge{
    int u,v,next;
    edge(){u=v=next=0;}
};
struct node{
    int x,y,r,t;
    node(){x=y=r=t=0;}
};
node ns[1005];
edge e1[1000005],e2[1000005];int head1[1005];int head2[1005];int s[1005];int v1[1005];int v2[1005];int suoDian[1005];
int deg[1005];int val[1005];
int num=1,top=0,ans=0;
void add(int u,int v){
    e1[num].u=u;e1[num].v=v;e1[num].next=head1[u];head1[u]=num;
    e2[num].u=v;e2[num].v=u;e2[num].next=head2[v];head2[v]=num++;
}
void DFSR(int x){
    v2[x]=1;
    for(int i=head2[x];i!=0;i=e2[i].next){
        if(v2[e2[i].v]==0)DFSR(e2[i].v);
    }
    s[++top]=x;
}
int DFS(int x,int sequence){
    int tmp=0,flag=0,tt=0;
    v1[x]=1;suoDian[x]=sequence;
    for(int i=head1[x];i!=0;i=e1[i].next){
        if(v1[e1[i].v]==0){
            tt=DFS(e1[i].v,sequence);
            if(tmp==0||tmp>tt)tmp=tt;
            flag=1;
        }
        else if(sequence!=suoDian[e1[i].v])deg[suoDian[e1[i].v]]=1;
    }
    if(flag) return ns[x].t>tmp?tmp:ns[x].t;
    else return ns[x].t;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&ns[i].x,&ns[i].y,&ns[i].r,&ns[i].t);
    }
    long long tt1=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            tt1=(long long)(ns[i].x-ns[j].x)*(ns[i].x-ns[j].x)+(long long)(ns[i].y-ns[j].y)*(ns[i].y-ns[j].y);
            if(tt1<=ns[i].r*ns[i].r)add(i,j);
            if(tt1<=ns[j].r*ns[j].r)add(j,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(v2[i]==0)DFSR(i);
    }
    int sequence=0;
    for(int i=n;i>=1;i--){
        if(v1[s[i]]==0)val[++sequence]=DFS(s[i],sequence);
    }
    for(int i=1;i<=sequence;i++){
        if(deg[i]==0)ans+=val[i];
    }
    printf("%d",ans);
    return 0;
}