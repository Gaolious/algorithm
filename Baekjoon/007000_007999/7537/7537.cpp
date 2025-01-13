#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
enum POS_TYPE { ABSOLUTE, RELATIVE };
struct IMG{
    int w{}, h{};
    vector<string> m;
};
struct CSS{
    int index;
    int x{}, y{};
    POS_TYPE posType;
    string parent;
    string filename;
    int layer{};
    int sx=-1, sy=-1, ex=-1, ey=-1;
};

void init(){
}
std::vector<std::string> tokenize(const std::string &str, const std::string &delimiters) {
    std::vector<std::string> tokens;
    std::string token;
    std::size_t start = 0, end = 0;
    while ((end = str.find_first_of(delimiters, start)) != std::string::npos) {
        if (end != start) {
            token = str.substr(start, end - start);
            if (!token.empty()) tokens.push_back(token);
        }
        start = end + 1;
    }
    if (start < str.size()) {
        token = str.substr(start);
        if (!token.empty()) tokens.push_back(token);
    }

    return tokens;
}

void Input(unordered_map<string, IMG> &ImageList, unordered_map<string, CSS>& CSSList) {
    int i, N, x, y;
    string line, s;
    cin >> N ;
    for(i = 0 ; i < N ; i ++ ) {
        cin >> s ;
        auto &img = (ImageList[s] = IMG());
        cin >> img.h >> img.w;
        cin.ignore();
        for (y=0 ; y < img.h ; y ++ ) {
            cin >> img.m.emplace_back();
            for (auto &c: img.m.back())
                if ( c == '.' ) c = ' ';
        }
    }

    cin >> N ;
    cin.ignore();
    int index =0;
    while ( N -- ) {
        getline(cin, line);
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        i = 1, s = "";
        while ( i < line.size() && line[i] != '{') s.push_back(line[i++]);
        auto &css = (CSSList[s] = CSS());
        css.index = index++;

        while (getline(cin, line)) {
            auto tokens = tokenize(line, ": =;\t");
            if ( tokens.size() < 1 ) break;
            if ( tokens.size() == 1 && tokens[0] == "}") break;
            if ( tokens[0] == "pos-x") css.x = stoi(tokens[1]);
            else if ( tokens[0] == "pos-y") css.y = stoi(tokens[1]);
            else if ( tokens[0] == "position") {
                if ( tokens[1] == "absolute" ) css.posType = ABSOLUTE;
                else {
                    css.posType = RELATIVE;
                    css.parent = tokens[2];
                }
            }
            else if ( tokens[0] == "file") css.filename = tokens[1];
            else if ( tokens[0] == "layer") css.layer = stoi(tokens[1]);
        }
    }

}

void updateSize(unordered_map<string, IMG> &imgList, unordered_map<string, CSS>& cssList, const string &cssName) {
    auto &css = cssList[cssName];
    if ( css.sx >= 0 ) return;

    if ( css.posType == ABSOLUTE ) {
        css.sx = css.x ;
        css.sy = css.y ;
    }
    else {
        updateSize(imgList, cssList, css.parent);
        auto &parentCss = cssList[css.parent];
        css.sx = parentCss.sx + css.x;
        css.sy = parentCss.sy + css.y;
    }
    css.ex = css.sx + imgList[css.filename].w ;
    css.ey = css.sy + imgList[css.filename].h ;
}

void process(int Case) {
    unordered_map<string, IMG> ImageList;
    unordered_map<string, CSS> CSSList;
    Input(ImageList, CSSList);
    int maxWidth=-1, maxHeight=-1;
    vector<pair<int, string>> Q;
    for (auto &[cssName, css]: CSSList) {
        updateSize(ImageList, CSSList, cssName);
        maxWidth = max( maxWidth, css.ex);
        maxHeight = max( maxHeight, css.ey);
        Q.emplace_back(css.layer, cssName);
    }
    vector<string> ans(maxHeight, string(maxWidth, ' '));
    cout << "Scenario #" << Case << ":\n";

    int i, j;
    std::sort(Q.begin(), Q.end(), [&CSSList](pair<int, string> &a, pair<int, string> &b) {
        if ( a.first != b.first ) return a.first < b.first;
        return CSSList[a.second].index < CSSList[b.second].index;
    });
    for ( auto &[layer, name] : Q) {
        auto &css = CSSList[name];
        auto &img = ImageList[css.filename];
        for (i = 0; i < img.h; i++)
            for (j = 0; j < img.w; j++)
                if ( img.m[i][j] != ' ')
                    ans[css.sy + i][css.sx + j] = img.m[i][j];
    }
    for (auto &row: ans) cout << row << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	 cin >> T;
	for ( int i=1 ; i <= T ; i ++ ) {
        if ( i > 1 ) cout << '\n';
        process(i);
    }
    return 0;
}
