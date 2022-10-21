#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define BASE 3
#define CHAR_OFFSET '1'
#define CHAR_EMPTY '0'
#define SPACE true

const int BASE_2 = BASE * BASE;
const int BASE_4 = BASE_2 * BASE_2;

typedef struct node {
    int row;
    int size;

    node* column;

    node* up;
    node* down;
    node* right;
    node* left;
} node;

typedef struct {
    int x;
    int y;
    int value;
} point;

node* head;
node* columns[BASE_4 * 4];
int columnCount = BASE_4 * 4;

int sparseMatrix[BASE_4 * BASE_2][4];
int rows;
point points[BASE_4 * BASE_2];

void init() {
    // initialize columns
    // link each columns
    for (int i = 0; i < columnCount; i++) {
        columns[i] = new node;
        columns[i]->size = 0;
    }

    for (int i = 0; i < columnCount; i++) {
        columns[i]->right = columns[(i + 1) % columnCount];
        columns[i]->right->left = columns[i];

        columns[i]->up = columns[i];
        columns[i]->down = columns[i];
    }

    head = new node;
    head->right = columns[0];
    head->left = head->right->left;
    head->right->left = head;
    head->left->right = head;

    // make dancing links
    for (int row = 0; row < rows; row++) {
        node* previous = nullptr;
        node* current = nullptr;

        for (int col : sparseMatrix[row]) {
            current = new node;
            current->row = row;

            // link with column
            current->column = columns[col];
            current->column->size++;

            // link with bottom node
            current->up = columns[col]->up;
            current->down = columns[col];
            columns[col]->up->down = current;
            columns[col]->up = current;

            // link with left and right
            if (previous == nullptr) {
                previous = current;
                previous->right = current;
            }
            current->right = previous->right;
            current->left = previous;
            previous->right->left = current;
            previous->right = current;

            previous = current;
        }
    }

    // filter 0 sized column
    int columns = 0;
    vector<int> singleSized;
    for (node* it = head->right; it != head; it = it->right) {
        if (it->size == 0) {
            it->left->right = it->right;
            it->right->left = it->left;
        }
        else {
            columns++;
        }
    }

#ifdef DEBUG
    cout << "ROWS=" << rows << "\n";
	cout << "COLUMNS=" << columns << "\n";
#endif
}

void cover(node* column) {
    column->left->right = column->right;
    column->right->left = column->left;
    for (node* it = column->down; it != column; it = it->down) {
        for (node* jt = it->right; jt != it; jt = jt->right) {
            jt->up->down = jt->down;
            jt->down->up = jt->up;
            jt->column->size--;
        }
    }
}

void uncover(node* column) {
    for (node* it = column->down; it != column; it = it->down) {
        for (node* jt = it->right; jt != it; jt = jt->right) {
            jt->up->down = jt;
            jt->down->up = jt;
            jt->column->size++;
        }
    }
    column->left->right = column;
    column->right->left = column;
}

char table[BASE_2][BASE_2];

bool horizontal[BASE_2][BASE_2];
bool vertical[BASE_2][BASE_2];
bool boxed[BASE][BASE][BASE_2];

bool search() {
    if (head->right == head) return true;

    // select a column which has lowest size
    node* selected = head->right;
    int lowest = selected->size;
    for (node* it = selected; it != head; it = it->right) {
        if (it->size == 0) return false;

        if (it->size < lowest) {
            lowest = it->size;
            selected = it;
        }
    }

    // cover the selected column
    cover(selected);

    for (node* it = selected->down; it != selected; it = it->down) {
        int x = points[it->row].x;
        int y = points[it->row].y;
        int value = points[it->row].value;

        for (node* jt = it->right; jt != it; jt = jt->right) {
            cover(jt->column);
        }

        if (search()) {
            table[points[it->row].y][points[it->row].x] = points[it->row].value;
            return true;
        }

        for (node* jt = it->left; jt != it; jt = jt->left) {
            uncover(jt->column);
        }
    }

    // uncover, go back and try another
    uncover(selected);

    return false;
}

void sudoku() {
    char ch;
    const char EMPTY = -1;

    for (int y = 0; y < BASE_2; y++) {
        for (int x = 0; x < BASE_2; x++) {
            cin >> ch;
            if (ch == CHAR_EMPTY) {
                table[y][x] = EMPTY;
                continue;
            }

            int num = ch - CHAR_OFFSET;

            horizontal[x][num] = true;
            vertical[y][num] = true;
            boxed[y / BASE][x / BASE][num] = true;

            table[y][x] = num;
        }
    }

    for (int y = 0; y < BASE_2; y++) {
        for (int x = 0; x < BASE_2; x++) {
            if (table[y][x] != EMPTY) continue;

            for (int i = 0; i < BASE_2; i++) {
                if (
                        horizontal[x][i]
                        || vertical[y][i]
                        || boxed[y / BASE][x / BASE][i]
                        ) continue;

                // fill any number in (x, y)
                sparseMatrix[rows][0] = BASE_4 * 0 + (BASE_2 * y + x);

                // fill unique number (0-9) in same row
                sparseMatrix[rows][1] = BASE_4 * 1 + (BASE_2 * y + i);

                // fill unique number (0-9) in same column
                sparseMatrix[rows][2] = BASE_4 * 2 + (BASE_2 * x + i);

                // fill unique number (0-9) in boxed
                sparseMatrix[rows][3] = BASE_4 * 3 + (BASE_2 * (BASE * (y / BASE) + (x / BASE)) + i);

                points[rows] = { x, y, i };

                rows++;
            }
        }
    }

    init();

    search();

    char out;
    for (int y = 0; y < BASE_2; y++) {
        for (int x = 0; x < BASE_2; x++) {
            out = table[y][x] + CHAR_OFFSET;

            cout << out;

            if (SPACE) cout << " ";
        }
        cout << "\n";
    }
}

void process() {
    fastio;
    sudoku();
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


