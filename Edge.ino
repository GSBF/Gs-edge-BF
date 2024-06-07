#include <LiquidCrystal.h>

const int potentiometer1Pin = A1; // Potenciômetro 1 substituindo o sensor de salinidade
const int potentiometer2Pin = A0; // Potenciômetro 2 substituindo o sensor de pH
const int greenLedPin = 8;
const int yellowLedPin = 9;
const int redLedPin = 10;
const int buzzerPin = 6;

const float tempLimiteMin = 20.0; // Temperatura mínima adequada
const float tempLimiteMax = 30.0; // Temperatura máxima adequada
const float tempLimiteAlertaMin = 15.0; // Temperatura mínima de alerta
const float tempLimiteAlertaMax = 35.0; // Temperatura máxima de alerta

const unsigned long displayUpdateInterval = 5000; // 5 segundos

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long lastDisplayUpdateTime = 0;
int displayMode = 0; // 0 para temperatura, 1 para salinidade, 2 para pH

byte sphereChar[8] = {
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(0, sphereChar);
  
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  const float BETA = 3950; // Deve corresponder ao coeficiente beta do termistor
  int analogValue = analogRead(A2);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;

  int potentiometer1Value = analogRead(potentiometer1Pin);
  float salinity = map(potentiometer1Value, 0, 1023, 0, 100); 

  int potentiometer2Value = analogRead(potentiometer2Pin);
  float pH = map(potentiometer2Value, 0, 1023, 0, 14);

  unsigned long currentMillis = millis();
  if (currentMillis - lastDisplayUpdateTime >= displayUpdateInterval) {
    updateDisplay(celsius, salinity, pH);
    lastDisplayUpdateTime = currentMillis;
  }

  // Verificar a temperatura e controlar os LEDs, o buzzer e exibir mensagens no LCD
  if (celsius <= 5) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    noTone(buzzerPin);
    
  } else if (celsius > 5 && celsius <= 15) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    noTone(buzzerPin);
    
  } else if (celsius > 15 && celsius <= 30) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    noTone(buzzerPin);
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    tone(buzzerPin, 1000); 
    delay(1000); 
    noTone(buzzerPin); 
  }

  delay(1000); 
}

void updateDisplay(float celsius, float salinity, float pH) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.print("Blue Sphere");

  lcd.setCursor(0, 1);
  
  switch (displayMode) {
    case 0: 
      lcd.print("Temp: ");
      lcd.print(celsius);
      lcd.print(" C");
      Serial.print(celsius);
      Serial.println(" °C");
      displayMode = 1; 
      break;
      
    case 1: 
      lcd.print("Salin: ");
      lcd.print(salinity);
      lcd.print("%");
      Serial.print("Salinity: ");
      Serial.print(salinity);
      Serial.println(" %");
      displayMode = 2; 
      break;
      
    case 2: 
      lcd.print("pH: ");
      lcd.print(pH);
      Serial.print("pH: ");
      Serial.println(pH);
      displayMode = 0; 
      break;
  }
}
