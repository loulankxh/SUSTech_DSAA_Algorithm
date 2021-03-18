//#include <iostream>
//int arr1[15],arr2[15];
//long long num[6][16][16][16][16][16];//第一个：这一组总共几个元素(1~5)，之后表示每个元素的值(0~15)
//long long ans=0;
//void init(){
//    for(int i=0;i<6;i++){
//        for(int j=0;j<16;j++){
//            for(int k=0;k<16;k++){
//                for(int m=0;m<16;m++){
//                    for(int n=0;n<16;n++){
//                        for(int x=0;x<16;x++) num[i][j][k][m][n][x]=-1;
//                    }
//                }
//            }
//        }
//    }
//}
//void xunhuan(int n){
//
//}
//void xunhuan2(int a,int b,int m){//包括前面不包括后面
//    if(a<b){
//        for(int i=arr1[a]-3*m>0?arr1[a]-3*m:0;i<=arr1[a];i++){
//            arr2[a]=i;
//            xunhuan2(a+1,b,m);
//        }
//    }
//    else if(a==b){//已经生成了前面一部分的数值
//
//    }
//    return;
//}
//void cal(int a, int b){
//    int me=(a+b)/2;
//    int n=me,m=b-me,n0=1;
//
//}
//int main(){
//    init();
//    int n;
//    scanf("%d",&n);
//    int limit=3*n-3,flag=0,boundary=0,sum=0;
//    for(int i=1;i<=n;i++){
//        scanf("%d",&arr1[i]);
//        if(arr1[i]>limit)flag=1;
//        if(arr1[i]==limit)boundary++;
//        sum+=arr1[i];
//    }
//    if(boundary>1||flag==1||sum<n*(n-1)||sum>n*(n-1)*3/2)printf("%d",0);
//    else{
//
//    }
//    return 0;
//}