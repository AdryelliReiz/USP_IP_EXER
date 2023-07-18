/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   Adryelli Reis dos Santos                   14714019           **/
/**                                                                 **/
/**   Data de entrega:                                              **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define NumeroMaxTimes 20
//#define NumeroMaxRodadas 38
#define NumeroMaxTimes 6
#define NumeroMaxRodadas 9


typedef struct auxtime {
  int PontosGanhos;
  int GolsMarcados;
  int GolsSofridos;
  int SaldoDeGols;
  int Vitorias;
  int GolAverage;
  char nome[31];
} time;

typedef struct auxjogo {
  char local[30];
  char visitante[30];
  int golslocal;
  int golsvisitante;
} jogo;

void lenometime(char * s) {
  int i;
  s[0] = '\0';
  char c;
  c = getchar();
  for(i = 0; c != ',' && i < 30;++i)
    {
      s[i] = c;
      c = getchar();
    }
  s[i] = '\0';
}

// Encontra se o time já está no arranjo de times do campeonato
//FEITO
int encontratime(time *timescampeonato, char * nome, int notimes) {
  for (int i = 0; i < notimes; i++) {
    if (strcmp(timescampeonato[i].nome, nome) == 0) {
      return i;
    }
  }

  return -1;
}

// Cria a lista de times do campeonato a partir dos nojogos
//FEITO
int crialistatimes(time * timescampeonato, jogo * dadosjogos, int numerojogos) {
  // preenche o arranjo timescampeonato com os times
  int i, auxindex = 0;
  for (i = 0; i < NumeroMaxTimes / 2; i++) {
    strncpy(timescampeonato[auxindex].nome,dadosjogos[i].local,30);
    timescampeonato[auxindex].GolAverage = 0;
    timescampeonato[auxindex].GolsMarcados = 0;
    timescampeonato[auxindex].GolsSofridos = 0;
    timescampeonato[auxindex].SaldoDeGols = 0;
    timescampeonato[auxindex].Vitorias = 0;
    timescampeonato[auxindex].PontosGanhos = 0;
    auxindex++;
    
    strncpy(timescampeonato[auxindex].nome,dadosjogos[i].visitante,30);
    timescampeonato[auxindex].GolAverage = 0;
    timescampeonato[auxindex].GolsMarcados = 0;
    timescampeonato[auxindex].GolsSofridos = 0;
    timescampeonato[auxindex].SaldoDeGols = 0;
    timescampeonato[auxindex].Vitorias = 0;
    timescampeonato[auxindex].PontosGanhos = 0;
    auxindex++;
  }

  return auxindex; // retorna o número de times. O zero é só para compilar
}

// Computa dados times
//FEITO
void computadadostimes(time * timescampeonato,int notimes,jogo * dadosjogos,int numerojogos) {
// Preenche os campos do arranjo timescampeonato: Vitorias,
// GolsSofridos, GolsMarcados, Golsaverage, SaldoDeGols, PontosGanhos.
  int i, indextime;

  //primeiro registra os gols marcados, sofriados e as vitorias
  for(i = 0; i < numerojogos; i++) {
    //começa pelo local
    indextime = encontratime(timescampeonato, dadosjogos[i].local, notimes);
    timescampeonato[indextime].GolsMarcados += dadosjogos[i].golslocal;
    timescampeonato[indextime].GolsSofridos += dadosjogos[i].golsvisitante;
    if(dadosjogos[i].golslocal > dadosjogos[i].golsvisitante) {
      timescampeonato[indextime].Vitorias += 1;
      timescampeonato[indextime].PontosGanhos += 3;
    }
    if(dadosjogos[i].golslocal == dadosjogos[i].golsvisitante) {
      timescampeonato[indextime].PontosGanhos += 1;
    }//se for uma derrota não soma nada

    //termina pelo visitante
    indextime = encontratime(timescampeonato, dadosjogos[i].visitante, notimes);
    timescampeonato[indextime].GolsMarcados += dadosjogos[i].golsvisitante;
    timescampeonato[indextime].GolsSofridos += dadosjogos[i].golslocal;
    if(dadosjogos[i].golsvisitante > dadosjogos[i].golslocal) {
      timescampeonato[indextime].Vitorias += 1;
      timescampeonato[indextime].PontosGanhos += 3;
    }
    if(dadosjogos[i].golsvisitante == dadosjogos[i].golslocal) {
      timescampeonato[indextime].PontosGanhos += 1;
    }//se for uma derrota não soma nada

  }

  //depois calcula gols average
  for(i = 0; i < notimes; i++) {
    timescampeonato[i].GolAverage = (timescampeonato[i].GolsSofridos == 0 
      ? timescampeonato[i].GolsMarcados
      : timescampeonato[i].GolsMarcados / timescampeonato[i].GolsSofridos
    );
  }

}

// Imprime classificação
void imprimeclassificacao(time * timescampeonato,int notimes){
  int ult, i, i2;
  time aux;
  //Ordena os times por classificação
  for (ult = notimes - 1; ult > 0; ult--) {
    for (i = 0; i < ult; i++) {
      aux = timescampeonato[i];
      if(aux.PontosGanhos < timescampeonato[i+1].PontosGanhos) {
        timescampeonato[i] = timescampeonato[i + 1];
        timescampeonato[i + 1] = aux;
      } else if (aux.PontosGanhos == timescampeonato[i+1].PontosGanhos) {
        if(aux.SaldoDeGols < timescampeonato[i+1].SaldoDeGols) {
          timescampeonato[i] = timescampeonato[i + 1];
          timescampeonato[i + 1] = aux;
        }
      }
    }
  }

  //printa os resultados da classificação
  printf("|| Nome: ||  Classificação:  ||  Pontuação: ||\n");
  for (i2 = 0; i2 < notimes; i2++) {
    printf("%s  ", timescampeonato[i2].nome);
    printf("||  %d  ", i2 + 1);
    printf("||  %d\n", timescampeonato[i2].PontosGanhos);
  }
}

// Salva os dados da classificação dos tipos em arquivo no disco

void salvaclassificacao(time * timescampeonato,int notimes, char * arquivo){

}

int main() {
  time times[NumeroMaxTimes];
  jogo jogos[NumeroMaxRodadas];
  int i, nojogos, golslocal = 0, golsvisitante = 0;
  char local[30], visitante[30];

  printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
  for(i = 0; i <= NumeroMaxRodadas; ++i) {
    lenometime(local);
    lenometime(visitante);
    scanf("%d,%d",&golslocal,&golsvisitante);

    if (golslocal < 0)
      break; // termina a entrada de dados

    strncpy(jogos[i].local,local,30);
    strncpy(jogos[i].visitante,visitante,30);

    jogos[i].golslocal = golslocal;
    jogos[i].golsvisitante = golsvisitante;
  }
  nojogos = i;

  // Confirmando os valores lidos
  for(i=0; i < nojogos;++i)
    printf("%s,%s,%d,%d",jogos[i].local,jogos[i].visitante,jogos[i].golslocal,jogos[i].golsvisitante);
  
  printf("\n");

  int notimes = crialistatimes(times,jogos,nojogos);

  computadadostimes(times,notimes,jogos,nojogos);

  imprimeclassificacao(times,notimes);

  // Opcional
  salvaclassificacao(times,notimes,"campeonatoIP.dat");

}