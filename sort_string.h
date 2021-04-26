//swap
void SWAP_STRING(char *a,char *b);

//quickSort
int partition_string(char **text, int left, int right);
void quickSort_string(char **text, int left, int right);

//mergeSort
void merge_string(char **text, int head, int mid, int tail);
void mergeSort_string(char **text, int head, int tail);

//heapSort
void heapify_string(char **text, int n, int i);
void heapSort_string(char **text, int n);

