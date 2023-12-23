#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

double num(char str[]){
    double ans = 0;
    for (int i=0;i<strlen(str);i++){
        ans = ans*10 + (str[i]-'0');
    }
    
    return ans;
}

int main(){
    
    /******************taking input********************/
    char expr[1000];
    int i;
    scanf("%s", expr);
    
    char expression[1000][1000];
    int j = 0;
    char temp[1000] = "";
    
    for(int i=0;i<strlen(expr);i++){
        if(expr[i] == ','){
            strcpy(expression[j++],temp);
            strcpy(temp, "");
        } else {
            strncat(temp, &expr[i], 1);
        }
    }
    strcpy(expression[j++],temp);
    
    
    /*************************Solution**************************/
    
    double stack[100];
    int top = -1;
    
    for(i=j-1;i>=0;i--){
        if((expression[i][0]-'0') <= 9 && (expression[i][0]-'0') >= 0){
            top += 1;
            stack[top] = num(expression[i]);
        } else {
            double a = stack[top];
            top = top-1;
            double b = stack[top];
            top = top-1;
            
            char operate = expression[i][0];
            
            top += 1;
            if(operate == '+'){
                stack[top] = (a+b);
            } else if (operate == '-'){
                stack[top] = (b-a);
            } else if (operate == '*'){
                stack[top] = (a*b);
            } else if (operate == '/'){
                stack[top] = (b*1.0/a);
            }
        }
    }
    
    printf("\n\n");
    
    float res = stack[top];
    printf("Result = %f", res);
 
    return 0;
}