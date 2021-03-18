//#include <iostream>
//#include <algorithm>
//#include <cmath>
//struct node{
//    double x,y;
//    node(){x=y=0;}
//};
//node ns[500005], *p0=NULL;
//node stack1[500005],stack2[500005];
//int top1=0,top2=0,ans=0;
//double calCha(node a,node b){
//    return (a.x-p0->x)*(b.y-p0->y)-(b.x-p0->x)*(a.y-p0->y);
//}
//double chaji=0;
//int com(node a,node b){
//    chaji=calCha(a,b);
//    if(chaji==0) return (pow(a.x-p0->x,2)+pow(a.y-p0->y,2))>(pow(b.x-p0->x,2)+pow(b.y-p0->y,2));
//    else return chaji>0;
//}
//int main(){
//    int n;double minY=1000000000;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        scanf("%lf%lf",&ns[i].x,&ns[i].y);
//        if(minY>ns[i].y){
//            minY=ns[i].y;
//            p0=&ns[i];
//        }
//    }
//    //严重精度问题
////    for(int i=1;i<=n;i++){
//////        if(&ns[i]==&p0)ns[i].cos=2; //这样地址并不相等
////        if(&ns[i]==p0)ns[i].cos=2;
////        else{
////            ns[i].z=sqrt((ns[i].x-p0->x)*(ns[i].x-p0->x)+(ns[i].y-p0->y)*(ns[i].y-p0->y));
////            ns[i].cos=(double)(ns[i].x-p0->x)/ns[i].z; // 不能全部平方！！正负无法区分
////        }
////    }
//    std::sort(ns+1,ns+n+1,com);
//    stack1[++top1]=ns[1];
//    for(int i=2;i<=n;i++){//第一次筛选
//        if(calCha(ns[i],stack1[top1])<0) stack1[++top1]=ns[i];
//    }
//    int ini=0;double pj=0,p1=0;
//    for(int i=1;i<=top1;i++){  //第二次筛选
//        if(i>3){
//            ini=top2;
//            for(int j=ini;j>2;j--){ //check 某一点能否留下
//                //直线方程式：(y2-y1)x-(x2-x1)y-x1y2+x2y1=0
//                pj=(stack1[i].y-stack2[j-1].y)*stack2[j].x-(stack1[i].x-stack2[j-1].x)*stack2[j].y-stack2[j-1].x*stack1[i].y+stack1[i].x*stack2[j-1].y;
//                p1=(stack1[i].y-stack2[j-1].y)*stack2[1].x-(stack1[i].x-stack2[j-1].x)*stack2[1].y-stack2[j-1].x*stack1[i].y+stack1[i].x*stack2[j-1].y;
//                if(p1*pj>0)   // on:>   vertex:>=
//                    top2--; //检验一点是否能留下，只需与其上一个点连线：j-1
//                else break;//若此点能留下则其后面的点也必然能留下
//            }
//        }
//        stack2[++top2]=stack1[i];
//    }
//    ans=top2;
//    for(int i=2;i<=n;i++){
//        if(calCha(ns[i],stack2[2])==0||calCha(ns[i],stack2[top2])==0){
//            if((ns[i].x==stack2[2].x&&ns[i].y==stack2[2].y)||(ns[i].x==stack2[top2].x&&ns[i].y==stack2[top2].y));
//            else ans++;
//        }
//    }
//    printf("%d",ans);
//    return 0;
//}