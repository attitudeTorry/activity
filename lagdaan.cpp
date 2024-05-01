#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> 

using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
        cout << "Iteration Pass: ";
        printArray(arr);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        cout << "Iteration Pass: ";
        printArray(arr);
    }
}

int main() {
    srand(time(0));
    char choice;
    do {
        cout << "M E N U\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;
        if (choice == '1') {
            int size;
            cout << "Enter array size : ";
            cin >> size;
            vector<int> arr(size);
            cout << "Input series of values : ";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            selectionSort(arr);
        } else if (choice == '2') {
            int size;
            cout << "Enter array size : ";
            cin >> size;
            vector<int> arr(size);
            cout << "Input series of values : ";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            insertionSort(arr);
        }
        cout << "TRY AGAIN (Y/N)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    return 0;
}

