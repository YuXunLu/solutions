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
unsigned char step[MAX_STATE] = {0};
unsigned long int BIT_OPR[16] = {0};
bool isBlack(unsigned long int state, unsigned char bit_flag)
{
	bool res = false;
	if (state & BIT_OPR[bit_flag] == 1) //black
		res = true;
	else //white
		res = false;
	return res;	
}
unsigned long int changeState(unsigned long int state, unsigned char bit_flag)
{
	unsigned long int res = state;
	if (isBlack(state, bit_flag) )
	{
		res = res ^ BIT_OPR[bit_flag];
	}
	else
	{
		res = res | BIT_OPR[bit_flag];
	}
	return res;
}
int bit_search(unsigned long int init){
//black is 1 and white is 0.
	long int ans = -1;
	unsigned long int now = init;
	unsigned long int state_queue[MAX_STATE] = {0};
	unsigned int ind = 0, tail = 0;

	state_queue[ind % MAX_STATE] = init;
	state[init] = 1;
	ind++;
	while ((ind % MAX_STATE) != (tail % MAX_STATE) ) {
		now = state_queue[tail % MAX_STATE];
		if (now == 0 || now == 65535){
//			printf("Found %lu, at step %d\n", now, step[now]);
			ans = step[now];
			return ans + 1;
		}
		tail++;
		for(int i = 0; i < 16; i++)	{
			unsigned long int new_state = 0;
			//expand state for 16 points
			new_state = changeState(now, i);
			if ( i - 1 >= (i / 4) * 4 )	//left
			{
				new_state = changeState(new_state, i - 1);
			}
			if ( i + 1 < (i / 4 + 1) * 4) //right
			{
				new_state = changeState(new_state, i + 1);
			}
			if ( ((((i / 4) - 1) * 4) + i % 4) >= 0) // up
			{
				new_state = changeState(new_state, (i / 4 - 1) * 4 + i % 4 );
			}
			if ( ((((i / 4) + 1 ) * 4) + i % 4) < 16) //down
			{
				new_state = changeState(new_state, (i / 4 + 1 ) * 4 + i % 4);
			}
			if (state[new_state] != 1) //never expanded before
			{
				step[new_state] = step[now] + 1;
				state_queue[ind % MAX_STATE] = new_state;
				state[new_state] = 1;
				ind++;
			}
		}
	}
	return ans;
}
int main(){
	for(int i = 0; i < 16; i++){
		BIT_OPR[i] = 1 << (15 - i);
	}
	char current_state_input[4] = {0};
	unsigned long int current_state = 0;
	for (int i = 0; i < 4; i++){
		scanf("%s\n",current_state_input);
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
