/**********************************
* ПИ-221                          *
* Иванов Тимофей                  *
* Змейка                          *
* 29.11.2022                      *
**********************************/

#include <iostream>
#include <conio.h>  // для getch
#include <windows.h>
using namespace std;

bool alive = true;

void firstMiniature() {
  cout << " Zmeyka    ih     k     lqsdfh\n";
  sleep(500);
  cout << "      o    d m    q     a\n";
  cout << "     o     p f   p q    w\n";
  sleep(500);
  cout << "    o     f   d  d  a   qdsfg\n";
  cout << "   o      g   w w   e   r\n";
  sleep(500);
  cout << "  o      i     y     q  s\n";
  cout << " Zmeyka  m     v     s  arwrtf\n\n";
  sleep(2000);
  cout << " Y     E  K   W         A\n";
  cout << "  L   Q   E  Q         D Q\n";
  cout << "   E S    ZDB         F   E\n";
  cout << "    D     X  F       QDSQKE\n";
  cout << "   S      Q   W     E      Q\n";
  cout << "  K       D    A   R        S\n";
  sleep(2000);
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
  cout << ",,,,,,,,,,,,,,,,,,,,,,,\n";
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "|                     |\n" << flush;
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "|                     |\n";
  cout << "'''''''''''''''''''''''";
}

int snakesHead[2] = {1, 6}; 

int main() {
  firstMiniature();
  system("pause");
  system("cls");
  while (alive) {
    playGame();
  }
  system("cls");
  secondMiniature();
  return 0;
}
