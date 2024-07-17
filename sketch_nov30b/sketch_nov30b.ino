 #include <PS2X_lib.h>

int error =0;
byte vibrate=0;
PS2X ps2x;
int LX;
int LY;
int RX;
int RY;


int BlancoA=2; // (A= Adelante) y (R= Reversa)
int BlancoR=3;
int AzulA=5;
int AzulR=4;

void setup() {
  // put your setup code here, to run once:
    pinMode (BlancoA , OUTPUT);
    pinMode (BlancoR , OUTPUT);
    pinMode (AzulA , OUTPUT);
    pinMode (AzulR , OUTPUT);
    error = ps2x.config_gamepad (7, 8, 9, 10, true, true );
    Serial.begin (9600);

}

void loop() {
  ps2x.read_gamepad();

  if (ps2x.Button(PSB_BLUE)){
    Adelante ();
  }
  if (ps2x.Button(PSB_PINK)){
    Atras ();
  }
  if (RY > 130){
    Adelante ();
  }
  if (RY < 120 ){
    Quieto ();
  }
  if (LX > 130){
    Girar_blanco ();
  }
  if (LX < 120){
    Girar_azul ();
  }

  RX = (ps2x.Analog (PSS_RX));
  Serial.print (" RX;");
  Serial.println (  RX);

   LX = (ps2x.Analog (PSS_LX));
  Serial.print (" LX;");
  Serial.println (  LX);

   RY = (ps2x.Analog (PSS_RY));
  Serial.print (" RY;");
  Serial.println (  RY);

   LY = (ps2x.Analog (PSS_LY));
  Serial.print (" LY;");
  Serial.println (  LY);

  delay(50);

}

 void Adelante (){
 digitalWrite(BlancoA, HIGH);
 digitalWrite(BlancoR, LOW);
 digitalWrite(AzulA, HIGH);
 digitalWrite(AzulR, LOW);

 }

 void Atras (){
 digitalWrite(BlancoA, LOW);
 digitalWrite(BlancoR, HIGH);
 digitalWrite(AzulA, LOW);
 digitalWrite(AzulR, HIGH);

 }

void Girar_azul (){
 digitalWrite(BlancoA, HIGH)
 digitalWrite(BlancoR, LOW);
 digitalWrite(AzulA, LOW);
 digitalWrite(AzulR, HIGH);

}

 void Girar_blanco(){
 digitalWrite(BlancoA, LOW)
 digitalWrite(BlancoR, HIGH);
 digitalWrite(AzulA, HIGH);
 digitalWrite(AzulR, LOW);

 }

 void Quieto (){
 digitalWrite(BlancoA, LOW)
 digitalWrite(BlancoR, LOW);
 digitalWrite(AzulA, LOW);
 digitalWrite(AzulR, LOW);

 }


