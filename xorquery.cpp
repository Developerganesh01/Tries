#include<bits/stdc++.h>
using namespace std;
//+x -x ? y k x^y>=k
struct node{
  int ct;
  node *child[2];
  node()
  {
    ct=0;
    child[0]=child[1]=NULL;
  }
};
struct trie{
  node *root;
  multiset<int>ms;
  trie()
  {
    root=new node;
  }
  void add(int num)
  {
    ms.insert(num);
    node *curr=root;
    for(int i=20;i>=0;i--)
    {
      if(!(curr->child[(num>>i)&1]))
      {
        curr->child[(num>>i)&1]=new node;
      }
       curr=curr->child[(num>>i)&1];
      curr->ct++;
    }
  }
  void remove(int num)
  {
    if(ms.find(num)==ms.end())return;
    auto it=ms.find(num);
    ms.erase(it);
    node *curr=root;
    for(int i=20;i>=0;i--)
    {
      curr=curr->child[(num>>i)&1];
      curr->ct--;
    }
  }

};
void solve()
{
  
  trie tri1;
  int q;
  cin>>q;
  while(q--)
  {
    int type;
    cin>>type;
    if(type==1)
    {
      int x;
      cin>>x;
      tri1.add(x);
    }
    else if(type==2)
    {
      int x;
      cin>>x;
      tri1.remove(x);
    }
    else
    {
      int y,k;
      cin>>y>>k;
      //#x (x^y)<=k
      int ans=0;
      node *curr=tri1.root;

      for(int i=20;i>=0;i--)
      {
        //b1->ith bit of k
        //b2->ith bit of y
        int b1=(k>>i)&1,b2=(y>>i)&1;
        if(b1)
        {
          //all element which gives 0 after xor with y at ith bit will be always lesser than k
         ans+=(curr->child[b2]?((curr->child[b2])->ct):0);
        }
         curr=curr->child[b1];
         //take path of k and if curr becomes null means we are done no further elements satisfying
         if(!curr)
         {
          break;
         }
      }
      if(curr){
        //represents (x^y)=k;
        ans+=curr->ct;
      }
      cout<<ans<<"\n";
    }
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