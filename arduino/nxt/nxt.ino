#include <Wire.h>
#include <NXShield.h>

NXShield nxshield;
int c = -1;
long            rotations = 2;  // Define variable rotations and set
// equal to 90
char            str[40];

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("Initializing the devices ...");

  nxshield.init (SH_HardwareI2C);

  Serial.println("Press GO button to continue ...");
  nxshield.waitForButtonPress (BTN_GO);

  Serial.println("OK");
  //
  // reset motors.
  //
  nxshield.bank_a.motorReset();
  nxshield.bank_b.motorReset();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    c = Serial.read();
    switch (c) {
      case 2 : // droite
        nxshield.bank_a.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Reverse,
                                          50);
        nxshield.bank_b.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Forward,
                                          50);
        break;
      case 3 : // gauche
        nxshield.bank_a.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Forward,
                                          50);
        nxshield.bank_b.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Reverse,
                                          50);
        break;
      case 4: // avance
        Serial.println("Bank A motors >>");
        sprintf(str, "Motor 1 Forward %d Rotations", rotations);
        Serial.println(str);
        nxshield.bank_a.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Reverse,
                                          100);
        nxshield.bank_b.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Reverse,
                                          100);
        break;
      case 5: // recule

        nxshield.bank_a.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Forward,
                                          100);
        nxshield.bank_b.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Forward,
                                          100);
        break;
      case 6: // arrêt
        nxshield.bank_a.motorStop(SH_Motor_1,
                                  SH_Next_Action_Float);
        nxshield.bank_b.motorStop(SH_Motor_1,
                                  SH_Next_Action_Float);
        break;
    }
  }
}
