#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void selectionSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void printArray(const vector<int>& arr);

int main() {
    char choice;
    do {
        cout << "\n=== M E N U ===" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "\n=== Selection Sort ===" << endl;
                break;
            case 2:
                cout << "\n=== Insertion Sort ===" << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        int size;
        cout << "Enter array size: ";
        cin >> size;

        vector<int> array(size);
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; ++i)
            cin >> array[i];

        cout << "\nIteration Pass:" << endl;
        if (option == 1)
            selectionSort(array);
        else if (option == 2)
            insertionSort(array);

        cout << "\nTRY AGAIN (Y/N)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
        printArray(arr);
    }
}


void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        printArray(arr);
    }
}

void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

