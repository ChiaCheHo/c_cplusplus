#include <iostream>
using namespace std;

void createMatrix(int *a, int dimX, int dimY);
void printfMatrix(int *a, int dimX, int dimY);
void addMatrix(int *a, int *b, int *c, int dimX, int dimY);
void transMatrix(int *a, int *b, int dimX, int dimY);
void multiplyMatrix(int *a, int *b, int *c, int m, int n, int p);
void compressMatrix(int *a, int *b, int m, int n, int p);

int main(){
    int a[12], b[12], add[12], trans[12], multiply[16];
    createMatrix(a, 4, 3);
    createMatrix(b, 4, 3);
    addMatrix(a, b, add, 4, 3);
    transMatrix(a, trans, 4, 3);
    multiplyMatrix(a, trans, multiply, 4, 3, 4);

    printfMatrix(a, 4, 3);
    printfMatrix(b, 4, 3);
    printfMatrix(add, 4, 3);
    printfMatrix(trans, 3, 4);
    printfMatrix(multiply, 4, 4);

    int sparse[36], compress[9];
    int size=6;
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            sparse[i*size+j] = 0;
        }
    }
    sparse[14] = 9;
    sparse[25] = 3;
    compressMatrix(sparse, compress, size, size, 2);
    printfMatrix(sparse, 6, 6);
    printfMatrix(compress, 3, 3);

    system("PAUSE");
    return 0;
}

void createMatrix(int *a, int dimX, int dimY){
    //每個矩陣值範圍都從0~9
    for(int row=0; row < dimX; row++){
        for(int col=0; col < dimY; col++){
            a[row*dimY+col] = rand()%10;
        }
    }
}

void printfMatrix(int *a, int dimX, int dimY){
    for(int row=0; row < dimX; row++){
        for(int col=0; col < dimY; col++){
            cout << a[row*dimY+col] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

void addMatrix(int *a, int *b, int *c, int dimX, int dimY){
    if(dimX<=0 || dimY<=0){
        cout << "維度必須大於0" << endl;
        return;
    }
    for(int row=0; row < dimX; row++){
        for(int col=0; col < dimY; col++){
            c[row*dimY+col] = a[row*dimY+col] + b[row*dimY+col];
        }
    }
}

void transMatrix(int *a, int *b, int dimX, int dimY){
    if(dimX<=0 || dimY<=0){
        cout << "維度必須大於0" << endl;
        return;
    }
    for(int row=0; row < dimX; row++){
        for(int col=0; col < dimY; col++){
            b[col*dimX+row] = a[row*dimY+col];
        }
    }
}

void multiplyMatrix(int *a, int *b, int *c, int m, int n, int p){
    //matrix(m*n) * matrix(n*p) =  matrix(m*p)
    if(m<=0 || n<=0 || p<=0){
        cout << "維度必須大於0" << endl;
        return;
    }
    for(int row=0; row < m; row++){
        for(int col=0; col < p; col++){
            int temp = 0;
            for(int k=0; k < n; k++){
                temp = temp + a[row*n+k] * b[k*p+col];
            }
            c[row*p+col] = temp;
        }
    }
}

void compressMatrix(int *a, int *b, int m, int n, int p){
    //m*n的矩陣共有p個元素不為0
    if(m<=0 || n<=0){
        cout << "維度必須大於0" << endl;
        return;
    }

    b[0] = m;
    b[1] = n;
    b[2] = p;
    int temp = 3;
    for(int row=0; row < m; row++){
        for(int col=0; col < n; col++){
            if(a[row*n+col]!=0){
                b[temp] = row;
                b[temp+1] = col;
                b[temp+2] = a[row*n+col];
                temp += 3;
            }
        }
    }
}