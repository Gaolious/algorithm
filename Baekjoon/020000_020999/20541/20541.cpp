#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Album {
    string title;
    int totalAlbums{};
    int totalImages{};
    map<string, Album *> albums;
    set<string> images;

    Album(const string &nm) : title(nm) {}
};
typedef pair<string, Album*> PATH;
typedef vector<pair<string, Album*>> PATHS;

list<Album> AlbumList;
void updateStatistics(PATHS &path, int albums, int images) {
    for (auto iter = path.rbegin() ; iter != path.rend() ; iter ++ ) {
        iter->second->totalAlbums += albums;
        iter->second->totalImages += images;
    }
}
bool createAlbum(PATHS &path, string &name) {
    auto parent = path.back().second;
    if (parent->albums.count(name) == 0) {
        AlbumList.emplace_back(name);
        parent->albums[name] = &(AlbumList.back());
        updateStatistics(path, 1, 0);
        return true;
    }
    return false;
}
bool createImage(PATHS &path, string &name) {
    auto parent = path.back().second;
    if (parent->images.count(name) == 0) {
        parent->images.insert(name);
        updateStatistics(path, 0, 1);
        return true;
    }
    return false;
}
pair<int, int> delAlbum(PATHS &path, const string& name) {
    pair<int, int> ret = {0, 0};
    auto parent = path.back().second;
    auto iter = parent->albums.find(name);
    if ( iter != parent->albums.end() ) {
        ret = {iter->second->totalAlbums + 1, iter->second->totalImages};
        parent->albums.erase(iter);
        updateStatistics(path, -ret.first, -ret.second);
    }
    return ret;
}
pair<int, int> delAlbumAll(PATHS &path) {
    pair<int, int> ret = {0, 0};
    auto parent = path.back().second;
    for (const auto& iter : parent->albums) {
        ret.first += iter.second->totalAlbums + 1;
        ret.second += iter.second->totalImages;
    }
    parent->albums.clear();
    updateStatistics(path, -ret.first, -ret.second);
    return ret;
}
int delImage(PATHS &path, const string& name) {
    auto parent = path.back().second;
    auto iter = parent->images.find(name);
    if ( iter != parent->images.end() ) {
        parent->images.erase(iter);
        updateStatistics(path, 0, -1);
        return 1;
    }
    return 0;
}
int delImageAll(PATHS &path) {
    int ret ;
    auto parent = path.back().second;
    ret = parent->images.size();
    updateStatistics(path, 0, -ret);
    parent->images.clear();
    return ret;
}
void init(){}
void dump(Album *root, int depth) {
    string padding(depth*4, ' ');
    cout << padding << "+-- [D] " << root->title << " sub Album: " << root->totalAlbums << ", sub Images: " << root->totalImages << '\n';
    for ( auto &al: root->albums )
        dump(al.second, depth+1);
    for ( auto &image: root->images )
        cout << padding << "     +-- [F] " << image << '\n';
}
void process(int Case) {
    int N ;
    cin >> N ;
    string cmd, paramS;
    auto rootAlbum = AlbumList.emplace_back("album");
    rootAlbum.totalAlbums ++;

    PATHS path = { {"album", &rootAlbum} };
    Album *curr = nullptr;

    while( N -- ) {
        cin >> cmd >> paramS;

        if ( cmd == "mkalb" ) {
            if ( !createAlbum(path, paramS) ) {
                cout << "duplicated album name\n";
            }
        }
        else if ( cmd == "rmalb" ) {
            curr = path.back().second;
            pair<int, int> ret;
            if ( curr->albums.empty() )
                ret = {0, 0};
            else if (paramS == "-1")
                ret = delAlbum(path, curr->albums.begin()->first);
            else if (paramS == "0")
                ret = delAlbumAll(path);
            else if (paramS == "1")
                ret = delAlbum(path, curr->albums.rbegin()->first);
            else
                ret = delAlbum(path, paramS);
            cout << ret.first << ' ' << ret.second << '\n';
        }
        else if ( cmd == "insert" ) {
            if ( !createImage(path, paramS) ) {
                cout << "duplicated photo name\n";
            }
        }
        else if ( cmd == "delete" ) {
            curr = path.back().second;
            int ret ;
            if ( curr->images.empty() )
                ret = 0;
            else if (paramS == "-1")
                ret = delImage(path, *curr->images.begin());
            else if (paramS == "0")
                ret = delImageAll(path);
            else if (paramS == "1")
                ret = delImage(path, *curr->images.rbegin());
            else
                ret = delImage(path, paramS);
            cout << ret << '\n';
        }
        else if ( cmd == "ca" ) {
            if ( paramS == ".." ) {
                if ( path.size() > 1 ) path.pop_back();
            }
            else if ( paramS == "/" ) {
                path.erase(path.begin()+1, path.end());
            }
            else {
                curr = path.back().second;
                auto iter = curr->albums.find(paramS);
                if ( iter != curr->albums.end() ) {
                    path.emplace_back(paramS, iter->second );
                }
            }
            curr = path.back().second;
            cout << curr->title << '\n';
        }

#ifdef AJAVA_DEBUG
        cout << "COMMAND : " << cmd << ' ' << paramS << '\n';
        dump(&rootAlbum, 0);
#endif
    }
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
