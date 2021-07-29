#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

int blueTx=2;// Bt의 Tx 와 연결 (보내는핀 설정)at
int blueRx=3;// Bt의 Rx 와 연결 (받는핀 설정)
SoftwareSerial BTSerial(2, 3);// 블루투스와 시리얼 통신을 위한 객체선언

void setup()
{
  Serial.begin(9600);// 시리얼모니터
  BTSerial.begin(9600);// 블루투스 시리얼
}
void loop()
{
  if (BTSerial.available()){
    Serial.write(BTSerial.read());// 블루투스측 내용을 시리얼모니터에 출력
  }
  if(Serial.available()){
    BTSerial.write(Serial.read());// 시리얼 모니터 내용을 블루투스 측에 WRITE
  }
}

