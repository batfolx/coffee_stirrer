#include <Arduino.h>

int8_t mach_pin = 12;
int8_t medium_pin = 10;
int8_t slow_pin = 8;

uint8_t slow_speed = 150;
uint8_t medium_speed = 200;
uint8_t mach_speed = 255;

int8_t ENA = A0;
int8_t EN1 = A1;
int8_t EN2 = 4;

int16_t val ;


void setup() {

  pinMode(mach_pin, INPUT);
  pinMode(medium_pin, INPUT);
  pinMode(slow_pin, INPUT);


  pinMode(ENA, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);


}


void stir(uint8_t speed) {

  analogWrite(ENA, speed);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  delay(20);
  analogWrite(ENA, 0);

}

void loop() {

    val = digitalRead(mach_pin);
    if ( val == HIGH ) {
      stir(mach_speed);
      return ;
    }

    val = digitalRead(medium_pin);
    if ( val == HIGH ) {
      stir(medium_speed);
      return ;
    }

    val = digitalRead(slow_pin);
    if ( val == HIGH ) {
      stir(slow_speed);
      return ;
    }

    delay (250);

}