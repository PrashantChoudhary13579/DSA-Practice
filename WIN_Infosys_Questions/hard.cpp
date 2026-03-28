/*

Hiker's Maximum Score

A hiker is traversing a rectangular terrain grid consisting of N rows and M columns.
The journey begins at the top-left cell (0, 0) and ends at the bottom-right cell (N-1, M-1).
From any given cell, the hiker is permitted to move only one step to the right or one step down.
The hiker's total score is determined by two factors:

- Scenic Value: Each cell (i, j) has a base scenic value V[i][j] which is collected immediately upon entering the cell (this includes the starting cell).
- Transition Bonus: Each cell also has a terrain type represented by a color code Color[i][j] (an integer from 1 to K). If the hiker moves into a cell that shares the same color as the cell they just left, they earn a transition bonus of B points. If the colors are different, no bonus is awarded.

Find the maximum possible total score the hiker can achieve by choosing an optimal path from start to destination.

Input Format
- First line: integers N, M, B
- Next N lines: M integers each representing Color[i][j]
- Next N lines: M integers each representing V[i][j]

*/


#include <bits/stdc++.h>
using namespace std;

long MaxScore(int N, int M, int B, vector<vector<int>> Color, vector<vector<int>> V) {
    vector<vector<long long>> cost(N, vector<long long>(M, 0));
    cost[0][0] = V[0][0];

    // Fill first column
    for (int i = 1; i < N; i++) {
        if (Color[i][0] == Color[i-1][0])
            cost[i][0] = cost[i-1][0] + B + V[i][0];
        else
            cost[i][0] = cost[i-1][0] + V[i][0];
    }

    // Fill first row
    for (int j = 1; j < M; j++) {
        if (Color[0][j] == Color[0][j-1])
            cost[0][j] = cost[0][j-1] + B + V[0][j];
        else
            cost[0][j] = cost[0][j-1] + V[0][j];
    }

    // Fill rest
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            long long up = 0;
            long long left = 0;

            if (Color[i][j] == Color[i-1][j]) {
                up = cost[i-1][j] + B + V[i][j];
            } else {
                up = cost[i-1][j] + V[i][j];
            }

            if (Color[i][j] == Color[i][j-1]) {
                left = cost[i][j-1] + B + V[i][j];
            } else {
                left = cost[i][j-1] + V[i][j];
            }

            cost[i][j] = max(up, left);
        }
    }

    return cost[N-1][M-1];
}

int main() {
    int N, M, B;
    cout<<"Enter the size of the grid (N x M): "<<endl;
    cin >> N >> M ;
    cout<<"Enter the Bonus value (B): "<<endl;
    cin >> B;

    cout<<"Enter the Color matrix: "<<endl;
    vector<vector<int>> Color(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Color[i][j];

    cout<<"Enter the Value matrix: "<<endl;
    vector<vector<int>> V(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> V[i][j];

    cout<<"Max score: " << MaxScore(N, M, B, Color, V) << endl;

    return 0;
}