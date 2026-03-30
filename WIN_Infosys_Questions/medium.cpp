/*
Mosaic Tile Optimization

An artist is creating a mosaic on a wall of dimensions N rows × M columns.
Each cell in this grid must be covered by exactly one ceramic tile. The artist has two types of tiles available:
- Type A: A 1×1 tile that covers a single cell. It costs costA to place.
- Type B: A 1×2 tile that covers two horizontally adjacent cells. It costs costB to place.

Additionally, certain cells are marked as "accent" cells. If an accent cell at position (i, j) is covered by a Type A tile, the artist earns a beauty bonus of V[i][j]. If an accent cell is covered by part of a Type B tile, no bonus is earned.

It is given that net cost is defined as:
Net Cost = (Total cost of all tiles used) − (Total beauty bonuses earned)
Find the minimum net cost to tile the entire wall.

Input Format

First line: integer N
Second line: integer M
Third line: integer costA
Fourth line: integer costB
Next N lines: M integers each representing V[i][j] (0 if not an accent cell, else the bonus value)

Output
Print the minimum net cost.

*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

long MinCost(int N, int M, int costA, int costB, vector<vector<int>> V) {
    long total = 0;

    for (int i = 0; i < N; i++) {
        vector<long> dp(M + 1, INT_MAX);
        dp[0] = 0;

        for (int j = 0; j < M; j++) {
            if (dp[j] == INT_MAX) continue;

            long bonus = V[i][j];
            dp[j + 1] = min(dp[j + 1], dp[j] + costA - bonus);

            if (j + 1 < M) {
                dp[j + 2] = min(dp[j + 2], dp[j] + costB);
            }
        }

        total += dp[M];
    }

    return total;
}

int main() {
    int N, M, costA, costB;
    cout<<"Enter the size N and M: "<<endl;
    cin >> N >> M ;
    cout<<"Enter the cost of A and B "<<endl;
    cin >> costA >> costB;

    cout<<"Enter the value in the matrix: "<<endl;
    vector<vector<int>> V(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> V[i][j];

    cout<<"Minimum Cost: " << MinCost(N, M, costA, costB, V) << endl;

    return 0;
}