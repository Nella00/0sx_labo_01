// la led qui sera utilisée
const int LED = 13;


void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  etatAllumer();
}

void etatAllumer(){
  Serial.println("Allumé - 2201250");
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
  // État de variation
  int brightness = 0;
  int fade = 5;

  while (brightness <= 255)
  { // Fade
    analogWrite(LED, brightness);
    delay(40);
    brightness = brightness + fade;
  }
  brightness = 0;
  cycly();  
}

void cycly(){
  Serial.println("Éteint - 2201250");
  digitalWrite(LED, LOW);
  delay(2000);
}