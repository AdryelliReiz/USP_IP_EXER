/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   Adryelli Reis dos Santos                   14714019           **/
/**                                                                 **/
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int diasdecadames[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int verificaAnoBissexto(int ano) {
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    return 1;
  else
    return 0;
}

int verificaDataValida(int d, int m, int a) {
  if (verificaAnoBissexto(a)) diasdecadames[1] = 29;

  if(d < 1 ||d > diasdecadames[m - 1] || m < 1 || m > 12 || a < 1) {
    return 0;
  }

  return 1;
}

void buscaOsDiasDeEncontro(int dia, int mes, int ano) {
  int clubes[5] = {2, 3, 4, 5, 6};  //Dias para cada clube se reunir novamente
  int diasdoanorestantes = 365;
  int i;

  if (verificaAnoBissexto(ano))
    diasdecadames[1] = 29;
    diasdoanorestantes = diasdoanorestantes + 1;
  
  //registra quantos dias até o termino do ano
  for (i = 0; i < mes - 1; i++) {
    diasdoanorestantes = diasdoanorestantes - diasdecadames[i];
  }

  diasdoanorestantes = diasdoanorestantes - dia;

  //percorre todos os dias do ano
  for (i = 1; i <= diasdoanorestantes; i++) {
    //incrementa cada dia a partir da data de inicio das aulas
    //até completar os dias restantes de aula
    dia++;
    if (dia > diasdecadames[mes - 1]) {
      dia = 1;
      mes++;
    }
        
    if (i % clubes[0] == 0 
        && i % clubes[1] == 0 
        && i % clubes[2] == 0 
        && i % clubes[3] == 0 
        && i % clubes[4] == 0
      ) {
        //vai dar merda na hora que o programa do professor corrigir se estiver assim ;-;
        //printf("%02d/%02d/%04d\n", dia, mes, ano);

        printf("%d/%d/%d\n", dia, mes, ano);
    }
  }
}

int main() {
    int dia, mes, ano;

    printf("Entre com a data de inicio do ano letivo:\n");
    printf("Entre com o dia: ");
    scanf("%d", &dia);
    printf("Entre com o mes: ");
    scanf("%d", &mes);
    printf("Entre com o ano: ");
    scanf("%d", &ano);

    if(!verificaDataValida(dia, mes, ano)) {
      printf("Dados incorretos\n");
      exit(1); // Esta função aborta a execução do programa.
    }
    
  // Adicione seu código
  printf("Data de inicio do ano letivo: %d/%d/%d\n", dia, mes, ano);
  printf("Proximos dias de encontro de todos os clubes:\n");
  buscaOsDiasDeEncontro(dia, mes, ano);

  return 0;
}