#include <queue>
#include "check.h"

using namespace std;


pair<int, vector<vector<int>>> numSolve(int intNum, vector<vector<int>> sud) {
    queue<pair<int, int>> block;
    for(int i = 0; i < 9; i++)  {
        for (int j = 0; j < 9; j++) {
            if (sud[i][j] == intNum) {
                block.push(make_pair(i,j));
            }
        }
    }
    while (!block.empty()) {
        int i = block.front().first;
        int j = block.front().second;
        int blockx = i - (i%3);
        int blocky = j - (j%3);
        for (int k = 0; k < 3; k++) {
            blocky = j - (j%3);
            for (int l = 0; l < 3; l++) {
                if(sud[blockx][blocky] == 0) {
                    sud[blockx][blocky] = -1;
                }
                blocky++;
            }
            blockx++;
        }
        for (int k = 0; k < 9; k++) {
            if (sud[i][k] == 0) {
                sud[i][k] = -1;
            }
            if (sud[k][j] == 0) {
                sud[k][j] = -1;
            }
        }
        block.pop();
    }
    pair<int,vector<vector<int>>> answ = check(intNum, sud);
    sud = answ.second;
    return (make_pair(answ.first,sud));
}