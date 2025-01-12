#include <LiquidCrystal.h>
#include<Arduino_FreeRTOS.h>
int hh = 0, mm = 0,ss=0; //inicialización de variables
void prueba(void*){
  Serial.begin(9600);
  while(!Serial);
  while(1){
    Serial.print(hh); //imprime la hora
    Serial.print(":"); //:
    Serial.print(mm); //minutos
    Serial.print(":"); //:
    Serial.println(ss);//Segundos
    }
  }

  
void tiempo(void*){  
  while(1){  //Loop infinito para que no finalice la tarea
    
    vTaskDelay(63);
    
    if(ss>=59){//Si es mayor o igual que 59 reinicia el contador y incrementa +1 en mm
    ss=0;
    mm++;
    }   
    
    else if(mm>=60){ //Si es mayor o igual a 60 reinicia ss,mm e incrementa la hora
    ss=0;
    mm=0;
    hh++;
    }
    else if(hh>=24){ //Si es mayor o igual a 24 reincia los 3 valores, ss,mm,hh
    ss=0;
    mm=0;
    hh=0;
    }
    else{ss++;}
    //ss++;
  }
  }
void mostrar (void*){ //Logica para mostar la hora en formato 00:00:00 y asi evitar que muestre 0:0:0
  LiquidCrystal lcd(12, 10, 5, 4, 3, 2);
  lcd.begin(16, 1); 
 // lcd.setCursor(4, 0); 
  while(true){
  if (hh < 10) {lcd.print("0"); }
  lcd.print(hh); lcd.print(":"); 

 
  if (mm < 10) {lcd.print("0"); }
  lcd.print(mm);lcd.print(":");
  

  if (ss < 10) {lcd.print("0");}
  lcd.print(ss);
  
 vTaskDelay(10);//Eliminar
  lcd.clear();
  //lcd.setCursor(4, 0); 
}
}

int boton1=0,boton2=0;

void cambio(void*){ //Se configuran dos pines para poder incrementar  el valor de los minutos y de las horas
    pinMode(7,INPUT); 
    pinMode(8,INPUT);
    while(1){
    boton1=digitalRead(7);
    if(boton1){
    while(digitalRead(7)){}
    mm++;
    if(mm>=60){
    mm=0;
    hh++;
    }
   
    vTaskDelay(2);
    }
    boton2=digitalRead(8);
    if(boton2){
    while(digitalRead(8)){}
    hh++;
    if(hh>=24){

    hh=0;
    }
    vTaskDelay(2);
    }
      }
  }

void setup() {
  //Se hace la creación de tareas, las cuales montraran la hora en el lcd
   xTaskCreate(mostrar, "mostrarLCD",128,NULL,1,NULL);
   xTaskCreate(tiempo, "timeSS",128,NULL,1,NULL); //Es la encargada de llevar el tiempo
   xTaskCreate(cambio, "cambio",128,NULL,1,NULL); //Es la encargada de camviar las variables de minuto y hora
  // xTaskCreate(prueba, "prueba",128,NULL,1,NULL);
}

void loop() {
  // No requiere codigo en Lopp al estar inicializado en setup con un loop infinito
  }
