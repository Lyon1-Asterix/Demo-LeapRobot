#include <Wire.h>
#include <NXShield.h>

NXShield nxshield;

void setup() {
  long            rotations = 2;  // Define variable rotations and set
  // equal to 90
  char            str[40];

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
  // Drive motor 1 forward and backward for a specific number of
  // rotations
  delay(1000);
  Serial.println("Bank A motors >>");
  sprintf(str, "Motor 1 Forward %d Rotations", rotations);
  Serial.println(str);
  str[0] = '\0';
  nxshield.bank_a.motorRunRotations(SH_Motor_1,
                                    SH_Direction_Forward,
                                    SH_Speed_Medium,
                                    rotations,
                                    SH_Completion_Wait_For,
                                    SH_Next_Action_BrakeHold);
  delay(1000);
  sprintf(str, "Motor 1 Reverse %d Rotations", rotations);
  Serial.println(str);
  str[0] = '\0';
  nxshield.bank_a.motorRunRotations(SH_Motor_1,
                                    SH_Direction_Reverse,
                                    SH_Speed_Medium,
                                    rotations,
                                    SH_Completion_Wait_For,
                                    SH_Next_Action_BrakeHold);
}

void loop() {
  // put your main code here, to run repeatedly:

}
