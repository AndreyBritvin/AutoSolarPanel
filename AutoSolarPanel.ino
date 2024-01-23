#define PHOTO_SENS_1 A0
#define PHOTO_SENS_2 A1
#define PHOTO_SENS_3 A2
#define PHOTO_SENS_4 A3
#define PHOTO_SENS_PLAT_1 A4
#define PHOTO_SENS_PLAT_2 A5

#define PHOTO_ENABLE 9

int sens_1, sens_2, sens_3, sens_4, sens_plat_1, sens_plat_2;

void setup() {
  // put your setup code here, to run once:
pinMode(PHOTO_SENS_1, INPUT);
pinMode(PHOTO_SENS_2, INPUT);
pinMode(PHOTO_SENS_3, INPUT);
pinMode(PHOTO_SENS_4, INPUT);

pinMode(PHOTO_SENS_PLAT_1, INPUT);
pinMode(PHOTO_SENS_PLAT_2, INPUT);

pinMode(PHOTO_ENABLE, OUTPUT);
digitalWrite(PHOTO_ENABLE, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
sens_1 = analogRead(PHOTO_SENS_1);
sens_2 = analogRead(PHOTO_SENS_2);
sens_3 = analogRead(PHOTO_SENS_3);
sens_4 = analogRead(PHOTO_SENS_4);

sens_plat_1 = analogRead(PHOTO_SENS_PLAT_1);
sens_plat_2 = analogRead(PHOTO_SENS_PLAT_2);
}
