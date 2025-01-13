#include<bits/stdc++.h>

using namespace std;
enum TYPE { VERTICAL, HORIZONAL, EXPR, TERM, PLUS, QUESTION, ASTERISK, LETTER };

void writePlus(vector<string> &outputs, vector<int> Y, vector<int> X)
{
    for ( auto y: Y) for ( auto x: X) outputs[y][x] = '+';
}
void writieVertBar(vector<string> &outputs, int sy, int ey, int sx, int ex)
{
    for ( ;sy <= ey; sy++ )
        outputs[sy][sx] = outputs[sy][ex] = '|';
}
void writeArrowL(vector<string> &outputs, int y, int sx, int ex)
{
    if ( sx < ex ) outputs[y][sx++] = '<';
    for ( ; sx <= ex ; sx++ ) outputs[y][sx] = '-';
}
void writeArrowR(vector<string> &outputs, int y, int sx, int ex)
{
    for ( ; sx < ex ; sx++ ) outputs[y][sx] = '-';
    if ( sx <= ex ) outputs[y][sx++] = '>';
}
void writeLine(vector<string> &outputs, vector<int> Y, int sx, int ex)
{
    for (auto y: Y) for (int x=sx; x<=ex; x ++ ) outputs[y][x] = '-';
}
void writeStr(vector<string> &outputs, int y, int x, string str)
{
    for (auto c: str) outputs[y][x++] = c;
}

struct Draw
{
    TYPE type;
    int sx{}, sy{}, width{}, height{};
    string letter;
    vector<Draw> childList;
    Draw() {}
    int ex() { return sx + width - 1; }
    int ey() { return sy + height - 1; }
    Draw(const Draw &child, TYPE oper)
    {
        this->type = oper;
        childList.push_back(child);
        switch (oper)
        {
            case PLUS: width = child.width + 6, height = child.height + 2; break;
            case QUESTION: width = child.width + 6, height = child.height + 3; break;
            case ASTERISK: width = child.width + 6, height = child.height + 5; break;
        }
    }
    Draw(const string &str)
    {
        type = LETTER;
        letter = str;
        width = str.length() + 4;
        height = 3;
    }
    Draw(const vector<Draw> &drawList, TYPE drawDir)
    {
        int maxX = -1, maxY=-1, sumX = 0, sumY = 0;

        for (auto &d: drawList)
        {
            maxX = max(maxX, d.width);
            maxY = max(maxY, d.height);
            sumX += d.width;
            sumY += d.height;
        }
        if ( drawDir == VERTICAL )
        {
            type = VERTICAL;
            height = sumY + (drawList.empty() ? 0 : (drawList.size() - 1));
            width = maxX + 6;
        }
        else
        {
            type = HORIZONAL;
            height = maxY ;
            width = sumX + (drawList.empty() ? 0 : (drawList.size() - 1) * 2);
        }
        childList = drawList;
    }
    void updatePos(int y, int x)
    {
        int i, len = childList.size();
        int ty, tx;
        ty = sy = y, tx = sx = x;

        switch (type)
        {
        case VERTICAL:
            for ( tx += 3, i = 0; i < len; ty += childList[i].height + 1, i++ )
                childList[i].updatePos(ty, tx);
            break;
        case HORIZONAL:
            for ( i = 0; i < len; tx += childList[i].width + 2, i++ )
                childList[i].updatePos(ty, tx);
            break;
        case PLUS:
            for ( i = 0; i < len; tx += childList[i].width + 3, i++ )
                childList[i].updatePos(ty, tx+=3 );
            break;
        case QUESTION:
            for ( i = 0; i < len; tx += childList[i].width + 3, i++ )
                childList[i].updatePos(ty+=3, tx+=3 );
            break;
        case ASTERISK:
            for ( i = 0; i < len; tx += childList[i].width + 3, i++ )
                childList[i].updatePos(ty+=3, tx+=3 );
            break;
        case LETTER:
            break;
        }
    }
    void dumpString(vector<string> &outputs)
    {
        vector<int> Y, X;
        int i, j, len = childList.size();
        int ty, tx, ey, ex;
        ey = sy + height - 1, ex = sx + width - 1;

        ty = sy, tx = sx;
        switch (type)
        {
        case VERTICAL:
                for ( i = 0 ; i < len ; i ++ )
                {
                    writePlus(outputs, {childList[i].sy + 1}, {sx, ex});
                    if ( i > 0 ) writieVertBar(outputs, childList[i-1].sy + 2, childList[i].sy, sx, ex);
                    writeArrowR(outputs, childList[i].sy+1, childList[i].sx-2, childList[i].sx-1);
                    writeArrowR(outputs, childList[i].sy+1, childList[i].sx + childList[i].width, ex-1);
                }
                break;
            case HORIZONAL:
                for ( i = 0 ; i < len-1 ; i ++ )
                {
                    writeArrowR(outputs, childList[i].sy+1, childList[i].ex()+1, childList[i+1].sx-1);
                }
                break;
            case PLUS:
                writePlus(outputs, {sy+1, ey}, {sx, ex});
                writieVertBar(outputs, sy+2, ey-1, sx, ex);
                writeArrowL(outputs, ey, sx+1, ex-1);
                writeArrowR(outputs, childList.front().sy+1, sx+1, childList.front().sx-1);
                writeArrowR(outputs, childList.front().sy+1, childList.back().ex()+1, ex-1);

                break;
            case QUESTION:
                writePlus(outputs, {sy+1, childList.front().sy+1}, {sx, ex});
                writieVertBar(outputs, sy+2, childList.front().sy, sx, ex);
                writeArrowR(outputs, sy+1, sx+1, ex-1);
                writeArrowR(outputs, childList.front().sy+1, sx+1, childList.front().sx-1);
                writeArrowR(outputs, childList.front().sy+1, childList.back().ex()+1, ex-1);
                break;
            case ASTERISK:
                writeArrowR(outputs, sy+1, sx+1, ex-1);
                writeArrowL(outputs, ey, sx+1, ex-1);
                writieVertBar(outputs, sy+2, ey-1, sx, ex);
                writePlus(outputs, {childList.front().sy+1, sy+1, ey}, {sx, ex});

                writeArrowR(outputs, childList.front().sy+1, sx+1, childList.front().sx-1);
                writeArrowR(outputs, childList.front().sy+1, childList.back().ex()+1, ex-1);
                break;
            case LETTER:
                writePlus(outputs, {sy, sy+1, ey}, {sx, ex});
                writeLine(outputs, {sy, ey}, sx+1, ex-1);
                writeStr(outputs, sy+1, sx+2, letter);
                break;
        }

        for ( i = 0 ; i < len ; i ++ )
            childList[i].dumpString(outputs);
    }
};

bool isLetter(char c) { return c >= 'A' && c <= 'Z'; }
bool isOper(char c) { return c == '+' || c == '?' || c == '*' ; }

Draw ParseTerm(const string &str, int &idx);
Draw ParseAtom(const string &str, int &idx);

Draw ParseExpr(const string &str, int &idx)
{
    vector<Draw> result;
    for ( ; idx < str.size(); idx++ )
    {
        result.push_back(ParseTerm(str, idx));
        if ( str[idx] == ')' ) break;
    }
    return ( result.size() == 1 ) ? result[0]: Draw(result, VERTICAL);
}

Draw ParseTerm(const string &str, int &idx)
{
    vector<Draw> result;
    for ( ; idx < str.size(); idx++ )
    {
        result.push_back(ParseAtom(str, idx));
        if ( str[idx] == '|' || str[idx] == ')' ) break;
    }
    return ( result.size() == 1 ) ? result[0]: Draw(result, HORIZONAL);
}

Draw ParseAtom(const string &str, int &idx)
{
    vector<Draw> result;
    Draw ret;
    string letter;
    char c;
    TYPE prev = TERM;

    for ( ; idx < str.size(); idx++)
    {
        if ( str[idx] == '(' )
        {
            if (!letter.empty() ) { result.emplace_back(letter); letter.clear(); }
            idx++;
            result.push_back(ParseExpr(str, idx));
            prev = EXPR;
        }
        else if ( isLetter(str[idx]) )
        {
            letter.push_back(str[idx]);
            prev = LETTER;
        }
        else if ( isOper(str[idx] ) )
        {
            auto currType = str[idx] == '+' ? PLUS : str[idx] == '?' ? QUESTION : ASTERISK;
            switch ( prev )
            {
            case LETTER:
                {
                    c = letter.back(); letter.pop_back();
                    if (!letter.empty() ) { result.emplace_back(letter); letter.clear(); }
                    letter.push_back(c);
                    result.emplace_back(letter, currType);
                    letter = "";
                    break;
                }
            case EXPR:
                {
                    auto lastExpr = result.back(); result.pop_back();
                    result.emplace_back(lastExpr, currType);
                    break;
                }
            case PLUS:
            case QUESTION:
            case ASTERISK:
                {
                    auto lastOper = result.back(); result.pop_back();
                    result.emplace_back(lastOper, currType);
                    break;
                }
            }
            prev = currType;
        }
        else
            break;
    }
    if (!letter.empty() ) { result.emplace_back(letter); letter.clear(); }

    return ( result.size() == 1 ) ? result[0]: Draw(result, HORIZONAL);
}
void dump(Draw &root, int depth=1)
{
    string padding = string(depth*2, ' ');
    string strType ;
    switch ( root.type )
    {
        case VERTICAL: strType = "VERTICAL"; break;
        case HORIZONAL: strType = "HORIZONAL"; break;
        case EXPR: strType = "EXPR"; break;
        case TERM: strType = "TERM"; break;
        case PLUS: strType = "PLUS"; break;
        case QUESTION: strType = "QUESTION"; break;
        case ASTERISK: strType = "ASTERISK"; break;
        case LETTER: strType = "LETTER"; break;
    }
    cout << padding << '[' << strType << "] Y=" << root.sy << ", X=" << root.sx << ", H=" << root.height << ", W=" << root.width << (root.type == LETTER ? root.letter : "") << '\n';;
    for (auto &child: root.childList)
        dump(child, depth+1);
}
void process() {
    string input;
    int idx=0, i;
    getline(cin, input);
    auto root = ParseExpr(input, idx);
    cout << root.height << ' ' << root.width + 6 << '\n';

    root.updatePos(0, 0);
    vector outputs(root.height, string(root.width, ' ') );
    root.dumpString(outputs);

    for ( i = 0 ; i < outputs.size(); i ++ )
    {
        cout << ( i == 1 ? "S->" : "   " );
        cout << outputs[i];
        cout << ( i == 1 ? "->F" : "   " );
        cout << '\n';
    }
    // dump(root);
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	process();
    return 0;
}
