#ifndef M_OPERATION_H
#define M_OPERATION_H
#include <Arduino.h>
#include "difinitions.h"
#include "U_Sonic.h"
int d;
int speed = 0;
#define kp 7
int k = 0;
int beko = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void move_forward(int speed_right = 255, int speed_left = 255)
{ //////////////////////////// the car will move forward /////////////////////////////

    digitalWrite(motor_left_1, HIGH);
    digitalWrite(motor_left_2, LOW);
    digitalWrite(motor_right_2, LOW);
    digitalWrite(motor_right_1, HIGH);
    analogWrite(motor_right_speed, speed_right);
    analogWrite(motor_left_speed, speed_left);
}

void move_backward(int speed_right = 255, int speed_left = 255)
{ //////////////////////////// the car will move forward /////////////////////////////

    digitalWrite(motor_left_1, LOW);
    digitalWrite(motor_left_2, HIGH);
    digitalWrite(motor_right_2, HIGH);
    digitalWrite(motor_right_1, LOW);
    analogWrite(motor_right_speed, speed_right);
    analogWrite(motor_left_speed, speed_left);
}

void stopp()
{
    digitalWrite(motor_left_1, LOW);
    digitalWrite(motor_left_2, LOW);
    analogWrite(motor_right_2, LOW); //  stop motors
    analogWrite(motor_right_1, LOW);
}

void diviate(int speed_right = 255, int speed_left = 255)
{
    d = ((distance_left - distance_right) / 2);
    speed = kp * d;
    if (d > 10)
    {
        k = kp - 3;
        speed = k * d;
        digitalWrite(motor_left_1, HIGH);
        digitalWrite(motor_left_2, LOW);
        digitalWrite(motor_right_2, LOW);
        digitalWrite(motor_right_1, HIGH);
        analogWrite(motor_right_speed, speed_right - speed); /// <<< right speed must be greater than the left speed
        analogWrite(motor_left_speed, speed_left + speed);
    }

    else
    {
        speed = kp * d;

        digitalWrite(motor_left_1, HIGH);
        digitalWrite(motor_left_2, LOW);
        digitalWrite(motor_right_2, LOW);
        digitalWrite(motor_right_1, HIGH);
        analogWrite(motor_right_speed, speed_right - speed); /// <<< right speed must be greater than the left speed
        analogWrite(motor_left_speed, speed_left + speed);
    }
}

void turn_right()
{
    steps = 0;
    steps2 = 0;
    move_forward(speedRight, speedLeft);
    delay(20);
    stopp();
    delay(500);
    while (1)
    {
        US_right();
        digitalWrite(motor_left_1, HIGH);
        digitalWrite(motor_left_2, LOW);
        analogWrite(motor_left_speed, h);

        if (digitalRead(sensor2))
        {

            steps2 = steps2 + 1;
            while (digitalRead(sensor2));
        }

        if (steps2 >= 15 || distance_right < 7)
        {

            stopp();

            analogWrite(motor_left_speed, 0);
            break;
        }
    }

    steps = 0;
    steps2 = 0;
    delay(500);
    while (1)
    {
        US_front();
        move_forward(speedRight, speedLeft);

        if (digitalRead(sensor2))
        {

            steps = steps + 1;
            while (digitalRead(sensor2))
                ;
        }

        if (digitalRead(sensor))
        {

            steps2 = steps2 + 1;
            while (digitalRead(sensor))
                ;
        }

        if (steps >= 8 || steps2 >= 9 || distance_front < 7)
        {

            stopp();
            delay(500);

            break;
        }
    }
}

void turn_left()
{
    steps = 0;
    steps2 = 0;
    move_forward(speedRight, speedLeft);
    delay(50);
    stopp();
    delay(500);
    while (1)
    {   beko = 0;
        US_left();
        digitalWrite(motor_right_1, HIGH);
        digitalWrite(motor_right_2, LOW);
        analogWrite(motor_right_speed, h);

        if (digitalRead(sensor))
        {

            steps = steps + 1;
            while (digitalRead(sensor))
                ;
        }

        if (steps >= 15 || distance_left < 10)
        {

            stopp();

            analogWrite(motor_right_speed, 0);
            break;
        }
      /*  US_right();
       if (distance_right < rest)
        {   
            Dright = distance_right;

            delay(2000);
            US_right();
            
            if (Dright == distance_right)
            {
                move_backward(70, 70);
                delay(900);
                stopp();
                delay(500);

                 beko = 1;
                break;
            }
        } */
    }

    steps = 0;
    steps2 = 0;
    delay(500);
    if (beko == 0)
     {
        while (1)
        {
            US_front();
            move_forward(speedRight, speedLeft);

            if (digitalRead(sensor))
            {

                steps = steps + 1;
                while (digitalRead(sensor))
                    ;
            }

            if (digitalRead(sensor2))
            {

                steps2 = steps2 + 1;
                while (digitalRead(sensor2))
                    ;
            }

            if (steps >= 9 || steps2 >= 8 || distance_front < 6)
            {

                stopp();
                delay(500);

                break;
            }
        }
     }
}

///  go back to the right path

#endif