#include <SoftwareSerial.h>

#include <Servo.h>
SoftwareSerial H1(2,3);
Servo ser;
int v;
char c;


String mensaje;




void setup() {
pinMode(13,1);
pinMode(5,1);
pinMode(6,1);
pinMode(9,1);
pinMode(10,1);
pinMode(11,1);
ser.attach(8);
Serial.begin(9600);
H1.begin(9600);

}

void loop() {
  digitalWrite(13,0);
  // put your main code here, to run repeatedly:
while(H1.available()){
  delay(5); 
   c = H1.read();
      if (c=='d'){
        llan();
      }

      if (c=='a'){
      dir();
      }

      if (c=='b'){
        vel();
        }
      }
  
}

void dir(){
  delay(3);
  while (H1.available()){
    c= H1.read();
    mensaje += c;
  }
  if (mensaje.length()>0){
    Serial.println(mensaje.toInt());
    ser.write(180-mensaje.toInt());
    mensaje="";
  }
}
void vel(){
  delay(3);
  while (H1.available()){
    c= H1.read();
    mensaje += c;
  }
  if (mensaje.length()>0){
 Serial.println(mensaje.toInt());
  v=(mensaje.toInt());
    mensaje="";
  }
  
}
void llan(){
    delay(3);
  while (H1.available()){
    c= H1.read();
    mensaje += c;
  }
  if (mensaje.length()>0){
    Serial.println(mensaje.toInt());

if((mensaje.toInt())==1){
      digitalWrite(5,1);
      digitalWrite(6,0);
      digitalWrite(9,0);
      digitalWrite(11,1);
    
   } 
  if ((mensaje.toInt())==2){
       digitalWrite(5,0);
       digitalWrite(6,1);
       digitalWrite(9,1);
       digitalWrite(11,0);
   } 
   if((mensaje.toInt())==3){
      digitalWrite(5,1);
      digitalWrite(6,0);
      digitalWrite(9,1);
      digitalWrite(11,0);
    
   } 

   if((mensaje.toInt())==4){
      digitalWrite(5,0);
      digitalWrite(6,1);
      digitalWrite(9,0);
      digitalWrite(11,1);
    
   }
   if((mensaje.toInt())==0){
      analogWrite(5,0);
      analogWrite(6,0);
      analogWrite(9,0);
      analogWrite(11,0);
    
   }

    mensaje="";
  
  

  
}
}
