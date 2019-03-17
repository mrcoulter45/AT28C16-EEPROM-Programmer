#define A0 9
#define A1 8
#define A2 7
#define A3 6
#define A4 5
#define A5 4
#define A6 3
#define A7 2
#define OE 11
#define WE 10

#define D0 13
#define D1 12
#define D2 14
#define D3 15
#define D4 16
#define D5 17
#define D6 18
#define D7 19

void setup() {
    Serial.begin(9600);
    pinMode(WE, OUTPUT);
    pinMode(OE, OUTPUT);
    
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A6, OUTPUT);
    pinMode(A7, OUTPUT);
    
    pinMode(D0, INPUT);
    pinMode(D1, INPUT);
    pinMode(D2, INPUT);
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
    pinMode(D5, INPUT);
    pinMode(D6, INPUT);
    pinMode(D7, INPUT);
    
    digitalWrite(WE, 1);
    digitalWrite(OE, 0);
    digitalWrite(A0, 0);
    digitalWrite(A1, 0);
    digitalWrite(A2, 0);
    digitalWrite(A3, 0);
    digitalWrite(A4, 0);
    digitalWrite(A5, 0);
    digitalWrite(A6, 0);
    digitalWrite(A7, 0);
    
    Serial.println("Read or write?");
}
void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readString();
        if(input == "read"){
            Serial.println("Enter address to read");
            while(1){
                if (Serial.available() > 0) {
                    String address = Serial.readString();
                    Serial.println("Reading address " + address);
                    int addr = address.toInt();
                    digitalWrite(WE, 1);
                    digitalWrite(OE, 0);
                    digitalWrite(A0, (addr & 0x01));
                    digitalWrite(A1, (addr & 0x02) >> 1);
                    digitalWrite(A2, (addr & 0x04) >> 2);
                    digitalWrite(A3, (addr & 0x08) >> 3);
                    digitalWrite(A4, (addr & 0x10) >> 4);
                    digitalWrite(A5, (addr & 0x20) >> 5);
                    digitalWrite(A6, (addr & 0x40) >> 6);
                    digitalWrite(A7, (addr & 0x80) >> 7);
                    Serial.println("Read or write?");
                    break;
                }
            }
        }
        else if(input == "write"){
            Serial.println("Enter address to write");
            while(1){
                if (Serial.available() > 0) {
                    String address = Serial.readString();
                    Serial.println("Writing address " + address);
                    int addr = address.toInt();
                    digitalWrite(WE, 1);
                    digitalWrite(OE, 0);
                    digitalWrite(A0, (addr & 0x01));
                    digitalWrite(A1, (addr & 0x02) >> 1);
                    digitalWrite(A2, (addr & 0x04) >> 2);
                    digitalWrite(A3, (addr & 0x08) >> 3);
                    digitalWrite(A4, (addr & 0x10) >> 4);
                    digitalWrite(A5, (addr & 0x20) >> 5);
                    digitalWrite(A6, (addr & 0x40) >> 6);
                    digitalWrite(A7, (addr & 0x80) >> 7);
                    break;
                }
            }
            Serial.println("Enter data to write");
            while(1){
                if (Serial.available() > 0) {
                    String data = Serial.readString();
                    Serial.println("Writing data " + data);
                    int d = data.toInt();
                    pinMode(D0, OUTPUT);
                    pinMode(D1, OUTPUT);
                    pinMode(D2, OUTPUT);
                    pinMode(D3, OUTPUT);
                    pinMode(D4, OUTPUT);
                    pinMode(D5, OUTPUT);
                    pinMode(D6, OUTPUT);
                    pinMode(D7, OUTPUT);
                    digitalWrite(D0, (d & 0x01));
                    digitalWrite(D1, (d & 0x02) >> 1);
                    digitalWrite(D2, (d & 0x04) >> 2);
                    digitalWrite(D3, (d & 0x08) >> 3);
                    digitalWrite(D4, (d & 0x10) >> 4);
                    digitalWrite(D5, (d & 0x20) >> 5);
                    digitalWrite(D6, (d & 0x40) >> 6);
                    digitalWrite(D7, (d & 0x80) >> 7);
                    digitalWrite(WE, 0);
                    digitalWrite(OE, 1);
                    delay(0.0001);
                    digitalWrite(WE, 1);
                    digitalWrite(OE, 0);
                    pinMode(D0, INPUT);
                    pinMode(D1, INPUT);
                    pinMode(D2, INPUT);
                    pinMode(D3, INPUT);
                    pinMode(D4, INPUT);
                    pinMode(D5, INPUT);
                    pinMode(D6, INPUT);
                    pinMode(D7, INPUT);
                    Serial.println("Read or write?");
                    break;
                }
            }
        }
        else{
            Serial.println("I swear the simplest things...");
            delay(2000);
            Serial.println("...");
            delay(2000);
            Serial.println("...");
            delay(2000);
            Serial.println("Let's try this again...");
            delay(2000);
            Serial.println("Read or write?");
        }
    }
}
