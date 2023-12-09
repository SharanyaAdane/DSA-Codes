#include <iostream>
#include<iostream>


using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node *parent;


    Node(int d)
    {
        this->data=d;
        this->left=nullptr;
        this->right=nullptr;
        this->parent=nullptr;
        this->height=0;

    }


};
int getHeight(Node *n)
{
    if(n==nullptr)
        return -1;
    else
        return n->height;
}
void UpdateHt(Node *&n)
{
    int leftht=getHeight(n->left);
    int rightht=getHeight(n->right);
    n->height=max(leftht,rightht)+1;
}

int Balance(Node *n)
{
    if(n==nullptr)
        return 0;
    else
        return (getHeight(n->left)-getHeight(n->right));
}
void LeftRot(Node *&n)
{
    Node *t=n->right;
    Node *x=t->left;
    n->right=x;

    if(x)
    {
        x->parent=n;
    }
    t->left=n;
    t->parent=n->parent;
    n->parent=t;

//n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
   // t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
    UpdateHt(n);
    UpdateHt(t);
    n=t;
}
void RightRot(Node *&n)
{
    Node *t=n->left;
    Node *x=t->right;
    n->left=x;
    if(x)
    {
        x->parent=n;
    }
    t->right=n;
    t->parent=n->parent;
    n->parent=t;

    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
   n=t;
}
void Insert(Node *&n,int t)
{
    if(n==nullptr)
       n=new Node(t);
    else if(n->data < t)
    {
        if(n->right==nullptr)
        {n->right=new Node(t);
         n->right->parent=n;

        }
        else
            Insert(n->right,t);
    }
      else if(n->data > t)
    {
        if(n->left==nullptr)
        {n->left=new Node(t);
         n->left->parent=n;
        }
        else
            Insert(n->left,t);
    }
    UpdateHt(n);
   int blc;
    blc=Balance(n);
    //cout << blc;
    if(blc>1)
    {
        if(t> (n->left->data))
        {
            LeftRot(n->left);

        }

             RightRot(n);
    }
    else if(blc<-1)
    {
        if(t< (n->right->data))
        {
            RightRot(n->right);

        }

             LeftRot(n);
    }


}
/*void Inorder(Node *n, bool isLast = false) {
    if (n == nullptr)
        return;

    Inorder(n->left, false);

    cout << n->data << ":" << n->height;

    if (!isLast) {
        cout << " --> ";
    } else {
        cout << endl;
    }

    Inorder(n->right, false);
}
*/
Node* pred(Node *n)
{
    while(n->right!=nullptr){
        n=n->left;
    }
    return n;
}
void Delete(Node *&n,int t)
{

    if(n==nullptr)
        return;
    else if(n->data < t)
        Delete(n->right,t);
    else if(n->data > t)
        Delete(n->left,t);
    else{
        if(n->left==nullptr || n->right==nullptr)
        {
            Node *temp=(n->left)?n->left:n->right;
            if(temp==nullptr)
            {
                temp=n;
                 n=nullptr;
            }
            else
            {
                *n=*temp;

            }
            delete temp;
        }
        else{
            Node *temp=pred(n->left);
            n->data=temp->data;
            Delete(n->left,temp->data);

        }
        if(n==nullptr)
            return;
        n->height=max(getHeight(n->left), getHeight(n->right));


    }
}
void Inorder(Node *n)
{
    if (n==nullptr)
        return;
    Inorder(n->left);
    cout << n->data << ":" << n->height << "-->";
    Inorder(n->right);
}
int main()
{   Node *root=nullptr;
    cout << "Enter the number of nodes" << endl;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "Enter the data" << endl;
        int k;
        cin >> k;
        Insert(root,k);
    }
    Inorder(root);
    cout << "Enter to delete" << endl;
    int d;
    cin >> d;
    Delete(root,d);
    Inorder(root);
    return 0;
}
