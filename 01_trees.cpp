/* in this code we are gona creat a simple tree with class node with simple operation*/

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
  int data;
  Node* left;
  Node* right;
   Node(int val) {
    data=val;
    left=NULL;
    right=NULL;
   }
   
};

void display(Node* root) {
    if(!root){
       return ;
      
    }
    else{ cout<<" "<<root->data;              // inorder recursive display of value;
          if(root->left!=NULL) display(root->left);
          if(root->right!=NULL) display(root->right);
    }
}

vector<vector<int>>  level_display(Node* root) {
    vector<vector<int>> ans;
    if( root==NULL) ans ;
    queue<Node*> que;
    que.push(root);
    while(!que.empty()) {
        vector<int> level;
        int len=que.size();
        for(int i=0; i<len; i++) {
            Node* temp=que.front();
            que.pop();
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
            level.push_back(temp->data);

        }
        ans.push_back(level);
        //cout<<"level"<<endl;
    }
    return ans;

}
int main() {
    Node* root , *N1, *N2,*N3,*N4,*N5,*N6;
    root=new Node(5);
    N1=new Node(4);
    N2=new Node(6);
    N3=new Node(3);
    N4=new Node(2);
    N5=new Node(7);
    N6=new Node(8);
    root->left=N1;
    root->right=N2;
    N1->left=N3;
    N1->right=N4;
    N2->left=N5;
    N2->right=N6;
    display(root);
    //level_display(root,0);
    cout<<endl;
    display(root);
    cout<<endl;
    vector<vector<int>> ans=level_display(root);
    for(int i=0;i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}