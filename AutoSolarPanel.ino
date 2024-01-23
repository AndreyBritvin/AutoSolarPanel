#define PHOTO_SENS_1 A0
#define PHOTO_SENS_2 A1
#define PHOTO_SENS_3 A2
#define PHOTO_SENS_4 A3
#define PHOTO_SENS_PLAT_1 A4
#define PHOTO_SENS_PLAT_2 A5

#define PHOTO_ENABLE 9

#define SERVO_DOWN_PIN 7
#define SERVO_UP_PIN 8

int sens_1, sens_2, sens_3, sens_4, sens_plat_1, sens_plat_2;

#include <Servo.h>

Servo myservo_down;
Servo myservo_up;
int pos_up = 0;
int pos_down = 0;

int need_pos = 0;

void setup() {
 Serial.begin(115200);
pinMode(PHOTO_SENS_1, INPUT);
pinMode(PHOTO_SENS_2, INPUT);
pinMode(PHOTO_SENS_3, INPUT);
pinMode(PHOTO_SENS_4, INPUT);

pinMode(PHOTO_SENS_PLAT_1, INPUT);
pinMode(PHOTO_SENS_PLAT_2, INPUT);

pinMode(PHOTO_ENABLE, OUTPUT);
digitalWrite(PHOTO_ENABLE, LOW);

myservo_down.attach(SERVO_DOWN_PIN);
myservo_up.attach(SERVO_UP_PIN);
}

void loop() {
digitalWrite(PHOTO_ENABLE, HIGH);
delay(15);
sens_1 = analogRead(PHOTO_SENS_1);
sens_2 = analogRead(PHOTO_SENS_2);
sens_3 = analogRead(PHOTO_SENS_3);
sens_4 = analogRead(PHOTO_SENS_4);

digitalWrite(PHOTO_ENABLE, LOW);
debug_print();
sens_plat_1 = analogRead(PHOTO_SENS_PLAT_1);
sens_plat_2 = analogRead(PHOTO_SENS_PLAT_2);
delay(1000);
}


void debug_print(void)
{
  Serial.print(sens_1);
Serial.print(" ");
Serial.print(sens_2);
Serial.print(" ");
Serial.print(sens_3);
Serial.print(" ");
Serial.print(sens_4);
Serial.print(" ");
Serial.print(sens_plat_1);
Serial.print(" ");
Serial.print(sens_plat_1);
Serial.print(" ");
}
