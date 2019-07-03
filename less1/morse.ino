#include <Morse.h>
Morse m(13);
char Code[100];
int i,n=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    Code[n]=Serial.read();
    n++;
    }
  for(i=0;i<n;i++){
    m.changeMorse(Code[i],m);
    }
}
