#include <iostream>

using namespace std;

int sdoku[9][9];

bool checkCol() {
    for (int j = 0; j < 9; j++) {
        bool nums[9];

        for (int i = 0; i < 9; i++) {
            nums[sdoku[i][j] - 1] = true;
        }

        for (int i = 0; i < 9; i++) {
            if (!nums[i])
                return false;
        }
    }
    return true;
}

bool checkRow() {
    for (int i = 0; i < 9; i++) {
        bool nums[9];

        for (int j = 0; j < 9; j++) {
            nums[sdoku[i][j] - 1] = true;
        }

        for (int i = 0; i < 9; i++) {
            if (!nums[i])
                return false;
        }
    }
    return true;
}

bool checkBox() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            bool nums[9];
            nums[sdoku[i * 3][j * 3] - 1] = true;
            nums[sdoku[i * 3][j * 3 + 1] - 1] = true;
            nums[sdoku[i * 3][j * 3 + 2] - 1] = true;
            nums[sdoku[i * 3 + 1][j * 3] - 1] = true;
            nums[sdoku[i * 3 + 1][j * 3 + 1] - 1] = true;
            nums[sdoku[i * 3 + 1][j * 3 + 2] - 1] = true;
            nums[sdoku[i * 3 + 2][j * 3] - 1] = true;
            nums[sdoku[i * 3 + 2][j * 3 + 1] - 1] = true;
            nums[sdoku[i * 3 + 2][j * 3 + 2] - 1] = true;
            for (int k = 0; k < 9; k++) {
                if (!nums[i])
                    return false;
            }
        }
    }

    return true;
}

int main(void) {
    int T, answer;

    cin >> T;

    for (int t_case = 0; t_case < T; t_case++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> sdoku[i][j];
            }
        }

        if (checkBox() & checkCol() & checkRow())
            answer = 1;
        else
            answer = 0;

        cout << "#" << t_case + 1 << " " << answer << "\n";
    }

    return 0;
}