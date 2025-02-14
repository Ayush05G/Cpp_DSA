class ProductOfNumbers {
    public:
        vector<int> arr;
        
        ProductOfNumbers() {
        }
        
        void add(int num) {
            arr.push_back(num);
        }
        
        int getProduct(int k) {   
            int product = 1;
            int n = arr.size();
            for (int i = 0; i < k; i++) {
                product *= arr[n - 1 - i]; 
            }
            return product;
        }
    };