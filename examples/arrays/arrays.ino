# include "sanlexandro_find.h"

void setup() {
  Serial.begin(9600);

  String array[8];
  Data test("!array:[1,2,3,4,5,6,7,8]");
  Serial.println(test.findString("!array:"));
  test.findStringArray("!array", array, 8);
  
  for (int i=0; i < 8; i++){
    Serial.println(array[i]);
  }
}

void loop() {

}
