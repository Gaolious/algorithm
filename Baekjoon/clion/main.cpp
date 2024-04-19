#include <bits/stdc++.h>
#include <execution>
#include <thread>

#include "rd.h"
#include "gen.h"
#include "eval.h"
#include "sa.h"
#include "col.h"
#include "enhance.h"
#include "exchange.h"
#include "dlas.h"

bool Enhance(Gen &best, Gen &sol) {
    // x x x x x x x x
    // * x * x x x x x
    // * x * x x x x x
    // * x * x x x x x
    // x x x x x x x x
    bool ret;
    vector<EnhanceData> data_list;
    int i, j ;
    for ( i = 0 ; i < Y - 2 ; i ++ )
        for ( j = 0 ; j < X - 2 ; j ++ )
            data_list.emplace_back(i, j);

    std::for_each(std::execution::par_unseq, data_list.begin(), data_list.end(), [&sol](EnhanceData &data) {
        data.run(sol);
    });

    ret = false ;
    for (auto &g: data_list) {
        if ( sol < g.ans ) {
            sol = g.ans ;
            ret = true;
        }
    }
    return ret;
}

void GetScore() {
    // input.txt 파일에서 읽고 점수 계산
    auto ep = EvalPartial();
    Gen sol;
    sol.readFromFile("input.txt");
    ep.updateEval(sol);
    sol.dump();
}


bool Swap(Gen &best, Gen &sol) {
    vector<SwapData> data_list;
    int i, j, k ;
    for ( i = 0 ; i < 10 ; i ++ )
        for (j = 0 ; j < 10 ; j ++ )
            for (k = 0 ; k < 10 ; k ++ )
            data_list.emplace_back(i, j, k);

    std::for_each(std::execution::par_unseq, data_list.begin(), data_list.end(), [&sol](SwapData &data) {
        data.run(sol);
    });

    bool ret = false ;
    for (auto &g: data_list) {
        if ( sol < g.ans ) {
            sol = g.ans ;
            ret = true;
        }
    }
    return ret;
}

bool AllForCol(Gen &best, Gen &sol, int colOffset) {
    vector<UpdateCol> data_list;
    int i ;
    bool ret = false ;
    for ( i = 0 ; i < X ; i ++ )
        data_list.emplace_back(i, colOffset, R.GetInt(0,9));

    std::for_each(std::execution::par_unseq, data_list.begin(), data_list.end(), [&sol](UpdateCol &data) {
        data.run(sol);
    });
    for (auto &g: data_list) {
        if ( sol < g.ans ) {
            sol = g.ans ;
            ret = true ;
        }
    }
    return ret;
}

bool run(const char *command, Gen &best, Gen &sol) {
    cout << "Started : " << command << '\n';
    EvalPartial().updateEval(best);
    EvalPartial().updateEval(sol);
    bool ret = false ;
    auto s = chrono::steady_clock::now();

    if ( strcmp(command, "score") == 0 ) {
        GetScore();
    }
    else if ( strcmp( command, "enhance") == 0 ) {
        ret = Enhance(best, sol);
    }
    else if ( strcmp( command, "swap") == 0 ) {
        ret = Swap(best, sol);
    }
    else if ( strcmp( command, "col") == 0 ) {
        ret = AllForCol(best, sol, R.GetInt(0,13));
    }
    else if ( strcmp( command, "col0") == 0 ) {
        AllForCol(best, sol, 0);
    }
    else if ( strcmp( command, "col1") == 0 ) {
        AllForCol(best, sol, 1);
    }
    else if ( strcmp( command, "col2") == 0 ) {
        AllForCol(best, sol, 2);
    }
    else if ( strcmp( command, "col3") == 0 ) {
        AllForCol(best, sol, 3);
    }
    else if ( strcmp( command, "col4") == 0 ) {
        AllForCol(best, sol, 4);
    }
    else if ( strcmp( command, "col5") == 0 ) {
        AllForCol(best, sol, 5);
    }
    else if ( strcmp( command, "col6") == 0 ) {
        AllForCol(best, sol, 6);
    }
    else if ( strcmp( command, "col7") == 0 ) {
        AllForCol(best, sol, 7);
    }
    else if ( strcmp( command, "col8") == 0 ) {
        AllForCol(best, sol, 8);
    }
    else if ( strcmp( command, "col9") == 0 ) {
        AllForCol(best, sol, 9);
    }
    else if ( strcmp( command, "col10") == 0 ) {
        AllForCol(best, sol, 10);
    }
    else if ( strcmp( command, "col11") == 0 ) {
        AllForCol(best, sol, 11);
    }
    else if ( strcmp( command, "col12") == 0 ) {
        AllForCol(best, sol, 12);
    }
    else if ( strcmp( command, "col13") == 0 ) {
        AllForCol(best, sol, 13);
    }
    else if ( strcmp( command, "sa") == 0 ) {
        SA sa;
        sa.genUniqueNumbers();
        sa.InitGen(sol);
        sa.do_iteration(best, sol);
    }

    auto e = chrono::steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(e-s);
    cout << "Estimated Time : " << elapsed.count() / 1000.0 << " seconds.\n";

    return ret;
}
int main(int argc, char *argv[]) {
    Gen sol, best;
    sol.readFromFile("current.txt");
    best.readFromFile("best.txt");

    bool updated = false;
    do {
//        if ( !updated ) {
//            cout << "Set to Random Sequence \n";
//            sol.setRandom();
//        }
//        updated = false;

//        run("sa", best, sol);
        updated = run("col", best, sol) || updated;
        updated = run("enhance", best, sol) || updated;
        updated = run("swap", best, sol) || updated;
        cout << "[ Best ]\n"; best.dump();
        cout << "[ Curr ]\n"; sol.dump();

        best.writeToFile("best.txt");
        sol.writeToFile("current.txt");
    } while ( false );

    return 0;
}