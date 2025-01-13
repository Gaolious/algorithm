#include <bits/stdc++.h>
using namespace std;
#define _TA(a) tableList[ (a) ]
#define _TR(a, b) _TA(a).trList[ (b) ]
#define _TD(a, b, c) _TR(a, b).tdList[ (c) ]

void init(){
}
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    if ( !a || !b ) return 0;
    else {
        int t = a / gcd(a, b) * b;
        return t;
    }
}
struct TD {
    int textIndex;
    int tableIndex;
    void setTextIdx(int idx) {
        textIndex = idx;
        tableIndex = -1;
    }
    void setTableIdx(int idx) {
        textIndex = -1;
        tableIndex = idx;
    }
};
struct TR {
    vector<TD> tdList;
};
struct TABLE {
    int depth;
    int parentTbl, parentTr, parentTd;
    vector<TR> trList;
    vector<int> rowCnt;
    vector<int> colCnt;
    bool isChecked;
    bool isEmpty;
};

struct Solution {
    vector<string> textList;
    vector<TABLE> tableList;
    Solution() {
        textList.emplace_back(""); // empty string
    }
    int parseTable(string &s, int pos, int tblIndex) {

        for (int i = pos; i < s.size() ; i++) {
            if (s[i] == '<') {
                if (s[i + 1] == '/') {
                    if ( i == pos ) {

                        auto &tr = _TA(tblIndex).trList.emplace_back();
                        tr.tdList.push_back({0, -1}); // <table></table>
                    }
                    return i + 7 - pos; // </table>
                }
                int trIndex= _TA(tblIndex).trList.size();
                _TA(tblIndex).trList.emplace_back();
                i += 4;
                i += parseTr(s, i, tblIndex, trIndex); // <tr>
            }
            else {
                cout << "";
            }
        }
        return s.size();
    }
    int parseTr(string &s, int pos, int tblIndex, int trIndex) {

        for (int i = pos; i < s.size() ; i++) {
            if (s[i] == '<') {
                if (s[i + 1] == '/') {
                    if ( i == pos )
                        _TR(tblIndex, trIndex).tdList.push_back({0, -1}); // <tr></tr>
                    return i + 4 - pos; // </tr>
                }
                int tdIndex = _TR(tblIndex, trIndex).tdList.size();
                _TR(tblIndex, trIndex).tdList.push_back({-1, -1});
                i+=4;
                i += parseTd(s, i, tblIndex, trIndex, tdIndex); // <td>
            }
            else {
                cout << "";
            }
        }
        return s.size();
    }
    int parseTd(string &s, int pos, int tblIndex, int trIndex, int tdIndex) {
        for (int i = pos; i < s.size() ; i++) {
            if (s[i] == '<') {
                if (s[i + 1] == '/') {
                    if ( i == pos ) {
                        _TD(tblIndex, trIndex, tdIndex).setTextIdx(0); // <td></td>
                    }
                    return i + 4 - pos; // </td>
                }

                int newTblIndex = tableList.size();
                tableList.push_back( {tableList[tblIndex].depth + 1, tblIndex, trIndex, tdIndex});
                _TD(tblIndex, trIndex, tdIndex).setTableIdx(newTblIndex);
                i += 7;
                i += parseTable(s, i, newTblIndex); // <table>
            }
            else {
                i += parseText(s, pos, tblIndex, trIndex, tdIndex);
            }
        }
        return s.size();
    }
    int parseText(string &s, int pos, int tblIndex, int trIndex, int tdIndex) {
        _TD(tblIndex, trIndex, tdIndex).setTextIdx(textList.size());
        auto &txt = textList.emplace_back();
        for ( int i = pos ; i < s.size() ; i ++ ) {
            txt.push_back(s[i]);
            if ( s[i+1] == '<' )
                return i - pos;
        }
        return s.size();
    }
    void parse(string &s) {
        int tblIndex = tableList.size();
        tableList.push_back( {0, -1, -1, -1});
        parseTable(s, 7, tblIndex);
    }

    void updateCount(int tblIndex) {
        int i, j;
        int maxRowCount=0, maxColCount=0;

        auto &tbl = tableList[tblIndex];
        maxRowCount = tbl.trList.size();

        for ( i = 0 ; i < tbl.trList.size() ; i ++ ) {
            auto &tr = tbl.trList[i];
            maxColCount = max( maxColCount, (int)tr.tdList.size());
        }
        if ( maxRowCount < 1 || maxColCount < 1 ) {
        }
        else {
            tbl.rowCnt.resize(maxRowCount, 1);
            tbl.colCnt.resize(maxColCount, 1);
        }
    }

    bool checkEmpty(int tblIndex) {
        auto &tbl = tableList[tblIndex];
        if ( tbl.isChecked ) return tbl.isEmpty;

        tbl.isChecked = true;

        for (auto &tr: tbl.trList) {
            for (auto &td: tr.tdList) {
                if ( td.textIndex >= 0 )
                    return tbl.isEmpty = false;
                if ( td.tableIndex >= 0 ) {
                    if (!checkEmpty(tblIndex))
                        return tbl.isEmpty = false;
                }
            }
        }
        if ( tbl.parentTbl >= 0 && tbl.parentTr >= 0 && tbl.parentTd >= 0 )
            tableList[tbl.parentTbl].trList[tbl.parentTr].tdList[tbl.parentTd].tableIndex = -1;
        return tbl.isEmpty = true;
    }
    vector<vector<int>> outText;
    vector<vector<int>> colSpan;
    vector<vector<int>> rowSpan;

    void draw(int tblIndex, int sy, int sx) {
        int i, j;
        int y, x, ty, tx;

        auto &tbl = tableList[tblIndex];
        for (i = 0, ty = 0; i < tbl.trList.size(); ty += tbl.rowCnt[i++]) {
            auto &tr = tbl.trList[i];

            for (j = 0, tx = 0; j < tr.tdList.size(); tx += tbl.colCnt[j++]) {
                auto &td = tr.tdList[j];

                if (td.textIndex >= 0) {
                    outText[sy+ty][sx+tx] = td.textIndex;
                    rowSpan[sy+ty][sx+tx] = tbl.rowCnt[i];
                    colSpan[sy+ty][sx+tx] = tbl.colCnt[j];
                }
                else if ( td.tableIndex >= 0 ) {
                    draw(td.tableIndex, sy+ty, sx+tx);
                }
            }
        }
    }

    void getResult() {
        int i, j;
        vector<int> indexes;
        for ( i = 0 ; i < tableList.size() ; i ++)
            updateCount(i);

        checkEmpty(0);
        for ( i = 0 ; i < tableList.size() ; i ++) {
            if ( i == 0 || checkEmpty(i) )
                continue;
            indexes.push_back(i);
        }

        std::sort(indexes.begin(), indexes.end(), [this](int a, int b){
            return tableList[a].depth == tableList[b].depth ? a > b : tableList[a].depth > tableList[b].depth;
        });

        int s;
        for (auto tblIndex: indexes ) {
            auto &tbl = tableList[tblIndex];
            auto &parent = tableList[tbl.parentTbl];

            for (s = 0, i = 0 ; i < tbl.rowCnt.size() ; i ++ ) s += tbl.rowCnt[i];
            parent.rowCnt[ tbl.parentTr ] = lcm( parent.rowCnt[ tbl.parentTr ], s );

            for (s = 0, i = 0 ; i < tbl.colCnt.size() ; i ++ ) s += tbl.colCnt[i];
            parent.colCnt[ tbl.parentTd ] = lcm( parent.colCnt[ tbl.parentTd ], s );
        }

        int nRows = 0, nCols = 0, y, x ;
        for ( auto n: tableList[0].rowCnt ) nRows += n ;
        for ( auto n: tableList[0].colCnt ) nCols += n ;
        outText.resize(nRows, vector<int>(nCols, -1));
        rowSpan.resize(nRows, vector<int>(nCols, 1));
        colSpan.resize(nRows, vector<int>(nCols, 1));

        draw(0, 0, 0);

        cout << "<table>";
        for ( i = 0 ; i < nRows ; i ++ ) {
            cout << "<tr>";
            for (j = 0; j < nCols; j++) {
                if (outText[i][j] >= 0) {
                    cout << "<td";
                    if (rowSpan[i][j] > 1) cout << " rowspan=\"" << rowSpan[i][j] << "\"";
                    if (colSpan[i][j] > 1) cout << " colspan=\"" << colSpan[i][j] << "\"";
                    cout << ">";
                    if (textList[outText[i][j]] == "F6")
                        cout << "";
                    cout << textList[outText[i][j]];
                    cout << "</td>";
                }
            }
            cout << "</tr>";
        }
        cout << "</table>\n";
    }
};

void process(int Case) {
    string s;

    cout << "<body>\n";
    while (getline(cin, s) && !s.empty() ) {
        if ( s == "<body>" ) continue;
        else if ( s == "</body>" ) break;
        Solution sol;
        sol.parse(s);
        sol.getResult();
    }
    cout << "</body>\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
