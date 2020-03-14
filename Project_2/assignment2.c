#include <stdio.h>
#define DOUBLE 2
#define TRIPLE 3
#define OUTBULL 25
#define INBULL 50

int throwa(int, char);         //calculates and returns the throw point
int rules(int, int, int, char);    //returns remaining point and start-end game


int main(){

int segment=0, current_point=0, target=0;       
char ring;

    printf("Target: ");
    scanf("%d",&target);
    printf("\n");
    
    current_point = target;

    while(current_point != 0){       //while loop works from target to 0 
        
        printf("Throw: ");
        scanf("%d %c",&segment,&ring);
        current_point = rules(target,current_point,segment,ring);
        printf("Points: %d\n", current_point);
    } //end of while                             
    
return 0;
}  //end of main



int throwa(int segment, char ring){              

	
    if( ring == 'S' ) {
    
        return segment;
    }

    else if( ring == 'D' ) {
 
        return segment * DOUBLE;

    }

    else if( ring == 'T' ) {

        return segment * TRIPLE;

    }

    else if( ring == 'O' ) {

        return segment * OUTBULL;

    }

    else if( ring == 'I' ) {

        return segment * INBULL;

    }
    return 0;
}  //end of throw


int rules(int target, int current_point, int segment, char ring){
    
    int next_point = 0;
    if(target == current_point && ring!='D'){ 

        return current_point;

    } //end of if. This condition for starting

    next_point = current_point - throwa(segment,ring);       //return throw value and calculate new point
    
    if(next_point == 1 || next_point < 0 || (next_point == 0 && ring != 'D')) {
  
        return current_point;

    } //end of if. This condition for ending

    else {

        return next_point;
    }


}  //end of rules
