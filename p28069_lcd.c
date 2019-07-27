// LCD Interface - 8 bit mode

// LCD Connections

// D0 -> GPIO5
// D1 -> GPIO6
// D2 -> GPIO7
// D3 -> GPIO12
// D4 -> GPIO16
// D5 -> GPIO17
// D6 -> GPIO18
// D7 -> GPIO19
//
// RS -> GPIO32
// RW -> GND
// E  -> GPIO33


#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

#include "p28069_lcd.h"

void WriteCommand(unsigned char CommandByte);
void WriteData(unsigned char DataByte);
void LCDDelay(void);
void LCDDelay1600(void);
void SendByte(unsigned char Value);

// Initialize LCD
void Initialize(void)
{
	int i = 0;
    //Set Enable pin High
    GpioDataRegs.GPBSET.bit.GPIO33 = 1;
    for(i=0;i<4;i++)
    {
        LCDDelay1600();
    }

	WriteCommand(0x38);			//Command to select 8 bit interface
	LCDDelay1600();

	WriteCommand(0x38);			//Command to select 8 bit interface
	LCDDelay();				        //Small delay

	WriteCommand(0x38);			//Command to select 8 bit interface
	LCDDelay();


	WriteCommand(0x08);			//Command to off cursor,display off
	WriteCommand(0x01);			//Command to Clear LCD
	LCDDelay1600();
	WriteCommand(0x06);			//Command for setting entry mode

	WriteCommand(0x0f);			//Command to on cursor,blink cursor
	WriteCommand(0x02);			//Command return the cursor to home
	LCDDelay1600();

}


// Function to write a command to the LCD
void WriteCommand(unsigned char CommandByte)
{
     //Clear RS pin to write command
    GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;
    SendByte(CommandByte);
	LCDDelay();				        //Small delay
}


// Send Databyte to the LCD
void SendByte(unsigned char Value)
{
	unsigned char var;

	if((Value & 0x01) == 0x01)
		  //Set D0 High;
	    GpioDataRegs.GPASET.bit.GPIO5 = 1;
	    else
		  //Set D0 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;

	if((Value & 0x02) == 0x02)
	    //Set D1 High;
        GpioDataRegs.GPASET.bit.GPIO6 = 1;
	else
        //Set D1 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;

	if((Value & 0x04) == 0x04)
	    //Set D2 High;
	    GpioDataRegs.GPASET.bit.GPIO7 = 1;
	else
        //Set D2 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;

	if((Value & 0x08) == 0x08)
	    //Set D3 High;
	    GpioDataRegs.GPASET.bit.GPIO12 = 1;
	else
        //Set D3 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;

	if((Value & 0x10) == 0x10)
	    //Set D4 High;
	    GpioDataRegs.GPASET.bit.GPIO16 = 1;
	else
        //Set D4 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO16 = 1;

	if((Value & 0x20) == 0x20)
	    //Set D5 High;
	    GpioDataRegs.GPASET.bit.GPIO17 = 1;
	else
        //Set D5 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO17 = 1;

	if((Value & 0x40) == 0x40)
	    //Set D6 High;
	    GpioDataRegs.GPASET.bit.GPIO18 = 1;
	else
        //Set D6 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO18 = 1;

	if((Value & 0x80) == 0x80)
	    //Set D7 High;
	    GpioDataRegs.GPASET.bit.GPIO19 = 1;
	else
        //Set D7 Low;
	    GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;


//Set E pin to select LCD
	 GpioDataRegs.GPBSET.bit.GPIO33 = 1;
	
	for(var=0;var<5; var++);
//Clear E pin to deselect LCD
	GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;
	LCDDelay();				            //Small delay

}

//Write a data byte to LCD
void WriteData(unsigned char DataByte)
{
//Set RS pin to write data
    GpioDataRegs.GPBSET.bit.GPIO32 = 1;
	SendByte(DataByte);
	LCDDelay();				            //Small delay
}


// Small delay
void LCDDelay(void)
{
	DELAY_US(50);
}

// Big delay
void LCDDelay1600(void)
{
	DELAY_US(1600);
}


//Show
void LCD_Cursor_ON(void)
{
	WriteCommand(0x0f);			//Command to switch on cursor
}



//Hide cursor
void LCD_Cursor_OFF(void)
{
	WriteCommand(0x0c);			//Command to switch off cursor
}


// Displays data
void Display_LCD(char LineNumber,char *Data)
{
    int a ,c = 0;
	if(LineNumber ==1)
	{	//First Line
		WriteCommand(0x80);		//Select the first line
	}
	else if(LineNumber ==2)
	{	//Second line
		WriteCommand(0xc0);		//Select the second line
	}
	else if(LineNumber ==3)
	    {   //third line
	        WriteCommand(0x94);      //Select the third line
	    }
	else if(LineNumber ==4)
	        {   //fourth line
	            WriteCommand(0xD4);      //Select the fourth line
	        }
	while(*Data != '\0')
	{c++;
	}


	for(a=0;a<=c;a++)               //Value of a can be incremented if there are more characters to display on lcd
	{
		WriteData(*Data);		//Display a character
		Data++;                  //Increment pointer
	}
	for(a=c+1;a<=20;a++)
	{
	    WriteData(' ');
	}

	return;
}
