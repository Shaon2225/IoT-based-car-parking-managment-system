#define parking_1_ir 2
#define parking_1_led 4

int cars = 1;           
bool parking_1 = true;
bool parking_count = true;


void setup() {
  Serial.begin(9600);       
  pinMode(parking_1_ir, INPUT);
  pinMode(parking_1_led, OUTPUT);
}

void countCars(){
  if(parking_count == true && parking_1 == true){
    cars--;
    }
  parking_count = false;
  Serial.println(cars);
  digitalWrite(parking_1_led,HIGH);
 // parking_1 = false;
}

void restoreCarsValue(){
  if(parking_count == false && parking_1 == false){
      cars++;
    }
  Serial.println(cars);
  parking_count=true;
  }

void loop() {
  //Serial.println('scan');
  if(digitalRead(parking_1_ir) == LOW){
    parking_1 = true;
    Serial.println(2225);
    countCars();
    }
   else{
    parking_1 =false;
    restoreCarsValue();
    digitalWrite(parking_1_led, LOW);
    }                
  delay(1000);
}
