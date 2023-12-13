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
    
  private:
    String _data_string;
};

void setFirstComandElement(String first_comand_element);