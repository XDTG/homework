void dash();
void dot();
void morseToLed(String str);
String charToMorse(int ascii);
void cSpace();
void wSpace();

int dotTime = 250;
int pin = 7;

void dash(){
    digitalWrite(pin, HIGH);
    delay(dotTime*4);
    digitalWrite(pin, LOW);
    delay(dotTime);
}

void dot(){
    digitalWrite(pin, HIGH);
    delay(dotTime);
    digitalWrite(pin, LOW);
    delay(dotTime);
}

void cSpace(){
    digitalWrite(pin, LOW);
    delay(dotTime*3);
}

void wSpace(){
    digitalWrite(pin, LOW);
    delay(dotTime*7);
}

void morseToLed(String str){
    int n = str.length(), i;
    char c;

    for(i=0; i<n; i++){
        c = str[i];
        switch(c){
            case '*':
                dot();
                break;
            case '-':
                dash();
                break;
            case ' ':
                cSpace();
                break;
            case '/':
                wSpace();
                break;
            default:
                break;
        }
    }
    
}

String charToMorse(int ascii){
    Stirng m = "";
    String alphabet[27] = {
         "/",
        "*-",
        "-***",
        "-*-*",
        "-**",
        "*",
        "**-*",
        "--*",
        "****",
        "**",
        "*---",
        "-*-",
        "*-**",
        "--",
        "-*",
        "---",
        "*--*",
        "--*-",
        "*-*",
        "***",
        "-",
        "**-",
        "***-",
        "*--",
        "-**-",
        "-*--",
        "--**"
    };
    if(ascii==32){
        m = alphabet[0];
        return m;
    }else{
        m = alphabet[ascii-96];
        return m+" ";
    }
}

int incoming = 0;
String str = "";

void setup(){
    Serial.begin(9600);
}

void loop(){
    while(Serial.available()>0){
        incoming = Serial.read();
        str += charToMorse(char(incoming));
    }

    if(str.length()>0){
        Serial.println(str);
        Serial.println("Look at LED");
        delay(1000);
        morseToLed(str);
    }
    str = "";
}
