//
// Created by ajava on 24. 3. 24.
//

#include "rd.h"
#include "gen.h"
#include "eval.h"

#ifndef CLION_SA_H
#define CLION_SA_H

struct SA {
    vector<Gen> genList ;
//    vector<EvalCache> cacheList;
    vector<ll> UniqueNumber;

    const int MaxIter = 50;

    void genUniqueNumbers() {
        vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        do {
            ll n = 0;
            for (auto t: A)
                n = n * 10 + t;
            UniqueNumber.push_back(n);
        } while(next_permutation(A.begin(), A.end()));
    }

    void InitGen(Gen curr) {
        int i;
        double d = 0.9 ;
        double T = 20;

        genList.clear();
        curr.maxIter = 2;
        curr.d = d;
        curr.T = T;
        curr.setRandom();

        for ( i = 0 ; i < 10 ; i ++ ) {
            Gen tmp = curr;
            tmp.SetReverse();
            genList.push_back(tmp);
        }
        for ( i = 0 ; i < 10 ; i ++ ) {
            Gen tmp = curr;
            tmp.SetRandomOutline();
            genList.push_back(tmp);
        }
    }

    void SwapElement(Gen &curr) {
        Gen ret = curr;
        auto ep = EvalPartial();
        vector<pii> Num[10];

        ep.updateEval(curr);

        int i, j;
        for ( i = 0 ; i < Y ; i ++ )
            for ( j = 0 ; j < X ; j ++ )
                Num[ (int)curr.G[i][j] ].emplace_back(i, j);

        for ( i = 0 ; i < 10 ; i ++ ) {
            for ( j = i+1 ; j < 10 ; j ++ ) {
                Gen tmp = curr ;
                for(auto [y,x] :Num[i] ) tmp.G[y][x] = j;
                for(auto [y,x] :Num[j] ) tmp.G[y][x] = i;

                ep.updateEval(tmp);

                if ( ret < tmp ) {
                    ret = tmp;
                }
            }
        }
        curr = ret;
    }

    void SwapCol( Gen &curr ) {
        Gen ret = curr;
        auto ep = EvalPartial();

        int i, j, k;
        for ( i = 0 ; i < X ; i ++ ) {
            for ( j = i+1 ; j < X ; j ++ ) {
                Gen tmp = curr ;
                for ( k = 0 ; k < Y ; k ++ ) swap(tmp.G[k][i], tmp.G[k][j]);
                ep.updateEval(tmp);

                if ( ret < tmp )
                    ret = tmp;
            }
        }
        curr = ret;
    }

    void SwapRow( Gen &curr ) {
        Gen ret = curr;
        auto ep = EvalPartial();
        int i, j, k;
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = i+1 ; j < Y ; j ++ ) {
                Gen tmp = curr ;
                for ( k = 0 ; k < X ; k ++ ) swap(tmp.G[i][k], tmp.G[j][k]);
                ep.updateEval(tmp);

                if ( ret < tmp )
                    ret = tmp;
            }
        }
        curr = ret;
    }

    void run(Gen &best, Gen &curr) {

        double delta;
        int i;
        double T = curr.T;
        double d = curr.d ;
        int y, x, n;
        auto ep = EvalPartial();
        ep.updateEval(curr);

        for ( i = 0 ; i < 500000 ; i++ ) {
            Gen nxt = curr ;

            y = R.GetInt(0,Y-1);
            x = R.GetInt(0,X-1);
            n = R.GetInt(0, 8) ;
            if ( n >= nxt.G[ y ][ x ] ) n++;

            nxt.G[ y ][ x ] = n ;
            //Eval(nxt);
            ep.updateEval(nxt, y, x, y, x);

            delta = (nxt.Score() - curr.Score()) / ( T ) ;
            if (curr < nxt || ( nxt < curr && exp(delta) > R.GetDouble(0, 1))) {
                curr = nxt;
            }
            else {
                ep.updateEval(curr, y, x, y, x);
            }
            if ( best < curr ) {
                best = curr;
            }
            T=max(1.0, T*d);
        }
        SwapElement(curr);
        SwapCol(curr);
        SwapRow(curr);
        if ( best < curr ) {
            best = curr;
        }
    }

    void PrintAvg(int iter, milliseconds elapsed) {
        int i ;
        double avg1;
        double avg2;
        //////////////////////////////////////////////////////////////////////////
        // Average
        for ( avg1 = avg2 = 0, i = 0 ; i < (int)genList.size() ; i ++ ) {
            auto &g = genList[i];
            avg1 = avg1 * ((double)(i) / (double)(i+1)) + g.totalCount / (double)(i+1);
            avg2 = avg2 * ((double)(i) / (double)(i+1)) + g.maxScore / (double)(i+1);
        }

        cout << "# Iter = " << iter << " / " << MaxIter
             << " / Elapsed time : " << setprecision(4) << fixed << elapsed.count() / 1000.0 << '\n'
             << " Average Score = " << avg1 << " / " << avg2 << '\n';
    }

    void PrintTop10() {
        int i, j, k ;

        //////////////////////////////////////////////////////////////////////////
        // Top 10
        cout << " [Top 10]\n";
        for ( i = 0 ; i < 10 && i < (int)genList.size() ; i ++ ) {
            if ( i ) cout << " | ";
            cout << "#" << i << ' ' << setw(5) << genList[i].maxScore << "/" << setw(5) << genList[i].totalCount ;
        }
        cout << '\n';
        for ( i = 0 ; i < 10 && i < (int)genList.size()  ; i ++ ) {
            if ( i ) cout << " | ";
            cout << "I" << setw(13) << genList[i].maxIter ;
        }
        cout << '\n';
        for ( i = 0 ; i < 10 && i < (int)genList.size()  ; i ++ ) {
            if ( i ) cout << " | ";
            cout << "T " << setw(12) << setprecision(6) << fixed << genList[i].T ;
        }
        cout << '\n';
        for ( i = 0 ; i < 10 && i < (int)genList.size() ; i ++ ) {
            if ( i ) cout << " | ";
            cout << "d " << setw(12) << setprecision(6) << fixed << genList[i].d ;
        }
        cout << '\n';

        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < 10 && j < (int)genList.size(); j ++ ) {
                for (k = 0; k < X; k++)
                    cout << (int)genList[j].G[i][k];
                cout << " | ";
            }
            cout << '\n';
        }
        cout << endl;
    }

    void do_iteration(Gen &best, Gen &curr) {
        for ( int iter = 0 ; iter < MaxIter ; iter ++ ) {
            // SA
            auto s = chrono::steady_clock::now();
            std::for_each(std::execution::par_unseq, genList.begin(), genList.end(), [this, &curr](Gen &g) {
                run(g, curr);
            });
            auto e = chrono::steady_clock::now();
            auto elapsed = duration_cast<milliseconds>(e-s);

            // Print Result - Average
            PrintAvg(iter, elapsed);

            // Print Result - Top10 (sequence 1-N)
            sort(genList.begin(), genList.end(), [](Gen &a, Gen &b) {
                return a.Score2() > b.Score2();
            });
            PrintTop10();
            if ( best < genList[0] ) best = genList[0];
            if ( curr < genList[0] ) curr = genList[0];

            // Print Result - Top10 (Total Count 1-10000)
            sort(genList.begin(), genList.end(), [](Gen &a, Gen &b) {
                return a.Score() > b.Score();
            });
            if ( best < genList[0] ) best = genList[0];
            if ( curr < genList[0] ) curr = genList[0];
            PrintTop10();
            best.dump();
        }
        curr = genList[0];
    }
};

#endif //CLION_SA_H
