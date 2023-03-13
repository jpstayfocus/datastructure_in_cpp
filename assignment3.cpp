// sorting algorithms and time complexity

// Insertion sort reverse sorted



#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main() {
    int N = 100;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }

    auto start = chrono::steady_clock::now();
    vector<int> sortedArr = insertionSort(arr);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl << "Time taken: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}

// Insertion Sort Presorted

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main() {
    int N = 100;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    auto start = chrono::steady_clock::now();
    vector<int> sortedArr = insertionSort(arr);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl << "Time taken: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}

*/

// Insertion Sort Many duplucates

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}


int main() {
    int N = 100000;
    vector<int> arr(N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
    }

    auto start = chrono::high_resolution_clock::now();
    arr = insertionSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000.0 << " ms" << endl;

    return 0;
}


// Insertion Sort few duplucates

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

vector<int> insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main() {
    int N = 100;

    vector<int> arr(N);
    srand(time(0)); 
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }

    auto start = chrono::steady_clock::now();
    vector<int> sortedArr = insertionSort(arr);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl << "Time taken: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}

// Insertion sort all zeros

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N, 0);

    auto start = chrono::high_resolution_clock::now();
    arr = insertionSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}


// Shell Sort reverse sorted

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> shellSort(vector<int> arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return arr;
}

int main() {
    int N = 1000000;
    vector<int> arr(N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }

    auto start = chrono::high_resolution_clock::now();
    arr = shellSort(arr);
    auto end = chrono::high_resolution_clock::now();

    // cout << "Sorted array: ";
    // for (int i = 0; i < N; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " sec" << endl;

    return 0;
}

// shell sort presorted

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> shellSort(vector<int> arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    auto start = chrono::high_resolution_clock::now();
    arr = shellSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}

// shell sort many duplicates

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> shellSort(vector<int> arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
    }

    auto start = chrono::high_resolution_clock::now();
    arr = shellSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}

// shell sort few duplicates

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> shellSort(vector<int> arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }

    auto start = chrono::high_resolution_clock::now();
    arr = shellSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}


// shell sort all zeros

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> shellSort(vector<int> arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N, 0);

    auto start = chrono::high_resolution_clock::now();
    arr = shellSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}

// mergesort reverse sorted

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }

    mergeSort(arr, 0, N - 1);

    return arr;
}

int main()
{
    int N = 1000000; 
    auto start = high_resolution_clock::now();

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start);

    // cout << "Sorted array:\n";
    // for (int i = 0; i < N; i++) {
    //     cout << sortedArr[i] << " ";
    // }

    cout<<"\nTime taken by the algorithm: " << duration.count() /1000000.0 << " sec\n";

    return 0;
}

// merge sort presorted 

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    mergeSort(arr, 0, N - 1);

    return arr;
}

int main()
{
    int N = 1000000; 
    auto start = high_resolution_clock::now();

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start);

    // cout << "Sorted array:\n";
    // for (int i = 0; i < N; i++) {
    //     cout << sortedArr[i] << " ";
    // }

    cout<<"\nTime taken by the algorithm: " <<duration.count() /1000000.0 << " sec \n";

    return 0;
}


// merge sorted many duplicates 

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
    }

    mergeSort(arr, 0, N - 1);

    return arr;
}

int main()
{
    int N = 1000000; 
    auto start = high_resolution_clock::now(); 

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start); 

    // cout << "Sorted array:\n";
    // for (int i = 0; i < N; i++) {
    //     cout << sortedArr[i] << " ";
    // }

    cout<<"\nTime taken by the algorithm: " << duration.count() /1000000.0 << " sec\n";

    return 0;
}


// mergesort few duplicates

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);
	srand(time(null));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }

    mergeSort(arr, 0, N - 1);

    return arr;
}

int main()
{
    int N = 1000000; 
    auto start = high_resolution_clock::now(); 

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start); 

    // cout << "Sorted array:\n";
    // for (int i = 0; i < N; i++) {
    //     cout << sortedArr[i] << " ";
    // }

    // Print the time taken by the algorithm
    cout<<"\nTime taken by the algorithm: " << duration.count() /1000000.0 << " sec\n";

    return 0;
}

// merge sort all zeros

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    return result;
}

vector<int> mergeSort(vector<int> arr) {
    int n = arr.size();
    if (n == 1) {
        return arr;
    }
    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main() {
    int N = 100000;
    vector<int> arr(N, 0);

    auto start = chrono::high_resolution_clock::now();
    arr = mergeSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}

// Quicksort reverse sorted

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
    	arr[i] = N - i;
	}

    auto start = chrono::high_resolution_clock::now();
    arr = quickSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}

// quicksort presorted

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
    	arr[i] = i + 1;
	}

    auto start = chrono::high_resolution_clock::now();
    arr = quickSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}


// quicksort many duplicates

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    int N = 100;
    vector<int> arr(N);
    srand(time(NULL));
    for(int i = 0; i < N; i++){
    	arr[i] = rand()%10;
	}

    auto start = chrono::high_resolution_clock::now();
    arr = quickSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " sec" << endl;

    return 0;
}

// quicksort few duplicates

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    int N = 1000;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
    	arr[i] = rand() % N;
	}

    auto start = chrono::high_resolution_clock::now();
    arr = quickSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " ms" << endl;

    return 0;
}


// quick sort all zeros 

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    int N = 100000;
    vector<int> arr(N, 0);

    auto start = chrono::high_resolution_clock::now();
    arr = quickSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " seconds" << endl;

    return 0;
}


// radix sort reverse sorted

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    vector<int> output(arr.size());

    while (maxVal / exp > 0) {
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

int main() {
    int N = 1000000;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }

    // measure time taken by radix sort algorithm
    auto start = chrono::high_resolution_clock::now();
    radixSort(arr);
    auto end = chrono::high_resolution_clock::now();

    // print sorted array and time taken by algorithm
    // cout << "Sorted array: ";
    // for (int i = 0; i < N; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " sec" << endl;

    return 0;
}


// radix sort pre sorted

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    vector<int> output(arr.size());

    while (maxVal / exp > 0) {
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

int main() {
    int N = 100;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    auto start = chrono::high_resolution_clock::now();
    radixSort(arr);
    auto end = chrono::high_resolution_clock::now();

    // cout << "Sorted array: ";
    // for (int i = 0; i < N; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000.0 << " sec" << endl;

    return 0;
}


// radix sort many duplicates 

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    vector<int> output(arr.size());

    while (maxVal / exp > 0) {
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

int main() {
    int N = 1000;
    vector<int> arr(N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
    }

    auto start = chrono::high_resolution_clock::now();
    radixSort(arr);
    auto end = chrono::high_resolution_clock::now();

//    cout << "Sorted array: ";
//    for (int i = 0; i < N; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000.0 << " ms" << endl;

    return 0;
}

// radix sort few duplicates

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    vector<int> output(arr.size());

    while (maxVal / exp > 0) {
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

int main() {
    int N = 1000000;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }

    auto start = chrono::high_resolution_clock::now();
    radixSort(arr);
    auto end = chrono::high_resolution_clock::now();

    // cout << "Sorted array: ";
    // for (int i = 0; i < N; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000000.0 << " sec" << endl;

    return 0;
}


// radix sort all zeros
\#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    vector<int> output(arr.size());

    while (maxVal / exp > 0) {
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}

int main() {
    int N = 1000;
    vector<int> arr(N, 0);

    auto start = chrono::high_resolution_clock::now();
    radixSort(arr);
    auto end = chrono::high_resolution_clock::now();

//    cout << "Sorted array: ";
//    for (int i = 0; i < N; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by algorithm: " << duration.count() / 1000.0 << " ms" << endl;

    return 0;
}


// std::sort reversed sorted

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }

    std::sort(arr.begin(), arr.end());

    return arr;
}

int main()
{
    int N = 10000; 
    auto start = high_resolution_clock::now(); 

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start); 

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout<<endl;

    cout << "Time taken by the algorithm: "<<duration.count()/1000000.0 << " sec";

    return 0;
}


// std::sort presorted

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    std::sort(arr.begin(), arr.end());

    return arr;
}

int main()
{
    int N = 10000; 
    auto start = high_resolution_clock::now(); 

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start); 

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout<<endl;

    cout << "Time taken by the algorithm: "<<duration.count()/1000000.0 << " sec";

    return 0;
}


// std:: sort many duplicates

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
    }

    std::sort(arr.begin(), arr.end());

    return arr;
}

int main()
{
    int N = 10000; 
    auto start = high_resolution_clock::now(); 

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start); 

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout<<endl;

    cout << "Time taken by the algorithm: "<<duration.count()/1000000.0 << " sec";

    return 0;
}


// std::sort few duplicates

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }

    std::sort(arr.begin(), arr.end());

    return arr;
}

int main()
{
    int N = 10000; 
    auto start = high_resolution_clock::now(); 

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start); 

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout<<endl;

    cout << "Time taken by the algorithm: "<<duration.count()/1000000.0 << " sec";

    return 0;
}


// std::sort all zeros

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> createAndSortArray(int N)
{
    vector<int> arr(N, 0);

    std::sort(arr.begin(), arr.end());

    return arr;
}

int main()
{
    int N = 10000; 
    auto start = high_resolution_clock::now(); 

    vector<int> sortedArr = createAndSortArray(N);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<chrono::microseconds>(stop - start); 

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++) {
        cout << sortedArr[i] << " ";
    }
    cout<<endl;

    cout << "Time taken by the algorithm: "<<duration.count()/1000000.0 << " sec";

    return 0;
}




