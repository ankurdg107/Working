#include<bits/stdc++.h>
using namespace std;
  

class Node{
    public:
    int data;
    Node* lchild;
    Node* rchild;
};

void Insert(Node* t,int key){
    Node* r=NULL,*p;

    while(t!=NULL){
        r=t;
        if(key==t->data)
            return;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    p=new Node();
    p->data=key;
    if(p->data<r->data)
        r->lchild=p;
    else r->rchild=p;
}