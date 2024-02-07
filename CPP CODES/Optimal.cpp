#include <iostream>
using namespace std;

int main() {
    int numFrames, numPages, frameArray[10], pageArray[30], faults = 0;

    cout << "Enter number of frames: ";
    cin >> numFrames;

    cout << "Enter number of pages: ";
    cin >> numPages;

    cout << "Enter page reference string: ";
    for (int i = 0; i < numPages; ++i) {
        cin >> pageArray[i];
    }

    for (int i = 0; i < numFrames; ++i) {
        frameArray[i] = -1;
    }

    for (int i = 0; i < numPages; ++i) {
        bool pageFound = false;

        for (int j = 0; j < numFrames; ++j) {
            if (frameArray[j] == pageArray[i]) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            int farthest = -1, farthestIndex = -1;

            for (int j = 0; j < numFrames; ++j) {
                int k;
                for (k = i + 1; k < numPages; ++k) {
                    if (frameArray[j] == pageArray[k]) {
                        if (k > farthest) {
                            farthest = k;
                            farthestIndex = j;
                        }
                        break;
                    }
                }
                if (k == numPages) {
                    farthestIndex = j;
                    break;
                }
            }

            frameArray[farthestIndex] = pageArray[i];
            faults++;
        }

        cout << "\n";

      
    }

    cout << "\n\nTotal Page Faults = " << faults;
    cout << "\n\nTotal Page Hits = " << numPages - faults;

    return 0;
}
