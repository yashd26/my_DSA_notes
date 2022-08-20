// no. of binary trees from given nodes
catalan number T(n) = 2nCn/(n+1)

//no of trees with max height
n = 2^(n-1)

// min nodes nd height
min_nodes = h + 1
min_height =  log(n + 1) - 1 // height varies from 0(logn) to O(n)

//max nodes nd height
max_nodes = 2^(h + 1) - 1
max_height = n - 1

// if element at = i => Lchild = 2i & Rchild = 2i + 1

// create binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue {
    int front;
    int rear;
    int size;
    struct Node **Q;
};

struct Node *root = NULL;

void create() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    input(&x); //root->data
    root = (struct Node *)malloc(sizeof(struct Node));
    root -> data = x;
    root -> lchild = root -> rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q)) {
        p = dequeue(&q);
        input(&x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            enqueue(&q, t);      
        }
        p = dequeue(&q);
        input(&x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            enqueue(&q, t);      
        }
    }
}

// Preorder in tree
void preorder(struct Node *p) {
    if (p) {
        print(p -> data);
        preorder(p -> lchild);
        preorder(p -> rchild);
    }
}

// Inorder in tree
void inorder(struct Node *p) {
    if (p) {
        inorder(p -> lchild);
        print(p -> data);
        inorder(p -> rchild);
    }
}

// Postorder in tree
void postorder(struct Node *p) {
    if (p) {
        postorder(p -> lchild);
        postorder(p -> rchild);
        print(p -> data);
    }
}

// BFS tree taversal
void printBFS(TreeNode *r) {
    h = height(r);
    for(i = 0; i <= h) {
        print_given_lvl(r, h);
    }
}

void print_given_lvl(TreeNode *r, int lvl) {
    if (r == NULL) {
        return;
    }
    else if(lvl == 0) {
        print(r -> val);
    }
    else {
        print_given_lvl(r -> left, lvl - 1);
        print_given_lvl(r -> right, lvl - 1);
    }
}
