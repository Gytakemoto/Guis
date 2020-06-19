aAvioes, resto_Couracados, resto_Torpedeiros, resto_Hidroavioes, acertos;
  double pontuacao;
};

int cronometro(double tempo){                                                   // Função criada para simular o cronômetro, que determinará o tempo decorrido do jogo;

  int sec=0;              #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct informacoes_do_jogador{
  int resto_Port                                                      // Definindo os segundos, os minutos e as horas;
  int min=0;
  int hr=0;

  sec = tempo;                                                                  // Definindo o tempo como 0, inicialmente;

  if(sec>=60){                                                                  // Condição para que quando os segundos atinga a marca de 60, acrescente 1 nos minutos e retorne o seu valor a zero;
    min = sec/60;
    sec = sec % 60;

  }

  if(min>=60){                                                                  // Condição para que quando os minutos atinga a marca de 60, acrescente 1 nas horas e retorne o seu valor a zero;
    hr = min/60;
    min = min % 60;
  }

  printf("Tempo decorrido de jogo:\n\n");

  printf("\n\t\t\t\t%dh:%dm:%ds\n\n", hr,min,sec);                              // Imprimindo o tempo decorrido de jogo;

  return 0;
}

int monta_tabuleiro(int tabuleiro[16][16]){                                     // Função criada para montar o tabuleiro e definir os espaços desocupados como 0

  int i, j;

  for(i=0; i<16; i++){                                                          // Definindo todos os espaços desocupados como 0;
    for(j=0; j<16; j++){

      tabuleiro[i][j] = 0;
    }
  }
}

void printa_tabuleiro (int tabuleiro[16][16]){                                  // Função criada para imprimir os tabuleiros de jogo na tela;

  int linha, coluna;

  printf("\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL \tM \tN \tO \tP");    // Definindo cada coluna por uma letra do alfabeto;
  printf("\n\n");

  for(linha = 0; linha < 16; linha ++){                                         // Enumerando as linhas;
    printf("%d", linha+1);
    for(coluna = 0; coluna < 16; coluna ++){
      if(tabuleiro[linha][coluna] >= 0 && tabuleiro[linha][coluna] <= 10)
        printf("\t~");                                                          // Definindo que, inicialmente, todo o tabuleiro irá estar coberto pelo símbolo que representará a água (~);
      else if(tabuleiro[linha][coluna] == -1)
        printf("\t(*)");                                                        // A cada tiro dado em um espaço sem alguma embarcação, o jogo deverá marcar aquela posição com um (*);
      else if(tabuleiro[linha][coluna] == 11)
        printf("\tP1");                                                         // Se o primeiro porta-aviões for atingido, o espaço deve ser preenchido por (P1);
      else if(tabuleiro[linha][coluna] == 12)
        printf("\tC1");                                                         // Se o primeiro couraçado for atingido, o espaço deverá ser preenchido por (C1);
      else if(tabuleiro[linha][coluna] == 13)
        printf("\tC2");                                                         // Se o segundo couraçado for atingido, o espaço deverá ser preenchido por (C2);
      else if(tabuleiro[linha][coluna] == 14)
        printf("\tT1");                                                         // Se o primeiro torpedeiro for atingido, o espaço deverá ser preenchido por (T1);
      else if(tabuleiro[linha][coluna] == 15)
        printf("\tT2");                                                         // Se o segundo torpedeiro for atingido, o espaço deverá ser preenchido por (T2);
      else if(tabuleiro[linha][coluna] == 16)
        printf("\tT3");                                                         // Se o terceiro torpedeiro for atingido, o espaço deverá ser preenchido por (T3);
      else if(tabuleiro[linha][coluna] == 17)
        printf("\tH1");                                                         // Se o primeiro hidroavião for atingido o espaço deverá ser preenchido por (H1);
      else if(tabuleiro[linha][coluna] == 18)
        printf("\tH2");                                                         // Se o segundo hidroavião for atingido o espaço deverá ser preenchido por (H2);
      else if(tabuleiro[linha][coluna] == 19)
        printf("\tH3");                                                         // Se o terceiro hidroavião for atingido o espaço deverá ser preenchido por (H3);
      else if(tabuleiro[linha][coluna] == 20)
        printf("\tH4");                                                         // Se o quarto hidroavião for atingido o espaço deverá ser preenchido por (H3);
     }
     printf("\n\n");
   }
  printf("\n");
}

int checar_variavel(int aux[16][16]){                                           // Função criada para não permitir sobreposições de embarcações no tabuleiro;
  int i, j, verificar;

  verificar = 0;

  for(i=0; i<16; i++){
    for(j=0; j<16; j++){
      if(aux[i][j] != 0)
        verificar = 1;                                                          // Se o espaço já estiver preenchido por alguma embarcação, o mesmo deve ser definido como 1;
      }
  }
  return verificar;}

int auxiliar_PortaAvioes(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16]){      // Criada para auxiliar na alocação dos porta-avioes
  int i, j, k;

    if(d==0){                                                                   // Condição que verifica se o porta-aviões será em pé;

      for(i=primeira_linha; i < primeira_linha+5; i++){
        if(i == primeira_linha+2){                                              // Condição para criar o unificador das "pernas do H", ou seja o ponto entre as (I I);
          for(j = primeira_coluna; j < primeira_coluna+3; j++){
              if(ordem == 0)                                                    // Verificar se as posições pretendidas para alocação cumprem os requisitos da inicição da alocação;
                aux[i][j] = tabuleiro[i][j];
              else if(ordem = 1)                                                // Caso cumpram os requisitos, a função alocará as posições e irá colocar o número representante em cada segmento da embarcação;
                tabuleiro[i][j] = 1;
           }
          }
          else{                                                                 // Condição que cria as "pernas do H em pé";
              for(j = primeira_coluna; j<primeira_coluna+3; j+=2){
                if(ordem == 0)                                                  // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
                  aux[i][j] = tabuleiro[i][j];
                else if(ordem==1)                                               // Se ordem = 1, os valores serão postos;
                  tabuleiro[i][j] = 1;
              }
            }
        }
    }

    if(d==1){                                                                   // Verificar se o porta-aviões será deitado;

      for(j = primeira_coluna; j < primeira_coluna+5; j++){
        if(j == primeira_coluna+2){                                             // Condição para criar o unificador das "pernas do H", ou seja o ponto entre as (I I);
          for(i = primeira_linha; i<primeira_linha+3; i++){
            if(ordem==0)                                                        // Declarar à função auxiliar que ela deve fazer o processo de verificação dos espaços alocados;
              aux[i][j] = tabuleiro[i][j];
            else if (ordem==1)                                                  // Declarar à função auxiliar que ela aloque as posições e as preencha com o seu número representante;
              tabuleiro[i][j] = 1;
          }
        }
          else{                                                                 // Condição que cria as "pernas do H deitado";
            for(i=primeira_linha; i<primeira_linha+3; i+=2){
              if(ordem=0)                                                       // Procedimento similar ao anterior;
                aux[i][j] = tabuleiro[i][j];
              else if(ordem=1)                                                  // Procedimento similar ao anterior;
                tabuleiro[i][j] = 1;
            }
          }
      }
    }
}

int definir_PortaAvioes(int tabuleiro[16][16]){                                 // Função criada para definir os porta-aviões;

  int d1, ordem, e, i, j, primeira_linha1, primeira_coluna1, aux[16][16];

  d1 = rand() % 2;                                                              // Definindo, de forma aleatória, se o porta-aviões será alocado em pé ou deitado;
  monta_tabuleiro(aux);                                                         // Conferir se os valores atribuidos à auxiliar estão zerados;

  if(d1==0){                                                                    // Definir as posições do porta-avioes caso H seja "em pe"

    do{
      primeira_linha1 = rand() % 12;                                            // Definir que, se o porta-aviões estiver em pé, deve começar a ser alocado antes da linha 12;
      primeira_coluna1 = rand() % 14;                                           // Definir que, se o porta-aviões estiver em pé, deve começar a ser alocado antes da coluna 14;
      e=0;
      monta_tabuleiro(aux);                                                     // Zerar os valores da matriz auxiliar;
      ordem = 0;                                                                // Se ordem = 0, o procedimento realizado pela variável auxiliar deverá ser apenas de checagem;

      auxiliar_PortaAvioes(aux, ordem, d1, primeira_linha1, primeira_coluna1, tabuleiro); // Pré-definir as posições a serem alocadas, por meio da matriz auxiliar, que será submetida a uma checagem a seguir;

      e = checar_variavel(aux);                                                 // Conferir se os espaços que a auxiliar porta-aviões tomou para si estão vazios, para dar sequência ao processo do código;
    }while ( e == 1);                                                           // Se os valores conferidos à auxiliar porta-aviões estiverem vazios e cumprirem com os requisitos para inicição da alocação das posições, o código pode prosseguir;

      ordem = 1;                                                                // Se ordem = 1, os portas aviões poderão ser alocados nos espaços, o que ocorrerá a seguir;

      auxiliar_PortaAvioes(aux, ordem, d1, primeira_linha1, primeira_coluna1, tabuleiro); // Alocar as posições para o porta-aviões;
  }


   if(d1==1){                                                                   // Caso o porta-aviões esteja posicionado deitado, o procedimento é similar ao anterior;

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

int auxiliar_Couracados(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16], int vezes){      // Criada para auxiliar na alocação dos Couraçados;

  int i, j;

  if(d==0){                                                                     // Condição que verifica se o Couraçado está em pé;

    for(i=primeira_linha; i<primeira_linha+5; i++){                             // Delimitando as posições dos couraçados;
      for(j = primeira_coluna; j<primeira_coluna+2; j++){
        if(ordem==0)                                                            // Se ordem = 0, a matriz aux irá ocupar os seguintes espaços determinados ;
          aux[i][j] = tabuleiro[i][j];
        else if(ordem==1){                                                      // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
            switch(vezes){

              case 0:
                tabuleiro[i][j] = 2;                                              // Após serem alocadas as posições para os couraçados, tais serão representadas pelo número 2 ou 3 (dependendo de qual couraçado for);
              break;

              case 1:
                tabuleiro[i][j] = 3;
              break;
            }
        }
      }
    }
  }

  if(d==1){                                                                     // Caso os couraçados estejam deitados;

    for(i=primeira_linha; i<primeira_linha+2; i++){                             // Delimitando as posições dos couraçados;
      for(j=primeira_coluna; j<primeira_coluna+5; j++){
        if(ordem == 0)                                                          // Se ordem = 0, a matriz aux irá ocupar os seguintes espaços determinados ;
          aux[i][j]=tabuleiro[i][j];
          else if(ordem==1){                                                    // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
              switch(vezes){

                case 0:
                  tabuleiro[i][j] = 2;                                            // Após serem alocadas as posições para os couraçados, tais serão representadas pelo número 2 ou 3 (dependendo de qual couraçado for);
                break;

                case 1:
                  tabuleiro[i][j] = 3;
                break;
              }
          }
      }
    }

  }
}

int definir_Couracados(int tabuleiro[16][16], int vezes){                       // Função criada para definir os Couraçados;

  int d2, ordem, i, j, primeira_linha2, primeira_coluna2, aux[16][16], e;

  d2 = rand() % 2;                                                              // Definindo, de forma aleatória, se os Couraçados serão alocados em pé ou deitados;

    if(d2==0){                                                                  // Condição que verifica se os Couraçados estão em pé;

      do{                                                                       // Definindo os limites do início da alocação dos Couraçados;
        primeira_linha2 = rand() % 12;
        primeira_coluna2 = rand() % 15;
        e=0;
        ordem = 0;

        monta_tabuleiro(aux);                                                   // Zerar os valores da matriz auxiliar;

        auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro, vezes); // Pré-definir as posições a serem alocadas, por meio da matriz auxiliar, que será submetida a uma checagem a seguir;

        e = checar_variavel(aux);                                               // Conferir se os espaços que o couraçado tomou para si estão vazios, para dar sequência ao processo do código;

      }while(e == 1);                                                           // Se os valores conferidos à auxiliar porta-aviões estiverem vazios e cumprirem com os requisitos para inicição da alocação das posições, o código pode prosseguir;

      ordem = 1;                                                                // Se ordem = 1, os couraçados poderão ser alocados nos espaços, o que ocorrerá a seguir;

      auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro, vezes); // Alocas as posições para os Couraçados;
    }

    if(d2==1){                                                                  // Condição que verifica se os Couraçados estão deitados;

      do{                                                                       // Todo o procedimento seguinte é similar ao da condição anterior;
        primeira_linha2 = rand() % 15;
        primeira_coluna2 = rand() % 12;
        e=0;
        ordem = 0;
        monta_tabuleiro(aux);

        auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro, vezes);

        e = checar_variavel(aux);
      }while(e == 1);

      ordem = 1;

      auxiliar_Couracados(aux, ordem, d2, primeira_linha2, primeira_coluna2, tabuleiro, vezes);
    }
}

int auxiliar_Torpedeiro(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16], int vezes){ // Função criada para auxiliar na alocação das posições destinadas aos Torpedeiros;
  int i, j;

  if(d==0){                                                                     // Caso os Torpedeiros sejam alocados em pé;
    for(i = primeira_linha; i < primeira_linha+5; i++){                         // Alocando a "haste" dos Torpedeiros;
      if(i == primeira_linha){                                                  // Se a linha for a "cabeça do T..."
        for(j = primeira_coluna; j < primeira_coluna+3; j++){                   // Alocando a parte superior do T, perpendicular a haste;
          if(ordem == 0){                                                        // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
            aux[i][j] = tabuleiro[i][j];
          }
          else if(ordem == 1){                                                  // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;

            switch(vezes){

              case 0:
                tabuleiro[i][j] = 4;                                              // Após serem alocadas as posições para os couraçados, tais serão representadas pelo número 4, 5 ou 6 (T1, T2, T3);
              break;

              case 1:
                tabuleiro[i][j] = 5;
              break;

              case 2:
                tabuleiro[i][j] = 6;
              break;
            }
          }
        }
      }
        else{                                                                   // Agora as linhas da haste do T serão selecionadas;
          j = primeira_coluna+1;
            if(ordem == 0)                                                      // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
              aux[i][j] = tabuleiro[i][j];
            else if(ordem == 1){                                                // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
              switch(vezes){                                                    // Após serem alocadas as posições para os couraçados, tais serão representadas pelo número 4, 5 ou 6 (T1, T2, T3);

                case 0:
                  tabuleiro[i][j] = 4;
                break;

                case 1:
                  tabuleiro[i][j] = 5;
                break;

                case 2:
                  tabuleiro[i][j] = 6;
                break;
              }
            }
        }
    }
  }


  if(d==1){                                                                     // Caso os Torpedeiros sejam alocados de "cabeça pra baixo";
    for(i = primeira_linha; i < primeira_linha+5; i++){
      if(i == primeira_linha+4){                                                // Linha que seria a "cabeça do T";
        for(j = primeira_coluna; j < primeira_coluna+3; j++){
          if(ordem == 0)                                                        // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
            aux[i][j] = tabuleiro[i][j];
          else if(ordem == 1){                                                  // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
            switch(vezes){

              case 0:
                tabuleiro[i][j] = 4;
              break;

              case 1:
                tabuleiro[i][j] = 5;
              break;

              case 2:
                tabuleiro[i][j] = 6;
              break;
            }
          }
        }
      }
        else{                                                                   // Definindo a "haste"
          j = primeira_coluna+1;
            if(ordem == 0)                                                      // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
              aux[i][j] = tabuleiro[i][j];
              else if(ordem == 1){                                              // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
                switch(vezes){

                  case 0:
                    tabuleiro[i][j] = 4;
                  break;

                  case 1:
                    tabuleiro[i][j] = 5;
                  break;

                  case 2:
                    tabuleiro[i][j] = 6;
                  break;
                }
              }
        }
    }
  }

    if(d==2){                                                                   // Caso os Torpedeiros sejam deitados para a esquerda;
      for( i = primeira_linha; i < primeira_linha+3; i++){
        if(i == primeira_linha+1){                                              // As posições da "cabeça do T";
          for(j = primeira_coluna; j < primeira_coluna+5; j++){
            if(ordem == 0)                                                      // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
              aux[i][j] = tabuleiro[i][j];
              else if(ordem == 1){                                              // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
                switch(vezes){

                  case 0:
                    tabuleiro[i][j] = 4;
                  break;

                  case 1:
                    tabuleiro[i][j] = 5;
                  break;

                  case 2:
                    tabuleiro[i][j] = 6;
                  break;
                }
              }
          }
        }
          else{
            j = primeira_coluna;
              if(ordem == 0)                                                    // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
                aux[i][j] = tabuleiro[i][j];
              else if(ordem == 1){                                            // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
                switch(vezes){

                  case 0:
                    tabuleiro[i][j] = 4;
                  break;

                  case 1:
                    tabuleiro[i][j] = 5;
                  break;

                  case 2:
                    tabuleiro[i][j] = 6;
                  break;
                }
              }
          }
      }
    }

    if(d==3){                                                                   // Caso os Torpedeiros sejam deitados para a direita;
      for( i = primeira_linha; i < primeira_linha+3; i++){
        if(i == primeira_linha+1){
          for(j = primeira_coluna; j < primeira_coluna+5; j++){
            if(ordem == 0)                                                      // Similar aos anteriores;
              aux[i][j] = tabuleiro[i][j];
            else if(ordem == 1){
              switch(vezes){

                case 0:
                  tabuleiro[i][j] = 4;
                break;

                case 1:
                  tabuleiro[i][j] = 5;
                break;

                case 2:
                  tabuleiro[i][j] = 6;
                break;
              }
            }
          }
        }
          else{
            j = primeira_coluna+4;
              if(ordem == 0)                                                    // Similar aos anteriores;
                aux[i][j] = tabuleiro[i][j];
              else if(ordem == 1){
                switch(vezes){

                  case 0:
                    tabuleiro[i][j] = 4;
                  break;

                  case 1:
                    tabuleiro[i][j] = 5;
                  break;

                  case 2:
                    tabuleiro[i][j] = 6;
                  break;
                }
              }
            }
        }
    }
  }

int definir_Torpedeiro(int tabuleiro[16][16], int vezes){                                  // Função criada para definir os limites da iniciação da alocação dos espaços para os Torpedeiros;

  int d, ordem, i, j, primeira_linha, primeira_coluna, aux[16][16], e;

  d = rand() % 4;                                                               // Definindo, de forma aleatória, se os Torpedeiros serão alocados em suaa posição normal, "de cabeça para baixo", ou deitados para esquerda ou direita;

    if(d==0 || d==1){                                                           // Condição que verifica se os Torpedeiros estão em pé, ou de cabeça para baixo;

      do{                                                                       // Definindo os limites para a alocação das primeiras posições dos Torpedeiros;
        primeira_linha = rand() % 12;
        primeira_coluna = rand() % 14 ;
        e=0;
        ordem = 0;

        monta_tabuleiro(aux);                                                   // Zerar os valores da matriz auxiliar;

        auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes); // Pré-definir as posições a serem alocadas, por meio da matriz auxiliar, que será submetida a uma checagem a seguir;

        e = checar_variavel(aux);                                               // Conferir se os espaços que o torpedeiro tomou para si estão vazios, para dar sequência ao processo do código;

      }while(e == 1);                                                           // Conferir se os espaços que a auxiliar torpedeiro tomou para si estão vazios, para dar sequência ao processo do código;

      ordem = 1;                                                                // Se ordem = 1, os torpedeiros poderão ser alocados nos espaços, o que ocorrerá a seguir;

      auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes); // Alocando as posições para os Torpedeiros;

   }

   if(d==2 || d==3){                                                            // Condição que verifica se os Torpedeiros estão deitados para esquerda ou para a direita;

     do{                                                                        // Processo similar ao da condição anterior;
       primeira_linha = rand() % 14;
       primeira_coluna = rand() % 12;
       e=0;
       ordem = 0;

       monta_tabuleiro(aux);

       auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes);

       e = checar_variavel(aux);

     }while(e == 1);

     ordem = 1;

     auxiliar_Torpedeiro(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes);
   }
}

int auxiliar_Hidroaviao(int aux[16][16], int ordem, int d, int primeira_linha, int primeira_coluna, int tabuleiro[16][16], int vezes){  // Função criada para auxiliar na alocação dos Hidroaviões;

  int i, j;

  if(d==0){                                                                     // Condição que verifica se os hidroaviões estão em pé;

    for(i=primeira_linha; i<primeira_linha+4; i++){                             // Dimensionamento dos hidroaviões;
      for(j = primeira_coluna; j<primeira_coluna+2; j++){
        if(ordem==0)                                                            // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
          aux[i][j]=tabuleiro[i][j];
          else if(ordem == 1){                                                  // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
            switch(vezes){

              case 0:
                tabuleiro[i][j] = 7;                                              // Após serem alocadas as posições para os hidro-aviõess, tais serão representadas pelo número 7, 8, 9 ou 10 (H1, H2, H3, H4);
              break;

              case 1:
                tabuleiro[i][j] = 8;
              break;

              case 2:
                tabuleiro[i][j] = 9;
              break;

              case 3:
                tabuleiro[i][j] = 10;
              break;
            }
          }
      }
    }
  }

  if(d==1){                                                                     // Condição que verifica se os hidroaviões estão deitados;

    for(i=primeira_linha; i<primeira_linha+2; i++){                             // Procedimento similar ao anterior;
      for(j=primeira_coluna; j<primeira_coluna+4; j++){
        if(ordem == 0)                                                          // Se ordem = 0, haverá a verificação dos espaços para ver se estão desocupados;
          aux[i][j]=tabuleiro[i][j];
        else if(ordem == 1){                                                    // Se ordem = 1, os couraçados irão, de fato, ocupar as posições propostas;
          switch(vezes){

            case 0:
              tabuleiro[i][j] = 7;
            break;

            case 1:
              tabuleiro[i][j] = 8;
            break;

            case 2:
              tabuleiro[i][j] = 9;
            break;

            case 3:
              tabuleiro[i][j] = 10;
            break;
          }
        }
      }
    }
  }
}

int definir_Hidroaviao(int tabuleiro[16][16], int vezes){                                  // Função criada para definir os limites para a iniciação da alocação das posições dos hidroaviões;

  int d, ordem, i, j, primeira_linha, primeira_coluna, aux[16][16], e;

  d = rand() % 2;                                                               // Definindo, aleatoriamente, se os hidroaviões serão alocadas em pé ou deitados;

    if(d==0){                                                                   // Condição que verifica se os hidroaviões estão em pé;

      do{                                                                       // Definindo os limites para a iniciação das posições dos hidroaviões em pé;
        primeira_linha = rand() % 13;
        primeira_coluna = rand() % 15 ;
        e=0;
        ordem = 0;

        monta_tabuleiro(aux);                                                   // Zerar os valores da matriz auxiliar;

        auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes); // Pré-definir as posições a serem alocadas, por meio da matriz auxiliar, que será submetida a uma checagem a seguir;

        e = checar_variavel(aux);                                               // Conferir se os espaços que o torpedeiro tomou para si estão vazios, para dar sequência ao processo do código;

      }while(e == 1);                                                           // Conferir se os espaços que a auxiliar hidro-aviões tomou para si estão vazios, para dar sequência ao processo do código;

      ordem = 1;                                                                // Se ordem = 1, os torpedeiros poderão ser alocados nos espaços, o que ocorrerá a seguir

      auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes); // Alocando a posição dos hidroaviões;

    }

      if(d==1){                                                                 // Condição que verifica se os hidroaviões estão deitados;

        do{                                                                     // Procedimento similar ao anterior;
          primeira_linha = rand() % 15;
          primeira_coluna = rand() % 13;
          e=0;
          ordem = 0;
          monta_tabuleiro(aux);

          auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes);

          e = checar_variavel(aux);
        }while(e == 1);

        ordem = 1;

        auxiliar_Hidroaviao(aux, ordem, d, primeira_linha, primeira_coluna, tabuleiro, vezes);
      }
 }

int tiros(int tabuleiro[16][16], int tiro[16][16], struct informacoes_do_jogador *jogador){ // Função criada para auxiliar no comando que atira;
  int i, j, linha, retorno;
  int proceder;
  char Nometiro[3], coluna;

    do{
      proceder = 0;
      printf("Atire conforme o molde: (linha)(coluna) - ex: 15A\n");
      scanf("%d %c", &linha, &coluna);

      i = linha - 1;
      j = coluna - 'A';                                                         // "Traduzindo" as letras para números, por meio da tabela ascii;

      if(i>15 || j>15){                                                         // Verificar se a entrada é válida
        proceder = 1;
        printf("Comando invalido!, tente de novo\n\n");
      }
      if(tiro[i][j] == 1){                                                      // Verifica se já atiraram na posição determinada;
        proceder = 1;
        printf("Tiro ja foi dado nesse lugar\n\n");
      }
    }while(proceder == 1);                                                      // Ficar no loop enquanto a entrada for inválida;

    tiro[i][j] = 1;                                                             // Se tiro[i][j] = 1, o tiro já foi dado nesse lugar;

    if(tabuleiro[i][j] == 1){                                                   //Porta-aviões;
      tabuleiro[i][j] = 11;
      (jogador->acertos)++;
      jogador->pontuacao = jogador->pontuacao + (11*(jogador->resto_PortaAvioes)*100)/256;
      (jogador->resto_PortaAvioes)--;
    }

    else if(tabuleiro[i][j] == 2 || tabuleiro[i][j] == 3){                      //Couraçados (abrange C1 e C2);
      if(tabuleiro[i][j] == 2)
        tabuleiro[i][j] = 12;                                                   //C1;
      else if(tabuleiro[i][j] == 3)
        tabuleiro[i][j] = 13;                                                   //C2;
      (jogador->acertos)++;
      jogador->pontuacao = jogador->pontuacao + (10*(jogador->resto_Couracados)*100)/256;
      (jogador->resto_Couracados)--;
    }

    else if(tabuleiro[i][j] >= 4 && tabuleiro[i][j] <= 6){                      // Torpedeiros (abrange T1, T2, T3 e T4);
      if(tabuleiro[i][j] == 4)
        tabuleiro[i][j] = 14;                                                   //T1;
      else if(tabuleiro[i][j] == 5)
        tabuleiro[i][j] = 15;                                                   //T2;
      else if(tabuleiro[i][j] == 6)
        tabuleiro[i][j] = 16;                                                   //T3;
      (jogador->acertos)++;
      jogador->pontuacao = jogador->pontuacao + (7*(jogador->resto_Torpedeiros)*100)/256;
      (jogador->resto_Torpedeiros)--;
    }

    else if(tabuleiro[i][j] >= 7 && tabuleiro[i][j] <= 10){                     // Hidro-aviões (abrange H1, H2, H3 e H4) ;
      if(tabuleiro[i][j] == 7)
        tabuleiro[i][j] = 17;                                                   //H1;
      else if(tabuleiro[i][j] == 8)
        tabuleiro[i][j] = 18;                                                   //H2;
      else if(tabuleiro[i][j] == 9)
        tabuleiro[i][j] = 19;                                                   //H3;
      else if(tabuleiro[i][j] == 10)
        tabuleiro[i][j] = 20;                                                   //H4;
      (jogador->acertos)++;
      jogador->pontuacao = jogador->pontuacao + (8*(jogador->resto_Hidroavioes)*100)/256;
      (jogador->resto_Hidroavioes)--;
    }

    if(tabuleiro[i][j] == 0){                                                   // Acerta a água;
      tabuleiro[i][j] = -1;
      jogador->pontuacao = jogador->pontuacao - (172*5)/256;
    }

    printf("TABULEIRO DO OPONENTE\n\n");
    printa_tabuleiro(tabuleiro);

}

int help(){                                                                     // Função que imprime as instruções dos comandos na tela;

  printf("----------------------------------------------------------------------\n");
  printf("comandos:\n");
  printf("1-pow: atira\n");
  printf("2-reset: inicia uma nova partida e volta ao estado inicial, reiniciando a pontuacao e o tempo no relogio\n");
  printf("3-sair: encerra o jogo\n");
  printf("4-acaso: inicia um novo tabuleiro aleatorio, conserva seus pontos e tempo no relogio\n");
  printf("5-salvar: salva o jogo\n");
  printf("6-carregar: carrega um jogo salvo\n");
  printf("----------------------------------------------------------------------\n");

}

void salvar_jogo(int tabuleiro1[16][16], int tiro1[16][16], double *tempo, int tabuleiro2[16][16], int tiro2[16][16], struct informacoes_do_jogador *jogador1, struct informacoes_do_jogador *jogador2){ // Função criada para salvar o progresso do jogo em (.bin);

  char NomeDoJogo[50];

    struct tm *hora_atual;
    time_t segundos;
    time(&segundos);

    hora_atual = localtime(&segundos);

    sprintf(NomeDoJogo, "tabuleiro-%d-%d-%d_%d_%d_%d.bin", hora_atual->tm_mday, hora_atual->tm_mon+1, hora_atual->tm_year+1900, hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);     // Salvando o arquvo de acordo com o horário do sistema;

    FILE *arquivo_criado;
    arquivo_criado = fopen(NomeDoJogo, "w");

    if(arquivo_criado == NULL){
      printf("Erro ao salvar! Tente novamente\n");
      perror("");
    }
    else
      printf("O arquivo foi salvo como %s!\n", NomeDoJogo);

  fwrite(tabuleiro1, 256, sizeof(int), arquivo_criado);                         // Armazenando cada variável;
  fwrite(tiro1, 256, sizeof(int), arquivo_criado);
  fwrite(tempo, 1, sizeof(double), arquivo_criado);
  fwrite(tabuleiro2, 256, sizeof(int), arquivo_criado);
  fwrite(tiro2, 256, sizeof(int), arquivo_criado);
  fwrite(jogador1, 1, sizeof(struct informacoes_do_jogador), arquivo_criado);
  fwrite(jogador2, 1, sizeof(struct informacoes_do_jogador), arquivo_criado);
  fclose(arquivo_criado);
}

int carregar_jogo(int tabuleiro1[16][16], int tiro1[16][16], double *tempo, int tabuleiro2[16][16], int tiro2[16][16], struct informacoes_do_jogador *jogador1, struct informacoes_do_jogador *jogador2){ // Função criada para carregar o jogo salvo;

  char NomeDoJogo[50];

  printf("Digite o arquivo que deseja abrir (inclua o .bin):\n");
  scanf(" %[^\n]%*c", NomeDoJogo);

  FILE *arquivo_criado;
  arquivo_criado = fopen(NomeDoJogo, "r");

  if(arquivo_criado == NULL){
    printf("Erro ao abrir arquivo, verifique se ele realmente existe!\n");
    return 1;
  }

  fread(tabuleiro1, 256, sizeof(int), arquivo_criado);                          // Carregando as variáveis;
  fread(tiro1, 256, sizeof(int), arquivo_criado);
  fread(tempo, 1, sizeof(double), arquivo_criado);
  fread(tabuleiro2, 256, sizeof(int), arquivo_criado);
  fread(tiro2, 256, sizeof(int), arquivo_criado);
  fread(jogador1, 1, sizeof(struct informacoes_do_jogador), arquivo_criado);
  fread(jogador2, 1, sizeof(struct informacoes_do_jogador), arquivo_criado);
  fclose(arquivo_criado);
  printf("jogo carregado!\n");
}

void sair_jogo(){                                                               // Sai do jogo;
  exit (0);
}

void monta_jogo(int tabuleiro[16][16], int tiro[16][16]){                       // Reseta as configurações da matriz tabuleiro e da matriz tiro. Usado para as funções 'reset" e "acaso";

  int vezes;
  monta_tabuleiro(tabuleiro);                                                   // Reiniciando o tabuleiro e...
  monta_tabuleiro(tiro);                                                        // ...os tiros à estaca zero
  definir_PortaAvioes(tabuleiro);                                               // Definindo as novas embarcações
  for(vezes = 0; vezes < 2; vezes ++){
    definir_Couracados(tabuleiro, vezes);
  }
  for(vezes = 0; vezes  < 4; vezes ++){
    definir_Hidroaviao(tabuleiro, vezes);
  }
  for(vezes = 0; vezes < 3; vezes++){
    definir_Torpedeiro(tabuleiro, vezes);
  }
}

void cheat(int tabuleiro1[16][16], int tabuleiro2[16][16]){                                                          // Mostra todo o tabuleiro;

  char password[10];
  int linha, coluna, jogador;

  printf("Digite a senha:\n");

  scanf(" %[^\n]%*c", password);

  if(strncmp(password, "password", 9) == 0){

    for(jogador = 1; jogador < 3; jogador++){

      if(jogador == 1){
        printf("\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL \tM \tN \tO \tP");
        printf("\n\n");

        for(linha = 0; linha < 16; linha ++){
          printf("%d", linha+1);
          for(coluna = 0; coluna < 16; coluna ++){
            if(tabuleiro1[linha][coluna] == 0)
              printf("\t~");
            else if(tabuleiro1[linha][coluna] == -1)
              printf("\t(*)");
            else if(tabuleiro1[linha][coluna] == 1 || tabuleiro1[linha][coluna] == 11)
              printf("\tP1");
            else if(tabuleiro1[linha][coluna] == 2 || tabuleiro1[linha][coluna] == 12)
              printf("\tC1");
            else if(tabuleiro1[linha][coluna] == 3 || tabuleiro1[linha][coluna] == 13)
              printf("\tC2");
            else if(tabuleiro1[linha][coluna] == 4 || tabuleiro1[linha][coluna] == 14)
              printf("\tT1");
            else if(tabuleiro1[linha][coluna] == 5 || tabuleiro1[linha][coluna] == 15)
              printf("\tT2");
            else if(tabuleiro1[linha][coluna] == 6 || tabuleiro1[linha][coluna] == 16)
              printf("\tT3");
            else if(tabuleiro1[linha][coluna] == 7 || tabuleiro1[linha][coluna] == 17)
              printf("\tH1");
            else if(tabuleiro1[linha][coluna] == 8 || tabuleiro1[linha][coluna] == 18)
              printf("\tH2");
            else if(tabuleiro1[linha][coluna] == 9 || tabuleiro1[linha][coluna] == 19)
              printf("\tH3");
            else if(tabuleiro1[linha][coluna] == 10 || tabuleiro1[linha][coluna] == 20)
              printf("\tH4");
            }
            printf("\n\n");
          }
          printf("\n");
        }
        else{
          printf("\tA \tB \tC \tD \tE \tF \tG \tH \tI \tJ \tK \tL \tM \tN \tO \tP");
          printf("\n\n");

          for(linha = 0; linha < 16; linha ++){
            printf("%d", linha+1);
            for(coluna = 0; coluna < 16; coluna ++){
              if(tabuleiro2[linha][coluna] == 0)
                printf("\t~");
              else if(tabuleiro2[linha][coluna] == -1)
                printf("\t(*)");
              else if(tabuleiro2[linha][coluna] == 1 || tabuleiro2[linha][coluna] == 11)
                printf("\tP1");
              else if(tabuleiro2[linha][coluna] == 2 || tabuleiro2[linha][coluna] == 12)
                printf("\tC1");
              else if(tabuleiro2[linha][coluna] == 3 || tabuleiro2[linha][coluna] == 13)
                printf("\tC2");
              else if(tabuleiro2[linha][coluna] == 4 || tabuleiro2[linha][coluna] == 14)
                printf("\tT1");
              else if(tabuleiro2[linha][coluna] == 5 || tabuleiro2[linha][coluna] == 15)
                printf("\tT2");
              else if(tabuleiro2[linha][coluna] == 6 || tabuleiro2[linha][coluna] == 16)
                printf("\tT3");
              else if(tabuleiro2[linha][coluna] == 7 || tabuleiro2[linha][coluna] == 17)
                printf("\tH1");
              else if(tabuleiro2[linha][coluna] == 8 || tabuleiro2[linha][coluna] == 18)
                printf("\tH2");
              else if(tabuleiro2[linha][coluna] == 9 || tabuleiro2[linha][coluna] == 19)
                printf("\tH3");
              else if(tabuleiro2[linha][coluna] == 10 || tabuleiro2[linha][coluna] == 20)
                printf("\tH4");
              }
              printf("\n\n");
            }
            printf("\n");
        }
      }
  }

  else
    printf("Voce errou a senha! :P\n");

}

int menu1(int tabuleiro1[16][16], int tiro1[16][16], double *tempo, time_t *t_ini, double *tempo_salvo, int tabuleiro2[16][16], int tiro2[16][16], struct informacoes_do_jogador *jogador1, struct informacoes_do_jogador *jogador2){     // Função que irá receber o comando

  char comando[8];

  for(;;){

    printf("Digite seu comando. Para exibir os comandos, digite help\n");

    scanf("%s", comando);

      if(strncmp(comando, "pow", 3) == 0){                                                // Comando utilizado para atirar;
        tiros(tabuleiro2, tiro2, jogador1);
        return 0;
      }
      else if(strncmp(comando, "help", 4) == 0)                                           // Comando para solicitar ajuda;
          help();
      else if(strncmp(comando, "salvar", 6) == 0)                                         // Comando para salvar o jogo;
        salvar_jogo(tabuleiro1, tiro1, tempo, tabuleiro2, tiro2, jogador1, jogador2);
      else if(strncmp(comando, "carregar", 8) == 0){                                      // Comando para carregar o jogo;
        carregar_jogo(tabuleiro1, tiro1, tempo, tabuleiro2, tiro2, jogador1, jogador2);
        *tempo_salvo = *tempo;                                                            // Atualizando o valor do tempo, que será influenciado pelotempo_salvo do antigo jogo;
        *t_ini = time(NULL);                                                              // A partir de agora, o tempo inicial a ser considerado será diferente;
        cronometro(*tempo_salvo);
        printa_tabuleiro(tabuleiro2);
        printa_tabuleiro(tabuleiro1);
      }
      else if(strncmp(comando, "sair", 4) == 0)                                          // Comando para finalizar o jogo;
        sair_jogo();
      else if(strncmp(comando, "reset", 5) == 0){                                        // Comando para reiniciar o jogo;
        monta_jogo(tabuleiro1, tiro1);
        monta_jogo(tabuleiro2, tiro2);
        printa_tabuleiro(tabuleiro2);
        printa_tabuleiro(tabuleiro1);
          *tempo_salvo = 0;                                                             // reiniciando todos as variáveis de jogo;
          *tempo = 0;                                                                   //...contador e tempo;
          *t_ini = time(NULL);                                                          //...acertos;
          jogador1->acertos = 0;                                                        //...número de embarcações restantes;
          jogador2->acertos = 0;
          jogador1->resto_PortaAvioes = 11;
          jogador2->resto_PortaAvioes = 11;
          jogador1->resto_Couracados = 20;
          jogador2->resto_Couracados = 20;
          jogador1->resto_Torpedeiros = 21;
          jogador2->resto_Torpedeiros = 21;
          jogador1->resto_Hidroavioes = 32;
          jogador2->resto_Hidroavioes = 32;

      }
      else if(strncmp(comando, "acaso", 5) == 0){                                       // Comando utilizado para criar um novo tabuleiro de jogo, mantendo as pontuações e o tempo de jogo;
        monta_jogo(tabuleiro1, tiro1);
        monta_jogo(tabuleiro2, tiro2);
        printa_tabuleiro(tabuleiro2);
        printa_tabuleiro(tabuleiro1);
      }
      else if(strncmp(comando, "cheat", 5) == 0){
        cheat(tabuleiro1, tabuleiro2);
      }
      else                                                                              // Caso o comando seja inválido...
        printf("Comando invalido\n");
      }
    }

int menu2(int tabuleiro1[16][16], int tiro1[16][16], struct informacoes_do_jogador *jogador2){

  char comando[8];

  for(;;){

    printf("Digite seu comando. Para exibir os comandos, digite help. O jogador 2 so pode atirar\n");

    scanf("%s", comando);

    if(strncmp(comando, "pow", 3) == 0){                                    // Diferentemente do jogador 1, o jogador dois poderá apenas atirar. Os demais comandos não são executáveis às ordens dele;
      tiros(tabuleiro1, tiro1, jogador2);
      return 0;
    }
    else
      printf("Comando invalido\n");
  }
}

int main(){
  srand( (unsigned)time(NULL) );
  int tabuleiro1[16][16], tabuleiro2[16][16], vezes, tiro1[16][16], tiro2[16][16], jogador;
  char comecar[7];
  double tempo, tempo_salvo = 0, pontuacao1, pontuacao2;
  time_t t_ini, t_fim;

  struct informacoes_do_jogador jogador1;
  struct informacoes_do_jogador jogador2;

  jogador1.acertos = 0;                                                         //Definindo os números de embarcações restantes;
  jogador2.acertos = 0;
  jogador1.resto_PortaAvioes = 11;
  jogador2.resto_PortaAvioes = 11;
  jogador1.resto_Couracados = 20;
  jogador2.resto_Couracados = 20;
  jogador1.resto_Torpedeiros = 21;
  jogador2.resto_Torpedeiros = 21;
  jogador1.resto_Hidroavioes = 32;
  jogador2.resto_Hidroavioes = 32;

  monta_jogo(tabuleiro1, tiro1);
  monta_jogo(tabuleiro2, tiro2);

  t_ini = time(NULL);

    printf("\n");
    printf("------------------------------------------Manual das embarcacoes-----------------------------------------------------------------\t\t\n");
  	printf("\t1 - Torpedeiros: possuem 7 blocos dispostos em formato de 'T', com dimensoes de 3x5 blocos;\n");
  	printf("\t2 - Porta-avioes: possuem 11 blocos dispostos em formato de um 'H', com dimensoes de 5x3 blocos;\n");
  	printf("\t3 - Hidroavioes: possuem 8 blocos dispostos em formato de um 'retangulo', com dimensoes de 4x2 blocos;\n");
  	printf("\t4 - Couracados: possuem 10 blocos dispostos em formato de um 'retangulo, com dimensoes de 5x2 blocos.\n");
    printf("\n\n\t Nota: As embarcacoes podem ser dispostas de forma aleatoria, ou seja, deitadas ou em pe.\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------\t\t\n\n\n");

  do{
        printf("Tabuleiro 2 (alvo do jogador 1):\n\n");
        printa_tabuleiro(tabuleiro2);
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n\n\n");
        printf("Tabuleiro 1 (alvo do jogador 2):\n\n");
        printa_tabuleiro(tabuleiro1);
        jogador = 1;
        printf("Vez do jogador %d\n\n", jogador);
        printf("Tabuleiro 2 (alvo do jogador 1):\n\n");
        printa_tabuleiro(tabuleiro2);
        menu1(tabuleiro1, tiro1, &tempo, &t_ini, &tempo_salvo, tabuleiro2, tiro2, &jogador1, &jogador2);
        jogador = 2;
        system("\npause\n");
        printf("Vez do jogador %d\n\n", jogador);
        printf("Tabuleiro 1 (alvo do jogador 2):\n\n");
        printa_tabuleiro(tabuleiro1);
        menu2(tabuleiro1, tiro1, &jogador2);
        t_fim = time(NULL);
        tempo = difftime(t_fim, t_ini) + tempo_salvo;
        cronometro(tempo);
        printf("pontuacao do jogador 1: %.3f\n", jogador1.pontuacao);
        printf("pontuacao do jogador 2: %.3f\n", jogador2.pontuacao);
        system("\npause\n");
        system("cls");
    }while(jogador1.acertos < 84 || jogador2.acertos < 84);

    if(jogador1.pontuacao > jogador2.pontuacao)
      printf("Parabens jogador 1, voce ganhou!\n");

    else if(jogador2.pontuacao > jogador1.pontuacao)
      printf("Parabens jogador 2, voce ganhou!\n");
}




