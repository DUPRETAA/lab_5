// 20. 	Найти минимальный из неповторяющихся элементов дву-мерного массива.
#include <iostream>

using namespace std;

const int N=3;
const int M=N;

int MinUniq(int matrix[N][M]) {
    
    int sortedMas[N*M]{};
    sortedMas[0]=matrix[0][0];

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (!i&&!j) continue;
            for (int k=(i*M)+j-1; k>=0;k--) {
                if (matrix[i][j]<sortedMas[k]) {
                    sortedMas[k+1]=sortedMas[k];
                    sortedMas[k]=matrix[i][j];
                }
                else {
                    sortedMas[k+1]=matrix[i][j];
                    k=0;
                }
            }
        }
    }
 
    int temp=sortedMas[0];
    if (temp!= sortedMas[1]) {
        return temp;
    }
    
    for (int i=1; i<N*M;i++) {
        if (temp==sortedMas[i]) continue;
        else if (sortedMas[i]==sortedMas[i+1]) temp=sortedMas[i]; 
            else return sortedMas[i];

    }
    return NULL;
}

int main() {
    setlocale(LC_ALL,"russian");
    srand(time(NULL));

    while (true) {
        int matrix[N][M]{};
        
        cout << "Массив: " << endl;
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                matrix[i][j] = rand()%11-5;
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
        
        int answer=MinUniq(matrix);
        if (answer!=NULL) cout << "Минимальный из неповторяющихся элементов двумерного массива: " << answer << endl; else cout << "Неповторяющиеся элементы двумерного массива отсутствуют" << endl;

        system("pause");
    }   
    return 0;
}