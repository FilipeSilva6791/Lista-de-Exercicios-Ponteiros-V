/*****************************************************************************************
 Implemente a função descrita nas questões a seguir, seguindo as especificações. No mesmo
 exercício, construa a função main() que utilize ou teste a função desenvolvida.

 Considere os tipos de dados declarados a seguir :

    typedef struct {
    int *d; // area de dados
    int t; // tamanho do campo de dados
    }vetor_t; // representa um vetor de dados tipo inteiros


    typedef struct {
    int *d; // area de dados
    pos2d_t t; // tamanho do campo de dados
    }matriz_t; // representa uma matriz de dados tipo inteiros

 2. int mat_vetor(matriz_t *mat, vetor_t *vet, int lin)
 Função : copia os valores do vetor *vet para a linha lin da matriz mat
 Parametros : vet - vetor origem dos dados
              mat – matriz destino
              lin – linha a ser copiada
 Retorno : 0 – função executada completamente
           -1 - tamanhos incompativeis
 *****************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>

 typedef struct {
 int lin; // posição na linha
 int col; // posição na coluna
 }pos2d_t; // posição em sistema de coordenadas 2d

 typedef struct {
 int *d; // area de dados
 int t; // tamanho do campo de dados
 }vetor_t; // representa um vetor de dados tipo inteiros

 typedef struct {
 int *d; // area de dados
 pos2d_t t; // tamanho do campo de dados
 }matriz_t; // representa uma matriz de dados tipo inteiros


 int main ()
 {
   setlocale(LC_ALL,"");

   int lin_mat, col_mat, tam_vet;
   int linha, retorno,i,j;

   //declarando as variáveis dos tipos de dados que foram criados
   matriz_t matriz;
   vetor_t vetor;

   // pedindo as dimensões do vetor e da matriz
   printf("Digite as dimensões da matriz e do vetor nos campos abaixo: \n");
   printf("Tamanho do vetor: "); scanf("%d",&tam_vet);
   printf("Quantidade de linhas da matriz: "); scanf("%d",&lin_mat);
   printf("Quantidade de colunas da matriz: "); scanf("%d", &col_mat);

   //declarando a matriz e o vetor com os valores conhecidos
   int vet[tam_vet];
   int mat[lin_mat][col_mat]; //zerando toda a matriz

   for(i=0; i<lin_mat; i++)
   {
      for(j=0; j<col_mat; j++)
          mat[i][j]=0;
   }

   //usuário preenchendo o vetor
   printf("\nAgora preencha o vetor com números inteiros: \n");

   for(i=0; i<tam_vet; i++) {
        printf("Valor %d : ",i);
        scanf("%d",&vet[i]); }

   //preenchendo os valores internos as estruturas
   matriz.t.lin=lin_mat;
   matriz.t.col=col_mat;
   matriz.d = &mat[0][0];

   vetor.t=tam_vet;
   vetor.d=&vet[0];

   //passando o vetor para uma linha da matriz
   printf("\nDigite para qual linha da matriz você quer passar o vetor: ");
   scanf("%d", &linha);

   retorno=mat_vetor(&matriz, &vetor, linha);

   if(retorno == 0)
   {
        printf("\nMatriz: \n");

        for(i=0; i<lin_mat; i++)
        {
            for(j=0; j<col_mat; j++)
            {
                printf("%d ", mat[i][j]);

                if(j==(col_mat-1))
                    printf("\n");
            }
        }
   }
   else
    printf("\nErro de compatibilidade. O vetor é maior que a linha da matriz. \n");

   return 0;
   system("pause");
 }

 int mat_vetor(matriz_t *mat, vetor_t *vet, int lin)
{
   int j;
   int pos;

   pos=mat->t.col * lin;       //determina onde começa a linha que queremos passar o vetor

   if((mat->t.col) < (vet->t)) //se a linha da matriz tem menos colunas que o vetor
        return -1;

   for(j=0;j<vet->t; j++)
      *(mat->d + pos +j)=*(vet->d+j);

   return 0;
}
