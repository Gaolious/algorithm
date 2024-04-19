//
// Created by ajava on 24. 3. 25.
//
#include "gen.h"
#include "eval.h"

#ifndef CLION_ENHANCE_H
#define CLION_ENHANCE_H

struct EnhanceData { // Y:3, X:4
    int y;
    int x;
    Gen ans ;
    EnhanceData(int sy, int sx) : y(sy), x(sx) {}
    void run(Gen sol) {
        int k;

        auto ep = EvalPartial();
        ep.updateEval(sol);
        ans = sol;

        for ( k = 0 ; k < 1000000 ; k ++ ) {
            sol.G[y+0][x+0] = (k / 100000) % 10;
            sol.G[y+1][x+0] = (k / 10000) % 10;
            sol.G[y+2][x+0] = (k / 1000) % 10;
            sol.G[y+0][x+2] = (k / 100) % 10;
            sol.G[y+1][x+2] = (k / 10) % 10;
            sol.G[y+2][x+2] = (k / 1) % 10;

            ep.updateEval(sol, y, x, y+2, x+2);
            if ( ans < sol )
                ans = sol;
        }

        for ( k = 0 ; k < 1000000 ; k ++ ) {
            sol.G[y+0][x+0] = (k / 100000) % 10;
            sol.G[y+0][x+1] = (k / 10000) % 10;
            sol.G[y+0][x+2] = (k / 1000) % 10;
            sol.G[y+2][x+0] = (k / 100) % 10;
            sol.G[y+2][x+1] = (k / 10) % 10;
            sol.G[y+2][x+2] = (k / 1) % 10;

            ep.updateEval(sol, y, x, y+2, x+2);
            if ( ans < sol )
                ans = sol;
        }

        for ( k = 0 ; k < 100000 ; k ++ ) {
            sol.G[y+0][x+0] = (k / 10000) % 10;
            sol.G[y+0][x+2] = (k / 1000) % 10;
            sol.G[y+2][x+0] = (k / 100) % 10;
            sol.G[y+2][x+2] = (k / 10) % 10;
            sol.G[y+1][x+1] = (k / 1) % 10;

            ep.updateEval(sol, y, x, y+2, x+2);
            if ( ans < sol )
                ans = sol;
        }
    }
};

#endif //CLION_ENHANCE_H
