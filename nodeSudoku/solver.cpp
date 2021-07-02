#include <cstring>
#include <stack>
#include "./lib/numSolver.h"
#include "./lib/update.h"
#include "./test/test.h"

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


vector<vector<int>> treeSolver(vector<vector<int>>& sud, vector<vector<vector<int>>>& sudo) {
    class ho {
        public:
            int x;
            int y;
            int val;
            vector<vector<int>> sud;
            ho(int x,int y,int val) : x(x), y(y), val(val) {}
            void inputSud(vector<vector<int>>& p) {
                copy(p.begin(), p.end(), back_inserter(sud));
            }
    };

    stack<ho*> graph;
    vector<vector<int>> prev;
    copy(sud.begin(), sud.end(), back_inserter(prev));
    int x = -1;
    int y = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (prev[i][j] == 0) {
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
            ho* tem = new ho(x,y,i+1);
            tem->inputSud(prev);
            graph.push(tem);
            cout << ".";
        }
    }
    while (!graph.empty()) {
        ho* temp = graph.top();
        graph.pop();
        //cout << temp->x;
        vector<vector<int>> p;
        copy(temp->sud.begin(), temp->sud.end(), back_inserter(p));
        //cout << p.size();
        p[temp->x][temp->y] = temp->val;
        //cout << "|";
        if (!isValid(p)) {
            //cout << "-";
            continue;
        }
        x = -1;
        y = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (p[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1) {
                break;
            }
        }
        if (x == -1) {
            return p;
        }
        for (int i = 0; i < 9; i++) {
            if (sudo[i][x][y] == 0) {
                ho* tem = new ho(x,y,i+1);
                tem->inputSud(p);
                graph.push(tem);
            }
        }
    }
    cout << "method failed!";
    return sud;
}
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
/*
    struct noder {
        int x;
        int y;
        int val;
        queue<noder*> next;
        vector<vector<int>> sud;
        noder* previ;
        noder() {}
        noder(int x, int y, int val, queue<noder*>& next, vector<vector<int>>& sud, noder* previ) : x(x),y(y),val(val),next(next),sud(sud),previ(previ) {}
        noder(int x, int y, int val, queue<noder*>& next, vector<vector<int>>& sud) : x(x),y(y),val(val),next(next),sud(sud),previ(NULL) {}
    };

    queue<noder*> start, temp;
    vector<vector<int>> prev;
    copy(sud.begin(), sud.end(), back_inserter(prev));
    int x = -1;
    int y = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (prev[i][j] == 0) {
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
            queue<noder*> nxt;
            noder* tem = new noder(x,y,i+1,nxt,prev);
            start.push(tem);
            cout << x << " " << y << " " << i+1 << endl;
        }
    }
    noder* curr = NULL;
    while(1) {
        if ((curr == NULL && !(start.empty())) || (curr != NULL && !((curr->next).empty()))) {
            if (curr!=NULL) {
                //cout << " : " << curr->x << " " << curr->y << " " << curr->val << endl;
                noder* tt = (curr->next).front();
                (curr->next).pop();
                curr = tt;
                
            }
            else {
                curr = start.front();
                start.pop();
            }
        }
        else {
            if(curr->previ == NULL) {
                if (!start.empty()) {
                    //cout << " : " << curr->x << " " << curr->y << " " << curr->val << endl;
                    curr = NULL;
                    //cout << "|";
                    prev.clear();
                    copy(sud.begin(),sud.end(), back_inserter(prev));
                    continue;
                }
                cout << "no solution!" << endl;
                exit(-1);
            }
            //cout << "|";
            //cout << " : " << curr->x << " " << curr->y << " " << curr->val << endl;
            
            curr = curr->previ;
            cout << curr->next.size() << " ";
            prev.clear();
            copy(curr->sud.begin(),curr->sud.end(), back_inserter(prev));
            continue;
        }
        prev[curr->x][curr->y] = curr->val;
        if (!isValid(prev)) {
            cout << "-";
            continue;
        }
        //cout << ".";
        x = -1;
        y = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (prev[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1) {
                break;
            }
        }
        if (x == -1) {
            return prev;
        }
        for (int i = 0; i < 9; i++) {
            if (sudo[i][x][y] == 0) {
                queue<noder*> nxt;
                noder* tem = new noder(x,y,i+1,nxt,prev,curr);
                //cout << ".";
                //cout << x << " " << y << " " << i+1 << endl;
                (curr->next).push(tem);
            }
        }
        //cout << " : ";
    }

}
*/