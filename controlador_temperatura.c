#include <stdio.h>

/*Desenvolva um programa em C que:
1.    Leia a temperatura atual do ambiente (entrada do usuário).
2.    Compare o valor com os limites de temperatura definidos (mínimo e máximo).
3.    Exiba mensagens correspondentes às ações do sistema: “Aquecendo...”, “Resfriando...” ou “Temperatura estável.”
4.    Utilize funções separadas para leitura, processamento e exibição dos resultados.
*/
void lertemp(float *temp, float *max, float *min) { //função dedicada a ler temperaturas
    printf("qual e a temperatura? \n");
    scanf("%f", temp);
    printf("qual e a temperatura maxima? \n");
    scanf("%f", max);
    printf("qual e a temperatura minima? \n");
    scanf("%f", min);
}

int processamento(float temp,float min, float max) { //função dedicada a processar temperatura, retornando um valor de 1~3
    int proces;
    //01 aquecendo, 02 esfriando, 03 temperatura normal
    if (temp < min) {
        proces = 1; }
    else if (temp > max) {
        proces = 2; }
    else {
          proces = 3; }
  return proces;
}

void exib (int proces){ //função dedicada a exibir o resultado 
    if (proces == 1){
        printf("temperatura muito baixa, aquecendo...\n");
    }
    else if (proces == 2){
        printf("temperatura muito alta, esfriando...\n");
    }
    else {
        printf("temperatura esta dentro dos parametros\n");
    }
}

int main(){
    float temp; //declaração das varaiveis
    float max;
    float min;
    int proces;

    lertemp(&temp, &max, &min);             //uso das funções
    proces = processamento(temp, min, max);
    exib(proces);

    getchar();  //comando para o programa não fechar automaticamente
    getchar();
    return 0;
}

