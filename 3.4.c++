#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;
using namespace std::chrono;

// الگوریتم‌های مرتب‌سازی برای اعداد

void bubbleSortInt(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void selectionSortInt(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSortInt(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void mergeInt(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortInt(vector<int>& arr, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSortInt(arr, l, m);
    mergeSortInt(arr, m + 1, r);
    mergeInt(arr, l, m, r);
}

int partitionInt(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortInt(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionInt(arr, low, high);
        quickSortInt(arr, low, pi - 1);
        quickSortInt(arr, pi + 1, high);
    }
}

void heapifyInt(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyInt(arr, n, largest);
    }
}

void heapSortInt(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyInt(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapifyInt(arr, i, 0);
    }
}

void countingSortInt(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int i, count[10] = {0};
    for (i = 0; i < n; ++i)
        ++count[(arr[i] / exp) % 10];
    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSortInt(vector<int>& arr) {
    int m = *max_element(arr.begin(), arr.end());
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSortInt(arr, exp);
}

void shellSortInt(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


// الگوریتم‌های مرتب‌سازی برای رشته‌ها

void bubbleSortStr(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void selectionSortStr(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSortStr(vector<string>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void mergeStr(vector<string>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortStr(vector<string>& arr, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSortStr(arr, l, m);
    mergeSortStr(arr, m + 1, r);
    mergeStr(arr, l, m, r);
}

int partitionStr(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortStr(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionStr(arr, low, high);
        quickSortStr(arr, low, pi - 1);
        quickSortStr(arr, pi + 1, high);
    }
}

void heapifyStr(vector<string>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyStr(arr, n, largest);
    }
}

void heapSortStr(vector<string>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyStr(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapifyStr(arr, i, 0);
    }
}

void countingSortStr(vector<string>& arr, int exp) {
    int n = arr.size();
    vector<string> output(n);
    int i, count[256] = {0};
    for (i = 0; i < n; ++i)
        ++count[static_cast<unsigned char>(arr[i][exp])];
    for (i = 1; i < 256; ++i)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; --i) {
        output[count[static_cast<unsigned char>(arr[i][exp])] - 1] = arr[i];
        --count[static_cast<unsigned char>(arr[i][exp])];
    }
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSortStr(vector<string>& arr, int maxLen) {
    for (int exp = maxLen - 1; exp >= 0; --exp)
        countingSortStr(arr, exp);
}

void shellSortStr(vector<string>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            string temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


// تابع برای اندازه‌گیری زمان اجرا

template<typename Func, typename T>
double measureTime(Func sortFunc, vector<T>& arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed = end - start;
    return elapsed.count();
}

// تابع اصلی

int main() {
    srand(time(0));
    vector<int> numbers = {686, 12345, 7894561};
    vector<string> words = {"app", "apple", "iphonee"};
    vector<void(*)(vector<int>&)> sortAlgorithmsInt = {bubbleSortInt, selectionSortInt, insertionSortInt, mergeSortInt, quickSortInt, heapSortInt, radixSortInt, shellSortInt};
    vector<void(*)(vector<string>&)> sortAlgorithmsStr = {bubbleSortStr, selectionSortStr, insertionSortStr, mergeSortStr, quickSortStr, heapSortStr, radixSortStr, shellSortStr};
    vector<string> algorithmNames = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort", "Radix Sort", "Shell Sort"};

    // تست برای اعداد

    cout << "Testing on numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    for (size_t i = 0; i < sortAlgorithmsInt.size(); ++i) {
        vector<int> arr = numbers; // کپی از آرایه اصلی
        double timeTaken = measureTime(sortAlgorithmsInt[i], arr);
        cout << algorithmNames[i] << ": " << timeTaken << " ms" << endl;
    }
    cout << "------------------------" << endl;

    // تست برای رشته‌ها
    
    cout << "Testing on words: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    for (size_t i = 0; i < sortAlgorithmsStr.size(); ++i) {
        vector<string> arr = words; // کپی از آرایه اصلی
        double timeTaken = measureTime(sortAlgorithmsStr[i], arr);
        cout << algorithmNames[i] << ": " << timeTaken << " ms" << endl;
    }
    cout << "------------------------" << endl;

    return 0;
}
