// Kullanacağım kütüphane'ler
#include <SPI.h>
#include <Ethernet2.h> // Bu kütüphaneyi https://github.com/adafruit/Ethernet2 indire bilirsiniz

// Button için kullanılacak pinler
#define pin_22  22
#define pin_24  24
#define pin_26  26
#define pin_28  28

// Kullanacağım LED pinleri
const int kucukPin = 37;
const int buyukPin = 49;

// Kullanacağım Button'ların durumlarını belirleyeceğim
static int btn_22 = 0;
static int btn_24 = 0;
static int btn_26 = 0;
static int btn_28 = 0;

// Ether Shield altındaki etikette yazılı MAC adresi
byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x2E, 0xF1 };

// 192.168.1 segmentindeki kullandığım adres
// Sizin segmentiniz hangisi ise ona göre değişin
IPAddress ip(192, 168, 1, 177);

// Web Server'ların genel http portu olan '80'
EthernetServer server(80);

void setup() {
  // Serial Monitor'den gelen bilgileri görmek için kullandım
  // Serial'dan(USB) bilgi almak ve vermek için de kullanılır
  Serial.begin(9600);

  // Pinleri OUTPUT için ayarlıyorum
  for (int buPin = kucukPin; buPin <= buyukPin; buPin++) {
    pinMode ( buPin, OUTPUT);
    digitalWrite(buPin, LOW);
  }
  // Button'ları INPUT için ayarlıyorum
  pinMode ( pin_22, INPUT); digitalWrite(pin_22, LOW);
  pinMode ( pin_24, INPUT); digitalWrite(pin_24, LOW);
  pinMode ( pin_26, INPUT); digitalWrite(pin_26, LOW);
  pinMode ( pin_28, INPUT); digitalWrite(pin_28, LOW);

  // Ethernet'i mac adresi ve IP için set ediyorum
  Ethernet.begin(mac, ip);

  // Server başlıyor
  server.begin();
  // Serial monitor'dan bilgileri görmek için kullandım
  Serial.print("server ip Adresi : ");
  Serial.println(Ethernet.localIP());
}
boolean istekVar = false;  // ? işaretini kontrol için kullandım
int pin; // Bu pin'e göre değer kullanacağım ve html'i buna göre dizayn edeceğim

void loop() {
  butonOku(); // Butonları okuyorum
  SmartHouse();
}


void SmartHouse() {
  EthernetClient client = server.available();

  // Eğer client varsa alt bölüme girer yoksa girmez
  if (client) {
    Serial.println("Basla");

    // client'a bağlandıysa buraya girer
    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); // client'ı c ye atıyoruz

        if (istekVar && c == ' ') istekVar = false; // istek yok
        if (c == '?') istekVar = true; // istek var

        if (istekVar) { // istek varsa buraya girer
          if (c == 'M') {
            Serial.print("Mutfak is open : ");
            pin = client.parseInt(); // Gelen numarayı pin'e atıyorum
            Serial.println(pin);
            digitalWrite(pin, HIGH);
          }
          else if (c == 'm') {
            Serial.print("Mutfak is closed : ");
            pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, LOW);
          }

          if (c == 'S') {
            Serial.print("Salon is open : ");
            pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, HIGH);
          }
          else if (c == 's') {
            Serial.print("Salon is closed : ");
            pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, LOW);
          }

          if (c == 'K') {
            Serial.print("Kombi is open : ");
            pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, HIGH);
          }
          else if (c == 'k') {
            Serial.print("Kombi is closed : ");
            pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, LOW);
          }

          if (c == 'L') {
            Serial.print("Klima is open : ");
            pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, HIGH);
          }
          else if (c == 'l') {
            Serial.print("Klima is closed : ");
            pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, LOW);
          }
        }

        if (c == '\n' ) { // istek doğru ise html'yi yazmaya başladım, siz istediğiniz gibi değişe bilirsiniz
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 5"); // 5 saniyeye ayarladım isterseniz değişe bilirsiniz
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<head><meta charset=\"utf-8\"><title>AMG</title></head>"); // Karakter seti ayarladım
          client.println("<html>");

          client.println("<table align=\"center\"><tr><td>");
          client.println("<label style=\"color:red; font-size:14pt;\" ><b><font face=\"monotype corsiva\"><font color=\"white\">---</font>Akıllı Ev Otomasyonu</font></b></label><br>");
          client.println("<label style=\"color:navy; font-size:14pt;\" >İnternet ve Kapasitif Button Kontrolu</label>");
          client.println("</td></tr></table><hr>");

          client.println("<table border=\"3\" style=\"width:100;\" bordercolor=\"black\" align=\"center\" bgcolor=\"cyan\">");

          //Mutfak
          if ( pin == 47 ) {
            if ( !digitalRead(pin) ) {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='M' value='47' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Mutfak' />");
              client.println("</form>");
              client.println("</td>");
            }
            else {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='m' value='47' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Mutfak' />");
              client.println("</form>");
              client.println("</td>");
            }
          }
          else {
            if ( !digitalRead(47) ) {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='M' value='47' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Mutfak' />");
              client.println("</form>");
              client.println("</td>");
            }
            else {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='m' value='47' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Mutfak' />");
              client.println("</form>");
              client.println("</td>");
            }
          }

          //Salon
          if ( pin == 46 ) {
            if ( !digitalRead(pin) ) {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='S' value='46' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Salon' />");
              client.println("</form>");
              client.println("</td></tr>");
            }
            else {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='s' value='46' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Salon' />");
              client.println("</form>");
              client.println("</td></tr>");
            }
          }
          else {
            if ( !digitalRead(46) ) {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='S' value='46' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Salon' />");
              client.println("</form>");
              client.println("</td></tr>");
            }
            else {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='s' value='46' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Salon' />");
              client.println("</form>");
              client.println("</td></tr>");
            }
          }

          //Kombi
          if ( pin == 45 ) {
            if ( !digitalRead(pin) ) {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='K' value='45' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Kombi' />");
              client.println("</form>");
              client.println("</td>");
            }
            else {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='k' value='45' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Kombi' />");
              client.println("</form>");
              client.println("</td>");
            }
          }
          else {
            if ( !digitalRead(45) ) {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='K' value='45' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Kombi' />");
              client.println("</form>");
              client.println("</td>");
            }
            else {
              client.println("<tr><td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='k' value='45' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Kombi' />");
              client.println("</form>");
              client.println("</td>");
            }
          }

          // Klima
          if ( pin == 44 ) {
            if ( !digitalRead(pin) ) {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='L' value='44' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Klima' />");
              client.println("</form>");
              client.println("</td></tr></table><hr>");
            }
            else {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='l' value='44' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Klima' />");
              client.println("</form>");
              client.println("</td></tr></table><hr>");
            }
          }
          else {
            if ( !digitalRead(44) ) {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='L' value='44' />");
              client.println("<input style=\"width:100px; height:100px;\" type='submit' value='Klima' />");
              client.println("</form>");
              client.println("</td></tr></table><hr>");
            }
            else {
              client.println("<td>");
              client.println("<form action='' method='get'>");
              client.println("<input type='hidden' name='l' value='44' />");
              client.println("<input style=\"width:100px; height:100px; background:green;\" type='submit' value='Klima' />");
              client.println("</form>");
              client.println("</td></tr></table><hr>");
            }
          }

          //Footer
          client.println("<table align=\"right\" border=\"0\"><tr><td>");
          client.println("<label style=\"color:navy; font-size:14pt;\" align=\"center\" ><i><u><b>Ahmet Mustafa GÜRGÜN<br>AMP-11/H<br>ahmetmustafafaruk@hotmail.com</b></u></i></label></td></tr></table>");

          client.println("</html>");
          break;
        }
      }
    }
    delay(1); // Bekliyorum
    client.stop(); // Kapatıyorum
    Serial.println("client Kapat");
  }
}

void butonOku() {
  btn_22 = digitalRead( pin_22 );
  if (btn_22 == 1)
  {
    // Kapasitiv button kullandığım için böyle yaptım
    digitalWrite(44, !digitalRead(44)); // Önce button'u oku sonra pin'i oku değilini al, yukarıdaki html ile aynı çalışması için

    // Push button kullanımı daha kolaydır eğer push button kullanıyorsanız alttaki kodu yazmalısınız, üstteki kodu kapatmalısınız
    // digitalWrite(pin_22, HIGH);
  }
  //  else {
  //    Push button kullanımı daha kolaydır eğer push button kullanıyorsanız alttaki kodu yazmalısınız
  //    digitalWrite(pin_22, LOW);
  // Eğer push button kullanacaksanız alttaki if'leri de buna benzetmelisiniz
  //  }

  btn_24 = digitalRead( pin_24 );
  if (btn_24 == 1)
  {
    digitalWrite(45, !digitalRead(45));
  }

  btn_26 = digitalRead( pin_26 );
  if (btn_26 == 1)
  {
    digitalWrite(46, !digitalRead(46));
  }

  btn_28 = digitalRead( pin_28 );
  if (btn_28 == 1)
  {
    digitalWrite(47, !digitalRead(47));
  }
}


