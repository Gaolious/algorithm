#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

typedef struct  {
    int left, right;
} RANGE;
#ifdef AJAVA_DEBUG
int Sum[100];
#else
int Sum[2000101];
#endif
vector<int> PreSumEven, PreSumOdd;
vector<RANGE> EvenRange, OddRange ;
void input(){
    int i, j, s, e, length ;
    int cum_len;
    int choice = 0 ;
    string str;

    cin >> str;

    e = -1, s = 0 ;
    length = str.size();
    while ( length >= 0 && str[length-1] == '-') length--;
    for ( i = 0, j = 0 ; i < length ; i ++ ) {
        if ( str[i] == '-' && i+1 < length && str[i+1] == '-' ) {
            i++;
            continue;
        }
        str[j++] = str[i];
    }
    str.erase(j, std::string::npos);
    length = str.size();


    for (i = 0 ; i < length ; i ++){
        if ( str[i] == '-') {
            if ( i+1 < length && str[i+1] == '-' ) {
                i++;
                continue;
            }
            e = i - 1;
            if ( s <= e ) {
                auto &target (choice++ % 2 == 0 ? EvenRange : OddRange);
                target.push_back({s, e});
            }
            s = i+1;
        }
    }
    if ( e < s ) {
        e = length-1;
        auto &target (choice++ % 2 == 0 ? EvenRange : OddRange);
        target.push_back({s, e});
    }

    for ( i = 0 ; i < EvenRange.size() ; i ++ ) {
        for ( j = EvenRange[i].left ; j <= EvenRange[i].right ; j ++ ) {
            if (PreSumEven.empty()) PreSumEven.push_back(str[j] - '0');
            else PreSumEven.push_back( PreSumEven.back() + str[j] - '0');
        }
    }
    for ( i = 0 ; i < OddRange.size() ; i ++ ) {
        for ( j = OddRange[i].left ; j <= OddRange[i].right ; j ++ ) {
            if (PreSumOdd.empty()) PreSumOdd.push_back(str[j] - '0');
            else PreSumOdd.push_back( PreSumOdd.back() + str[j] - '0');
        }
    }
}

int GetEvenSum(int l, int r) {
    int ret = 0;
    if ( 0 <= l && l <= r ) {
        r = min((int)PreSumEven.size()-1, r);
        ret = PreSumEven[r] - ( l > 0 ? PreSumEven[l-1] : 0 );
    }
    return ret;
}
int GetOddSum(int l, int r) {
    int ret = 0;

    if ( 0 <= l && l <= r ) {
        r = min((int)PreSumOdd.size()-1, r);
        ret = PreSumOdd[r] - ( l > 0 ? PreSumOdd[l-1] : 0 );
    }
    return ret;
}

int process_even() {
    int x, y ;
    int even_count, odd_cum_count ;
    int odd_left, odd_right;
    int range_index, i;
    even_count = (int)PreSumEven.size();
    x=0, y=0;

    odd_cum_count = 0;
    odd_left = 0, odd_right = -1;

    for ( range_index = 0 ; range_index < EvenRange.size() ; range_index ++ ) {
        if (range_index > 0 ) {
            for ( i = OddRange[range_index-1].left ; i <= OddRange[range_index-1].right ; i ++ ) {
                Sum[x] += GetEvenSum(0, even_count - 1) + GetOddSum(odd_left, odd_right);
#ifdef AJAVA_DEBUG
                printf(
                        "x=%d, y=%d, Sum=%d (even sum=%d~%d), (odd = sum=%d~%d) $$\n",
                        x, y, Sum[x], 0, even_count - 1, odd_left, odd_right
                );
#endif
                odd_right++;
                if (even_count - 1 >= 0 ) even_count --;
                else odd_left++;
                x++;
                odd_cum_count++;
            }
        }
#ifdef AJAVA_DEBUG
        printf("\n");
#endif
        for ( i = EvenRange[range_index].left ; i <= EvenRange[range_index].right ; i ++) {
            Sum[x] += GetEvenSum(0, even_count - 1) + GetOddSum(odd_left, odd_right);
#ifdef AJAVA_DEBUG
            printf(
                    "x=%d, y=%d, Sum=%d (even sum=%d~%d), (odd = sum=%d~%d) \n",
                    x, y, Sum[x], 0, even_count - 1, odd_left, odd_right
            );
#endif
            x++, y++;
            odd_right = min(odd_right + 1, odd_cum_count-1);
            if (even_count - 1 >= 0 ) even_count --;
            else odd_left++;
        }
#ifdef AJAVA_DEBUG
        printf("\n");
#endif
    }
    return x;
}

int process_odd() {
    int x, y ;
    int odd_count, even_cum_count ;
    int even_left, even_right;
    int range_index, i;
    odd_count = (int)PreSumOdd.size();
    x=0, y=0;
    even_left = 0, even_right = -1;

    even_cum_count = 0;

    for ( range_index = 0 ; range_index < OddRange.size() ; range_index ++ ) {

        for ( i = EvenRange[range_index].left ; i <= EvenRange[range_index].right ; i ++ ) {
            Sum[x] += GetOddSum(0, odd_count - 1) + GetEvenSum(even_left, even_right);
#ifdef AJAVA_DEBUG
            printf(
                    "x=%d, y=%d, Sum=%d (odd sum=%d~%d), (even = sum=%d~%d) $$\n",
                    x, y, Sum[x], 0, odd_count - 1, even_left, even_right
            );
#endif
            even_right++;
            if (odd_count - 1 >= 0 ) odd_count --;
            else even_left++;
            x++;
            even_cum_count++;
        }
#ifdef AJAVA_DEBUG
        printf("\n");
#endif
        for ( i = OddRange[range_index].left ; i <= OddRange[range_index].right ; i ++) {
            Sum[x] += GetOddSum(0, odd_count - 1) + GetEvenSum(even_left, even_right);

#ifdef AJAVA_DEBUG
            printf(
                    "x=%d, y=%d, Sum=%d (odd sum=%d~%d), (even = sum=%d~%d) $$\n",
                    x, y, Sum[x], 0, odd_count - 1, even_left, even_right
            );
#endif
            x++, y++;
            even_right = min(even_right + 1, even_cum_count-1);
            if (odd_count - 1 >= 0 ) odd_count --;
            else even_left++;
        }
#ifdef AJAVA_DEBUG
        printf("\n");
#endif
    }
    return x;
}

int main()
{
    int x1, x2, x, i;
    memset(Sum, 0x00, sizeof(Sum));

    fastio;

    input();

    x1 = process_even();
    x2 = process_odd();
    x = 0;
    for ( i = 0 ; i < x1 || i < x2; i ++ ) {
        if ( Sum[i] >= 10 ) {
            Sum[i+1] += Sum[i]/10;
            Sum[i]%=10;
        }
        x++;
    }
    for ( ; Sum[i] > 0 ; i ++) {
        if ( Sum[i] >= 10 ) {
            Sum[i+1] += Sum[i]/10;
            Sum[i]%=10;
        }
        x ++;
    }
    if ( x > 0 ){
        for ( x-- ; x >= 0 ; x -- ) {
            cout << Sum[x];
        }
    }
    else {
        cout << 0;
    }
    cout << '\n';
    return 0;
}
