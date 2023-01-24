/*******************************************************************************************************
 Implemente a função descrita nas questões a seguir, seguindo as especificações. No mesmo
 exercício, construa a função main() que utilize ou teste a função desenvolvida.

 Considere os tipos de dados declarados a seguir :

    typedef struct {
    int lin; // posição na linha
    int col; // posição na coluna
    }pos2d_t; // posição em sistema de coordenadas 2d

    typedef struct {
    int *d; // area de dados
    pos2d_t t; // tamanho do campo de dados
    }matriz_t; // representa uma matriz de dados tipo inteiros

 3. int m_identidade(matriz_t *mat_t, matriz_t *mat );
 Função : obtem a transposta de matrizes
 Parametros : mat – matriz origem
 mat_t – matriz transposta
 Retorno : 0 – função executada, -1 : tamanhos incompativeis
********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

 typedef struct {
 int lin; // posição na linha
 int col; // posição na coluna
 }pos2d_t; // posição em sistema de coordenadas 2d

 typedef struct {
 int *d; // area de dados
 pos2d_t t; // tamanho do campo de dados
 }matriz_t; // representa uma matriz de dados tipo inteiros

 int m_identidade(matriz_t *mat_t, matriz_t *mat );

int main ()
{
 setlocale(LC_ALL,"");
 srand(time(NULL));

 int i,j,retorno;
 matriz_t mat;
 matriz_t mat_transposta;

 printf("Informe dimensões para a matriz nos campos abaixo: \n");
 printf("Quantidade de linhas: "); scanf("%d", &mat.t.lin);
 printf("Quantidade de colunas: "); scanf("%d", &mat.t.col);

 printf("\n5Agora, informe as dimensões da matriz transposta nos campos abaixo: \n");
 printf("Quantidade de linhas: "); scanf("%d", &mat_transposta.t.lin);
 printf("Quantidade de colunas: "); scanf("%d", &mat_transposta.t.col);

 //declarando as matrizes com valores conhecidos
 int matriz [mat.t.lin][mat.t.col];
 int matriz_t[mat_transposta.t.lin][mat_transposta.t.col];

 //apontando os ponteiros para as matrizes
 mat.d=&matriz[0][0];
 mat_transposta.d=&matriz_t[0][0];

 //preenchendo a matriz com valores aleatórios
 for(i=0; i<(mat.t.lin); i++)
 {
     for(j=0; j<(mat.t.col); j++)
            matriz[i][j]=rand()%100;
 }

 //exibindo a matriz original
 printf("\nMatriz com valores aleatórios:\n");

 for(i=0; i<(mat.t.lin); i++)
 {
     for(j=0; j<(mat.t.col); j++)
        {
            printf("%2d ", matriz[i][j]);

            if(j==mat.t.col-1)
                printf("\n");
        }
 }

 //passando os valores para a matriz transposta
 retorno=m_identidade(&mat_transposta, &mat);

 //exibindo a mat transposta
 if(retorno==0)
 {
     printf("\nMatriz transposta:\n");

     for(i=0; i<(mat_transposta.t.lin); i++)
    {
        for(j=0; j<(mat_transposta.t.col); j++)
        {
            printf("%2d ", matriz_t[i][j]);

            if(j==mat_transposta.t.col-1)
                printf("\n");
        }
    }

    printf("\n\n");

 }else
     printf("\n\nERRO> O número de linhas e colunas informados para a transposta não pode ser usado. \n\n");

 return 0;
 system("pause");
}

int m_identidade(matriz_t *mat_t, matriz_t *mat )
{
    int k,l=0,x=0;

    //se as matrizes não tiverem os valores de coluna e linha invertidos uma da outra
    if(mat_t->t.lin != mat->t.col || mat_t->t.col != mat->t.lin)
        return -1;

    //laço que começa em zero e vai até (lin x col)
    for(k=0; k<((mat->t.col)*(mat->t.lin)); k++)
    {
       //os valores da transposta passam de forma linear;
       //os valores da matriz origem passa de linha em linha na posição zero
       //depois de linha em linha na posição de coluna 1, e assim por diante...

       *((mat_t->d)+k) = *((mat->d)+(x* mat->t.col)+l);

       //'x' multiplica o valor das colunas e se soma ao endereço da primeira posição da matriz
       //o que vai fazer com que a matriz origem "pule" de linha em linha;
       //a cada laço x incrementa.
       x++;

       //quando a matriz prigem chegar na ultima linha, ou seja, sua posição dividida pelo nº de linhas
       //resulta em um resto =0 ;
       //zeramos 'x', o que fará com que a matriz origem volte para primeira linha, e incrementamos 'l',
       //que controla em qual coluna estamos
         if(((k+1)%(mat->t.lin))==0 && k!=0)
         {
             printf("PASSEI k= %d ",k);
             x=0;
             l++;
         }
    }

    return 0;
}
