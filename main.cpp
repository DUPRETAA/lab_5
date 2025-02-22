#include <iostream>

using namespace std;

void MinUniq(int**& matrix, int rows, int columns) {
    
}

int main() {
    setlocale(LC_ALL,"russian");
    srand(time(NULL));

    const int N=5;
    const int M=N;

    int matrix[N][M]{};

    cout << "Массив: " << endl;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            matrix[i][j] = rand()%11-5;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }



    return 0;
}