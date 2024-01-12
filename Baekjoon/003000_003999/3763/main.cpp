#include <bits/stdc++.h>

#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;
namespace DLX {
    struct Node {
        int row;
        int count;
        Node *column;
        Node *left, *right, *up, *down ;

        void cover() {
            Node *i, *j ;
            this->right->left = this->left;
            this->left->right = this->right;
            for (i = this->down ; i != this ; i = i->down) {
                for (j = i->right ; j != i ; j = j->right) {
                    j->down->up = j->up;
                    j->up->down = j->down;
                    j->column->count --;
                }
            }
        }
        void uncover() {
            Node *i, *j ;
            for (i = this->up ; i != this ; i = i->up) {
                for (j = i->left ; j != i ; j = j->left) {
                    j->down->up = j;
                    j->up->down = j;
                    j->column->count ++;
                }
            }
            this->right->left = this->left;
            this->left->right = this->right;
        }
    };

}

void process()
{
    int y, x , k;
    char c ;

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


