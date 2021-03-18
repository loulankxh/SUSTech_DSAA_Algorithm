//理解错题目意思了：是对每个字符串分别考虑

//#include <iostream>
//#include <queue>
//#include <cstring>
//struct node{
//    int id,count;
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
//std::priority_queue<node* ,std::vector<node*>,com> min;
//node* ns[26], *root;
//int depth[26], ans=0;
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
//    for(int i=0;i<26;i++) {
//        ns[i]=new node(); // 指针不能被自动初始化
//        ns[i]->id=i;
//    }
//    int n,num;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        std::cin>>s[i];
//        int limit = s[i].length();
//        for(int j=0;j<limit;j++){
//            num = s[i][j]-'a';
//            ns[num]->count++;
//        }
//    }
//    for(int i=0;i<26;i++) if(ns[i]->count>0) min.push(ns[i]);
//    node *a,*b;
//    int size = min.size();
//    while(size > 1){
//        node *c = new node();
//        a=min.top();min.pop();
//        b=min.top();min.pop();
//        c->count = a->count+b->count;
//        c->left=a;c->right=b;
//        c->id=-1;    //区分a
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