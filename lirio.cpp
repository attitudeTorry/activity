#include <iostream>
#include <cstdlib>
#include <ctime>

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

    
    srand(time(NULL));
  
    cout << "Input series of values: ";
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 50 + 10; 
        cout << array[i] << " ";
    }
    cout << endl;

  
    selectionSort(array, size);

    
    cout << "Iteration Pass:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    
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

