// Changing case of a string
int main() {
    char A[] = "welComE";
    for(int i = 0; A[i] != '\0', ++i) {
        if (A[i] >= 65 && A[i] <= 90) {
            A[i] += 32;
        }
        else if(A[i] >= 'a' && A[i] <= 122) {
            A[i] -= 32;
        }
    }
}

// Finding duplicates in a string
int main() {
    char A[] = "finding";
    int H[26], i;

    for(int i = 0; A[i] != '\0'; ++i) {
        H[A[i] - 97] += 1;
    }
    for(i = 0; i < 26; ++i) {
        if (H[i] > 1) {
            printf("%c", i + 97);
            printf("%d", H[i]);
        }
    }
}

// Finding duplicates of a string using bitwise
int main() {
    char A[] = "finding";
    long int H = 0, x = 0;

    for(i = 0; A[i] != "\0"; ++i) {
        x = 1;
        x = x << A[i] - 97;
        if (x & H > 0) {
            printf("%c is Duplicate", A[i]);
        }
        else {
            H = x | H;
        }
    }
}

//Check if strings are Anagram
int main() {
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26] = {0};

    for(i = 0; A[i] != "\0"; ++i) {
        H[A[i] - 97] += 1;
    }
    for(i = 0; B[i] != "\0"; ++i) {
        H[A[i] - 97] -= 1;
        if (H[A[i] - 97] < 0) {
            printf("not anagram");
            break;
        }
    }
    if (B[i] == "\0") {
        printf("anagram");
    }
}

//permutation of string
void perm(char S[], int l, int h) {
    int i;
    if (l == h) {
        printf(S);
    }
    else {
        for(i = l; i <= h; ++i) {
            swap(s[l], s[i]);
            perm(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}
