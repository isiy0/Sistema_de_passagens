#include <cstdio>
#include <unistd.h>
#include <iostream>

// Função para limpar o terminal
void clearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int reservas;
    int classe;
    
    char matriz[10][6] = {
        {' ', 'X', 'X', 'X', ' ', ' '},
        {' ', ' ', 'X', ' ', ' ', ' '},
        {'X', 'X', ' ', 'X', 'X', 'X'},
        {' ', 'X', 'X', 'X', 'X', ' '},
        {'X', 'X', ' ', 'X', 'X', 'X'},
        {'X', 'X', ' ', ' ', 'X', 'X'},
        {' ', 'X', 'X', ' ', ' ', 'X'},
        {' ', ' ', 'X', 'X', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', 'X', 'X'}
    };
    int col;
    int row;
    
    char poltrona;
    int fileira;
   
    std::cout << R"(
   _____ _     _                             _                                               
  / ____(_)   | |                           | |                                              
 | (___  _ ___| |_ ___ _ __ ___   __ _    __| | ___   _ __ ___  ___  ___ _ ____   ____ _ ___ 
  \___ \| / __| __/ _ \ '_ ` _ \ / _` |  / _` |/ _ \ | '__/ _ \/ __|/ _ \ '__\ \ / / _` / __|
  ____) | \__ \ ||  __/ | | | | | (_| | | (_| |  __/ | | |  __/\__ \  __/ |   \ V / (_| \__ \
 |_____/|_|___/\__\___|_| |_| |_|\__,_|  \__,_|\___| |_|  \___||___/\___|_|    \_/ \__,_|___/
    )" << std::endl;
   
    printf("\nOlá, tudo bem com você? Espero que sim!\nMe chamo Gui e serei o seu guia de reserva de poltronas!\n\nEspero que possa lhe ajudar!\n\n");
    std::cout << R"(                                                                                                    
                                                                             
                                                  
                                                  
                   .::::::::::.                   
               ..::::::::::::::::..               
             .::::::::::::::::::::::.             
            .::::::::::::::::::::::::.            
           :::::::*@@*::::::*@@*:::::::           
          .:::::::@@@@::::::@@@@:::::::.          
         .::::::::@@@@::::::@@@@::::::::.         
         .::::::::=@@=::::::=@@=::::::::.         
         ::::::::::::::::::::::::::::::::         
         .::::::::::::::::::::::::::::::.         
         .:::::::@::::::::::::::@:::::::.         
          .:::::::%@::::::::::@%:::::::.          
           ::::::::+@@+@@@-+@@+::::::::           
            .:::::::::+@@@@@:::::::::.            
             .::::::::::::::::::::::.             
               ..::::::::::::::::..               
                   .::::::::::.                   
                                                                                                                                                                                                    
    )" << std::endl;
    sleep(5);
    
    while(true){
        printf("\n\nQuantas poltronas você deseja reservar?\n");
    
        scanf("%d", &reservas);
        clearInputBuffer();
    
        if (reservas <= 0)
        {
            printf("Valor inválido! Por favor, digite um valor válido!\n");
            continue;   
        }

        printf("\nObrigado pela resposta!\n\nEntão");
        if (reservas>1){
            printf(" serão %d poltronas...", reservas);
        }
        else{
            printf(" será %d poltrona...", reservas);
        }
        printf(" Anotado!\n\nAh, antes que eu esqueça... qual classe você prefere?");
        
        
        switch (reservas){
            case 1:
                printf("\n1 ->Executiva");
                break;
            case 2:
                printf("\n1 ->Executiva");
                
                printf("\n2 ->Combo Casal <3");
                break;
            default:
                printf("\n1 ->Executiva");
                
                printf("\n2 ->Combo Casal <3");
                
                printf("\n3 ->Combo Familia");
                break;
        }
    
        printf("\n\nOBS: digite um número\n");
    
        scanf("%d", &classe);
        clearInputBuffer();
    
        printf("\nÓtimo! Agora vamos escolher a");
        reservas > 1 ? printf("s suas poltronas ;)\n") : printf(" sua poltrona :)\n");
    
        printf("OBS: Poltronas com 'X' estão ocupadas e poltronas marcadas com '*' são recomendações de acordo com a quantidade de reservas selecionada.\n");
        printf("\nPoltronas disponíveis:\n");
    
        printf("\n     A  B  C  D  E  F \n\n");
        for (int x=0; x<10; x++){
            x!=9 ? printf("%d   ", x+1) : printf("%d  ", x+1);
            for (int y=0; y<6; y++){
                bool canRecommend = true;
                for (int k = 0; k < reservas; k++) {
                    if (y + k >= 6 || matriz[x][y + k] != ' ') {
                        canRecommend = false;
                        break;
                    }
                }
                if (canRecommend) {
                    for (int k = 0; k < reservas; k++) {
                        matriz[x][y + k] = '*';
                    }
                }
                printf("(%c)", matriz[x][y]);
            }
            printf("\n");
        }
    
        for (int i=0; i<reservas; i++){
            bool invalido = false;
            while(true){
                printf("\nDigite a letra da sua poltrona:");
                scanf("%c", &poltrona);
                clearInputBuffer();

                poltrona = toupper(poltrona);

                switch (poltrona){
                    case 'A':
                        col = 0;
                        invalido = false;
                        break;
                    case 'B':
                        col = 1;
                        invalido = false;
                        break;
                    case 'C':
                        col = 2;
                        invalido = false;
                        break;
                    case 'D':
                        col = 3;
                        invalido = false;
                        break;
                    case 'E':
                        col = 4;
                        invalido = false;
                        break;
                    case 'F':
                        col = 5;
                        invalido = false;
                        break;
                    default:
                        printf("\nPoltrona inválida!\n");
                        printf("%c", poltrona);
                        invalido = true;
                        break;   
                }
                if (!invalido){
                    break;
                }
            }
            while (true)
            {
                printf("\nDigite a fileira da sua poltrona: \n");
                scanf("%d", &fileira);
                clearInputBuffer();
                if (fileira < 1 || fileira > 10){
                    printf("\nFileira inválida!\n");
                    invalido = true;
                }
                else {
                    row = fileira - 1;
                    invalido = false;
                    break;
                }
            }
            printf("\n     A  B  C  D  E  F \n\n");
            for (int x=0; x<10; x++){
            
                x!=9 ? printf("%d   ", x+1) : printf("%d  ", x+1);
                for (int y=0; y<6; y++){
                    if (x==row && y==col){
                        if (matriz[x][y] == 'X'){
                            invalido = true;
                            i--;
                            
                        }
                        else if(matriz[x][y] == 'O'){
                            invalido = true;
                            i--;
                            
                        }
                        else {
                            matriz[x][y] = 'O';
                        }
                    }
                    printf("(%c)", matriz[x][y]);
                }
                printf("\n");
            }
            if (!invalido){
                printf("\n Poltrona selecionada: %c%d\n", poltrona, fileira);
                invalido = true;
            }
            else {
                printf("Poltrona já selecionada pelo usuário ou ocupada.\nPor favor, selecione outra poltrona!\n");
            }
        }

        for (int x=0; x<10; x++){
            for (int y=0; y<6; y++){
                if(matriz[x][y] == 'O'){
                    matriz[x][y] = 'X';
                }
            }
        }
        char resposta;
        while (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N')
        {
            printf("\n\nDeseja fazer mais alguma reserva? (s/n)\n");
            scanf(" %c", &resposta);
            clearInputBuffer();
            if (resposta == 'n' || resposta == 'N'){
                
                break;
            }
            else if (resposta == 's' || resposta == 'S'){
                continue;
            }
            else {
                printf("\nResposta inválida!\n");
            }
        }
        if (resposta == 'n' || resposta == 'N'){
            break;
        }
        else if (resposta == 's' || resposta == 'S'){
            clearTerminal();
        }
    }
}