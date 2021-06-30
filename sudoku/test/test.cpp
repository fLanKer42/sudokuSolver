#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& sud) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sud[i][j] != 0) {
                for (int k = 0; k < 9; k++) {
                    if (k != i) {
                        if (sud[k][j] == sud[i][j]) {
                            cout << k << "," << j << " : " << i << "," << j << endl;
                            return false;
                        }
                    }
                    if (k != j) {
                        if (sud[i][k] == sud[i][j]) {
                            cout << i << "," << k << " : " << i << "," << j << endl;
                            return false;
                        }
                    }
                }
                for (int l = i - (i%3); l < (i/3)+3; l++) {
                    for (int h = j - (j%3); h < (j/3)+3; h++) {
                        if (l != i || h != j) {
                            if (sud[l][h] == sud[i][j]) {
                                cout << l << "," << h << " : " << i << "," << j << endl;
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool isComplete(vector<vector<int>>& sud) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sud[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}