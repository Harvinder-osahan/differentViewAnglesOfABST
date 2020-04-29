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
            trav(root->left,v1,v2,ind);ind++;
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
cout<<" Height of this tree is>> "<<factor<<endl;
trav(root,v1,v2,0);
int M;
cout<<v1.size()<<"    ";
for(int i=0;i<v1.size();i++)v1[i]+=factor-1;
//for(int i=0;i<v1.size();i++)cout<<v1[i];
vector<int> freq(v1.size(), 0);
for(int i = 0;i < v1.size();i++)
{
    if(freq[v1[i]]==0)
       {
        freq[v1[i]]++;
        vc.push_back( make_pair(v1[i],v2[i]) );
       }
}

v1.clear();v2.clear();
freq.clear();
sort(vc.begin(),vc.end());
cout<<endl<<"TOP VIEW\n";

for(i=0;i<vc.size();i++)
{

        cout<<vc[i].second<<endl;
}

return 0;
}
