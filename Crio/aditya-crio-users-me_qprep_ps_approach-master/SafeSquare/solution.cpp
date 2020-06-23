struct chess {
    vector<vector<char>> board;
    int rows,cols;
    vector<vector<int>> mark;

    chess(vector<vector<char> > brd) {
        rows = brd.size();
        cols = brd[0].size();

        for (int i = 0; i < rows; ++i) {
            vector<char> t1(brd[i]);
            vector<int> tmp(cols, 0);
            board.push_back(t1);
            mark.push_back(tmp);
        }
    }

    // TODO: CRIO_TASK_MODULE_SAFE_SQUARE
    // Input:
    //   1) chess board matrix
    // Task:
    //   1) Implement Rook move
    //   2) Implement Bishop move
    //   3) Implement Queens move
    //   4) Implement knight's move
    //   5) Special move
    // Output:
    //   Count the number of safe square and return it

    void markunsafeforRook(int row, int col) {
        mark[row][col] = 1;

        // verticle 
        for (int i = row-1; i >= 0; --i) {
            if (board[i][col] != '.') {
                break;
            }
            mark[i][col] = 1;
        }

        for (int i = row+1; i < rows; ++i) {
            if (board[i][col] != '.') {
                break;
            }
            mark[i][col] = 1;
        }

        // horizontal 
        for (int i = col-1; i >= 0; --i) {
            if (board[row][i] != '.') {
                break;
            }
            mark[row][i] = 1;
        }

        for (int i = col+1; i < cols; ++i) {
            if (board[row][i] != '.') {
                break;
            }
            mark[row][i] = 1;
        }
    }

    void markunsafeforBishop(int row, int col) {
        int i,j;
        mark[row][col] = 1;

        for (i=(row-1), j=(col-1); i>=0 && j>=0; --i, --j) {
            if (board[i][j] != '.') {
                break;
            }
            mark[i][j] = 1;
        }

        for (i=(row+1), j=(col-1); i<rows && j>=0; ++i, --j) {
            if (board[i][j] != '.') {
                break;
            }
            mark[i][j] = 1;
        }

        for (i=(row+1), j=(col+1); i<rows && j<cols; ++i, ++j) {
            if (board[i][j] != '.') {
                break;
            }
            mark[i][j] = 1;
        }

        for (i=(row-1), j=(col+1); i>=0 && j<cols; --i, ++j) {
            cout << i << " " << j << endl;
            if (board[i][j] != '.') {
                break;
            }
            mark[i][j] = 1;
        }
    }

    void markunsafeforQueen(int row, int col) {
        markunsafeforBishop(row, col);
        markunsafeforRook(row, col);
    }

    void markunsafeforKnight(int row, int col) {
        mark[row][col] = 1;

        if (row-2 >= 0) {
            if (col-1 >= 0) {
                mark[row-2][col-1] = 1;
            }

            if (col+1 < cols) {
                mark[row-2][col+1] = 1;
            }
        }

        if (row+2 < rows) {
            if (col-1 >= 0) {
                mark[row+2][col-1] = 1;
            }

            if (col+1 < cols) {
                mark[row+2][col+1] = 1;
            }
        }

        if (col-2 >= 0) {
            if (row-1 >= 0) {
                mark[row-1][col-2] = 1;
            }

            if (row+1 < rows) {
                mark[row+1][col-2] = 1;
            }
        }

        if (col+2 < cols) {
            if (row-1 >= 0) {
                mark[row-1][col+2] = 1;
            }

            if (row+1 < rows) {
                mark[row+1][col+2] = 1;
            }
        }
    }

    void markunsafeforSpecial(int row, int col) {
        int layer = min(row, col);
        layer = min(layer, min(rows-1-row, cols-1-col));
        int i;

        for (i = layer; i <= cols-1-layer; ++i) {
            mark[layer][i] = 1;
            mark[rows-1-layer][i] = 1;
        }

        for (i = layer; i <= rows-1-layer; ++i) {
            mark[i][layer] = 1;
            mark[i][cols-1-layer] = 1;
        }
    }

    int countsafe() {
        int safeboxes = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                if (mark[i][j] == 0) {
                    safeboxes++;
                }
            }
        }

        return safeboxes;
    }

    int move() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'R') {
                    markunsafeforRook(i,j);
                } else if (board[i][j] == 'B') {
                    markunsafeforBishop(i,j);
                } else if (board[i][j] == 'Q') {
                    markunsafeforQueen(i,j);
                } else if (board[i][j] == 'K') {
                    markunsafeforKnight(i,j);
                } else if (board[i][j] == 'S') {
                    markunsafeforSpecial(i,j);
                }
            }
        }

        return countsafe();
    }
