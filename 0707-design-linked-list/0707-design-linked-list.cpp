class Node{
public:
   int data;
   Node*next;
   Node(int val){  
    data = val;
    next = NULL;
   }
};


class MyLinkedList {
public:
      Node* head;
      Node* tail;
      int size;
    MyLinkedList() {
        
        head = tail = NULL;
        size = 0;
    }
    
    int get(int index) {
       if(index<0 || index>=size){
        return -1;
       }
       if(index == 0){
        return head->data;
       }
       if(index == size -1){
        return tail->data;
       }
        Node* temp = head;
        for(int i = 0;i<index;i++){
            temp = temp->next;
        }
        return temp->data;

        
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if(size == 0)
        {                            
          head = tail = newnode;
        }
        else{
        newnode->next = head;
        head = newnode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);
         if(size == 0){    
            head =  tail = newnode;
        }else{
        tail->next = newnode;   
        tail = newnode;
        }
       
        size++;
    }
    
    void addAtIndex(int index, int val) {
              
     if(index<0 || index>size)
     {
        return;
     }
     if(index == 0) 
     {
        addAtHead(val);
        return;
     }
     if(index == size){   
        addAtTail(val);
        return;
     }
     Node* newnode = new Node(val);
     Node* temp = head;
     for(int i = 0;i<index-1;i++){
        temp = temp->next;
     }                           
     newnode->next =temp->next;        
     temp->next = newnode;       
      size++;   
    }
    
    void deleteAtIndex(int index) {
    if(index<0 || index>=size)
     {
        return;
     }
     if(index == 0) 
     {
        Node*temp = head;
        head = head->next;
        delete temp;
        if(size == 1) tail = NULL; 
     }
     else{  
          Node* temp = head;
          for(int i = 0;i<index-1;i++){
            temp=temp->next;
          }
        Node*remove = temp->next;        
          temp->next = temp->next->next; 
          delete remove;                 
          if(index == size-1) tail = temp;  
     }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
