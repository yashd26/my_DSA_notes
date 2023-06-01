// Bubble Sort
void Bubble(int A[], int n) {
  int i, j, flag = 0;
  for (i = 0; i < n - 1; i++) {
    flag = 0;
    for (j = 0; j < n - i - 1; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0) break;
  }
}

//  Insertion Sort
void Insertion(int A[], int n) {
  int i, j, x;
  for (i = 1; i < n; i++) {
    j = i - 1;
    x = A[i];
    while (j > -1 && A[j] > x) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = x;
  }
}

// Selection Sort
void SelectionSort(int A[], int n) {
  int i, j, k;
  for (i = 0; i < n - 1; i++) {
    for (j = k = i; j < n; j++) {
      if (A[j] < A[k]) {
        k = j;
      }
    }
    swap(A[i], A[k]);
  }
}

// QuickSort
int partition(int A[], int l, int h) {
  int pivot = A[l];
  int i = l, j = h;
  While(i < j) {
    While(A[i] <= A[pivot] && i <= h - 1) {
      i++;
    }
    While(A[j] > A[pivot] && j >= l + 1) {
      j--;
    }
    if (i < j) {
      Swap(A[i], A[j]);
    }
  }


  














  swap(A[l], A[j]);
  return j;
}

void QuickSort(int A[], int l, int h) {
  int j;
  if (l < h) {
    j = partition(A, l, h);
    QuickSort(A, l, j);
    QuickSort(A, j + 1, h);
  }
}

// MergeSort
void Merge(int A[], int l, int mid, int h) {
  int i = l, j = mid + 1, k = l;
  int B[100];
  while (i <= mid && j <= h) {
    if (A[i] < A[j]) {
        B[k++] = A[i++];
    }
    else {
        B[k++] = A[j++];
    }
  }
  for (; i <= mid; i++) {
    B[k++] = A[i];
  }
  for (; j <= h; j++) {
    B[k++] = A[j];
  }
  for (i = l; i <= h; i++) {
    A[i] = B[i];
  }
}

void MergeSort(int A[], int l, int h) {
  int mid;
  if (l < h) {
    mid = (l + h) / 2;
    MergeSort(A, l, mid);
    MergeSort(A, mid + 1, h);
    Merge(A, l, mid, h);
  }
}
