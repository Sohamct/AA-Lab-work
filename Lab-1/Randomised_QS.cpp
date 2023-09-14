#include <iostream>

using namespace std;
int comparisions, swaps;
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high){
    int pivort = arr[high];
    int i = low - 1;
    comparisions += high - low;
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivort){
            i++;
            swap(arr, i, j);
            swaps++;
        }
    }
    swap(arr, i + 1, high);swaps++;
    return i + 1;
}

int random_Partition(int arr[], int low, int high){
    int randInd = low + (rand() % (high - low + 1));
    //swapping
    swap(arr, randInd, high);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int q = random_Partition(arr, low, high);
        quickSort(arr, low, q-1);
        quickSort(arr, q + 1, high);
    }
}

int main()
{
    srand(time(0));
    int n = 1000;
    int arr[n];
    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }
    // Average case time complexity while Array is sorted in ascending/descending order => O(n(log(n))).
    // worst case(without random_Partition) : Comparisions: O(n2) = 500,000
    // Average case: (with random_Partition) : Comparisions: O(nlog(n)) = 9960
    quickSort(arr, 0, n-1);
    cout << "Comparisions: " << comparisions << " Swaps: " << swaps;
    return 0;
}
