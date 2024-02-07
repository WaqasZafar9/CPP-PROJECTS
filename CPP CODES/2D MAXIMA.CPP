
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

bool comparePoints(const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

void findMaximalPoints(Point points[], int n) {
    sort(points, points + n, comparePoints);
    stack<Point> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && (s.top().x <= points[i].x && s.top().y <= points[i].y)) {
            s.pop();
        }

        s.push(points[i]);
    }

    while (!s.empty()) {
        cout << "(" << s.top().x << "," << s.top().y << ") ";
        s.pop();
    }
}

int main() {
    const int n = 12;
    Point points[] = { {2, 5}, {9, 10}, {13, 3}, {13, 6}, {15, 11},
                       {12, 12}, {7, 13}, {14, 10}, {4, 11}, {7, 7},
                       {5, 1}, {4, 4} };

    findMaximalPoints(points, n);

    return 0;
}
