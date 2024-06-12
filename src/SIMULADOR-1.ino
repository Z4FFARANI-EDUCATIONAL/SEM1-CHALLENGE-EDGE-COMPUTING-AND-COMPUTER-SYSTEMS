#include "DHT.h"
#include "LiquidCrystal.h"

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  delay(500);
}

void loop() {
  analise();
  estrategia();
  delay(1000);
}

void analise() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Erro ao ler");
    lcd.setCursor(0, 1);
    lcd.print("sensor DHT!");
    return;
  }

  lcd.setCursor(2, 0);
  lcd.print("TEMPERATURA:");
  lcd.setCursor(4, 1);
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  delay(2000);
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("UMIDADE:");
  lcd.setCursor(5, 1);
  lcd.print(h);
  lcd.print("%");

  delay(2000);
  lcd.clear();
}

void estrategia() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Erro ao ler");
    lcd.setCursor(0, 1);
    lcd.print("sensor DHT");
    return;
  }
  

  if ((t >= 25 && t <= 40) && (h >= 0 && h <= 40)) {
    lcd.setCursor(0, 0);
    lcd.print("BATERIA!");
    lcd.setCursor(0, 1);
    lcd.print("Sobreaquece +");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("PNEUS!");
    lcd.setCursor(0, 1);
    lcd.print("Desgastam +");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Minimize carga");
    lcd.setCursor(0, 1);
    lcd.print("e ajuste o ritmo");
    delay(3000);
    lcd.clear();
    

  } else if ((t >= 25 && t <= 40) && (h >= 40 && h <= 70)) {
    lcd.setCursor(0, 0);
    lcd.print("PILOTO!");
    lcd.setCursor(0, 1);
    lcd.print("Hidrate-se");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("VENTILACAO!");
    lcd.setCursor(0, 1);
    lcd.print("Ative o sistema");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Procure ajuste");
    lcd.setCursor(0, 1);
    lcd.print("de resfriamento");
    delay(3000);
    lcd.clear();


  } else if ((t >= 0 && t <= 25) && (h >= 0 && h <= 40)) {
    lcd.setCursor(0, 0);
    lcd.print("BATERIA!");
    lcd.setCursor(0, 1);
    lcd.print("Aqueca-a");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("PNEUS!");
    lcd.setCursor(0, 1);
    lcd.print("Aqueca-os");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Mapear motor e");
    lcd.setCursor(0, 1);
    lcd.print("aquecer o carro");
    delay(3000);
    lcd.clear();


  } else if ((t >= 0 && t <= 25) && (h >= 40 && h <= 70)) {
    lcd.setCursor(0, 0);
    lcd.print("PISTA!");
    lcd.setCursor(0, 1);
    lcd.print("Escorregadia");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("BATERIA!");
    lcd.setCursor(0, 1);
    lcd.print("Aqueca-a");
    delay(3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Conduza-se");
    lcd.setCursor(0, 1);
    lcd.print("suavemente");
    delay(3000);
    lcd.clear();


  } else {
    lcd.setCursor(0, 0);
    lcd.print("CONDICOES");
    lcd.setCursor(0, 1);
    lcd.print("EXTREMAS!");
    delay(3000);
    lcd.clear();
  
    lcd.setCursor(0, 0);
    lcd.print("CORRIDA");
    lcd.setCursor(0, 1);
    lcd.print("CANCELADA");
    delay(3000);
    lcd.clear();
  }
}