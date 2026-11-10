/*
 * Calculadora de Analise Combinatoria
 * - Triangulo de Pascal
 * - Arranjo simples      A(n,r) = n! / (n-r)!
 * - Permutacao simples   P(n)   = n!
 * - Combinacao simples   C(n,r) = n! / (r! * (n-r)!)
 *
 * Compilar: gcc calculadora.c -o calculadora
 * Executar: ./calculadora
 */

#include <stdio.h>

#define MAX_LINHAS 20   /* limite do triangulo de Pascal */
#define MAX_FAT 20      /* 20! e o maior fatorial que cabe em unsigned long long */

/* Calcula o fatorial de n usando um laco for */
unsigned long long fatorial(int n)
{
    unsigned long long resultado = 1;
    int i;

    for (i = 2; i <= n; i++) {
        resultado = resultado * i;
    }
    return resultado;
}

/* Permutacao simples: P(n) = n! */
unsigned long long permutacao(int n)
{
    return fatorial(n);
}

/* Arranjo simples: A(n,r) = n! / (n-r)! */
unsigned long long arranjo(int n, int r)
{
    return fatorial(n) / fatorial(n - r);
}

/* Combinacao simples: C(n,r) = n! / (r! * (n-r)!) */
unsigned long long combinacao(int n, int r)
{
    return fatorial(n) / (fatorial(r) * fatorial(n - r));
}

/* Imprime o triangulo de Pascal com 'linhas' linhas.
   Cada numero e a soma dos dois que estao acima dele. */
void trianguloPascal(int linhas)
{
    unsigned long long tri[MAX_LINHAS][MAX_LINHAS];
    int i, j, k;

    /* monta o triangulo */
    for (i = 0; i < linhas; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                tri[i][j] = 1;                          /* bordas valem 1 */
            } else {
                tri[i][j] = tri[i-1][j-1] + tri[i-1][j]; /* soma dos de cima */
            }
        }
    }

    /* imprime o triangulo */
    printf("\nTriangulo de Pascal com %d linhas:\n\n", linhas);
    for (i = 0; i < linhas; i++) {
        /* espacos para deixar o triangulo "centralizado" */
        for (k = 0; k < (linhas - i - 1) * 3; k++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("%6llu", tri[i][j]);
        }
        printf("\n");
    }
}

/* Mostra o menu na tela */
void mostraMenu(void)
{
    printf("\n=====================================\n");
    printf("   CALCULADORA DE COMBINATORIA\n");
    printf("=====================================\n");
    printf("1 - Triangulo de Pascal\n");
    printf("2 - Arranjo simples      A(n,r)\n");
    printf("3 - Permutacao simples   P(n)\n");
    printf("4 - Combinacao simples   C(n,r)\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main(void)
{
    int opcao, n, r, linhas;

    do {
        mostraMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantas linhas (1 a %d)? ", MAX_LINHAS);
                scanf("%d", &linhas);
                if (linhas < 1 || linhas > MAX_LINHAS) {
                    printf("Erro: digite um valor entre 1 e %d.\n", MAX_LINHAS);
                } else {
                    trianguloPascal(linhas);
                }
                break;

            case 2:
                printf("Digite n: ");
                scanf("%d", &n);
                printf("Digite r: ");
                scanf("%d", &r);
                if (n < 0 || r < 0 || r > n) {
                    printf("Erro: precisa ter 0 <= r <= n.\n");
                } else if (n > MAX_FAT) {
                    printf("Erro: n maior que %d estoura o limite do tipo.\n", MAX_FAT);
                } else {
                    printf("A(%d,%d) = %llu\n", n, r, arranjo(n, r));
                }
                break;

            case 3:
                printf("Digite n: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Erro: n nao pode ser negativo.\n");
                } else if (n > MAX_FAT) {
                    printf("Erro: n maior que %d estoura o limite do tipo.\n", MAX_FAT);
                } else {
                    printf("P(%d) = %d! = %llu\n", n, n, permutacao(n));
                }
                break;

            case 4:
                printf("Digite n: ");
                scanf("%d", &n);
                printf("Digite r: ");
                scanf("%d", &r);
                if (n < 0 || r < 0 || r > n) {
                    printf("Erro: precisa ter 0 <= r <= n.\n");
                } else if (n > MAX_FAT) {
                    printf("Erro: n maior que %d estoura o limite do tipo.\n", MAX_FAT);
                } else {
                    printf("C(%d,%d) = %llu\n", n, r, combinacao(n, r));
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente de novo.\n");
        }
    } while (opcao != 0);

    return 0;
}
