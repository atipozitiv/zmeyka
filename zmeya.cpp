/**********************************
* ПИ-221                          *
* Иванов Тимофей                  *
* Змейка                          *
* 29.11.2022                      *
**********************************/

#include <iostream>
#include <windows.h>
#include <locale.h>
#include <string>
//мб нужен math
using namespace std;

int snakeHead[2] = {2, 7};
int apple[2];
int tailLength = 2;
int score = 0;
bool alive = true;
char orientation = 's';

void firstMiniature() {
  cout << " Zmeyka    ih     k     lqsdfh\n";
  Sleep(500);
  cout << "      o    d m    q     a\n";
  cout << "     o     p f   p q    w\n";
  Sleep(500);
  cout << "    o     f   d  d  a   qdsfg\n";
  cout << "   o      g   w w   e   r\n";
  Sleep(500);
  cout << "  o      i     y     q  s\n";
  cout << " Zmeyka  m     v     s  arwrtf\n\n";
  Sleep(1000);
  cout << " Y     E   K   W         A\n";
  Sleep(300);
  cout << "  L   Q    E  Q         D Q\n";
  Sleep(50);
  cout << "   E S     ZDB         F   E\n";
  Sleep(300);
  cout << "    D      X  F       QDSQKE\n";
  Sleep(300);
  cout << "   S       Q   W     E      Q\n";
  Sleep(100);
  cout << "  K        D    A   R        S\n\n";
  Sleep(2000);
}

void secondMiniature() {
  while (true) {
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
    system("cls");
  }
} 

/*                ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
 карта:           |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  |                             |
                  '''''''''''''''''''''''''''''''

                  счет: 
*/

// 0 - ничего ; 1 - тело ; 2 - голова
int snakeOnMap[13][15] = { {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

int tailString[200];
int tailColumn[200];
tailString[0] = 0;
tailColumn[0] = 7;
tailString[1] = 1;
tailColumn[1] = 7;
int turnForTail = 0;

void workWithTail() {
  snakeOnMap[tailString[turnForTail]][tailColumn[turnForTail]] = 0;
  int position = (turnForTail + tailLength) % 200;
  tailString[position] = snakeHead[0];
  tailColumn[position] = snakeHead[1];
  turnForTail += 1;
  turnForTail = turnForTail % 200;
}

void moveSnake() {
  if (orientation == 's') {
    if ((snakeHead[0] == 12) || (snakeOnMap[snakeHead[0] + 1][snakeHead[1]] == 1)) alive = false;
    snakeHead[0] += 1;
    snakeOnMap[snakeHead[0]][snakeHead[1]] = 2;
    snakeOnMap[snakeHead[0] - 1][snakeHead[1]] = 1;
  }
  if (orientation == 'w') {
    if ((snakeHead[0] == 0) || (snakeOnMap[snakeHead[0] - 1][snakeHead[1]] == 1)) alive = false;
    snakeHead[0] -= 1;
    snakeOnMap[snakeHead[0]][snakeHead[1]] = 2;
    snakeOnMap[snakeHead[0] + 1][snakeHead[1]] = 1;
  }
  if (orientation == 'a') {
    if ((snakeHead[1] == 0) || (snakeOnMap[snakeHead[0]][snakeHead[1] - 1] == 1)) alive = false;
    snakeHead[1] -= 1;
    snakeOnMap[snakeHead[0]][snakeHead[1]] = 2;
    snakeOnMap[snakeHead[0]][snakeHead[1] + 1] = 1;
  }
  if (orientation == 'd') {
    if ((snakeHead[1] == 14) || (snakeOnMap[snakeHead[0]][snakeHead[1] + 1] == 1)) alive = false;
    snakeHead[1] += 1;
    snakeOnMap[snakeHead[0]][snakeHead[1]] = 2;
    snakeOnMap[snakeHead[0]][snakeHead[1] - 1] = 1;
  }
}

void spawnApple() {
  
  rand()
}

char checkPosition(int string, int column) {
  if (snakeOnMap[string][column] == 0) return ' ';
  if (snakeOnMap[string][column] == 1) return '*';
  if (snakeOnMap[string][column] == 2) return '0';
  return 'A';
}

void playGame() {
  workWithTail();
  moveSnake();
  string gameWindow = ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
  for (int snakeString = 0; snakeString < 13; ++snakeString) {
    gameWindow += "|";
    for (int snakeColumn = 0; snakeColumn < 14; ++snakeColumn) {
      gameWindow = gameWindow + checkPosition(snakeString, snakeColumn) + " ";
    }
    gameWindow = gameWindow + checkPosition(snakeString, 14) + "|\n";
  }
  gameWindow = gameWindow + "'''''''''''''''''''''''''''''''\n\nсчет: " + to_string(score);
  system("cls");
  cout << gameWindow;

}

int main() {
  system("mode con cols=31 lines=17");
  setlocale(LC_ALL, "Russian");
  firstMiniature();
  system("pause");
  system("cls");
  playGame();
  Sleep(350);

  int speed = 0;
  while (alive) {
    if (GetAsyncKeyState(0x57)) orientation = 'w';
    if (GetAsyncKeyState(0x41)) orientation = 'a';
    if (GetAsyncKeyState(0x53)) orientation = 's';
    if (GetAsyncKeyState(0x44)) orientation = 'd';
    if (speed == 49999) playGame();
    ++speed;
    speed = speed % 50000;
  }

  system("cls");
  secondMiniature();
  return 0;
}
