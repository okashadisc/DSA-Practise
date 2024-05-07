class MyCircularQueue {
public:
    struct node{
        
        int val;
        node* next;
        node* prev;
        
        node(int val_){
            
            val= val_;
        }
    };
    
    int cap, currSize=0;
    node* head= NULL;
    node* tail= NULL;
    
    MyCircularQueue(int k) {
        
        cap= k;
        head= new node(-1);
        tail= new node(-1);
        
        head->next= tail;
        tail->prev= head;
        head->prev= tail;
        tail->next= head;
    }
    
    bool enQueue(int value) {
        
        if(isFull())return false;
        
        node* newNode= new node(value);
        newNode->next= tail;
        newNode->prev= tail->prev;
        tail->prev->next= newNode;
        tail->prev= newNode;
        currSize+= 1;
        
        return true;
    }
    
    bool deQueue() {
        
        if(isEmpty())return false;
        
        auto delNode= head->next;
        head->next= delNode->next;
        delNode->next->prev= head;
        currSize-=1;
        
        return true;
    }
    
    int Front() {
        
        if(isEmpty())return (-1);
        
        return head->next->val;
    }
    
    int Rear() {
        
        if(isEmpty())return (-1);
        
        return tail->prev->val;
    }
    
    bool isEmpty() {
        
        return (currSize==0);
    }
    
    bool isFull() {
        
        return currSize==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */