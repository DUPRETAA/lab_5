// 20. 	Найти минимальный из неповторяющихся элементов дву-мерного массива.
#include <iostream>

using namespace std;

const int N=5;
const int M=N;

void MinUniq(int matrix[N][M]) {
    
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
 
    bool isFounded=false;
    int temp=sortedMas[0];

    if (!isFounded) {
        for (int i=1; i<N*M;i++) {
            if (temp==sortedMas[i]) continue;
            else if (sortedMas[i]==sortedMas[i+1]) temp=sortedMas[i]; 
                else  {temp =sortedMas[i]; isFounded=true; i=M*N;}

        }
    }

    if (isFounded) cout << "Минимальный из неповторяющихся элементов двумерного массива: " << temp << endl;
    else cout << "Неповторяющиеся элементы двумерного массива отсутствуют" << endl;
    return;
}

int main() {
    setlocale(LC_ALL,"russian");
    srand(time(NULL));

    int matrix[N][M]{};

    while (true) {
        
        cout << "Массив: " << endl;
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                matrix[i][j] = rand()%11-5;
                cout << matrix[i][j] << "\t";
            }  
            cout << endl;
        }
        
        MinUniq(matrix);
        cin.get();
    }   
    return 0;
}