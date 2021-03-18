//#include <iostream>
//long long power2[63];
//void setPower2(){
//    power2[0]=1;
//    for(int i=1;i<63;i++) power2[i]=2*power2[i-1];
//}
//long long count,ans;
//void calculate(long long pos,int mode){
//    if(pos==0) return;
//    long long n=0, pos0=pos+1; //不能作为全局变量
//    while(pos0>0){
//        pos0/=2;
//        n++;    //n bits number
//    }
//    n--; //2^n-1 bits VC(n) 满足2^n-1<=pos   一定有n>=1
//    count+=power2[n-1]; //2^n-1:   2^(n-1)个V
//    if(pos == power2[n]-1) return;
//    else if(pos == power2[n]){
//        if(mode==1) count++;//中间V
//    }
//    else { // >power2[n]
//        if(mode==1) count++;//中间V 不要漏掉！！！
//        pos-=power2[n];  // VC(n-1)+V/C   在此等价于取模%power2[n]
////        if(n==1) ; //不可能到这一步   1~2bits    >=3bits=>以VC(2)为前缀
//        if(pos<=power2[n-1]-1)  //n-1  而非 n-2  之前已经n--了
//            calculate(pos,1);  // 仍然符合VC规范: VC（n-1)+V+VC(n-1)'
//        else calculate(pos,0);  //规范：VC（n-1)+C+VC(n-1)'
//        //不要count+   反复叠加了，除非count是局部变量
//    }
//}
//int main(){
//    setPower2();
//    int t;long long l,r,lans,rans;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%lld%lld",&l,&r);
//        count=0;
//        calculate(l-1,1);lans=count;
//        count=0;
//        calculate(r,1);rans=count;
//        ans=rans-lans;
//        printf("%lld\n",ans);
//    }
//    return 0;
//}