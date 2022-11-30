/**********************************
* ПИ-221                          *
* Иванов Тимофей                  *
* Змейка                          *
* 29.11.2022                      *
**********************************/

#include <iostream>
#include <windows.h>
#include <locale.h>
using namespace std;

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
  Sleep(2000);
  cout << " Y     E   K   W         A\n";
  cout << "  L   Q    E  Q         D Q\n";
  cout << "   E S     ZDB         F   E\n";
  cout << "    D      X  F       QDSQKE\n";
  cout << "   S       Q   W     E      Q\n";
  cout << "  K        D    A   R        S\n";
  Sleep(2000);
}

void secondMiniature() {
  cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
  cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
  cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
  cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
  cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
  cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
  cout << "ТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\nТЫПРОИГРАЛТЫПРОИГРАЛТЫПРОИГРАЛ\n";
}

void playGame() {
  cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
  cout << "|                             |\n";
  cout << "|              *              |\n";
  cout << "|              *              |\n";
  cout << "|              0              |\n";
  cout << "|                             |\n";
  cout << "|                             |\n";
  cout << "|                             |\n";
  cout << "|                             |\n";
  cout << "|                             |\n";
  cout << "|                             |\n";
  cout << "|                             |\n";
  cout << "'''''''''''''''''''''''''''''''";
}        

void moveHead() {
  if (orientation == 's') {

  }
}

void deleteTail() {
  //удалить хвост(можно будет 
}

void spawnApple() {
  //удалить старое яблоко и создать новое
}

int apple[2];
bool alive = true;
int snakesHead[2] = {8, 4};
int sneakesTail[2] = {0, 0};
char orientation = 's';

int main() {
  system("mode con cols=31 lines=20");
  setlocale(LC_ALL, "Russian");
  firstMiniature();
  system("pause");
  system("cls");
  playGame();

  while (alive) {
    if (GetAsyncKeyState(0x57)) orientation = 'w';
    if (GetAsyncKeyState(0x41)) orientation = 'a';
    if (GetAsyncKeyState(0x53)) orientation = 's';
    if (GetAsyncKeyState(0x44)) orientation = 'd';
    moveHead();
    if ((snakesHead[0] == apple[0]) && (snakesHead[1] == apple[1])) {
      spawnApple();
    } else {
      deleteTail();
    }
  }

  system("cls");
  secondMiniature();
  Sleep(3000);
  return 0;
}
