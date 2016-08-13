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
		//change to white
		res = res ^ BIT_OPR[bit_flag];
	}
	else
	{
		//change to black
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
	state[init] = 1;
	if ( now == 0 || now == 65535 ){
		ans = 0;
		return ans;
	}
	else{
		state_queue[ind % MAX_STATE] = init;
		ind++;
	}
	while ((ind % MAX_STATE) != (tail % MAX_STATE) ) {
		now = state_queue[tail % MAX_STATE];
		state[now] = 1; //record the state
		if (now == 0 || now == 65535){
			ans = ind;
			break;
		}
		tail++;
		for(int i = 0; i < 16; i++)	{
			unsigned long int new_state = 0;
			//state expands for 16 different points.
				/* condition 1: 0 <= i < 4 -> Line 1
				   condition 2: 4 <= i < 8 -> Line 2
				   condition 3: 8 <= i < 12 -> Line 3
				   condition 4: 12 <= i < 16 -> Line 4
				   i = 0, 3, 12, 15 > corner
				   i = 4, 8  > left side
				   i = 7, 11 > right side
				*/
			new_state = changeState(now, i);
			if ( i - 1 > (i / 4) * 4 )	//left
				new_state = changeState(new_state, i - 1);
			if ( i + 1 <= (i / 4 + 1) * 4) //right
				new_state = changeState(new_state, i + 1);
			if ( (((i / 4) - 1 * 4) + i % 4) > 0) // up
				new_state = changeState(new_state, (i / 4 - 1) * 4 + i % 4 );
			if ( (((i / 4) + 1 * 4) + i % 4) < 16) //down
				new_state = changeState(new_state, (i / 4 + 1 ) * 4 + i % 4);
			if (state[new_state] != 1) //never expanded before
			{
				state_queue[ind % MAX_STATE] = new_state;
				ind = ind++;
			}
		}
	}
	return ans;
}
int main(){
//init bit opr
	for(int i = 0; i < 16; i++){
		BIT_OPR[i] = 1 << (15 - i);
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
