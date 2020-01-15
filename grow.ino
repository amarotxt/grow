#include <Wire.h>  //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
 
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //FUNÇÃO DO TIPO "LiquidCrystal_I2C"
 
void setup()
{
  //inicializa o display (16 colunas x 2 linhas)
  lcd.begin (16,2); // ou 20,4 se for o display 20x4
}
 
void loop(){
    //acende o backlight do LCD
    lcd.setBacklight(HIGH);
    //posiciona o cursor para escrita
    //.setCursor(coluna, linha)
    lcd.setCursor(0,0);
    lcd.print("FERNANDOK.COM");
    lcd.setCursor(0,1);
    lcd.print("ACESSE!!!");
    delay(1000); //intervalo de 1s
    //desliga o backlight do LCD
    lcd.setBacklight(LOW);
    delay(1000); //intervalo de 1s
}
