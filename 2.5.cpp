#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

bool compareStrings(const string& str1, const string& str2) {
    return str1 < str2;
}

bool compareNumbers(const int& num1, const int& num2) {
    return num1 < num2;
}

void bubbleSort(string arr[], int n, bool (*compare)(const string&, const string&)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort(int arr[], int n, bool (*compare)(const int&, const int&)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(string arr[], int n, bool (*compare)(const string&, const string&)) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void selectionSort(int arr[], int n, bool (*compare)(const int&, const int&)) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    srand(time(0));

    string word;
    word += 'A' + rand() % 26;
    word += 'A' + rand() % 26;
    word += 'A' + rand() % 26;

    int number = rand() % 1000;

    cout << "Randomly generated word: " << word << endl;
    cout << "Randomly generated number: " << number << endl;

    string wordArr[] = {word};
    int numberArr[] = {number};

    clock_t startTime = clock();
    bubbleSort(wordArr, 1, compareStrings);
    clock_t endTime = clock();
    double timeTakenByBubbleSortForWord = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort for word: " << fixed << setprecision(10) << timeTakenByBubbleSortForWord << " seconds" << endl;

    startTime = clock();
    bubbleSort(numberArr, 1, compareNumbers);
    endTime = clock();
    double timeTakenByBubbleSortForNumber = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort for number: " << fixed << setprecision(10) << timeTakenByBubbleSortForNumber << " seconds" << endl;

    startTime = clock();
    selectionSort(wordArr, 1, compareStrings);
    endTime = clock();
    double timeTakenBySelectionSortForWord = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken by Selection Sort for word: " << fixed << setprecision(10) << timeTakenBySelectionSortForWord << " seconds" << endl;

    startTime = clock();
    selectionSort(numberArr, 1, compareNumbers);
    endTime = clock();
    double timeTakenBySelectionSortForNumber = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken by Selection Sort for number: " << fixed << setprecision(10) << timeTakenBySelectionSortForNumber << " seconds" << endl;

    return 0;
}
