void inicio(){
  Serial.println("Iniciando lectura...");
  delay(1000); 
}

int LecturaSensor() {
  digitalWrite(13, HIGH);
  int lectura= analogRead(A0);
  delay(2000);
  digitalWrite(13, LOW);
  delay(2000);
  digitalWrite(14,HIGH);
  delay(2000);
  digitalWrite(14,LOW);
  delay(2000);
  return lectura;
}

float convertir(int voltaje){
  float volt= voltaje*(5.0/1023.0);
  return volt;
}

void imprimir(float vol){
  Serial.print("El voltaje es de ");
  Serial.println(vol);
}

void loop(){
  inicio();
  int leer= LecturaSensor();
  Serial.print("Lectura ADC: ");
  Serial.println(leer);
  delay(1000);
  
  float volt=convertir(leer);
  imprimir(volt);
}

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

