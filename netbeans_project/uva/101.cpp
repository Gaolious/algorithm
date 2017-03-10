/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   101.cpp
 * Author: ajava
 *
 * Created on 2017년 3월 11일 (토), 오전 12:00
 */

#include <cstdlib>
#include <list>

using namespace std;

int main(int argc, char** argv) {

    string cmd1, cmd2;
    int a, b, n;
    int i;
    
    list< list<int> > map ;
    
    cin >> n;
    
    
    for ( i = 0 ; i < n ; i ++ )
    {
        list<int> t ;
        t.push_back( i + 1 ) ;
        
        map.push_back( t );
    }
                
    cin >> cmd1 >> a >> cmd2 >> b;
    
    return 0;
}

