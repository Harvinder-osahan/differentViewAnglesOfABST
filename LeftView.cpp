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
void rtv(t* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";

         if(root->r)
            rtv(root->r);
         else if(root->l)
            rtv(root->l);
    }
    else
        return;
}
void ltv(t*root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
         if(root->l)
            ltv(root->l);
         else if(root->r)
            ltv(root->r);
    }
    else
        return;
}

int main()
{
    t*root=NULL;
    int n,c,i;
    cin>>n;
    while(n--)
    {
        cin>>c;
        root=Ins(root,c);
    }
cout<<"left view ";
   ltv(root);
    cout<<endl<<"right view ";
    rtv(root);
return 0;
}
