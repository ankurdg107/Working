#include<bits/stdc++.h>
using namespace std;
  
class Node{
    public:
    int data;
    Node* lchild;
    Node* rchild;
};

Node* Rsearch(Node* t,int key){
    if(t==NULL){
        return NULL;
    }

    if(key==t->data){
        return t;
    }else if(key<t->data){
        return Rsearch(t->lchild,key);
    }else{
        return Rsearch(t->rchild,key);
    }
}

Node* Search(Node* t,int key){
    while(t!=NULL){
        if(key==t->data){
            return t;
        }else if(key<t->data){
            t=t->lchild;
        }else{
            t=t->rchild;
        }
    }
    return NULL;
}