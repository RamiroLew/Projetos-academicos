#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Desenvolva um programa em linguagem C que solicite o nome do funcionário,
 o número de horas trabalhadas e o valor da hora. O programa deverá calcular o salário total,
considerando horas extras (acima de 40 horas) com adicional de 50%.
 O cálculo deve ser realizado por meio de uma função criada pelo estudante.*/

float calcularSalario(float horas, float valorHora) { //função para calcular salario.
    float salarioTotal;
    float horasNormais = 40.0; //hora padrão do funcionario
    float adicionalExtra = 1.5; /* Adicional de 50% = 150% do valor hora exigidos no enunciado */

    if (horas > horasNormais) { //extrutura condicional para o calculo do salario já com os possiveis adicionais
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

    do {    //estrutura para o cadastro do funcionario, tendo tratamento de erros
        printf("\n--- Cadastro de Colaborador ---\n");
        printf("Digite o nome do funcionario: ");
        fgets(nome, sizeof(nome), stdin); // recebe nomes compostos 
        
        /* Remove o caractere de nova linha '\n' capturado pelo fgets */
        nome[strcspn(nome, "\n")] = '\0';

        printf("Digite o numero de horas trabalhadas na semana: ");
        while (scanf("%f", &horasTrabalhadas) != 1 || horasTrabalhadas < 0) { //recebendo horas trabalhadas com tratamento de erros
            printf("Entrada invalida! Digite um valor numerico positivo para as horas: ");
            while (getchar() != '\n');
        }

        printf("Digite o valor por hora trabalhada (R$): ");
        while (scanf("%f", &valorHora) != 1 || valorHora <= 0) { //recebendo variavel das horas trabalhadas com tratamento de erros
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

        printf("\nDeseja calcular a folha de outro funcionario? (S/N): "); //confirmação para continuar ou não o programa
        scanf("%c", &continuar);
        
        /* Limpeza do buffer do scanf */
        while (getchar() != '\n');

    } while (continuar == 'S' || continuar == 's');

    printf("\nSistema encerrado com sucesso. Obrigado!\n");

    return 0;
}
