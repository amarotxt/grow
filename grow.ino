#include <Wire.h>  //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
#include "DHT.h"
#include <NTPClient.h>
#include "ESP8266WiFi.h"
#include <WiFiUdp.h>

#define DHTPIN 9  // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
//
//const char *ssid = "Amaro";
//const char *password = "Marleyyury";
//
//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP);


DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 16, 2); //FUNÇÃO DO TIPO "LiquidCrystal_I2C"

void setup()
{
  //inicializa o display (16 colunas x 2 linhas)
  //lcd.begin (16, 2); // ou 20,4 se for o display 20x4
  Serial.begin(9600);
//  lcd.init();
  dht.begin();
//  lcd.backlight();
//  lcd.setCursor(0, 0);
//  lcd.print("TESTE");
  
  //Serial.begin(115200);
//  WiFi.begin(ssid, password);
//  while ( WiFi.status() != WL_CONNECTED ) {
//    delay ( 500 );
//    Serial.print ( "." );
//  }
//  timeClient.begin();
}

void loop() {
  //acende o backlight do LCD
  float humidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
//  Serial.println("CONSEGUI GRAVAR");
   if (isnan(temperatura) || isnan(humidade)) 
  {
    Serial.println("Failed to read from DHT");
  } 
//    timeClient.update();
//
//    Serial.println(timeClient.getFormattedTime());
  
    delay(1000);
//    lcd.print("TESTE");
}
