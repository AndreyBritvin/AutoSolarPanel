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
digitalWrite(PHOTO_ENABLE, HIGH);

myservo_down.attach(SERVO_DOWN_PIN);
myservo_up.attach(SERVO_UP_PIN);
}

void loop() {
 get_sens_data();
debug_print();
calc_pos();
delay(1000);
}

int max_value;

void calc_pos(void)
{
  max_value = max_val(sens_1,sens_2,sens_3,sens_4,sens_5,sens_6);
  if(max_value==sens_1)  
  {
    need_pos = 0;
    return;
  }
  if(max_value==sens_2)  
  {
    need_pos = 60;
    return;
  }
  if(max_value==sens_3)  
  {
    need_pos = 120;
    return;
  }
  if(max_value==sens_4)  
  {
    need_pos = 180;
    return;
  }
  if(max_value==sens_5)  
  {
    need_pos = 240;
    return;
  }
  if(max_value==sens_6)  
  {
    need_pos = 300;
    return;
  }
}

int max_val(int s1, int s2, int s3, int s4, int s5, int s6)
{
  if (s1>=s2 and s1>=s3 and s1>=s4 and s1>=s5 and s1>=s6)
  {
    return s1;
  }
  if (s2>=s1 and s2>=s3 and s2>=s4 and s2>=s5 and s2>=s6)
  {
    return s2;
  }
  if (s3>=s2 and s3>=s1 and s3>=s4 and s3>=s5 and s3>=s6)
  {
    return s3;
  }
  if (s4>=s2 and s4>=s3 and s4>=s1 and s4>=s5 and s4>=s6)
  {
    return s4;
  }
  if (s5>=s2 and s5>=s3 and s5>=s4 and s5>=s1 and s5>=s6)
  {
    return s5;
  }
  if (s6>=s2 and s6>=s3 and s6>=s4 and s6>=s5 and s6>=s1)
  {
    return s6;
  }
}

void get_sens_data(void)
{ 
digitalWrite(PHOTO_ENABLE, LOW);
delay(15);
sens_1 = analogRead(PHOTO_SENS_1);
sens_2 = analogRead(PHOTO_SENS_2);
sens_3 = analogRead(PHOTO_SENS_3);
sens_4 = analogRead(PHOTO_SENS_4);
sens_5 = analogRead(PHOTO_SENS_5);
sens_6 = analogRead(PHOTO_SENS_6);
digitalWrite(PHOTO_ENABLE, HIGH);
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
