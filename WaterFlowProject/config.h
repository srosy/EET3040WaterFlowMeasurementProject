/**
   Water System Measurement
   Class: EEt 3040
   Professor Petersen
   Author(s): Spencer Rosenvall,
   Sterling Hilte, Justin Hart
*/

template<class T> inline Print &operator <<(Print &obj, T arg) {
  obj.print(arg);
  return obj;
}

char user_input;

long pressure;
int pressurePin = A0; // input

long flowRate;
int flowRatePin = A1; // input

long powerConsumption;
int powerConsumptionPin = A2; // input

boolean motorOn = LOW;
int motorPin = 13; // input


