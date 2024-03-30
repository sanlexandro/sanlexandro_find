#include "sanlexandro_find.h"

void setup(){
  Serial.begin(9600);

  String memory[10]; //создаём массив с памятью, такой величины, которую вам необходимо сохранять

  Data test = Data("!test:15345 !new:test_text"); //обявляем переменную

  setMemorySave(true); //включаем запись памяти (bool вкл/выкл)
  getMemory(memory, 10); // передаём адресс памяти (массив памяти, размер памяти)

  Serial.print("!test:  "); Serial.println(test.findString("!test:", &memory[0])); // ищем команду и передаём ссылку на ячейку массива, в которую хотим сохранить переменную

  test = Data("!new:231");

  Serial.print("\n!test:  "); Serial.println(test.findString("!test:", &memory[0])); 
  // собственно в строке команды нет, но ,т. к. включено сохранение памяти,
  // программа вернёт значение из памяти.

  Serial.print("\n!new:  "); Serial.println(test.findString("!new:", &memory[1]));

  Serial.print("\n!test:  "); Serial.println(test.findString("!test:")); // если не передать ячейку памяти, то программа вернёт то, что найдёт

  setMemorySave(false); // если память отключить, то прога, аналогично, вернёт то, что найдёт
  Serial.print("\n!test:  "); Serial.println(test.findString("!test:", &memory[0])); 

  //////////////////////////////////
  Serial.print("\n\n");
  //////////////////////////////////
  
  String array[10];
  test = Data("!array:[ 1, 2, 3, 4, 5, 6, 7, 8, 9, hello]");// собственно у массивов всё работает аналогично
  setMemorySave(true);
  
  test.findStringArray("!array:", array, 10, &memory[2]);
  for (int i=0; i < 10; i++){
    Serial.println(array[i]);
  }

  test = Data("example");

  test.findStringArray("!array:", array, 10, &memory[2]);
  for (int i=0; i < 10; i++){
    Serial.println(array[i]);
  }
}

void loop(){

}