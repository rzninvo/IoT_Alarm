String message = "";
String alrm = "";
long alarm = 0;
int buzzer = 24;
long stop_time = 0;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (Serial3.available() > 0){
    message = Serial3.readString();
    if (message[0] == 'T')
    {
      Serial.print(message);
        message[5] = '\0';
      if (message == "Time:"){
        message[5] = ' ';
        int inp = 6;
        int counter = 0;
        while (message[inp] != '\n'){
          alrm += message[inp];
          counter++;
          inp++;
        }
        alrm[counter] = '\0';
        alarm = alrm.toInt();
        Serial.println(alarm);
      }
    }
    else if (message[0] == 'C')
    {
      Serial.print(message);
      message[8] = '\0';
      if (message == "Command:"){
        message[8] = ' ';
        if (message[9] == '0'){
          noTone(buzzer);
        }
        if (message[9] == '1'){
          noTone(buzzer);
          alarm = millis() + 5000;
        }
      }
    }
  }
  if (alarm != 0){
    if (millis() == alarm){
      tone(buzzer, 1000);
      stop_time = 20000 + millis(); 
     }
   }
  if (stop_time <= millis()){
     noTone(buzzer);
  }
}
