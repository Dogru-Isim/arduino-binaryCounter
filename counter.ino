int LEDOne = 2; 	// this LED represents 1. digit	(2**0)
int LEDTwo = 3;		// this LED represents 2. digit (2**1)
int LEDThree = 4;	// this LED represents 3. digit	(2**2)
int LEDFour = 5;	// this LED represents 4. digit (2**3)

int number = 1;		//  
int remainder;

bool pin5;
bool pin4;
bool pin3;
bool pin2;

char x[4];

int place = 0;

int new_number = 2;

int counter = 0;
int zero_counter = 0;

void setup() {
  Serial.begin(5);
  
  pinMode(LEDOne, OUTPUT);
  pinMode(LEDTwo, OUTPUT);
  pinMode(LEDThree, OUTPUT);
  pinMode(LEDFour, OUTPUT);
}

void loop() {
  	while (true) {
      	remainder = number % 2;
      	number = number / 2;
      
  		if (remainder == 1) {
			x[place] = 1;
            place++;
    	}
      	if (remainder == 0) {
			x[place] = 0;
            place++;
        }
      
      	counter++;
      	
      	if (counter == 4) {
        	break;
      	}
    }

  
	pin5 = x[0];
  	pin4 = x[1];
  	pin3 = x[2];
  	pin2 = x[3];
  	
  	delay(1000);
  
  	if (pin5) {
  		digitalWrite(LEDOne, HIGH);
    }
  	else {
  		digitalWrite(LEDOne, LOW);
    }
//=====================================
  	if (pin4) {
  		digitalWrite(LEDTwo, HIGH);
    }
  	else {
  		digitalWrite(LEDTwo, LOW);
    }
//====================================
  	if (pin3) {
  		digitalWrite(LEDThree, HIGH);
    }
  	else {
  		digitalWrite(LEDThree, LOW);
    }
//====================================
  	if (pin2) {
  		digitalWrite(LEDFour, HIGH);
    }
  	else {
  		digitalWrite(LEDFour, LOW);
    }
//====================================
  	delay(500);
	number = new_number;
  
  	new_number++;
  	counter = 0;
  	place = 0;
}
