# include "sanlexandro_find.h"

void setup() {
  Serial.begin(9600);

  String string_array[8];
  Data test("!array:[ 1, 2, 3, 4, 5, 6, 7, 8]");

  Serial.print("\nTest 1\n");

  // в функцию передаём команду, затем массив(который нужно заполнить) и длину этого массива
  test.findStringArray("!array:", string_array, 8); 
  for (int i=0; i < 8; i++){
    Serial.println(string_array[i]);
  }

  Serial.print("\nTest 2\n");

  // для int массива аналогично
  int int_array[8];
  test.findIntArray("!array:", int_array, 8);
  for (int i=0; i < 8; i++){
    Serial.println(int_array[i] + 20);
  }

  Serial.print("\nTest 3\n");

  test = Data("!array:{ 1% 2% 3% 4% 5% 6% 7% 8}");
  setArrayEdge ("{"); // также можно поменять символ начала массива
  setArrayCpaser("%"); // и разделитель(не знаю зачем, но можно)
  test.findIntArray("!array:", int_array, 8);
  for (int i=0; i < 8; i++){
    Serial.println(int_array[i] + 20);
  }
}

void loop() {

}
