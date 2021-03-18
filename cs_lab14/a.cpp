//#include <iostream>
//struct edge{
//    int u, v, next, val;
//    edge(){u = v = next = 0; val = 1;}
//};
//edge es[1005005];int cnt = 0; // 2*i & 2*i + 1 是一组  通过“ ^1 ”得到
//int head[1005], visit[1005], n, m, flag = 1, ans = 0;
//
//void add(int u, int v){
//    es[cnt].u = u; es[cnt].v = v; es[cnt].next = head[u]; head[u] = cnt++; // cnt == 0 这条边是无效的——本题中
//    es[cnt].u = v; es[cnt].v = u; es[cnt].next = head[v]; head[v] = cnt++;
//}
//int edgeVal = 1;  // 在本题情况下是一个定值, 否则在DFS中计算出来
//void DFS(int u){
//    if(u == n + 1) {// 到达t
//        flag = 1;
//        return;
//    }
//    for(int i = head[u]; i != 0; i = es[i].next){
//        if(es[i].val && !visit[es[i].v]){ //es[i].val > 0 :当前残留网络有这条边
//            // visit[es[i].v] == 0： 不成环 => 不重复经过同一条边,防错； 提高效率
//            visit[es[i].v] = 1;
//            DFS(es[i].v);
//            if(flag){
//                es[i].val -= edgeVal;
//                es[i^1].val += edgeVal;
//                return;
//            }
//        }
//    }
//    return;
//}
//void ford_fulkson(){
//    visit[0] = 1;
//    while(flag){
//        flag = 0;
//        DFS(0);
//        if(flag){
//            ans += edgeVal;  //最小割最大流
//            for(int i = 1; i < 1005; i++) visit[i] = 0;  // visit == 1的点不一定都在stack中
//        }
//    }
//}
//int main(){
//    int color, u, v; scanf("%d%d",&n, &m);
//    for(int i = 1; i <= n; i++){
//        scanf("%d",&color);
//        if(color) add(i, 0);  // white: s->i
//        else add(n+1, i);  // black: i->t
//    }
//    for(int i = 1; i <= m ; i++){
//        scanf("%d%d",&u, &v);
//        add(u, v);
//    }
//    ford_fulkson();
//    printf("%d", ans);
//    return  0;
//}
//
//
//
////#include <iostream>   // 有问题 wrong
////
////int visit[1005], stack[1005], top = 0, n, m, flag = 1, ans = 0, edge[1005][1005];
////
////void DFS(int u){
////    if(u == n + 1) {// 到达t
////        flag = 1;
////        return;
////    }
////    for(int i = n + 1; i != u && i > 0; i --){  // i > 0: 不考虑i -> s
////        if(edge[u][i] > 0 && visit[i] == 0){  //edge[i].val > 0 :当前残留网络有这条边
////            // visit[es[i].v] == 0： 不成环 => 不重复经过同一条边,防错； 提高效率
////            stack[++top] = i;
////            visit[i] = 1;
////            DFS(i);
////            if(flag) return;
////            top--;  // 此点找不到 s->t
////        }
////    }
////    return;
////}
////int edgeVal = 1;  // 在本题情况下是一个定值
////void ford_fulkson(){
////    visit[0] = 1;
////    while(flag){
////        flag = top = 0;
////        DFS(0);
////        if(flag){
////            ans += edgeVal;
////            for(int i = 1; i < 1005; i++) visit[i] = 0;  // visit == 1的点不一定都在stack中
////            while(top){
////                edge[stack[top-1]][stack[top]] -= edgeVal;   // stack[0] = 0 : s
////                edge[stack[top]][stack[--top]] += edgeVal;  // val = edgeVal
////            }
////        }
////    }
////
////}
////int main(){
////    int color, u, v; scanf("%d%d",&n, &m);
////    for(int i = 1; i <= n; i++){
////        scanf("%d",&color);
////        if(color) edge[0][i] = 1;  // white: s->i
////        else edge[i][n+1] = 1;  // black: i->t
////    }
////    for(int i = 1; i <= m ; i++){
////        scanf("%d%d",&u, &v);
////        edge[u][v] = 1; edge[v][u] =1;
////    }
////    ford_fulkson();
////    printf("%d", ans);
////    return  0;
////}