#define _CRT_SECURE_NO_WARNINGS 1
//˼·��ÿ���γ������ܵ���ĵط�����Ⱦɫ��������Ⱦɫ�ĵ������ɢ��
//������1������·�ߣ�ĳ��·�߷����пɴ�վ�㣬�㽫���·�ߵ�����վ�㶼ȾɫΪ�ɴ�վ�㡣
//     2��һ��·�ߣ���ɶ�·����վ���Ⱦɫ�󣬸�·�߱�ʧȥ�ٴα��������壬�´ο��Բ��ٱ�����ʹ��roadused��¼�Ѿ����ʹ����·�ߡ�

bool flag[1000000] = { 0 };       //��1��վ��˵���ɴ�
bool flag_update[1000000] = { 0 }; //��ĳһ�α����У��ոձ�Ⱦɫ�ĵ㲻��ֱ�ӷŵ�falg�У���ֹ�Ա��α����������ڵ���Ӱ��
int  * colsize = 0;
#define printf(fmt, args...) ((void)0)    //���Կ���
int setroad(int *road, int k)
{

	int isin = 0;

	for (int i = 0; i<colsize[k]; i++){
		printf("colsize[%d]=%d\n", i, colsize[i]);
		if (flag[road[i]] == 1){//�ж��Ƿ�����һ����Ⱦɫ
			printf("[%d]is in!\n", road[i]);
			isin = 1; break;
		}
	}
	if (isin == 0)return 0;
	for (int i = 0; i<colsize[k]; i++){
		printf("set other %d in road \n", road[i]);
		flag_update[road[i]] = 1;//�ڵ�ǰһ��Ⱦɫ
	}
	return 1;
}


int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int S, int T){
	colsize = routesColSize;
	memset(flag, 0, sizeof(bool)* 1000000);
	memset(flag_update, 0, sizeof(bool)* 1000000);
	int times = 0;
	int ran = 0;
	int * roadused = 0;
	roadused = calloc(sizeof(int), routesSize);
	flag[S] = 1;
	flag_update[S] = 1;
	if (flag[T] == 1)return times;//�տ�ʼ����Ŀ��վ��������û���ǵ���
	while (1){
		memcpy(flag, flag_update, sizeof(bool)* 1000000);//����flag
		times++;
		printf("start once search times=%d\n", times);
		ran = 0;
		for (int i = 0; i<routesSize; i++)
		{

			if (roadused[i] == 1)continue;
			printf("search  road [%d]\n", i);
			if (setroad(routes[i], i) == 1){
				ran = 1;
				roadused[i] = 1;
			}
		}
		if (flag_update[T] == 1)return times;
		if (ran == 0) return -1;
	}

}