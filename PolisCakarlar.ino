//Polis lambalarındaki olduğu gibi sağdan ve soldan ledlerimizi belirledik
//Sol taraftaki ledlerimizi belirledik
const byte pin37 = 37;
const byte pin38 = 38;// 255'ten küçük olduğu için byte kullandım
const byte pin39 = 39;
const byte pin40 = 40;
const byte pin41 = 41;
//Sağ taraftaki lederimizi belirledik
const uint8_t pin46 = 46;
const uint8_t pin47 = 47;// 255'ten küçük olduğu için uint8_t (byte) kullandım
const uint8_t pin48 = 48;
const uint8_t pin49 = 49;

void setup() {
  //Sağ ve Sol'daki ledlerimizi for yardımıyla set ettik(karta tanıttık)
  //Sol taraftaki pinleri set ettik
  for (byte oPin = pin37; oPin <= pin41; oPin++) {
    pinMode(oPin, OUTPUT);          // Bu şekildede Set edebiliyoruz
    digitalWrite(oPin, LOW);
  }
  //Sağ taraftaki pinleri set ettik
  pinMode(pin46, OUTPUT); digitalWrite(pin46, LOW);
  pinMode(pin47, OUTPUT); digitalWrite(pin47, LOW);   // Bu şekildede Set edebiliyoruz
  pinMode(pin48, OUTPUT); digitalWrite(pin48, LOW);   // Önemli olan yönünü belirlemek
  pinMode(pin49, OUTPUT); digitalWrite(pin49, LOW);
}

void loop() {
  //Yaptığımız metot'u loop'a çağırıyoruz
  poliscakar();
}

void poliscakar() {
  // For sayesinde toplam 6 defa led'leri yakıyoruz, 3 kez sağ taraf 3 kez sol tarafı yakıyoruz.
  for (byte say = 0; say < 6; ++say) {
    if (say < 3 ) { // yani 0, 1, 2 için burası
      digitalWrite(pin37, HIGH);
      digitalWrite(pin38, HIGH);// Belirlemiş olduğumuz led'i açıyoruz
      digitalWrite(pin39, HIGH);
      digitalWrite(pin40, HIGH);
      digitalWrite(pin41, HIGH);
      delay(50); // Bekleme süresi

      digitalWrite(pin37, LOW);
      digitalWrite(pin38, LOW);// Belirlemiş olduğumuz led'i kapatıyoruz
      digitalWrite(pin39, LOW);
      digitalWrite(pin40, LOW);
      digitalWrite(pin41, LOW);
      delay(50);
    }
    else if (say > 2) {  // 3, 4, 5 için burası
      for (uint8_t oPin = pin46; oPin <= pin49; oPin++)// For'u tek işlem için böyle kullana biliriz
        digitalWrite(oPin, HIGH);

      delay(50);

      for (uint8_t oPin = pin46; oPin <= pin49; oPin++) {
        digitalWrite(oPin, LOW);
      }
      delay(50);
    }  // else if
  }// Ana for
}// metot
