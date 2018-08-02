#include <Console.h>
#include <Serial.h>

int b;
int p = 36;

void setup() {
	pinMode(p, OUTPUT);
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
		} else {
			digitalWrite(p, HIGH);
			delay(500);
			digitalWrite(p, LOW);
		}
	}
}
