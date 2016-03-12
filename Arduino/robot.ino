int diode[8]; // pins pour les diodes
int moteur[4]; // pins pour les moteurs
int c = -1;

void setup() {
    Serial.begin(115200); //set serial with baud rate
    // initialisation des diodes
    for (int i = 0; i < 6; i++) {
        diode[i] = 2 + i;
    }

    diode[6] = 12;
    diode[7] = 13;

    // initialisation des moteurs
    moteur[0] = 5;
    moteur[1] = 6;
    moteur[2] = 10;
    moteur[3] = 11;

    for (int i = 0; i < 4; i++)  {
        pinMode (moteur[i], OUTPUT);
    }

    for (int i = 0; i < 8; i++) {
        pinMode (diode[i], OUTPUT);
    }
}

void loop() {
    if (Serial.available() > 0) {  //if we have incoming value
        c = Serial.read();

        switch (c) {
        case 0 : // On éteint tout
            for (int i = 0; i < 10; i++) {
                digitalWrite (diode[i], LOW);
                delay (10);
            }
            break;

        case 1: // On allume tout
            for (int i = 0; i < 10; i++) {
                digitalWrite (diode[i], HIGH);
                delay (10);
            }
            break;
        case 2: // Droite
            analogWrite (moteur[0], 150);
            analogWrite (moteur[1], 0);
            analogWrite (moteur[2], 0);
            analogWrite (moteur[3], 0);
            break;

        case 3: // Gauche
            analogWrite (moteur[0], 0);
            analogWrite (moteur[1], 0);
            analogWrite (moteur[2], 0);
            analogWrite (moteur[3], 150);
            break;

        case 4: // Haut
            analogWrite (moteur[0], 150);
            analogWrite (moteur[1], 0);
            analogWrite (moteur[2], 150);
            analogWrite (moteur[3], 0);
            break;

        case 5: // Bas
            analogWrite (moteur[0], 0);
            analogWrite (moteur[1], 150);
            analogWrite (moteur[2], 0);
            analogWrite (moteur[3], 150);
            break;
        
        default: break;

            //motor ();
        }
    }
}
