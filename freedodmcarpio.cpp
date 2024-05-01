#include <iostream>

using namespace std;


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);

        
        cout << "Iteration Pass " << i + 1 << ": ";
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "M E N U" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cout << "Enter Choice: ";
    cin >> choice;

    if (choice == 3) {
        cout << "Exiting program." << endl;
        return 0;
    }

    cout << "Selection Sort" << endl;
    cout << "Enter array size: ";
    cin >> size;

 
    int* array = new int[size];

    
    cout << "Enter " << size << " values separated by spaces: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    
    selectionSort(array, size);

    delete[] array;

    char tryAgain;
    cout << "TRY AGAIN (Y/N)? ";
    cin >> tryAgain;
    if (tryAgain == 'Y' || tryAgain == 'y') {
        main();
    } else {
        cout << "Exiting program." << endl;
    }

    return 0;
}

