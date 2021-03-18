//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//int arr[300009];
//int top=-1;
//int cur=1;
//int num[300009];//初始为假？
//void en(int x){
//    top++;
//    arr[top]=x;
//}
//void de(){
//    num[arr[top]]=0;//不能用cur,到后期cur=n+1,同理
//    printf("%d ",arr[top]);//不能用cur,到后期cur=n+1
//    top--;
//}
//bool check(){
//    if(top!=-1&&arr[top]==cur){//不能改成<=  !!!
//    ——这样cur++不断进行，有可能cur=13,但10还在外面，却因为arr[top]=12<13check成立
//eg. 4 5 6 7 8 12 5 2 3 9 1 14 15 10 13
//        de();
////        cur++;//这是返回不去的
//        return true;
//    }
//    else return false;
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int n;
//        cur=1;
//        scanf("%d",&n);
//        int number;
////        printf("%d",num[1]);只能以0 1形式输出真假？ 用cout怎么搞
//        for(int i=1;i<=n;i++){
//            scanf("%d",&number);
//            num[number]=1;
//            en(number);
//            while(check()||num[cur]){
//                //||num[cur]cur++几次后可能check(cur)又成立了
//if(top!=-1&&arr[top]<cur);
//else cur++;
//不行！！ 已经进去过但被弹出来的会出错，因为cur可以往回走
//            }
//        }
//        for(int i=0;i<=top;i++){
//            de();
//        }
//        printf("\n");
//    }
//    return 0;
//}