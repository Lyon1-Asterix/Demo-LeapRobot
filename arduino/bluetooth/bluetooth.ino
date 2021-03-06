/* Copyright 2016 Ghayth Bouagila & Hedi Nasr */

/* Licensed under the Apache License, Version 2.0 (the "License"); */
/* you may not use this file except in compliance with the License. */
/* You may obtain a copy of the License at */

/*     http://www.apache.org/licenses/LICENSE-2.0 */

/* Unless required by applicable law or agreed to in writing, software */
/* distributed under the License is distributed on an "AS IS" BASIS, */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/* See the License for the specific language governing permissions and */
/* limitations under the License. */

#define START_CMD_CHAR '*'
#define END_CMD_CHAR '#'
#define DIV_CMD_CHAR '|'
#define CMD_DIGITALWRITE 10
#define CMD_ANALOGWRITE 11
#define CMD_TEXT 12
#define CMD_READ_ARDUDROID 13
#define MAX_COMMAND 20  // max command number code. used for error checking.
#define MIN_COMMAND 10  // minimum command number code. used for error checking. 
#define IN_STRING_LENGHT 40
#define MAX_ANALOGWRITE 255
#define PIN_HIGH 3
#define PIN_LOW 2

int mtd1 = 5;
int mtd2 = 6;
int mtg1 = 10;
int mtg2 = 11;

String inText;

void setup() {
  Serial.begin(9600);
  Serial.println("ArduDroid 0.12 Alpha by TechBitar (2013)");
  Serial.flush();
}

void loop()
{
  Serial.flush();
  int ard_command = 0;
  int pin_num = 0;
  int pin_value = 0;

  char get_char = ' ';  //read serial

  // wait for incoming data
  if (Serial.available() < 1) return; // if serial empty, return to loop().

  // parse incoming command start flag
  get_char = Serial.read();
  if (get_char != START_CMD_CHAR) return; // if no command start flag, return to loop().

  // parse incoming command type
  ard_command = Serial.parseInt(); // read the command

  // parse incoming pin# and value
  pin_num = Serial.parseInt(); // read the pin
  pin_value = Serial.parseInt();  // read the value

  // 1) GET TEXT COMMAND FROM ARDUDROID
  if (ard_command == CMD_TEXT) {
    inText = ""; //clears variable for new input
    while (Serial.available())  {
      char c = Serial.read();  //gets one byte from serial buffer
      delay(5);
      if (c == END_CMD_CHAR) { // if we the complete string has been read
        // add your code here
        break;
      }
      else {
        if (c !=  DIV_CMD_CHAR) {
          inText += c;
          delay(5);
        }
      }
    }
  }

  // 2) GET digitalWrite DATA FROM ARDUDROID
  if (ard_command == CMD_DIGITALWRITE) {
    if (pin_value == PIN_LOW) pin_value = LOW;
    else if (pin_value == PIN_HIGH) pin_value = HIGH;
    else return; // error in pin value. return.
    set_digitalwrite( pin_num,  pin_value);  // Uncomment this function if you wish to use
    return;  // return from start of loop()
  }

  // 3) GET analogWrite DATA FROM ARDUDROID
  if (ard_command == CMD_ANALOGWRITE) {
    analogWrite(  pin_num, pin_value );
    // add your code here
    return;  // Done. return to loop();
  }

  // 4) SEND DATA TO ARDUDROID
  if (ard_command == CMD_READ_ARDUDROID) {
    // char send_to_android[] = "Place your text here." ;
    // Serial.println(send_to_android);   // Example: Sending text
    Serial.print(" Analog 0 = ");
    Serial.println(analogRead(A0));  // Example: Read and send Analog pin value to Arduino
    return;  // Done. return to loop();
  }
}

// 2a) select the requested pin# for DigitalWrite action
void set_digitalwrite(int pin_num, int pin_value)
{
  switch (pin_num) {
    case 13: // Droite
      pinMode(13, OUTPUT);
      digitalWrite(13, pin_value);
      Serial.println("Droite");
      analogWrite(mtd1, 200);
      analogWrite(mtd2, 0);
      analogWrite(mtg1, 0);
      analogWrite(mtg2, 0);
      break;
    case 12: // Haut
      pinMode(12, OUTPUT);
      digitalWrite(12, pin_value);
      Serial.println("Haut");
      analogWrite(mtd1, 200);
      analogWrite(mtd2, 0);
      analogWrite(mtg1, 140);
      analogWrite(mtg2, 0);
      break;
    case 11:
      pinMode(11, OUTPUT);
      digitalWrite(11, pin_value);
      // add your code here
      break;
    case 10: // Gauche
      pinMode(10, OUTPUT);
      digitalWrite(10, pin_value);
      Serial.println("Gauche");
      analogWrite(mtd1, 0);
      analogWrite(mtd2, 0);
      analogWrite(mtg1, 140);
      analogWrite(mtg2, 0);
      break;
    case 9:
      pinMode(9, OUTPUT);
      digitalWrite(9, pin_value);
      // add your code here
      break;
    case 8: // Stop
      pinMode(8, OUTPUT);
      digitalWrite(8, pin_value);
      Serial.println("Stop");
      analogWrite(mtd1, 0);
      analogWrite(mtd2, 0);
      analogWrite(mtg1, 0);
      analogWrite(mtg2, 0);

      // add your code here
      break;
    case 7: // Bas
      pinMode(7, OUTPUT);
      digitalWrite(7, pin_value);
      Serial.println("Bas");
      analogWrite(mtd1, 0);
      analogWrite(mtd2, 200);
      analogWrite(mtg1, 0);
      analogWrite(mtg2, 140);
      // add your code here
      break;
    case 6:
      pinMode(6, OUTPUT);
      digitalWrite(6, pin_value);
      // add your code here
      break;
    case 5:
      pinMode(5, OUTPUT);
      digitalWrite(5, pin_value);
      // add your code here
      break;
    case 4:
      pinMode(4, OUTPUT);
      digitalWrite(4, pin_value);
      // add your code here
      break;
    case 3:
      pinMode(3, OUTPUT);
      digitalWrite(3, pin_value);
      // add your code here
      break;
    case 2:
      pinMode(2, OUTPUT);
      digitalWrite(2, pin_value);
      // add your code here
      break;
      // default:
      // if nothing else matches, do the default
      // default is optional
  }
}
