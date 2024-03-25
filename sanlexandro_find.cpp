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

bool _memory_save = true;
void setMemorysave(bool memory_save){ _memory_save = memory_save;}

int _memory_size = 2;
void setMemorysize(const int memory_size){ _memory_size = memory_size;}
String (*memory)[2] = new String[_memory_size][2];


String error_messages[3][2] = {{"String", "error"}, {"int", "0"}, {"bool", "false"}};

void setErrorMessage(const String& error_message, const String& Class){
  for (int i; i < 3; i++){
    if (error_messages[i][0] == Class){
      error_messages[i][1] = String(error_message);
      break;
    }
  }
}

/*
void tryme(){
  String **memory;
  memory = malloc(_memory_size * sizeof(String*));
  memory[0] = malloc(2 * sizeof(String));
}
*/

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

  if (_memory_save == true){
    int new_save;
    for (int i; i < _memory_size; i ++){
      if (memory[i][0] == find){new_save = i; break;}
      else if (memory[i][0] == ""){new_save = i; break;}
    }
    memory[new_save][0] = find;
    memory[new_save][1] = result;
  }
  return result;  //  Возвращаем результат
}

int find_comand_in_memory(const String& comand){
  for(int i; i < _memory_size; i++){
    if (memory[i][0] == comand){return i;}
  }
  return -1;
}

String find_error_message(const String& Class){
  for(int i; i < 3; i++){
    if (error_messages[i][0] == Class){return error_messages[i][1];}
  }
}

Data::Data (const String& data_string){ // Обозначаем класс и принимаемые данные
  _data_string = data_string;
}

int Data::findInt(const String& comand){ // функция нахождения команды в строке, возвращает int
  String buf = get_comand(_data_string, comand);
  if ((_memory_save == true) and (buf == "error") and (find_comand_in_memory(comand) != -1)){ return memory[find_comand_in_memory(comand)][1].toInt();}
  else {return buf.toInt();}
}

String Data::findString(const String& comand){ // функция нахождения команды в строке, возвращает string
  String buf = get_comand(_data_string, comand);
  if ((_memory_save == true) and (buf == "error") and (find_comand_in_memory(comand) != -1)){ return memory[find_comand_in_memory(comand)][1];}
  else {return buf;}
}

bool Data::findBool(const String& comand){
  String buf = get_comand(_data_string, comand);
  if ((_memory_save == true) and (buf == "error") and (find_comand_in_memory(comand) != -1)){ buf = memory[find_comand_in_memory(comand)][1];}
  buf.toLowerCase();
  if ((buf == "true") or (buf == "1")){ return true;}
  else if ((buf == "false") or (buf == "0")){ return false;}
  else{
    if (find_error_message("bool") == "true"){return true;}
    return false;
  }
}

String Data::findStringArrayElement(const String& comand, int array_size, int index){
  String data = get_comand(_data_string, comand) + _array_cpaser;
  String result[array_size];
  for (int counter = 0; counter < array_size; counter++){
    String buf;
    while (String(data[0]) != _array_cpaser){
      buf = buf + data[0];
      data.remove(0, 1);
    }
    data.remove(0, 1);
    result[counter] = buf;
  }
  return result[index];
}

int Data::findIntArrayElement(const String& comand, int array_size, int index){
  String data = get_comand(_data_string, comand) + _array_cpaser;
  int result[array_size];
  for (int counter = 0; counter < array_size; counter++){
    String buf;
    while (String(data[0]) != _array_cpaser){
      buf = buf + data[0];
      data.remove(0, 1);
    }
    data.remove(0, 1);
    result[counter] = buf.toInt();
  }
  return result[index];
}