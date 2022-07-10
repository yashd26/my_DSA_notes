// Structure of AVL
struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
    int height;
}*root = NULL;

// Find max_height of node
int NodeHeight(struct Node *p) {    
    int hl,hr;    
    hl=p && p->lchild?p->lchild->height:0;    
    hr=p && p->rchild?p->rchild->height:0;        
    return hl>hr?hl+1:hr+1; 
} 

// Return balance factor of node
int BalanceFactor(struct Node *p) {    
    int hl,hr;    
    hl=p && p->lchild?p->lchild->height:0;    
    hr=p && p->rchild?p->rchild->height:0;        
    return hl-hr; 
}

// Algo for Left-Left case
struct Node *LLRotation(struct Node *p) {    
    struct Node *pl = p -> lchild;    
    struct Node *plr = pl -> rchild;    
    pl -> rchild = p;    
    p -> lchild= plr;    
    p -> height = NodeHeight(p);    
    pl -> height = NodeHeight(pl);
    if (root == p) {
        root = pl;
    }
    return pl; 
}

// Algo for Left-Right case
struct Node * LRRotation(struct Node *p) {    
    struct Node *pl=p->lchild;    
    struct Node *plr=pl->rchild;        
    pl->rchild=plr->lchild;    
    p->lchild=plr->rchild;        
    plr->lchild=pl;    
    plr->rchild=p;        
    pl->height=NodeHeight(pl);    
    p->height=NodeHeight(p);    
    plr->height=NodeHeight(plr);        
    if(root==p) {
        root=plr;
    }           
    return plr; 
} 

// Insert in AVL tree
struct Node *RInsert(struct Node *p,int key) {    
    struct Node *t=NULL;        
    if(p==NULL) {        
        t=(struct Node *)malloc(sizeof(struct Node));        
        t->data=key;        
        t->height=1;        
        t->lchild=t->rchild=NULL;        
        return t;    
    }    
    if(key < p->data) {        
        p->lchild=RInsert(p->lchild,key);    
    }
    else if(key > p->data) {        
        p->rchild=RInsert(p->rchild,key);        
    }
    p->height=NodeHeight(p);        
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1) {        
        return LLRotation(p);    
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1) {       
        return LRRotation(p);    
    }
    /*
    else if(BalanceFactor(p)==-2 && BalanceFactor(p>rchild)==-1) {        
        return RRRotation(p);    
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p>rchild)==1) {        
        return RLRotation(p);    
    }
    */
    return p;    
}
