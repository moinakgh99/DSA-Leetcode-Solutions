class NumArray {
public:
     vector<int>tree;
     int n;
    NumArray(vector<int>& nums) {
     n=nums.size();
     tree.resize(4*n);
     build(nums,0,0,n-1);
    }
    void build(vector<int>& nums, int node, int start, int end){
        if(start==end){
            tree[node]=nums[start];
        }   
        else{
             int mid = start+(end-start)/2;
            build(nums,2*node + 1, start, mid);
            build(nums,2*node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1]+tree[2 * node + 2];
        }     
    }

    void update(int index, int val) {
        f(0,0,n-1, index, val);
    }
    
    void f(int node, int start, int end, int index, int val){
      if(start==end){
        tree[node]=val;
        return;
      }
      else{
    int mid=(start+end)/2;
    if(index<=mid){
        f(2*node+1, start, mid, index, val);
    }
    else{
        f(2*node+2, mid+1, end, index, val);
    }
    tree[node]=tree[2*node+1]+tree[2*node+2];
      }
    }

    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }

    int query(int node, int start, int end, int l, int r){
    if (l>end || r<start) {
            return 0;
        }
        if (l<=start && end<=r) {
            return tree[node];
        }
        int mid = start+(end - start)/2;
        int left=query(2*node+1,start,mid,l,r);
        int right=query(2*node+2,mid+1,end,l,r);
        return left+right;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */