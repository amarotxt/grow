#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int LM35 = 0; 
float temp = 0; 
int LM35_ADC = 0; 

byte custom[8] = {
  0b00111,          // Caractere customizado
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{  
  Serial.begin(9600);   
  analogReference(INTERNAL);  // Muda a referência de 5V para 1,1V
  lcd.init();           
  lcd.backlight(); 
  lcd.createChar(5, custom); // Cria nosso caractere definindo-o como o byte 5

}  

void loop()
{   
  LM35_ADC = analogRead(LM35);   // Lê o valor no pino A0
  temp = LM35_ADC * 0.1075268817;    //Transforma o nº analógico para ºC
  lcd.print("  Temp = ");
  lcd.print(temp);   
  lcd.print(" C"); 
  lcd.home(); // Seta o cursor para o inicio caracter 0, na linha 0
  lcd.print("->");  
  lcd.setCursor(14,0); // Seta o cursor para o caracter 14, na linha 0
  lcd.write(5); // Imprime o byte 5(nosso caracter custom)
  delay(1000); 
  lcd.clear(); //Limpa a tela do LCD
}
  
