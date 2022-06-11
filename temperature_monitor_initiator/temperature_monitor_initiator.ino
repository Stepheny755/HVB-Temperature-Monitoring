//MASTER

#include <Wire.h>

const int tempSensorNumb = 7;

char rawReceive[20]={};
char tempReceive[10]={};
char SOCReceive[10]={};

void setup()
{
  //sets arduino as master
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  for (int x = 1; x <= tempSensorNumb; x++)
  {
  
    //request event (4 characters) from arduino with address x
    Wire.requestFrom(x,11);
  
    //counter for each byte
    int i=0;
    while (Wire.available())
    {
    	//put each character that arrives in empty array t
    	rawReceive[i] = Wire.read();
    	i = i+1;
    }

    i = 0;
    
    while(sent[i] != 's' && i <= 10){
      tempReceive[i] = rawReceive[i];
      i++;
    }
    
    Serial.print("Temp ");
    Serial.print(x);
    Serial.print(": ");
    Serial.println(tempReceive);
    
    i++;
    int j = 0;
    while(((rawReceive[j+i] >= '0' && rawReceive[j+i] <= '9') || rawReceive[j+i] == '.') && j <= 10){
      SOCReceive[j] = rawReceive[j+i];
      j++;
    }
    
    
    Serial.print("SOC ");
    Serial.print(x);
    Serial.print(": ");
    Serial.println(SOCReceive);
    
              
    delay(500);
    
  }
}