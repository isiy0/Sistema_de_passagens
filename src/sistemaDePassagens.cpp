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
   
    printf("\n\033[34mOlá, tudo bem com você? Espero que sim!\nMe chamo Gui e serei o seu guia de reserva de poltronas!\n\nEspero que possa lhe ajudar!\n\n");
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
        printf("\n\n\033[33mQuantas poltronas você deseja reservar?\n");
    
        scanf("%d", &reservas);
        clearInputBuffer();
    
        if (reservas <= 0)
        {
            printf("\033[31mValor inválido! Por favor, digite um valor válido!\n");
            continue;   
        }

        printf("\n\033[32mObrigado pela resposta!\n\nEntão");
        if (reservas>1){
            printf("\033[32m serão %d poltronas...", reservas);
        }
        else{
            printf("\033[32m será %d poltrona...", reservas);
        }
        printf("\033[32m Anotado!\n");
        printf("\n\033[33mAh, antes que eu esqueça... qual classe você prefere?");
        
        int selection = 0;
        while (true)
        {
            switch (reservas){
                case 1:
                    printf("\n\033[33m1 ->Executiva");
                    selection = 1;
                    break;
                case 2:
                    printf("\n\033[33m1 ->Executiva");
                    
                    printf("\n\033[33m2 ->Combo Casal <3");
                    selection = 2;
                    break;
                default:

                    printf("\n\033[33m1 ->Executiva");
                    if (reservas % 2 ==0){
                        printf("\n\033[33m2 ->Combo Casal <3");
                        printf("\n\033[33m3 ->Combo Familia");
                        selection = 3;
                    }
                    else{
                        printf("\n\033[33m2 ->Combo Familia");
                        selection = 2;
                    }
                    break;
            }
        
            printf("\n\n\033[34mOBS: digite um número\n");
        
            scanf("%d", &classe);
            if (classe < 1 || classe > selection){
                printf("\n\033[31mClasse inválida!\n");
                clearInputBuffer();
                continue;
            }
            else {
                clearInputBuffer();
                break;
            }
        }
        printf("\n\033[32mÓtimo! Agora vamos escolher a");
        reservas > 1 ? printf("\033[32ms suas poltronas ;)\n") : printf("\033[32m sua poltrona :)\n");
    
        printf("\033[34mOBS: Poltronas com 'X' estão ocupadas e poltronas marcadas com '*' são recomendações de acordo com a quantidade de reservas selecionada.\n");
        printf("\n\033[33mPoltronas disponíveis:\n");
    
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
                printf("\n\033[33mDigite a letra da sua poltrona:");
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
                        printf("\n\033[31mPoltrona inválida!\n");
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
                printf("\n\033[33mDigite a fileira da sua poltrona: \n");
                scanf("%d", &fileira);
                clearInputBuffer();
                if (fileira < 1 || fileira > 10){
                    printf("\n\033[31mFileira inválida!\n");
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
                printf("\n\033[32m Poltrona selecionada: %c%d\n", poltrona, fileira);
                invalido = true;
            }
            else {
                printf("\033[31mPoltrona já selecionada pelo usuário ou ocupada.\nPor favor, selecione outra poltrona!\n");
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
            printf("\n\n\033[33mDeseja fazer mais alguma reserva? (s/n)\n");
            scanf(" %c", &resposta);
            clearInputBuffer();
            if (resposta == 'n' || resposta == 'N'){
                
                break;
            }
            else if (resposta == 's' || resposta == 'S'){
                continue;
            }
            else {
                printf("\n\033[31mResposta inválida!\n");
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