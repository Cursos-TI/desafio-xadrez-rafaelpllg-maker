// Nível Mestre - Funções Recursivas e Loops Aninhados
// Sugestão: Substitua as movimentações das peças por funções recursivas.
// Exemplo: Crie uma função recursiva para o movimento do Bispo.

// Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
// Inclua o uso de continue e break dentro dos loops.


#include <stdio.h>

int usuarioDirecao(int flag);

//----------------[   sistema de movimento das peças   ]----------------

//Movimento simples da torre com recursão
void moveTorre(int casas, char direcao[]) {
    if (casas > 0) {
        printf("%s\n", direcao);
        moveTorre(casas - 1, direcao);
    }

}

//Bispo com loops aninhados e recursão
void moveBispo(int casas, char direcao1[], char direcao2[]) {
    if (casas > 0) {
        for (int i =0 ; i < 1; i++) {
            for (int j = 0; j < 1; j++) {
                printf("%s e %s\n", direcao1, direcao2);
            }
        }
        moveBispo(casas - 1, direcao1, direcao2);
    }
}

//A rainha possui os movimentos do bispo e da torre combinados. Usei recursão.
void moveRainha(int casas, char direcao1[], char direcao2[], int diagonal) {
    if (casas > 0) {
        if (diagonal == 1) {
            moveBispo(1, direcao1, direcao2);
        } else {
            moveTorre(1, direcao1);
        }
        moveRainha(casas - 1, direcao1, direcao2, diagonal);
    }
}

//Cavalo com loops complexos
void moveCavalo(char direcao1[], char direcao2[]) {
    //Um loop complexo simulando o movimento em L
    for (int i = 1; i <= 3; i++) {
        if (i <= 2) {
            printf("%s\n", direcao1);
            continue; //Pula para o próximo passo
        }
        //Loop aninhado da perna mais curta do L
        for (int j = 0; j < 1; j++) {
            printf("%s\n", direcao2);
        }
        break; //Encerra o loop principal
    }
}

//----------------[   sistema de escolha de direção   ]----------------

//Escolha da direção para a torre, 4 opções
void dirTorre(int casas, int direcao) {
    switch (direcao) {
        case 1:
            moveTorre(casas, "Direita");
            break;
        case 2:
            moveTorre(casas, "Esquerda");
            break;
        case 3:
            moveTorre(casas, "Cima");
            break;
        case 4:
            moveTorre(casas, "Baixo");
            break;
        default:
            printf("Ação inválida!\n");
    }
}

//Escolha da direção para o bispo, 4 opções
void dirBispo(int casas, int direcao) {
    switch (direcao) {
        case 1:
            moveBispo(casas, "Cima", "Direita");
            break;
        case 2:
            moveBispo(casas, "Cima", "Esquerda");
            break;
        case 3:
            moveBispo(casas, "Baixo", "Direita");
            break;
        case 4:
            moveBispo(casas, "Baixo", "Esquerda");
            break;
        default:
            printf("Ação inválida!\n");
    }
}

//Escolha da direção para a rainha, 8 opções
void dirRainha(int casas, int direcao) {
    switch (direcao) {
        case 1:
            moveRainha(casas, "Direita", "Cima", 1);
            break;
        case 2:
            moveRainha(casas, "Direita", "Baixo", 1);
            break;
        case 3:
            moveRainha(casas, "Esquerda", "Cima", 1);
            break;
        case 4:
            moveRainha(casas, "Esquerda", "Baixo", 1);
            break;
        case 5:
            moveRainha(casas, "Direita", "", 0);
            break;
        case 6:
            moveRainha(casas, "Esquerda", "", 0);
            break;
        case 7:
            moveRainha(casas, "Cima", "", 0);
            break;
        case 8:
            moveRainha(casas, "Baixo", "", 0);
            break;
        default:
            printf("Ação inválida!\n");
    }
}

//Escolha da direção para o cavalo, 8 opções
void dirCavalo(int direcao) {
    switch (direcao) {
        case 1:
            moveCavalo("Direita", "Cima");
            break;
        case 2:
            moveCavalo("Direita", "Baixo");
            break;
        case 3:
            moveCavalo("Esquerda", "Cima");
            break;
        case 4:
            moveCavalo("Esquerda", "Baixo");
            break;
        case 5:
            moveCavalo("Cima", "Direita");
            break;
        case 6:
            moveCavalo("Cima", "Esquerda");
            break;
        case 7:
            moveCavalo("Baixo", "Direita");
            break;
        case 8:
            moveCavalo("Baixo", "Esquerda");
            break;
        default:
            printf("Ação inválida!\n");
    }
}

//Escolhe a peça e a direção
void escolhePeca(int peca, int casas) {
    int direcao = usuarioDirecao(peca);
    switch (peca) {
        case 1:
            dirTorre(casas, direcao);
            break;
        case 2:
            dirBispo(casas, direcao);
            break;
        case 3:
            dirRainha(casas, direcao);
            break;
        case 4:
            dirCavalo(direcao);
            break;
        default:
            printf("Peça inválida!\n");
    }
}

//Menu de escolha da peça e número de casas, com validação de entrada
void startUsuario() {
    int peca, casas;
    do {
        printf("Escolha a peça\n\n       1 - Torre   |   2 - Bispo\n       3 - Rainha  |   4 - Cavalo");
        printf("\n\nDigite o número da peça que deseja mover: ");
        scanf("%d", &peca);
        if (peca < 1 || peca > 4) {
            printf("Peça inválida! Digite um número de 1 a 4.\n\nTente novamente.\n");
        }
    } while (peca < 1 || peca > 4);
    if (peca != 4) {
         do {
        printf("Digite o número de casas para mover: ");
        scanf("%d", &casas);
        if (casas < 1 || casas > 8) {
            printf("Número de casas inválido! Digite um número de 1 a 8.\n\nTente novamente.\n");
        }
    } while (casas < 1 || casas > 8);
    }

    escolhePeca(peca, casas);
}

//Menu das direções, recebe a flag da peça selecionada para apresentar as opções corretas
int usuarioDirecao(int flag) {
    int direcao;
    do {
        printf("\nEscolha a direção\n\n");
        if (flag == 1) {
            printf("     1 - Direita\n     2 - Esquerda\n     3 - Cima\n     4 - Baixo\n");
        } else if (flag == 2) {
            printf("     1 - Cima e Direita\n     2 - Cima e Esquerda\n     3 - Baixo e Direita\n     4 - Baixo e Esquerda\n");
        } else if (flag == 3) {
            printf("     1 - Diagonal Direita e Cima\n     2 - Diagonal Direita e Baixo\n     3 - Diagonal Esquerda e Cima\n     4 - Diagonal Esquerda e Baixo\n     5 - Direita\n     6 - Esquerda\n     7 - Cima\n     8 - Baixo\n");
        } else if (flag == 4) {
            printf("     1 - Direita e Cima\n     2 - Direita e Baixo\n     3 - Esquerda e Cima\n     4 - Esquerda e Baixo\n     5 - Cima e Direita\n     6 - Cima e Esquerda\n     7 - Baixo e Direita\n     8 - Baixo e Esquerda\n");
        }
        printf("\nDigite o número da direção em que deseja mover a peça: ");
        scanf("%d", &direcao);
        printf("\n\nMovendo a peça...\n\n");
        if ((flag == 1 && (direcao < 1 || direcao > 4)) ||
            (flag == 2 && (direcao < 1 || direcao > 4)) ||
            (flag == 3 && (direcao < 1 || direcao > 8)) ||
            (flag == 4 && (direcao < 1 || direcao > 8))) {
            printf("Direção inválida! Tente novamente.\n");
        }
    } while ((flag == 1 && (direcao < 1 || direcao > 4)) ||
             (flag == 2 && (direcao < 1 || direcao > 4)) ||
             (flag == 3 && (direcao < 1 || direcao > 8)) ||
             (flag == 4 && (direcao < 1 || direcao > 8)));
    return direcao;
}

//Tela inicial do jogo, com menu para iniciar ou sair
int menuInicial() {
    int escolha = 1;

    printf("======================================================\n");
    printf("      Bem-vindo ao jogo de xadrez recursivo!\n");
    printf("======================================================\n\n");

    do {
        printf("Digite 1 para jogar ou 2 para sair: ");
        scanf("%d", &escolha);
        if (escolha < 1 || escolha > 2) {
            printf("Escolha inválida! Tente novamente.\n");
        }
    } while (escolha < 1 || escolha > 2);

    switch (escolha)
    {
    case 1:
        startUsuario();
        return escolha;
    case 2:
        printf("Saindo do jogo. Até a próxima!\n");
        return 0;
    default:
        printf("Escolha inválida! Tente novamente.\n");
        return 1;
    }
}

//Função principal que inicia o programa
int main () {
    int escolha;
    
    do
    {
        escolha = menuInicial();
    } while (escolha == 1);

    return 0;
}

/* #include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {

    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.
    int movimento_torre = 5, movimento_rainha = 5, movimento_bispo = 5, movimento_cavalo = 5;

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
    printf("\n\nMovimento Bispo\n\n");
    while (movimento_bispo > 0)
    {
        printf("Cima\n");
        printf("Esquerda\n");
        movimento_bispo--;
    }
    
    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
    printf("\n\nMovimento Torre\n\n");
    for (int i = 0; i < movimento_torre; i++)
    {
        printf("Direita\n");
    }

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
    printf("\n\nMovimento Rainha\n\n");
    do {
        printf("Esquerda\n");
        movimento_rainha--;
    } while (movimento_rainha > 0);
    
    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.
    printf("\n\nMovimento Cavalo\n\n");
    for (int i = 0; i < 1; i++)
    {
        printf("Esquerda\n");

        for (int j = 0; j < 2; j++)
        {
            printf("Cima\n");
        }
        
    }
   
    return 0;
}
    */ 

x