#include <stdio.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

// input
int Z1;
int Z2;
float angpres;
int M;

// output
float Dp, Pr, DE, DI, h, S, C, b1,b2, c, f;

int calculosEng_1(int Z1, int Z2, int M){
    Dp = M * Z1;
    Pr = M * M_PI;
    DE = M * (Z1 + 2);
    DI = Dp - (2.166 * M);
    h = 2.166 * M;
    S = Pr/2;
    C = (M*(Z1+Z2))/2;
    b1 = 6 * M;
    b2 = 10 * M;
    c = M;
    f = 1.166 * M;
    return 0;
}

int calculosEng_2(int Z1, int Z2, int M){
    Dp = M * Z2;
    Pr = M * M_PI;
    DE = M * (Z2 + 2);
    DI = Dp - (2.166 * M);
    h = 2.166 * M;
    S = Pr/2;
    C = (M*(Z1+Z2))/2;
    b1 = 6 * M;
    b2 = 10 * M;
    c = M;
    f = 1.166 * M;
    return 0;
}

void writeDim() {

    char filename[50];
    sprintf(filename, "engrenagem_%d_%d.txt", Z1, Z2); 

    // Abre o arquivo para escrita
    FILE *arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve as informações da engrenagem no arquivo
    fprintf(arquivo, "Engrenagem 1 - Dentes: %d\n", Z1);
    fprintf(arquivo, "Modulo: %d\n", M);
    fprintf(arquivo, "Angulo de pressão: %.2f°\n", angpres);
    fprintf(arquivo, "Diametro primitivo (Dp): %.3f mm\n", Dp);
    fprintf(arquivo, "Passo (Pr): %.3f mm\n", Pr);
    fprintf(arquivo, "Diametro externo (DE): %.3f mm\n", DE);
    fprintf(arquivo, "Diametro interno (DI): %.3f mm\n", DI);
    fprintf(arquivo, "Altura (h): %.3f mm\n", h);
    fprintf(arquivo, "Espessura do dente (S): %.3f mm\n", S);
    fprintf(arquivo, "Distancia entre os flancos (C): %.3f mm\n", C);
    fprintf(arquivo, "Espessura da engrenagem (b): de %.3f mm até %.3f mm\n", b1,b2);
    fprintf(arquivo, "Cabeca (c): %.3f\n", c);
    fprintf(arquivo, "Fundo (f): %.3f\n", f);

    fprintf(arquivo, "=======================================================================\n\n");
    calculosEng_2(Z1,Z2,M);

    fprintf(arquivo, "Engrenagem 2 - Dentes: %d\n", Z2);
    fprintf(arquivo, "Modulo: %d\n", M);
    fprintf(arquivo, "Angulo de pressão: %.2f°\n", angpres);
    fprintf(arquivo, "Diametro primitivo (Dp): %.3f mm\n", Dp);
    fprintf(arquivo, "Passo (Pr): %.3f mm\n", Pr);
    fprintf(arquivo, "Diametro externo (DE): %.3f mm\n", DE);
    fprintf(arquivo, "Diametro interno (DI): %.3f mm\n", DI);
    fprintf(arquivo, "Altura (h): %.3f mm\n", h);
    fprintf(arquivo, "Espessura do dente (S): %.3f mm\n", S);
    fprintf(arquivo, "Distancia entre os flancos (C): %.3f mm\n", C);
    fprintf(arquivo, "Espessura da engrenagem (b): de %.3f mm até %.3f mm\n", b1,b2);
    fprintf(arquivo, "Cabeca (c): %.3f\n", c);
    fprintf(arquivo, "Fundo (f): %.3f\n", f);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Arquivo %s gerado com sucesso!\n", filename);
}

int main(){

    printf("Digite o numero de dentes da engrenagem 1: ");
    scanf("%d",&Z1);
    printf("Digite o numero de dentes da engrenagem 2: ");
    scanf("%d",&Z2);
    printf("Digite o numero de modulo da engrenagem: ");
    scanf("%d",&M);
    printf("Digite o angulo de pressao da engrenagem: ");
    scanf("%f",&angpres);

    calculosEng_1(Z1,Z2,M);
    writeDim();
    return 0;
}