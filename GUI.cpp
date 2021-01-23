#include"GUI.h"
extern int Out[M];
extern int OutSize;


/********************************************************/
/*	函数功能：图片初始化界面							*/
/*	函数参数：无										*/
/*	函数返回值：无										*/
/********************************************************/
void initgraph()
{
	setbkcolor(YELLOW);									//设置背景色
	cleardevice();										//读取图片至绘图窗口

	IMAGE Map, JDlist;									//创建IMAGE对象
	loadimage(&Map, _T("地标地图.jpg"), 1080, 760);		//加载地图
	loadimage(&JDlist, _T("景点名称.png"), 320, 250);	//加载景点名称
	putimage(0, 0, &Map);								//显示地图
	putimage(1080, 510, &JDlist);						//显示景点信息

	settextcolor(BLACK);								//设置字体颜色
	settextstyle(20, 0, _T("楷体"));					//设置字体样式
	
	//设置功能选项按钮
	RECT r2 = { 0, 0, 2300, 150 };						
	drawtext(_T("1.问路查询"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r3 = { 0, 0, 2320, 300 };
	drawtext(_T("2.关节点查询"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r4 = { 0, 0, 2440, 450 };
	drawtext(_T("3.查询任意两节点所有路径"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r5 = { 0, 0, 2440, 600 };
	drawtext(_T("4.校园景点具体信息查询"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r6 = { 0, 0, 2460, 750 };
	drawtext(_T("5.多景点最佳访问路线查询"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT r7 = { 0, 0, 2700, 1500 };
	drawtext(_T("退出"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}


/********************************************************/
/*	函数功能：界面更新									*/
/*	函数参数：无										*/
/*	函数返回值：无										*/
/********************************************************/
void upgradeGraph()
{
	IMAGE Map;											//创建IMAGE对象
	char* str = "地标地图";
	loadimage(&Map, _T("%s.jpg"),str, 1080, 760);		//加载地图
	putimage(0, 0, &Map);								//显示地图
	clearrectangle(1080, 430, 1400, 465);				//清空文本输出矩形框内容
}

/********************************************************/
/*	函数功能：根据Out数组进行地图划线					*/
/*	函数参数：邻接矩阵G									*/
/*	函数返回值：无										*/
/********************************************************/
void makeline(Mgraph G)
{
	int i;
	Sleep(500);											//划线停顿休眠
	for (i = 0; i < OutSize - 1; ++i)					//循环划线
	{
		setlinecolor(RED);								//设置点颜色
		setlinestyle(PS_ENDCAP_ROUND, 10);				//设置点粗度
		line(G.vexs[Out[i]].x, G.vexs[Out[i]].y, G.vexs[Out[i]].x, G.vexs[Out[i]].y);//划点
		setlinecolor(LIGHTRED);							//设置划线颜色
		setlinestyle(PS_ENDCAP_ROUND, 3);				//设置划线粗度
		line(G.vexs[Out[i]].x, G.vexs[Out[i]].y, G.vexs[Out[i + 1]].x, G.vexs[Out[i + 1]].y);//划线
		Sleep(250);										//划线停顿休眠
	}
	setlinecolor(RED);									//设置点(终点)颜色
	setlinestyle(PS_ENDCAP_ROUND, 10);					//设置点粗度
	line(G.vexs[Out[OutSize-1]].x, G.vexs[Out[OutSize - 1]].y, G.vexs[Out[OutSize - 1]].x, G.vexs[Out[OutSize - 1]].y);//划点
	system("pause");									//暂停
	OutSize = 0;										//再次初始化Out数组大小为0
}

/********************************************************/
/*	函数功能：鼠标点击事件								*/
/*	函数参数：											*/
/*	函数返回值：无										*/
/********************************************************/
void mouseClick()
{
	IMAGE picture_1;									//创建IMAGE对象
	Mgraph g =											//邻接矩阵结构体
	{
		{
			{"一道门","一道门为中北大学正门,正对着彭德怀大将军的雕像，位于七号楼的南面，可乘坐校园巴士，是进入中北大学的第一道门，位于新兰路，来往车辆一般从此门进入。",210,616},
			{"二道门","二道门靠近文瀛宿舍区与小白楼，作为宿舍楼与铁路的隔断至关重要，可在此处乘坐到校园巴士，有时可以在二道门看见校园内的火车，是学校的一道独特的风景线。",255,423},
			{"三道门","三道门靠近回字楼和铁路主题公园，以前有一条小吃街，这里停靠着以前的火车，是师生和来此处参观的游客拍照的景点之一。",370,405},
			{"四道门","四道门靠近行知广场，也正对着主楼，四道门相当于位于学校中心位置，有着地下通道可以通往中北酒店。",564,360},
			{"五道门","五道门靠近学校原先的韵达快递站，也靠近笃学楼教学楼，以前聚集了小吃街的精华，衣食住行一应俱全，位属于东区。",690,365},
			{"六道门","六道门靠近致学广场，也靠近六号楼，为从前小吃街的尽头，六道门因为修路有些已被拆除。",752,345},
			{"七道门","位于东区，附近有许多外卖店，也与上兰村相连，也是学校的最东边的一个门，也是校园巴士的中点。",882,323},
			{"七号楼","中北大学教学楼，也称德怀楼，位于校园西区一道门附近，南边伫立着彭德怀大将军的雕像，教学楼成倒v形，上课的教室一般从东西两处的门进入。",236,605},
			{"西区足球场","西区的足球场，面积大，七院足球队经常在这里训练，平时体育课选秀足球的同学也会在这里练习，靠近怡丁教工宿舍。",278,509},
			{"校史馆","中北大学记录学校以往发展历史的地方，经常组织新生参观，里面有着在学校其他地区有着合作的公司和学校的照片，丰富多彩，也有学生在此处为他们介绍校园发展。",216,513},
			{"柏林园","提供休闲娱乐的户外场所，景色优美，依傍二龙山，内有柏树林，荷花池，喷泉，长廊，适合散心，是太原市七所四星级公园之一。",202,433},
			{"小白楼","中北大学心理健康咨询处，位于西区，日常与各班心理委员一起，关注学生心理健康，帮助学生排忧解难，谈天聊心。",230,432},
			{"文瀛宿舍","中北大学学生宿舍楼，位于西区，住有各院的学生，也有学生科在此处设有办公地点。",302,339},
			{"二龙山","中北大学校内的山峰景区，西临汾河，是太原的北大门，景色秀丽，山上鲜花遍布，二龙山旅游风景区是太原为数不多的避暑胜地。",155,284},
			{"科艺苑","中北大学举办大型活动的场所，位于西区，校学生会也在这里，在此处会设立讲座，报告会，校庆演出等。",272,257},
			{"第四食堂","中北大学食堂之一，位于西区，位于文瀛宿舍附近，便于学生就餐，同时有着各类饭菜，适合不同口味的学生。",328,282},
			{"主操场","中北大学最大操场，位于西区，拥有四百米的跑道和养护完好的绿色真实草地，是体育长跑和健康测试的地点，经常遍布学生锻炼身体。",433,281},
			{"工程训练中心","位于中北大学西区，其前身是学校成立的实习工厂，如今已是山西省实验教学示范中心，给学生提供创新工作平台。",374,132},
			{"老年活动中心","位于中北大学西区，经常有退休了的老教授在这里锻炼身体和娱乐活动，里面有着乒乓球等设施。",432,176},
			{"图书馆","位于中北大学校园中央，拥有丰厚的书籍，有快捷电子服务渠道，里面经常坐满来学习和借阅书籍的学生，在这里有着浓厚的学习氛围。",483,244},
			{"游泳馆","位于中北大学东区，提供干净安全的游泳环境给上体育课和日常来游泳的师生。",449,122},
			{"校医院","位于中北大学临近汾河处，是一所二级乙等医院，日常接待了许多生病受伤的同学、老师、居民，给健康提供保障。",394,132},
			{"行知广场","位于中北大学主楼的前方，每日会在这里升起国旗，在重大节日也会在这里举行仪式。",534,322},
			{"9号楼","中北大学教学楼，位于东区，，靠近东区篮球场，理学院主楼，大物实验也在这里上课。",594,176},
			{"东区篮球场","东区的篮球场，学校各院的篮球比赛会在这里举行，日常这里有许多学生在这里运动。",722,244},
			{"文韬宿舍","东区的宿舍楼之一，有着各院的学生在这里居住，靠近篮球场，经常有学生去锻炼。",787,237},
			{"致学广场","位于中北大学东区六号楼的前方，一个大面积广场，靠近文韬宿舍区。",797,327},
			{"田园餐厅","东区的食堂之一，靠近文澜宿舍，给此处的学生提供便捷的吃饭场所。",910,346},
			{"文澜宿舍","最东面的学生宿舍，需要通过地下通道到达，相对于其他宿舍区，此处相对而言较为偏僻。",958,326},
			{"中北酒店","位于中北大学校区内，靠近汾河和二龙山，风景优美，二层有着会议中心，接待来此处交流的老师等。",597,484},
			{"怡丁教工宿舍","教职工宿舍区之一，环境清静，靠近百业生活广场，便于进行购物和吃饭。",623,490},
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
	MOUSEMSG m;											//创建MOUSEMSG对象
	/*循环点击*/
	while (1) /*点击事件*/
	{
		m = GetMouseMsg();

		/*当鼠标不在目标位置就覆盖之前的蓝色边框*/
		setlinestyle(PS_ENDCAP_ROUND, 1);				//设置划线粗度
		setlinecolor(WHITE);							//设置划线颜色
		rectangle(1100, 60, 1200, 90);					//第一功能矩形白环
		rectangle(1100, 135, 1220, 165);				//第二功能矩形白环
		rectangle(1098, 210, 1350, 240);				//第三功能矩形白环
		rectangle(1098, 285, 1350, 315);				//第四功能矩形白环
		rectangle(1098, 360, 1360, 390);				//第五功能矩形白环
		rectangle(1330, 740, 1370, 760);				//结束按钮矩形白环

		/*各景点处矩形圆角白环*/
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

		/*最短路径查询*/
		if (m.x >= 1100 && m.x <= 1200 && m.y >= 60 && m.y <= 90)//鼠标在“最短路径查询”按钮上									
		{
			setlinecolor(BLUE);							//设置线的颜色为蓝色
			rectangle(1100, 60, 1200, 90);				//设置矩形框
			if (m.uMsg == WM_LBUTTONDOWN)				//如果按下鼠标左键实现相应功能.
			{
			/*弹框获取用户需求信息*/
			char s1[10]="", s2[10]="";
			InputBox(s1, 10, _T("请输入起点(1-31)"), "最短路径查询", "1", 60, 10, FALSE);
			InputBox(s2, 10, _T("请输入终点(1-31)"), "最短路径查询", "7", 60, 10, FALSE);
			int v1,v2;
			sscanf_s(s1, "%d", &v1);					//类型转换（字符长类型->整形）	
			sscanf_s(s2, "%d", &v2);					//类型转换（字符长类型->整形）	

			if(strlen(s1) > 0 && strlen(s2)>0)			//已输入内容
				if(v1>0&&v1<32&&v1>0 && v1 < 32)		//内容合法
				{
					dist d;
					path p;
					floyd(g, d, p);						//floyd算法求d、p向量
					floydprint(g, d, p, v1 - 1, v2 - 1);//floyd算法求v1-1到v2-1点最短路径
					settextcolor(BLACK);				//设置文本颜色
					settextstyle(23, 0, _T("黑体"));	//设置文本样式
					/*界面输出*/
					char text[20];
					sprintf_s(text, sizeof(text), "路径长度：%d米", d[v1-1][v2-1]);
					outtextxy(1110, 440, text);
					makeline(g);

					upgradeGraph();						//界面更新
					/*Out数组初始化*/
					OutSize = 0;						
					for (int i = 0; i < M; ++i)Out[i] = 0;
				}
			continue;
			}
		}

		/*关节点查询*/
		else if (m.x >= 1100 && m.x <= 1220 && m.y >= 135 && m.y <= 165)									
		{
			setlinecolor(BLUE);							//设置线的颜色为蓝色
			rectangle(1100, 135, 1220, 165);			//设置矩形框
			if (m.uMsg == WM_LBUTTONDOWN)				//如果按下鼠标左键实现相应功能.
			{		
				LinkedGraph L;
				ljb_from_ljjz(&L, g);
				FindArticul(L);
				/*Out数组初始化*/
				OutSize = 0;
				for (int i = 0; i < M; ++i)Out[i] = 0;
				upgradeGraph();
				continue;
			}
		}

		/*查询任意两节点所有路径*/
		else if (m.x >= 1098 && m.x <= 1350 && m.y >= 210 && m.y <= 240)									
		{
			setlinecolor(BLUE);
			rectangle(1098, 210, 1350, 240);
			if (m.uMsg == WM_LBUTTONDOWN) {					//如果按下鼠标左键实现相应功能.
				char s1[10], s2[10];
				InputBox(s1, 10, _T("请输入起点"), "两景点间所有路径", "1", 60, 10, FALSE);
				InputBox(s2, 10, _T("请输入终点"), "两景点间所有路径", "7", 60, 10, FALSE);
				int v1, v2;
				sscanf_s(s1, "%d", &v1);
				sscanf_s(s2, "%d", &v2);
				if (strlen(s1) > 0 && strlen(s2) > 0)		//已输入内容
					if (v1 > 0 && v1 < 32 && v1>0 && v1 < 32)//内容合法
					{
					allpathsout(g, v1-1, v2-1);				//调用allpathsout函数
					/*Out数组初始化*/
					OutSize = 0;
					for (int i = 0; i < M; ++i)Out[i] = 0;

					upgradeGraph();							//界面更新
					continue;
					}
			}
		}

		/*最优路线规划*/
		else if (m.x >= 1098 && m.x <= 1360 && m.y >= 360 && m.y <= 390)							
		{
			int i,j=0;
			int want[M],flag=1,second;						//flag为输入对错标志位
			char temp[3]="";
			char s1[2*M]="";
			setlinecolor(BLUE);								//设置划线颜色
			rectangle(1098, 360, 1360, 390);				//矩形框	
			if (m.uMsg == WM_LBUTTONDOWN)					//如果按下鼠标左键实现相应功能.
			{
				/*弹框获取用户需求信息*/
				InputBox(s1, 2*M, _T("请输入您想参观的景点(中间用-分开)"), "最优路线规划", "1-2-3-4", 60, 10, FALSE);
				if(strlen(s1)>0)							//输入不为空
				{
					for (i = 0;s1[i]!='\0'; i++)			//求want[]
					{
						if (s1[i] == 45)	continue;		//遇到分隔符跳跃 
						temp[0] = s1[i];					//每个字符单独取出
						sscanf_s(temp, "%d", &want[j]);		//类型转化
						want[j]--;							//系统减1
						if (s1[i + 1] >= 48 && s1[i + 1] <= 57)//存在第两位数
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
					if (j > 0 && flag == 1)					//want数组界面与算法衔接
					{
						dist d;
						path p;
						floyd(g, d, p);
						BestpathOutput(g, want, j, d, p);	//调用BestpathOutput函数
						/*Out数组初始化*/
						OutSize = 0;
						for (int i = 0; i < M; ++i)Out[i] = 0;
						upgradeGraph();
					}
				}
				continue;
			}
		}

		/*结束按钮*/
		else if (m.x >= 1330 && m.x <= 1370 && m.y >= 740 && m.y <= 760)
		{
			setlinecolor(BLUE);
			rectangle(1330, 740, 1370, 760);
			if (m.uMsg == WM_LBUTTONDOWN) {
				closegraph();
				printf("结束 \n");
				return;
			}
		}

		/*景点信息查询按钮*/
		else if (m.x >= 200 && m.x <= 220 && m.y >= 606 && m.y <= 626)								
		{
			setlinecolor(BLUE);
			roundrect(200, 606, 220, 626, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("一道门_1.png"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图

				TCHAR s[] = _T("一道门为中北大学正门,正对着彭德怀大将军的雕像，位于七号楼的南面，可乘坐校园巴士，是进入中北大学的第一道门，");
				outtextxy(10, 20, s);

				TCHAR s2[] = _T("位于新兰路，来往车辆一般从此门进入。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 245 && m.x <= 265 && m.y >= 413 && m.y <= 433) {
			setlinecolor(BLUE);
			roundrect(245, 413, 265, 433, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("二道门_2.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("二道门靠近文瀛宿舍区与小白楼，作为宿舍楼与铁路的隔断至关重要，可在此处乘坐到校园巴士，有时可以在二道门");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("看见校园内的火车，是学校的一道独特的风景线。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 360 && m.x <= 380 && m.y >= 395 && m.y <= 415) {
			setlinecolor(BLUE);
			roundrect(360, 395, 380, 415, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("三道门_3.png"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("三道门靠近回字楼和铁路主题公园，以前有一条小吃街，这里停靠着以前的火车，是师生和来此处参观的游客拍照的");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("景点之一。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 554 && m.x <= 574 && m.y >= 350 && m.y <= 370) {
			setlinecolor(BLUE);
			roundrect(554, 350, 574, 370, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("四道门_4.png"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("四道门靠近行知广场，也正对着主楼，四道门相当于位于学校中心位置，有着地下通道可以通往中北酒店。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 680 && m.x <= 700 && m.y >= 355 && m.y <= 375) {
			setlinecolor(BLUE);
			roundrect(680, 355, 700, 375, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("五道门_5.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("五道门靠近学校原先的韵达快递站，也靠近笃学楼教学楼，以前聚集了小吃街的精华，衣食住行一应俱全，位属于东区。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 742 && m.x <= 762 && m.y >= 335 && m.y <= 355) {
			setlinecolor(BLUE);
			roundrect(742, 335, 762, 355, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("六道门_6.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("六道门靠近致学广场，也靠近六号楼，为从前小吃街的尽头，六道门因为修路有些已被拆除。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 872 && m.x <= 892 && m.y >= 313 && m.y <= 333) {
			setlinecolor(BLUE);
			roundrect(872, 313, 892, 333, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("七道门_7.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("七道门位于东区，附近有许多外卖店，也与上兰村相连，也是学校的最东边的一个门，也是校园巴士的终点。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 226 && m.x <= 246 && m.y >= 595 && m.y <= 615) {
			setlinecolor(BLUE);
			roundrect(226, 595, 246, 615, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("德怀楼_8.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学教学楼，也称德怀楼，位于校园西区一道门附近，南边伫立着彭德怀大将军的雕像，教学楼成倒v形，上课的");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("教室一般从东西两处的门进入。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 268 && m.x <= 288 && m.y >= 499 && m.y <= 519) {
			setlinecolor(BLUE);
			roundrect(268, 499, 288, 519, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("西区足球场_9.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("西区的足球场，面积大，七院足球队经常在这里训练，平时体育课选秀足球的同学也会在这里练习，靠近怡丁教工宿舍。");
				outtextxy(10, 20, s);

				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 206 && m.x <= 226 && m.y >= 503 && m.y <= 523) {
			setlinecolor(BLUE);
			roundrect(206, 503, 226, 523, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("校史馆_10.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学记录学校以往发展历史的地方，经常组织新生参观，里面有着在学校其他地区有着合作的公司和学校的照片，");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("丰富多彩，也有学生在此处为他们介绍校园发展。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 192 && m.x <= 212 && m.y >= 423 && m.y <= 443) {
			setlinecolor(BLUE);
			roundrect(192, 423, 212, 443, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("柏林园_11.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("提供休闲娱乐的户外场所，景色优美，依傍二龙山，内有柏树林，荷花池，喷泉，长廊，适合散心，");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("是太原市七所四星级公园之一。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 220 && m.x <= 240 && m.y >= 422 && m.y <= 442) {
			setlinecolor(BLUE);
			roundrect(220, 422, 240, 442, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("小白楼_12.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学心理健康咨询处，位于西区，日常与各班心理委员一起，关注学生心理健康，帮助学生排忧解难，谈天聊心。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 292 && m.x <= 312 && m.y >= 329 && m.y <= 349) {
			setlinecolor(BLUE);
			roundrect(292, 329, 312, 349, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("文瀛宿舍_13.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学学生宿舍楼，位于西区，住有各院的学生，也有学生科在此处设有办公地点。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 145 && m.x <= 165 && m.y >= 274 && m.y <= 294) {
			setlinecolor(BLUE);
			roundrect(145, 274, 165, 294, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("二龙山_14.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学校内的山峰景区，西临汾河，是太原的北大门，景色秀丽，山上鲜花遍布，二龙山旅游风景区是太原为数不多");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("的避暑胜地。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 262 && m.x <= 282 && m.y >= 247 && m.y <= 267) {
			setlinecolor(BLUE);
			roundrect(262, 247, 282, 267, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("科艺苑_15.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学举办大型活动的场所，位于西区，校学生会也在这里，在此处会设立讲座，报告会，校庆演出等。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 318 && m.x <= 338 && m.y >= 272 && m.y <= 292) {
			setlinecolor(BLUE);
			roundrect(318, 272, 338, 292, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("第四食堂_16.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学食堂之一，位于西区，位于文瀛宿舍附近，便于学生就餐，同时有着各类饭菜，适合不同口味的学生。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 423 && m.x <= 443 && m.y >= 271 && m.y <= 291) {
			setlinecolor(BLUE);
			roundrect(423, 271, 443, 291, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("主操场_17.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学最大操场，位于西区，拥有四百米的跑道和养护完好的绿色真实草地，是体育长跑和健康测试的地点，经常");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("遍布学生锻炼身体。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 364 && m.x <= 384 && m.y >= 122 && m.y <= 142) {
			setlinecolor(BLUE);
			roundrect(364, 122, 384, 142, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("工训中心_18.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("位于中北大学西区，其前身是学校成立的实习工厂，如今已是山西省实验教学示范中心，给学生提供创新工作平台。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 422 && m.x <= 442 && m.y >= 166 && m.y <= 186) {
			setlinecolor(BLUE);
			roundrect(422, 166, 442, 186, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("老年活动中心_19.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("位于中北大学西区，经常有退休了的老教授在这里锻炼身体和娱乐活动，里面有着乒乓球等设施。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 473 && m.x <= 493 && m.y >= 234 && m.y <= 254) {
			setlinecolor(BLUE);
			roundrect(473, 234, 493, 254, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("图书馆_20.png"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("位于中北大学校园中央，拥有丰厚的书籍，有快捷电子服务渠道，里面经常坐满来学习和借阅书籍的学生，在这里有");
				outtextxy(10, 20, s);
				TCHAR s2[] = _T("着浓厚的学习氛围。");
				outtextxy(10, 60, s2);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 439 && m.x <= 459 && m.y >= 112 && m.y <= 132) {
			setlinecolor(BLUE);
			roundrect(439, 112, 459, 132, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("游泳馆_21.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("位于中北大学东区，提供干净安全的游泳环境给上体育课和日常来游泳的师生。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 384 && m.x <= 404 && m.y >= 122 && m.y <= 142) {
			setlinecolor(BLUE);
			roundrect(384, 122, 404, 142, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("校医院_22.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("校位于中北大学临近汾河处，是一所二级乙等医院，日常接待了许多生病受伤的同学、老师、居民，给健康提供保障。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 524 && m.x <= 544 && m.y >= 312 && m.y <= 332) {
			setlinecolor(BLUE);
			roundrect(524, 312, 544, 332, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("行知广场_23.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("位于中北大学主楼的前方，每日会在这里升起国旗，在重大节日也会在这里举行仪式。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 584 && m.x <= 604 && m.y >= 166 && m.y <= 186) {
			setlinecolor(BLUE);
			roundrect(584, 166, 604, 186, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("9号楼_24.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北大学9号教学楼，位于东区，靠近东区篮球场，理学院主楼，大物实验也在这里上课。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 712 && m.x <= 732 && m.y >= 234 && m.y <= 254) {
			setlinecolor(BLUE);
			roundrect(712, 234, 732, 254, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("东区篮球场_25.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("东区的篮球场，学校各院的篮球比赛会在这里举行，日常这里有许多学生在这里运动。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 777 && m.x <= 797 && m.y >= 227 && m.y <= 247) {
			setlinecolor(BLUE);
			roundrect(777, 227, 797, 247, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("文韬宿舍_26.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("文韬宿舍：东区的宿舍楼之一，有着各院的学生在这里居住，靠近篮球场，经常有学生去锻炼。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 787 && m.x <= 807 && m.y >= 317 && m.y <= 337) {
			setlinecolor(BLUE);
			roundrect(787, 317, 807, 337, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("致学广场_27.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("致学广场：位于中北大学东区六号楼的前方，一个大面积广场，靠近文韬宿舍区。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 900 && m.x <= 920 && m.y >= 336 && m.y <= 356) {
			setlinecolor(BLUE);
			roundrect(900, 336, 920, 356, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("田园餐厅_28.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("田园餐厅：东区的食堂之一，靠近文澜宿舍，给此处的学生提供便捷的吃饭场所。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 948 && m.x <= 968 && m.y >= 316 && m.y <= 336) {
			setlinecolor(BLUE);
			roundrect(948, 316, 968, 336, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("文澜宿舍_29.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("文澜公寓：最东面的学生宿舍，需要通过地下通道到达，相对于其他宿舍区，此处相对而言较为偏僻。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 587 && m.x <= 607 && m.y >= 474 && m.y <= 494) {
			setlinecolor(BLUE);
			roundrect(587, 474, 607, 494, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("中北酒店_30.png"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("中北酒店：位于中北大学校区内，靠近汾河和二龙山，风景优美，二层有着会议中心，接待来此处交流的老师等。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
		else if (m.x >= 613 && m.x <= 633 && m.y >= 480 && m.y <= 500) {
			setlinecolor(BLUE);
			roundrect(613, 480, 633, 500, 10, 10);
			if (m.uMsg == WM_LBUTTONDOWN) //如果按下鼠标左键实现相应功能.
			{
				loadimage(&picture_1, _T("怡丁教工宿舍_31.jpg"), 1080, 760);
				putimage(0, 0, &picture_1);//显示地图
				TCHAR s[] = _T("怡丁教工宿舍：教职工宿舍区之一，环境清静，靠近百业生活广场，便于进行购物和吃饭。");
				outtextxy(10, 20, s);
				system("pause");
				initgraph();
				continue;
			}
		}
	}
	}

