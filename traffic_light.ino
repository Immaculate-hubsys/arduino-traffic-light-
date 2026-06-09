
// ─────────────────────────────────────
// PROJECT:   Arduino Traffic Light
// AUTHOR:    immaculate_hubsys
// DATE:      June 2026
// VERSION:   1.0
// PLATFORM:  Arduino Uno
// SIMULATOR: Wokwi
//
// DESCRIPTION:
// Non-blocking traffic light using millis()
// and state machine pattern.
// STOP → READY → PASS → READY → STOP
// ─────────────────────────────────────


int red = 12;
int org = 7;
int grn = 3;

int rt = 3000;
int ot = 1500;


enum state {redstate, orgstate, grnstate, org_redstate};
state currentstate = redstate;

unsigned long lastchange = 0;

void trafficlight(int time, int off, int on, int offf, state presentstate, char colour[]){
if(millis()-lastchange >= time) {
  digitalWrite(red, off);
  digitalWrite(org, on);
  digitalWrite(grn, offf);
  currentstate = presentstate;
  lastchange = millis();
  Serial.println(colour);
}
}





void setup() {
  pinMode(red, OUTPUT);
  pinMode(org, OUTPUT);
  pinMode(grn, OUTPUT);
  Serial.begin(9600);
  digitalWrite(red, HIGH);
  lastchange=millis();
  Serial.println("STOP");
  // put your setup code here, to run once:

}

void loop() {
  switch(currentstate){
    case redstate:
    trafficlight(rt, LOW, HIGH, LOW, orgstate, "READY");
    break;

    case orgstate:
    trafficlight(ot,LOW, LOW, HIGH, grnstate, "PASS" );
    break;

    case grnstate:
    trafficlight(rt, LOW, HIGH, LOW, org_redstate, "READY");
    break;


    case org_redstate:
    trafficlight(ot,HIGH, LOW, LOW, redstate, "STOP");
    break;
  }


  // put your main code here, to run repeatedly:

}
