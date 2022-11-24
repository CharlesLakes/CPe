<<<<<<< HEAD
//#include <bits/stdc++.h>
//using namespace std;
vector<int> v, Tree;
void buildTree(int tidx, int lo, int hi){
	if(lo==hi){
		Tree[tidx] = v[hi];
		return;
	}
	int mid = (lo+hi)/2;
	buildTree(2*tidx+1, lo, mid);
	buildTree(2*tidx+2, mid+1, hi);
	Tree[tidx] = Tree[2*tidx+1] + Tree[2*tidx+2];

}

void updateTree(int tidx, int lo, int hi, int idx, int val){
	if(lo==hi){
		Tree[tidx] = val;
		return;
	}
	int mid = (lo+hi)/2;
	if(idx<=mid)
		updateTree(2*tidx+1, lo, mid, idx, val);
	else
		updateTree(2*tidx+2, mid+1, hi, idx, val);
	Tree[tidx] = Tree[2*tidx+1] + Tree[2*tidx+2];
}

int query(int tidx, int lo, int hi, int L, int R){
	if( R<lo || L>hi )
		return 0;
	if( L<=lo && hi<=R )
		return Tree[tidx];
	int mid = (lo+hi)/2;
	int leftans = query(2*tidx+1, lo, mid, L, R);
	int rightans = query(2*tidx+2, mid+1, hi, L, R);
	return leftans + rightans;

=======
const int N = 1e5;
int n;
int t[2 * N];

void build() { 
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) { 
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) { 
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
>>>>>>> a6c6ea8c69f084166a72057c476b7b1bc8ba24b1
}
