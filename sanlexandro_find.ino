#include "sanlexandro_find.h"

void setup(){
  Serial.begin(9600);

  Data data("!x:1,2,3,4,5");
  //for (int i = 0; i < 5; i ++){ Serial.println(data.findIntArrayElement("!x:", 5, i) + 1);}
}

void loop(){}