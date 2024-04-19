//
// Created by ajava on 24. 3. 24.
//
#include "common.h"
#include "rd.h"
#include "gen.h"

#ifndef CLION_EVAL_H
#define CLION_EVAL_H

//
//struct EvalCache {
//    char C[ 8 ][ 14 ][ 10 ]{};
//    vector<pii> numPos[10];
//    char Flag[10000+1]{};
//    int Count[8][14]{};
//
//    bool F(Gen &curr, int y, int x, int digit, int n) {
//        if ( !n ) return true;
//        auto &ret = C[y][x][digit];
//        if ( ~ret ) return ret;
//
//        for ( int d = 0 ; d < 8 ; d ++ ) {
//            int ty = y + dy[d];
//            int tx = x + dx[d];
//            if (!valid(ty,tx)) continue;
//            if ( curr.G[ ty ][ tx ] != n%10 ) continue;
//            if ( F( curr, ty, tx, digit + 1, n/10 ) ) {
//                Count[ty][tx]++;
//                ret = 1;
//                return ret;
//            }
//        }
//        ret = 0;
//        return ret;
//    }
//
//    bool check(Gen &curr, int n, int &digit) {
//        int reverseN = 0;
//        bool canUseCache = false;
//        if ( n >= digit * 10 ) digit *= 10;
//
//        for ( int i = n ; i ; i /=10 ) reverseN = reverseN * 10 + (i%10);
//        if ( digit <= n && n < digit * 10 && digit <= reverseN && reverseN < digit * 10 ) canUseCache = true;
//
//        if ( canUseCache && n <= 10000 && Flag[n] != -1 ) {
//            return Flag[n];
//        }
//        memset(C, -1, sizeof(C));
//        for (auto [y,x]: numPos[ n%10 ] )
//            if (F(curr, y, x, 0, n/10)) {
//                if ( canUseCache && n <= 10000 && Flag[n] == -1 ) {
//                    Count[y][x]++;
//                    Flag[reverseN] = 1;
//                    Flag[n] = 1;
//                }
//                return true;
//            }
//        if ( canUseCache && n <= 10000 && Flag[n] == -1 ) {
//            Flag[reverseN] = 0;
//            Flag[n] = 0;
//        }
//        return false;
//    }
//
//    void eval(Gen &curr) {
//        int n ;
//        int digit = 1;
//        for ( n = 1 ; check(curr, n, digit) ; n ++ );
//        curr.totalCount = curr.maxScore = n - 1;
//
//        for ( n++ ; n < 10000 ; n ++ )
//            if (check(curr, n, digit)) curr.totalCount++;
//
//        for ( n = 0 ; n < 10 ; n ++ ) numPos[ n ].clear();
//    }
//    void init(Gen &curr ) {
//        int i, j;
//        for ( i = 0 ; i < 10 ; i ++ )
//            numPos[ i ].clear();
//
//        for ( i = 0 ; i < Y ; i ++ )
//            for ( j = 0 ; j < X ; j ++ )
//                numPos[ (int)curr.G[i][j] ].emplace_back(i, j);
//
//        memset(Flag, -1, sizeof(Flag));
//    }
//    void dumpCount() {
//        cout << "Count : \n";
//        for ( int y = 0 ; y < Y ; y ++ ) {
//            for ( int x = 0 ; x < X ; x ++ ) {
//                cout << setw(3) << Count[y][x] << ' ' ;
//            }
//            cout << '\n';
//        }
//    }
//};


struct EvalPartial {
    vector<int> Numbers[Y][X][4];
    vector<int> Count;

    EvalPartial() {
        Count = vector<int>(10000, 0);
    }
    void clear() {
        for (auto &n: Count) n = 0;
        for ( int y = 0 ; y < Y ; y ++ )
            for ( int x = 0 ; x < X ; x ++ )
                for (int k = 0 ; k < 4 ; k ++ )
                    Numbers[y][x][k].clear();
    }
    pii updateEval(Gen &curr, int sy=0, int sx=0, int ey=Y-1, int ex=X-1) {
        int y, x, k, digit;
        int left, right, top, bottom, d;
        for (k = 0; k < 4; k++) {
            left = max(0, sx - k);
            right = min(X - 1, ex + k);
            top = max(0, sy - k);
            bottom = min(Y - 1, ey + k);
            for (y = top; y <= bottom; y++) {
                for (x = left; x <= right; x++) {
                    for (auto n: Numbers[y][x][k]) {
                        Count[n]--;
                        assert (Count[n] >= 0);
                    }
                    Numbers[y][x][k].clear();
                }
            }
        }

        for ( k = 0, digit=1; k < 4 ; k ++, digit*=10 ) {
            left = max(0, sx - k);
            right = min(X - 1, ex + k);
            top = max(0, sy - k);
            bottom = min(Y - 1, ey + k);

            for ( y = top ; y <= bottom ; y ++ ) {
                for ( x = left ; x <= right ; x ++ ) {
                    if ( !Numbers[y][x][k].empty() ) continue;
                    if ( k == 0 ) {
                        Numbers[y][x][k].push_back(curr.G[y][x]);
                        continue;
                    }
                    for (d = 0; d < 8; d++) {
                        int ty = y + dy[d];
                        int tx = x + dx[d];
                        if (!valid(ty, tx)) continue;
                        for (auto n: Numbers[ty][tx][k - 1])
                            Numbers[y][x][k].push_back(curr.G[y][x] * digit + n);
                    }
                }
            }
        }
        for ( k = 0 ; k < 4 ; k ++) {
            left = max(0, sx - k);
            right = min(X - 1, ex + k);
            top = max(0, sy - k);
            bottom = min(Y - 1, ey + k);
            for (y = top; y <= bottom; y++)
                for (x = left; x <= right; x++)
                    for (auto n: Numbers[y][x][k])
                        Count[n]++;
        }

        int total=0, best = -1 ;
        for (int i = 1 ; i < 10000 ; i ++ ) {
            if ( Count[i] == 0 && best < 0 ) best =  i-1;
            if ( Count[i] ) total++;
        }
        curr.maxScore = best;
        curr.totalCount = total;

        if ( curr.maxScore >= 8140 ) {
            cout << "Found over 8140 points\n";
            curr.dump();
            curr.writeToFile("8140.txt");
        }

        return {best, total};
    }
    unordered_set<int> getSet() {
        unordered_set ret  = unordered_set<int>();
        for (int i = 1 ; i < 10000 ; i ++ ) {
            if ( Count[i] ) ret.insert(i);
        }
        return ret;
    }

};
#endif //CLION_EVAL_H
