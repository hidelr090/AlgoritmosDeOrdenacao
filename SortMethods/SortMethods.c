#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *BubbleSort(int *vetor, int tam){
    
    int i=1;
    int pos;
    int fim = pos = tam-1;
    int j;
    int coud;
    int aux;

    puts("Ordenar em ordem crescente ou decrescente?\n");
    puts("Crescente - 1\n");
    puts("Decrescente - 2\n");
    scanf("%d", &coud);

    if(coud==1){
        while(i==1){
            i = 0;
            for(j=0; j<fim; j++){
                if(vetor[j]>vetor[j+1]){
                    aux = vetor[j];
                    vetor[j]=vetor[j+1];
                    vetor[j+1]=aux;
                    pos = j;
                    i=1;
                }
            }
            fim = pos;
        }
    }else{
        while(i==1){
            i=0;
            for(j=0; j<fim; j++){
                if(vetor[j]<vetor[j+1]){
                    aux = vetor[j];
                    vetor[j]=vetor[j+1];
                    vetor[j+1]=aux;
                    pos = j;
                    i=1;
                }
            }
            fim = pos;
        }
    }

    return vetor;
}

int *SelectionSort(int *vetor, int tam){
    int i, j;
    int aux;
    int min;
    int coud;
    printf("Ordenar em ordem crescente ou decrescente?\n");
    printf("Crescente - 1\n");
    printf("Decrescente -2\n");
    scanf("%d", &coud);
    if(coud == 1){
        for(i=0; i<tam-1; i++){
            min = i;
            for(j=i+1; j<tam; j++){
                if(vetor[j]<vetor[min]){
                    min = j;
                }
            }
            if(i!=min){
                aux = vetor[i];
                vetor[i] = vetor[min];
                vetor[min] = aux;
            }
        }
    }else{
        for(i=0; i<tam-1; i++){
            min = i;
            for(j=i+1; j<tam; j++){
                if(vetor[j]>vetor[min]){
                    min = j;
                }
            }
            if(i!=min){
                aux = vetor[i];
                vetor[i] = vetor[min];
                vetor[min] = aux;
            }
        }
    }

    return vetor;
}

int *InsertionSort(int *vetor, int tam){
    int chave, i, j;
    int coud;
    printf("Ordenar em ordem crescente ou decrescente?\n");
    printf("Crescente - 1\n");
    printf("Decrescente -2\n");
    scanf("%d", &coud);

    if(coud==1){
        for(i=1; i<tam; i++){
            chave = vetor[i];
            j = i-1;
            while(j>=0 && chave < vetor[j]){
                vetor[j+1] = vetor[j];
                j-=1;
            }
            if(j!=i-1)
                vetor[j+1]=chave;
        }
    }else{
        for(i=1; i<tam; i++){
            chave = vetor[i];
            j = i-1;
            while(j>=0 && chave > vetor[j]){
                vetor[j+1] = vetor[j];
                j-=1;
            }
            if(j!=i-1)
                vetor[j+1]=chave;
        }
    }

    return vetor;
}

void mostraVetor(int *vetor, int tam){

    int i;
    for(i=0; i<tam; i++){
        printf("%d ", vetor[i]);
    }
    puts("\n");
}


int main(){
    int tamanho;
    printf("Defina o tamanho do vetor.\n");
    scanf("%d", &tamanho);
    int *vetor;
    vetor = (int*)malloc(sizeof(int)*tamanho);
    int i;

    for(i=0; i<tamanho; i++){
        scanf("%d", &vetor[i]);
    }
    int choose = -1;
    while(choose!=0){
        printf("===MENU===\n");
        printf("1 - BubbleSort\n");
        printf("2 - SelectionSort\n");
        printf("3 - InsertionSort\n");
        scanf("%d", &choose);
        switch (choose){
            case 1:
                vetor = BubbleSort(vetor, tamanho);
                break;
            case 2:
                vetor = SelectionSort(vetor, tamanho);
                break;
            case 3:
                vetor = InsertionSort(vetor, tamanho);
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
        mostraVetor(vetor, tamanho);
    }

    free(vetor);

    return 0;
}