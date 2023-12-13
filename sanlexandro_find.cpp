/* 
  библиотека написанна sanlexandro 
  v1.0 от 12 декабря 2023г.
*/
#include "WString.h"
#include "sanlexandro_find.h"

String _first_comand_element = "!";
void setFirstComandElement(String first_comand_element){ _first_comand_element = first_comand_element;}

String get_comand(String data, String find){ //  Функция для нахождения команд в строке
  while (not(data.startsWith(_first_comand_element)) and (data.length() > 0)) data.remove(0, 1); //  Пока строка не начинается со стартого символа команды, удаляем первый символ
  String result;  //  Выделение места под запист результата
  int remove = data.indexOf(find);  //  Находим индекс нахождения переданного значения find
  if (remove == -1){return "error";}
  data.remove(0, remove + find.length());  //  Вылеляем команду слева
  while (data.length() > 0){  //  Обрезаем команду справа, пока длина data больше нуля
    result += data[0];
    data.remove(0, 1);
  }
  remove = result.indexOf(_first_comand_element); //  Находим осталась ли команда
  if (remove != -1){result.remove(remove);} //  Если есть очищаем
  return result;  //  Возвращаем результат
}

Data::Data (String data_string){ // Обозначаем класс и принимаемые данные
  _data_string = data_string;
}

int Data::findInt(String comand){ // функция нахождения команды в строке, возвращает int
  return get_comand(_data_string, comand).toInt();
}
String Data::findString(String comand){ // функция нахождения команды в строке, возвращает string
  return get_comand(_data_string, comand);
}