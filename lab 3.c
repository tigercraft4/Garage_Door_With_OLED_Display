#include <16F877A.h>
#fuses NOWDT,HS, NOPUT, NOPROTECT, NODEBUG, NOLVP, NOCPD, NOWRT, BROWNOUT
#device adc=10

#use delay(clock=20000000)
#use RS232(baud=9600,xmit=Pin_C6,rcv=Pin_C7,Parity=N,Bits=8)
//################inicio codigo do ecra###################
#use I2C(MASTER, I2C1, FAST = 100000, stream = SSD1306_STREAM)





//################fim codigo do ecra###################

#define RS     PIN_E0
#define ENABLE PIN_E1
//#define LSB PIN_A2

int16 paberto,pfechado,c,estado;

#INT_RDA
void Interrupcao(){
   c=getchar();
    
}

void verifica_portao(){
if(pfechado==0){
     set_pwm1_duty(512);
         }
if(paberto==0){set_pwm1_duty(512);}
      

}

int8 i = 0;

void main()
{
   int16 i,j=0;
  enable_interrupts ( INT_RDA ) ;
      enable_interrupts ( global ) ;
  


   set_tris_d(0x00);//diz que sao saidas
      setup_adc_ports(AN0);
      setup_adc(ADC_clock_internal);
      
      setup_ccp1(ccp_pwm);// ccp1 pin c2 pwm1
      setup_timer_2(t2_div_by_4,255,1);

  while (1)
   {
     
      delay_ms(100);
      set_adc_channel(0);
      delay_us(20);
      
     pfechado=input(Pin_C3);
     paberto=input(Pin_C4);
    
     
     
   // set_pwm1_duty(1); //8bits 0-255 10 bits 0-1023
   
     
      
//!     if(input(Pin_B4)==1){
//!      set_pwm1_duty(1);
//!     }
//!     if(input(Pin_B5)==1){
//!      set_pwm1_duty(1000);
//!     }
//!     
//!     if(input(Pin_B6)==1){
//!      set_pwm1_duty(512);
//!     }
     
          if(c=='1'){
      set_pwm1_duty(1);
       c='3';
     }
    
    // delay_us(1000);
    
     
     
     
      if(c=='0'){
      set_pwm1_duty(1000);
       c='3';
     }
       
      // delay_us(1000);
      
//!     if(input(Pin_B6)==1){
//!      set_pwm1_duty(512);
//!     }
     
     
     if(pfechado==0)
     {
     set_pwm1_duty(512);
      c='3';
     }
      if(paberto==0)
      {
       set_pwm1_duty(512);
        c='3';
      }
   // verifica_portao();
    
    
    
    //c=getchar();
    if(c=='1'){output_HIGH( PIN_B0 ) ;}
   if(c=='0'){output_LOW( PIN_B0 ) ;}
    


    
    //################Ecra##############
  
    
    
    
    
    
    
    
}










     }
    

   


