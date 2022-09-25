class MyCircularQueue {
public:
    int* arr;
    int size = 0;
    int top   = -1;
    int back  = -1;
    int el = 0;
    
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
    }
    
    bool enQueue(int value) {
        if(el < size){
             if(el == 0){
                 top =  0;
                 back = 0;
                 el++;
                 arr[back] = value;
                 
             }else{
                 back = (back + 1)%size;
                 el++;
                 arr[back] = value;
                 
                 
             }
            
            return true;
        }
        return false;
        
    }
    
    bool deQueue() {
        if(el > 0 ){
            if(el == 1){
                top = -1;
                back = -1;
                el = 0;
                
            }else{
                top = (top + 1) % size;
                el--;
                
            }
            return true;
        }
        
        
        return false;
    }
    
    int Front() {
        if(el > 0)
            return arr[top];
        return -1;
        
    }
    
    int Rear() {
        if(el > 0)
            return arr[back];
        return -1;
        
    }
    
    bool isEmpty() {
        return el == 0;
        
    }
    
    bool isFull() {
        return el == size;
        
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