#ifndef _DIFINITIONS_H
#define _DIFINITIONS_H
#include<Arduino.h>
#define motor_right_1 7 //////////
#define motor_right_2 8 ///////////       motors configuration 
#define motor_left_1 4 ///////////
#define motor_left_2  3 ///////////// 

#define motor_right_speed 5 
#define motor_left_speed 6


///////////////////////////////////////////////////////////////////////////////////

#define ultra_sonic_front 11
#define ultra_sonic_right 10
#define ultra_sonic_left 12


#define Trigo_pin_front  2 /////////////////////   ultrasonic sensor configuration 
#define Trigo_pin_right  A4
#define Trigo_pin_left  13
 //////////////////////////////////////////////////////////////////////

#define IR 9     ///////  IR configuration 
#define led_red 2

//////////////////////////////////////////////////////////////:

#define maze_size 200


//////////////////////////////////////////////////////////

#define sensor A1
#define sensor2 A0

unsigned long start_time = 0;
unsigned long end_time = 0;
int steps=0;
int steps2 = 0;
float steps_old=0;
float temp=0;
float rps=0;
int Dright = 0;
int Dfront = 0;
int rest = 6;

int rest_distance = 20;

//////////// speeds //////////////
#define speedLeft 80
#define speedRight  80
#define h 85


//////////////////////////////
#endif


