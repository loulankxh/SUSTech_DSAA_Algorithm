#include <iostream>
long long power2[63];
void setPower2(){
    power2[0]=1;
    for(int i=1;i<63;i++) power2[i]=2*power2[i-1];
}
long long count,ans;
void calculate(long long pos,int mode){
    if(pos==0) return;
    long long n=0, pos0=pos+1;
    while(pos0>0){
        pos0/=2;
        n++;    //n bits number
    }
    n--;  // prefix VC(n):2^n -1
    count+=power2[n-1];
    if(pos == power2[n]-1) return;
    else if(pos == power2[n]){
        if(mode==1) count++;
    }
    else {
        if(mode==1) count++;
        pos-=power2[n];
        if(pos<=power2[n-1]-1)
            calculate(pos,1);
        else calculate(pos,0);
    }
}
int main(){
    setPower2();
    int t;long long l,r,lans,rans;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        count=0;
        calculate(l-1,1);lans=count;
        count=0;
        calculate(r,1);rans=count;
        ans=rans-lans;
        printf("%lld\n",ans);
    }
    return 0;
}