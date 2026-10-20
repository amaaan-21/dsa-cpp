/*
Consider the procedure below. Its argument A is an array of integers, A.size holds the length n of
that array, and you may assume n ≥ 2. A return exits the procedure immediately.
0. def scan(A) // indices start at 0
1. A[0] = 1
2. n = A.size
3. for i in range(1, n):
4. for j in range(i - 1):
5. A[j] = A[j] + 1
6. if A[i] != A[i-1]:
7. return
8. return
Write T(n) for the worst-case running time of scan(A), taken over all integer arrays A of length
n. Charge one unit of time to each assignment, each comparison and each arithmetic operation.
(a) Is T(n) = O(n
2
)? Prove your answer.
Solution.
[ replace this line with your solution ]
(b) Is T(n) = Ω(n
2
)? Prove your answer.
Solution.
[ replace this line with your solution ]
 */

 #include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

void scan(vector<int>& A) {
    A[0] = 1;
    int n = A.size();

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i - 1; j++) {
            A[j] = A[j] + 1;
        }

        if (A[i] != A[i - 1]) {
            return;
        }
    }

    return;
}

void printArray(const vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {

    // n = 9
    vector<int> A = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    cout << "Before scan: ";
    printArray(A);

    scan(A);
jkjk
    cout << "After scan:  ";
    printArray(A);

    return 0;
}