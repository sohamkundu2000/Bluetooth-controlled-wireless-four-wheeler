#include<SoftwareSerial.h>
SoftwareSerial BT(10,11);

  char t;
void setup() {
  pinMode(13,OUTPUT);//led
  pinMode(12,OUTPUT);//LEFT MOTOR REVERSE
  pinMode(11,OUTPUT);//RIGHT MOTORS FORWARD
  pinMode(10,OUTPUT);//RIGHT MOTORS REVERSE
  pinMode(9,OUTPUT);//left motors forward
  Serial.begin(9600);
  BT.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  
  if(BT.available()){
  t=BT.read();
  Serial.println(t);
  }
  if(t='F'){                        //move forward
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW); 
  }
  else if(t='B'){                 //move backward
    digitalWrite(12,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
  }
  
  else if(t='R'){                //turn right
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);
   digitalWrite(11,HIGH); 
   digitalWrite(12,LOW);
  }
  else if(t='L'){                //turn left
     digitalWrite(13,HIGH); 
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
       }
  else if(t='W'){                 //turn on led
    digitalWrite(9,HIGH);
  }
  else if(t='w'){                  //turn off led
    digitalWrite(9,LOW);
  }
 
  else if(t='S'){                  //stop
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
  delay(20);
}
    
  
 


  // put your main code here, to run repeatedly:
