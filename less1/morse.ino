#include <morse.h>

Morse m(13);
char Code[100];
int i,n=0;
void setup() {

  Serial.begin(9600);
}

void loop() {

  while(Serial.available()>0){
      Code[n]=Serial.read();
      n++;
    }
  for(i=0;i<n;i++){
      m.changeMorse(Code[i],m);
    }
}
