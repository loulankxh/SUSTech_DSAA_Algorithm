//#include <iostream>
//#include <algorithm>
//#include <cmath>
//struct node{
//    double x,y;int vis;
//    node(){x=y=0;vis=1;}
//};
//node ns[500005], p0;
//node stack[500005];
//int top=0,ans=0;
//double calCha(node a,node b){
//    return (a.x-p0.x)*(b.y-p0.y)-(b.x-p0.x)*(a.y-p0.y);
//}
//double chaji=0;
//int com(node a,node b){
//    if(p0.x==a.x&&p0.y==a.y)return 1;
//    if(p0.x==b.x&&p0.y==b.y)return 0;
//    chaji=calCha(a,b);
//    if(chaji==0)
//        return (pow(a.x-p0.x,2)+pow(a.y-p0.y,2))>(pow(b.x-p0.x,2)+pow(b.y-p0.y,2));
//    else return chaji>0;
//}
//int main(){
//    int n;double minY=1000000000;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        scanf("%lf%lf",&ns[i].x,&ns[i].y);
//        // &ns[i] 是这个数组的地址，不是这个点对象的？？？
//        if(minY>ns[i].y){
//            minY=ns[i].y;
//            p0=ns[i]; //不随点边，就是在数组的这个地方
//            // p0 = &ns[i] 是数组的地址，不会随着sort之后的点变化
//        }
//    }
//    std::sort(ns+1,ns+n+1,com);
//    double me=0;
//    for(int i=3;i<=n;i++){
//        me=calCha(ns[i],ns[i-1]);
//        if(me==0) ns[i].vis=0;
//    }
//    int ini=0;double pj=0,p1=0;
//    for(int i=1;i<=n;i++){  //第二次筛选
//        if(ns[i].vis==1){
//            if(top>2){
//                ini=top;
//                for(int j=ini;j>2;j--){
//                    pj=(ns[i].y-stack[j-1].y)*stack[j].x-(ns[i].x-stack[j-1].x)*stack[j].y-stack[j-1].x*ns[i].y+ns[i].x*stack[j-1].y;
//                    p1=(ns[i].y-stack[j-1].y)*stack[1].x-(ns[i].x-stack[j-1].x)*stack[1].y-stack[j-1].x*ns[i].y+ns[i].x*stack[j-1].y;
//                    if(p1*pj>0)
//                        top--;
//                    else break;
//                }
//            }
//            stack[++top]=ns[i];
//        }
//    }
//    ans=top;
//    for(int i=2;i<=n;i++){
//        if(ns[i].vis==0){
//            if(calCha(ns[i],stack[2])==0||calCha(ns[i],stack[top])==0) ans++;
//        }
//    }
//    printf("%d",ans);
//    return 0;
//}