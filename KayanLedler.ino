// Başlangıç ve bitiş pin'lerimizi tanımlıyoruz
const byte kucukPin = 37;
const byte buyukPin = 49;

void setup() {
  // Serial monitörden bilgi almak için kullandım
  Serial.begin(9600);
  // For dögüsünü kullanarak küçük pin'den büyük pin'e kadar olan pin'lerin yönünü OUTPUT
  // olarak ayarlıyoruz
  // Eğer bilgi almak isteseydik yönünü INPUT olarak ayarlıyacaktık
  for (byte yeniPin = kucukPin; yeniPin <= buyukPin; yeniPin++) {
    pinMode (yeniPin, OUTPUT);
    digitalWrite(yeniPin, LOW);
  }
}
// gel değişkenini static olarak tanımlıyorum ve buyukPin yerine kullanacağım
static byte gel;
void loop() {
  // kayanLedler adında oluşturduğum metodu loop'a çağırdım
  kayanLedler();
}


void kayanLedler() {
  // gel değişkenini 49'a eşitliyorum
  gel = 49;
  // for dögüsü sayesinde 13 defa işlem yapması gerektiğini bildiriyorum çünkü benim 13 tane led'im var
  for (byte i = 0; i < 13; i++) {
    // for dögüsü sayesinde küçük pin'den büyük pin'e kadar olan ledleri yakıyorum
    for (byte yeniPin = 37; yeniPin <= gel; yeniPin++) {
      // kucukPin'i yakıyorum
      digitalWrite(yeniPin, HIGH);
      // bekleme süresi
      delay(50);
      // gel(buyukPin)'i -1 yapıyorum ve yeniPin(kucukPin)'den büyük olduğu sürece if sorgusuna giriyor
      if (gel - 1 >= yeniPin)
        // if sorgusuna girdiği zaman yeniPin(kucukPin)'i söndürüyorum
        digitalWrite(yeniPin, LOW);
    }
    // serial monitör'ünde break koyduğum yer
    Serial.println(gel);
    // gel(buyukPin)'i bir bir azaltıyorum
    --gel;
  }
  // for döngüsünü tersine çeviriyorum
  for (byte yeniPin = buyukPin; yeniPin >= kucukPin; yeniPin--) {
    // buyukPin'i söndürüyorum
    digitalWrite(yeniPin, LOW);
    // bekleme süresi
    delay(50);
    // kucukPin ile buyukPin eşit olduğu sürece if sorgusuna girer
    if (kucukPin == yeniPin)
      digitalWrite(yeniPin, HIGH);
    // buyukPin'i yakıyorum
  }

  // gel'i 38'e eşitliyorum
  gel = 38;

  // for dögüsü sayesinde 13 defa işlem yapması gerektiğini bildiriyorum çünkü benim 13 tane led'im var
  for (byte i = 0; i < 13; i++) {
    // for döngüsü sayesinde geri sayımı yapıyorum
    for (byte yeniPin = 49; yeniPin >= gel; yeniPin--) {
      // buyukPin'i yakıyorum
      digitalWrite(yeniPin, HIGH);
      // bekleme süresi
      delay(50);
      //  gel'i +1 yapıyorum ve 49(yeniPin)'a küçük eşit olduğu zaman if sorgusuna giriyor
      if (gel + 1 <= yeniPin)
        // buyukPin'i söndürüyorum
        digitalWrite(yeniPin, LOW);
    }
    Serial.println(gel);
    // gel'i bir bir arttırıyorum
    ++gel;
  }
}
