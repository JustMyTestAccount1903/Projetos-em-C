
#include <stdio.h>
/*
*Cria um registro do tipo Jogador
*tem como atributos: matricula, jogos,
*gols e assists; todos inteiros;
*/
typedef struct player
{
    int id;
    int jogos;
    int gols;
    int assists;
} Player;

//Imprimir jogador
/*
* Funcao imprimeJogador, recebe um ponteiro do tipo jogador
* e imprime o valor de seus atributos;
*/
void imprimeJogador(Player *j)
{
    printf("Matricula do jogador: %d\n", j->id);
    printf("Quantidade de jogos: %d\n", j->jogos);
    printf("Numero de gols: %d\n", j->gols);
    printf("Numero de assistencias: %d\n", j->assists);
}

//Atribuir jogador
/*
* Funcao setJogador, recebe um ponteiro do tipo jogador,
* e inteiros: matricula, jogos, gols e assists,
* atribuindo os valores recebidos ao ponteiro jogador;
*/
Player* setJogador(Player *j)
{
    printf("Digite o ID do jogador: \n");
    scanf("%d", &j->id);
    printf("Digite a quantidade de jogos, gols e assistencias: \n");
    scanf("%d%d%d", &j->jogos, &j->gols, &j->assists);
    return j;
}

//Jogador destaque
/*
* Funcao jogadorDestaque, recebe um ponteiro do tipo jogador
* e verifica se a soma do numero de gols e de
* assistencias dividido pela quantidade de jogos
* é igual ou maior a 0.5;
* se sim, retorna 1;
* se nao, retorna 0;
*/
int jogadorDestaque(Player *j)
{
    float particip_gol = j->gols + j->assists;
    float gols_jogo = particip_gol / j->jogos;
    if(gols_jogo >= 0.5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
* Funcao imprimeListaJogador, recebe um vetor de jogador
* e um tamanho do tipo inteiro;
* imprime na tela o vetor recebido;
*/
void imprimeListaJogador(Player vetor[], int tamanho)
{
  for (int i=0; i<tamanho; i++)
    {
      printf("Jogador %d:\n", i+1);
      imprimeJogador(&vetor[i]);
    }
}
