#include <iostream>
#include <vector>
/*
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
#19

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 9 2 -4 -4 0
0 0 0 -2 0 0
0 0 -1 -2 -4 0
#13
 */
using namespace std;

int maxHourGlass(vector<vector<int>> matrix);
int largest(int matrix[][4]);
int glassTotal(vector<vector<int>> matrix, int p, int q, int r, int d);

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << maxHourGlass(arr);
    return 0;
}

int maxHourGlass(vector<vector<int>> glasses) {
    int sums[4][4] = {0};

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                sums[i][j] = glassTotal(glasses, i, j,j + 3,i + 3);
            }
        }

    return largest(sums);

}

int glassTotal(vector<vector<int>> matrix, int p, int q, int r, int d) {
    int value = 0;
    int a = 0;
    for (int i = p; i < d; i++) {
        if (a == 1) {
            value += matrix[p+1][q+1];
            a = 0;
            continue;
        }
        for (int j = q; j < r; j++) {
            value += matrix[i][j];
        }
        a++;
    }
    return value;
}

int largest(int matrix[][4]) {
    int maxGlass = matrix[0][0];
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++)
            if (maxGlass < matrix[row][col])
                maxGlass = matrix[row][col];
    }
    return maxGlass;
}