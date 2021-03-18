//#include <iostream>
//#include <algorithm>
//struct task{
//    int start,end,val;
//    task(){start=end=val=0;}
//};
//task ts[5005],ts1[5005];
//int n=0;
//long long ans=0;
//int com(task a,task b){ //从大到小
//    return a.val>b.val;
//}
//int com2(task a,task b){ // active point
//    return a.start<b.start;
//}
//struct act{
//    int val,isUsed;
//    task t;    //task t如何初始化？
//    act(){val=isUsed=0;}
//};
//act active[5005];
//int mid=0;
//int search(int start,int l,int r){
//    while(l<r){
//        mid=l+((r-l)>>1);
//        if(active[mid].val<start) l=mid+1;
//        else r=mid;
//    }
//    return l;
//}
//int find(task t,int x){
//    if(t.start>active[x].val || active[x].val>t.end) return 0;
//    else{//t.start<=x
//        if(active[x].isUsed==0){
//            active[x].t=t;
//            active[x].isUsed=1;
//            return 1;
//        }
//        else{
//            if(active[x].t.end>t.end){
//                if(find(active[x].t,x+1)==1){
//                    active[x].t=t;
//                    return 1;
//                }
//                else return 0;
//            }
//            else return find(t,x+1);
//        }
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i= 1;i<=n;i++){
//        scanf("%d%d%d",&ts[i].start,&ts[i].end,&ts[i].val);
//        ts1[i]=ts[i];   // val or address   ？？？
//    }
//    std::sort(ts1+1,ts1+n+1,com2); // start 从小到大
//    int count=1;
//    for(int i=1;i<=n;i++){ // active point
//        if(count<ts1[i].start){
//            active[i].val=ts1[i].start;
//            count=ts1[i].start+1;
//        }
//        else{
//            active[i].val=count++;
//        }
//    }
//    std::sort(ts+1,ts+n+1,com);   // val 从大到小
//    int x=0;
//    for(int i=1;i<=n;i++){
//        x=search(ts[i].start,1,n);  // >= 的第一个    有可能最右，仍小于
//        if(find(ts[i],x)==1) ans+=ts[i].val;
//    }
//    printf("%lld",ans);
//}