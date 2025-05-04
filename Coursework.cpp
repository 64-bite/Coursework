#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 5

int WhiteRows = {1, 4, 2, 4, 3};
int WhiteCals = {1, 2, 2, 0, 1};
int BlackCals = {0, 0, 0, 0, 0};
int BlackRows = {0, 0, 0, 0, 2};
vector<int> board[5][5];

bool isSafe(int x, int y) {
	if(y = 1) {
		int w = 0, b = 0;
		
		if(board[x - 1][y] = 0) {
			return true;
		} else {
			for(int i = x - 1; i >= 0; i--) {
				do { 
					b++;
				} while(board[i][y] = 0);
			}
			if(b = BlackCals[0] && BlackCals[0] = 0) { 
				return false;
			} else { 
				return true;
			}
		}
	}
	if(y > 0) {
		switch x:
			case 1:
				if(board[x - 5][y - 1] = 1 || board[x - 4][y - 1] = 1) { 
					return false;
				} else { 
					return true;
				}
			case 5: 
				if(board[x - 5][y - 1] = 1 || board[x - 6][y - 1] = 1) { 
					return false;
				} else { 
					return true;
				}
			default:		
				if(board[x - 5][y-1] = 1 || board[x - 4][y-1] = 1 || board[x - 6][y-1] = 1) { 
					return false;
				} else {
					return true;
				}
	}
	return false;
}
	bool checkRowsAndCols(){
		
	bool solve(int x,int y);
		board[1][1] = 1;
		
    void printBoard(const vector<vector<int>>& r, const vector<vector<int>>& bs) {
        for (int i = 0; i < RAWS; i++) {
            for (int j = 0; j < CALS; j++) {
                cout << bs[i][j] << " ";
            }
            cout << '\n';
        }
        if (r == bs) {
            cout << "Puzzle solved!" << endl;
        } else {
            cout << "Not solved yet." << endl;
        }
    }

int main() {
    
    return 0;
}