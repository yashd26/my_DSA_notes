// Queue structure
struct Queue {
    int size;
    int front;
    int Rear;
    int *Q;
}

int main() {
    struct Queue q;
    input(q.size);
    q.Q = (int *)malloc(q.size*sizeof(int));
    q.front = q.Real = -1;
}

// enqueue in queue
void enqueue(Queue *q, int x) {
    if (q -> Rear == q -> size - 1) {
        print("Queue full");
    }
    else {
        q -> Rear++:
        q -> Q[q -> Rear] = x;
    }
}

// dequeue in queue
void dequeue(Queue *q) {
    int x = -1;
    if (q -> front == q -> Rear) {
        print("Queue empty");
    }
    else {
        x = q -> Q[q -> front];
    }
    return x;
}

// circular queue
void create(struct Queue *q,int size) {    
    q->size=size;
    q->front=q->rear=0;    
    q->Q=(int *)malloc(q->size*sizeof(int)); 
} 

// display queue
void Display(struct Queue q) {    
    int i=q.front+1;        
    do {            
        printf("%d ",q.Q[i]);        
        i=(i+1)%q.size;    
    }
    while(i!=(q.rear+1)%q.size);
    print("\n");
} 

// enqueue in circular queue
void enqueue(struct Queue *q,int x) {    
    if((q->rear+1)%q->size==q->front) {        
        printf("Queue is Full");
    }    
    else {        
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;    
    } 
} 

// dequeue in circular queue
int dequeue(struct Queue *q) {    
    int x=-1;
    if(q->front==q->rear) {        
        printf("Queue is Empty\n");    
    }
    else {        
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];   
    }
    return x; 
}
