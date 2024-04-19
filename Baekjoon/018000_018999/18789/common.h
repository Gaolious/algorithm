//
// Created by ajava on 24. 3. 24.
//
#include <bits/stdc++.h>
#include <execution>
#include <thread>

#ifndef CLION_COMMON_H
#define CLION_COMMON_H

#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
using namespace chrono;

const int Y = 8;
const int X = 14;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

#endif //CLION_COMMON_H
