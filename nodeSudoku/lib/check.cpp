#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> update_solver(vector<vector<int>> sud, int x, int y) {
    int blockx = x - (x%3);
    int blocky = y - (y%3);
    for (int i = blockx; i < blockx+3; i++) {
        for (int j = blocky; j < blocky+3; j++) {
            if (sud[i][j] == 0) {
                sud[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (sud[x][i] == 0) {
            sud[x][i] = -1;
        }
        if (sud[i][y] == 0) {
            sud[i][y] = -1;
        }
    }
    return sud;
}


pair<int,vector<vector<int>>> check(int intNum, vector<vector<int>> sud) {
    int last = 0, lc = 0;
    int kast = 0, kc = 0;
    int change = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sud[i][j] == 0) {
                lc++;
                last = j;
            }
            else if (sud[i][j] == intNum) {
                lc = 2;
                break;
            }
        }
        if (lc == 1) {
            sud[i][last] = intNum;
            sud = update_solver(sud, i, last);
            change++;
        }
       
        lc = 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sud[j][i] == 0) {
                kc++;
                kast = j;
            }
            else if (sud[j][i] == intNum) {
                kc = 2;
                break;
            }
        }
        if (kc == 1) {
            sud[kast][i] = intNum;
            sud = update_solver(sud, kast, i);
            change++;
        }
        kc = 0;
    }
    int blockx;
    int blocky;
    lc = 0;
    last = 0;
    kast = 0;
    for (blockx = 0; blockx < 9; blockx+=3) {
        for (blocky = 0; blocky < 9; blocky+=3) {
            for(int i = blockx; i < blockx+3; i++) {
                for (int j = blocky; j < blocky+3; j++) {
                    if (sud[i][j] == 0){
                        lc++;
                        last = i;
                        kast = j;
                    }
                    else if (sud[i][j] == intNum) {
                        lc = 2;
                        break;
                    }
                }
                if (lc == 2) {
                    break;
                }
            }
            if (lc == 1) {
                sud[last][kast] = intNum;
                sud = update_solver(sud, last, kast);
                change++;
            }
            lc = 0;
        }
    }
    return (make_pair(change,sud));
}