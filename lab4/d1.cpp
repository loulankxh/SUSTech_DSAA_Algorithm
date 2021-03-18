//#include <cstdio>
//using namespace std;
//int arr[300009];
//int top=-1;
//int cur=1;
//int num[300009];
//void en(int x){
//    top++;
//    arr[top]=x;
//}
//void de(){
//    num[arr[top]]=0;
//    printf("%d ",arr[top]);
//    top--;
//}
//bool check(){
//    if(top!=-1&&arr[top]<=cur){
//        de();
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
//        for(int i=1;i<=n;i++){
//            scanf("%d",&number);
//            num[number]=1;
//            en(number);
//            while(check()||num[cur]){
//                if(top!=-1&&arr[top]<cur);
//                else cur++;
//            }
//        }
//        for(int i=0;i<=top;i++){
//            de();
//        }
//        printf("\n");
//    }
//    return 0;
//}