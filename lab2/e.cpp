//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//long long sum=0;
//long long ans=0;
////pair<long long,long long> s[200009];
////pair类型的指针？sort方法？
//struct node{
//    int x,y,z;
//};
//node me[200009];//把这玩意写里面为什么会爆炸啊。。。？？？
//node v[200009];
//void merge_sort(node* arr,int l,int r){//n个小时的bug,这里血暴了
//    if(l==r) return ;
//    int mid=l+((r-l)>>1);
//    merge_sort(arr,l,mid);
//    merge_sort(arr,mid+1,r);
////    node me[r-l+1];//把这玩意写里面为什么会爆炸啊。。。？？？
//    int i=l,j=mid+1;
//    for(int k=0;k<=r-l;k++){
//        if(i<=mid&&(j>r||arr[j].z>arr[i].z)){
//            me[k]=arr[i];
//            i++;
//        }
//        else{
//            me[k]=arr[j];
//            j++;
//        }
//    }
//    for(int i=0;i<=r-l;i++){
//        arr[l+i]=me[i];
//    }
//    return;
//}
//void test(){
//    int n,p,q;
//    scanf("%d%d%d",&n,&p,&q);
//    for(int i=1;i<=n;i++){
//        scanf("%d%d",&v[i].x,&v[i].y);
//        v[i].z=v[i].x-v[i].y;
//        sum+=v[i].y;
//    }
//    if(q==0)printf("%lld",sum);
//    else{
//        int beishu=1;
//        for(int i=1;i<=p;i++){
//            beishu*=2;
//        }
//        merge_sort(v,1,n);
//        int count=0;
//        for(int i=1;i<=n&&i<=q;i++){
//            if(v[n+1-i].z>0){
//                sum+=v[n+1-i].z;
//                count++;
//            }
//            else break;
//        }
//        int count1=q-count;//剩余机会
//        long long last=0;//上次最大
//        for(int i=n;i>=1;i--){
//            if(count>0){//z为正数
//                ans=sum+(long long)(beishu-1)*v[i].x;
//                ans=last>=ans?last:ans;
////                ans=__max(last,ans);//没有declared in this scope？？？
//                last=ans;
//                count--;
//            }
////        if(count--);//不行，当count为负数的时候又会出错
//            else {
//                long long me=(long long)beishu*v[i].x-v[i].y;
//                if(me>0){
//                    ans=sum+me;
//                    if(count1>0);//还有赋值机会没用
//                    else{//没有剩余机会了count1==0,此时q>0则一定有人被赋值过
//                        ans-=v[n+1-(q-count1)].z;//之前count--了欸，所以不能直接用count
////                        sum-=v[n+1-count].z;//注意不能每一次循环减一个！
//                    }
//                    ans=last>=ans?last:ans;
//                    last=ans;
//                }
//            }
//        }
//        printf("%lld",ans);
//    }
//}
//int main(){
//    test();
//    return 0;
//}
