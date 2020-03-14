#include <stdio.h>


int main(){


    int coun=0, year=0, year_end=0, years_middle=0, j=0, k=0, m=0, q=0,day_answer=0;


    printf("Enter date [year, month, day]: ");
    scanf("%d%d%d",&year,&m,&q);

    if( (m == 2 && q>28) || ( (m == 2 || m==4 || m==6 || m == 9 || m==11 ) && q > 30 ) || q > 31) {
    
        printf("Invalid date!");
        return 1;
    }     

    printf("Enter end year :");
    scanf("%d",&year_end);


    j=year/100;
    k=year%100;

    if(m==1 || m==2){
        
        m+=12;
        k--;
    }

    day_answer = (q + (13*(m+1)/5) + k + k/4 + j/4 + 5*j) % 7; 

    switch(day_answer){

        case 0: printf("It is a Saturday.\n");
                break;
        case 1: printf("It is a Sunday.\n");
                break;
        case 2: printf("It is a Monday.\n");
                break;
        case 3: printf("It is a Tuesday.\n");
                break;
        case 4: printf("It is a Wednesday.\n");
                break;
        case 5: printf("It is a Thursday.\n");
                break;
        case 6: printf("It is a Friday.\n");
                break;
        default: break;   
    }
   

    for(years_middle = year ; years_middle <= year_end ; years_middle++) {

        j = years_middle / 100;
        k = years_middle % 100;
        
        if(m==1 || m==2){
        	
        	k--;        	
		}
        if(((q + (13*(m+1)/5) + k + k/4 + j/4 + 5*j) % 7) == day_answer) {
        
            coun++;
        }        
    }
    
    printf("Same day-and-month on same weekday between %d - %d : %d.", year, year_end, coun);

return 0;
}
