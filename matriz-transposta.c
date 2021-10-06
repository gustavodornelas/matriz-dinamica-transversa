#include <stdio.h>
#include <stdlib.h>

int** preenche_matriz (int linha, int coluna){ //função para preencher matriz de tamanho N x M

    int** m;

    m=malloc(sizeof(int*)*linha); //aloca espaço para as linhas

    for (int i=0; i<linha; i++){
        m[i]=malloc (sizeof(int)*coluna); //aloca espaço para as colunas

        for (int j=0; j<coluna; j++){
            printf ("Digite o valor[%d][%d]: ", i, j);
            scanf ("%d", &m[i][j]); //recebe os valores para a matriz
        }
    }

    return m; //retorna a matriz
}

void imprime_matriz (int** matriz, int linha, int coluna){ //função para imprimir Matriz

    for (int i=0; i<linha; i++){
        for (int j=0; j<coluna; j++){
            printf ("%d ", matriz[i][j]);
        }
        printf ("\n");
    }
}

int** transposta(int** matriz, int linha, int coluna){ //função para criar matriz transposta

    int** t;
    
    t=malloc(sizeof(int*)*coluna); //aloca espaço para as linhas, de acordo com o tamanho das colunas da matriz original

    for (int i=0; i<linha; i++){
        t[i]=malloc (sizeof(int)*linha); //aloca espaço para as colunas, de acordo com o tamanho das linhas da matriz original
    }

    for (int i=0; i<linha; i++){ //percorre a matriz original, armazenando os valores na transposta
        for (int j=0; j<coluna; j++){
            t[j][i]=matriz[i][j];
        }
    }

    return t; //retorna a matriz transposta
}

void free_col (int** m, int linha){ //função para limpar memoria das matrizes

    for (int i=0; i<linha; i++){
        free (m[i]);
    }

}

int main (){

    int n, m;
    int** matriz, matrizTransposta;

    printf ("Digite o tamanho da matriz (Linhas Colunas): ");
    scanf ("%d %d", &n, &m); //recebe valores de n(linhas) e m(colunas)

    matriz=preenche_matriz(n, m); //preenche a matriz

    printf ("\nImprimindo Matriz!\n");
    imprime_matriz (matriz, n, m); // imprime a matriz

    matrizTransposta=transposta(matriz, n, m); //quantidades de linhas e colunas da matriz original

    printf ("\nImprimindo Matriz Transposta!\n");
    imprime_matriz (matrizTransposta, m, n); //Inverte Valores de m e n de lugar para imprimir a transposta


    //limpar memoria
    free_col(matriz, n);
    free(matriz);
    free_col (matrizTransposta, m);
    free(matrizTransposta);
    return 0;
}