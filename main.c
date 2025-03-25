#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

// input
int Z1;
int Z2;
float angpres;
int M;
float f10, f11, f20, f21;

// output
float Dp, Pr, DE, DI, Db, h, S, C, b1,b2, c, f, e, Rp, r, r1;

int calculosEng_1(){
    Dp = M * Z1;
    Pr = M * M_PI;
    DE = M * (Z1 + 2);
    DI = Dp - (2.166 * M);
    Db = Dp * cos(angpres * (M_PI/180));
    h = 2.166 * M;
    S = Pr/2;
    C = (M*(Z1+Z2))/2;
    b1 = 6 * M;
    b2 = 10 * M;
    c = M;
    f = 1.166 * M;
    e = 0.167 * M;
    Rp = ((0.3*M)+(S/6))/2;
    r = M * f10;
    r1 = M * f11;
    return 0;
}

int calculosEng_2(){
    Dp = M * Z2;
    Pr = M * M_PI;
    DE = M * (Z2 + 2);
    DI = Dp - (2.166 * M);
    Db = Dp * cos(angpres * (M_PI/180));
    h = 2.166 * M;
    S = Pr/2;
    C = (M*(Z1+Z2))/2;
    b1 = 6 * M;
    b2 = 10 * M;
    c = M;
    f = 1.166 * M;
    e = 0.167 * M;
    Rp = ((0.3*M)+(S/6))/2;
    r = M * f20;
    r1 = M * f21;
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
    int Dp1 = Dp;
    fprintf(arquivo, "Passo (Pr): %.3f mm\n", Pr);
    fprintf(arquivo, "Diametro externo (DE): %.3f mm\n", DE);
    int DE1 = DE;
    fprintf(arquivo, "Diametro interno (DI): %.3f mm\n", DI);
    fprintf(arquivo, "Diametro base (Db): %.3f mm\n", Db);
    fprintf(arquivo, "Altura (h): %.3f mm\n", h);
    fprintf(arquivo, "Espessura do dente (S): %.3f mm\n", S);
    fprintf(arquivo, "Distancia entre os flancos (C): %.3f mm\n", C);
    fprintf(arquivo, "Espessura da engrenagem (b): de %.3f mm até %.3f mm\n", b1,b2);
    fprintf(arquivo, "Altura da cabeca/dente (c): %.3f mm\n", c);
    fprintf(arquivo, "Altura do pe do dente: %.3f mm\n", f);
    fprintf(arquivo, "Folga do pe do dente (e): %.3f mm\n", e);
    fprintf(arquivo, "Raio do pe do dente (Rp): %.3f mm\n", Rp);
    fprintf(arquivo, "Raio maior do dente (r): %.3f mm\n", r);
    fprintf(arquivo, "Raio menor do dente (r1): %.3f mm\n", r1);

    fprintf(arquivo, "=======================================================================\n\n");
    calculosEng_2(Z1,Z2,M,angpres);

    fprintf(arquivo, "Engrenagem 2 - Dentes: %d\n", Z2);
    fprintf(arquivo, "Modulo: %d\n", M);
    fprintf(arquivo, "Angulo de pressão: %.2f°\n", angpres);
    fprintf(arquivo, "Diametro primitivo (Dp): %.3f mm\n", Dp);
    fprintf(arquivo, "Passo (Pr): %.3f mm\n", Pr);
    fprintf(arquivo, "Diametro externo (DE): %.3f mm\n", DE);
    fprintf(arquivo, "Diametro interno (DI): %.3f mm\n", DI);
    fprintf(arquivo, "Diametro base (Db): %.3f mm\n", Db);
    fprintf(arquivo, "Altura (h): %.3f mm\n", h);
    fprintf(arquivo, "Espessura do dente (S): %.3f mm\n", S);
    fprintf(arquivo, "Distancia entre os flancos (C): %.3f mm\n", C);
    fprintf(arquivo, "Espessura da engrenagem (b): de %.3f mm até %.3f mm\n", b1,b2);
    fprintf(arquivo, "Altura da cabeca/dente (c): %.3f mm\n", c);
    fprintf(arquivo, "Altura do pe do dente: %.3f mm\n", f);
    fprintf(arquivo, "Folga do pe do dente (e): %.3f mm\n", e);
    fprintf(arquivo, "Raio do pe do dente (Rp): %.3f mm\n", Rp);
    fprintf(arquivo, "Raio maior do dente (r): %.3f mm\n", r);
    fprintf(arquivo, "Raio menor do dente (r1): %.3f mm\n", r1);

    fprintf(arquivo, "=======================================================================\n\n");

    fprintf(arquivo, "Distancia entre centros: %.3f mm\n", (Dp1+Dp)/2);
    fprintf(arquivo, "Folga entre o Diam ext. Z1 e o Diam int Z2: %.3f mm\n", (DE1 - DI));

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

    // Coeficientes de Grant
    printf("Digite o coeficiente f da engrenagem 1: ");
    scanf("%f",&f10);
    printf("Digite o coeficente f1 da engrenagem 1: ");
    scanf("%f",&f11);
    printf("Digite o coeficiente f da engrenagem 2: ");
    scanf("%f",&f20);
    printf("Digite o coeficente f1 da engrenagem 2: ");
    scanf("%f",&f21);

    calculosEng_1(Z1,Z2,M,angpres,f10,f11);
    writeDim();
    return 0;
}