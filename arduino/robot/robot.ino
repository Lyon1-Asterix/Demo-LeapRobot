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

int diode[8]; // pins pour les diodes
int moteur[4]; // pins pour les moteurs
int c = -1;
bool semaphore = false;

void setup() {
  Serial.begin(115200); //set serial with baud rate
  // initialisation des diodes
  diode[0] = 2;
  diode[1] = 3;
  diode[2] = 4;
  diode[3] = 7;
  diode[4] = 8;
  diode[5] = 9;
  diode[6] = 12;
  diode[7] = 13;

  // initialisation des moteurs
  moteur[0] = 5;
  moteur[1] = 6;
  moteur[2] = 10;
  moteur[3] = 11;

  for (int i = 0; i < 8; i++) {
    pinMode (diode[i], OUTPUT);
    // RAZ des diodes
    digitalWrite (diode[i], LOW);
  }

  for (int i = 0; i < 4; i++) {
    pinMode (moteur[i], OUTPUT);
    // RAZ des moteurs
    analogWrite (moteur[i], 0);
  }

  semaphore = false;
}

void loop() {
  if (Serial.available() > 0) {  //if we have incoming value
    c = Serial.read();

    switch (c) {
      // DIODES
      case 0 : // On éteint tout
        if (!semaphore) {
          semaphore = true;
          for (int i = 0; i < 8; i++) {
            digitalWrite (diode[i], LOW);
            //delay (50);
          }
        }
        semaphore = false;

        break;

      case 1: // On allume tout

        if (!semaphore) {
          semaphore = true;
          for (int i = 0; i < 8; i++) {
            digitalWrite (diode[i], HIGH);
            //delay (50);
          }
        }
        semaphore = false;

        break;
      // MOTEURS
      case 2: // Droite

        if (!semaphore) {
          semaphore = true;
          analogWrite (moteur[0], 250);
          analogWrite (moteur[1], 0);
          analogWrite (moteur[2], 0);
          analogWrite (moteur[3], 0);
        }
        semaphore = false;

        break;

      case 3: // Gauche
        if (!semaphore) {
          semaphore = true;
          analogWrite (moteur[0], 0);
          analogWrite (moteur[1], 0);
          analogWrite (moteur[2], 200);
          analogWrite (moteur[3], 0);
        }
        semaphore = false;

        break;

      case 4: // Haut

        if (!semaphore) {
          semaphore = true;
          analogWrite (moteur[0], 250);
          analogWrite (moteur[1], 0);
          analogWrite (moteur[2], 200);
          analogWrite (moteur[3], 0);
        }
        semaphore = false;

        break;

      case 5: // Bas
        if (!semaphore) {
          semaphore = true;
          analogWrite (moteur[0], 0);
          analogWrite (moteur[1], 250);
          analogWrite (moteur[2], 0);
          analogWrite (moteur[3], 200);
        }
        semaphore = false;

        break;

      case 6: // Arrêt
        if (!semaphore) {
          semaphore = true;
          analogWrite (moteur[0], 0);
          analogWrite (moteur[1], 0);
          analogWrite (moteur[2], 0);
          analogWrite (moteur[3], 0);
        }
        semaphore = false;

        break;

      default: break;
    }
  }
}
