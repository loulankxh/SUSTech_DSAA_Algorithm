//#include <iostream>
//#include <queue>
//#include <cstring>
////各种signal segment???
//
///*
//string s1
//
//typeid(variable).name()
//s1:NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
//s1[0]:c
//
//%s 字符串，后面给的是首地址，不能直接用填string类型
//printf("%c",s1);用法错误
//printf("%s",s1.c_str());用法正确
//printf("%s",s1[0]);用法错误
//
//%c 单个字符
//对于字符串s1, printf("%c",s1[0]);用法正确
//
// cout
// std::cout<<s1[0]<< std:: endl;正确（s1是字符串）
// std::cout<<s1<< std:: endl;正确（s1是字符串）
// cin
// 用于读取字符串string
// */
//
////  代码一，用node实现
////struct node{
////    int id,count;
//////    node left,right;   ？？？
////    node* left,*right;
////    node(){
////        id=count=0;
////        left=right=NULL;
////    }
////};
////struct com{
////    bool operator()(node a,node b){
////        return b.count<a.count; //小顶堆
////    }
////};
////std::priority_queue<node ,std::vector<node>,com> min;
////node ns[26], root;
////int depth[26],ans=0;
////std::string s[12];
////void search(node* root, int d){
////    if(root->right==NULL){
////        depth[root->id] = d;
////        return;
////    }
////    search(root->left,d+1);
////    search(root->right,d+1);
////}
////int main(){
////    for(int i=0;i<26;i++) ns[i]->id=i;
////    int n,num;
////    scanf("%d",&n);
////    for(int i=0;i<n;i++){
////        std::cin>>s[i];
////        int limit = s[i].length();
////        for(int j=0;j<limit;j++){
////            num = s[i][j]-'a';
////            ns[num].count++;  // ？？？ 直接用s[i][j]-'a'当下标会报错？？？
////        }
////    }
////    for(int i=0;i<26;i++) if(ns[i].count>0) min.push(ns[i]);
////    node a,b;// node c不能写在外面，否则这个c的值一直在改变<=前后关联 ？？？
////    int size = min.size();
////    while(size > 1){     // ？？？ 直接写min.size()会无法运行？
////        // min.size(), min.top(), s[i][j]等写道debug里会导致debug断开？？？
////        node c;
////
//////        me=min.top();a=&me;min.pop();   // *a = min.top()   or   a=&min.top()都不行
//////        me=min.top();b=&me;min.top();min.pop();
//////  node me;  me = min.top()   me的地址不变，只是把top的这个元素给到了me
////
////
//////        c.count=a.count+b.count;
//////        c.left=&a;c.right=&b;    ？？？直接这样，每个循环里的c.left和.right指向的地址分别都一样 --- 同上方错误一样
//////        c.id=-1;
////
//////合适写法？？？
////
////        min.push(c);
////        size = min.size();
////    }
////    if(size ==1)root=min.top();
////    if(root.left==NULL) depth[root.id]=1; //depth==0但是要占用一个长度的编码
////    else{ // depth = 编码长度
////        search(&root,0);
////    }
////    for(int i=0;i<n;i++){
////        ans=0;
////        for(int j=0;j<s[i].length();j++){
////            num = s[i][j]-'a';
////            ans+=depth[num];
////        }
////        printf("%d\n",ans);
////    }
////    return 0;
////}
//
//
//
//
////  代码二，用node*实现
//struct node{
//    int id,count;
////    node left,right;   ？？？
//    node* left,*right;
//    node(){
//        id=count=0;
//        left=right=NULL;
//    }
//};
//struct com{
//    bool operator()(node* a,node* b){
//        return b->count<a->count; //小顶堆
//    }
//};
//std::priority_queue<node* ,std::vector<node* >,com> min;
//node* ns[26], *root;
//int depth[26],ans=0;
//std::string s[12];
//void search(node* root, int d){
//    if(root->right==NULL){
//        depth[root->id] = d;
//        return;
//    }
//    search(root->left,d+1);
//    search(root->right,d+1);
//}
//int main(){
//    for(int i=0;i<26;i++) ns[i]->id=i;
//    int n,num;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        std::cin>>s[i];
//        int limit = s[i].length();
//        for(int j=0;j<limit;j++){
//            num = s[i][j]-'a';
//            ns[num]->count++;  // ？？？ 直接用s[i][j]-'a'当下标会报错？？？
//        }
//    }
//    for(int i=0;i<26;i++) if(ns[i]->count>0) min.push(ns[i]);
//    node *a,*b;// node c*不能写在外面，否则这个c的值一直在改变<=前后关联 ？？？
//    int size = min.size();
//    while(size > 1){     // ？？？ 直接写min.size()会无法运行？
//        // min.size(), min.top(), s[i][j]等写道debug里会导致debug断开？？？
//        node *c = new node();    //  指针  ？？？
//        a=min.top();min.pop();
//        b=min.top();min.pop();
//        c->count = a->count+b->count;
//        c->left=a;c->right=b;
//        c->id=-1;
//        min.push(c);
//        size = min.size();
//    }
//    if(size ==1)root=min.top();
//    if(root->left==NULL) depth[root->id]=1; //depth==0但是要占用一个长度的编码
//    else{ // depth = 编码长度
//        search(root,0);
//    }
//    for(int i=0;i<n;i++){
//        ans=0;
//        for(int j=0;j<s[i].length();j++){
//            num = s[i][j]-'a';
//            ans+=depth[num];
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}