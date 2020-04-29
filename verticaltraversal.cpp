#include<bits/stdc++.h>
using namespace std;
struct tree{
  int data;
  tree*left, *rite;
} *root;
tree* Node(int val)
{
    tree* o =new tree;
    o->data=val;
    o->left=o->rite=NULL;

}
tree*insertO(tree* root, int val)
{
    if(root==NULL)
        return Node(val);

    if(root->data>val)
    {
     root->left=insertO(root->left,val);
    }
    else{
        root->rite=insertO(root->rite,val);
    }
return root;
}
/*
void getVerticalOrder(tree* root, int hd, map<int, vector<int> > &m)
{
    // Base case
    if (root == NULL)
        return;

    // Store current node in map 'm'
    m[hd].push_back(root->data);

    // Store nodes in left subtree
    getVerticalOrder(root->left, hd-1, m);

    // Store nodes in right subtree
    getVerticalOrder(root->rite, hd+1, m);
}

// The main function to print vertical order of a binary tree
// with the given root
void printVerticalOrder(tree* root)
{
    // Create a map and store vertical order in map using
    // function getVerticalOrder()
    map < int,vector<int> > m;
    int hd = 0;
    getVerticalOrder(root, hd,m);

    // Traverse the map and print nodes at every horigontal
    // distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
*/


void trav(tree* root, vector<int>&v1,vector<int>&v2,int ind)
{
    if(root==NULL)
    {
        return;
    }
    if(root!=NULL)
    {
        v1.push_back(ind);
        v2.push_back(root->data);
        if(root->left)
            ind=ind-1;
            trav(root->left,v1,v2,ind);
            ind++;
        if(root->rite)
             ind=ind+1;
             trav(root->rite,v1,v2,ind);
    }

}
int height(tree* root)
{
    if(root==NULL)
        return 0;

    return 1+ max(height(root->left),height(root->rite));
}
int main(){

tree* root=NULL;
vector<pair<int,int> >vc;
vector<int> v1,v2;
int i,n,x;
cin>>n;
while(n--)
{
    cin>>x;
    root=insertO(root,x);
}
int factor=height(root);
//cout<<factor<<"\n\n";
trav(root,v1,v2,0);
//inorder(root,vc,v,factor);

for(int i = 0;i<v1.size();i++)
{
 vc.push_back( make_pair(v1[i],v2[i]) );
 //cout<<v1[i]<<" "<<v2[i]<<" "<<vc[i].first<<vc[i].second<<endl;
}
v1.clear();v2.clear();

sort(vc.begin(),vc.end());
cout<<endl;
cout<<vc[0].second;

for(i=1;i<vc.size();i++)
{
    if(vc[i-1].first!=vc[i].first)cout<<endl<<vc[i].second<<" ";

    else
        cout<<vc[i].second<<" ";
}

//cout<<endl<<endl<<endl;
//printVerticalOrder(root);
return 0;
}
