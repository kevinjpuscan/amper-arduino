#include <EmonLib.h>
EnergyMonitor emon1;

//Tensao da rede eletrica
int rede = 220;
 
//Pino do sensor SCT
int pino_sct = A1;

void setup() {
    Serial.begin(9600);
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 2000/33 = 60
  emon1.current(pino_sct, 60);
 

}

void loop() {
    if(Serial.available()>0){
      char option=Serial.read();
      

     if(option=='a'){
          //Calcula a corrente
          double Irms = emon1.calcIrms(1480);
          //Irms=getValueValidate(Irms,10.0);
          Serial.println(Irms,4); // Irms
      }
      
     if(option=='b'){
          //Calcula a corrente
          double Irms = emon1.calcIrms(1480);
          Irms=getValueValidate(Irms,1.0);
          Serial.println(Irms,4); // Irms
      }
 
          
          
  
    }
 
}

double getValueValidate(double v, double factor){
   if(v>=0.15){
      return (v-0.15)/factor;
    }
    return 0.0;
  }