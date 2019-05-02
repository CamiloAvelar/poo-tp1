#include <iostream>

#include "../include/Util.h"
#include "../include/Operations.h"
#define OFF 0

using namespace std;

int main() {

  Operations* operations = Operations::getInstance(); // Classe singleton, o construtor é privado, assim que ela é instaciada.

  int option = -1;

  while (option != OFF) {

    switch(option) {
      case 1:
        operations->operation1();
        option = Util::waitForAction(option);
        break;
      case 2:
        operations->operation2();
        option = Util::waitForAction(option);
        break;
      case 3:
        operations->operation3();
        option = Util::waitForAction(option);
        break;
      case 4:
        operations->operation4();
        option = Util::waitForAction(option);
        break;
      case 5:
        operations->operation5();
        option = Util::waitForAction(option);
        break;
      case 6:
        operations->operation6();
        option = Util::waitForAction(option);
        break;
      case 7:
        operations->operation7();
        option = Util::waitForAction(option);
        break;
      case 8:
        operations->operation8();
        option = Util::waitForAction(option);
        break;
      case 9:
        operations->createDesempregado();
        option = Util::waitForAction(option);
        break;
      case 10:
        operations->createVaga();
        option = Util::waitForAction(option);
        break;
      default:
        option = Util::displayAction();
        break;
    }
  }

  return 0;
}