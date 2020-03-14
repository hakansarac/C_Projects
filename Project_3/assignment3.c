#include <stdio.h>


int main(){
	
	int i=0,j=0,a=0,b=0,size=0,cars=0,park[50][50]={{0}};
	int x=0,y=0,result_x=0,result_y=0;
	
	
	
	printf("Size: ");
	scanf("%d",&size);
	while(size>50 || size<1){                               //it works until size between 1-50
		printf("Size must be between 50 and 1");
		printf("Size: ");
		scanf("%d",&size);
	}
	printf("Cars: ");
	scanf("%d",&cars);
	
	int distance=0;											//distance from nearest car
	int distance_every_one=size+size;						//to calculate distance between every slot and cars. 
	
	if(cars>=size*size){
		printf("Best Slot Found In: 0 0\n");
		return 0;
	}
	if(cars==0){
		printf("Best Slot Found In: 1 1\n");
		return 0;
	}
	for(i=0 ; i<cars ; i++){
		printf("Locations: ");
		scanf("%d %d",&a,&b);
		
			
		park[a-1][b-1]=1;
		
		    
	}
	
	/*manhattan distance: x(a,b) with y(c,d)
	abs(a-c) + abs(b-d)
	*/
	
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			for(a=0;a<size;a++){
		
				for(b=0;b<size;b++){
			
					if(park[i][j]!=park[a][b]){                   //to calculate slot and parked areas 
				
						x=i-a;
						y=j-b;
						if(x<0){
							x*=-1;
						}
						if(y<0){
							y*=-1;
						}											//(i-a) + (j-b) = distance
						if(distance_every_one>x+y){                //to calculate nearest car distance
							distance_every_one = x+y;
						}
					}
			
				}
			}
		    if(distance<distance_every_one && park[i][j]==0){     //if last calculated distance is more than before one,    
		    	distance=distance_every_one;					  //last calculated distance will be new distance	
		    	result_x=i+1;
		    	result_y=j+1;
			}
			distance_every_one=size+size;
		
		}
	}
	
	printf("Best Slot Found In: %d %d\n",result_x,result_y);
	
	return 0;
}

