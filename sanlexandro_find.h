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

    int findInt(const String& comand);
    String findString(const String& comand);
    bool findBool(const String& comand);

  private:
    String _data_string;
};

void setFirstComandElement(const String& first_comand_element);

void setArrayCpaser(const String& array_cpaser);