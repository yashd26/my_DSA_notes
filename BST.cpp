// Structure of BST
struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

// Recursive/iterative search in BST
RSearch(Node *t, int key) {
    if (t == NULL) {
        return NULL;
    }
    if (key == t -> data) {
        return t;
    }
    else if(key < t -> data) {
        return RSearch(t -> lchild, key);
    }
    else {
        return RSearch(t -> rchild, key);
    }
}

Node *Search(Node *t, int key) {
    while(t != NULL) {
        if (key == t -> data) {
            return key;
        }
        else if(key < t -> data) {
            t = t -> lchild;
        }
        else {
            t = t -> rchild;
        }
    }
    return NULL;
}

// Iterative/recursive inserting in BST
void Insert(int key) {
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p -> data = key;
        p -> lchild = p -> rchild = NULL;
        root = p;
        return;
    }
    while(t != NULL) {
        r = t;
        if (key < t -> data) {
            t = t -> lchild;
        }
        else if (key > t -> data) {
            t = t -> rchild;
        }
        else {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p -> data = key;
    p -> lchild = p -> rchild = NULL;

    if (key < r -> data) {
        r -> lchild = p;
    }
    else {
        r -> rchild = p;
    }
}

struct Node *RInsert(struct Node *p, int key) {
    struct Node *t = NULL;

    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t -> data = key;
        t -> lchild = t -> rchild = NULL;
        return t;
    }
    if (key < p -> data) {
        p -> lchild = RInsert(p -> lchild, key);
    }
    else if (key > p -> data) {
        p -> rchild = RInsert(p -> rchild, key);
    }
    return p;
}

// Delete from BST
int Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
 
Node* InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}
 
Node* InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}

Node* Delete(Node *p, int key) {
    Node* q;
 
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

// Create BST from preorder
void createFromPreorder(int *pre, int n) {
 
    // Create root node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;
 
    // Iterative steps
    Node* t;
    Node* p = root;
    stack<Node*> stk;
 
    while (i < n){
        // Left child case
        if (pre[i] < p->data){
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        } else {
            // Right child cases
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}
