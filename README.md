# Soil_and_pH-arduino-environmental-stem-project
STEM Project: Soil Measurment 
// C++ code

int moisture = 0; 
  #define NOTE_C4 100
  #define NOTE_A3 196
  #define NOTE_B3 220
  #define NOTE_B3 247
  #define NOTE_C4 262
  // notes in the melody:
  int melody[] = {
    NOTE_C4, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_A3, 0, NOTE_B3, NOTE_C4
  };
  // NOTE DURATIONS: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4,4,4,4,6,3,4,1
  };


void setup()  {
  pinMode (A0, OUTPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(2, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 3.30;
    delay(pauseBetweenNotes);
    noTone(2);
  }
} 

void loop()
{
  
  // Apply power to the soil moisture sensor
  digitalWrite(A0, LOW);
  delay(10); // wait for 10 millisecond(s)
  moisture = analogRead(A0);

  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6,LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  if (moisture < 18) {
    digitalWrite(3, HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  } else {
    if (moisture < 36){
      digitalWrite(6, HIGH);
    } else {
      if (moisture < 54) {
        digitalWrite(7, HIGH);
      } else {
        if (moisture < 72) {
          digitalWrite(8, HIGH);
        } else {
          if (moisture < 90) {
            digitalWrite(9, HIGH);
          } else { 
            if (moisture < 108) {
              digitalWrite(10, HIGH);
            } else {
              if (moisture < 126) {
                digitalWrite(11, HIGH);
              } else {
                if (moisture < 146) {
                  digitalWrite(12,HIGH);
                }
              }
            }
          }
        }
      }
    }
  }
  delay(100);
}
–––––––––––––––––––––––––––––––––––––––––––––––––––––   ––––––––––––––––––––––––––––––––––––––––––––  
// This is the experimental case where pH is added 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <BlynkSimpleEsp32.h>
#include <SimpleTimer.h>

//you get Auth Token in the Blynk app
char auth[] = "3vbf7rpD6vqpvve23wX3LcgknUqh_L31";

char ssid
char pass

SimpleTimer timer; 

float calibration_value = 20.24 - 0.7; 
int phval = 0;
unsigned long int avgval;
int buffer_arr[10], temp;

float ph_act;

//for OLED display
#define SCREEN_WIDTH 128 //PIXELS FOR WIDTH
#define SCREEN_HEIGHT 64 // PIXELS FOR HEIGHT 

// Declaration for on SSD1306 display 


