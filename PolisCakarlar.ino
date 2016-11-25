const int pin37 = 37;
const int pin38 = 38;
const int pin39 = 39;
const int pin40 = 40;
const int pin41 = 41;

const int pin46 = 46;
const int pin47 = 47;
const int pin48 = 48;
const int pin49 = 49;

void setup() {
  for (int oPin = pin37; oPin <= pin41; oPin++) {
    pinMode(oPin, OUTPUT);
    digitalWrite(oPin, LOW);
  }
  for (int buPin = pin46; buPin <= pin49; buPin++) {
    pinMode(buPin, OUTPUT);
    digitalWrite(buPin, LOW);
  }
}

void loop() {

  poliscakar();

}

void poliscakar() {

  for (byte say = 0; say < 6; ++say) {
    if (say < 3 ) {
      digitalWrite(pin37, HIGH);
      digitalWrite(pin38, HIGH);
      digitalWrite(pin39, HIGH);
      digitalWrite(pin40, HIGH);
      digitalWrite(pin41, HIGH);
      delay(50);

      digitalWrite(pin37, LOW);
      digitalWrite(pin38, LOW);
      digitalWrite(pin39, LOW);
      digitalWrite(pin40, LOW);
      digitalWrite(pin41, LOW);
      delay(50);
    }
    else if (say > 2) {

      digitalWrite(pin46, HIGH);
      digitalWrite(pin47, HIGH);
      digitalWrite(pin48, HIGH);
      digitalWrite(pin49, HIGH);
      delay(50);

      digitalWrite(pin46, LOW);
      digitalWrite(pin47, LOW);
      digitalWrite(pin48, LOW);
      digitalWrite(pin49, LOW);
      delay(50);

    }
  }
}
