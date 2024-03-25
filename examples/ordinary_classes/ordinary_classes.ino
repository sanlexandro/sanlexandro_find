/* 
  библиотека написанна sanlexandro 
  v1.2 от 25.03.24г.
*/
#include "sanlexandro_find.h" //подключаем библиотеку

void setup() {
  Serial.begin(9600); // подключаем serial для просмотра значений

  setFirstComandElement("!"); // задаём первый УНИКАЛЬНЫЙ элемент комманды (все команды должны начинаться с ЕДИНОГО элемента)
  // по умолчанию стоит "!"

  /* 
  класс Data принимает ТОЛЬКО String
  функция findInt("здесь находится имя команды, значение которой необходимо найти") возвращает значение переменной в классе int
  аналогично findString("здесь находится имя команды, значение которой необходимо найти") возвращает значение переменной в классе String
  */

  Data test("!x:12 !y:12 !z:33"); // создаём переменную класса Data и передаём ей значение

  Serial.println(test.findInt("!x:") + 1); // вернёт 13, так как 12 + 1 = 13
  Serial.println(test.findString("!y:")); // вернёт 12
  Serial.println(test.findInt("!z:")); // вернёт 33

  // если команды в строке нет, функция вернёт 0(для int) или "error"(для String)
  test = Data("!example:10");

  Serial.println(test.findInt("!x:")); // вернёт 0
  Serial.println(test.findString("!y:")); // вернёт "error"

  setFirstComandElement("#"); // меняем первый элемент на "#"

  test = Data("#example:10!example:70");

  Serial.println(test.findString("#example:")); // вернёт "10!example:70" так как все команды должны начинаться с ЕДИНОГО элемента

  test = Data("#bool_1:true #bool_2:false #bool_3:1 #bool_4:0 #bool_5:TRUE #bool_6:FALSE #bool_7:TrUe #bool_8:fAlsE"); 
  // собственно для булийных переменных допистимо такое обозначение

  for (int i = 1; i < 9; i++){
    Serial.print("#bool_"); Serial.print(i); Serial.print(":  ");
    if (test.findBool("#bool_" + String(i) + ":") == true){ Serial.println("true");}
    else {Serial.println("false");}
  }
}

void loop() {
}