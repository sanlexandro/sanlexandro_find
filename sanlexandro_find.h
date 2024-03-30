/* 
  библиотека написанна sanlexandro 
  v1.0 от 12 декабря 2023г.
*/
#pragma once
#include "WString.h"
#include "Arduino.h"

class Data {
  public:
    Data(const String& data_string);

    int findInt(const String& comand, String* cell = NULL);
    String findString(const String& comand, String* cell = NULL);
    bool findBool(const String& comand, String* cell = NULL);
    void findStringArray(const String& comand, String* array, const int &array_lenth, String* cell = NULL);
    void findIntArray(const String &comand, int* array, const int &array_lenth, String* cell = NULL);

  private:
    String _data_string;
};

void setFirstComandElement(const String& first_comand_element);

void setArrayCpaser(const String& array_cpaser);

void setMemorySave(const bool& memory_save);

void getMemory(String* memory_array, const byte& memory_size);