//#include <iostream>
//#include <algorithm>
//#include <cmath>
//struct node{
//    long long cor[3];int id;
//    node* left=NULL;node* right=NULL;
//    node(){cor[0]=cor[1]=cor[2]=0;id=0;}
//};
//node nsX[500005],ns[500005],copy[500005];
//node a,b,m,n,p,q,ans1,ans2;
//long long min=2000000000,INF=1e30,dSearch=INF,me;
//double cal(node x, node y, int mode1,int mode2){
//    return sqrt(pow(x.cor[mode1]-y.cor[mode1],2)+pow(x.cor[mode2]-y.cor[mode2],2));
//}
//int comX(node a,node b){
//    if(a.cor[0]==b.cor[0]){
//        if(a.cor[1]==b.cor[1])return a.cor[2]<b.cor[2];
//        else return a.cor[1]<b.cor[1];
//    }
//    else return a.cor[0]<b.cor[0];
//}
//int comY(node a,node b){
//    if(a.cor[1]==b.cor[1])return a.cor[2]<b.cor[2];
//    else return a.cor[1]<b.cor[1];
//}
//int comZ(node a,node b){
//    return a.cor[2]<b.cor[2];
//}
//double tmp1,tmp2,tmp3; double d,d1,d2;
//void check2(node *nsY,node *copyY,int l,int r,int mode1,int mode2){
//    if(r-l<3){
//        if(l==r){
//            ans1=nsX[l];
//            return;
//        }
//        else if(l==r-1){
//            ans1=nsX[l];ans2=nsX[r];
//            d=cal(nsX[l],nsX[r],mode1,mode2);
//            return;
//        }
//        else{
//            tmp1=cal(nsX[l],nsX[l+1],mode1,mode2);tmp2=cal(nsX[l+1],nsX[l+2],mode1,mode2);tmp3=cal(nsX[l],nsX[l+2],mode1,mode2);
//            if(tmp1<=tmp2&&tmp1<=tmp3){
//                ans1=nsX[l];ans2=nsX[l+1];
//                d=tmp1;
//            }
//            else if(tmp2<=tmp1&&tmp2<=tmp3){
//                ans1=nsX[l+1];ans2=nsX[l+2];
//                d=tmp2;
//            }
//            else{
//                ans1=nsX[l];ans2=nsX[l+2];
//                d=tmp3;
//            }
//            return;
//        }
//    }
//    int mid=(l+r)>>1;
//    int ll=l,rr=mid+1,k=l;
//    for(int i=l;i<=r;i++){
//        if((nsY+i)->id<=mid)*(copyY+ll++)=*(nsY+i);
//        else *(copyY+rr++)=*(nsY+i);
//    }
//    check2(copyY,nsY,l,mid,mode1,mode2);
//    a=ans1;b=ans2;d1=d;
//    check2(copyY,nsY,mid+1,r,mode1,mode2);
//    m=ans1;n=ans2;d2=d;
//    if(d1>d2){
//        d=d2;
//        ans1=m;ans2=n;
//    }
//    else {
//        d=d1;
//        ans1=a;ans2=b;
//    }
//
//    ll=l;rr=mid+1;
//    while(ll<=mid||rr<=r){  // 重新构造nsY
//        if(rr>r||(rr<=r&&ll<=mid&&(copyY+ll)->cor[mode2]<(copyY+rr)->cor[mode2]))
//            *(nsY+k++)=*(copyY+ll++);
//        else *(nsY+k++)=*(copyY+rr++);
//    }
//
//    k=l;
//    for(int i=l;i<=r;i++){
//        if((nsX[mid].cor[mode1]-(nsY+i)->cor[mode1])<=d&&(nsX[mid].cor[mode1]-(nsY+i)->cor[mode1])>=-d)
//            *(copyY+k++)=*(nsY+i);
//    }
//
//    int count=0; double dNew=0;
//    for(int i=l;i<k;i++){
//        count=i+1;
//        while(count<k&&(copyY+count++)->cor[mode2]-(copyY+i)->cor[mode2]<=d){
//            dNew=cal(*(copyY+count),*(copyY+i),mode1,mode2);
//            if(d>dNew){
//                if((copyY+count)->cor[mode1]==(copyY+i)->cor[mode1]){
//                    if((copyY+count)->cor[mode2]<(copyY+i)->cor[mode2]){
//                        ans1=*(copyY+count);ans2=*(copyY+i);
//                    }
//                    else {
//                        ans2=*(copyY+count);ans1=*(copyY+i);
//                    }
//                }
//                else if((copyY+count)->cor[mode1]<(copyY+i)->cor[mode2]){
//                    ans1=*(copyY+count);ans2=*(copyY+i);
//                }
//                else {
//                    ans2=*(copyY+count);ans1=*(copyY+i);
//                }
//                d=dNew;
//            }
//        }
//    }
//}
//
//void check3(int t){
//    for(int i=1;i<=t;i++){
//        for(int j=0;j<3;j++)ns[i].cor[j]=nsX[i].cor[j];
//        ns[i].id=nsX[i].id=i;
//    }
//    std::sort(ns+1,ns+t+1,comY);
//    check2(ns,copy,1,t,0,1);
//    tmp1=sqrt(pow(ans1.cor[0]-ans2.cor[0],2+pow(ans1.cor[1]-ans2.cor[1],2)+pow(ans1.cor[2]-ans2.cor[2],2)));
//    a=ans1;b=ans2;
//    std::sort(ns+1,ns+t+1,comZ);
//    check2(ns,copy,1,t,0,2);
//    tmp2=sqrt(pow(ans1.cor[0]-ans2.cor[0],2+pow(ans1.cor[1]-ans2.cor[1],2)+pow(ans1.cor[2]-ans2.cor[2],2)));
//    m=ans1;n=ans2;
//    std::sort(nsX+1,nsX+t+1,comY);
//    for(int i=1;i<=t;i++){
//        for(int j=1;j<3;j++)ns[i].cor[j]=nsX[i].cor[j];
//        ns[i].id=nsX[i].id=i;
//    }
//    std::sort(ns+1,ns+t+1,comZ);
//    check2(ns,copy,1,t,1,2);
//    tmp3=sqrt(pow(ans1.cor[0]-ans2.cor[0],2+pow(ans1.cor[1]-ans2.cor[1],2)+pow(ans1.cor[2]-ans2.cor[2],2)));
//    p=ans1;q=ans2;
//    if(tmp1<=tmp2&&tmp1<=tmp3){
//        if(comX(a,b)){
//            ans1=a;ans2=b;
//        }
//        else{
//            ans2=a;ans1=b;
//        }
//    }
//    else if(tmp2<=tmp1&&tmp2<=tmp3){
//        if(comX(m,n)){
//            ans1=m;ans2=n;
//        }
//        else{
//            ans2=m;ans2=n;
//        }
//    }
//    else{
//        if(comX(p,q)){
//            ans1=p;ans2=q;
//        }
//        else{
//            ans2=p;ans1=q;
//        }
//    }
//}
//int main(){
//    int t,d;
//    scanf("%d%d",&t,&d);
//    for(int i=1;i<=t;i++){
//        for(int j=0;j<d;j++){
//            scanf("%lld",&nsX[i].cor[j]);
//        }
//    }
//    std::sort(nsX+1,nsX+t+1,comX);
//    if(d==1){
//        for(int i=1;i<t;i++){
//            if((nsX[i+1].cor[0]-nsX[i].cor[0])<min){
//                min=nsX[i+1].cor[0]-nsX[i].cor[0];
//                ans1=nsX[i];ans2=nsX[i+1];
//            }
//        }
//        printf("%lld\n%lld",ans1.cor[0],ans2.cor[0]);
//    }
//    else if(d==2){
//        for(int i=1;i<=t;i++){
//            for(int j=0;j<2;j++)ns[i].cor[j]=nsX[i].cor[j];
//            ns[i].id=nsX[i].id=i;
//        }
//        std::sort(ns+1,ns+t+1,comY);
//        check2(ns, copy,1,t,0,1);
//        printf("%lld %lld\n%lld %lld",ans1.cor[0],ans1.cor[1],ans2.cor[0],ans2.cor[1]);
//
//    }
//    else{//d==3
//        check3(t);
//        printf("%lld %lld %lld\n%lld %lld %lld",ans1.cor[0],ans1.cor[1],ans1.cor[2],ans2.cor[0],ans2.cor[1],ans2.cor[2]);
//    }
//    return 0;
//}