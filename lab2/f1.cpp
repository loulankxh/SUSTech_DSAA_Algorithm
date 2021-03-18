//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//struct node{
//    int x,y,z;
//};
//node bead[100009];
//node _b[100009];
//node _a[100009];
//node me[100009];
//int ans,add;
//void merge_sort(node* arr,int l,int r,int canshu){//canshu:1--b<a;-1-->b>a
//    if(l==r) return;
//    int mid=l+((r-l)>>1);
//    merge_sort(arr,l,mid,canshu);
//    merge_sort(arr,mid+1,r,canshu);
//    int i=l,j=mid+1;
//    for(int k=0;k<=r-l;k++){
//        bool med=canshu>0?arr[j].x>arr[i].x:arr[j].y<arr[i].y;
//        if(i<=mid&&(j>r||med)){
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
//    long long t;
//    scanf("%lld",&t);
//    while(t--){
//        int n;
//        ans=0;
//        scanf("%d",&n);
//        for(int i=0;i<n;i++){
//            scanf("%d%d",&bead[i].x,&bead[i].y);
//            bead[i].z=bead[i].x-bead[i].y;//b-a
//        }
//        int size1=0,size3=0,re=0;
//        for(int i=0;i<n;i++){
//            if(bead[i].z>0)_a[size3++]=bead[i];
//            else if(bead[i].z<0)_b[size1++]=bead[i];
//            else{
//                ans+=bead[i].x;
//                re=re>bead[i].x?re:bead[i].x;
//            }
//        }
//        ans-=re;
//        int b1=0,a1=0;
//        if(size1>0) {
//            merge_sort(_b, 0, size1 - 1, 1);
//            b1 = _b[0].x, a1 = _b[0].y;
//        }
//        for(int i=1;i<size1;i++){
//            add=a1>_b[i].x?_b[i].x:a1;
//            ans+=add;
////            b1+=_b[i].x-add;
//            a1+=_b[i].y-add;
//        }
//        int b3=0,a3=0;
//       if(size3>0) {
//           merge_sort(_a,0,size3-1,-1);
//           b3=_a[0].x,a3=_a[0].y;
//       }
//        for(int i=1;i<size3;i++){
//            add=a3>_a[i].x?_a[i].x:a3;
//            ans+=add;
//            b3+=_a[i].x-add;
//            a3+=_a[i].y-add;
//        }
//        add=a1>re?re:a1;
//        ans+=add;
//        a1+=re-add;
//        ans+=a1>b3?b3:a1;
//        printf("%d\n",ans);
//    }
//}
//int main(){
//    test();
//    return 0;
//}