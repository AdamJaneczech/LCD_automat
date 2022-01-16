#include <LiquidCrystal_I2C.h>
#include <Servo.h>

/*---220117---
 * přidání proměnných s možnostmi
 * přidání polí s názvy možností (dvouvrstvé menu - START, OBJEM -> nastavení po 5 ml)
 * debouncing tlačítka
 * přidání potvrzovacího tlačítka
 * přidání relé
 * funkce potvrzovacího tlačítka
 * popř. přidávání objemu
 */

LiquidCrystal_I2C displej(0x27, 16, 2); //definice displeje displej dle knihovny LiquidCrystal_I2C
//    hodnoty v závorce: (adresa displeje, počet znaků na šířku, počet znaků na výšku)

Servo servo;  //definice serva servo dle knihovny Servo

void setup() {
  servo.attach(9);  //přiřazení pinu 9 na Arduino servu
  
  displej.init(); //inicializace displeje - nutný příkaz na začátek
  displej.backlight(); //zapnutí podsvícení displeje
  displej.setCursor(1,0); //nastavení kurzoru (X - na šířku, Y - na výšku)
  displej.print("Moznost 1"); //vytiskni na displeji
  displej.setCursor(1,1);
  displej.print("Moznost 2");
  displej.setCursor(0,0);
  displej.print(">");
  //">" na pozici displeje 0,0

  byte moznost = 0;
  byte predchoziMoznost = 0;
  
  pinMode(2, INPUT);  //nastavení směru pinu -> pin 2 nastaven jako vstup (INPUT)
  pinMode(3, INPUT);
}

void loop() {
  
  if(digitalRead(2) == true && digitalRead(3) == false){  //digitalRead(digitální pin) -> čtení z digitálního pinu; true - pravda -> 5 V (tlačítko stisknuto), false - nepravda -> 0 V
    displej.setCursor(0,0);
    displej.print(" ");
    displej.setCursor(0,1);
    displej.print(">");
  }

  if(digitalRead(3) == true && digitalRead(2) == false){
    displej.setCursor(0,1);
    displej.print(" ");
    displej.setCursor(0,0);
    displej.print(">");
  }

}
