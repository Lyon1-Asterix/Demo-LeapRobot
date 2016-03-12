int pin[10];
int c = -1;

void setup() {
  // initialisation des pins
  Serial.begin(115200); //set serial with baud rate
  for (int i = 0; i < 10; i++) {
    pin[i] = 2 + i;
    pinMode (pin[i], OUTPUT);
  }    
}

void loop() {
  if (Serial.available() > 0) {  //if we have incoming value
    c = Serial.read();

    switch (c) {
      case 0 :
        for (int i = 0; i < 10; i++) {
          digitalWrite (pin[i], LOW);
          delay (50);
        }
      break;

      case 1:
        for (int i = 0; i < 10; i++) {
          digitalWrite (pin[i], HIGH);
          delay (50);
        }
      break;

      default: break;
    }
  }
}
