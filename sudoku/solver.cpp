#include <iostream>
#include <vector>
#include <utility>
#include "./lib/numSolver.h"
#include "./lib/update.h"

using namespace std;

vector<vector<vector<int>>> start_set(vector<vector<int>>& sud) {
    vector<vector<vector<int>>> sudo;
    for (int i = 0; i < 9; i++) {
        vector<vector<int>> temp;
        copy(sud.begin(), sud.end(), back_inserter(temp));
        sudo.push_back(temp);
    }
    return sudo;
}

pair<vector<vector<int>>, vector<vector<vector<int>>>> straight_solver(vector<vector<int>>& sud, vector<vector<vector<int>>>& sudo) {
    int changes = 0;
    pair<int, vector<vector<int>>> tc;
    int l = 0;
    while (1) {
        for (int i = 0; i < 9; i++) {
            tc = numSolve(i+1, sudo[i]);
            sudo[i] = tc.second;
            if (tc.first > 0) {
                sud = update_sud(sud, sudo[i]);
                sudo = update_set(sud, sudo);
            }
            changes += tc.first;
        }
        if (changes == 0) {
            break;
        }
        cout << "iteration : " << l+1 << " : changes : " << changes << endl;
        changes = 0;
        l++;
    }
    return (make_pair(sud,sudo));
}


pair<vector<vector<int>>, vector<vector<vector<int>>>> treeSolver(vector<vector<int>>& sud, vector<vector<vector<int>>>& sudo) {
    ///under construction!!
    /*
               -
              - -
             -   -
            -  |  -
           -   .   -
          - - - - - -
            WARNING
        The following piece
        of code is incomplete.
    */
    struct node {
        int x;
        int y;
        int val;
        vector<node> next;
        node(int x, int y, int val, vector<node>& next) : x(x),y(y),val(val),next(next) {}
    };

    vector<node> start;
    int x = -1;
    int y = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sud[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) {
            break;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (sudo[i][x][y] == 0) {
            vector<node> nxt;
            node tem(x,y,i+1,nxt);
            start.push_back(tem);
        }
    }


}