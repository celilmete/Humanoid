
void setupServo() {
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(500);
}


void getInitial() {
  pwm.setPWM(ankleServoL2, 0, angleToPulse1(ankleL2Ini) );   pwm.setPWM(ankleServoR2, 0, angleToPulse1(ankleR2Ini) );
  pwm.setPWM(ankleServoL, 0, angleToPulse1(ankleLIni) );   pwm.setPWM(ankleServoR, 0, angleToPulse1(ankleRIni) );
  pwm.setPWM(kneeServoL, 0, angleToPulse1(kneeLIni) );  pwm.setPWM(kneeServoR, 0, angleToPulse1(kneeRIni) );
  pwm.setPWM(thighServoL, 0, angleToPulse1(thighLIni) );  pwm.setPWM(thighServoR, 0, angleToPulse1(thighRIni) );
  pwm.setPWM(thighServoL2, 0, angleToPulse2(thighL2Ini) );   pwm.setPWM(thighServoR2, 0, angleToPulse2(thighR2Ini) );
  
  goWithDelay(kneeServoL,kneeLLast,kneeLIni);  goWithDelay(thighServoL,thighLLast,thighLIni);  
  
  ankleR2Last = ankleR2Ini, ankleRLast = ankleRIni ,  kneeRLast = kneeRIni , thighRLast  = thighRIni , thighR2Last = thighR2Ini ,
  ankleL2Last = ankleL2Ini , ankleLLast = ankleLIni ,  kneeLLast = kneeLIni, thighLLast  = thighLIni , thighL2Last = thighL2Ini ;

  delay(1000);
}

int angleToPulse1(int ang) {
  ang = map(ang, 0, 180, 100, 410);
  int pulse = ang;
  return pulse;
}
int angleToPulse2(int ang) {
  ang = map(ang, 0, 180, 100, 450);
  int pulse = ang;
  return pulse;
}
