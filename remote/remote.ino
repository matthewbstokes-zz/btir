#include <IRremote.h>
#include <IRremoteInt.h>
#include <SoftwareSerial.h>

// Definitions
#define GND_PIN                     2
#define rxPin                       4
#define txPin                       3
#define NEC_L                       32
#define NUM_CODES                   21
#define BLINK_DELAY                 300 // ms

SoftwareSerial mySerial(rxPin, txPin);
IRsend ir_send;
// create lookup table for IR codes
const unsigned long codes[NUM_CODES] = {
   0xC40BF,            // PROJ_POWER
   0xC10EF,            // PROJ_AUTO
   0xCE01F,            // PROJ_BLANK
   0xCC03F,            // PROJ_FREEZE
   0xC30CF,            // PROJ_KEYSTONE_DOWN
   0xCD02F,            // PROJ_KEYSTONE_UP
   0xC08F7,            // PROJ_MODE
   0xC708F,            // PROJ_PANEL_KEY_LOCK
   0xC20DF,            // PROJ_SOURCE
   0xCF00F,            // PROJ_MENU
   0xCF00F,            // PROJ_EXIT
   0xC41BE,            // PROJ_VOL_UP
   0xCC13E,            // PROJ_VOL_DOWN
   0xCD02F,            // PROJ_UP
   0xC30CF,            // PROJ_DOWN
   0xCB04F,            // PROJ_LEFT
   0xC708F,            // PROJ_RIGHT
   0xC08F7,            // PROJ_OK
   0xFF20DF,           // HDMI_SWITCH_1
   0xFF10EF,           // HDMI_SWITCH_2
   0xFF50AF,           // HDMI_SWITCH_3
 };

int parseIntBT(SoftwareSerial& ser) {
   String tmp = "";
   while(ser.available()) {
     tmp += char(ser.read());
   }
   return tmp.toInt();
}

// the setup routine runs once when you press reset:
void setup() {        
  pinMode(GND_PIN, OUTPUT);  
  digitalWrite(GND_PIN, LOW);
  mySerial.begin(9600);
}

// the loop routine runs over and over asensorpingain forever:
void loop() {
  if(mySerial.available()) {
    int command = parseIntBT(mySerial);
    mySerial.println(command);
    
   if (command >= NUM_CODES || command < 0) {
     mySerial.println("Command not found");
   }
   else {
     mySerial.println("found");
     ir_send.sendNEC(codes[command], NEC_L); 
   } 
  }
  delay(2000);
}
