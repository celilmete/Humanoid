
void verileriOku(){
  Wire.beginTransmission(MPU);
  /* I2C haberleşmesi yapılacak kart seçildi */
  Wire.write(0x3B); 
  /* 0x3B adresindeki register'a ulaşıldı */
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);
  /* 14 BYTE'lık veri istendi */
  
  AcX=Wire.read()<<8|Wire.read();   
  AcY=Wire.read()<<8|Wire.read(); 
  AcZ=Wire.read()<<8|Wire.read(); 
  Tmp=Wire.read()<<8|Wire.read(); 
  GyX=Wire.read()<<8|Wire.read(); 
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();


  AcX=map(AcX,-17000,17000,0,180);
  AcY=map(AcY,-17000,17000,0,180);
  AcZ=map(AcZ,-17000,17000,0,180);
  GyX=map(AcX,-17000,17000,0,180);
  GyY=map(AcY,-17000,17000,0,180);
  GyZ=map(AcZ,-17000,17000,0,180);

  Serial.print("ivmeX = "); Serial.print(AcX);
  Serial.print(" | ivmeY = "); Serial.print(AcY);
  
  /* 
  * Sırası ile okunan her iki byte birleştirilerek sırası ile değişkenlere yazdırıldı
  * Böylece IMU'dan tüm değerler okunmuş oldu
  * 0X3B adresi imu değerlerinden ilk sensörün değerine denk gelmektedir.
  * IMU'dan tüm değerlerin okunabilmesi için bu adresten başlandı
  */
}
