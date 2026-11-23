class ProductOfNumbers {
public:

    vector<int> res;
    int n;

    ProductOfNumbers() {
        res.clear();
        n = 0;
    }
    
    void add(int num) {

        if(num == 0) {
            res = {};
            n = 0;
        } else if(res.empty()) res.push_back(num);
        else res.push_back(num * res.back());
        n++;
    }
    
    int getProduct(int k) {

        int n = res.size();
        
        if(k > n) return 0;
        else if(k == n) return res.back();
        else return res[n-1] / res[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */