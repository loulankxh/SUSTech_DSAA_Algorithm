#include <iostream>
struct edge{
    int u,v,w,next;
    edge(){u=v=w=next=0;}
};
edge es[50005];long long binary[100005];long long loca[100005];long long head[50005];long long kth[50005];
long long size=0;long long kSize=0;
void fastRead(long long& in){
    in=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        in*=10;
        in+=ch-'0';
        ch=getchar();
    }
}
void init(long long n){
    size=kSize=0;
    for(int i=0;i<=n;i++)head[i]=0;
}
void insert(long long val,long long v){
    if(size<100004){
        binary[++size]=val;loca[size]=v;
    }
    else if(binary[100004]>val){//不是50004！！！最后一个不一定是堆里面最大的
        binary[100004]=val;loca[100004]=v;
    }
    long long t=size;
    while(t/2>0&&binary[t/2]>binary[t]){
        binary[t/2]^=binary[t];binary[t]^=binary[t/2];binary[t/2]^=binary[t];
        loca[t/2]^=loca[t];loca[t]^=loca[t/2];loca[t/2]^=loca[t];
        t=t/2;
    }
}
long long deleteMin(){
    long long t=1,location=loca[1];
    kth[++kSize]=binary[1];
    loca[1]=loca[size];binary[1]=binary[size--];
    while(((long long)2*t<=size&&binary[2*t]<binary[t])||((long long)2*t<size&&binary[2*t+1]<binary[t])){
        if((long long)2*t<size&&binary[2*t+1]<binary[2*t]){
            binary[2*t+1]^=binary[t];binary[t]^=binary[2*t+1];binary[2*t+1]^=binary[t];
            loca[2*t+1]^=loca[t];loca[t]^=loca[2*t+1];loca[2*t+1]^=loca[t];
            t=2*t+1;
        }
        else{
            binary[2*t]^=binary[t];binary[t]^=binary[2*t];binary[2*t]^=binary[t];
            loca[2*t]^=loca[t];loca[t]^=loca[2*t];loca[2*t]^=loca[t];
            t=2*t;
        }
    }
    return location;
}
int main(){
    long long t,n,m,q,u,v,k,w;fastRead(t);
    while(t--){
        fastRead(n);fastRead(m);fastRead(q);
        init(n);
        for(long long i=1;i<=m;i++){
            fastRead(u);fastRead(v);fastRead(w);
            es[i].u=u;es[i].v=v;es[i].w=w;es[i].next=head[u];head[u]=i;
            insert(w,v);
        }
        long long diff=0,u=0;long long tmp;
        for(long long i=0;i<q;i++){
            fastRead(k);
            diff=k-kSize;
            while(diff-->0){
                u=deleteMin();
                for(int i=head[u];i!=0;i=es[i].next){
                    tmp=es[i].w+kth[kSize];insert(tmp,es[i].v);
                }
            }
            printf("%lld\n",kth[k]);
        }
    }
    return 0;
}