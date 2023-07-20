/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   Adryelli Reis dos Santos                   14714019           **/
/**                                                                 **/
/**   Data de entrega: 19/07/2023                                   **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumeroMaxTimes 20
#define NumeroMaxRodadas 38
#define NumeroMaxJogos NumeroMaxTimes * NumeroMaxRodadas

typedef struct auxtime {
    int PontosGanhos;
    int GolsMarcados;
    int GolsSofridos;
    int SaldoDeGols;
    int Vitorias;
    int Empates;
    int Derrotas;
    float GolAverage;
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
int encontratime(time *timescampeonato, char * nome, int notimes) {
    // Retorna a posição do arranjo times de campeonato
    for (int i = 0; i < notimes; i++) {
        if (strcmp(timescampeonato[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;; // retorna -1 se o time com o nome "nome" não existe
}

// Cria a lista de times do campeonato a partir dos nojogos
int crialistatimes(time * timescampeonato, jogo * dadosjogos, int numerojogos) {
    int i, auxindex = 0, timeexiste;
    for (i = 0; i < numerojogos; i++) {
        timeexiste = encontratime(timescampeonato,dadosjogos[i].local,auxindex);
        if(timeexiste == -1) {
            strncpy(timescampeonato[auxindex].nome,dadosjogos[i].local,30);
            timescampeonato[auxindex].GolAverage = 0;
            timescampeonato[auxindex].GolsMarcados = 0;
            timescampeonato[auxindex].GolsSofridos = 0;
            timescampeonato[auxindex].SaldoDeGols = 0;
            timescampeonato[auxindex].Vitorias = 0;
            timescampeonato[auxindex].Empates = 0;
            timescampeonato[auxindex].Derrotas = 0;
            timescampeonato[auxindex].PontosGanhos = 0;
            auxindex++;
        }
        
        timeexiste = encontratime(timescampeonato,dadosjogos[i].visitante,auxindex);
        if(timeexiste == -1) {
            strncpy(timescampeonato[auxindex].nome,dadosjogos[i].visitante,30);
            timescampeonato[auxindex].GolAverage = 0;
            timescampeonato[auxindex].GolsMarcados = 0;
            timescampeonato[auxindex].GolsSofridos = 0;
            timescampeonato[auxindex].SaldoDeGols = 0;
            timescampeonato[auxindex].Vitorias = 0;
            timescampeonato[auxindex].Empates = 0;
            timescampeonato[auxindex].Derrotas = 0;
            timescampeonato[auxindex].PontosGanhos = 0;
            auxindex++;
        }
    }

    return auxindex; // retorna o número de times. O zero é só para compilar
}

// Computa dados times
void computadadostimes(time * timescampeonato,int notimes,jogo * dadosjogos,int numerojogos) {
// Preenche os campos dos elementos do arranjo timescampeonato: Vitorias,
// GolsSofridos, GolsMarcados, Golsaverage, SaldoDeGols, PontosGanhos.
    int i, indextimelocal, indextimevisitante;

    //primeiro registra os gols marcados, sofriados e as vitorias
    for(i = 0; i < numerojogos; i++) {
        indextimelocal = encontratime(timescampeonato, dadosjogos[i].local, notimes);
        indextimevisitante = encontratime(timescampeonato, dadosjogos[i].visitante, notimes);
    
        timescampeonato[indextimelocal].GolsMarcados += dadosjogos[i].golslocal;
        timescampeonato[indextimevisitante].GolsMarcados += dadosjogos[i].golsvisitante;

        timescampeonato[indextimelocal].GolsSofridos += dadosjogos[i].golsvisitante;
        timescampeonato[indextimevisitante].GolsSofridos += dadosjogos[i].golslocal;
        
        if(dadosjogos[i].golslocal > dadosjogos[i].golsvisitante) {
            timescampeonato[indextimelocal].Vitorias += 1;
            timescampeonato[indextimelocal].PontosGanhos += 3;

            timescampeonato[indextimevisitante].Derrotas += 1;
        } else if(dadosjogos[i].golslocal == dadosjogos[i].golsvisitante) {
            timescampeonato[indextimelocal].Empates += 1;
            timescampeonato[indextimelocal].PontosGanhos += 1;

            timescampeonato[indextimevisitante].Empates += 1;
            timescampeonato[indextimevisitante].PontosGanhos += 1;
        } else {
            timescampeonato[indextimelocal].Derrotas += 1;

            timescampeonato[indextimevisitante].Vitorias += 1;
            timescampeonato[indextimevisitante].PontosGanhos += 3;
        }
    }

    //depois calcula gols average e o soldo de gols
    for(i = 0; i < notimes; i++) {
        timescampeonato[i].GolAverage = (timescampeonato[i].GolsSofridos == 0 
        ? timescampeonato[i].GolsMarcados
        : (float)timescampeonato[i].GolsMarcados / timescampeonato[i].GolsSofridos
        );
        timescampeonato[i].SaldoDeGols = timescampeonato[i].GolsMarcados - timescampeonato[i].GolsSofridos;
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
            //ordena por pontos ganhos
            if(aux.PontosGanhos < timescampeonato[i+1].PontosGanhos) {
                timescampeonato[i] = timescampeonato[i + 1];
                timescampeonato[i + 1] = aux;
            }
            else if (aux.PontosGanhos == timescampeonato[i+1].PontosGanhos) {
                //ordena por saldo de gols
                if(aux.SaldoDeGols < timescampeonato[i+1].SaldoDeGols) {
                    timescampeonato[i] = timescampeonato[i + 1];
                    timescampeonato[i + 1] = aux;
                }
                else if (aux.SaldoDeGols == timescampeonato[i+1].SaldoDeGols) {
                    //ordena por maior numero de vitorias
                    if(aux.Vitorias < timescampeonato[i+1].Vitorias) {
                        timescampeonato[i] = timescampeonato[i + 1];
                        timescampeonato[i + 1] = aux;
                    }
                }
            }
        }
    }

    printf("Posicao,Nome,Pontos Ganhos,Vitorias,Empates,Derrotas,Saldo de Gols,Gol Average\n");
    for(i=0; i < notimes;++i) {
        printf("%d,%s,%d,%d,%d,%d,%d,%0.3f\n", 
            i + 1,
            timescampeonato[i].nome,
            timescampeonato[i].PontosGanhos,
            timescampeonato[i].Vitorias,
            timescampeonato[i].Empates,
            timescampeonato[i].Derrotas,
            timescampeonato[i].SaldoDeGols,
            timescampeonato[i].GolAverage
        );
    }

}

// Salva os dados da classificação dos tipos em arquivo no disco
void salvaclassificacao(time * timescampeonato,int notimes, char * arquivo){
    //abrir arquivo para escrita
    FILE *arquivoC = fopen(arquivo, "w");
    if (arquivoC == NULL) {
        printf("Erro ao abrir o arquivo.");
    } else {
        // escrever cabeçalho no arquivo
        fprintf(arquivoC, "%-15s%-30s%-8s%-9s%-8s%-9s%-14s%-11s\n", "Classificacao", "Nome", "Pontos", "Vitorias", "Empates", "Derrotas", "Saldo de Gols", "Gol Average");

        // escrever informações dos times no arquivo
        for (int i = 0; i < notimes; i++) {
            fprintf(arquivoC, "%-15d%-30s%-8d%-9d%-8d%-9d%-14d%-9.3f\n",
                i + 1, timescampeonato[i].nome, timescampeonato[i].PontosGanhos,
                timescampeonato[i].Vitorias, timescampeonato[i].Empates, timescampeonato[i].Derrotas,
                timescampeonato[i].SaldoDeGols, timescampeonato[i].GolAverage);
        }

        // fechar o arquivo
        fclose(arquivoC);
    }
}

int main() {
  time times[NumeroMaxTimes];
  jogo jogos[NumeroMaxJogos];
  int i, nojogos, golslocal = 0, golsvisitante = 0;
  char local[30],visitante[30];

  printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
  for(i = 0; i < NumeroMaxJogos; ++i) {
    lenometime(local);
    lenometime(visitante);
    scanf("%d,%d",&golslocal,&golsvisitante);
    getchar(); // consome o enter do scanf
    if (golslocal < 0)
      break; // termina a entrada de dados

    if(strcmp(local,visitante) == 0)
      continue; // possui o mesmo nome time local e visitante

    strncpy(jogos[i].local,local,30);
    strncpy(jogos[i].visitante,visitante,30);

    jogos[i].golslocal = golslocal;
    jogos[i].golsvisitante = golsvisitante;
  }
  nojogos = i;

  int notimes = crialistatimes(times,jogos,nojogos);

  computadadostimes(times,notimes,jogos,nojogos);

  imprimeclassificacao(times,notimes);

  salvaclassificacao(times,notimes,"campeonatoIP.dat");
}