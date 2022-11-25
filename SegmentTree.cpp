template <typename T> class ST{
	private:
		vector<T> Tree, v;
		int size;
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
		void updateTree(int tidx, int lo, int hi, int idx, T val){
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
		int queryTree(int tidx, int lo, int hi, int L, int R){
			if( R<lo || L>hi )
				return 0;
			if( L<=lo && hi<=R )
				return Tree[tidx];
			int mid = (lo+hi)/2;
			int leftans = queryTree(2*tidx+1, lo, mid, L, R);
			int rightans = queryTree(2*tidx+2, mid+1, hi, L, R);
			return leftans + rightans;
		}

	public:
		ST(vector<T> &m){
			v = m;
			size = m.size();
			Tree.resize(3*size,0);
		};
		void build(){buildTree(0,0,size - 1);};
		void update(int idx, T val){updateTree(0,0,size - 1,idx,val);};
		int query(int L,int R){return queryTree(0,0,size - 1,L,R);};
};