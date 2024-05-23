#include<bits/stdc++.h>
using namespace std;
//q querires to find common prefises
struct node{
  int val;
  node * child[2];
  node()
  {
    child[0]=child[1]=NULL;
    val=0;
  }
};
struct trie{
  node *t;
  trie()
  {
    t=new node;
  }
  void insert(string s)
  {
    node *curr=t;
    for(int i=0;i<s.size();i++)
    {
        if(!(curr->child[s[i]-'0']))
        {
          curr->child[s[i]-'0']=new node;
        }
        curr=curr->child[s[i]-'0'];
        curr->val++;
      }
    }
};
void show(trie &tri1,node *curr)
{
  if(!curr)
  {
    return ;
  }
  cout<<curr->val<<" ";
  show(tri1,curr->child[0]);
show(tri1,curr->child[1]);
}
void solve()
{
  int n;
  cin>>n;
  vector<string>v(n);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  trie tri1;
for(int i=0;i<n;i++)
{
  tri1.insert(v[i]);
}
show(tri1,tri1.t);
  int q;
  cin>>q;
  while(q--)
  {
    string s;
    cin>>s;
    int ct=0;
    node *curr=(tri1.t);
    for(int i=0;i<s.size();i++)
    {
      curr=curr->child[s[i]-'0'];
      if(curr==NULL)
      {
        break;
      }
    }
    if(curr)
    {
      ct=curr->val;
    }
    cout<<s<<" "<<ct<<"\n";
  }

}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}