/*
  Deurbel sensor
  Meet spanning over een diode en zet dan poort 13 hoog. 
  Bel niet ingedrukt: 0.2V (1M over ingang)
  Bel ingedrukt: 0.8V
  Trigger spanning: 0.7V (1024/5 *0.7=143
  
  jan 2015
 */
 
// Pin 13 has an LED connected on most Arduino boards.

int led = 13;
int bel = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {
  bel = analogRead(0);
  Serial.println(bel);
  if (bel> 143)
  {
  Serial.print("Deurbel ingedrukt: ");
  Serial.println(bel);
  digitalWrite(led, HIGH);   // Led en Bel aan
  delay(500);               // hou vast
  digitalWrite(led, LOW);    // Led en Bel uit
  delay(100);               // even wachten
  }
}
