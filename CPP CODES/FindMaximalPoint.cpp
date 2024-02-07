//mwaqas zafar
//38605

#include <iostream>

struct Point {
    int x, y;
};

using namespace std;

void findMaximalPoints(Point points[], int n) {
    for (int i = 0; i < n; ++i) {
        bool maximal = true;

        for (int j = 0; j < n; ++j) {
            if (i != j && points[i].x <= points[j].x && points[i].y <= points[j].y) {
                maximal = false;
                break;
            }
        }

        if (maximal) {
            cout << "(" << points[i].x << "," << points[i].y << ") ";
        }
    }
}

int main() {
    const int n = 12;
    Point points[] = { {2, 5}, {9, 10}, {13, 3}, {15, 7}, {14, 10},
                       {12, 12}, {7, 13}, {11, 5}, {4, 11}, {7, 7},
                       {5, 1}, {4, 4} };

    findMaximalPoints(points, n);

    return 0;
}
