#include<stdlib.h>

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MAX_PIN          19

#define KROKIX 800
#define KROKIY 800
#define KROKIZ 800

String incomingByte;

int liczbakrokowX = 0;
bool DirXHIGH = true;

int liczbakrokowY = 0;
bool DirYHIGH = true;

int liczbakrokowZ = 0;
bool DirZHIGH = true;

bool response = false; //Czy drukarka ma odeslac status idle?

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(X_ENABLE_PIN,OUTPUT);
  digitalWrite(X_ENABLE_PIN,LOW);
  pinMode(X_DIR_PIN,OUTPUT);
  digitalWrite(X_DIR_PIN,DirXHIGH);
  pinMode(X_STEP_PIN,OUTPUT);
  pinMode(X_MAX_PIN,INPUT_PULLUP);
  

  pinMode(Y_ENABLE_PIN,OUTPUT);
  digitalWrite(Y_ENABLE_PIN,LOW);
  pinMode(Y_DIR_PIN,OUTPUT);
  digitalWrite(Y_DIR_PIN,DirYHIGH);
  pinMode(Y_STEP_PIN,OUTPUT);
  pinMode(Y_MAX_PIN,INPUT_PULLUP);

  pinMode(Z_ENABLE_PIN,OUTPUT);
  digitalWrite(Z_ENABLE_PIN,LOW);
  pinMode(Z_DIR_PIN,OUTPUT);
  digitalWrite(Z_DIR_PIN,DirZHIGH);
  pinMode(Z_STEP_PIN,OUTPUT);
  pinMode(Z_MAX_PIN,INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:

    if((digitalRead(X_MAX_PIN)!=1 || DirXHIGH == true) && liczbakrokowX > 0){
      digitalWrite(X_STEP_PIN,HIGH);
      liczbakrokowX--;
    }
    
    if((digitalRead(Y_MAX_PIN)!=1 || DirYHIGH == true) && liczbakrokowY > 0){
      digitalWrite(Y_STEP_PIN,HIGH);
      liczbakrokowY--;
    }
    if((digitalRead(Z_MAX_PIN)!=1 || DirZHIGH == true) && liczbakrokowZ > 0){
      digitalWrite(Z_STEP_PIN,HIGH);
      liczbakrokowZ--;
    }
      
      delayMicroseconds(500);
      digitalWrite(X_STEP_PIN,LOW);
      digitalWrite(Y_STEP_PIN,LOW);
      digitalWrite(Z_STEP_PIN,LOW);
      //delayMicroseconds(500);
      

    
    

    



//
//    if(liczbakrokowX==KROKIX){
//      //DirXHIGH=!DirXHIGH;
//      digitalWrite(X_DIR_PIN,DirXHIGH);
//      
//      liczbakrokowX=0;
//    }
//
//    if(liczbakrokowY==KROKIY){
//      //DirYHIGH=!DirYHIGH;
//      digitalWrite(Y_DIR_PIN,DirYHIGH);
//      
//      liczbakrokowY=0;
//    }
//    
//    if(liczbakrokowZ==KROKIZ){
//      //DirZHIGH=!DirZHIGH;
//      digitalWrite(Z_DIR_PIN,DirZHIGH);
//      
//      liczbakrokowZ=0;
//    }
//    


    
    if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.readStringUntil('\n');
                sscanf( incomingByte.c_str(), "a %d b %d c %d", &liczbakrokowX, &liczbakrokowY, &liczbakrokowZ);
                response=true;
                DirXHIGH=liczbakrokowX<0;
                liczbakrokowX=abs(liczbakrokowX);
                digitalWrite(X_DIR_PIN,DirXHIGH);

                DirYHIGH=liczbakrokowY<0;
                liczbakrokowY=abs(liczbakrokowY);
                digitalWrite(Y_DIR_PIN,DirYHIGH);

                DirZHIGH=liczbakrokowZ<0;
                liczbakrokowZ=abs(liczbakrokowZ);
                digitalWrite(Z_DIR_PIN,DirZHIGH);


                
                // say what you got:
                //Serial.print("I received: ");
                //Serial.println(incomingByte);
        }

   if(liczbakrokowX==0 && liczbakrokowY==0 && liczbakrokowZ==0 && response){
    Serial.print("idle\n");
    response=false;
   }
}
