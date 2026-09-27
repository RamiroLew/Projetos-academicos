#include <stdio.h>


void lertemp(float *temp, float *max, float *min) {
    printf("qual e a temperatura? \n");
    scanf("%f", temp);
    printf("qual e a temperatura maxima? \n");
    scanf("%f", max);
    printf("qual e a temperatura minima? \n");
    scanf("%f", min);
}

int processamento(float temp,float min, float max) {
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

void exib (int proces){
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
    float temp;
    float max;
    float min;
    int proces;
    lertemp(&temp, &max, &min);
    proces = processamento(temp, min, max);
    exib(proces);
    getchar();
    getchar();
    return 0;
}


    // Baseado em tudo que a gente concluiu, tenta escrever:
//A assinatura da função de leitura
//A assinatura da função de processamento
//A assinatura da função de exibição
//Como ficaria a chamada de cada uma dessas três lá dentro do main'