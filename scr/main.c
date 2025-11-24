#include <LPC213X.H>
void msdelay(unsigned int time)
{
 unsigned int i, j;
 for(i=0;i<time;i++)
  {
  for(j=0;j<3000;j++);
  }
}
//
void lcd_data(char data)
{
  IOPIN1 = (data<<16);
  IOPIN1 |= (5<<24);
  msdelay(1);
  IOPIN1 &= ~(1<<26);
}
//
void lcd_cmd(unsigned char cmd)
{
  IOPIN1 = (cmd<<16);
  IOPIN1 |= (4<<24);
  msdelay(1);
  IOPIN1 &= ~(1<<26);
}
//
void lcd_init()
{
  lcd_cmd(0x38);
  lcd_cmd(0x0C);
  lcd_cmd(0x80);
}
//
unsigned int adc_read()
{
  unsigned int val;
  AD1CR = (1<<2) //CHANNEL NO.
        | (2<<8) //CLKDIV BY 3
        | (1<<21) //PDN ..TURN ON ADC
        | (0<<17) //10-BIT RESOLUTION
        | (1<<24); //start conversion
  while(!(AD1DR & 0x80000000));
  val=AD1GDR;
  val=(val >> 6) & 0x03FF;
  return val;
}
//
void backspace()
{
  lcd_cmd(0x10);
  msdelay(1);
}
//
int main()
{
  unsigned int i,r=0;
  unsigned char a[]="Temprature:";
  unsigned char b=' ';
  unsigned int adc_out;
  char buffer[50];
  
   IODIR1 =0xffffffff;
   IODIR0 =(0x0F<<18);
   PINSEL0 = 0x00300000;// as AD1.2
  
   lcd_init();

  for(i=0;a[i]!='\0';i++)
  {
  lcd_data(a[i]);
  }
   while(1)
  {

    adc_out = adc_read();
    adc_out = (adc_out/3);
    
  if(adc_out>20)
    adc_out = adc_out-1;
  if(adc_out>48)
    adc_out = adc_out-1;
  if(adc_out>75)
    adc_out = adc_out-1;
  if(adc_out>103)
    adc_out = adc_out-1;
  if(adc_out>131)
    adc_out = adc_out-1;
  if(adc_out >= 40)
    IOSET0 = (1<<18)|(1<<20);
  else
    IOCLR0 = (1<<18)|(1<<20);
    
  if(adc_out >= 60)
    IOSET0 = (3<<18)|(3<<20);
  else
    IOCLR0 = (1<<19)|(1<<21);
    
  if(r==0){
    r++;
  }
  else
  {
    for(i=0;i<5;i++)
    {
      backspace();
    }
  }
    
   buffer[0] = ((adc_out/100)%10)+48;
   buffer[1] = ((adc_out/10)%10)+48;
   buffer[2]= (adc_out%10)+48 ;
   buffer[3] = (223);
   buffer[4] = (67);
    
  for(i=0;i<5;i++)
  {
    lcd_data(buffer[i]);
  }
    msdelay(10);
    
  for(i=0;i<5;i++)
  {
    backspace();
  }
    
  for(i=0;i<5;i++)
  {
    lcd_data(b);
  }
  }
  return 0;
}
