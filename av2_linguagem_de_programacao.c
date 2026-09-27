#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Função: calcularSalario
 * Parâmetros:
 *   - horas: número de horas trabalhadas na semana (float)
 *   - valorHora: valor pago por hora trabalhada (float)
 * Retorno:
 *   - Valor total do salário com adicional de 50% sobre horas extras (> 40h)
 */
float calcularSalario(float horas, float valorHora) {
    float salarioTotal;
    float horasNormais = 40.0;
    float adicionalExtra = 1.5; /* Adicional de 50% = 150% do valor hora */

    if (horas > horasNormais) {
        float horasExtras = horas - horasNormais;
        salarioTotal = (horasNormais * valorHora) + (horasExtras * valorHora * adicionalExtra);
    } else {
        salarioTotal = horas * valorHora;
    }

    return salarioTotal;
}

int main() {
    char nome[100];
    float horasTrabalhadas, valorHora, salarioFinal;
    char continuar;

    printf("====================================================\n");
    printf("   SISTEMA DE FOLHA DE PAGAMENTO - TERCEIRIZACAO   \n");
    printf("====================================================\n");

    do {
        printf("\n--- Cadastro de Colaborador ---\n");
        printf("Digite o nome do funcionario: ");
        fgets(nome, sizeof(nome), stdin);
        
        /* Remove o caractere de nova linha '\n' capturado pelo fgets */
        nome[strcspn(nome, "\n")] = '\0';

        printf("Digite o numero de horas trabalhadas na semana: ");
        while (scanf("%f", &horasTrabalhadas) != 1 || horasTrabalhadas < 0) {
            printf("Entrada invalida! Digite um valor numerico positivo para as horas: ");
            while (getchar() != '\n');
        }

        printf("Digite o valor por hora trabalhada (R$): ");
        while (scanf("%f", &valorHora) != 1 || valorHora <= 0) {
            printf("Entrada invalida! Digite um valor numerico positivo para o valor-hora: ");
            while (getchar() != '\n');
        }

        /* Chamada da função de cálculo salarial */
        salarioFinal = calcularSalario(horasTrabalhadas, valorHora);

        /* Exibição detalhada do resultado */
        printf("\n====================================================\n");
        printf("               DEMONSTRATIVO DE PAGAMENTO           \n");
        printf("====================================================\n");
        printf("Funcionario:             %s\n", nome);
        printf("Horas Trabalhadas:       %.2f h\n", horasTrabalhadas);
        printf("Valor por Hora:          R$ %.2f\n", valorHora);
        
        if (horasTrabalhadas > 40.0) {
            float extras = horasTrabalhadas - 40.0;
            printf("Horas Extras (50%%):      %.2f h\n", extras);
        } else {
            printf("Horas Extras (50%%):      0.00 h\n", 0.0);
        }
        
        printf("----------------------------------------------------\n");
        printf("SALARIO BRUTO TOTAL:     R$ %.2f\n", salarioFinal);
        printf("====================================================\n");

        /* Limpeza do buffer de entrada antes de ler a resposta de repetição */
        while (getchar() != '\n');

        printf("\nDeseja calcular a folha de outro funcionario? (S/N): ");
        scanf("%c", &continuar);
        
        /* Limpeza do buffer do scanf */
        while (getchar() != '\n');

    } while (continuar == 'S' || continuar == 's');

    printf("\nSistema encerrado com sucesso. Obrigado!\n");

    return 0;
}
