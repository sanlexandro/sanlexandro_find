/* 
  библиотека написанна sanlexandro 
  v1.0 от 12 декабря 2023г.
*/
#include "WString.h"
#include "sanlexandro_find.h"

String _first_comand_element = "!";
void setFirstComandElement(const String& first_comand_element){ _first_comand_element = first_comand_element;}

String _array_cpaser = ",";
void setArrayCpaser(const String& array_cpaser){ _array_cpaser = array_cpaser;}

bool _memory_save = false;
void setMemorySave(const bool& memory_save){ _memory_save = memory_save;}
void getMemory(String *memory_array, const byte &memory_size){ for (byte i; i < memory_size; i++){memory_array[i] = "error";}}

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

  result.trim();
  return result;  //  Возвращаем результат
}

Data::Data (const String& data_string){ // Обозначаем класс и принимаемые данные
  _data_string = data_string;
}

int Data::findInt(const String& comand, String* cell = NULL){ // функция нахождения команды в строке, возвращает int
  String buf = get_comand(_data_string, comand);

  if ((_memory_save == true) and (*cell != NULL)){
    if (buf != "error"){ *cell = buf;}
    buf = *cell;
  }
  return buf.toInt();
}

String Data::findString(const String& comand, String* cell = NULL){ // функция нахождения команды в строке, возвращает string
  String buf = get_comand(_data_string, comand);

   if ((_memory_save == true) and (*cell != NULL)){
    if (buf != "error"){ *cell = buf;}
    buf = *cell;
  }
  return buf;
}

bool Data::findBool(const String& comand, String* cell = NULL){
  String buf = get_comand(_data_string, comand);
  buf.toLowerCase();
  if (_memory_save == true){
    if ((buf != "error") and (*cell != NULL)){ *cell = buf;}
    else {buf = *cell;}
  } 

  if ((buf == "true") or (buf == "1")){ return true;}
  else if ((buf == "false") or (buf == "0")){ return false;}
}