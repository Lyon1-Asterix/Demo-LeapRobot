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
     nxshield.bank_a.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Reverse,
                                          100);
        nxshield.bank_b.motorRunUnlimited(SH_Motor_1,
                                          SH_Direction_Reverse,
                                          100);
}