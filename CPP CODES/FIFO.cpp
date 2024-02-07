#include<iostream>

using namespace std;

int main() {
    int index1 = 0, index2 = 0, index3 = 0, index4 = 0, length, numFrames, referenceString[30], flag = 1, frames[30], hits = 0, misses = 0;

    cout << "FIFO page replacement algorithm....\n";
    cout << "Enter the number of frames: ";
    cin >> numFrames;

    if (numFrames <= 0) {
        cout << "Invalid number of frames. Exiting program.\n";
        return 1;
    }

    cout << "Enter the length of the reference string: ";
    cin >> length;

    if (length <= 0 || length > 30) {
        cout << "Invalid length of the reference string. Exiting program.\n";
        return 1;
    }

    cout << "Enter the reference string (each number separated by space): ";

    for (index1 = 0; index1 < length; index1++) {
        cin >> referenceString[index1];

        if (referenceString[index1] < 0) {
            cout << "Invalid input. Exiting program.\n";
            return 1;
        }
    }

    for (index2 = 0; index2 < numFrames; index2++)
        frames[index2] = 0;

    for (index1 = 0; index1 < length; index1++) {
        flag = 1;

        for (index2 = 0; index2 < numFrames; index2++) {
            if (frames[index2] == referenceString[index1]) {
                cout << "Data already in page....\n";
                flag = 0;
                hits++;
                break;
            }
        }

        if (flag == 1) {
            frames[index3] = referenceString[index1];
            index3++;
            index4++;

            if (index3 == numFrames)
                index3 = 0;

            for (index2 = 0; index2 < numFrames; index2++) {
                cout << "\nPage " << index2 + 1 << ": " << frames[index2];
                if (frames[index2] == referenceString[index1])
                    cout << "*";
            }

            cout << "\nMiss\n\n";
            misses++;
        }
    }

    cout << "\nHits: " << hits << "\nMisses: " << misses << endl;

    return 0;
}
