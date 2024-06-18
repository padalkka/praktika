#include <iostream>
#include <cstdlib>
#include <string>
//#include <fstream>

//ofstream outFile(File.json)


void SetLocale() { setlocale(LC_ALL, "Ukr"); }

char board[9] = {};

void clearscreen() {
    for (int i = 0; i < 40; i++) {
        std::cout << std::endl;
    }
}

void clearboard() {
    for (int i = 0; i < 9; i++) {
        board[i] = '-';
    }
}

bool has_wonQ(char player) {
    int wins[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
    for (int i = 0; i < 8; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            if (board[wins[i][j]] == player)
                count++;
        }
        if (count == 3) {
            return true;
        }
    }
    return false;
}

void print_board(std::string indent) {
    std::cout << "\n";
    std::cout << indent << "-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-" << std::endl;
    std::cout << indent << "-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-" << std::endl;
    std::cout << indent << "-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-" << std::endl;
}

int get_move() {
    std::cout << "Варiанти ходу:\n";
    std::cout << "\n";
    std::cout << "\t" << "-7-|-8-|-9-" << std::endl;
    std::cout << "\t" << "-4-|-5-|-6-" << std::endl;
    std::cout << "\t" << "-1-|-2-|-3-" << std::endl;
    std::cout << "\n";

    print_board("");
    std::cout << "\nВаш хiд: ";

    int move;
    std::cin >> move;
    while (move > 9 || move < 1 || board[move - 1] != '-') {
        std::cout << "введiть корректний хiд (1-9):\n";
        std::cin >> move;
    }
    return move;
}

char play_and_get_winner() {
    int turn = 1;
    while (!has_wonQ('X') && !has_wonQ('O')) {
        clearscreen();
        int move = get_move();
        clearscreen();
        if (turn % 2 == 1) {
            board[move - 1] = 'X';
            if (has_wonQ('X')) {
                std::cout << "Перемога Х!\n";
                return 'X';
            }
        }
        else {
            board[move - 1] = 'O';
            if (has_wonQ('O')) {
                std::cout << "Перемога 0!\n";
                return 'O';
            }
        }
        turn++;
        if (turn == 10) {
            std::cout << "\t Нічия!\n";
            return 'D';
        }
    }
}

int main() {
    SetLocale(LC_ALL, "Ukr");
    std::cout << "Привіт!\n";
    std::string reply = "y";
    int x_wins = 0, o_wins = 0, ties = 0;
    while (reply == "y") {
        clearboard();
        char winner = play_and_get_winner();
        print_board("\t  ");
        switch (winner) {
        case 'X': x_wins++;
            break;
        case 'O': o_wins++;
            break;
        case 'D': ties++;
            break;
        }
        std::cout << "\n\t*Статистика*\n гравець X: " << x_wins << ", гравець O: " << o_wins << "Нiчия: " << ties << "\n";
        std::cout << "\n зiграти ще? (y/n):";
        std::cin >> reply;
        while (reply != "y" && reply != "n") {
            std::cout << "Введiть вiдповiдь(y/n)";
            std::cin >> reply;
        }
    }
    /*
    ifstream inFile("File.json")

    outFile<<"win x:"<<x_wins<<endl;
    outFile<<"win o:"<<o_wins<<endl;
    outFile<<"tie:"<<ties<<endl;

    string line;
    while (getline(inFile,line)){
    std::cout<<line<<endl;
    }

    inFile,close()
    */

    system("pause");
    return 0;
}


