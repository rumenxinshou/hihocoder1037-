#include<iostream>
#include<algorithm>
#define maxLevel 100
using namespace std;
int rewardSum[maxLevel][maxLevel];
int reward[maxLevel][maxLevel];

void initReward()//初始化
{
	for (int i = 0; i < maxLevel; i++)
	{
		for (int j = 0; j < maxLevel; j++)
		{
			rewardSum[i][j] = -1;
		}
	}
}

int calcRewardSum(int level,int num)//计算第level层的第num个房间的奖券和
{
	if (rewardSum[level - 1][num] != -1)//已经计算过  直接返回
	{
		return rewardSum[level - 1][num];
	}
	else
	{
		if (1 == level)  //第一层  直接计算
		{
			rewardSum[level - 1][num] = reward[level - 1][num];
		}
		else
		{
			if (num > 0 && num < level - 1) //中间的房间  有两种可能
			{
				rewardSum[level - 1][num] = max(calcRewardSum(level - 1, num - 1) + reward[level - 1][num], calcRewardSum(level - 1, num) + reward[level - 1][num]);
			}
			else if (num == 0)//最左边的房间  只有一种可能
			{
				rewardSum[level - 1][num] = calcRewardSum(level - 1, num) + reward[level-1][num];
			}
			else if (num == level - 1)//最右边的房间  只有一种可能
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
	cin >> level;  //层数
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j <= i; j++) //输入每层每个房间的奖券
		{
			cin >> reward[i][j];
		}
	}

	initReward();//初始化每个房间奖券和

	for (int i = 0; i < level; i++) //计算最后一层每个房间的奖券和 最大值为结果
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