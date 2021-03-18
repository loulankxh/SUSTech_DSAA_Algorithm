//#include <iostream>
//
//using namespace std;
//
//long long previousState[205][2], currentState[205][2];
//long long sleep[100005];
//long long mod = 998244353;
//
//void initial1(){
//    for(int i=1;i<=200;i++){
//        currentState[i][1] = 0;
//        currentState[i][0] = 0;
//    }
//}
//
//void initial(){
//    if(sleep[2] == -1) {
//        if (sleep[1] == -1) {
//            for (int i = 1; i <= 200; i++) {
//                currentState[i][1] = 1;
//                currentState[i][0] = i - 1;
//            }
//        } else {
//            for (int i = 1; i <= sleep[1] - 1; i++) {
//                currentState[i][1] = 0;
//                currentState[i][0] = 0;
//            }
//            currentState[sleep[1]][1] = 1;
//            currentState[sleep[1]][0] = 0;
//            for (int i = sleep[1] + 1; i <= 200; i++) {
//                currentState[i][1] = 0;
//                currentState[i][0] = 1;
//            }
//        }
//    } else {
//        initial1();
//        if(sleep[1] == -1){
//            currentState[sleep[2]][1] = 1;
//            currentState[sleep[2]][0] = sleep[2]-1;
//        } else {
//            if(sleep[1] == sleep[2]){
//                currentState[sleep[2]][1] = 1;
//                currentState[sleep[2]][0] = 0;
//            } else {
//                currentState[sleep[2]][1] = 0;
//                currentState[sleep[2]][0] = 1;
//            }
//        }
//    }
//}
//
//void cuToPr(){
//    for(int i=1;i<=200;i++){
//        previousState[i][1] = currentState[i][1];
//        previousState[i][0] = currentState[i][0];
//    }
//}
//
//int main(){
//    int n = 0;
//    scanf("%d",&n);
//    for(int i=1; i<=n; i++){
//        scanf("%lld",&sleep[i]);
//    }
//    initial();
//    cuToPr();
//    for(int i=3; i<=n; i++){
//        if(sleep[i] == -1){
//            long long sum = 0;
//            currentState[1][0] = 0;
//            for(int j=2;j<=200;j++){
//                sum+=previousState[j-1][0]+previousState[j-1][1];
//                currentState[j][0] = sum%mod;
//            }
//            sum = 0;
//            for(int j=200;j>=1;j--){
//                sum+=previousState[j][1];
//                currentState[j][1] = (sum+previousState[j][0])%mod;
//            }
//        } else {
//            initial1();
//            long long sum = 0;
//            for(int j=1; j<= sleep[i]-1;j++){
//                sum+=previousState[j][0]+previousState[j][1];
//            }
//            currentState[sleep[i]][0] = sum%mod;
//            sum = 0;
//            for(int j=200;j>=sleep[i];j--){
//                sum+=previousState[j][1];
//            }
//            currentState[sleep[i]][1] = (sum+previousState[sleep[i]][0])%mod;
//        }
//        cuToPr();
//    }
//    if(sleep[n] == -1){
//        long long sum = 0;
//        for(int i=1;i<=200;i++){
//            sum+=currentState[i][1];
//        }
//        cout<<sum%mod<<endl;
//    } else {
//        cout<<currentState[sleep[n]][1]<<endl;
//    }
//    return 0;
//}