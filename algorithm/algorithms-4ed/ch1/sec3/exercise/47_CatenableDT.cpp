#include "CircularLinkedList.h"

int main() {
  CircularLinkedList cir1{1,2,3};
  CircularLinkedList cir2{4,5,6};
  cir1.catenation(&cir2);
  cir1.display();

  return 0;
}
