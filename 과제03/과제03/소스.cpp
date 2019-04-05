#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double selectionSort(int A[], int n);
int findMAX(int A[], int n);
void swap(int A[], int a, int b);
double bubbleSort(int A[], int n);
double InsertionSort(int A[], int n);
void merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);
void quickSort(int A[], int left, int right);
int partition(int A[], int left, int right);
void quickSort_Mid(int A[], int left, int right);
void quickSort_Random(int A[], int left, int right);
void reset_re(int n);
void reset_ran(int n);
void print();
void heap_sort(int A[], int n);
void build_maxHeap(int A[], int n);
void max_heapify(int A[], int n, int i);
int compare(const void *a, const void *b);
typedef struct DATAI {
	double Random[3];
	double Reverse[3];
}type;
type category[9];
char data_index[7][100] = { "\t","Random1000","Reverse1000","Random10000","Reverse10000","Random100000","Reverse100000" };
char Category[9][100] = { "Bubble","Selection","Insertion","Merge","Quick1","Quick2","Quick3" ,"Heap","Library" };
clock_t end, start;
#define DATALENGTH 100000
int data[100000];
int tmp[DATALENGTH];
int main() {
	srand(time(NULL));
	print();

	int N = 1000;
	printf("%10s      ", Category[0]);
	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); category[0].Reverse[i] = bubbleSort(data, N);
		for (int j = 0; j < 10; j++) {
			reset_ran(N); sum += bubbleSort(data, N);
		}
		category[0].Random[i] = (sum / 10.0); N *= 10;
		printf("%10lf    %10lf    ", category[0].Random[i], category[0].Reverse[i]);
	}N = 1000; printf("\n%10s      ", Category[1]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); category[1].Reverse[i] = selectionSort(data, N);
		for (int j = 0; j < 10; j++) {
			reset_ran(N); sum += selectionSort(data, N);
		}category[1].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[1].Random[i], category[1].Reverse[i]);
	}N = 1000; printf("\n%10s      ", Category[2]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); category[2].Reverse[i] = InsertionSort(data, N);
		for (int j = 0; j < 10; j++) {
			reset_ran(N); sum += InsertionSort(data, N);
		}category[2].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[2].Random[i], category[2].Reverse[i]);
	}N = 1000; printf("\n%10s      ", Category[3]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); start = clock(); mergeSort(data, 0, N - 1); end = clock();
		category[3].Reverse[i] = (double)(end - start) / CLK_TCK;
		for (int j = 0; j < 10; j++) {
			reset_ran(N);  start = clock(); mergeSort(data, 0, N - 1); end = clock();
			sum += (double)(end - start) / CLK_TCK;
		}
		category[3].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[3].Random[i], category[3].Reverse[i]);
	}N = 1000; printf("\n%10s      ", Category[4]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); start = clock(); quickSort(data, 0, N - 1); end = clock();
		category[4].Reverse[i] = (double)(end - start) / CLK_TCK;
		for (int j = 0; j < 10; j++) {
			reset_ran(N);  start = clock(); quickSort(data, 0, N - 1); end = clock();
			sum += (double)(end - start) / CLK_TCK;
		}category[4].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[4].Random[i], category[4].Reverse[i]);
	} N = 1000; printf("\n%10s      ", Category[5]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); start = clock(); quickSort_Mid(data, 0, N - 1); end = clock();
		category[5].Reverse[i] = (double)(end - start) / CLK_TCK;
		for (int j = 0; j < 10; j++) {
			reset_ran(N);  start = clock(); quickSort_Mid(data, 0, N - 1); end = clock();
			sum += (double)(end - start) / CLK_TCK;
		}category[5].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[5].Random[i], category[5].Reverse[i]);
	} N = 1000; printf("\n%10s      ", Category[6]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); start = clock(); quickSort_Random(data, 0, N - 1); end = clock();
		category[6].Reverse[i] = (double)(end - start) / CLK_TCK;
		for (int j = 0; j < 10; j++) {
			reset_ran(N);  start = clock(); quickSort_Random(data, 0, N - 1); end = clock();
			sum += (double)(end - start) / CLK_TCK;
		}category[6].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[6].Random[i], category[6].Reverse[i]);
	} N = 1000; printf("\n%10s      ", Category[7]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); start = clock(); heap_sort(data, N); end = clock();
		category[7].Reverse[i] = (double)(end - start) / CLK_TCK;
		for (int j = 0; j < 10; j++) {
			reset_ran(N);  start = clock(); heap_sort(data, N); end = clock();
			sum += (double)(end - start) / CLK_TCK;
		}category[7].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[7].Random[i], category[7].Reverse[i]);
	} N = 1000; printf("\n%10s      ", Category[8]);

	for (int i = 0; i < 3; i++) {
		double sum = 0;
		reset_re(N); start = clock(); qsort(data, N, sizeof(int), compare); end = clock();
		category[8].Reverse[i] = (double)(end - start) / CLK_TCK;
		for (int j = 0; j < 10; j++) {
			reset_ran(N);  start = clock(); qsort(data, N, sizeof(int), compare); end = clock();
			sum += (double)(end - start) / CLK_TCK;
		}category[8].Random[i] = sum / 10.0; N *= 10;
		printf("%10lf    %10lf    ", category[8].Random[i], category[8].Reverse[i]);
	}
	return 0;
}
void print() {
	printf(" -------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 7; i++) {
		printf(" %10s ", data_index[i]);
	} printf("\n"); printf(" -------------------------------------------------------------------------------------------------\n");

}

double selectionSort(int A[], int n) {
	start = clock();
	for (int last = n - 1; last >= 1; last--) {
		int max = findMAX(A, last);
		swap(A, last, max);
	}
	end = clock();
	return (double)(end - start) / CLK_TCK;
}
int findMAX(int A[], int n) {
	int max_index = n;
	for (int i = n - 1; i >= 0; i--) {
		if (A[max_index] < A[i]) {
			max_index = i;
		}
	}
	return max_index;
}
void swap(int A[], int a, int b) {

	int tmp = A[a];
	A[a] = A[b]; A[b] = tmp;
}
double bubbleSort(int A[], int n) {
	start = clock();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (A[i] > A[j])
				swap(A, i, j);
		}
	}
	end = clock();
	return (double)(end - start) / CLK_TCK;
}
double InsertionSort(int A[], int n) {
	int tmp; int j;
	start = clock();
	for (int i = 1; i < n; i++) {
		tmp = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > tmp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
	}
	end = clock();
	return (double)(end - start) / CLK_TCK;
}
void mergeSort(int A[], int p, int r) {

	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
void merge(int A[], int p, int q, int r) {
	int i = p, j = q + 1, k = p;

	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			tmp[k++] = A[i++];
		else
			tmp[k++] = A[j++];
	}
	while (i <= q)
		tmp[k++] = A[i++];
	while (j <= r)
		tmp[k++] = A[j++];
	for (int i = p; i <= r; i++)
		A[i] = tmp[i];
}
int partition(int A[], int left, int right) {
	int pivot = A[right];
	int pindex = left;
	for (int i = left; i < right; i++) {
		if (A[i] <= pivot) {
			swap(A, i, pindex); pindex++;
		}
	}swap(A, pindex, right);
	return pindex;
}

void quickSort(int A[], int left, int right) {
	while (left < right) {
		if (right - left < 10) {
			InsertionSort(A, right + 1); break;
		}
		else {
			int pivot = partition(A, left, right);
			if (pivot - left < right - pivot) {
				quickSort(A, left, pivot - 1); left = pivot + 1;
			}
			else {
				quickSort(A, pivot + 1, right); right = pivot - 1;
			}
		}
	}
}
void quickSort_Mid(int A[], int left, int right) {
	int i = left, j = right;
	int pivot = A[(left + right) / 2];
	while (i <= j)
	{
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(A, i, j);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort_Mid(A, left, j);

	if (i < right)
		quickSort_Mid(A, i, right);
}
void quickSort_Random(int A[], int left, int right) {
	int x, p;
	if (left < right) {
		x = rand() % (right + 1);
		swap(A, x, right);
		p = partition(A, left, right);
		quickSort(A, left, p - 1);
		quickSort(A, p + 1, right);
	}
}

void reset_re(int n) {
	for (int i = 0; i < n; i++) {
		data[i] = n - i;
	}
}
void reset_ran(int n) {
	for (int i = 0; i < n; i++) {
		data[i] = (rand() % n) + 1;
	}
}

void max_heapify(int A[], int n, int i) {
	int left = i * 2;
	int right = (i * 2) + 1;
	int largest = i;

	if (left<n&&A[left]>A[largest]) {
		largest = left;
	}
	if (right<n&&A[right]>A[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(A, largest, i);
		max_heapify(A, n, largest);
	}
}

void heap_sort(int A[], int n) {
	build_maxHeap(A, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(A, i, 0);
		max_heapify(A, i, 0);
	}
}

void build_maxHeap(int A[], int n) {
	for (int i = n / 2; i >= 0; i--) {
		max_heapify(A, n, i);
	}
}

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}