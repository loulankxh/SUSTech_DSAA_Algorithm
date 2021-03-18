//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//long long sum=0;
//long long ans=0;
//struct node{
//    int x,y,z;
//};
//node me[200009];
//node v[200009];
//void merge_sort(node* arr,int l,int r){
//    if(l==r) return ;
//    int mid=l+((r-l)>>1);
//    merge_sort(arr,l,mid);
//    merge_sort(arr,mid+1,r);
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
//        int count1=q-count;
//        long long last=0;
//        ans=sum;//保底——1 0 200000 1 2否则会挂掉
//        for(int i=n;i>=1;i--){
//            if(count>0){
//                ans=sum+(long long)(beishu-1)*v[i].x;
//                ans=last>=ans?last:ans;
//                last=ans;
//                count--;
//            }
//            else {
//                long long me=(long long)beishu*v[i].x-v[i].y;
//                if(me>0){
//                    ans=sum+me;
//                    if(count1>0);
//                    else{
//                        ans-=v[n+1-(q-count1)].z;
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
