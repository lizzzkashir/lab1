#include "tasks.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>

void clear() {
    using namespace std;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//BackRec10
void r10(const char* filename) {
    using namespace std;

    ifstream fin(filename);
    if (!fin) {
        cout << "Ошибка " << filename << endl;
        return;
    }

    int N;
    double Z;
    fin >> N >> Z;

    vector<double> weights(N);
    vector<double> taxes(N);

    for (int i = 0; i < N; i++) fin >> weights[i];
    for (int i = 0; i < N; i++) fin >> taxes[i];

    fin.close();

    int bestm = 0;
    double bestt = 1e9;
    double bestw = 0;

    // перебор множеств
    int tot = 1 << N;
    for (int mask = 0; mask < tot; mask++) {
        double  sumw = 0;
        double sumt = 0;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                 sumw += weights[i];
                sumt += taxes[i];
            }
        }

        if ( sumw > Z) {
            if (sumt < bestt) {
                bestt = sumt;
                bestw =  sumw;
                bestm = mask;
            }
        }
    }

    cout << "номер (нумерация с 0): ";
    for (int i = 0; i < N; i++) {
        if (bestm & (1 << i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Суммарный вес: " << fixed << setprecision(2) << bestw << " кг" << endl;
    cout << "Суммарный налог: " << fixed << setprecision(2) << bestt << endl;
}

void REc10() {
    using namespace std;
    int N;
    double Z;
    cout << "Введите количество артефактов: ";
    cin >> N;
    cout << "Введите минимальный суммарный вес: ";
    cin >> Z;

    vector<double> weights(N);
    vector<double> taxes(N);

    cout << "Введите веса " << N << " арт: ";
    for (int i = 0; i < N; i++) cin >> weights[i];

    cout << "Введите налог " << N << " арт: ";
    for (int i = 0; i < N; i++) cin >> taxes[i];

    int bestm = 0;
    double bestt = 1e9;
    double bestw = 0;

    int tCom = 1 << N;
    for (int mask = 0; mask < tCom; mask++) {
        double sumw = 0;
        double sumt = 0;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                sumw += weights[i];
                sumt += taxes[i];
            }
        }

        if (sumw > Z) {
            if (sumt < bestt) {
                bestt = sumt;
                bestw = sumw;
                bestm = mask;
            }
        }
    }

    cout << "Номера арт: ";
    for (int i = 0; i < N; i++) {
        if (bestm & (1 << i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Суммарный вес: " << fixed << setprecision(2) << bestw << " кг" << endl;
    cout << "Суммарный налог: " << fixed << setprecision(2) << bestt << endl;
}

void rec10m() {
    using namespace std;
    cout << "Выберите способ ввода данных:" << endl;
    cout << "1. Из файла" << endl;
    cout << "2. С клавиатуры" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;
    clear();

    if (choice == 1) {
        r10("b10.txt");
    } else if (choice == 2) {
        REc10();
    } else {
        cout << "нет" << endl;
    }
}

//HomeDyn1
void din1fil(const char* filename) {
    using namespace std;

    ifstream fin(filename);
    if (!fin) {
        cout << "ошибка" << filename << endl;
        return;
    }

    int N;
    fin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fin >> board[i][j];
        }
    }

    fin.close();

    // правый вверх левый низ
    vector<vector<int>> dp(N, vector<int>(N, 0));

    dp[0][N-1] = board[0][N-1];

    for (int j = N-2; j >= 0; j--) {
        dp[0][j] = dp[0][j+1] + board[0][j];
    }

    for (int i = 1; i < N; i++) {
        dp[i][N-1] = dp[i-1][N-1] + board[i][N-1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = N-2; j >= 0; j--) {
            dp[i][j] = max(dp[i-1][j], dp[i][j+1]) + board[i][j];
        }
    }

    int result = dp[N-1][0];

    cout << "max сумма: " << result << endl;

    ofstream fout("h1.txt");
    fout << result;
    fout.close();
    cout << "Результат сохранен" << endl;
}

void dyn1cons() {
    using namespace std;
    int N;
    cout << "Введите размер поля: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    cout << "Введите числа на доске " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][N-1] = board[0][N-1];
    for (int j = N-2; j >= 0; j--) {
        dp[0][j] = dp[0][j+1] + board[0][j];
    }

    for (int i = 1; i < N; i++) {
        dp[i][N-1] = dp[i-1][N-1] + board[i][N-1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = N-2; j >= 0; j--) {
            dp[i][j] = max(dp[i-1][j], dp[i][j+1]) + board[i][j];
        }
    }

    int result = dp[N-1][0];

    cout << "max сумма: " << result << endl;
}

void dyn1m() {
    using namespace std;

    cout << "Способ ввода данных:" << endl;
    cout << "1. Из файла" << endl;
    cout << "2. С клавиатуры" << endl;
    cout << "Выбор: ";

    int choice;
    cin >> choice;
    clear();

    if (choice == 1) {
        din1fil("h1.txt");
    } else if (choice == 2) {
        dyn1cons();
    } else {
        cout << "нет" << endl;
    }
}


//Dyn17
void dyn17f(const char* filename) {
    using namespace std;
    ifstream fin(filename);
    if (!fin) {
        cout << "ошибка" << filename << endl;
        return;
    }

    int K, N;
    fin >> K >> N;
    fin.close();

    if (N <= 0 || K < 2 || K > 10) {
        cout << "надо другие данные" << endl;
        return;
    }

    vector<vector<double>> dp(N + 1, vector<double>(3, 0.0));

    if (N >= 1) {
        dp[1][0] = K - 1;  // первая цифра не 0
        dp[1][1] = 0;      // не 0
        dp[1][2] = 0;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) * (K - 1);//послед 0
        dp[i][1] = dp[i-1][0]; // посл 0 перед ней !0
        dp[i][2] = dp[i-1][1];//00
    }

    double total = dp[N][0] + dp[N][1] + dp[N][2];
// 1100 1110 1111 1010 1011 1101 1001 
    cout << "Основание системы " << K << endl;
    cout << "Количество разрядов " << N << endl;
    cout << "ответ ";
    cout << fixed << setprecision(0) << total << endl;

    ofstream fout("h17.txt");
    fout << fixed << setprecision(0) << total;
    fout.close();
    cout << "сохранен" << endl;
}

void dyndyn17con() {
    using namespace std;
    int K, N;
    cout << "основание системы счисления: ";
    cin >> K;
    cout << "количество разрядов N (до 20): ";
    cin >> N;

    if (N <= 0 || K < 2 || K > 10 || N >= 20 || N + K >= 26) {
        cout << "нет" << endl;
        return;
    }

    vector<vector<double>> dp(N + 1, vector<double>(3, 0.0));

    if (N >= 1) {
        dp[1][0] = K - 1;
        dp[1][1] = 0;
        dp[1][2] = 0;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) * (K - 1);
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1];
    }

    double total = dp[N][0] + dp[N][1] + dp[N][2];

    cout << "ответ ";
    cout << fixed << setprecision(0) << total << endl;
}

void dyndyn17m() {
    using namespace std;
    cout << "Выберите способ ввода:" << endl;
    cout << "1. Из файла" << endl;
    cout << "2. С клавиатуры" << endl;
    cout << "выбор: ";

    int choice;
    cin >> choice;
    clear();

    if (choice == 1) {
        dyn17f("yyy.txt");
    } else if (choice == 2) {
        dyndyn17con();
    } else {
        cout << "ytn" << endl;
    }
}




