struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// create linked list
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// traverse through linked list
void display(struct node *p)
{
    while (p != NULL)
    {
        print(p->data)
            p = p->next;
    }
}

// traverse in reverse order
void display(struct node *p)
{
    if (p != NULL)
    {
        display(p->next);
        print(p->data);
    }
}

// insert in linked list
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(structNode));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; ++i)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// delete from linked list
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > count(p))
    {
        return -1;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

// reverse a linked list
void Reverse(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// merging two linked lists
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last->next = q;
    }
}

// create circular ll
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; ++i)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// display circular ll
void display(Node *p)
{
    do
    {
        print(p->data);
        p = p->next;
    } while (p != Head / first);
}

// insert in circular ll
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
    {
        return;
    }
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

// delete from circular ll
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 0 || index > Length(Head))
    {
        return -1;
    }
    if (index == 1)
    {
        while (p->next != Head)
        {
            p = p->next;
        }
        x = Head->data;
        if (Head == p)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

// create doubly ll
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; ++i)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// insert in doubly ll
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > Length(p))
    {
        return;
    }
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index; ++i)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Noded));
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

// delete for doubly ll
int delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;

    if (index < 1 || index > Length(p))
    {
        return -1;
    }
    if (index = 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < index; ++i)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
}

// reverse doubly ll
p = first;
while (p)
{
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;
    if (p->next == NULL)
    {
        first = p;
    }
}

// MergeSort in LinkedList
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *ptr = new ListNode(0);
    ListNode *curr = ptr;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if (l1 != NULL)
    {
        curr->next = l1;
        l1 = l1->next;
    }

    if (l2 != NULL)
    {
        curr->next = l2;
        l2 = l2->next;
    }

    return ptr->next;
}

ListNode *MergeList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    return merge(l1, l2);
}
