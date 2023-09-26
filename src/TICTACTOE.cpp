#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void drawBoard(char* spaces);
void drawNewBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);
void clearScreen();
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);

int main(){
    char spaces[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool isRunning = true;

    drawBoard(spaces);

    while (isRunning)
    {
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer))
        {
            isRunning = false;
            break;
        }
        else if (checkTie(spaces))
        {
            isRunning = false;
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);
    }
    

}


void drawBoard(char* spaces){
    clearScreen();
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void drawNewBoard(char* spaces) {
    std::cout << '\n';
    for (int i = 0; i < 9; i++) {
        std::cout << " " << spaces[i] << " ";
        if (i == 2 || i == 5 || i == 8) {
            std::cout << '\n';
            if (i < 8) {
                std::cout << "-----------\n";
            }
        } else {
            std::cout << "|";
        }
    }
    std::cout << '\n';
}

void playerMove(char* spaces, char player){
    int number;
    do{
        std::cout<<"Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
    
}

void computerMove(char* spaces, char computer){
    int number;
    srand(time(0));

    while (true){
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
    
}

bool checkWinner(char* spaces, char player, char computer) {
    // Define todas as combinações vencedoras
    const int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Linhas horizontais
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Colunas verticais
        {0, 4, 8}, {2, 4, 6}              // Diagonais
    };

    for (int i = 0; i < 8; i++) {
        int a = winCombinations[i][0];
        int b = winCombinations[i][1];
        int c = winCombinations[i][2];

        // Verifica se todas as três casas da combinação atual pertencem ao jogador ou ao computador
        if (spaces[a] == player && spaces[b] == player && spaces[c] == player) {
            std::cout << "YOU WIN!!\n";
            return true;
        } else if (spaces[a] == computer && spaces[b] == computer && spaces[c] == computer) {
            std::cout << "YOU LOSE\n";
            return true;
        }
    }

    return false;
}

bool checkTie(char* spaces){
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
        
    }
    std::cout << "TIE\n";
    
    return true;
}

void clearScreen(){
    system("clear");
}
