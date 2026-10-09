
#include <iostream>
using namespace std;

// Simulated picked number
int pickedNumber = 6;

// Guess API
// Returns:
// -1 if guess is greater than picked number
//  1 if guess is less than picked number
//  0 if guess equals picked number

int guess(int num) {
    if (num > pickedNumber) {
        return -1;
    }
    else if (num < pickedNumber) {
        return 1;
    }
    else {
        return 0;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int result = guess(mid);

            if (result == 0) {
                return mid;
            }
            else if (result == -1) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    int n;

    cout << "Enter the upper limit n: ";
    cin >> n;

    Solution obj;
    int result = obj.guessNumber(n);

    cout << "Picked number: " << result << endl;

    return 0;
}
