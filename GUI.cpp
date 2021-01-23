#include"GUI.h"
extern int Out[M];
extern int OutSize;


/********************************************************/
/*	�������ܣ�ͼƬ��ʼ������							*/
/*	������������										*/
/*	��������ֵ����										*/
/********************************************************/
void initgraph()
{
	setbkcolor(YELLOW);									//���ñ���ɫ
	cleardevice();										//��ȡͼƬ����ͼ����

	IMAGE Map, JDlist;									//����IMAGE����
	loadimage(&Map, _T("�ر��ͼ.jpg"), 1080, 760);		//���ص�ͼ
	loadimage(&JDlist, _T("��������.png"), 320, 250);	//���ؾ�������
	putimage(0, 0, &Map);								//��ʾ��ͼ
	putimage(1080, 510, &JDlist);						//��ʾ������Ϣ

	settextcolor(BLACK);								//����������ɫ
	settextstyle(20, 0, _T("����"));					//����������ʽ
	
	//���ù���ѡ�ť
	RECT r2 = { 0, 0, 2300, 150 };						
	drawtext(_T("1.��·��ѯ"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r3 = { 0, 0, 2320, 300 };
	drawtext(_T("2.�ؽڵ��ѯ"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r4 = { 0, 0, 2440, 450 };
	drawtext(_T("3.��ѯ�������ڵ�����·��"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r5 = { 0, 0, 2440, 600 };
	drawtext(_T("4.У԰���������Ϣ��ѯ"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r6 = { 0, 0, 2460, 750 };
	drawtext(_T("5.�ྰ����ѷ���·�߲�ѯ"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r7 = { 0, 0, 2700, 1500 };
	drawtext(_T("�˳�"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}


/********************************************************/
/*	�������ܣ��������									*/
/*	������������										*/
/*	��������ֵ����										*/
/********************************************************/
void upgradeGraph()
{
	IMAGE Map;											//����IMAGE����
	char* str = "�ر��ͼ";
	loadimage(&Map, _T("%s.jpg"),str, 1080, 760);		//���ص�ͼ
	putimage(0, 0, &Map);								//��ʾ��ͼ
	clearrectangle(1080, 430, 1400, 465);				//����ı�������ο�����
}

/********************************************************/
/*	�������ܣ�����Out������е�ͼ����					*/
/*	�����������ڽӾ���G									*/
/*	��������ֵ����										*/
/********************************************************/
void makeline(Mgraph G)
{
	int i;
	Sleep(500);											//����ͣ������
	for (i = 0; i < OutSize - 1; ++i)					//ѭ������
	{
		setlinecolor(RED);								//���õ���ɫ
		setlinestyle(PS_ENDCAP_ROUND, 10);				//���õ�ֶ�
		line(G.vexs[Out[i]].x, G.vexs[Out[i]].y, G.vexs[Out[i]].x, G.vexs[Out[i]].y);//����
		setlinecolor(LIGHTRED);							//���û�����ɫ
		setlinestyle(PS_ENDCAP_ROUND, 3);				//���û��ߴֶ�
		line(G.vexs[Out[i]].x, G.vexs[Out[i]].y, G.vexs[Out[i + 1]].x, G.vexs[Out[i + 1]].y);//����
		Sleep(250);										//����ͣ������
	}
	setlinecolor(RED);									//���õ�(�յ�)��ɫ
	setlinestyle(PS_ENDCAP_ROUND, 10);					//���õ�ֶ�
	line(G.vexs[Out[OutSize-1]].x, G.vexs[Out[OutSize - 1]].y, G.vexs[Out[OutSize - 1]].x, G.vexs[Out[OutSize - 1]].y);//����
	system("pause");									//��ͣ
	OutSize = 0;										//�ٴγ�ʼ��Out�����СΪ0
}

/********************************************************/
/*	�������ܣ�������¼�								*/
/*	����������											*/
/*	��������ֵ����										*/
/********************************************************/
void mouseClick()
{
	IMAGE picture_1;									//����IMAGE����
	Mgraph g =											//�ڽӾ���ṹ��
	{
		{
			{"һ����","һ����Ϊ�б���ѧ����,��������»��󽫾��ĵ���λ���ߺ�¥�����棬�ɳ���У԰��ʿ���ǽ����б���ѧ�ĵ�һ���ţ�λ������·����������һ��Ӵ��Ž��롣",210,616},
			{"������","�����ſ��������������С��¥����Ϊ����¥����·�ĸ���������Ҫ�����ڴ˴�������У԰��ʿ����ʱ�����ڶ����ſ���У԰�ڵĻ𳵣���ѧУ��һ�����صķ羰�ߡ�",255,423},
			{"������","�����ſ�������¥����·���⹫԰����ǰ��һ��С�Խ֣�����ͣ������ǰ�Ļ𳵣���ʦ�������˴��ι۵��ο����յľ���֮һ��",370,405},
			{"�ĵ���","�ĵ��ſ�����֪�㳡��Ҳ��������¥���ĵ����൱��λ��ѧУ����λ�ã����ŵ���ͨ������ͨ���б��Ƶꡣ",564,360},
			{"�����","����ſ���ѧУԭ�ȵ��ϴ���վ��Ҳ������ѧ¥��ѧ¥����ǰ�ۼ���С�Խֵľ�������ʳס��һӦ��ȫ��λ���ڶ�����",690,365},
			{"������","�����ſ�����ѧ�㳡��Ҳ��������¥��Ϊ��ǰС�Խֵľ�ͷ����������Ϊ��·��Щ�ѱ������",752,345},
			{"�ߵ���","λ�ڶ�������������������꣬Ҳ��������������Ҳ��ѧУ����ߵ�һ���ţ�Ҳ��У԰��ʿ���е㡣",882,323},
			{"�ߺ�¥","�б���ѧ��ѧ¥��Ҳ�Ƶ»�¥��λ��У԰����һ���Ÿ������ϱ���������»��󽫾��ĵ��񣬽�ѧ¥�ɵ�v�Σ��ϿεĽ���һ��Ӷ����������Ž��롣",236,605},
			{"��������","���������򳡣��������Ժ����Ӿ���������ѵ����ƽʱ������ѡ�������ͬѧҲ����������ϰ�����������̹����ᡣ",278,509},
			{"Уʷ��","�б���ѧ��¼ѧУ������չ��ʷ�ĵط���������֯�����ιۣ�����������ѧУ�����������ź����Ĺ�˾��ѧУ����Ƭ���ḻ��ʣ�Ҳ��ѧ���ڴ˴�Ϊ���ǽ���У԰��չ��",216,513},
			{"����԰","�ṩ�������ֵĻ��ⳡ������ɫ��������������ɽ�����а����֣��ɻ��أ���Ȫ�����ȣ��ʺ�ɢ�ģ���̫ԭ���������Ǽ���԰֮һ��",202,433},
			{"С��¥","�б���ѧ��������ѯ����λ���������ճ����������ίԱһ�𣬹�עѧ��������������ѧ�����ǽ��ѣ�̸�����ġ�",230,432},
			{"�������","�б���ѧѧ������¥��λ��������ס�и�Ժ��ѧ����Ҳ��ѧ�����ڴ˴����а칫�ص㡣",302,339},
			{"����ɽ","�б���ѧУ�ڵ�ɽ�徰�������ٷںӣ���̫ԭ�ı����ţ���ɫ������ɽ���ʻ��鲼������ɽ���η羰����̫ԭΪ������ı���ʤ�ء�",155,284},
			{"����Է","�б���ѧ�ٰ���ͻ�ĳ�����λ��������Уѧ����Ҳ������ڴ˴�����������������ᣬУ���ݳ��ȡ�",272,257},
			{"����ʳ��","�б���ѧʳ��֮һ��λ��������λ��������ḽ��������ѧ���Ͳͣ�ͬʱ���Ÿ��෹�ˣ��ʺϲ�ͬ��ζ��ѧ����",328,282},
			{"���ٳ�","�б���ѧ���ٳ���λ��������ӵ���İ��׵��ܵ���������õ���ɫ��ʵ�ݵأ����������ܺͽ������Եĵص㣬�����鲼ѧ���������塣",433,281},
			{"����ѵ������","λ���б���ѧ��������ǰ����ѧУ������ʵϰ�������������ɽ��ʡʵ���ѧʾ�����ģ���ѧ���ṩ���¹���ƽ̨��",374,132},
			{"��������","λ���б���ѧ�����������������˵��Ͻ��������������������ֻ����������ƹ�������ʩ��",432,176},
			{"ͼ���","λ���б���ѧУ԰���룬ӵ�з����鼮���п�ݵ��ӷ������������澭��������ѧϰ�ͽ����鼮��ѧ��������������Ũ���ѧϰ��Χ��",483,244},
			{"��Ӿ��","λ���б���ѧ�������ṩ�ɾ���ȫ����Ӿ�������������κ��ճ�����Ӿ��ʦ����",449,122},
			{"УҽԺ","λ���б���ѧ�ٽ��ںӴ�����һ�������ҵ�ҽԺ���ճ��Ӵ�������������˵�ͬѧ����ʦ�����񣬸������ṩ���ϡ�",394,132},
			{"��֪�㳡","λ���б���ѧ��¥��ǰ����ÿ�ջ�������������죬���ش����Ҳ�������������ʽ��",534,322},
			{"9��¥","�б���ѧ��ѧ¥��λ�ڶ������������������򳡣���ѧԺ��¥������ʵ��Ҳ�������ϿΡ�",594,176},
			{"��������","���������򳡣�ѧУ��Ժ�������������������У��ճ����������ѧ���������˶���",722,244},
			{"�������","����������¥֮һ�����Ÿ�Ժ��ѧ���������ס���������򳡣�������ѧ��ȥ������",787,237},
			{"��ѧ�㳡","λ���б���ѧ��������¥��ǰ����һ��������㳡�����������������",797,327},
			{"��԰����","������ʳ��֮һ�������������ᣬ���˴���ѧ���ṩ��ݵĳԷ�������",910,346},
			{"��������","����ѧ�����ᣬ��Ҫͨ������ͨ�����������������������˴���Զ��Խ�ΪƫƧ��",958,326},
			{"�б��Ƶ�","λ���б���ѧУ���ڣ������ںӺͶ���ɽ���羰�������������Ż������ģ��Ӵ����˴���������ʦ�ȡ�",597,484},
			{"�����̹�����","��ְ��������֮һ�������徲��������ҵ����㳡�����ڽ��й���ͳԷ���",623,490},
		},

		//Mgraph.edges[M][M]
		{
			{0,397,FINITY, FINITY, FINITY, FINITY, FINITY,35,359, FINITY, FINITY, FINITY, FINITY,FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY, FINITY},
			{397,0,220,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,238,FINITY ,FINITY ,50,380,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY },
			{ FINITY ,220,0,365,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,320,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY },
			{ FINITY ,FINITY ,365,0,211,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,249,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,150,FINITY },
			{ FINITY ,FINITY ,FINITY ,211,0,284,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY },
			{ FINITY ,FINITY ,FINITY ,FINITY ,284,0,228,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,160,FINITY ,FINITY ,FINITY ,FINITY },
			{ FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,228,0,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,200,825,FINITY ,FINITY ,FINITY },
			{35,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,0 ,FINITY ,340,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY },
			{359,238,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,0 ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY ,FINITY },
			{FINITY ,FINITY ,FINITY ,FINITY , FINITY , FINITY , FINITY , 340,FINITY , 0,250,350,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 250,0,166,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY },
			{ FINITY , 50,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 350 , 166,0,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY },
			{ FINITY , 380,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 0,220,260,230,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY },
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 220,0,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY },
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 260,FINITY , 0 , FINITY ,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , 320,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 230,FINITY , FINITY , 0,200,530,310,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY },
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY ,200,0,FINITY , 500,100,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 530,FINITY , 0,FINITY , FINITY , FINITY , 120,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY },
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 310,500,FINITY , 0,FINITY , FINITY , 100,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 100,FINITY , FINITY , 0,390 , FINITY , 300,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 390,0,210,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 120,100,FINITY , 210,0,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , 249,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 300,FINITY , FINITY , 0 , 380,450,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY ,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 380,0,200,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY },
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 450,200,0,220,FINITY , FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 220,0,180,FINITY , FINITY , FINITY , FINITY },
			{ FINITY , FINITY , FINITY , FINITY , FINITY , 160,200,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 180,0,FINITY , FINITY , FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 825,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 0,20,FINITY , FINITY},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 20,0,FINITY , FINITY},
			{ FINITY , FINITY , FINITY , 150,FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 0,140},
			{ FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , FINITY , 140,0}
		},
		31,40 };
	MOUSEMSG m;											//����MOUSEMSG����
	/*ѭ�����*/
	while (1) /*����¼�*/
	{
		m = GetMouseMsg();

		/*����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�*/
		setlinestyle(PS_ENDCAP_ROUND, 1);				//���û��ߴֶ�
		setlinecolor(WHITE);							//���û�����ɫ
		rectangle(1100, 60, 1200, 90);					//��һ���ܾ��ΰ׻�
		rectangle(1100, 135, 1220, 165);				//�ڶ����ܾ��ΰ׻�
		rectangle(1098, 210, 1350, 240);				//�������ܾ��ΰ׻�
		rectangle(1098, 285, 1350, 315);				//���Ĺ��ܾ��ΰ׻�
		rectangle(1098, 360, 1360, 390);				//���幦�ܾ��ΰ׻�
		rectangle(1330, 740, 1370, 760);				//������ť���ΰ׻�

		/*�����㴦����Բ�ǰ׻�*/
		roundrect(200, 606, 220, 626, 10, 10);
		roundrect(245, 413, 265, 433, 10, 10);
		roundrect(360, 395, 380, 415, 10, 10);
		roundrect(554, 350, 574, 370, 10, 10);
		roundrect(680, 355, 700, 375, 10, 10);
		roundrect(742, 335, 762, 355, 10, 10);
		roundrect(872, 313, 892, 333, 10, 10);
		roundrect(226, 595, 246, 615, 10, 10);
		roundrect(268, 499, 288, 519, 10, 10);
		roundrect(206, 503, 226, 523, 10, 10);
		roundrect(192, 423, 212, 443, 10, 10);
		roundrect(220, 422, 240, 442, 10, 10);
		roundrect(292, 329, 312, 349, 10, 10);
		roundrect(145, 274, 165, 294, 10, 10);
		roundrect(262, 247, 282, 267, 10, 10);
		roundrect(318, 272, 338, 292, 10, 10);
		roundrect(423, 271, 443, 291, 10, 10);
		roundrect(364, 122, 384, 142, 10, 10);
		roundrect(422, 166, 442, 186, 10, 10);
		roundrect(473, 234, 493, 254, 10, 10);
		roundrect(439, 112, 459, 132, 10, 10);
		roundrect(384, 122, 404, 142, 10, 10);
		roundrect(524, 312, 544, 332, 10, 10);
		roundrect(584, 166, 604, 186, 10, 10);
		roundrect(712, 234, 732, 254, 10, 10);
		roundrect(777, 227, 797, 247, 10, 10);
		roundrect(787, 317, 807, 337, 10, 10);
		roundrect(900, 336, 920, 356, 10, 10);
		roundrect(948, 316, 968, 336, 10, 10);
		roundrect(587, 474, 607, 494, 10, 10);
		roundrect(613, 480, 633, 500, 10, 10);

		/*���·����ѯ*/
		if (m.x >= 1100 && m.x <= 1200 && m.y >= 60 && m.y <= 90)//����ڡ����·����ѯ����ť��									
		{
			setlinecolor(BLUE);							//�����ߵ���ɫΪ��ɫ
			rectangle(1100, 60, 1200, 90);				//���þ��ο�
			if (m.uMsg == WM_LBUTTONDOWN)				//�������������ʵ����Ӧ����.
			{
			/*�����ȡ�û�������Ϣ*/
			char s1[10]="", s2[10]="";
			InputBox(s1, 10, _T("���������(1-31)"), "���·����ѯ", "1", 60, 10, FALSE);
			InputBox(s2, 10, _T("�������յ�(1-31)"), "���·����ѯ", "7", 60, 10, FALSE);
			int v1,v2;
			sscanf_s(s1, "%d", &v1);					//����ת�����ַ�������->���Σ�	
			sscanf_s(s2, "%d", &v2);					//����ת�����ַ�������->���Σ�	

			if(strlen(s1) > 0 && strlen(s2)>0)			//����������
				if(v1>0&&v1<32&&v1>0 && v1 < 32)		//���ݺϷ�
				{
					dist d;
					path p;
					floyd(g, d, p);						//floyd�㷨��d��p����
					floydprint(g, d, p, v1 - 1, v2 - 1);//floyd�㷨��v1-1��v2-1�����·��
					settextcolor(BLACK);				//�����ı���ɫ
					settextstyle(23, 0, _T("����"));	//�����ı���ʽ
					/*�������*/
					char text[20];
					sprintf_s(text, sizeof(text), "·�����ȣ�%d��", d[v1-1][v2-1]);
					outtextxy(1110, 440, text);
					makeline(g);

					upgradeGraph();						//�������
					/*Out�����ʼ��*/
					OutSize = 0;						
					for (int i = 0; i < M; ++i)Out[i] = 0;
				}
			continue;
			}
		}

		/*�ؽڵ��ѯ*/
		else if (m.x >= 1100 && m.x <= 1220 && m.y >= 135 && m.y <= 165)									
		{
			setlinecolor(BLUE);							//�����ߵ���ɫΪ��ɫ
			rectangle(1100, 135, 1220, 165);			//���þ��ο�
			if (m.uMsg == WM_LBUTTONDOWN)				//�������������ʵ����Ӧ����.
			{		
				LinkedGraph L;
				ljb_from_ljjz(&L, g);
				FindArticul(L);
				/*Out�����ʼ��*/
				OutSize = 0;
				for (int i = 0; i < M; ++i)Out[i] = 0;
				upgradeGraph();
				continue;
			}
		}

		/*��ѯ�������ڵ�����·��*/
		else if (m.x >= 1098 && m.x <= 1350 && m.y >= 210 && m.y <= 240)									
		{
			setlinecolor(BLUE);
			rectangle(1098, 210, 1350, 240);
			if (m.uMsg == WM_LBUTTONDOWN) {					//�������������ʵ����Ӧ����.
				char s1[10], s2[10];
				InputBox(s1, 10, _T("���������"), "�����������·��", "1", 60, 10, FALSE);
				InputBox(s2, 10, _T("�������յ�"), "�����������·��", "7", 60, 10, FALSE);
				int v1, v2;
				sscanf_s(s1, "%d", &v1);
				sscanf_s(s2, "%d", &v2);
				if (strlen(s1) > 0 && strlen(s2) > 0)		//����������
					if (v1 > 0 && v1 < 32 && v1>0 && v1 < 32)//���ݺϷ�
					{
					allpathsout(g, v1-1, v2-1);				//����allpathsout����
					/*Out�����ʼ��*/
					OutSize = 0;
					for (int i = 0; i < M; ++i)Out[i] = 0;

					upgradeGraph();							//�������
					continue;
					}
			}
		}

		/*����·�߹滮*/
		else if (m.x >= 1098 && m.x <= 1360 && m.y >= 360 && m.y <= 390)							
		{
			int i,j=0;
			int want[M],flag=1,second;						//flagΪ����Դ��־λ
			char temp[3]="";
			char s1[2*M]="";
			setlinecolor(BLUE);								//���û�����ɫ
			rectangle(1098, 360, 1360, 390);				//���ο�	
			if (m.uMsg == WM_LBUTTONDOWN)					//�������������ʵ����Ӧ����.
			{
				/*�����ȡ�û�������Ϣ*/
				InputBox(s1, 2*M, _T("����������ι۵ľ���(�м���-�ֿ�)"), "����·�߹滮", "1-2-3-4", 60, 10, FALSE);
				if(strlen(s1)>0)							//���벻Ϊ��
				{
					for (i = 0;s1[i]!='\0'; i++)			//��want[]
					{
						if (s1[i] == 45)	continue;		//�����ָ�����Ծ 
						temp[0] = s1[i];					//ÿ���ַ�����ȡ��
						sscanf_s(temp, "%d", &want[j]);		//����ת��
						want[j]--;							//ϵͳ��1
						if (s1[i + 1] >= 48 && s1[i + 1] <= 57)//���ڵ���λ��
						{
							temp[0] = s1[i + 1];
							sscanf_s(temp, "%d", &second);
							printf("j= %d\n", second);
							want[j] = (want[j]+1) * 10 + second;
							want[j]--;
							i++;
						}
						j++;
					}
					if (j > 0 && flag == 1)					//want����������㷨�ν�
					{
						dist d;
						path p;
						floyd(g, d, p);
						BestpathOutput(g, want, j, d, p);	//����BestpathOutput����
						/*Out�����ʼ��*/
						OutSize = 0;
						for (int i = 0; i < M; ++i)Out[i] = 0;
						upgradeGraph();
					}
				}
				continue;
			}
		}

		/*������ť*/
		else if (m.x >= 1330 && m.x <= 1370 && m.y >= 740 && m.y <= 760)
		{
			setlinecolor(BLUE);
			rectangle(1330, 740, 1370, 760);
			if (m.uMsg == WM_LBUTTONDOWN) {
				closegraph();
				printf("���� \n");
				return;
			}
		}

		/*������Ϣ��ѯ��ť*/
		else if (m.x >= 200 && m.x <= 220 && m.y >= 606 && m.y <= 626)								
		{
			setlinecolor(BLUE);
			roundrect(200, 606, 220, 626, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("һ����_1.png"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ

				TCHAR s[] = _T("һ����Ϊ�б���ѧ����,��������»��󽫾��ĵ���λ���ߺ�¥�����棬�ɳ���У԰��ʿ���ǽ����б���ѧ�ĵ�һ���ţ�");
				outtextxy(10, 20, s);

				TCHAR s2[] = _T("λ������·����������һ��Ӵ��Ž��롣");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 245 && m.x <= 265 && m.y >= 413 && m.y <= 433) {
			setlinecolor(BLUE);
			roundrect(245, 413, 265, 433, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("������_2.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�����ſ��������������С��¥����Ϊ����¥����·�ĸ���������Ҫ�����ڴ˴�������У԰��ʿ����ʱ�����ڶ�����");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("����У԰�ڵĻ𳵣���ѧУ��һ�����صķ羰�ߡ�");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 360 && m.x <= 380 && m.y >= 395 && m.y <= 415) {
			setlinecolor(BLUE);
			roundrect(360, 395, 380, 415, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("������_3.png"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�����ſ�������¥����·���⹫԰����ǰ��һ��С�Խ֣�����ͣ������ǰ�Ļ𳵣���ʦ�������˴��ι۵��ο����յ�");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("����֮һ��");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 554 && m.x <= 574 && m.y >= 350 && m.y <= 370) {
			setlinecolor(BLUE);
			roundrect(554, 350, 574, 370, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�ĵ���_4.png"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�ĵ��ſ�����֪�㳡��Ҳ��������¥���ĵ����൱��λ��ѧУ����λ�ã����ŵ���ͨ������ͨ���б��Ƶꡣ");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 680 && m.x <= 700 && m.y >= 355 && m.y <= 375) {
			setlinecolor(BLUE);
			roundrect(680, 355, 700, 375, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�����_5.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("����ſ���ѧУԭ�ȵ��ϴ���վ��Ҳ������ѧ¥��ѧ¥����ǰ�ۼ���С�Խֵľ�������ʳס��һӦ��ȫ��λ���ڶ�����");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 742 && m.x <= 762 && m.y >= 335 && m.y <= 355) {
			setlinecolor(BLUE);
			roundrect(742, 335, 762, 355, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("������_6.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�����ſ�����ѧ�㳡��Ҳ��������¥��Ϊ��ǰС�Խֵľ�ͷ����������Ϊ��·��Щ�ѱ������");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 872 && m.x <= 892 && m.y >= 313 && m.y <= 333) {
			setlinecolor(BLUE);
			roundrect(872, 313, 892, 333, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�ߵ���_7.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�ߵ���λ�ڶ�������������������꣬Ҳ��������������Ҳ��ѧУ����ߵ�һ���ţ�Ҳ��У԰��ʿ���յ㡣");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 226 && m.x <= 246 && m.y >= 595 && m.y <= 615) {
			setlinecolor(BLUE);
			roundrect(226, 595, 246, 615, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�»�¥_8.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧ��ѧ¥��Ҳ�Ƶ»�¥��λ��У԰����һ���Ÿ������ϱ���������»��󽫾��ĵ��񣬽�ѧ¥�ɵ�v�Σ��Ͽε�");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("����һ��Ӷ����������Ž��롣");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 268 && m.x <= 288 && m.y >= 499 && m.y <= 519) {
			setlinecolor(BLUE);
			roundrect(268, 499, 288, 519, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��������_9.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("���������򳡣��������Ժ����Ӿ���������ѵ����ƽʱ������ѡ�������ͬѧҲ����������ϰ�����������̹����ᡣ");
				outtextxy(10, 20, s);

				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 206 && m.x <= 226 && m.y >= 503 && m.y <= 523) {
			setlinecolor(BLUE);
			roundrect(206, 503, 226, 523, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("Уʷ��_10.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧ��¼ѧУ������չ��ʷ�ĵط���������֯�����ιۣ�����������ѧУ�����������ź����Ĺ�˾��ѧУ����Ƭ��");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("�ḻ��ʣ�Ҳ��ѧ���ڴ˴�Ϊ���ǽ���У԰��չ��");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 192 && m.x <= 212 && m.y >= 423 && m.y <= 443) {
			setlinecolor(BLUE);
			roundrect(192, 423, 212, 443, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("����԰_11.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�ṩ�������ֵĻ��ⳡ������ɫ��������������ɽ�����а����֣��ɻ��أ���Ȫ�����ȣ��ʺ�ɢ�ģ�");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("��̫ԭ���������Ǽ���԰֮һ��");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 220 && m.x <= 240 && m.y >= 422 && m.y <= 442) {
			setlinecolor(BLUE);
			roundrect(220, 422, 240, 442, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("С��¥_12.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧ��������ѯ����λ���������ճ����������ίԱһ�𣬹�עѧ��������������ѧ�����ǽ��ѣ�̸�����ġ�");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 292 && m.x <= 312 && m.y >= 329 && m.y <= 349) {
			setlinecolor(BLUE);
			roundrect(292, 329, 312, 349, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�������_13.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧѧ������¥��λ��������ס�и�Ժ��ѧ����Ҳ��ѧ�����ڴ˴����а칫�ص㡣");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 145 && m.x <= 165 && m.y >= 274 && m.y <= 294) {
			setlinecolor(BLUE);
			roundrect(145, 274, 165, 294, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("����ɽ_14.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧУ�ڵ�ɽ�徰�������ٷںӣ���̫ԭ�ı����ţ���ɫ������ɽ���ʻ��鲼������ɽ���η羰����̫ԭΪ������");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("�ı���ʤ�ء�");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 262 && m.x <= 282 && m.y >= 247 && m.y <= 267) {
			setlinecolor(BLUE);
			roundrect(262, 247, 282, 267, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("����Է_15.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧ�ٰ���ͻ�ĳ�����λ��������Уѧ����Ҳ������ڴ˴�����������������ᣬУ���ݳ��ȡ�");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 318 && m.x <= 338 && m.y >= 272 && m.y <= 292) {
			setlinecolor(BLUE);
			roundrect(318, 272, 338, 292, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("����ʳ��_16.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧʳ��֮һ��λ��������λ��������ḽ��������ѧ���Ͳͣ�ͬʱ���Ÿ��෹�ˣ��ʺϲ�ͬ��ζ��ѧ����");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 423 && m.x <= 443 && m.y >= 271 && m.y <= 291) {
			setlinecolor(BLUE);
			roundrect(423, 271, 443, 291, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("���ٳ�_17.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧ���ٳ���λ��������ӵ���İ��׵��ܵ���������õ���ɫ��ʵ�ݵأ����������ܺͽ������Եĵص㣬����");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("�鲼ѧ���������塣");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 364 && m.x <= 384 && m.y >= 122 && m.y <= 142) {
			setlinecolor(BLUE);
			roundrect(364, 122, 384, 142, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��ѵ����_18.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("λ���б���ѧ��������ǰ����ѧУ������ʵϰ�������������ɽ��ʡʵ���ѧʾ�����ģ���ѧ���ṩ���¹���ƽ̨��");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 422 && m.x <= 442 && m.y >= 166 && m.y <= 186) {
			setlinecolor(BLUE);
			roundrect(422, 166, 442, 186, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��������_19.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("λ���б���ѧ�����������������˵��Ͻ��������������������ֻ����������ƹ�������ʩ��");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 473 && m.x <= 493 && m.y >= 234 && m.y <= 254) {
			setlinecolor(BLUE);
			roundrect(473, 234, 493, 254, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("ͼ���_20.png"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("λ���б���ѧУ԰���룬ӵ�з����鼮���п�ݵ��ӷ������������澭��������ѧϰ�ͽ����鼮��ѧ������������");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("��Ũ���ѧϰ��Χ��");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 439 && m.x <= 459 && m.y >= 112 && m.y <= 132) {
			setlinecolor(BLUE);
			roundrect(439, 112, 459, 132, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��Ӿ��_21.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("λ���б���ѧ�������ṩ�ɾ���ȫ����Ӿ�������������κ��ճ�����Ӿ��ʦ����");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 384 && m.x <= 404 && m.y >= 122 && m.y <= 142) {
			setlinecolor(BLUE);
			roundrect(384, 122, 404, 142, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("УҽԺ_22.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("Уλ���б���ѧ�ٽ��ںӴ�����һ�������ҵ�ҽԺ���ճ��Ӵ�������������˵�ͬѧ����ʦ�����񣬸������ṩ���ϡ�");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 524 && m.x <= 544 && m.y >= 312 && m.y <= 332) {
			setlinecolor(BLUE);
			roundrect(524, 312, 544, 332, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��֪�㳡_23.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("λ���б���ѧ��¥��ǰ����ÿ�ջ�������������죬���ش����Ҳ�������������ʽ��");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 584 && m.x <= 604 && m.y >= 166 && m.y <= 186) {
			setlinecolor(BLUE);
			roundrect(584, 166, 604, 186, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("9��¥_24.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б���ѧ9�Ž�ѧ¥��λ�ڶ����������������򳡣���ѧԺ��¥������ʵ��Ҳ�������ϿΡ�");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 712 && m.x <= 732 && m.y >= 234 && m.y <= 254) {
			setlinecolor(BLUE);
			roundrect(712, 234, 732, 254, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��������_25.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("���������򳡣�ѧУ��Ժ�������������������У��ճ����������ѧ���������˶���");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 777 && m.x <= 797 && m.y >= 227 && m.y <= 247) {
			setlinecolor(BLUE);
			roundrect(777, 227, 797, 247, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�������_26.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("������᣺����������¥֮һ�����Ÿ�Ժ��ѧ���������ס���������򳡣�������ѧ��ȥ������");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 787 && m.x <= 807 && m.y >= 317 && m.y <= 337) {
			setlinecolor(BLUE);
			roundrect(787, 317, 807, 337, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��ѧ�㳡_27.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("��ѧ�㳡��λ���б���ѧ��������¥��ǰ����һ��������㳡�����������������");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 900 && m.x <= 920 && m.y >= 336 && m.y <= 356) {
			setlinecolor(BLUE);
			roundrect(900, 336, 920, 356, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��԰����_28.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("��԰������������ʳ��֮һ�������������ᣬ���˴���ѧ���ṩ��ݵĳԷ�������");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 948 && m.x <= 968 && m.y >= 316 && m.y <= 336) {
			setlinecolor(BLUE);
			roundrect(948, 316, 968, 336, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("��������_29.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("������Ԣ������ѧ�����ᣬ��Ҫͨ������ͨ�����������������������˴���Զ��Խ�ΪƫƧ��");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 587 && m.x <= 607 && m.y >= 474 && m.y <= 494) {
			setlinecolor(BLUE);
			roundrect(587, 474, 607, 494, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�б��Ƶ�_30.png"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�б��Ƶ꣺λ���б���ѧУ���ڣ������ںӺͶ���ɽ���羰�������������Ż������ģ��Ӵ����˴���������ʦ�ȡ�");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 613 && m.x <= 633 && m.y >= 480 && m.y <= 500) {
			setlinecolor(BLUE);
			roundrect(613, 480, 633, 500, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //�������������ʵ����Ӧ����.
			{
				loadimage(&picture_1, _T("�����̹�����_31.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//��ʾ��ͼ
				TCHAR s[] = _T("�����̹����᣺��ְ��������֮һ�������徲��������ҵ����㳡�����ڽ��й���ͳԷ���");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
	}
	}

