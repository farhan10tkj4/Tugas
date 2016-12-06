int potPin = 0; // select the input pin for the LM35
float temperature = 0;
int suhu;
long val = 0;
int ledmerah = 7;
int ledkuning = 6;
int ledhijau = 4;
void setup()
{
Serial.begin(9600);
pinMode(ledmerah, OUTPUT);
pinMode(ledkuning, OUTPUT);
pinMode(ledhijau, OUTPUT);
}
void loop()
{
if (Serial.available()) // if monitor screen opened
{
val = analogRead(potPin); // read the value from the sensor
temperature = (5.0 * val * 100.0)/1024.0;
suhu = temperature;
Serial.println("Suhu sekarang adalah : ");
Serial.println((long)temperature);
if (suhu > 30) { // Jika suhunya lebih besar dari 30 derajat
digitalWrite(ledmerah,HIGH);
digitalWrite(ledkuning,LOW);
digitalWrite(ledhijau,LOW);
}
if (suhu >=27 || suhu <= 30) { // Jika suhunya antara 27-30 derajat
digitalWrite(ledkuning,HIGH);
digitalWrite(ledhijau,LOW);
digitalWrite(ledmerah,LOW);
}
if (suhu < 27) { // Jika suhunya kurang dari 27 derajat
digitalWrite(ledhijau,HIGH);
digitalWrite(ledmerah,LOW);
digitalWrite(ledkuning,LOW);
}
}
delay(5000);
}
