//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//char arr[30009];
//int top=-1;
//void push(char a){
//    top++;
//    arr[top]=a;
//}
//void pop(){
//    top--;
//};
//bool check(char a){
//    bool flag =false;
//    if(a=='{'||a=='('||a=='['){
//        flag=true;
//        push(a);
//    }
//    else {
//        if(top!=-1&&((a=='}'&&arr[top]=='{')||(a==')'&&arr[top]=='(')||(a==']'&&arr[top]=='['))){
//            //右边多了top==-1
//            pop();
//            flag=true;
//        }
//    }
//    return flag;
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        top=-1;//不要忘了
//        int n;
//        scanf("%d",&n);
//        scanf("%s",arr);
//        bool flag=true;
//        for(int i=0;i<n;i++){
//            if(check(arr[i]));
//            else {
//                flag=false;
//                break;
//            }
//        }
//        if(top!=-1)flag= false;//左边多了，不要漏了
//        if(flag)printf("YES\n");
//        else printf("NO\n");
//    }
//    return 0;
//}