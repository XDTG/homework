void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);//input 1
  pinMode(3, OUTPUT);//input 2
  pinMode(4, OUTPUT);//input 3
  pinMode(5, OUTPUT);//input 4
  pinMode(6, OUTPUT);//LE
  pinMode(7, OUTPUT);//BI
  pinMode(8, OUTPUT);//LT
  
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  
}

int income = 0;

void loop()
{
  if(Serial.available()){
    income = int(Serial.read() - '0');
    if(income >= 0 && income <= 9){
      Serial.println(income);
      Serial.print(bool(income&8));
      Serial.print(bool(income&4));
      Serial.print(bool(income&2));
      Serial.println(bool(income&1));

      digitalWrite(2, bool(income&1));
      digitalWrite(3, bool(income&2));
      digitalWrite(4, bool(income&4));
      digitalWrite(5, bool(income&8));
      delay(100);
      digitalWrite(7, HIGH);
    }
  }
}

