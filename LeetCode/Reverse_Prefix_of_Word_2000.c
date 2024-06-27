// https://leetcode.com/problems/reverse-prefix-of-word/description/
// 2000 - Reverse Prefix of Word

char* reversePrefix(char* word, char ch) {
    short int tam=strlen(word),i;
    
    for(i=0; i<tam; i++)
        if(word[i]==ch){
            char aux;
            for(short int j=0; j<i; j++, i--){
                aux=word[j];
                word[j]=word[i];
                word[i]=aux;
            }
            break;
        }
            
    return word;
        
}
