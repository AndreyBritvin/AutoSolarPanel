#define PHOTO_SENS_1 A0
#define PHOTO_SENS_2 A1
#define PHOTO_SENS_3 A2
#define PHOTO_SENS_4 A3
#define PHOTO_SENS_5 A4
#define PHOTO_SENS_6 A5

#define PHOTO_ENABLE 9

#define SERVO_DOWN_PIN 7
#define SERVO_UP_PIN 8

int sens_1, sens_2, sens_3, sens_4, sens_5, sens_6;

#include <Servo.h>

Servo myservo_down;
Servo myservo_up;
int pos_up = 0;
int pos_down = 0;

int need_pos = 0;

void setup() {
 Serial.begin(115200);
pinMode(PHOTO_SENS_1, INPUT_PULLUP);
pinMode(PHOTO_SENS_2, INPUT_PULLUP);
pinMode(PHOTO_SENS_3, INPUT_PULLUP);
pinMode(PHOTO_SENS_4, INPUT_PULLUP);

pinMode(PHOTO_SENS_5, INPUT_PULLUP);
pinMode(PHOTO_SENS_6, INPUT_PULLUP);

pinMode(PHOTO_ENABLE, OUTPUT);
digitalWrite(PHOTO_ENABLE, LOW);

myservo_down.attach(SERVO_DOWN_PIN);
myservo_up.attach(SERVO_UP_PIN);
}

void loop() {
 get_sens_data();
debug_print();

delay(1000);
}

void get_sens_data(void)
{
  
digitalWrite(PHOTO_ENABLE, HIGH);
delay(15);
sens_1 = analogRead(PHOTO_SENS_1);
sens_2 = analogRead(PHOTO_SENS_2);
sens_3 = analogRead(PHOTO_SENS_3);
sens_4 = analogRead(PHOTO_SENS_4);
sens_5 = analogRead(PHOTO_SENS_5);
sens_6 = analogRead(PHOTO_SENS_6);
digitalWrite(PHOTO_ENABLE, LOW);
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
Serial.print(sens_5);
Serial.print(" ");
Serial.print(sens_6);
Serial.println(" ");

}
