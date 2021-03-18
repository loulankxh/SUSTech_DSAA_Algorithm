//#include <iostream>
//#include <algorithm>
//struct node{
//    int a,b;
//    node(){a=b=0;}
//};
//node ns[500005];
//node ns1[500005];
//int com(node a,node b){
//    if(a.a!=b.a)return a.a<b.a;
//    else return a.b<b.b;   //  否则 a.a==b.a顺序不同，会出现一点问题 !!!
//}
//long long ans=0;
//void merge(int l,int r){
//    if(l==r) return;
//    int mid=l+((r-l)>>1);
//    if(l<=mid)merge(l,mid);
//    if(mid<r)merge(mid+1,r);
//    int i=l,j=mid+1,count=r-mid;   // 顺序对
//    for(int k=l;k<=r;k++){
//        if(j>r || (i<=mid&&j<=r&&ns[i].b<=ns[j].b)){   // <=
//            if(ns[i].a==ns[j].a&&ns[i].b==ns[j].b)ans++; // 两者各加一个满意度
//            ns1[k]=ns[i++];
//            ans+=(long long)count;
//        }
//        else{
//            ns1[k]=ns[j++];
//            count--;
//        }
//    }
//    for(int k=l;k<=r;k++) ns[k]=ns1[k];
//}
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        scanf("%d%d",&ns[i].a,&ns[i].b);
//        ns1[i]=ns[i];
//    }
//    std::sort(ns+1,ns+n+1,com);   // a: small -> large
//    merge(1,n);
//    printf("%lld",ans);
//    return 0;
//}