#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int relogio(float temp1;){

  int sec, min, hr;

  float diff = (clock() - temp1) / 10000000);
  printf("%d", diff);

  sec = diff/1000;
  min = sec/60;
  hr = min/60;


        printf("Cronometro\n\n");
        printf("\n\t\t\t\t%dh:%dm:%ds\n\n", hr,min,sec);
}

int monta_tabuleiro(int tabuleiro[16][16]){                                     // Função criada para montar o tabuleiro e definir os espaços desocupados como 0

  int i, j;

  for(i=0; i<16; i++){
    for(j=0; j<16; j++){

      tabuleiro[i][j] = 0;
    }
  }
}

void printa_tabuleiro (int tabuleiro[16][16]){

  int linha, coluna;

  printf("\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL \tM \tN \tO \tP");
  printf("\n\n");

  for(linha = 0; linha < 16; linha ++){
    printf("%d", linha+1);
    for(coluna = 0; coluna < 16; coluna ++){
      if(tabuleiro[linha][coluna] >= 0 && tabuleiro[linha][coluna] <= 4)
        printf("\t~");
        else if(tabuleiro[linha][coluna] == -1)
          printf("\t(*)");
        else if(tabuleiro[linha][coluna] == 5)
          printf("\tP1");
        else if(tabuleiro[linha][coluna] == 6)
          printf("\tC1");
        else if(tabuleiro[linha][coluna] == 7)
          printf("\tT1");
        else if(tabuleiro[linha][coluna] == 8)
          printf("\tH1");
     }
     printf("\n\n");
   }
  printf("\n");
}

int checar_variavel(int aux[16][16]){
  int i, j, verificar;

  for(i=0; i<16; i++){
    for(j=0; j<16; j++){
      if(aux[i][j] != 0)
        verificar = 1;
      }
  }
  return verificar;
}                                         // Criada para economizar linhas

int auxiliar_PortaAvioes(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16]){      // Criada para auxiliar na alocação dos porta-avioes
  int i, j, k;

    if(d==0){

      for(i=primeira_linha; i < primeira_linha+5; i++){                         // Visualizar se as posições reservadas ao porta-aviões estão desocupadas
        if(i == primeira_linha+2){                                              // essa parte seria a casa que liga "as duas pernas" do H
          for(j = primeira_coluna; j < primeira_coluna+3; j++){
              if(ordem == 0)
                aux[i][j] = tabuleiro[i][j];
                else if(ordem = 1)
                  tabuleiro[i][j] = 1;
           }
          }
          else{                                                                 //seriam as pernas normais do H: I I;
              for(j = primeira_coluna; j<primeira_coluna+3; j+=2){
                if(ordem == 0)
                  aux[i][j] = tabuleiro[i][j];
                  else if(ordem==1)
                    tabuleiro[i][j] = 1;
              }
            }
        }
    }

    if(d==1){

      for(j = primeira_coluna; j < primeira_coluna+5; j++){
        if(j == primeira_coluna+2){                                             // essa parte seria a casa que liga "as duas pernas" do H
          for(i = primeira_linha; i<primeira_linha+3; i++){
            if(ordem==0)
              aux[i][j] = tabuleiro[i][j];
              else if (ordem==1)
                tabuleiro[i][j] = 1;
          }
        }
          else{
            for(i=primeira_linha; i<primeira_linha+3; i+=2){
              if(ordem=0)
                aux[i][j] = tabuleiro[i][j];
                else if(ordem=1)
                  tabuleiro[i][j] = 1;
            }
          }
      }
    }
}

int definir_PortaAvioes(int tabuleiro[16][16]){

  int d1, ordem, e, i, j, primeira_linha1, primeira_coluna1, aux[16][16];

  d1 = rand() % 2;
  monta_tabuleiro(aux);  // ter certeza de que os valores atribuidos à auxiliar estão zerados

  if(d1==0){                                                                     // H em pe

    do{                                            // definir as posições do porta-avioes caso H seja "em pe"
      primeira_linha1 = rand() % 12;
      primeira_coluna1 = rand() % 14;
      e=0;
      monta_tabuleiro(aux);
      ordem = 0;

      auxiliar_PortaAvioes(aux, ordem, d1, primeira_linha1, primeira_coluna1, tabuleiro);

      e = checar_variavel(aux);
    }while ( e == 1);                                                           // verificar se os valores inseridos em primeira_linha e primeira_coluna são válidos ( se não há outro barco)

      ordem = 1;

      auxiliar_PortaAvioes(aux, ordem, d1, primeira_linha1, primeira_coluna1, tabuleiro);
  }


   if(d1==1){                                                                    // caso o porta-avioes esteja deitado

    do{
      primeira_linha1 = rand() % 14;
      primeira_coluna1 = rand() % 12;
      e=0;
      monta_tabuleiro(aux);
      ordem = 0;

      auxiliar_PortaAvioes(aux, ordem, d1, primeira_linha1, primeira_coluna1, tabuleiro);

      e = checar_variavel(aux);
      }while(e == 1);

      ordem=1;

      auxiliar_PortaAvioes(aux, ordem, d1, primeira_linha1, primeira_coluna1, tabuleiro);
   }
}

int auxiliar_Couracados(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16]){      // Criada para auxiliar na alocação dos couraçados

  int i, j;

  if(d==0){

    for(i=primeira_linha; i<primeira_linha+5; i++){
      for(j = primeira_coluna; j<primeira_coluna+2; j++){
        if(ordem==0)                                                            //Nessa hora seria revisado se a embarcação pode ser alocada no local definido
          aux[i][j]=tabuleiro[i][j];
          else if(ordem==1)
            tabuleiro[i][j] = 2;                                                //Aprovados os locais, agora os valores seriam definidos
      }
    }
  }

  if(d==1){

    for(i=primeira_linha; i<primeira_linha+2; i++){
      for(j=primeira_coluna; j<primeira_coluna+5; j++){
        if(ordem == 0)
          aux[i][j]=tabuleiro[i][j];
         else if (ordem == 1)
          tabuleiro[i][j] = 2;
      }
    }

  }
}

int definir_Couracados(int tabuleiro[16][16]){

  int d2, ordem, i, j, primeira_linha2, primeira_coluna2, aux[16][16], e;

  d2 = rand() % 2;

    if(d2==0){

      do{
        primeira_linha2 = rand() % 12;
        primeira_coluna2 = rand() % 15;
        e=0;
        ordem = 0;

        monta_tabuleiro(aux);

        auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro);

        e = checar_variavel(aux);
      }while(e == 1);

      ordem = 1;

      auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro);
    }

    if(d2==1){

      do{
        primeira_linha2 = rand() % 15;
        primeira_coluna2 = rand() % 12;
        e=0;
        ordem = 0;
        monta_tabuleiro(aux);

        auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro);

        e = checar_variavel(aux);
      }while(e == 1);

      ordem = 1;

      auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro);
    }
}

int auxiliar_Torpedeiro(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16]){
  int i, j;

  if(d==0){                                                                     // T está em pé
    for(i = primeira_linha; i < primeira_linha+5; i++){
      if(i == primeira_linha){                                                    //Os 3 lugares da ponta do T
        for(j = primeira_coluna; j < primeira_coluna+3; j++){
          if(ordem == 0)                                                        // Se ordem=0, estaremos verificando se os lugares estão ocupados
            aux[i][j] = tabuleiro[i][j];
            else if(ordem == 1)                                                 // Se ordem=1, estaremos atribuindo a posição à embarcação
              tabuleiro[i][j] = 3;
        }
      }
        else{                                                                   // As demais posições de T são formados por uma única casa
          for(j = primeira_coluna+1; j < primeira_coluna+2; j++){
            if(ordem == 0)
              aux[i][j] == tabuleiro[i][j];
              else if(ordem == 1)
                tabuleiro[i][j] = 3;
          }
        }
    }
  }


  if(d==1){                                                                     // T de "cabeça para baixo"
    for(i = primeira_linha; i < primeira_linha+5; i++){
      if(i == primeira_linha+4){
        for(j = primeira_coluna; j < primeira_coluna+3; j++){
          if(ordem == 0)
            aux[i][j] = tabuleiro[i][j];
              else if(ordem == 1)
                tabuleiro[i][j] = 3;
        }
      }
        else{
          for(j = primeira_coluna+1; j < primeira_coluna+2; j++){
            if(ordem == 0)
              aux[i][j] = tabuleiro[i][j];
               else if (ordem == 1)
                tabuleiro[i][j] = 3;
          }
        }
    }
  }

    if(d==2){                                                                   // T deitado pra direita
      for( i = primeira_linha; i < primeira_linha+3; i++){
        if(i == primeira_linha+1){
          for(j = primeira_coluna; j < primeira_coluna+5; j++){
            if(ordem == 0)
              aux[i][j] = tabuleiro[i][j];
              else if (ordem == 1)
                tabuleiro[i][j] = 3;
          }
        }
          else{
            j = primeira_coluna;
              if(ordem == 0)
                aux[i][j] = tabuleiro[i][j];
                  else if (ordem == 1)
                    tabuleiro[i][j] = 3;
          }
      }
    }

    if(d==3){                                                                   // T deitado pra esquerda
      for( i = primeira_linha; i < primeira_linha+3; i++){
        if(i == primeira_linha+1){
          for(j = primeira_coluna-4; j < primeira_coluna+1; j++){
            if(ordem == 0)
              aux[i][j] = tabuleiro[i][j];
              else if (ordem == 1)
                tabuleiro[i][j] = 3;
          }
        }
          else{
            j = primeira_coluna;
              if(ordem == 0)
                aux[i][j] = tabuleiro[i][j];
                  else if (ordem == 1)
                    tabuleiro[i][j] = 3;
              }
        }
    }
  }

int definir_Torpedeiro(int tabuleiro[16][16]){

  int d, ordem, i, j, primeira_linha, primeira_coluna, aux[16][16], e;

  d = rand() % 4;

    if(d==0 || d==1){

      do{
        primeira_linha = rand() % 12;
        primeira_coluna = rand() % 14 ;
        e=0;
        ordem = 0;

        monta_tabuleiro(aux);

        auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);
        e = checar_variavel(aux);
      }while(e == 1);

      ordem = 1;

      auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);

   }

   if(d==2 || d==3){

     do{
       primeira_linha = rand() % 14;
       primeira_coluna = rand() % 12;
       e=0;
       ordem = 0;

       monta_tabuleiro(aux);

       auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);
       e = checar_variavel(aux);
     }while(e == 1);

     ordem = 1;

     auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);
   }
}

int auxiliar_Hidroaviao(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16]){      // Criada para auxiliar na alocação dos Hidroavioes

  int i, j;

  if(d==0){

    for(i=primeira_linha; i<primeira_linha+4; i++){
      for(j = primeira_coluna; j<primeira_coluna+2; j++){
        if(ordem==0)                                                            //Nessa hora seria revisado se a embarcação pode ser alocada no local definido
          aux[i][j]=tabuleiro[i][j];
          else if(ordem==1)
            tabuleiro[i][j] = 4;                                                //Aprovados os locais, agora os valores seriam definidos
      }
    }
  }

  if(d==1){

    for(i=primeira_linha; i<primeira_linha+2; i++){
      for(j=primeira_coluna; j<primeira_coluna+4; j++){
        if(ordem == 0)
          aux[i][j]=tabuleiro[i][j];
         else if (ordem == 1)
          tabuleiro[i][j] = 4;
      }
    }

  }
}

int definir_Hidroaviao(int tabuleiro[16][16]){

  int d, ordem, i, j, primeira_linha, primeira_coluna, aux[16][16], e;

  d = rand() % 2;

    if(d==0){

      do{
        primeira_linha = rand() % 13;
        primeira_coluna = rand() % 15 ;
        e=0;
        ordem = 0;

        monta_tabuleiro(aux);

        auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);

        e = checar_variavel(aux);

      }while(e == 1);

      ordem = 1;

      auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);

    }

      if(d==1){

        do{
          primeira_linha = rand() % 15;
          primeira_coluna = rand() % 13;
          e=0;
          ordem = 0;
          monta_tabuleiro(aux);

          auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);

          e = checar_variavel(aux);
        }while(e == 1);

        ordem = 1;

        auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro);
      }
 }

int tiros(int tabuleiro[16][16], int tiro[16][16], int acertos){
  int i, j, linha, retorno;
  int proceder;
  char Nometiro[3], coluna;

    do{
      proceder = 0;
      printf("atire conforme o molde: pow(linha)(coluna) - ex: pow 15 A\n");
      scanf("%s %d %c", Nometiro, &linha, &coluna);

      i = linha - 1;
      j = coluna - 'A';
      retorno = strncmp(Nometiro,"pow" , 3);

      if(i>15 || j>15 || retorno != 0){
        proceder = 1;
        printf("Comando invalido!, tente de novo\n");
      }
      if(tiro[i][j] == 1){
        proceder = 1;
        printf("Tiro ja foi dado nesse lugar\n");
      }
    }while(proceder == 1);

    tiro[i][j] = 1;

      switch(tabuleiro[i][j])
      {
        case 1:
        tabuleiro[i][j] = 5;
        acertos++;
        break;

        case 2:
        tabuleiro[i][j] = 6;
        acertos++;
        break;

        case 3:
        tabuleiro[i][j] = 7;
        acertos++;
        break;

        case 4:
        tabuleiro[i][j] = 8;
        acertos++;
        break;

        case 0:
        tabuleiro[i][j] = -1;
        break;
      }
}


int main(){
  srand( (unsigned)time(NULL) );
  int tabuleiro1[16][16], vezes, tiro[16][16], acertos = 0, inicio;
  clock_t temp1;
  char comecar[7];

  monta_tabuleiro(tabuleiro1);
  monta_tabuleiro(tiro);
  definir_PortaAvioes(tabuleiro1);
  for(vezes = 0; vezes < 2; vezes ++){
    definir_Couracados(tabuleiro1);
  }
  for(vezes = 0; vezes  < 4; vezes ++){
    definir_Hidroaviao(tabuleiro1);
  }
  for(vezes = 0; vezes < 3; vezes++){
    definir_Torpedeiro(tabuleiro1);
  }
  printf("digite comecar\n");
  scanf("%s", comecar);
  inicio = strncmp(comecar, "comecar", 7);

  if(inicio == 0){
    temp1 = clock();
    do{
      relogio(temp1);
      printa_tabuleiro(tabuleiro1);
      tiros(tabuleiro1, tiro, acertos);
      inicio = 1;

    }while(acertos < 84);
  }
}
