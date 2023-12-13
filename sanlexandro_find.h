/* 
  библиотека написанна sanlexandro 
  v1.0 от 12 декабря 2023г.
*/
#pragma once
#include "WString.h"
#include "Arduino.h"

class Data {
  public:
    Data(String data_string);

    int findInt(String comand);
    String findString(String comand);
    
    int findIntArrayElement (String comand, int array_size, int index);
    String findStringArrayElement (String comand, int array_size, int index);
  private:
    String _data_string;
};

void setFirstComandElement(String first_comand_element);

void setarrayCpaser(String array_cpaser);