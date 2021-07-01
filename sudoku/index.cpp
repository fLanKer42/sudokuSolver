#include <string>
#include "solver.h"

using namespace std;

int main() {
    vector<vector<int>> sud;
    string inputLine;
    ifstream inputFile("./inputText/sudoku.txt");
    int j = 0;
    while (getline(inputFile, inputLine)) {
        vector<int> line;
        for (j = 0; j < inputLine.length(); j+=2) {
            if (inputLine[j] == '_') {
                line.push_back(0);
            }
            else {
                line.push_back((int)inputLine[j] - '0');
            }
        }
        sud.push_back(line);
    }
    inputFile.close();
    vector<vector<vector<int>>> sudo = start_set(sud);
    pair<vector<vector<int>>, vector<vector<vector<int>>>> ans = straight_solver(sud, sudo);
    sud = ans.first;
    sudo = ans.second;
    int p = 0;
    ans = straight_solver(sud, sudo);
    sud = ans.first;
    sudo = ans.second;    
    while(p < 3) {
        if (isValid(sud)) {
            cout << "The solution is valid!" << endl;
            if (isComplete(sud)) {
                cout << "The solution is complete!" << endl;
                break;
            }
            else {
                p++;
                cout << "The solution is incomplete!" << endl;
                printFile(sud,sudo);
                cout << "Commencing Tree Construction Constructions" << endl;
                sud = treeSolver(sud,sudo);
                cout << "Done :)!" << endl;
                ans = straight_solver(sud, sudo);
                sud = ans.first;
                sudo = ans.second;
            }
        }
        else {
            cout << "The solution is flawed!" << endl;
            break;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sud[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
