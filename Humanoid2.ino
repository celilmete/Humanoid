#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
/*
   I2C fonksiyonlarını kullanabilmek için
   Wire.h kütüphanesini projemize ekledik
*/

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

byte ankleServoR2 = 9 , ankleServoR = 8 ,  kneeServoR = 7 , thighServoR  = 6 , thighServoR2 = 5 ,
     ankleServoL2 = 0 , ankleServoL = 1 ,  kneeServoL = 2 , thighServoL  = 3 , thighServoL2 = 4 ;

byte ankleR2Ini = 105 , ankleRIni = 55 ,  kneeRIni = 110 , thighRIni  = 85 , thighR2Ini = 90 ,
     ankleL2Ini = 90 , ankleLIni = 80 ,  kneeLIni = 40 , thighLIni  = 55 , thighL2Ini = 85 ;

byte ankleR2Last = ankleR2Ini, ankleRLast = ankleRIni ,  kneeRLast = kneeRIni , thighRLast  = thighRIni , thighR2Last = thighR2Ini ,
     ankleL2Last = ankleL2Ini , ankleLLast = ankleLIni ,  kneeLLast = kneeLIni, thighLLast  = thighLIni , thighL2Last = thighL2Ini ;



const int MPU = 0x68;
/* MPU-6050'nin I2C haberleşme adresi */

int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
/* IMU'dan alınacak değerlerin kaydedileceği değişkenler */



void setup() {
  /*
    Wire.begin();
    Wire.beginTransmission(MPU);
    Wire.write(0x6B);
    Wire.write(0); /* MPU-605
    0 çalıştırıldı
    Wire.endTransmission(true);
    /* I2C haberleşmesi başlatıldı ve MPU-6050'nin ilk ayarları yapıldı */
  Serial.begin(9600);
  setupServo();
  getInitial();
  delay(1000);
  
}


void loop() {

  walk();
  //while(true);
}

void goWithDelay(byte servoNum , byte startAngle , byte endAngle) {
  if (startAngle < endAngle) {
    for (int i = startAngle ; i < endAngle ; i++) {
      pwm.setPWM(servoNum, 0, angleToPulse1(i));
      delay(25);
    }
  } else {
    for (int i = startAngle ; i > endAngle ; i--) {
      pwm.setPWM(servoNum, 0, angleToPulse1(i));
      delay(25);
    }

  }


}
