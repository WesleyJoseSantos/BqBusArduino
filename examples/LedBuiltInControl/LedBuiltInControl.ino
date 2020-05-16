/**
 * @file LedBuiltInControl.ino
 * @author Wesley José Santos (https://binary-quantum.com)
 * @brief Arduino code example to work with LedBuiltInCotrol.exe
 * Repo of visual studio application: https://github.com/WesleyJoseSantos/BqBusNet
 * @version 0.1
 * @date 2020-05-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "BqBus.h"

BqBus vstudio(1);     //Instance to share 1 register with vstudio application

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                               //Initialize serial port
  vstudio.setBus(Serial);                           //Set serial port used to communicate with vstudio application
  pinMode(LED_BUILTIN, OUTPUT);                     //Configure board default output to control on-board led
}

void loop() {
  // put your main code here, to run repeatedly:
  vstudio.communicationTask();                      //Performs communication betteen arduino and vstudio application
  digitalWrite(LED_BUILTIN, vstudio.getReg(0));     //Read register with address zero and write his values on led
}