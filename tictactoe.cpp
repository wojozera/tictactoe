#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int MAXSIZE = 35;

struct Game {
    int N, M, K;
    char active;
};

int howmanyempty(Game* GAME, char** arr) {
    int counter = 0;
    for (int i = 0; i < GAME->N; i++) {
        for (int j = 0; j < GAME->M; j++) {
            if (arr[i][j] == '0') counter++;
        }
    }
    return counter;
}

bool emptycell(Game* GAME, char** arr) {
    for (int i = 0; i < GAME->N; i++) {
        for (int j = 0; j < GAME->M; j++) {
            if (arr[i][j] == '0') return true;
        }
    }
    return false;
}

int min(int a, int b) {
    if (a >= b) return b;
    else return a;
}

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int staticevaluation(Game* GAME, char** arr) {

    int togetherD = 1;
    int togetherI = 1;
    int togetherC = 1;
    int togetherR = 1;
    int togetherD2 = 1;
    int togetherI2 = 1;
    int togetherC2 = 1;
    int togetherR2 = 1;

    for (int i = 0; i < GAME->N; i++) {          // rows
        for (int j = 0; j <= (GAME->M - GAME->K); j++) {
            for (int k = j; k < GAME->K + j; k++) {
                if (arr[i][k] == '1') togetherR *= 10;
                else if (arr[i][k] == '2') togetherR2 *= 10;
            }
        }
    }

    for (int j = 0; j < GAME->M; j++) {          // columns
        for (int i = 0; i <= (GAME->N - GAME->K); i++) {
            for (int k = i; k < GAME->K + i; k++) {
                if (arr[k][j] == '1') togetherC *= 10;
                else if (arr[k][j] == '2') togetherC2 *= 10;
            }
        }
    }

    for (int k = 0; k <= GAME->M - GAME->K; k++) {
        for (int i = 0; i <= (GAME->N - GAME->K); i++) {
            for (int j = 0; j < GAME->K; j++) {
                if (arr[j + i][j + k] == '1') togetherD *= 10;
                else if (arr[j + i][j + k] == '2') togetherD2 *= 10;
            }
        }
    }

    for (int k = 0; k <= GAME->M - GAME->K; k++) {
        for (int i = 0; i <= (GAME->N - GAME->K); i++) {
            for (int j = 0; j < GAME->K; j++) {
                if (arr[GAME->N - 1 - j - i][j + k] == '1') togetherI *= 10;
                else if (arr[GAME->N - 1 - j - i][j + k] == '2') togetherI2 *= 10;
            }
        }
    }
    int sum = togetherC + togetherD + togetherI + togetherR;
    int sum2 = togetherC2 + togetherD2 + togetherI2 + togetherR2;

    if (sum > sum2) {
        return -10;
    }
    else if (sum < sum2) {
        return 10;
    }
    else {
        return 0;
    }

}

int endcondition(Game* GAME, char** arr, char who) {
    

    int together = 0;

  

            for (int k = 0; k <= GAME->M - GAME->K; k++) {
                for (int i = 0; i <= (GAME->N - GAME->K); i++) {
                    for (int j = 0; j < GAME->K; j++) {
                        if (arr[j + i][j + k] == who)  together++; //diagonal
                    }
                    if (together >= GAME->K) return 1;
                    else together = 0;
                }
            }

            for (int k = 0; k <= GAME->M - GAME->K; k++) {
                for (int i = 0; i <= (GAME->N - GAME->K); i++) {
                    for (int j = 0; j < GAME->K; j++) {
                        if (arr[GAME->N - 1 - j - i][j + k] == who) together++;  //inverse diagonal
                    }
                    if (together >= GAME->K) return 1;
                    else together = 0;
                }
            }
      
    

    for (int i = 0; i < GAME->N; i++) {          // rows
        for (int j = 0; j <= (GAME->M - GAME->K); j++) {
            for (int k = j; k < GAME->K + j; k++) {
                if (arr[i][k] == who) together++;
            }
            if (together >= GAME->K) return 1;
            else together = 0;
        }
    }

    for (int j = 0; j < GAME->M; j++) {          // columns
        for (int i = 0; i <= (GAME->N - GAME->K); i++) {
            for (int k = i; k < GAME->K + i; k++) {
                if (arr[k][j] == who) together++;
            }
            if (together >= GAME->K) return 1;
            else together = 0;
        }
    }

    return 0;

}







int endcondition1(Game* GAME, char** arr, char who) {
    int together = 0;

    if (GAME->M == 3 && GAME->N == 3) {
        if (arr[1][1] != '0') {

            for (int k = 0; k <= GAME->M - GAME->K; k++) {
                for (int i = 0; i <= (GAME->N - GAME->K); i++) {
                    for (int j = 0; j < GAME->K; j++) {
                        if (arr[j + i][j + k] == who)  together++; //diagonal
                    }
                    if (together >= GAME->K) return 1;
                    else together = 0;
                }
            }

            for (int k = 0; k <= GAME->M - GAME->K; k++) {
                for (int i = 0; i <= (GAME->N - GAME->K); i++) {
                    for (int j = 0; j < GAME->K; j++) {
                        if (arr[GAME->N - 1 - j - i][j + k] == who) together++;  //inverse diagonal
                    }
                    if (together >= GAME->K) return 1;
                    else together = 0;
                }
            }
        }
    }

    for (int i = 0; i < GAME->N; i++) {          // rows
        for (int j = 0; j <= (GAME->M - GAME->K); j++) {
            for (int k = j; k < GAME->K + j; k++) {
                if (arr[i][k] == who) together++;
            }
            if (together >= GAME->K) return 1;
            else together = 0;
        }
    }

    for (int j = 0; j < GAME->M; j++) {          // columns
        for (int i = 0; i <= (GAME->N - GAME->K); i++) {
            for (int k = i; k < GAME->K + i; k++) {
                if (arr[k][j] == who) together++;
            }
            if (together >= GAME->K) return 1;
            else together = 0;
        }
    }

    return 0;

}


void printarr(Game* GAME, char** arr, int newI, int newJ) {
    for (int i = 0; i < GAME->N; i++) {
        for (int j = 0; j < GAME->M; j++) {
            if (i == newI && j == newJ) cout << GAME->active << " ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void print(Game* GAME, char** arr) {
    for (int i = 0; i < GAME->N; i++) {
        for (int j = 0; j < GAME->M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print(Game* GAME, char** arr, bool** arrofempty) {

    for (int i = 0; i < GAME->N; i++) {
        for (int j = 0; j < GAME->M; j++) {
            if (arrofempty[i][j] == true)
            {
                printarr(GAME, arr, i, j);
            }
        }

    }
}

void genallposmov(Game* GAME, char** arr) {
    bool** arrofempty = new bool* [GAME->N];
    for (int i = 0; i < GAME->N; ++i)
        arrofempty[i] = new bool[GAME->M];

    for (int i = 0; i < GAME->N; i++) {
        for (int j = 0; j < GAME->M; j++) {
            arrofempty[i][j] = false;
        }
    }

    int counter = 0;

    for (int i = 0; i < GAME->N; i++) {
        for (int j = 0; j < GAME->M; j++) {
            if (arr[i][j] == '0') {
                arrofempty[i][j] = true;
                counter++;
            }
        }
    }

    if (endcondition(GAME, arr, '1') == 1)
    {
        counter = 0;
        cout << counter << endl;
    }
    else if (endcondition(GAME, arr, '2') == 1) {
        counter = 0;
        cout << counter << endl;
    }
    else {
        cout << counter << endl;
        print(GAME, arr, arrofempty);
    }
}


int minmax(Game* GAME, char** arr, int depth, bool isMax) { //2 is max


    if (depth == 0) return 0;
    int score = 0;
    score = endcondition1(GAME, arr, '2');

    if (score == 1) {
        return 1;
    }

    score = endcondition1(GAME, arr, '1');
    if (score == 1) {
        return -1;
    }

    if (emptycell(GAME, arr) == false) {
        if (endcondition1(GAME, arr, '1') == 1) {
            return -1;
        }
        else if (endcondition1(GAME, arr, '2') == 1) {
            return 1;
        }
        return 0; //tie
    }


    if (isMax)
    {
        int value = -10;
        int best = -100;
        for (int j = 0; j < GAME->M; j++) {
            for (int i = 0; i < GAME->N; i++) {
                if (arr[i][j] == '0')
                {
                    arr[i][j] = '2';
                    value = minmax(GAME, arr, depth - 1, !isMax);
                    best = max(best, value);
                    // Undo the move
                    arr[i][j] = '0';
                }
            }
        }

        return best;

    }
    else
    {
        int best = 100;
        int value = 10;
        for (int j = 0; j < GAME->M; j++) {
            for (int i = 0; i < GAME->N; i++) {
                if (arr[i][j] == '0')
                {
                    arr[i][j] = '1';
                    value = minmax(GAME, arr, depth - 1, !isMax);
                    best = min(best, value);
                    // Undo the move
                    arr[i][j] = '0';
                }
            }
        }
        return best;
    }

}


void input(Game* GAME) {
    char command[MAXSIZE];
    while (true) {
        cin >> command;
        cin >> GAME->N >> GAME->M >> GAME->K >> GAME->active;

        char** arr = new char* [GAME->N];
        for (int i = 0; i < GAME->N; ++i)
            arr[i] = new char[GAME->M];

        for (int i = 0; i < GAME->N; i++) {
            for (int j = 0; j < GAME->M; j++) {
                cin >> arr[i][j];
            }
        }

        if (strcmp(command, "GEN_ALL_POS_MOV_CUT_IF_GAME_OVER") == 0) {

            char inactive = '0';;
            if (GAME->active == '1') inactive = '2';
            else inactive = '1';
            if (endcondition(GAME, arr, inactive) == 1) {
                cout << '0' << endl;

            }
            else {
                bool possiblewin = false;
                for (int i = 0; i < GAME->N; i++) {
                    for (int j = 0; j < GAME->M; j++) {
                        if (arr[i][j] == '0' && possiblewin == false) {
                            arr[i][j] = GAME->active;
                            if (endcondition(GAME, arr, GAME->active) == 1) {
                                possiblewin = true;
                                cout << 1 << endl;
                                print(GAME, arr);
                            }
                            else {
                                arr[i][j] = '0';
                            }
                        }

                    }
                }
                if (possiblewin == false) genallposmov(GAME, arr);
            }
        }
        else if (strcmp(command, "GEN_ALL_POS_MOV") == 0) {
            genallposmov(GAME, arr);

        }
        else if (strcmp(command, "SOLVE_GAME_STATE") == 0) {

            int result = 0;
            if (GAME->active == '2') {
                result = minmax(GAME, arr, (GAME->N * GAME->M - 1), true);
            }
            else {
                result = minmax(GAME, arr, (GAME->N * GAME->M - 1), false);
            }

            if (result == -1)  cout << "FIRST_PLAYER_WINS" << endl;
            else if (result == 1)  cout << "SECOND_PLAYER_WINS" << endl;
            else if (result == 0) cout << "BOTH_PLAYERS_TIE" << endl;
        }
        else if (feof(stdin) != 0) {
            break;
        }
    }
}


int main() {

    Game GAME;
    input(&GAME);


    return 0;
}