#include <Arduino.h>
#include "difinitions.h"
#include "M_operations.h"
#include "U_Sonic.h"
#include "short_path.h"
char maze_array[100]; // >>>>>>>>>>>>>> array where the maze will be saved
                      // >>>>>>>>>>>> variable for the distance  of the condition
int i = 0;            //  >>>>>>>>>>>>>   index of the array


void functions()
{

   for (int i = 2; i < 10; i++)
   {
      pinMode(i, OUTPUT);
   }

   for (int i = 10; i < 13; i++)
   {

      pinMode(i, INPUT);
   }
   pinMode(Trigo_pin_front, OUTPUT);
   pinMode(Trigo_pin_right, OUTPUT);
   pinMode(Trigo_pin_left, OUTPUT);
   pinMode(sensor, INPUT);
}

void setup()
{
   Serial.begin(9600);
   functions();
}

void loop()
{

   US_left();
   US_right();
   US_front();

   // >>>>>>>>>>>>>>>>>>>   start calculations of distancea

   if (distance_left < rest_distance && distance_front > 8 && distance_right < rest_distance) // Straight path
   {
      
      move_forward(speedRight, speedLeft);
      diviate(speedRight, speedLeft);
   }

   else if (distance_left > rest_distance && distance_front > rest_distance ||
            distance_right > rest_distance && distance_front > rest_distance || //  >>>>>>>>  if is there any intersaction then do
            distance_left > rest_distance && distance_right > rest_distance ||
            distance_left > rest_distance && distance_front > rest_distance && distance_right > rest_distance ||
            distance_left > rest_distance || distance_right > rest_distance

   )
   {

      // shortest path will start after the code enter this condition

      stopp();

      if (distance_left > rest_distance)
      {
         maze_array[i] = 'L';
         stopp();
         turn_left();
         
         
         i++;
      }
      else if (distance_front > rest_distance)
      {
         maze_array[i] = 'S';
         stopp();
         move_forward(speedRight, speedLeft);
         i++;
      }
      else if (distance_right > rest_distance)
      {
         maze_array[i] = 'R';
         stopp();
         turn_right();
      }
   }
   else
      stopp();
}