const int LED = 13;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){

}

void etatAllumer(){
  Serial.println("Allume - 2201250");
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
  etatClignotement();
}

void etatClignotement(){
  digitalWrite(LED, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  delay(250);
}
void etatVariation(){

}