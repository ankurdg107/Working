#include<bits/stdc++.h>
using namespace std;
  

class Node{
    public:
    int data;       
    Node* lchild;
    Node* rchild;
    int height;
}*root=NULL;

int NodeHeight(struct Node *p)
{
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;
return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct Node *p)
{
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;
return hl-hr;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->data = key;
    node->lchild = NULL;
    node->rchild = NULL;
    node->height = 1; // new node is initially
                      // added at leaf
    return(node);
}

Node *LLRotate(Node *p){
    struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=p;
p->lchild=plr;

p->height=NodeHeight(p);
pl->height=NodeHeight(pl);
if(root==p)
root=pl;
return pl;
}
Node *LRRotate(Node *p){
   struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=plr->lchild;
p->lchild=plr->rchild;
plr->lchild=pl;
plr->rchild=p;
pl->height=NodeHeight(pl);
p->height=NodeHeight(p);
plr->height=NodeHeight(plr);
if(root==p)
root=plr;
return plr;
}

