// Başlangıç ve bitiş pin'lerimizi tanımlıyoruz
const int kucukPin = 37;
const int buyukPin = 49;

void setup() {
  // For dögüsünü kullanarak küçük pin'den büyük pin'e kadar olan pin'lerin yönünü OUTPUT
  // olarak ayarlıyoruz
  // Eğer bilgi almak isteseydik yönünü INPUT olarak ayarlıyacaktık
  for (int buPin = kucukPin; buPin <= buyukPin; buPin++) {
    pinMode(buPin, OUTPUT);
    digitalWrite(buPin, LOW);
  }
}

void loop() {
  // karasimsek olarak hazırladığımız void'i loop'a çağırıyoruz
  karasimsek();
}

void karasimsek() {
  // For dögüsünü kullanarak belirlemiş olduğumuz pin'lere bilgi gönderiyoruz
  // Eğer adreslenebilir led kullansaydık aynı yöntemi uygulayıp adreslere bilgi gönderebiliriz
  for (int buPin = kucukPin; buPin <= buyukPin; buPin++) {
    digitalWrite(buPin, HIGH);
    digitalWrite(buPin - 3, LOW);
    delay(50);
  }
  // For dögüsünü kullanarak belirlemiş olduğumuz pin'lerin geri gelmesini sağlıyoruz
  for (int buPin = buyukPin; buPin >= kucukPin; buPin--) {
    digitalWrite(buPin, HIGH);
    // 3'lü gezdirdiğimiz için 46'dan büyük ise buraya girmiyor
    if (buPin < 47 )
      digitalWrite(buPin + 3, LOW);
    delay(50);
  }
}
