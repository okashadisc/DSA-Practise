class Node {
    
    public:
    Node* left;
    Node* right;
    int val;
    int lazy;
    
    Node(){
        
        left= NULL;
        right= NULL;
        val= 0;
        lazy= 0;
    }
    
//     void extend(){
        
//         left= new Node();
//         right= new Node();
//     }
};
class SegmentTree {
    
    public:
    int n;
    Node* root;
    
    SegmentTree(int _n){
        
       root= new Node();
        
        n= _n;
    }
    
    void up(int left,int right,int val){
        
        updateRangeQuery(root,0,n,left,right,1);
    }
    
    int query(int left,int right){
        
        return rangeSumQuery(root,0,n,left,right);
    }
    
    void updateRangeQuery(Node* root,int start,int end,int left,int right,int val){
        
        if(root->lazy){
            
            root->val+= root->lazy;
            if(start != end){
                if(!root->left or !root->right){
                    
                    root->left= new Node();
                    root->right= new Node();
                }
                
                root->left->lazy+= root->lazy;
                root->right->lazy+= root->lazy;
                
            }
            
            root->lazy=0;
        }
        
        // No Overlap
        
        if(end<left or start>right or start>end)return;
        
        // Complete Overlap
        
        if(start>=left and end<=right){
            
            root->val+= (val);
            
            if(start != end){
                
                if(!root->left or !root->right){
                    
                    root->left= new Node();
                    root->right= new Node();
                }
            
                root->left->lazy+= (val);
                root->right->lazy+= (val);
            
            }
            
            return;
        }
        
        // Partial Overlap
        
        int mid= start + (end-start)/2;
        
        if(!root->left or !root->left){
            
            root->left= new Node();
            root->right= new Node();
        }
        
        updateRangeQuery(root->left,start,mid,left,right,val);
        
        updateRangeQuery(root->right,mid+1,end,left,right,val);
        
        root->val= max(root->left->val,root->right->val);
        
        
    }
    
    int rangeSumQuery(Node* root,int start,int end,int left,int right){
        
        if(root->lazy){
            
            root->val+= (root->lazy);
            
            if(start != end){
                
                if(!root->left or !root->right){
                    
                    root->left= new Node();
                    root->right= new Node();
                }
                
                root->left->lazy+= (root->lazy);
                root->right->lazy+= (root->lazy);
            }
            
            root->lazy= 0;
        }
        
        // No Overlap
        
        if(end<left or start>right or start>end)return 0;
        
        // Complete Overlap
        
        if(start>=left and end<=right){
            
            return root-> val;
        }
        
        // Partial Overlap
        
        int mid= start + (end-start)/2;
        
        if(!root->left or !root->right){
            
            root->left= new Node();
            root->right= new Node();
        }
        
        return max(rangeSumQuery(root->left,start,mid,left,right),rangeSumQuery(root->right,mid+1,end,left,right));
        
        
    }
};
class MyCalendarTwo {
public:
    int n= 1e9 + 5;
    SegmentTree* st;
    
    MyCalendarTwo() {
        
        st= new SegmentTree(n);
    }
    
    bool book(int start, int end) {
        
        int intersection= st->query(start,end-1);
        if(intersection==2)return false;
        
        st->up(start,end-1,1);
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */