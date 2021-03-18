//#include <iostream>
//struct edge{
//    int u,v,next;
//    edge(){u=v=0;}
//};
//int head[70];int dot[70];
//edge es[280];int cnt=1;
//int visit[70];
//int n,count,length;long long ans=0;
//void add(int u, int v){
//    es[cnt].u=u;es[cnt].v=v;es[cnt].next=head[u];head[u]=cnt++;
//    es[cnt].u=v;es[cnt].v=u;es[cnt].next=head[v];head[v]=cnt++;
//
//}
//int checkPoint1(int u){
//    int num=0,a=u%n,b=u/n;
//    if(a==n-1||(a!=n-1&&visit[u+1]==1)) num++;//右边不通
//    if(a==0||(a!=0&&visit[u-1]==1)) num++;//左边
//    if(b==0||(b!=0&&visit[u-n]==1)) num++;//上边
//    if(b==n-1||(b!=n-1&&visit[u+n]==1)) num++;//下边
//    return num;
//}
//void DFS(int u){
//    visit[u]=1;length++;//路长
//    int onlyOneWay=0,dot=0;
//    for(int i=head[u];i!=0;i=es[i].next){
//        if(visit[es[i].v]==0){
//            if(checkPoint1(es[i].v)==3&&es[i].v!=n*n-n){
//                onlyOneWay++;
//                dot=es[i].v;
//            }
//        }
//    }
//    if(onlyOneWay==1)DFS(dot);
//    else if(onlyOneWay==0){
//        int a=u%n,b=u/n, blank=0;
//        for(int i=head[u];i!=0;i=es[i].next){
//            if(visit[es[i].v]==0){
//                if(es[i].v!=n*n-n){//没到终点
//                    if(es[i].v==u-1||es[i].v==u+1){//左边、右边
//                        if(b>0&&visit[u-n]==0&&b<n-1&&visit[u+n]==0){//上面下面都未经过
//                            for(int i=0;i<n;i++) if(visit[b*n+i]==0)blank++;//有缺口
//                            if(blank>1)DFS(es[i].v);
//                        }
//                        else DFS(es[i].v);
//                    }
//                    else{//上面、下面
//                        if(a>0&&visit[u-1]==0&&a<n-1&&visit[u+1]==0){//左边、右边都未经过
//                            for(int i=0;i<n;i++) if(visit[i*n+a]==0)blank++;
//                            if(blank>1)DFS(es[i].v);
//                        }
//                        else DFS(es[i].v);
//                    }
//                }
//                else{//下一个点是终点
//                    if(length==count-1)ans++;
//                }
//            }
//        }
//    }//>=2是不行的，直接返回
//    length--;//这一个点的已经找完了
//    visit[u]=0;
//    return;
//}
//int main(){
//    scanf("%d",&n);
//    getchar();// \n
//    char x;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            x=getchar();
//            if(x-'.'==0){
//                dot[n*i+j]=1;
//                count++;//总共需经历多少个点
//            }
//            else visit[n*i+j]=1;//不可经过的障碍
//            if(j==n-1) getchar();//换行
//        }
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(dot[n*i+j]==1){
//                if(j<n-1&&dot[n*i+j+1]==1)add(n*i+j,n*i+j+1);
//                if(i<n-1&&dot[n*i+j+n]==1)add(n*i+j,n*i+j+n);
//            }
//        }
//    }
//    DFS(0);
//    printf("%lld",ans);
//    return 0;
//}