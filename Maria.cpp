#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);

        // Display the array after each iteration
        cout << "Iteration Pass " << i + 1 << ": ";
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << " ";
        }
        cout << endl;
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

        // Display the array after each iteration
        cout << "Iteration Pass " << i << ": ";
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    char choice;
    do {
        cout << "\nM E N U" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        int option;
        cin >> option;

        if (option == 3) {
            cout << "Exiting program." << endl;
            break;
        } else if (option != 1 && option != 2) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        int size;
        cout << "Enter array size: ";
        cin >> size;

        vector<int> array(size);
        cout << "Input series of values: ";
        for (int i = 0; i < size; ++i)
            cin >> array[i];

        cout << "Iteration Pass:" << endl;
        if (option == 1)
            selectionSort(array);
        else if (option == 1)
            insertionSort(array);

        cout << "TRY AGAIN (Y/N)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

