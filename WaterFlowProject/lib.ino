/**
   Water System Measurement
   Class: EET 3040
   Professor Petersen
   Author(s): Spencer Rosenvall,
   Sterling Hilte, Justin Hart
*/

/*
   @Justin:
   I made the interface easy to use. To start using the code do this: (tools -> port -> (select port com 1,2,3...), press upload,
   finally press ctrl+shift+m. All that needs to be tested is that we're getting an accurate count
   of the pulse signal from the flow meter. Use the duration to determine how many reads it takes to get
   close to one second of checking and from there we can do math and figure out the flow rate... At least,
   theroetically.

   Notes:
   Analog reads 0-5V, converts is to digital values 0-1023.

   Flow Meter:
   Each pulse is approximately 2.25 milliliters. Note this isn't a precision sensor,
   and the pulse rate does vary a bit depending on the flow rate, fluid pressure and sensor orientation.
   It will need careful calibration if better than 10% precision is required.

   Pump: Pacific Hydrostar 68395 .23 A, 264 GPH
*/

void _setup() {
  Serial.begin(9800);
  Serial << "Water System Measurement Project\n";
  Serial << "EET 3040 Instrumentation and Measurements\n";
  Serial << "Professor Spencer Petersen, FALL 2018\n";
  Serial << "Author(s): Spencer Rosenvall, Sterling Hilte, Justin Hart\n";
  Serial.println();

  pinMode(flowRatePin, INPUT); // might have to add pulldown resistor to ground and input to get clear signals.
  pinMode(motorPin, OUTPUT);
  motorOFF(); // initialize pump off
  help();
}

void run_program() {
  while (Serial.available()) {
    user_input = Serial.read(); //Read user input and trigger appropriate function
    switch (user_input) {
      //case '+': motorON(); break;
      //case '-': motorOFF(); break;
      case 't': testFlowReading(); break;
      case 'f': getFlowRate(); break;
      case 'h': help(); break;
      default: Serial << "not a command."; break;
    }
  }
}

void help() {
  Serial << "Help Menu:\n";
  //Serial << "'+' POWER ON\n";
  //Serial << "'-' POWER OFF\n";
  Serial << "'f' Read Flow rate\n";
  Serial << "'t' Test Flow rate\n";
  Serial.println();
}

void testMotor() { // test relay operation
  motorON();
  delay(1000);
  motorOFF();
  delay(1000);
}

void motorON() {
  digitalWrite(motorPin, LOW); // reverse logic for relays
  Serial << "Power: HIGH" << "\n";
}

void motorOFF() {
  //motorOn = !motorOn;
  digitalWrite(motorPin, HIGH);
  Serial << "Power: LOW";
  //  Serial << "PowerPin: " << motorPin;
  Serial.println();
}

void testFlowReading() { // test to see if arduino detects pulses from flow meter
  int count = 0;
  //Serial << "Starting Flow Test\n";
  //while (true) {
  if (digitalRead(flowRatePin)) {
    count ++;
    Serial << "Pulse Detected\n";
  }
  //if (count == 5) break;
  //}
  //Serial << "Flow Test Done";
  Serial << "count: " << count << "\n";
}

int readFlow() { // return count of pulses
  int count = 0;
  for (int i = 0; i < numTimesToCheckForSignal; i++) { // numTimesToCheckForSignal change this number around until duration is close to 1000 milliseconds.
    if (digitalRead(flowRatePin)) count++;
  }
  return count;
}

long getFlowRate() {
  int startTime = millis();
  int pulses = ((readFlow() * 2.25) / 3785.41); // Unit conversions into gals (pulses * 2.25ml per pulse) * ( 1 gal / 3785.41)
  float duration = (millis() - startTime); // get total milliseconds of duration
  Serial << "Duration: " << duration << "\n";
  flowRate = (pulses / duration);
  Serial << "Flow Rate: " << flowRate << "GPH\n";
  Serial.println();
}






