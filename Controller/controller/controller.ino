#include <Keypad.h>

String message;
char keys[4][3] ={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[4] = {22, 23, 24, 25};
byte colPins[3] = {26, 27, 28};

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, 4, 3);

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    message = Serial.readString();
    Serial3.println("Time: " + message);
  }
  
  char key = kpd.getKey();
  if (key != NO_KEY)
  {
    String msg = "Command: ";
    msg += key;
    Serial3.println(msg);
  }
}
