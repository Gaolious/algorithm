#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int R, C, M;

struct Shark {
    int y, x;
    int dy;
    int dx;
    int speed;
    int size;
    int nx, ny;
    Shark *prev, *next;
    Shark() {
        prev = next = nullptr;
    }
    void update_next_point() {
        nx = x + ( (speed) % ( C*2 - 2 ) ) * dx ;
        ny = y + ( (speed) % ( R*2 - 2 ) ) * dy ;
        while ( nx <= 0 || nx > C || ny <= 0 || ny > R ) {
            if ( nx <= 1 ) nx = 2 - nx, dx=-dx;
            if ( ny <= 1 ) ny = 2 - ny, dy=-dy;
            if ( nx >= C ) nx = 2*C - nx, dx=-dx;
            if ( ny >= R ) ny = 2*R - ny, dy=-dy;
        }
    }
    Shark *remove() {
        Shark *pp = prev, *nn = next ;
        if ( pp ) pp->next = nn;
        if ( nn ) nn->prev = pp;
        return pp;
    }
};
vector<Shark> shark;
Shark *grid[101][101];

void process() {
    fastio;
    int i, j ;
    int human;
    ll ret ;

    Shark root ;
    cin >> R >> C >> M ;
    shark.resize(M+1);

    root.next = &(shark[0]);
    shark[0].prev = &root;
    for ( i = 0 ; i < M ; i ++ )
    {
        auto &s = shark[i];
        cin >> s.y >> s.x >> s.speed >> j >> s.size ;
        if ( j == 1 ) s.dy = -1;
        else if ( j == 2 ) s.dy = 1;
        else if ( j == 3 ) s.dx = 1;
        else s.dx = -1;
        if ( i > 0 ) s.prev = &(shark[i-1]);
        if ( i < M-1 ) s.next = &(shark[i+1]);
    }

    ret = 0;

    for ( human = 1 ; human <= C ; human ++ ) {
        Shark *willRemove = nullptr;
        for (auto curr = root.next; curr; curr = curr->next) {
            if (curr->x == human) {
                if (willRemove == nullptr || willRemove->y > curr->y)
                    willRemove = curr;
            }

        }
        if (willRemove) {
            ret += willRemove->size;
            willRemove->remove();
        }

        memset(grid, 0, sizeof(grid));
        for (auto curr = root.next; curr; curr = curr->next) {
            curr->update_next_point();
            auto prev = grid[curr->ny][curr->nx];
            if (prev) {
                if (prev->size > curr->size) {
                    curr = curr->remove();
                    continue;
                } else {
                    prev->remove();
                }
            }
            curr->y = curr->ny;
            curr->x = curr->nx;
            grid[curr->y][curr->x] = curr;
        }
//        for (auto curr = root.next; curr; curr = curr->next)
//            grid[curr->y][curr->x] = nullptr;
    }

    cout << ret << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


