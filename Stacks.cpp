// struct of stack
struct stack {
    int size;
    int Top;
    int *s;
}

// create stack
int main() {
    struct stack st;
    stack_size = input();
    st.s = new int[stack_size];
    st.Top = -1;
}
// if Top == -1 => stack empty && if Top = size - 1 => stack full

// push in stack
void push(stack *st, int x) {
    if (st -> Top == st -> size - 1) {
        print("stack overflow");
    }
    else {
        st -> Top++;
        st -> s[st -> Top] = x;
    }
}

// pop in stack
int pop(stack *st) {
    int x = -1;
    if (st -> Top == -1) {
        print("stack empty");
    }
    else {
        x = st -> s[st -> Top];
        st -> Top--;
    }
    return x;
}

// peek in stack
int peek(stack *st, int pos) {
    int x = -1;
    if (st -> Top - pos + 1 < 0) {
        print("invalid position");
    }
    else {
        x = st.s[st.Top - pos + 1];
    }
    return x;
}

// paranthesis problem
int isBalanced(char *exp) {
    // intialize stack st
    for(i = 0; exp[i] != '\0'; ++i) {
        if (exp[i] == '(') {
            push(&st, exp[i]);
        }
        else if(exp[i] == ')') {
            if (isEmpty(st)) {
                return false;
            }
            pop(&st);
        }
    }
    return isEmpty(st)?true:false;
}

// infix to postfix
int pre(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    else if(x == '*' || x == '-') {
        return 2;
    }
    return 0;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    else {
        return 1;
    }
}

char *convert(char *infix) {
    // Intialize struct stack st;
    char *postfix = new Node(strlen(infix) + 1);
    int i = 0, j = 0;
    while(infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        }
        else {
            if (pre(infix[i]) > pre(stackTop(st))) {
                push(&st, infix[i++]);
            }
            else {
                postfix[j++] = pop(st);
            }
        }
    }
    while(!isEmpty(st)) {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}
