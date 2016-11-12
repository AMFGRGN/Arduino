// Başlangıç ve bitiş pin'lerimizi tanımlıyoruz
const int kucukPin = 37;
const int buyukPin = 49;
// Gereken diğer değişkenleri tanımlıyoruz
int Yon = buyukPin;

void setup() {
  // For dögüsünü kullanarak küçük pin'den büyük pin'e kadar olan pin'lerin yönünü OUTPUT
  // olarak ayarlıyoruz
  // Eğer bilgi almak isteseydik yönünü INPUT olarak ayarlıyacaktık
  for (int buPin = kucukPin; buPin <= buyukPin; buPin++) {
    pinMode ( buPin, OUTPUT);
    digitalWrite(buPin, LOW);
  }
}

void loop() {
  // ciftYon olarak hazırladığımız void'i loop'a çağırıyoruz
  ciftYon();

}

void ciftYon() {
  // For dögüsünü kullanarak belirlemiş olduğumuz pin'lere bilgi gönderiyoruz
  // Eğer adreslenebilir led kullansaydık aynı yöntemi uygulayıp adreslere bilgi gönderebiliriz
  for (int buPin = kucukPin; buPin <= buyukPin; buPin++) {
    digitalWrite(buPin, HIGH);
    digitalWrite(Yon, HIGH);
    delay(50);

    digitalWrite(buPin, LOW);
    digitalWrite(Yon, LOW);
    // Diğer yönü kontrol etmek için kullanıldı
    --Yon;
  }
  // Burada yön küçüldüğü için tekrar buyukPın'i Yon'e eşitliyoruz
  Yon = buyukPin;
}
