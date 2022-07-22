#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* lchild;
    Node* rchild;
};

class Tree{
    Node* root;
    public:
    Tree(){root=NULL;};
   void createtree();
   void Preorder(){Preorder(root);}
    void Preorder(Node *p);
};
class Queue {
private:
int front;
int rear;
int size;
Node **Q;
public:
Queue(){front=rear=-1;size=10;Q=new Node*[size];}
Queue(int size){front=rear=-1;this->size=size;;Q=new
Node*[size];}
void enqueue(Node *x);
Node *dequeue();
int isEmpty(){ return front==rear;}
};
void Queue::enqueue(Node *x)
{
if(rear==size-1)
printf("Queue Full\n");
else
{
rear++;
Q[rear]=x;
}
}
Node *Queue::dequeue()
{

Node *x=NULL;
if(front==rear)
printf("Queue is Empty\n");
else
{
x=Q[front+1];
front++;
}
return x;
}

void Tree::Preorder(struct Node *p)
{
if(p)
{
printf("%d ",p->data);
Preorder(p->lchild);
Preorder(p->rchild);
}
}
void Tree::createtree(){
    Node *p,*t;
    int x;
  Queue q(100);
    cout<<"Enter root"<<endl;
    cin>>x;

    root = new Node;
    root->lchild=root->rchild=NULL;

    
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter left child of "<<p->data<<" "<<endl;
        cin>>x;
       
        if(x!=-1){ t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
            
       cout<<"Enter right child of "<<p->data<<" "<<endl;
        cin>>x;
        
        if(x!=-1){ t = new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

int main(){
Tree t;
t.createtree();
t.Preorder();
}

