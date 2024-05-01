#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<int> > generateMagicSquare(int n) {
std::vector<std::vector<int> > magicSquare(n, std::vector<int>(n, 0));


std::cout <<"Orsal, Ma. Ann Corrine R." << std::endl;
std::cout <<"BS CPE - 2B" << std::endl;


    int row = 0, col = n / 2, num = 1;
    while (num <= n * n) {
        magicSquare[row][col] = num;

        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (magicSquare[nextRow][nextCol] != 0) {
            row = (row + 1) % n;
        } else {
            row = nextRow;
            col = nextCol;
        }

        num++;
    }

    return magicSquare;
}

void printMagicSquare(const std::vector<std::vector<int> >& magicSquare) {
    for (int i = 0; i < magicSquare.size(); ++i) {
        for (int j = 0; j < magicSquare[i].size(); ++j) {
            std::cout << std::setw(4) << magicSquare[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter an odd number (n): ";
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "Error: n must be odd" << std::endl;
        return 1;
    }

    std::vector<std::vector<int> > magicSquare = generateMagicSquare(n);

    std::cout << "Magic Square for n = " << n << ":" << std::endl;
    printMagicSquare(magicSquare);
    
    std::cout << "The common sum is:" << n * (n * n + 1) / 2 << std::endl;

    return 0;
}


