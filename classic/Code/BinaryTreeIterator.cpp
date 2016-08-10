#include<iostream>
#include<stack>
using namespace std;

class node{
public:
    int val;
    node * left;
    node * right;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

class Iterator{
private:
    //store left branch
    stack<node*>s;
    //current node;
    node * it;
    //if current node is from left branch of parent
    bool left;
public:
    int next(){
        left=false;
        //push all nodes in left branch in stack
        while(it){
            s.push(it);
            if(it->left){
                //if left branch grows
                left=true;
            }
            it=it->left;
        }
        if(s.size()>0){
            //return the new lowest left most node 
            node* retVal = s.top();
            s.pop();
            if(s.size()>0){
                node * parent = s.top();
                //if the popped node is right leaf, don't repush
                if (left&&parent->right){
                    it=parent->right;
                    left=false;
                } else {
                    it = NULL;
                }
            }
            return retVal->val;
        }else{
            return -1;
        }
    }
    Iterator(node * root){
        it=root;
    }
};

int main(){
    node * root = new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->right=new node(5);
    //post order:24531
    Iterator it = Iterator(root);
    //pop in post order 
    //exceeding number of nodes: return -1 
    for(int i=0;i<6;i++){
        cout << it.next()<<endl;
    }
    return 0;
}

