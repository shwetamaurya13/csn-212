#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct interval
    {
    int low,high;
};
struct node
    {
    struct interval *it;
    int max;
    bool color;
    struct node *left, *right, *parent;
};
struct node *createNewNode (struct interval *i)
    {
    struct node *temp= new struct node;
        temp->it= new struct interval;
        temp->it->low=i->low;
    temp->it->high=i->high;
        temp->max=i->high;
    temp->color=1; // 1 denotes red
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *BSTInsertion(struct node *root, struct node *pt)
    {

    if (root == NULL)
       return pt;
    
    if (pt->it->low < root->it->low)
    {
        root->left  = BSTInsertion(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->it->low > root->it->low)
    {
        root->right = BSTInsertion(root->right, pt);
        root->right->parent = root;
    }
  
    if (root->max < pt->it->high)
        root->max = pt->it->high;
    return root;
}
struct node *leftRotate(struct node *root, struct node *pt)
    {
    struct node *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;
    return root;
}

struct node *rightRotate(struct node *root, struct node *pt)
    {
      struct node *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
    return root;
}

struct node * fixRBT(struct node *root, struct node *pt)
    {
      struct node *parent_pt = NULL;
    struct node *grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != 0) &&
           (pt->parent->color == 1))
    {
 
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
        if (parent_pt == grand_parent_pt->left)
        {
 
            struct node *uncle_pt = grand_parent_pt->right;
            if (uncle_pt != NULL && uncle_pt->color == 1)
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
 
            else
            {
                if (pt == parent_pt->right)
                {
                    leftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rightRotate(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        else
        {
            struct node *uncle_pt = grand_parent_pt->left;
            if ((uncle_pt != NULL) && (uncle_pt->color == 1))
            {
                grand_parent_pt->color =1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    rightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                leftRotate(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
 
    root->color = 0;
    return root;
}
struct node *RBTInsertion (struct node *root, struct interval *i)
    { struct node *temp= createNewNode(i); 
  root = BSTInsertion(root, temp);
    root=fixRBT(root,temp);
    return root;
}
bool doOVerlap(interval i1, interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}

interval *overlapSearch(struct node *root, interval i)
{
    if (root == NULL) return NULL;

    if (doOVerlap(*(root->it), i))
        return root->it;

    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
 
    return overlapSearch(root->right, i);
}
int main()
{
    interval ints[] = {{15, 20}, {10, 30}, {17, 19},{5, 20}, {12, 15}, {30, 40} };
    int n = sizeof(ints)/sizeof(ints[0]);
    struct node *root = NULL;
    for (int i = 0; i < n; i++)
        root = RBTInsertion(root, ints+i);
 
    interval x = {14,16};
 
    cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
    interval *res = overlapSearch(root, x);
    if (res == NULL)
        cout << "\nNo Overlapping Interval";
    else
        cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
    return 0;
}
    


