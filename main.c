#include <16F877A.h>
#device adc=10

#FUSES XT                       
#byte PORTB=0x06
#byte PORTC=0x07
#use delay(clock=4000000)

int16 x=0;

void main()
{

   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   set_tris_b(0);
   set_tris_c(0xff);

   while(true){
  
  
   x=read_adc();
   PORTB=x;
   
   if(x<PORTC){
   PORTB=0xff;
   }else{
   PORTB=0;
   }
   
   
   }

}
