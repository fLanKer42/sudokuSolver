#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> update_sud(vector<vector<int>>& sud, vector<vector<int>>& part) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (part[i][j] != -1) {
                sud[i][j] = part[i][j];
            }
        }
    }
    return sud;
}

vector<vector<vector<int>>> update_set(vector<vector<int>>& sud, vector<vector<vector<int>>>& sudo) {
    for (int k = 0; k < 9; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sud[i][j] != 0) {
                    sudo[k][i][j] = sud[i][j];
                }
            }
        }
    }
    return sudo;
}