/*
	MrRedBeard 
	Seems to work not compleltly tested and written in about 30 minutes
*/
int cols = 27;
String letterArr[27] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"," " };
String morseArr[27] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."," " };

int led = 13; //Pin the led is hooked to
String msg = "";
int msgLen = 0;


void setup() 
{
  pinMode(led, OUTPUT); //Set pin to output
}

// the loop function runs over and over again forever
void loop() 
{
  
  msg = "Blink blink blink blink"; //Text you want converted to morsecode
  
  chartolight(); //Call to function that makes the conversion
}

void chartolight()
{
  
  msgLen = msg.length(); //Get length of message

  int i = 0;

  while( i <= msgLen)
  {
    //msg.charAt(i)
    for (int x = 0; x < cols; x++) 
    {
      if(String(msg.charAt(i)) == letterArr[x]) //Get morse val of char
      {
        char mors[50];
        morseArr[x].toCharArray(mors, 50);
        for (int y = 0; y < sizeof(mors); y++) //Get times for morse val
        {
          if(mors[y] == '.') //Short light
          {
            digitalWrite(led, HIGH);
            delay(350);
            digitalWrite(led, LOW);
            delay(200);
          }
          if(mors[y] == '-') //Long light
          {
            digitalWrite(led, HIGH);
            delay(650);
            digitalWrite(led, LOW);
            delay(200);
          }
          if(mors[y] == ' ') //Spaces
          {
            digitalWrite(led, LOW);
            delay(400);
          }
        }
        
      }
      
    }

    
    i++;
  }

}

