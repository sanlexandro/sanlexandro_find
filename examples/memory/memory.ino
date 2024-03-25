#include "sanlexandro_find.h"

void setup(){
  Serial.begin(9600);

  String memory[2]; //создаём массив с памятью

  Data test = Data("!test:15345 !new:test_text"); //обявляем переменную

  setMemorySave(true); //включаем запись памяти (bool вкл/выкл)
  getMemory(memory, 2); // передаём адресс памяти (массив памяти, размер памяти)

  Serial.print("!test:  "); Serial.println(test.findString("!test:", &memory[0])); // ищем команду и передаём ссылку на ячейку массива, в которую хотим сохранить переменную

  test = Data("!new:231");

  Serial.print("\n!test:  "); Serial.println(test.findString("!test:", &memory[0])); 
  // собственно в строке команды нет, но ,т. к. включено сохранение памяти,
  // программа вернёт значение из памяти.

  Serial.print("\n!new:  "); Serial.println(test.findString("!new:", &memory[1]));

  Serial.print("\n!test:  "); Serial.println(test.findString("!test:")); // если не передать ячейку памяти, то программа вернёт то, что найдёт

  setMemorySave(false); // если память отключить, то прога, аналогично, вернёт то, что найдёт
  Serial.print("\n!test:  "); Serial.println(test.findString("!test:", &memory[0])); 
}

void loop(){

}