#include <Console.h>
#include <Serial.h>

int b;
int p = 36;
int rst = 35;
int l = 13;

void setup() {
	pinMode(p, OUTPUT);
	pinMode(rst, OUTPUT);
	pinMode(l, OUTPUT);
	Bridge.begin();
	Console.begin();
	while(!Console);
	Serial.begin();
}

void loop() {
	if(Console.available() > 0) {
		b = Console.read();
		if b != "o" {
			Serial.write(b);
			int r = Serial.read();
			if r != "ok" {
				digitalWrite(l, HIGH);
				delay(5000);
				digitalWrite(l, LOW);
				digitalWrite(rst, HIGH);
			}
		} else {
			digitalWrite(p, HIGH);
			delay(500);
			digitalWrite(p, LOW);
		}
	}
}
