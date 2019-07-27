/* Author.. Karan Tank
   28069_LCD_.h
 */

#ifndef LCD_H_
#define LCD_H_

void CursorON(void);							  // Make Cursor visible
void CursorOFF(void);							  // Hide cursor
void DisplayLCD(char LineNumber,char *Data);	  // Display the given message
void WriteCommandLCD(unsigned char CommandByte);  // Write the given command
void WriteDataLCD(unsigned char DataByte);		  // Write the given data
void InitializeLCD(void);						  // Initialize LCD

#endif


