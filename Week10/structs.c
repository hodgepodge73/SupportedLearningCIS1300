#include "structs.h"
//there are 2 problems in this code
int main(int argc, char const *argv[])
{
	FILE* fp = fopen("attendees1.txt", "r");
	//
	participants slg[20];
	int i;//

	
	while(!feof(fp)){
		fscanf(fp, "%s %d %d ", &slg[i].name, &slg[i].hours, &slg[i].sessions);
		i++;
	}
	//sort by hours
	qsort(&slg[0].hours, 6, sizeof(participants), comp);

	printf("LEADERBOARD: ");
	for (int j=0;j<i; j++){
		printf("%d. %s   %d     %d sessions\n", j+1, slg[j].name, slg[j].hours, slg[j].sessions);
	}

	printf("Okay let's do the average time attended per session now\n");

	for (int j=0; j<i; j++){
		slg[j].average = (float)(slg[j].hours/slg[j].sessions);
	}

	//sort by averages
    qsort(slg, 20, sizeof(participants), comp);

	printf("LEADERBOARD: \n");
	for (int j=0;j<i; j++){
		printf("%d. %s   %.2lf     %d sessions\n", j+1, slg[j].name, slg[j].average, slg[j].sessions);
	}

	return 0;
}


//write the comp function
int comp(const void*a, const void*b ){
	const participants * avga;
	const participants *avgb;
	avga = a;
	avgb = b;
	return ((int)avga->average)-((int)avgb->average);
}

