#include <iostream>

void drawBoard(char* spaces) {
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


int main(){
    char spaces[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    drawBoard(spaces);
}