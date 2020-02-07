#define in1 2
#define in2 3
int LDRO;
int LDRT;
int poserror;
int error;
long valor; //posicion del potenciometro en tanto por ciento
unsigned long t;
unsigned long previousMillis;
unsigned long startMillis;
unsigned long currentMillis;
const long interval = 2000;

void setup() {
   Serial.begin(250000);
   startMillis = micros();
   for (int i = 6 ; i<11 ; i++)
      pinMode( i, OUTPUT);
   }

void loop() {
  analogWrite(10,255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  LDRO = analogRead(A0);
  LDRT = analogRead(A1);
  valor = analogRead(A2);
  currentMillis = micros();
  t = currentMillis - startMillis;
  error= LDRO-LDRT;
  poserror = abs(error);
  if (poserror > 50){
     if (error > 0) {
       digitalWrite(in2, HIGH);
       //Serial.print("IN2 HIGH");
      }
    else if (error < 0)    {
      //Serial.print("IN1 HIGH");
      digitalWrite(in1, HIGH);
  }}
  else if (poserror <= 50 )  {
    //Serial.print("AMBOS LOW");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    }
  /*if ( resta < -100){ digitalWrite(in2, HIGH); digitalWrite(in1 , LOW);
  Serial.println("primer condicional");}
  if ( resta  > 100){ digitalWrite(in1, HIGH); digitalWrite(in2 , LOW); 
   Serial.println("segundo condicional");}
  else{ digitalWrite(in1, LOW); digitalWrite(in2 , LOW); 
   Serial.println("tercer condicional");}*/
  if (currentMillis - previousMillis >= interval) {
    Serial.print(valor);
    Serial.print(",");
    Serial.print(LDRO);
    Serial.print( ",") ;
    Serial.print(LDRT);
    Serial.print( ",") ;
    Serial.print(digitalRead(in1));
    Serial.print(",");
    Serial.println(digitalRead(in2));
    previousMillis = currentMillis;
  }
  delay(100);
}
