#include <iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class treenode
{
  public:
  T data;
  vector<treenode<int>*> children;
  treenode(T data)
  {
    this->data=data;
  }
};
void printtree(treenode<int>*root)
{
 if(root==NULL)
 {
   return;
 } 
  cout<<root->data<<":";
  for(int i=0;i<root->children.size();i++)
  {
    cout<<root->children[i]->data<<",";
  }
  cout<<endl;
  for(int i=0;i<root->children.size();i++)
  {
    printtree(root->children[i]);
  }
}
treenode<int> *takeinput()
{
  int rootdata;
  cout<<"enter root data"<<endl;
  cin>>rootdata;
  treenode<int> *root=new treenode<int>(rootdata);
  queue<treenode<int>*> pendingnodes;
  pendingnodes.push(root);
  while(pendingnodes.size()!=0)
  {
    treenode<int> *front = pendingnodes.front();
    pendingnodes.pop();
    cout<<"enter no. of children of "<<front->data<<endl;
    int numchild;
    cin>>numchild;
    for(int i=0;i<numchild;i++)
    {
      int childdata;
      cout<<"enter"<<i<<"th child of"<<front->data<<endl;
      cin>>childdata;
      treenode<int> *child=new treenode<int>(childdata);
      front->children.push_back(child);
      pendingnodes.push(child);
    }
  }
  return root;
}
int numnodes(treenode<int> *root)
{
  int ans=1;
  for(int i=0;i<root->children.size();i++)
  {
    ans =ans + numnodes(root->children[i]);
  }
  return ans;
}
int height(treenode<int> *root)
{
  int max=0;
  for(int i=0;i<root->children.size();i++)
  {
    int h1 = height(root->children[i]);
    if(h1>max)
    {
      max=h1;
    }
  }
  return max+1;
}
void printatlevel(treenode<int> *root,int k)
{
  if(k==0)
  {
    cout<<root->data<<endl;
    return;
  }
  if (root==NULL)
  {
    return;
  }
  for(int i=0;i<root->children.size();i++)
  {
    printatlevel(root->children[i],k-1);
  }
}
void preorder(treenode<int> *root)
{
  if(root==NULL)
  {
    return;
  }
  cout<<root->data<<" ";
  for(int i=0;i<root->children.size();i++)
  {
    preorder(root->children[i]);
  }
}
void postorder(treenode<int> *root)
{
    if(root==NULL)
  {
    return;
  }
  for(int i=0;i<root->children.size();i++)
  {
    postorder(root->children[i]);
  }
   cout<<root->data<<" ";
}
treenode<int>* maxsumnodes(treenode<int>*root)
{
  treenode<int>*y=root;
  int ans=root->data;
  for(int i=0;i<root->children.size();i++)
  {
    ans=ans + root->children[i]->data;
  }
  for(int i=0;i<root->children.size();i++)
  {
    treenode<int> *x =maxsumnodes(root->children[i]);
    int xsum = x->data;
    for(int i=0;i<x->children.size();i++)
    {
      xsum = xsum+ x->children[i]->data;
    }
    if(xsum>ans)
    {
      y=x;
      ans=xsum;
    }   
  }
  return y;
}
int main()
{
  treenode<int> *root = takeinput();
  maxsumnodes(root);
}