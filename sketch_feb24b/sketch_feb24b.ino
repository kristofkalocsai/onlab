#include <EthernetUdp.h>
#include <EthernetClient.h>
#include <Ethernet.h>
#include <EthernetServer.h>

byte mac[] = { 0x00, 0x1A, 0xB6, 0x02, 0xC1, 0x38 };

//just temporarily
IPAddress thinkpad(152,66,157,101);
unsigned int tpPort = 5005;
unsigned int localPort = 2000;

EthernetUDP UDP;

#define LED1 D1_LED
#define LED2 D2_LED
#define LED3 D3_LED
#define LED4 D4_LED
#define SW1 USR_SW1
#define SW2 USR_SW2

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  
  //start serial
  Serial.begin(9600);
  
  //start ethernet
  Serial.print("starting ethernet: ");
  if (Ethernet.begin(mac) == 0){
    
    Serial.println("fail");
    for(;;){
      if (Ethernet.begin(mac) == 1){
        break;
      }
    };
  }
  Serial.println("success");
  Serial.println("my ip: ");
  Serial.println(Ethernet.localIP());
  
  //start udp
  Serial.print("starting udp: ");
  if (UDP.begin(localPort) == 0){
    
    Serial.println("fail");
    for(;;){
      if (UDP.begin(localPort) == 1){
        break;
      }
    };
  }
  Serial.println("success");
  
}

void loop()
{
  
  // put your main code here, to run repeatedly:
  
}
