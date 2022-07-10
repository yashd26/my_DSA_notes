// Hash func
int hash(int key) {
    return key%10;
}

// Insert using chaining
void Insert(struct Node *H[], int key) {
    int index = hash(key);
    SortedInsert(&H[index], key);
}

// Search using chaining
int Search(int H[],int key) {    
    int index=hash(key);        
    int i=0;        
    while(H[(index+i)%10]!=key) {        
        i++;        
    }
    return (index+i)%10; 
} 

// Linear probing
// h'(x) = (h(x) + f(i)) % 10 where f(i) = 1, 2, 3, ..., 9

int probe(int H[],int key) {    
    int index=hash(key);
    int i=0;    
    while(H[(index+i)%10]!=0) {        
        i++;
    }    
    return (index+i)%10; 
}

void Insert(int H[],int key) {    
    int index=hash(key);        
    if(H[index]!=0) {        
        index=probe(H,key);
    }    
    H[index]=key; 
} 

int Search(int H[],int key) {    
    int index=hash(key);        
    int i=0;        
    while(H[(index+i)%10]!=key) {        
        i++;
    }        
    return (index+i)%10; 
}
