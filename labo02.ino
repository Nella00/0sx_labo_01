const int ledPins[] = {8, 9, 10, 11};  // Tableau des numéros de broches
int potentiometerPin = A1;           
int potentiometerValue = 0;          
int ledIndex = 0;                   // Index du DEL allume
const int boutonPin = 2;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    // Initialisation des DEL en sortie
    pinMode(ledPins[i], OUTPUT); 
  }
  pinMode(boutonPin, INPUT_PULLUP);
}

void loop() {
  potentiometerValue = analogRead(potentiometerPin);
  int potentio_convertie = map(potentiometerValue, 0, 1023, 0, 20);

  if (potentio_convertie < 5) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
  } else if (potentio_convertie < 10) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
  } else if (potentio_convertie < 15) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], LOW);
  } else {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
  }

  
  
}

void button(){
  int potentio_convertie = map(potentiometerValue, 0, 1023, 0, 100);
  int valueBouton = digitalRead(boutonPin);
  Serial.println(valueBouton);

  if (valueBouton == 0){
    for (int )
    Serial.println(potentio_convertie);
  }

}
