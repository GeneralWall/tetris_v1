#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


enum duration {
    LEFT,
    RIGHT,
    UP,
    STATIC
};
duration dir = STATIC;


void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;

        }
    }
}


int main()
{
    
    const int ROWS = 20;
    const int COLS = 20;
    int map[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j==0 || j == COLS - 1 || i == ROWS - 1) {
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }

    
    bool objectgrip = false;
    int objectnumber;

    int cubetemp = 1; // чтобы раз в два раза куб шел вниз CT

    //// для куба
    int cubepos[2][2] = { {2,2},{2,2} };
    int cubexpos = COLS / 2;
    int cubeypos = 1;
    

    while (1) {

        system("cls");

        input();

        if (!objectgrip) {

            objectnumber = 0; //rand() % 3;
            objectgrip = true;
        }
        else if (objectgrip) {
            if (objectnumber == 0) { //IF ITS CUBE

                cubetemp++; //CT

                if (cubetemp == 2 && map[cubeypos + 1][cubexpos] == 0 && map[cubeypos + 1][cubexpos + 1] == 0) {  //downnnn

                    cubetemp -= 2; //CT

                    cubeypos++;

                    map[cubeypos][cubexpos] = 2;
                    map[cubeypos - 1][cubexpos] = 2;
                    map[cubeypos][cubexpos + 1] = 2;
                    map[cubeypos - 1][cubexpos + 1] = 2;

                    map[cubeypos - 2][cubexpos] = 0;
                    map[cubeypos - 2][cubexpos + 1] = 0;
                }
                if (dir == RIGHT && map[cubeypos][cubexpos + 2] == 0 && map[cubeypos - 1][cubexpos + 2] == 0) {

                    cubexpos++;

                    map[cubeypos][cubexpos + 1] = 2;
                    map[cubeypos - 1][cubexpos + 1] = 2;

                    map[cubeypos][cubexpos - 1] = 0;
                    map[cubeypos - 1][cubexpos - 1] = 0;
                    dir = STATIC;
                }
                if (dir == LEFT && map[cubeypos][cubexpos - 1] == 0 && map[cubeypos - 1][cubexpos - 1] == 0) {

                   
                    map[cubeypos][cubexpos-1] = 2;
                    map[cubeypos - 1][cubexpos-1] = 2;

                    map[cubeypos][cubexpos + 1] = 0;
                    map[cubeypos - 1][cubexpos + 1] = 0;
                    cubexpos -= 1;
                    dir = STATIC;
                }
                
                if (map[cubeypos + 1][cubexpos] == 1 || map[cubeypos + 1][cubexpos + 1] == 1) {
                    map[cubeypos][cubexpos] = 1;
                    map[cubeypos - 1][cubexpos] = 1;
                    map[cubeypos][cubexpos + 1] = 1;
                    map[cubeypos - 1][cubexpos + 1] = 1;

                    cubexpos = COLS / 2;
                    cubeypos = 1;

                
                }
            }
            //
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (map[i][j] == 2) cout << "6";
                else if (map[i][j] == 1) cout << "#";
                else if (map[i][j] == 0) cout << " ";
            }
            cout << endl;
        }
        Sleep(100);
    }
}
