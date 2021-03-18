#include <iostream>
#include <algorithm>
#include <cmath>
struct node{
    long long cor[3];int id;
    node* left=NULL;node* right=NULL;
    node(){cor[0]=cor[1]=cor[2]=0;id=0;}
};
node nsX[500005],ns[500005],copy[500005];
node a,b,m,n,ans1,ans2,*root=NULL,*p;
long long min=2000000000,INF=1e30,dSearch=INF,me;
double cal(node x, node y, int mode){
    if(mode==2)
        return sqrt(pow(x.cor[0]-y.cor[0],2)+pow(x.cor[1]-y.cor[1],2));
    else if(mode==3)
        return sqrt(pow(x.cor[0]-y.cor[0],2)+pow(x.cor[1]-y.cor[1],2)+pow(x.cor[2]-y.cor[2],2));
}
void insert(node *a){
    if(root==NULL){
        root=a;
        a->left=NULL;a->right=NULL;
    }
    else{
        p=root;
        while(true){
            if(a->cor[1]<=p->cor[1]){
                if(p->left==NULL){
                    p->left=a;
                    return;
                }
                p=p->left;
            }
            else{
                if(p->right==NULL){
                    p->right=a;
                    return;
                }
                p=p->right;
            }
        }
    }
}
void search(node *x,node *r,double d){
    if(r->cor[2]-x->cor[2]<=d){ //z越来越大
        if(r->cor[2]-x->cor[2]>=-d&&r->cor[1]-x->cor[1]<=d&&r->cor[1]-x->cor[1]>=-d){
            me=cal(*r,*x,3);
            if(d>me&&dSearch>me){
                dSearch=me;
                p=r;
            }
        }
        if(r->cor[1]-x->cor[1]<=d){//y还可以变大
            if(r->right!=NULL)search(x,r->right,d);
        }
        if(r->cor[1]-x->cor[1]>=-d){//y还可以缩小
            if(r->left!=NULL)search(x,r->left,d);
        }
    }
    return;
}
int comX(node a,node b){
    if(a.cor[0]==b.cor[0]){
        if(a.cor[1]==b.cor[1])return a.cor[2]<b.cor[2];
        else return a.cor[1]<b.cor[1];
    }
    else return a.cor[0]<b.cor[0];
}
int comY(node a,node b){
    if(a.cor[1]==b.cor[1])return a.cor[2]<b.cor[2];
    else return a.cor[1]<b.cor[1];
}
int comZ(node a,node b){
    return a.cor[2]<b.cor[2];
}
double tmp1,tmp2,tmp3; double d,d1,d2;
void check2(node *nsY,node *copyY,int l,int r){
    if(r-l<3){
        if(l==r){
            ans1=nsX[l];
            return;
        }
        else if(l==r-1){
            ans1=nsX[l];ans2=nsX[r];
            d=cal(nsX[l],nsX[r],2);
            return;
        }
        else{
            tmp1=cal(nsX[l],nsX[l+1],2);tmp2=cal(nsX[l+1],nsX[l+2],2);tmp3=cal(nsX[l],nsX[l+2],2);
            if(tmp1<=tmp2&&tmp1<=tmp3){
                ans1=nsX[l];ans2=nsX[l+1];
                d=tmp1;
            }
            else if(tmp2<=tmp1&&tmp2<=tmp3){
                ans1=nsX[l+1];ans2=nsX[l+2];
                d=tmp2;
            }
            else{
                ans1=nsX[l];ans2=nsX[l+2];
                d=tmp3;
            }
            return;
        }
    }
    int mid=(l+r)>>1;
    int ll=l,rr=mid+1,k=l;
    for(int i=l;i<=r;i++){
        if((nsY+i)->id<=mid)*(copyY+ll++)=*(nsY+i);
        else *(copyY+rr++)=*(nsY+i);
    }
    check2(copyY,nsY,l,mid);
    a=ans1;b=ans2;d1=d;
    check2(copyY,nsY,mid+1,r);
    m=ans1;n=ans2;d2=d;
    if(d1>d2){
        d=d2;
        ans1=m;ans2=n;
    }
    else {
        d=d1;
        ans1=a;ans2=b;
    }

    ll=l;rr=mid+1;
    while(ll<=mid||rr<=r){  // 重新构造nsY
        if(rr>r||(rr<=r&&ll<=mid&&(copyY+ll)->cor[1]<(copyY+rr)->cor[1]))
            *(nsY+k++)=*(copyY+ll++);
        else *(nsY+k++)=*(copyY+rr++);
    }

    k=l;
    for(int i=l;i<=r;i++){
        if((nsX[mid].cor[0]-(nsY+i)->cor[0])<=d&&(nsX[mid].cor[0]-(nsY+i)->cor[0])>=-d)
            *(copyY+k++)=*(nsY+i);
    }

    int count=0; double dNew=0;
    for(int i=l;i<k;i++){
        count=i+1;
        while(count<k&&(copyY+count++)->cor[1]-(copyY+i)->cor[1]<=d){
            dNew=cal(*(copyY+count),*(copyY+i),2);
            if(d>dNew){
                ans1=*(copyY+count);ans2=*(copyY+i);
                d=dNew;
            }
        }
    }
}

void check3(node *nsZ,node *copyZ,int l,int r){
    if(r-l<3){
        if(l==r){
            ans1=nsX[l];
            return;
        }
        else if(l==r-1){
            ans1=nsX[l];ans2=nsX[r];
            d=cal(nsX[l],nsX[r],3);
            return;
        }
        else{
            tmp1=cal(nsX[l],nsX[l+1],3);tmp2=cal(nsX[l+1],nsX[l+2],3);tmp3=cal(nsX[l],nsX[l+2],3);
            if(tmp1<=tmp2&&tmp1<=tmp3){
                ans1=nsX[l];ans2=nsX[l+1];
                d=tmp1;
            }
            else if(tmp2<=tmp1&&tmp2<=tmp3){
                ans1=nsX[l+1];ans2=nsX[l+2];
                d=tmp2;
            }
            else{
                ans1=nsX[l];ans2=nsX[l+2];
                d=tmp3;
            }
            return;
        }
    }
    int mid=(l+r)>>1;
    int ll=l,rr=mid+1,k=l;
    for(int i=l;i<=r;i++){
        if((nsZ+i)->id<=mid)*(copyZ+ll++)=*(nsZ+i);
        else *(copyZ+rr++)=*(nsZ+i);
    }
    check3(copyZ,nsZ,l,mid);
    a=ans1;b=ans2;d1=d;
    check3(copyZ,nsZ,mid+1,r);
    m=ans1;n=ans2;d2=d;
    if(d1>d2){
        d=d2;
        ans1=m;ans2=n;
    }
    else {
        d=d1;
        ans1=a;ans2=b;
    }

    ll=l;rr=mid+1;
    while(ll<=mid||rr<=r){  // 重新构造nsZ
        if(rr>r||(rr<=r&&ll<=mid&&(copyZ+ll)->cor[2]<(copyZ+rr)->cor[2]))
            *(nsZ+k++)=*(copyZ+ll++);
        else *(nsZ+k++)=*(copyZ+rr++);
    }

    k=l;root=NULL;
    for(int i=l;i<=r;i++){
        if((nsX[mid].cor[0]-(nsZ+i)->cor[0])<=d&&(nsX[mid].cor[0]-(nsZ+i)->cor[0])>=0)
            *(copyZ+k++)=*(nsZ+i);
        else if((nsX[mid].cor[0]-(nsZ+i)->cor[0])<0&&(nsX[mid].cor[0]-(nsZ+i)->cor[0])>=-d)
            insert(&nsX[i]);  //进树
    }

    for(int i=l;i<k;i++){
        dSearch=INF;
        if(root!=NULL)search(&nsX[i],root,d);
        if(dSearch<d){
            d=dSearch;
            ans1=*p;ans2=nsX[i];
        }
    }
}
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        for(int j=0;j<d;j++){
            scanf("%lld",&nsX[i].cor[j]);
        }
    }
    std::sort(nsX+1,nsX+n+1,comX);
    if(d==1){
        for(int i=1;i<n;i++){
            if((nsX[i+1].cor[0]-nsX[i].cor[0])<min){
                min=nsX[i+1].cor[0]-nsX[i].cor[0];
                ans1=nsX[i];ans2=nsX[i+1];
            }
        }
        printf("%lld\n%lld",ans1.cor[0],ans2.cor[0]);
    }
    else if(d==2){
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++)ns[i].cor[j]=nsX[i].cor[j];
            ns[i].id=nsX[i].id=i;
        }
        std::sort(ns+1,ns+n+1,comY);
        check2(ns, copy,1,n);
        if(comX(ans1,ans2))printf("%lld %lld\n%lld %lld",ans1.cor[0],ans1.cor[1],ans2.cor[0],ans2.cor[1]);
        else printf("%lld %lld\n%lld %lld",ans2.cor[0],ans2.cor[1],ans1.cor[0],ans1.cor[1]);

    }
    else{//d==3
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++)ns[i].cor[j]=nsX[i].cor[j];
            ns[i].id=nsX[i].id=i;
        }
        std::sort(ns+1,ns+n+1,comZ);
        check3(ns,copy,1,n);
        if(comX(ans1,ans2))printf("%lld %lld %lld\n%lld %lld %lld",ans1.cor[0],ans1.cor[1],ans1.cor[2],ans2.cor[0],ans2.cor[1],ans2.cor[2]);
        else printf("%lld %lld %lld\n%lld %lld %lld",ans2.cor[0],ans2.cor[1],ans2.cor[2],ans1.cor[0],ans1.cor[1],ans1.cor[2]);
    }
    return 0;
}