```cpp
#include <AccelStepper.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// ========================= PINS =========================

#define ENA 8
#define ENB 9

#define RELAY_PIN 7

#define IR_SENSOR_PIN 13

#define BUZZER_PIN 6

// ========================= STEPPER =========================

const int stepsPerRevolution = 200;

AccelStepper myStepper(
  AccelStepper::FULL4WIRE,
  2, 3, 4, 5
);

// ========================= SERVOS =========================

Servo servoArm;
Servo servoLift;
Servo servoDoor;

// ========================= LCD =========================

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ========================= KEYPAD =========================

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {0, 1, 6, 7};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);

// ========================= VARIABLES =========================

bool systemStarted = false;

// ========================= FUNCTIONS =========================

// Smooth Servo Movement
void moveServoSmoothly(
  Servo &servo,
  int startPos,
  int endPos,
  int stepDelay
) {

  if (startPos < endPos) {

    for (int pos = startPos; pos <= endPos; pos += 2) {

      servo.write(pos);
      delay(stepDelay);
    }

  } else {

    for (int pos = startPos; pos >= endPos; pos -= 2) {

      servo.write(pos);
      delay(stepDelay);
    }
  }
}

// Buzzer Alert
void playAlert(int times) {

  for (int i = 0; i < times; i++) {

    digitalWrite(BUZZER_PIN, HIGH);
    delay(300);

    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  }
}

// Rotate Medicine Tray
void rotateTray(int rotations) {

  for (int i = 0; i < rotations; i++) {

    myStepper.move(stepsPerRevolution / 2);

    while (myStepper.distanceToGo() != 0) {

      myStepper.run();
    }

    Serial.println("Tray Rotated 180 Degrees");
  }
}

// Pick Pill
void pickPill() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Picking Pill");

  servoArm.write(90);
  delay(700);

  moveServoSmoothly(servoLift, 0, 180, 15);
  delay(500);

  digitalWrite(RELAY_PIN, HIGH);

  lcd.setCursor(0, 1);
  lcd.print("Vacuum ON");

  delay(5000);

  moveServoSmoothly(servoLift, 180, 0, 15);
  delay(500);

  servoArm.write(180);
  delay(700);
}

// Release Pill
void releasePill() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Delivering");

  servoArm.write(90);
  delay(700);

  moveServoSmoothly(servoLift, 0, 180, 15);

  digitalWrite(RELAY_PIN, LOW);

  lcd.setCursor(0, 1);
  lcd.print("Pill Released");

  delay(2000);

  moveServoSmoothly(servoLift, 180, 0, 15);

  servoArm.write(180);
  delay(700);
}

// Check Medication Intake
void checkMedicationTaken() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Take Medicine");

  playAlert(3);

  unsigned long startTime = millis();

  while (millis() - startTime < 10000) {

    if (digitalRead(IR_SENSOR_PIN) == HIGH) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Medicine Taken");

      servoDoor.write(90);

      delay(3000);

      servoDoor.write(0);

      return;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dose Missed");

  playAlert(5);
}

// ========================= SETUP =========================

void setup() {

  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(RELAY_PIN, OUTPUT);

  pinMode(IR_SENSOR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  servoArm.attach(10);
  servoLift.attach(11);
  servoDoor.attach(12);

  lcd.init();
  lcd.backlight();

  myStepper.setMaxSpeed(500);
  myStepper.setAcceleration(250);

  servoArm.write(180);
  servoLift.write(0);
  servoDoor.write(0);

  lcd.setCursor(0, 0);
  lcd.print("Smart Pill");

  lcd.setCursor(0, 1);
  lcd.print("Organizer");

  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press A Start");
}

// ========================= LOOP =========================

void loop() {

  char key = keypad.getKey();

  if (key == 'A') {

    systemStarted = true;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Started");

    delay(2000);
  }

  if (systemStarted) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Medication Time");

    playAlert(2);

    delay(2000);

    rotateTray(6);

    pickPill();

    rotateTray(6);

    releasePill();

    checkMedicationTaken();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cycle Complete");

    delay(5000);

    systemStarted = false;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press A Start");
  }
}
```
