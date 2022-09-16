


#include <stdio.h>
#include <stdlib.h>

//states
#define ON 1
#define OFF 0


void set_tlcolor(char color,int* speed,int* roomTemp,char* acstate,int* engTemp,char* etcs_state){
	if (color == 'G' || color == 'g'){
		*speed = 100;
	}else if (color == 'O' || color == 'o'){
		*speed = 30;
		*acstate = ON;
		*roomTemp = (*roomTemp)*(5/4)+1;
		*etcs_state = ON;
		*engTemp = (*engTemp)*(5/4)+1;
	}else if (color == 'R' || color == 'r'){
		*speed = 0;
	}
}



void set_room_temp(int* temp,char* state){
	if(*temp<10){
		*state = ON;
		*temp = 20;
	}else if(*temp >30){
		*state = ON;
		*temp = 20;
	}else{
		*state = OFF;
	}
}



void set_engine_temp(int* temp,char* state){
	if(*temp < 100){
		*state = ON;
		*temp = 125;
	}else if(*temp > 150){
		*state = ON;
		*temp = 125;
	}else{
		*state = OFF;
	}
}



void state_print(char engine_State,char AC_State,int vSpeed,int room_temp,char etcs,int engine_temp){

	engine_State == ON?printf("Engine is ON\n"):printf("Engine is OFF\n");
	AC_State == ON?printf("AC is ON\n"):printf("AC is OFF\n");
	printf("Vehicle speed: %d km/h \n",vSpeed);
	printf("Room Temperature: %d C\n",room_temp);
	etcs == OFF?printf("Engine Temperature controller is OFF\n"):printf("Engine Temperature controller is ON\n");
	printf("Engine Temperature: %d C\n\n",engine_temp);

}





int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char engineState = OFF;
	char acState = OFF;
	char tlColor = 'G';
	char etcs = OFF;
	int v_speed = 100;
	int roomTemp = 25;
	int engineTemp = 100;
	char input;

while(1){
	//start menu
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	scanf(" %c",&input);

	if(input == 'c'){
		break;

	}else if(input == 'b'){
		printf("Turn off the vehicle engine\n\n");
		continue;

	}else if(input == 'a'){
		engineState = ON;
		while(1){
			//engine ON menu
			printf("a. Turn off the engine\n");
			printf("b. Set the traffic light color\n");
			printf("c. Set the room temperature (Temperature Sensor)\n");
			printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
			scanf(" %c",&input);

			if(input == 'a'){
				break;

			}else if(input == 'b'){
				printf("Enter the required color:\n");
				scanf(" %c",&tlColor);

				// changing vehicle parameters according to input
				set_tlcolor(tlColor,&v_speed,&roomTemp,&acState,&engineTemp,&etcs);

				// printing the state of the vehicle before returning to engine ON menu
				state_print(engineState,acState,v_speed,roomTemp,etcs,engineTemp);
				continue;

			}else if(input == 'c'){
				printf("Enter the required room temperature: \n");
				scanf("%d",&roomTemp);

				// changing room temperature and AC state according to input
				set_room_temp(&roomTemp,&acState);

				// printing the state of the vehicle before returning to engine ON menu
				state_print(engineState,acState,v_speed,roomTemp,etcs,engineTemp);
				continue;

			}else if(input == 'd'){
				printf("Enter the required engine temperature:\n");
				scanf("%d",&engineTemp);

				// changing engine temperature and ETCS according to input
				set_engine_temp(&engineTemp,&etcs);

				// printing the state of the vehicle before returning to engine ON menu
				state_print(engineState,acState,v_speed,roomTemp,etcs,engineTemp);
				continue;

			}


		}

	}

}



	return 0;
}
