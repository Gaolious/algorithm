//
// Created by ajava on 24. 3. 27.
//
#include "eval.h"
#include "gen.h"

#ifndef CLION_DLAS_H
#define CLION_DLAS_H

struct DLSA{
    const int maxIdleIter = 10000;
    const int maxCandidates = 100;

    void mutate(Gen &curr) {
        int y = R.GetInt(0,Y-1);
        int x = R.GetInt(0,X-1);
        int n = R.GetInt(0, 8) ;
        if ( n >= curr.G[ y ][ x ] ) n++;

        curr.G[ y ][ x ] = n ;
    }

    void run(Gen &best, Gen &init) {
        int i, idleIter, k, currIdx, newIdx ;
        double score ;

        vector<Gen> Candidates(maxCandidates);
        vector<EvalPartial> Eval(maxCandidates);
        vector<double> Fitness(maxCandidates);

        EvalPartial().updateEval(best);

        for ( i = 0 ; i < maxCandidates ; i ++ ) {
            Candidates[i] = init ;
            Eval[i].updateEval(Candidates[i]);
            Fitness[i] = Candidates[i].Score();
        }
        score = Candidates[0].Score();

        k = 0 ;
        currIdx = 0;
        newIdx = 0 ;

        for (idleIter = 0 ; idleIter < maxIdleIter ; idleIter ++ ) {
            currIdx = (currIdx + 1) % maxCandidates;
            newIdx = (newIdx + 1) % maxCandidates;
            if ( newIdx == currIdx ) newIdx = (newIdx + 1) % maxCandidates;

            Gen &currGen = Candidates[currIdx];
            Gen &newGen = Candidates[newIdx];

            newGen = currGen;
            mutate(newGen);
            EvalPartial().updateEval(newGen);
            double newScore = newGen.Score();
            if ( best.Score() < newGen.Score() ) {
                best = newGen;
                idleIter = 0;
            }
            if ( abs(currGen.Score() - newGen.Score()) < 1.0e-7 || newGen.Score() < *max_element(Fitness)) {

            }
/*

            Domain& curS = S[curPos];
            Domain& newS = S[newPos];

            newS = curS;
            mutate(newS);
            CoDomain newF = f(newS);
            if (newF < minF) {
                idleIters = 0;
                minPos = newPos;
                minF = newF;
            }
            if (newF == curF || newF < *std::max_element(fitness.begin(), fitness.end())) {
                curPos = newPos;
                curF = newF;
            }

            CoDomain& fit = fitness[k];
            if (curF > fit || curF < fit && curF < prvF) {
                fit = curF;
            }
            k = incMod(k, LEN);
 * */
        }
    }
};
#endif //CLION_DLAS_H
