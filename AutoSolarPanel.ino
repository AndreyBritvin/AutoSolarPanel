#define PHOTO_SENS_1 A0
#define PHOTO_SENS_2 A1
#define PHOTO_SENS_3 A2
#define PHOTO_SENS_4 A3
#define PHOTO_SENS_PLAT_1 A4
#define PHOTO_SENS_PLAT_2 A5

#define PHOTO_ENABLE 9

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

}
