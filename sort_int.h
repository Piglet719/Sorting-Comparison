//swap
void SWAP_INT(int *x, int *y);

//quickSort
int partition_int(int *number, int left, int right);
void quickSort_int(int *number, int left, int right);

//mergeSort
void merge_int(int *number, int head, int mid, int tail);
void mergeSort_int(int *number, int head, int tail);

//heapSort
void heapify_int(int *number, int n, int i);
void heapSort_int(int *number, int n);

//radixSort
int get_max_int(int *number, int n);
void radixSort_int(int *number, int n);
