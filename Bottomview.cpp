#include<bits/stdc++.h>
using namespace std;
struct t{
int data;
t* l,* r;
} *root;

t* N(int v)
{
    t* nd=  new t;
    nd->data=v;
    nd->l=nd->r=NULL;
return nd;
}

t* Ins(t* root, int v)
{
    if(root==NULL)
        return N(v);
    if(root->data>v)
    {
        root->l=Ins(root->l, v);
    }
    else{
        root->r=Ins(root->r, v);
    }
return root;
}
bool printLevel(t* root, int level,vector<int> &v)
{
    if (root == NULL)
        return false;

    if (level == 1)
    {
        v.push_back(root->data);

        // return true if at-least one node is present at given level
        return true;
    }

    bool left = printLevel(root->l, level - 1,v);
    bool right = printLevel(root->r, level - 1,v);

    return left || right;
}
void trav(t* root, int h,vector<int>&v)
{
    int level=h;

while(printLevel(root,level,v))
    level++;

}

int height(t* root)
{
    if(root==NULL)
        return 0;

    return 1+ max(height(root->l),height(root->r));
}


int main()
{
    t* root=NULL;
    int n,c;
vector<int>v;
    cin>>n;

    while(n--)
    {
        cin>>c;
        root=Ins(root, c);
    }

int factor=height(root);
cout<<" Height of this tree is>> "<<factor<<endl;
trav(root,factor-1,v);
for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";

}
