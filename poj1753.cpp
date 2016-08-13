#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <cstring>
using namespace std;
/*
	solution: bit-compress + prone; Each state needs 16bit to store.
	The state which has been expanded before shall be stored in a hash table.
	If all state has been expanded, then no solution.
*/
const unsigned long int MAX_STATE = 0b1111111111111111;
unsigned char state[MAX_STATE] = {0};
const unsigned long int BIT_OPR[16] = {0};
int bit_search(unsigned long int init){
//black is 1 and white is 0.
	long int ans = -1;
	unsigned long int now = init;
	unsigned long int state_queue[MAX_STATE] = {0};
	unsigned int ind = 0;
	state[init] = 1;
	if ( now == 0 || now == 65535 ){
		ans = 0;
		return ans;
	}
	else{
		state_queue[ind] = init;
		ind++;
	}
	now = state_queue[ind - 1];
	while ( now != 0 && now != 65535){
		for(int i = 0; i < 16; i++)	{
			unsigned long int new_state = 0;
			//state expands for 16 different points.
			if ( now & BIT_OPR[i] != 0 ){
				//current point is black

			}
			else{
				//current point is white
			}
			state_queue[ind] = new_state;
			ind = ind++;
		}

	}
	return ans;
}
int main(){
//init bit opr
	for(int i = 0; i < 16; i++){
		BIT_OPR[i] = 1 << i;
	}
//	printf("%d". MAX_STATE);
	char current_state_input[4] = {0};
	unsigned long int current_state = 0;
	for (int i = 0; i < 4; i++){
		scanf("%s\n",current_state_input);
//		printf("str len %ld\n", strlen(current_state_input));
		for (int j = 0; j < strlen(current_state_input); j++){
			if (current_state_input[j] == 'b' ){
				current_state = current_state | 1;
			}
			current_state = current_state << 1;
		}
	}
	current_state = current_state >> 1;
	long int ans = bit_search(current_state);
	if ( ans == -1){
		printf("Impossible\n");
	}
	else{
		printf("%ld\n", ans);
	}
}
