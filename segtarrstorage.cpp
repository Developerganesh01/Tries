#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class sgtarrstorage{
  public:
  vector<vector<int>>storage;
  int nodes;
  sgtarrstorage(int nodes,vector<int>&arr)
  {
    storage.resize(4*nodes);
    this->nodes=nodes;
    build(1,0,nodes-1,arr);
  }
  void build(int index,int l,int r,vector<int>&arr)
  {
    if(l==r)
    {
      storage[index].push_back(arr[l]);
      return;
    }
    int mid=l+(r-l)/2;
    build(2*index,l,mid,arr);
    build(2*index+1,mid+1,r,arr);
    int i=0,j=0,n=storage[2*index].size(),m=storage[2*index+1].size();
    while(i<n&&j<m)
    {
      if(storage[2*index][i]<=storage[2*index+1][j])
      {
        storage[index].push_back(storage[2*index][i]);
        i++;
      }
      else
      {
        storage[index].push_back(storage[2*index+1][j]);
        j++;
      }
    }
    while(i<n)
    {
      storage[index].push_back(storage[2*index][i]);
      i++;
    }
    while(j<m)
    {
      storage[index].push_back(storage[2*index+1][j]);
      j++;
    }
  }
  ll query(int index,int l,int r,int lq,int rq,int k)
  {
    if(l>rq || lq>r){
      return 0;
    }
    if(l>=lq&&r<=rq)
    {
      return (storage[index].size()-(lower_bound(storage[index].begin(),storage[index].end(),k)-storage[index].begin()));
    }
    int mid=l+(r-l)/2;
    ll left=query(2*index,l,mid,lq,rq,k);
    ll right=query(2*index+1,mid+1,r,lq,rq,k);
    return left+right;
  }
};
void solve()
{

}
int main(){
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}