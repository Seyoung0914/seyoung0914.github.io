// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {//메인 함수 자체는 간단함. 그저 번호에 따라 각각의 함수를 출력하는 excutor 역할.
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}

/*
채널 자체를 출력하는 것은 그냥 반복문에다 인덱스 쓰면 쉬운 일이고, 아니면 그냥 뭐 적어도 되고.....
그런데 여기서 중요한 부분은 찾는 것인데, Top channel과 평균적인 Average를 찾아야 하면 결국에 거기에 속한 애들을 다 불러야 되긴 하겠네
그러면 일단 다 찾아야 해서 하나하나 다 봐야겠네. 
level당 해서 0부터 4까지 한다음에->얘는 반복문 돌리면 되고.
다 더한다음 평균을 구하는거 하나랑
채널 갯수
그리고 가장 많은 채널도 구하려면
변수를 여러개 선언할 필요가 있겠네?

변수는 채널갯수랑, 가장 많은 채널 요거 두개가 필요하겠네 그리고 LEVEL속한 모든 구독자 수를 더해줄 변술랑
그리고 평균 구독자 수 는 모든 구독자수/ 채널 갯수가 필요할거고, 가장 많은 채널은 채널 갯수만큼 돌리면 되니까
아니 애초에 채널 갯수자체는 파라미터로 들어오니까 
결국, 채널갯수만큼 돌리고 더하고 가장많은 채널 더하고 더한 총 구독자 수를 파라매터로 받은 채널 갯수로 나누면 되겠네!


*/



void printStatistics(struct st_channel* c[], int size){//모든 채널 정보에 대해 5개 등급별 채널개수와 평균 구독자수, 최대 구독자수를 가진 채널명, 구독자수를 출력한다 //no는 최대 채널 갯수
	printf("> Statistics of Channels\n");


	for(int i=0; i<=5; i++){
		int c_amount=0;
		int p_amount=0;
		char t_channel;
		int t_channel_p=0;
		
		for(int k=0; k<size; k++){//등급당 채널 갯수를 알아야 하잖아 그러면 그것도 구해야 겠는데?
			if(c->level=i){//여기서 속한 총 채널 갯수가 출력이 되겠지.
				c_amount++;
				p_amount += c->count; //원래 있던 총량에 더하는 방법이 뭐지?
			}
			if(c_amount<=){
				t_channel = c->name;
				t_channel_p = c->count;
			}

		}
		printf("%s : %d channels, Average %f peoples, Top channel : %s (%d peoples)",LNAME[i], c_amount, p_amount/c_amount, t_channel, t_channel_p); //가장 많은 채널을 찾기 위해서는 하나하나 봐야돼. 하나하나 보지 않고 한번에 할 수 있는 방법이 있을까? if이용하면?

	}



}

void pickupRandomChannels(struct st_channel* c[], int size){// 채널 중에서 사용자가 입력한 개수만큼의 임의의 채널을 선택해서 출력한다.
	printf("> Pick up Channels\n");
	printf("> How much channels you want to pick up? > ");




}
void searchChannel(struct st_channel* c[], int size){//채널 정보 중 다음 조건에 맞는 채널 정보를 출력한다. 1) 특정 범위 숫자(최소~최대)의 구독자 수를 가진 채널 검색 2) 특정 문자열이 포함된 이름을 가진 채널 검색
	printf("> Search Channels\n");
	printf("> Choose one (1:by peoples 2:by names) > ");





}

void updateChannel(struct st_channel* c[], int size){//사용자가 입력한 번호에 해당하는 채널에 대해 새로운 정보(채널명,구독자수)를 입력받아 변경한다.
	printf("> Modify a new Channel\n");
	printf("> Enter a number of channel > ");


}

int deleteChannel(struct st_channel* c[], int size){//사용자가 입력한 번호와 구조체 포인터에 연결된 채널정보를 삭제하고, 대신 마지막 번호의 채널을 연결한다. 삭제 후에는 채널 개수가 1개 줄어들었으니 size-1을 리턴한다.
	int no, yesno;
	printf("> Delete a new Channel\n");
	printf("> Enter a number of channel > ");

	return size;
}


void makeReport(struct st_channel* c[], int size){//report.txt 파일에 [1]과 [2]메뉴의 출력 내용을 저장하고, channels.txt에는 현재까지 변경된 모든 채널의 이름과 구독자수를 저장한다.

}