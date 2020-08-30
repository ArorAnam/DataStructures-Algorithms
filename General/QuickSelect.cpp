#include <climits>
#include <iostream>

using namespace std;

int partition(int arr[], int l, int r);

int kthsmallest(int arr[], int l, int r, int k) {
    // if k is smaller than number of elements
    if (k > 0 && k <= r - l + 1) {
        // partition the array around the last element
        // and get the pivot element in sorted array
        int pos = partition(arr, l, r);

        //if position is same as k
        if (pos == k)
            return arr[pos];
        else if(pos > k)
            return kthsmallest(arr, l, pos - 1, k);
        else
            return kthsmallest(arr, pos + 1, r, k - pos + 1);

        // if k is more than number of elements
        return INT_MAX;
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for(int j = l; j <= r-1; j++) {
        if(arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        swap(&arr[i], &arr[r]);
        return i;
    }
}

int main() {
    int arr[] = {23, 54, 2, 55, 1, 3, 65, 578, 24, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    cout << "K'th smallest = " << kthsmallest(arr, 0, n - 1, k) << '\n';
    return 0;
}
