//lc 1352


//bruteforce //o(k)

class ProductOfNumbers {
    public:
        vector<int>q;
        ProductOfNumbers() { 
        
        }
        
        void add(int num) {
           q.push_back(num);
        }
        
        int getProduct(int k) {
            int ans=1;
            int size=q.size();
            for(int i=size-1;k>0;i--){
                ans*=q[i];
                k--;
            }
            return ans;
        }
    };
    
    

    // optimal 1 khud
    // o(1)
    // tarika 1
    class ProductOfNumbers {
        public:
            vector<int> preprod; // stores pre product of an element (incl) .... after previous last zero element
            int i = -1; // for index of last zero
            int n=0; // size of stream
        
            ProductOfNumbers() {
              
            }
            
            void add(int num) {
                if (num == 0) {
                    preprod.push_back(1);  // Reset product sequence
                    n++;
                    i=n-1;  // Store the index of zero
                } else 
                {
                    if(n==0) preprod.push_back(num);
                    else preprod.push_back(preprod.back() * num);
                    n++;
                }
                
            }
            
            int getProduct(int k) {
                if ( i >= n - k) { 
                    return 0;  // If a zero exists in the last k elements, product is 0
                }
                if(n==k) return preprod.back() ;
                return preprod.back() / preprod[n - k - 1];
            }
        };
        //tarika 2

        class ProductOfNumbers {
            public:
                vector<int> preprod; // stores pre product of an element (incl) .... after previous last zero element
                
                int i = -1; // for idx of last zero
                int n=0;
            
                ProductOfNumbers() {
                    preprod.push_back(1);  // Initial product of 1 // to handle 1.multiplication logic in add() for first element 2.getproduct() mein preprod[n - k - 1] when elements in stream = k
                    n++;
                }
                
                void add(int num) {
                    if (num == 0) {
                        preprod.push_back(1);  // Reset product sequence
                        n++; 
                        i=n-1;  // Store the index of zero
                    } else {
                        preprod.push_back(preprod.back() * num);
                        n++;
                    }
                   
                }
                
                int getProduct(int k) {
                    if (i >= n - k) { 
                        return 0;  // If a zero exists in the last k elements, product is 0
                    }
                    return preprod.back() / preprod[n - k - 1];
                }
            };
    
            
         
    
        
        // optimal 2
        //o(1)

       // https://youtu.be/Jvu3hd8A2rg?si=WBOUc1r2x5AaMLye

       //tarika 1

       class ProductOfNumbers {
        private:
            
            vector<int> pre; // Stores pre product of the elements of stream
            int size = 0; // length of stream
        
        public:
            ProductOfNumbers() {
                
            }
        
            void add(int num) {
                if (num == 0) {
                    // If num is 0, reset the cumulative products since multiplication
                        // with 0 invalidates previous products
                    pre = {};
                    size = 0;
                } else {
                    // Append the cumulative product of the current number with the last
                    // product
                    if(size==0) pre.push_back(num);
                    else pre.push_back(pre.back() * num);
                    size++;
                }
            }
        
            int getProduct(int k) {
                // Check if the requested product length exceeds the size of the valid
                    // product list
                if (k > size) return 0;
                 // Compute the product of the last k elements using division
                if(size==k) return pre[size-1];
                return pre[size-1] / pre[size-1 - k];
            }
        };

       //tarika 2

        class ProductOfNumbers {
            private:
            
                vector<int> prefixProduct;// Stores pre product of the elements of stream
                int size = 0;
            
            public:
                ProductOfNumbers() {
                    // Initialize the product list with 1  to handle 1.multiplication logic in add() for first element 2.getproduct() mein prefixProduct[size-1 - k] when elements in stream = k
                    prefixProduct.push_back(1);
                    size++;
                }
            
                void add(int num) {
                    if (num == 0) {
                        // If num is 0, reset the cumulative products since multiplication
                        // with 0 invalidates previous products
                        prefixProduct = {1};
                        size = 1;
                    } else {
                        // Append the cumulative product of the current number with the last
                        // product
                        prefixProduct.push_back(prefixProduct[size-1] * num);
                        size++;
                    }
                }
            
                int getProduct(int k) {
                    // Check if the requested product length exceeds the size of the valid
                    // product list
                    if (k > size-1) return 0;
            
                    // Compute the product of the last k elements using division
                    return prefixProduct[size-1] / prefixProduct[size-1 - k];
                }
            };