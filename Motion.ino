
void walk() {

  getInitial();

  leanLeftF();

  raiseRightF();

  lowerRight();

  leanRight();

  raiseLeft();

  lowerLeft();
  delay(180);
  getInitial();
  
 

}

int delayVal = 25;

void leanLeftF() {

  int k = 0;
  for (; k <= 30; k++) {
    pwm.setPWM(ankleServoL2, 0, angleToPulse1(ankleL2Last + (2 * k / 3)) );
    pwm.setPWM(ankleServoR2, 0, angleToPulse1(ankleR2Last + (2*k / 3)) );

    delay(delayVal);
  }

  ankleL2Last = ankleL2Last + (2 * k / 3);
  ankleR2Last = ankleR2Last + (2*k / 3) ;




}

void raiseRightF() {

  int k = 0;
  Serial.println("raiseRightF");
  for (; k <= 30; k++) {
    pwm.setPWM(thighServoR, 0, angleToPulse1(thighRLast + k ));
    pwm.setPWM(kneeServoR, 0, angleToPulse1(kneeRLast - k / 2) );
    pwm.setPWM(thighServoR2, 0, angleToPulse2(thighR2Last + k / 6) );
    pwm.setPWM(ankleServoR, 0, angleToPulse2(ankleRLast + 2*k / 3 ) );

    delay(delayVal);
  }
  thighRLast = thighRLast + k ;
  kneeRLast = kneeRLast - k / 2 ;
  thighR2Last = thighR2Last + k / 6;
  ankleRLast = ankleRLast + 2*k / 3;

}



void lowerRight() {

  int k = 0;
  for (; k <= 30; k++) {
    pwm.setPWM(ankleServoL, 0, angleToPulse1(ankleLLast + ( 2* k / 3)) );
    pwm.setPWM(ankleServoR2, 0, angleToPulse1(ankleR2Last - (2*k / 3)) );
    pwm.setPWM(ankleServoL2, 0, angleToPulse1(ankleL2Last - (2 * k / 3)) );
  

    delay(delayVal);
  }
  ankleLLast = ankleLLast + 2*k/3;
  ankleL2Last = ankleL2Last - 2*k / 3;
  ankleR2Last = ankleR2Last  - 2*k /3;


  pwm.setPWM(thighServoR2, 0, angleToPulse1(thighR2Last + 5) );

}

void leanRight() {
  int k = 0;
  for (; k <= 30; k++) {
    pwm.setPWM(ankleServoR, 0, angleToPulse1(ankleRLast - k/4) );
    pwm.setPWM(ankleServoL2, 0, angleToPulse1(ankleL2Last - (2*k / 3)) );
    pwm.setPWM(ankleServoR2, 0, angleToPulse1(ankleR2Last - (2*k / 3)) );
 
    delay(delayVal);
  }
  ankleRLast = ankleRLast - k/4;
  ankleL2Last = ankleL2Last - (2*k / 3);
  ankleR2Last = ankleR2Last - (2*k / 3);


}

void raiseLeft() {
  int k = 0;
  for (; k <= 30; k++) {
    pwm.setPWM(ankleServoL2 , 0 , angleToPulse1(ankleL2Last + k/3));
    pwm.setPWM(thighServoR, 0, angleToPulse1(thighRLast - k ));
    pwm.setPWM(ankleServoL, 0 , angleToPulse1(ankleLLast - 2*k/3));
    


    delay(delayVal);
  }
  
  thighRLast = thighRLast - k;
  ankleLLast = ankleLLast - 2*k/3;
  ankleL2Last = ankleL2Last + k/3;
}

void  lowerLeft() {

  for (int k = 0; k <= 30; k++) {
    
    pwm.setPWM(ankleServoR, 0, angleToPulse1(ankleRLast - 2 * k / 3) );
    pwm.setPWM(kneeServoR, 0, angleToPulse1(kneeRLast + 2*k / 3) );
    pwm.setPWM(ankleServoR2 , 0 , angleToPulse1(ankleR2Last + 2*k/3));
    pwm.setPWM(ankleServoL2 , 0 , angleToPulse1(ankleL2Last + k/3));


    
  delay(delayVal);
  }
}
