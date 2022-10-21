#include <stdio.h>
#include <vector>
using namespace std;

int R, C;
int M;
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,-1,1,0,0 };
vector<int> map[105][105];
int ans = 0;

struct shark
{
	int live = 0;  //상어가 죽었는지 살았는지
	int r, c, s, d, z;
};

shark Shark[10005];  // 상어구조체 배열
int main()
{
	scanf("%d %d %d", &R, &C, &M);
	for (int i1 = 1; i1 <= M; i1++)
	{
		Shark[i1].live = 1;
		scanf(" %d %d %d %d %d", &Shark[i1].r, &Shark[i1].c, &Shark[i1].s, &Shark[i1].d, &Shark[i1].z);
		map[Shark[i1].r][Shark[i1].c].push_back(i1);

		if (Shark[i1].d == 1 || Shark[i1].d == 2)
		{
			if (Shark[i1].s % (2 * R - 2) == 0 && Shark[i1].s != 0 && (Shark[i1].r==1 || Shark[i1].r == R))
				Shark[i1].s = 2 * R - 2;
			else
				Shark[i1].s %= (2 * R - 2);
		}
		else
		{
			if (Shark[i1].s % (2 * C - 2) == 0 && Shark[i1].s != 0 && (Shark[i1].c == 1 || Shark[i1].c == C))
				Shark[i1].s = 2 * C - 2;
			else
				Shark[i1].s %= (2 * C - 2);
		}
	}


	for (int i2 = 1; i2 <= C; i2++)  // 1단계 사람 움직이기
	{
		for (int j2 = 1; j2 <= R; j2++)  // 2단계 상어잡기
			if (!map[j2][i2].empty())
			{
				int num = map[j2][i2].front();
				map[j2][i2].clear();
				Shark[num].live = 0;
				ans += Shark[num].z;
				break;
			}

		for (int a = 1; a <= M; a++)  // 3단계 상어 움직이기
			if (Shark[a].live == 1&& map[Shark[a].r][Shark[a].c].size()>0)
			{
				int now_r = Shark[a].r;
				int now_c = Shark[a].c;
				map[now_r][now_c].clear();

				now_r += dy[Shark[a].d] * Shark[a].s;
				now_c += dx[Shark[a].d] * Shark[a].s;


				// 상어가 벽보고 있고 속력이 2*R-2 또는 2C-2이면 항상 그자리다
				if ( (Shark[a].s == 2 * R - 2 && ((Shark[a].d == 1 && Shark[a].r == 1) || (Shark[a].d == 2 && Shark[a].r == R)))
					|| (Shark[a].s == 2 * C - 2 && ((Shark[a].d == 3 && Shark[a].c == C) || (Shark[a].d == 4 && Shark[a].r == 1))))
					Shark[a].s = 0;

				
				else
				{
                    // 상하로 움직일때
					if (Shark[a].d == 1 || Shark[a].d == 2)
					{
						if (-2 * R + 2 <= now_r && now_r < 0)
							Shark[a].r = now_r + (2 * R - 2);
						if (-R + 2 <= now_r && now_r <= 0 && Shark[a].s != 0)
						{
							Shark[a].d = 2;
							Shark[a].r = 2 - now_r;
						}
						if (0 < now_r)
							Shark[a].r = now_r;
						if (R < now_r)
						{
							Shark[a].d = 1;
							Shark[a].r = 2 * R - now_r;
						}
						if (2 * R <= now_r)
						{
							Shark[a].d = 2;
							Shark[a].r = now_r % (2 * R - 2);
						}
					}

					//좌우로 움직일 때
					else
					{
						if (-2 * C + 2 <= now_c && now_c < 0)
							Shark[a].c = now_c + (2 * C - 2);
						if (-C + 2 <= now_c && now_c <= 0 && Shark[a].s != 0)
						{
							Shark[a].d = 3;
							Shark[a].c = 2 - now_c;
						}
						if (0 < now_c)
							Shark[a].c = now_c;
						if (C < now_c)
						{
							Shark[a].d = 4;
							Shark[a].c = 2 * C - now_c;
						}
						if (2 * C <= now_c)
						{
							Shark[a].d = 3;
							Shark[a].c = now_c % (2 * C - 2);
						}
					}
				}
				map[Shark[a].r][Shark[a].c].push_back(a);
			}
		
		for (int i3 = 1; i3 <= R; i3++)  // 같은 공간 상어끼리 잡아먹기
			for (int j3 = 1; j3 <= C; j3++)
				if (map[i3][j3].size() > 1)
				{
					int max = 0;
					int who;
					for (int k3 = 0; k3 < map[i3][j3].size(); k3++)
					{
						int now = map[i3][j3][k3];
						if (max < Shark[now].z)
						{
							max = Shark[now].z;
							who = now;
						}
					}
					for (int b = 0; b < map[i3][j3].size(); b++)
					{
						if (map[i3][j3][b] == who)
						{
							continue;
						}
						Shark[map[i3][j3][b]].live = 0;
					}
					map[i3][j3].clear();
					map[i3][j3].push_back(who);
				}
	}
	printf("%d\n", ans);
}
