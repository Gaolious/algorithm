//
// Created by ajava on 24. 3. 25.
//
/*
 *
32657437403857
30064159217480
94728015869243
47132874683053
26315793710681
95096980359461
58702416295329
62415243218279
 * */

#include "gen.h"
#include "eval.h"

#ifndef CLION_EXCHANGE_H
#define CLION_EXCHANGE_H
struct SwapData {
    char p1, p2, p3;
    Gen ans;
    SwapData(char a, char b, char c): p1(a), p2(b), p3(c) {}
    void run(Gen sol) {
        int y1, x1, y2, x2, y3, x3;

        int i, j, k;

        auto ep = EvalPartial();
        ep.updateEval(sol);
        ans = sol ;

        for ( i = 0 ; i < X*Y ; i ++ ) {
            y1 = i / X, x1 = i % X ;
            sol.G[y1][x1] = p1;
            ep.updateEval(sol, y1, x1, y1, x1);

            for (j = i+1; j < X*Y; j++) {
                y2 = j / X, x2 = j % X ;
                sol.G[y2][x2] = p2;
                ep.updateEval(sol, y2, x2, y2, x2);

                for (k = j+1; k < X*Y; k++) {
                    y3 = k / X, x3 = k % X ;
                    sol.G[y3][x3] = p3;
                    ep.updateEval(sol, y3, x3, y3, x3);
                    if ( ans < sol ) {
                        ans = sol;
                    }
                }
            }
        }
    }
};
#endif //CLION_EXCHANGE_H
