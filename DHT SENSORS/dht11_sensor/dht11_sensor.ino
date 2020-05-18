//program works by copying the dht.h and dht.cpp libraries
#include "dht.h"
dht DHT;
#define DHT11_PIN 4
double data[5];
double *data_pointer = NULL;
int incomingByte = 0;

void setup(){
  pinMode(DHT11_PIN,INPUT);
  Serial.begin(9600);
  data_pointer = data;
}

void loop(){
  // starting to save temperature  
  DHT.read11(DHT11_PIN);
  *data_pointer = DHT.temperature;

  //increasing pointer's address
  data_pointer = data_pointer + 1;
  if (data_pointer > &data[4]){
    data_pointer = data;
    }
  if (Serial.available() > 0) {
     // read the incoming byte:
    incomingByte = Serial.read();

    //  checking the incoming byte
    if (incomingByte == '1'){
      //printing array of temperatures
      double *ptr = NULL;
      for (ptr = data; ptr <= &data[4]; ptr++){
        Serial.print(*ptr);
        if(ptr == &data[4]){
          Serial.println();
        }
        else {
          Serial.print(',');
        }
      }
    }  
  }
delay(200);
}
