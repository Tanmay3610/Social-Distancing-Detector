const int pingPin = 13; 
const int echoPin = 12; 
const int buzzer = 11; 
void setup() {
   Serial.begin(9600); 
}

void loop() {
   
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   pinMode(buzzer, OUTPUT);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   if(inches <= 72){
   	tone(buzzer, (72-inches)*10);
   }
   else{
  	noTone(buzzer);
   }
   
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
