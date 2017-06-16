void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

  while(!Serial){
    
  }
  delay(100);

  
      pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(50);
  digitalWrite(2, HIGH);
  delay(100);  
  digitalWrite(2, LOW);
  
  Serial.println("WELCOME");
  delay(200);
}


void ignitionProcedure(){
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
  }

String demoData = "0,0;\n100,500;\n200,600;\n300:1200;\n400,1500;\n500,2300;\n600,5000;\n700,1000;\n800,100;\n900,100;\n1000,0;\n";

String cmd;
void loop() {
  cmd = "";
  if(Serial.available() > 0){
    
  while(Serial.available() > 0){
      cmd += String(char(Serial.read()));      
      delay(1);
  }
  }

    if(cmd!=""){
      delay(50);
      // switch??
      if(cmd=="REURDY"){
          Serial.println("YES");
       }else if(cmd=="DATAPLS"){
          delay(1);
          Serial.print(demoData);
          Serial.flush();
       }else if(cmd=="IGNPRCDR"){
          delay(1);
          ignitionProcedure();
       }else{
        Serial.println("IGETTHAT:"+cmd);
        }
        
    }
  // put your main code here, to run repeatedly:

}
