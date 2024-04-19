//
// Created by ajava on 24. 3. 25.
//
#include "gen.h"
#include "eval.h"

#ifndef CLION_COL_H
#define CLION_COL_H

struct UpdateCol {
    int firstCol;
    int firstNum;
    int addCol;

    Gen ans;
    EvalPartial ep ;

    UpdateCol(int startIndex, int addCol, int startNum=-1) : firstCol(startIndex), firstNum(startNum), addCol(addCol) {}

    void recur(Gen &sol, int row, int col){
        if ( row >= Y ) {
            if ( ans < sol ) {
                ans = sol;
            }
            return ;
        }
        col = (col + addCol) % X ;

        for ( int n = 0 ; n < 10 ; n ++ ) {
            sol.G[row][col] = n;
            ep.updateEval(sol, row, col, row, col);
            recur(sol, row+1, col);
        }
    }

    void run(Gen sol) {
        ep.updateEval(sol);
        ans = sol ;

        int s = 0 , e = 9 ;
        if ( firstNum >= 0 ) {
            s = e = firstNum;
        }
        for ( int n = s ; n <= e ; n ++ ) {
            sol.G[0][firstCol] = n;
            ep.updateEval(sol, 0, firstCol, 0, firstCol);
            recur(sol, 1, firstCol);
        }
    }
};

#endif //CLION_COL_H
