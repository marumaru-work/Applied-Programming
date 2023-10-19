// 学生番号：I21Ixxx	氏名：理大　太郎	作成日：2021/99/99
// 内容：BMIを求めるプログラム．(関数を利用するように変更中)
// 入力：身長(cm)：整数型，体重(Kg)：実数型
// 出力：BMI（小数以下2桁），肥満度（https://keisan.casio.jp/exec/system/1161228732　参照）
// 1.人数を入力して，人数分繰り返す．
// 2.肥満度を変数として扱う．痩せ：0，普通：1，肥満1：2，肥満2：3，肥満3：4，肥満4：5　とする．
// 3.肥満度を計算する部分を関数とした．
// 4.BMIを計算する部分を関数とした．
#include <stdio.h>

/* 追加:プロトタイプ宣言 */
double CalcBMI(int height, double weight);
int CalcFatness(double bmi);
void PrintOut(int fatness, int height, double weight, double bmi);

int main(void)
{
	int height, fatness, i, cnt;
	double weight, bmi;

	printf("人数：");
	scanf("%d", &cnt);
	for(i = 0; i < cnt; i++)
	{
		printf("身長(cm)：");
		scanf("%d",  &height);
		printf("体重(Kg)：");
		scanf("%lf", &weight);

		bmi = CalcBMI(height, weight);
		fatness = CalcFatness(bmi);
		PrintOut(fatness, height, weight, bmi);
	}
	return(0);
}

//追加：BMIを計算する
//入力：身長(整数:cm)，体重(実数:Kg)
//戻り値：BMI(実数)
double CalcBMI(int height, double weight)
{
	double dh /*= height / 100.0*/, bmi;

	dh = height / 100.0;      // 身長 (cm → m)
	bmi = weight / (dh * dh); // BMI ＝ 体重kg / (身長m)^2

	return (bmi);
}

//肥満度を計算する．最初のコメント内のサイトの値で評価する
//入力：bmi(実数)
//戻り値：肥満度(整数)
int CalcFatness(double bmi)
{
	int fatness;

	if (bmi < 18.5)
	{
		fatness = 0;
	}
	else if (bmi < 25.0)
	{
		fatness = 1;
	}
	else if (bmi < 30.0)
	{
		fatness = 2;
	}
	else if (bmi < 35.0)
	{
		fatness = 3;
	}
	else if (bmi < 40.0)
	{
		fatness = 4;
	}
	else
	{
		fatness = 5;
	}

	return (fatness);
}

void PrintOut(int fatness, int height, double weight, double bmi)
{
	printf("身長：%3dcm, 体重：%6.2lfKg, BMI：%5.2lf\t", height, weight, bmi);
	switch(fatness)
	{
		case 0: printf("低体重");    break;
		case 1: printf("普通体重");  break;
		case 2: printf("肥満(1度)"); break;
		case 3: printf("肥満(2度)"); break;
		case 4: printf("肥満(3度)"); break;
		case 5: printf("肥満(4度)");
	}
	printf("\n");
}

/* 実行結果
*/
