/* Author.. Karan Tank
   28069_LCD_.h
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_Cursor_ON(void);							  // Make Cursor visible
void LCD_Cursor_OFF(void);							  // Hide cursor
void Display_LCD(char LineNumber,char *Data);	  // Display the given message
void WriteCommand(unsigned char CommandByte);  // Write the given command
void WriteData(unsigned char DataByte);		  // Write the given data
void Initialize(void);						  // Initialize LCD

#endif


