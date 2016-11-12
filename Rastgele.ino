// Başlangıç ve bitiş pin'lerimizi tanımlıyoruz
const int kucukPin = 37;
const int buyukPin = 49;

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
  // Rastgele olarak hazırladığımız void'i loop'a çağırıyoruz
  Rastgele();

}

void Rastgele() {
  // For dögüsünü kullanarak belirlemiş olduğumuz pin'lere bilgi gönderiyoruz
  // Eğer adreslenebilir led kullansaydık aynı yöntemi uygulayıp adreslere bilgi gönderebiliriz
  int tut = random(20); //0'dan 20 arasında bir sayı tutar
  // Bu sadece loop'ta çalışacağı için buna gerek yok, fakat başka bir uygulamanın içinde kullanmak isterseniz diye yazdım
  for (int say = 0; say <= tut; say++) {

    // Önceden tanımladığımız 37 ile 49 arasında bir sayı tutar
    // Üstteki random'dan farklı olarak başlangıç ve bitiş değerini biz verebiliriz
    // Random'un 2 değişik kullanımı
    // Daha sonra random'un daha farklı şekillerinide anlatacağım
    int ara = random(kucukPin, buyukPin + 1); // Random en büyük sayı -1 olarak çalıştığı için +1 yaptım
    digitalWrite(ara, HIGH);

    delay(50);

    digitalWrite(ara, LOW);

  }
}
