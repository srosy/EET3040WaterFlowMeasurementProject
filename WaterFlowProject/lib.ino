/**
   Water System Measurement
   Class: EET 3040
   Professor Petersen
   Author(s): Spencer Rosenvall,
   Sterling Hilte, Justin Hart
*/

/*
   Notes:
   Analog reads 0-5V, converts is to digital values 0-1023.


*/

void _setup() {
  //  pinMode(pressurePin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9800);
  Serial << "Water System Measurement Project\n";
  Serial << "EET 3040 Instrumentation and Measurements\n";
  Serial << "Professor Spencer Petersen, FALL 2018\n";
  Serial << "Author(s): Spencer Rosenvall, Sterling Hilte, Justin Hart\n";
  Serial.println();

  Serial << "'+' POWER ON/OFF\n";
  Serial << "'p' Read Pressure\n";
  Serial << "'f' Read Flow rate\n";
  Serial << "'w' Read Power Consumption\n";
  Serial.println();
}

void run_program() {
  while (Serial.available()) {
    user_input = Serial.read(); //Read user input and trigger appropriate function
    switch (user_input) {
      case '+': motorON_OFF(motorOn); break;
      case 'f': getFlowRate(); break;
      case 'w': getPowerConsumption; break;
      case 'p': getPressure(); break;
      default: break;
    }
  }
}

void motorON_OFF(boolean b) {
  motorOn = !motorOn; // toggle
  digitalWrite(motorPin, b);
  Serial << "Power: " << motorOn;
  Serial.println();
}

void readPressure() {
  pressure = analogRead(pressurePin); // Do some converstion here from voltage reading to determine pressure.
}

long getPressure() {
  readPressure();
  Serial << "Pressure: " << pressure << "PSI";
  Serial.println();
}

void readFlow() {
  flowRate = analogRead(flowRatePin); // Do some converstion here from voltage reading to determine Flow. Put into correct units with conversion.
}

long getFlowRate() {
  readFlow();
  Serial << "Flow Rate: " << flowRate << "GPH";
  Serial.println();
}

void readPowerConsumption() {
  powerConsumption = analogRead(powerConsumptionPin); // Do some converstion here from voltage reading to determine pressure.
}

long getPowerConsumption() {
  readPowerConsumption();
  Serial << "Power Consumption: " << powerConsumption << "Watts";
  Serial.println();
}


//if (user_input == 'f')
//{
//  getFlow();
//}
//else if (user_input == 'w')
//{
//  getPowerConsumption();
//}
//
//else if (user_input == 'p')
//{
//  getPressure();
//}
//else
//{
//  Serial.println("Invalid option entered.");
//}





