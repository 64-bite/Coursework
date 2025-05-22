#include <iostream>
using namespace std;
const int B = 9;
/* int rboard[SIZE][SIZE] = {
	{1,0,0,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0},
	{1,0,0,0,1,0,0,1,0},
	{0,0,1,0,1,0,0,0,0},
	{0,0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,1,0},
	{1,0,0,0,0,0,0,0,0},
	{1,0,1,1,1,0,1,0,0}
}; */
class Coursework {
public:
int board[B][B] = {{1,1,0,0,0,1,0,0,1},
				   {0,0,0,0,0,0,0,0,0},
				   {0,0,0,1,1,1,0,0,0},
				   {0,0,0,0,1,1,0,0,0}};
int WhiteRows[B] = {4, 0, 3, 7, 4, 0, 8, 3, 8};
int BlackRows[B] = {3, 0, 4, 0, 2, 0, 0, 0, 0};
int WhiteCols[B] = {3, 8, 3, 4, 6, 6, 4, 8, 2};
int BlackCols[B] = {2, 0, 0, 0, 0, 0, 0, 0, 3};
int ships[10] = {4,3,3,2,2,2,1,1,1,1};
public:
bool black = false, white = false;

void uniqueOperations(bool block = false) {
	for(int i = 0; i < B; i++) {
		for(int j = 0; j < B; j++) {
			if(block) {
				if(WhiteRows[i] == 0 && BlackRows[i] == 0) {
					board[j][i] = 2;
				} else if(WhiteRows[i] == 8) {
					for(int k = 1; k < 8; k++){
						board[k][i] = 2;
				}
				} else if(WhiteRows[i] == 7) { 
					for(int k = 2; k < 7; k++){
						board[k][i] = 2;
					}
				} else if(WhiteRows[i] == 6) {
					for(int k = 3; k < 5; k++) {
					board[k][i] = 2;
					}
				}
				if(WhiteCols[i] == 0 && BlackCols[i] == 0) {
					board[i][j] = 2;
				} else if(WhiteCols[i] == 8) {
					for(int k = 1; k < 8; k++){
						board[i][k] = 2;
					}
				} else if(WhiteCols[i] == 7) { 
					for(int k = 2; k < 7; k++){
						board[i][k] = 2;
					}
				} else if(WhiteCols[i] == 6) {
					for(int k = 3; k < 5; k++) {
						board[i][k] = 2;
					}
				}
			} else {
				if(board[j][k] == 2){
					board[j][k] = 0;
				}
			}
		}
	}
}

	
bool canPlace(int c, int r, int ship, bool horizontal) {
	if(horizontal) { 
		if(r + ship > B) { 
			return false;
		}
		for(int i = 0; i < ship; i++) {
			int x = r + i;
			int y = c;
			if(board[y][x] != 0) {
				return false;
			}
			for(int dx = -1; dx <= 1; dx++) {
				for(int dy = -1; dy <= 1; dy++) {
					int nx = x + dx;
					int ny = y + dy;
					if(nx >= 0 && nx < B && ny >= 0 && ny < B) {
						if(board[ny][nx] == 1) {
							return false;
						}
					}
				}
			}
		}					
	} else {
		if(c + ship > B) { 
			return false;
		}
		for(int i = 0; i < ship; ++i) {
			int x = r;
			int y = c + i;
			if(board[y][x] != 0) {
				return false;
			}
			for(int dx = -1; dx <= 1; ++dx) {
				for(int dy = -1; dy <= 1; ++dy) {
					int nx = x + dx;
					int ny = y + dy;
					if(nx >= 0 && nx < B && ny >= 0 && ny < B) {
						if(board[ny][nx] == 1) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}	
void putship(int c, int r,int ship, bool horizontal) {
	for(int i = 0; i < ship; i++) {
		if(horizontal) {
			board[c][r + i] = 1;
		} else {
			board[c + i][r] = 1;
		}
	}
}
void deleteship(int c, int r,int ship, bool horizontal) {
	for(int i = 0; i < ship; i++) {
		if(horizontal) {
			board[c][r + i] = 0;
		} else {
			board[c + i][r] = 0;
		}
	}
}
int longest(bool horizontal, int index, bool occupied) {
	int count = 0, value, r = 0;
	for(int i = 0; i < B; i++) {
		if(horizontal) {
			value = board[index][i];
			if(occupied) {
				if(value == 1) {
					count++;
				} else { 
					count = 0;
				}
				if(r < count) {
					r = count;
				}
			} else {
				if(value == 0) {
					count++;
				} else { 
					count = 0;
				}
				if(r < count) {
					r = count;
				}
			}
		} else {
			value = board[i][index];
			if(occupied) {
				if(value == 1) {
					count++;
				} else { 
					count = 0;
				}
				if(r < count) {
					r = count;
				}
			} else {
				if(value == 0) {
					count++;
				} else { 
					count = 0;
				}
				if(r < count) {
					r = count;
				}
			}
		}	
	}
	return r;
}
bool rows[B], cols[B];
bool check_rows() {
	for(int i = 0; i < B; i++) {
		if(longest(true,i,false) == 9 && WhiteCols[i] == 0 && BlackCols[i] == 0) {
			rows[i] = true;
		} else if(WhiteCols[i] == 0 && longest(true,i,true) == BlackCols[i]) {
			rows[i] = true;
		} else if(BlackCols[i] == 0 && longest(true,i,false) == WhiteCols[i] ) {
			rows[i] = true;
		} else if(BlackCols[i] != 0 && WhiteCols[i] != 0 && longest(true,i,false) == WhiteCols[i] && longest(true,i,true) == BlackCols[i]){
			rows[i] = true;
		} else { 
			rows[i] = false;
		}
		if(longest(false,i,false) == 9 && WhiteRows[i] == 0 && BlackRows[i] == 0) {
			cols[i] = true;
		} else if(WhiteRows[i] == 0 && longest(false,i,true) == BlackRows[i]) {
			cols[i] = true;
		} else if(BlackRows[i] == 0 && longest(false,i,false) == WhiteRows[i] ) {
			cols[i] = true;
		} else if(BlackRows[i] != 0 && WhiteRows[i] != 0 && longest(false,i,false) == WhiteRows[i] && longest(false,i,true) == BlackRows[i]){
			cols[i] = true;
		} else { 
			cols[i] = false;
		}
	}
	return true;
}
bool check_cols() { 
	for(int i = 0; i < B; i++) {
int count = 0;
bool solve(int shipIndex) { 
   if (shipIndex == 9) {
		do{
			return checkRC();
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j < 9; j++) {
					cout << board[i][j] << ' ';
				}
				cout << '\n';
			}
			count++;
		} while(count != 25);
    }
	if(shipIndex == 0) {
		uniqueOperations(true);
	}
    int len = ships[shipIndex];
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < B; ++j) {
            if (canPlace(i, j, len, true)) {
                putship(i, j, len, true);
                if (solve(shipIndex + 1)) {
					return true;
				}
                deleteship(i, j, len, true);
            }

            if (canPlace(i, j, len, false)) {
                putship(i, j, len, false);
                if (solve(shipIndex + 1)) {
					return true;
				}
                deleteship(i, j, len, false);
            }
        }
    }
    return false;
}
};
int main() {
	Coursework c;
	c.solve(0);
	cout << "   ";
	for(int k = 0; k < 9; k++) {
		cout << c.WhiteRows[k] << ' ';
	}
	cout << '\n';
	for(int i = 0; i < 9; i++) {
		cout << c.WhiteCols[i] << "| ";
		for(int j = 0; j < 9; j++) {
			cout << c.board[i][j] << ' ';
		}
		cout << '|' <<  c.BlackCols[i] << '\n';
	}
	cout << "   ";
	for(int k = 0; k < 9; k++) {
		cout << c.BlackRows[k] << ' ';
	}
    return 0;
}
