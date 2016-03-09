#include <stdio.h>
#include <string.h>

void reverse_mem_block(char* s, char* e) {
  char tmp;
  
  while (s < e) {
    tmp = *s; //store the beginning
    *s++ = *e; //set beginning to end, inc start
    *e-- = tmp; //set end to beginning, dec end
  }
}

void reverse_words(char* sentence) {
    //reverse string
    //reverse each word afterwards
    
    int length = strlen(sentence);
    char* end = sentence+length-1;
    while ((*end == ' ') && (end > sentence))
        end--; //get rid of trailing whitespace

    reverse_mem_block(sentence, end); //leaves null at end in correct place
    //at this point we have a reversed the entire sentence
    
    char *s = sentence;
    while (*s) { //while it doesn't point to nul

        //scan to the beginning of the word
        while ((*s == ' ') && (*s != '\0'))
            s++; //moves past spaces (including multiple)
        
        if (*s == '\0') 
            break;
            
        char *e = s;
        //scan to the end of the word
        while ((*e != ' ') && (*e != '\0')) 
            e++;
        
        reverse_mem_block(s,e-1); //reverse word we've found
        s = e; //set up the next word
    }
}

int main() {
    char test[]= "Now is the winter of our discontent made glorious summer by this son of York";
    reverse_words(test);
    printf("%s\n", test);
}
