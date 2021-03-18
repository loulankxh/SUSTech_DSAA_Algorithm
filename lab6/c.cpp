//#include <iostream>
//#include <stack>
//#include <algorithm>
//using namespace std;
//stack<int> post;
//int pre[1005];
//int in[1005];
//int x1;
//void handle(int l,int r){//l包括，r不包括
//    post.push(pre[x1]);//pre: 根，左，右  先把根存起来
//    if(l==r-1){
//        x1++;//x1往后走
//        printf("%d ",post.top());//左右叶子结点
//        post.pop();
//        return;
//    }
//    int tmp=find(in+l,in+r,pre[x1++])-in;//x1往后走
//    //include algorithm!!!(lower_bound不用)
//    if(tmp>l)handle(l,tmp);
//    if(r>tmp+1)handle(tmp+1,r);
//    printf("%d ",post.top());//根节点
//    post.pop();
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int n;
//        x1=0;
//        scanf("%d",&n);
//        for(int i=0;i<n;i++){
//            scanf("%d",&pre[i]);
//        }
//        for(int i=0;i<n;i++){
//            scanf("%d",&in[i]);
//        }
//        handle(0,n);
//        printf("\n");
//    }
//    return 0;
//}