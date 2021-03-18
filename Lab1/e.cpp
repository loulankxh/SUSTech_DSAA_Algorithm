//#include <cstdio>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//#include <cstring>
//using namespace std;
////long long place[2][static_cast<int>(1e9 + 10)];???
//long long place[2][100010];
//long long search(long long right,long long left,int n,int turn1,int turn2){
//    long long last=0;
//    if(left==right)return left;
//    long long mid=(left+right)>>1;//即次数
//    bool flag=false;
//    int a=mid%n,b=mid/n;//判断某个点是否能追上，只能这样
//    if(mid<abs(place[0][a]+b*turn1)+abs(place[1][a]+b*turn2)) last=search(right,mid+1,n,turn1,turn2);
//    else last=search(mid,left,n,turn1,turn2);//<=都可以————可以停住不走
//    return last;
//}
//void test(){//二分法找
//    //确定一个上限
//    int x1,y1,x2,y2;
//    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//    int x=x2-x1,y=y2-y1;//不要试图分方向，然后一步一步讨论S带来的影响，这样
//    place[0][0]=x;
//    place[1][0]=y;
//    int n;
//    long long time=0;
//    scanf("%d",&n);
//    string du;
//    cin>>du;
////    cout<<du<<"\n";
////    scanf("%s",&du);为什么这样读进来输出去总会出锅？——不能这样读
////    printf("%s",du);
//    char s;
//    for(int i=1;i<=n;i++){//每一次都重新求曼哈顿距离,重新取绝对值
//        // 懒得去讨论原来的x,y距离与变换的方向（看-or+），讨论对绝对值-or+
//        s=du[i-1];
//        if(s=='U')y++;
//        else if(s=='D')y--;
//        else if(s=='L')x--;
//        else if(s=='R')x++;
//        place[0][i]=x;
//        place[1][i]=y;
//    }
//    int turn1=place[0][n]-place[0][0],turn2=place[1][n]-place[1][0];
//    //因为每一个循环内位置的变化不是单调的，（在前一点不能追上的时候）要判断这一点能否追上只能和自己比较，若想确切的知道什么时候能追上（从前往后）只能遍历
//    //能否追上这一个状态是单调的，故可以二分
//    if(abs(place[0][n])+abs(place[1][n])-time==abs(place[0][0])+abs(place[1][0]))printf("%d",-1);
//    else{//距离每次最少-1，故最多2e9个循环，总共计算n*2e9步——找上界
//        printf("%lld",search(n*2e9,1,n,turn1,turn2));
//    }
//}
//int main(){
//    test();
//    return 0;
//}