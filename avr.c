#include <Console.h>
#include <Serial.h>

int b;

void setup() {
	Bridge.begin();
	Console.begin();
	while(!Console);
	Serial.begin();
}

void loop() {
	if(Console.available() > 0) {
		b = Console.read();
		Serial.write(b);
	}
}
