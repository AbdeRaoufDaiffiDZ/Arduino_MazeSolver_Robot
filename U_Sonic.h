#ifndef _U_SONIC_H_
#define _U_SONIC_H_
#include<Arduino.h>
#include "difinitions.h"

long duration_front;
int distance_front ; 
long duration_right;
int distance_right;

long duration_left;
int distance_left;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
void US_operation(int Trigo_pin_com){
  
  digitalWrite(Trigo_pin_com, LOW); /////////////// function for sending signal for ultra sonic //////////

  delayMicroseconds(2);

  digitalWrite(Trigo_pin_com, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigo_pin_com, LOW);}


 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
void US_front(){                      //////////////// function for the front ultrasonic  //////////////
  US_operation(Trigo_pin_front);

  duration_front = pulseIn(ultra_sonic_front, HIGH);
  distance_front = duration_front * 0.034 / 2;
  
  //Serial.print("Distance_front:  ");
  //Serial.println(distance_front);
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  void US_right(){      /////////////////////////func for the right ultra sonic  //////////////////
  US_operation(Trigo_pin_right);
  duration_right = pulseIn(ultra_sonic_right, HIGH);
  distance_right = duration_right * 0.034 / 2;
  
  //Serial.print("Distance_right:  ");
 //Serial.println (distance_right);
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
void US_left(){                    ////////////////////// func for the left  ultra sonic /////////////////////
  US_operation(Trigo_pin_left);
  duration_left = pulseIn(ultra_sonic_left, HIGH);
  distance_left = duration_left * 0.034 / 2;
 
 // Serial.print("Distance_left: ");
  //Serial.println(distance_left);
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////

  
#endif