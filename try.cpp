#include <iostream>

using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
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
        }

        int size;
        cout << "Enter array size: ";
        cin >> size;

        int *array = new int[size];

        cout << "Input series of values: ";
        for (int i = 0; i < size; ++i)
            cin >> array[i];

        cout << "Iteration Pass:" << endl;
        if (option == 1)
            selectionSort(array, size);
        else if (option == 2)
            insertionSort(array, size);

        for (int i = 0; i < size; ++i)
            cout << array[i] << " ";
        cout << endl;

        delete[] array;

        cout << "TRY AGAIN (Y/N)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

