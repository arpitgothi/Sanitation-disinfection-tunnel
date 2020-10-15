int relayPin = 11;                

int inputPin = 5;           
int inputPin2 = 6;             

int pirState = LOW;           
int val = 0;                   
int val2 = 0;                 

 
void setup() {
  pinMode(relayPin, OUTPUT);     
  pinMode(inputPin, INPUT);   
  pinMode(inputPin2, INPUT);  
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  
  val2 = digitalRead(inputPin2);
  if (val == HIGH || val2 == HIGH) {         
    digitalWrite(relayPin, HIGH);
    if (pirState == LOW) {
      // turned on
      Serial.println("Motion detected!");
      // 16 sec delay
      delay(16000);
      pirState = HIGH;
    }
  } else {
    digitalWrite(relayPin, 0); // turn Relay OFF
    if (pirState == HIGH){
      // turned off
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
  
}
