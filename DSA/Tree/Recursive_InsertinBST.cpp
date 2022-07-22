#include<bits/stdc++.h>
using namespace std;
  

class Node{
    public:
    int data;       
    Node* lchild;
    Node* rchild;
};

Node* Insert(Node* p,int key){
    Node* t;
    if(p==NULL){
        t=new Node();
        t->data=key;
        t->lchild=t->rchild=NULL;
        return;
    }

    if(key<p->data){
        p->lchild=Insert(p->lchild,key);
    }else if(key>p->data){
        p->rchild=Insert(p->rchild,key);
    }
    return p;
}