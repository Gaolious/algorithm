#include <iostream>
using namespace std;

const int MAX = 101;
int map[MAX][MAX];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for(int k=0; k<N; k++){
                if(map[j][i] && map[i][k]) map[j][k]=1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}