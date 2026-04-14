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
int led_pins[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

void setup()  {
  Serial.begin(9600);
  
  for (int index = 0; index < 10; index++) {
  	pinMode(led_pins[index], OUTPUT);
  }
  
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
  // replace 876 with max of moisture sensor when recieved
  int moisture = map(analogRead(A0), 0, 876, 0, 100);
  
  Serial.println(moisture);
  
  for (int index = 0; index < 10; index++) {
  	digitalWrite(led_pins[index], LOW);
  }
  
  for (int index = 0; index <= moisture/10; index++) {
  	digitalWrite(led_pins[index], HIGH);
  }
  
  delay(100);
}


// // This is the experimental case where pH is added 
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <BlynkSimpleEsp32.h>
// #include <SimpleTimer.h>

// //you get Auth Token in the Blynk app
//move credentials into another file, dont commit secrets
// char auth[] = "";

// char ssid
// char pass

// SimpleTimer timer; 

// float calibration_value = 20.24 - 0.7; 
// int phval = 0;
// unsigned long int avgval;
// int buffer_arr[10], temp;

// float ph_act;

// //for OLED display
// #define SCREEN_WIDTH 128 //PIXELS FOR WIDTH
// #define SCREEN_HEIGHT 64 // PIXELS FOR HEIGHT 

// // Declaration for on SSD1306 display 