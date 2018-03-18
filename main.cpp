#include<iostream>
#include<algorithm>
#define maxLevel 100
using namespace std;
int rewardSum[maxLevel][maxLevel];
int reward[maxLevel][maxLevel];

void initReward()//��ʼ��
{
	for (int i = 0; i < maxLevel; i++)
	{
		for (int j = 0; j < maxLevel; j++)
		{
			rewardSum[i][j] = -1;
		}
	}
}

int calcRewardSum(int level,int num)//�����level��ĵ�num������Ľ�ȯ��
{
	if (rewardSum[level - 1][num] != -1)//�Ѿ������  ֱ�ӷ���
	{
		return rewardSum[level - 1][num];
	}
	else
	{
		if (1 == level)  //��һ��  ֱ�Ӽ���
		{
			rewardSum[level - 1][num] = reward[level - 1][num];
		}
		else
		{
			if (num > 0 && num < level - 1) //�м�ķ���  �����ֿ���
			{
				rewardSum[level - 1][num] = max(calcRewardSum(level - 1, num - 1) + reward[level - 1][num], calcRewardSum(level - 1, num) + reward[level - 1][num]);
			}
			else if (num == 0)//����ߵķ���  ֻ��һ�ֿ���
			{
				rewardSum[level - 1][num] = calcRewardSum(level - 1, num) + reward[level-1][num];
			}
			else if (num == level - 1)//���ұߵķ���  ֻ��һ�ֿ���
			{
				rewardSum[level - 1][num] = calcRewardSum(level - 1, num - 1) + reward[level - 1][num];
			}
		}
		return rewardSum[level - 1][num];
	}
}
int main()
{
	int level,ans=-1,temp;
	cin >> level;  //����
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j <= i; j++) //����ÿ��ÿ������Ľ�ȯ
		{
			cin >> reward[i][j];
		}
	}

	initReward();//��ʼ��ÿ�����佱ȯ��

	for (int i = 0; i < level; i++) //�������һ��ÿ������Ľ�ȯ�� ���ֵΪ���
	{
		temp = calcRewardSum(level, i);
		if (ans < temp)
		{
			ans = temp;
		}
	}

	cout << ans;
	system("pause");
	return 0;
}