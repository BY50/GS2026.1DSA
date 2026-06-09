#include <stdio.h>
#include <string.h>
void exibirMenu(); 
int inserirTemperatura(int temperatura);
int inserirEnergia(int energia);
int inserirComunicacao(int comunicacao);
void executarAnalise(int temperatura, int energia, int comunicacao, char respostaTemperatura[28], char respostaEnergia[21], char respostaComunicacao[22]); 
void visualizarStatus(char respostaTemperatura[28], char respostaEnergia[21], char respostaComunicacao[22]); 
int main(){
    int opcao, temperatura = -999999, energia = -1, comunicacao = -1;
    char respostaTemperatura[28] = "Faca uma analise."; 
    char respostaEnergia[21] = "Faca uma analise."; 
    char respostaComunicacao[22] = "Faca uma analise."; 
    do{
        exibirMenu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1: 
            printf("Insercao de dados selecionado.\n");
            temperatura = inserirTemperatura(temperatura);
            energia = inserirEnergia(energia);
            comunicacao = inserirComunicacao(comunicacao);
            break;
            case 2: 
            printf("Execucao de analise selecionado.\n");
            executarAnalise(temperatura, energia, comunicacao, respostaTemperatura, respostaEnergia, respostaComunicacao);
            break;
            case 3: 
            printf("Visualizacao de status selecionado.\n");
            visualizarStatus(respostaTemperatura, respostaEnergia, respostaComunicacao); 
            break;
            case 0: 
            printf("Saindo...\n"); 
            break;
            default: printf("Invalido!\n");
        }
    }while(opcao != 0);
    return 0;
}

void exibirMenu(){
    printf("\n========================\n");
    printf(" MONITORAMENTO DA NAVE \n");
    printf("========================\n");
    printf("1 - Inserir dados\n");
    printf("2 - Executar analise\n");
    printf("3 - Visualizar status\n");
    printf("0 - Sair\n");
    printf("========================\n");
    printf("Escolha uma opcao: \n");
}

int inserirTemperatura(int temperatura){
    printf("Digite o valor da temperatura: \n"); 
    scanf("%d", &temperatura);
    while(temperatura == -999999){
        printf("Valor invalido, tente novamente.\n");
        scanf("%d", &temperatura);
    }
    return temperatura;
}

int inserirEnergia(int energia){
    printf("Digite a porcentagem de energia (de 0 a 100): \n"); 
    scanf("%d", &energia);
    while(energia < 0 || energia > 100){
        printf("Valor invalido, tente novamente.\n");
        scanf("%d", &energia);
    }
    return energia;
}

int inserirComunicacao(int comunicacao){
    printf("Digite o status da comunicacao (0 e falha e 1 e normal): \n"); 
    scanf("%d", &comunicacao);
    while(comunicacao != 0 && comunicacao != 1){
        printf("Valor invalido, tente novamente.\n");
        scanf("%d", &comunicacao);
    }
    printf("Pressione Enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
    return comunicacao;
}

void executarAnalise(int temperatura, int energia, int comunicacao, char respostaTemperatura[28], char respostaEnergia[21], char respostaComunicacao[22]){
    if(temperatura == -999999) printf("Insira uma temperatura.\n");
    else if(temperatura > 80) strcpy(respostaTemperatura, "Alerta de superaquecimento.");
    else strcpy(respostaTemperatura, "Sem superaquecimento.");
    if(energia == -1) printf("Insira uma porcentagem de energia.\n");
    else if(energia < 20) strcpy(respostaEnergia, "Economia de energia.");
    else strcpy(respostaEnergia, "Energia suficiente.");
    if(comunicacao == -1) printf("Insira o status da comunicacao.\n");
    else if(comunicacao == 0) strcpy(respostaComunicacao, "Falha de comunicacao.");
    else strcpy(respostaComunicacao, "Comunicacao normal.");
    printf("Analise realizada.\n");
    printf("Pressione Enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
}

void visualizarStatus(char respostaTemperatura[28], char respostaEnergia[21], char respostaComunicacao[22]){
    printf("\n--- STATUS DA NAVE ---\n");
    printf("Temperatura: %s\n", respostaTemperatura);
    printf("Energia: %s\n", respostaEnergia);
    printf("Comunicacao: %s\n", respostaComunicacao);
    printf("-------------------\n");
    printf("Pressione Enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
}
