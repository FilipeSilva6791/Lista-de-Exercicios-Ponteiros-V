 /*****************************************************************************************
  Implemente a fun��o descrita nas quest�es a seguir, seguindo as especifica��es. No mesmo
  exerc�cio, construa a fun��o main() que utilize ou teste a fun��o desenvolvida.

  Considere o tipo de dados declarado a seguir :

    typedef struct {
    int *d;    // area de dados
    int t;     // tamanho do campo de dados
    }vetor_t;  // representa um vetor de dados tipo inteiros

  Fun��o a ser desenvolvida:

    1. void v_maior(vetor_t *vet, int *maior, int *pos );
    Fun��o : encontra o maior valor contido no vetor vet
    Parametros : vet � vetor com os dados
    maior � maior valor encontrado
    pos � posi��o do maior valor no vetor
 ********************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>
 #include<time.h>

 #define TAM 10                     //determina o tamanho do vetor

 typedef struct {
     int *d;                         // area de dados (handler do vetor)
     int t;                          // tamanho do campo de dados (tam. do vetor)
 }vetor_t;                           // representa um vetor de dados tipo inteiros


 void v_maior(vetor_t *vet, int *maior, int *pos )
{
     int j;

     *maior =*(vet->d);   //armazena o primeiro valor do vetor

     for(j=0; j<(vet->t); j++)
     {
         if(*((vet->d)+j) > *maior) //se o valor atual do vetor for maior que o valor armazenado em 'maior'
        {
            *maior=*((vet->d) + j);
            *pos=j;
        }
     }
}

 int main ()
 {
     setlocale(LC_ALL,"");

     //declarando vari�veis
     int i,maior=0,posicao=0;                                     //maior -> armazena o maior valor do vetor ; posicao -> armazena a posicao do maior valor no vetor
     int vetor[TAM];
     vetor_t dados;

     //apontando o ponteiro que est� dentro da estrutura para o vetor
     dados.d=&vetor[0];

     //definindo o tamanho do vetor
     dados.t=TAM;

     //Inicializando o vetor com valores aleat�rios
     srand(time(NULL));

     for(i=0; i<TAM; i++)
        vetor[i]=rand()%100;

     //exibindo o vetor
     printf("Vetor : \n\n");

     for(i=0; i<TAM; i++)
        printf("posi��o[%d]=%d \n",i,vetor[i]);

     //chamando a fun��o
     v_maior(&dados,&maior,&posicao);

     //exibindo os resultados
     printf("\nMaior valor = %d \n",maior);
     printf("Posi��o = %d \n\n", posicao);

     system("pause");
     return 0;
 }
