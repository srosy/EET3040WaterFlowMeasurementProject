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

int numTimesToCheckForSignal = 10000;
long flowRate;
int flowRatePin = 8; // input

int motorPin = 6; // output


