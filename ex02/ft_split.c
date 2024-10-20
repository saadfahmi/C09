#include <stdlib.h>


int check_separator(char c, char *charset) {
    int i = 0;
    while (charset[i] != '\0') {
        if (c == charset[i])
            return 1;
        i++;
    }
    return 0;
}


int count_strings(char *str, char *charset) {
    int i = 0;
    int count = 0;
    
    while (str[i] != '\0') {
        
        while (str[i] != '\0' && check_separator(str[i], charset))
            i++;
        
       
        if (str[i] != '\0') {
            count++;
           
            while (str[i] != '\0' && !check_separator(str[i], charset))
                i++;
        }
    }
    
    return count;
}


int ft_strlen_sep(char *str, char *charset) {
    int i = 0;
   
    while (str[i] != '\0' && !check_separator(str[i], charset))
        i++;
    return i;
}


char *ft_word(char *str, char *charset) {
    int len_word = ft_strlen_sep(str, charset);  
    char *word = (char *)malloc(sizeof(char) * (len_word + 1));  
    
    int i = 0;
    while (i < len_word) {
        word[i] = str[i];  
        i++;
    }
    word[i] = '\0'; 
    return word;
}


char **ft_split(char *str, char *charset) {
    char **strings;
    int i = 0;
    
    
    strings = (char **)malloc(sizeof(char *) * (count_strings(str, charset) + 1));
    
    while (*str != '\0') {
      
        while (*str != '\0' && check_separator(*str, charset))
            str++;
        
      
        if (*str != '\0') {
            
            strings[i] = ft_word(str, charset);
            i++;
            
            while (*str != '\0' && !check_separator(*str, charset))
                str++;
        }
    }
    
    strings[i] = NULL;  
    return strings;
}
// Hf//
