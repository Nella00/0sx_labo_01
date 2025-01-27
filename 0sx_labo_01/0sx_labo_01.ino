// la led qui sera utilisée
const int LED = 13;
// Des variables qui seront utilisées dans l'état de variation
int brightness = 0;
int fade = 5;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  etatAllumer();
}

void etatAllumer(){
  Serial.println("Allume - 2201250");
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
  etatClignotement();
}

void etatClignotement(){
  Serial.println("Clignotement - 2201250");
  for (int i = 0; i < 4; i++){
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
  }
  etatVariation();
}

void etatVariation(){
  Serial.println("Variation - 2201250");
  analogWrite(LED, brightness);
  brightness = brightness + fade;
  while (brightness <= 0 || brightness >= 255){
    fade = -fade;
  }
  cycly();
}

void cycly(){
  Serial.println("Éteint - 2201250");
  delay(2000);
}