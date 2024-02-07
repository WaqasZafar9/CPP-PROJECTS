
#include <iostream>
using namespace std;

const int MAX = 100;

int find2DPeak(int arr[][MAX], int rowStart, int rowEnd, int col, int n) {
    int midRow = (rowStart + rowEnd) / 2;

   
    int maxRowIndex = 0;
    int maxVal = arr[0][col];

    for (int i = 1; i < n; i++) {
        if (arr[i][col] > maxVal) {
            maxVal = arr[i][col];
            maxRowIndex = i;
        }
    }

   
    if ((col == 0 || arr[maxRowIndex][col] >= arr[maxRowIndex][col - 1]) &&
        (col == n - 1 || arr[maxRowIndex][col] >= arr[maxRowIndex][col + 1])) {
        return arr[maxRowIndex][col];
    }

    
    if (col > 0 && arr[maxRowIndex][col - 1] > arr[maxRowIndex][col]) {
        return find2DPeak(arr, rowStart, rowEnd, col - 1, n);
    } else {
        return find2DPeak(arr, rowStart, rowEnd, col + 1, n);
    }
}

int main() {
    int n, m; 
    n = 4; 
    m = 4; 

    int arr[MAX][MAX] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };

    int peak = find2DPeak(arr, 0, n - 1, m / 2, m);

    if (peak != -1) {
        cout << "A peak element in the 2D array is: " << peak << endl;
    } else {
        cout << "No peak element found in the 2D array." << endl;
    }

    return 0;
}
