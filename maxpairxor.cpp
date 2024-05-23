#include<bits/stdc++.h>
using namespace std;
//find maximum xor pair A[i]^A[j] i!=j N=1e5 A[i]<=1e6
//length 22 for each path
//can also find the indices by storing index in node structure
struct node{
  int count;
  node* child[2];
  node()
  {
    child[0]=child[1]=NULL;
    count=0;
  }
};
struct trie{
  node *root;
  trie()
  {
    root=new node;
  }
  void add(int num)
  {
    node*curr=root;
    for(int i=20;i>=0;i--)
    {
      if(!curr->child[(num>>i)&1])
      {
        curr->child[(num>>i)&1]=new node;
      }
      curr=curr->child[(num>>i)&1];
      curr->count++;
    }
  }
};
void solve()
{
  int n;
  cin>>n;
  vector<int>v(n);
  trie tri1;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    tri1.add(v[i]);
  }
  int ans=0;
  for(int i=0;i<n;i++)
  {
    node *curr=tri1.root;
    int currans=0;
    int ele=v[i];
    for(int j=20;j>=0;j--)
    {
      if(!(curr->child[!((ele>>j)&1)])){
        curr=curr->child[(ele>>j)&1];
      }
      else{
        currans=currans|(1<<j);
        curr=curr->child[!((ele>>j)&1)];
      }
    }
    ans=max(ans,currans);
  }
  cout<<ans<<"\n";
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