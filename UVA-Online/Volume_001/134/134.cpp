// 134 - Loglan-A Logical Language
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
 * 
 * Loglan is a synthetic speakable language designed to test some of the fundamental problems of linguistics,
such as the Sapir Whorf hypothesis. It is syntactically unambiguous, culturally neutral and
metaphysically parsimonious. What follows is a gross over-simplification of an already very small
grammar of some 200 rules.

 * Loglan sentences consist of a series of words and names, 
 * separated by spaces, 
 * and are terminated by a period (.). 
 * 
 * Loglan words all end with a vowel; names, which are derived extra-linguistically, 
 * end with a consonant. 
 * 
 * Loglan words are divided into two classes — little words which specify the structure
of a sentence, and predicates which have the form CCVCV or CVCCV where C represents a consonant
and V represents a vowel (see examples later).
 * 
 * 
A ⇒ a | e | i | o | u
MOD ⇒ ga | ge | gi | go | gu
BA ⇒ ba | be | bi | bo | bu
DA ⇒ da | de | di | do | du
LA ⇒ la | le | li | lo | lu
NAM ⇒ {all names}
PREDA ⇒ {all predicates}
< sentence > ⇒ < statement > | < predclaim >
< predclaim > ⇒ < predname > BA < preds > | DA < preds >
< preds > ⇒ < predstring > | < preds > A < predstring >
< predname > ⇒ LA < predstring > | NAM
< predstring > ⇒ PREDA | < predstring > PREDA
< statement > ⇒ < predname > < verbpred > < predname > | < predname > < verbpred >
< verbpred > ⇒ MOD < predstring >
 * 
 * 
 * ex>
 * 
 * la mutce bunbo mrenu bi ditca.
 * 
 * LA(la) <predicates>(mutce bunbo mrenu bi ditca.)
 * 
 * LA(la) <predicates>(mutce) <NAM>(bunbo) mrenu bi ditca.)
 * LA(la) <predicates>(mutce) <NAM>(bunbo) <predicates>(mrenu) bi ditca.)
 * LA(la) <predicates>(mutce) <NAM>(bunbo) <predicates>(mrenu) <BA>(bi) ditca.)
 * LA(la) <predicates>(mutce) <NAM>(bunbo) <predicates>(mrenu) <BA>(bi) <predicates>ditca.
 * 
 */
typedef enum { WORD_A, WORD_MOD, WORD_BA, WORD_DA, WORD_LA, WORD_NAM, WORD_PREDA, WORD_NONE } WORD_TYPE;
bool IsVowel(char c)
{
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
}
bool IsConsonant(char c)
{
    return !IsVowel(c);
}
bool IsWordMatch(char *str, int len , char c)
{
    if ( str == NULL ) return false;
    if ( len != 1 ) return false ;
    return ( str[0] == c );
}
bool IsWordMatchA(char *str, int len)
{
    if ( str == NULL ) return false;
    if ( len != 1 ) return false ;
    // A ⇒ a | e | i | o | u
    return IsVowel(str[0]);
}
bool IsWordMatchMOD(char *str, int len)
{
    if ( !IsWordMatch( str, len-1, 'g' ) ) return false;
    return IsWordMatchA(str+1, len-1);
}
bool IsWordMatchBA(char *str, int len)
{
    if ( !IsWordMatch( str, len-1, 'b' ) ) return false;
    return IsWordMatchA(str+1, len-1);
}
bool IsWordMatchDA(char *str, int len)
{
    if ( !IsWordMatch( str, len-1, 'd' ) ) return false;
    return IsWordMatchA(str+1, len-1);
}
bool IsWordMatchLA(char *str, int len)
{
    if ( !IsWordMatch( str, len-1, 'l' ) ) return false;
    return IsWordMatchA(str+1, len-1);
}
bool IsWordMatchNAM(char *str, int len)
{
    return ( len > 0 && IsConsonant(str[len-1]) );
}
bool IsWordMatchPREDA(char *str, int len)
{
    if ( len == 5 )
    {
        if ( IsConsonant(str[0]) && IsConsonant(str[1]) && IsVowel(str[2]) && IsConsonant(str[3]) && IsVowel(str[4]) ) 
            return true ;
        if ( IsConsonant(str[0]) && IsVowel(str[1]) && IsConsonant(str[2]) && IsConsonant(str[3]) && IsVowel(str[4]) )
            return true ;
    }
    return false;
}

WORD_TYPE GetWordType(char *str )
{
    int len = str == NULL ? 0 : strlen(str);
    if ( IsWordMatchA(str, len )) return WORD_A;
    if ( IsWordMatchMOD(str, len )) return WORD_MOD;
    if ( IsWordMatchBA(str, len )) return WORD_BA;
    if ( IsWordMatchDA(str, len )) return WORD_DA;
    if ( IsWordMatchLA(str, len )) return WORD_LA;
    if ( IsWordMatchNAM(str, len )) return WORD_NAM;
    if ( IsWordMatchPREDA(str, len )) return WORD_PREDA;
    
    return WORD_NONE;
}
const char *GetWordType(WORD_TYPE t )
{
    switch ( t )
    {
        case WORD_A : return "A";
        case WORD_MOD : return "MOD";
        case WORD_BA : return "BA";
        case WORD_DA : return "DA";
        case WORD_LA : return "LA";
        case WORD_NAM: return "NAM";
        case WORD_PREDA : return "PREDA";
    }
    return "NONE";
}
struct NODE
{
    WORD_TYPE type;
    NODE *next ;
};
NODE *addNode( NODE *root, WORD_TYPE type)
{
    NODE *new_node = new NODE;
    new_node->type = type;
    new_node->next = NULL ;    
    
    if ( root != NULL )
        root->next = new_node ;
    return new_node ;
}
void delNode( NODE *root)
{
    NODE * curr, * next;
    
    for ( curr = root, next = curr ; curr != NULL ; curr = next)
    {
        next = curr->next ;
        delete(curr);
    }
}

NODE * SkipPredString(NODE *root)
{
    while ( root != NULL && root->type == WORD_PREDA )
        root = root->next ;
    return root;
}
bool IsPredString(NODE *root)
{
    return ( root != NULL && root->type == WORD_PREDA );
}

NODE * SkipVerbPred(NODE *root)
{ 
    if ( root == NULL ) return NULL;
    
    if ( root->type == WORD_MOD ) root = root->next;
    return SkipPredString(root);
}
bool IsVerbPred(NODE *root)
{ 
    return root != NULL && root->type == WORD_MOD && IsPredString(root->next);
}

NODE * SkipPredName(NODE *root)
{
    if ( root == NULL ) return NULL ;
    if ( root->type == WORD_LA ) 
    {
        root = root->next;
        return SkipPredString(root);
    }
    else if ( root->type == WORD_NAM )
    {
        return root->next;
    }
    return NULL ;
}
bool IsPredName(NODE *root)
{
    return root != NULL && ( root->type == WORD_NAM || ( root->type == WORD_LA && IsPredString(root->next )) );
}

NODE * SkipPreds(NODE *root)
{    
    if ( !IsPredString(root) )
        return NULL ;

    int nPreda = 0 ;
    int nAPreds = 0 ;
    NODE *curr;
    
    for ( curr = root ; curr != NULL ; curr = curr->next )
    {
        if ( curr->type == WORD_PREDA ) 
            nPreda ++;
        else
            break;
    }

    for ( ; curr != NULL && curr->next != NULL ; curr = curr->next )
    {
        if ( curr->type == WORD_A && curr->next->type == WORD_PREDA ) 
        {
            nPreda ++;
            curr = curr->next; // skip A
            while ( curr->next && curr->next->type == WORD_PREDA )
                curr = curr->next; 
        }
        else
            break;
    }
                
    return curr;
}

bool IsPreds(NODE *root )
{
    if ( root == NULL ) return false;
    
    if ( IsPredString(root) )
    {
        return true ;
    }
    return false;
}
bool IsStatement(NODE *root)
{
    if ( !IsPredName(root) ) return false;
    root = SkipPredName(root);
    if ( ! IsVerbPred(root) ) return false;
    root = SkipVerbPred(root);
    if ( root == NULL )
        return true ;
    if ( ! IsPredName(root) ) return false;
    root = SkipPredName(root);
    if ( root == NULL )
        return true ;

    return false;
}

bool IsPredClaim(NODE *root)
{
    if ( root->type == WORD_DA )
    {
        root = root->next;
        
        if (!IsPreds(root)) return false;
        root = SkipPreds(root);
        if ( root != NULL ) return false;
        return true ;
    }
    else if ( IsPredName(root) )
    {
        root = SkipPredName(root);
        if ( root == NULL || root->type != WORD_BA ) return false;
        root = root->next;
        if (!IsPreds(root)) return false;
        root = SkipPreds(root);
        if ( root != NULL ) return false;
        return true ;
    }
    else
        return false;
}

bool IsSentence(NODE *root)
{
    return ( IsPredClaim(root) || IsStatement(root ) );
}

void process(FILE *fp)
{
    char word[1024]={0,};
    NODE root;
    NODE *curr = &root;
    
    while ( fscanf(fp, "%s ", word) == 1 && strcmp(word, "#"))
    {
        int len = strlen(word);
        if ( word[len-1] == '.' ) 
        {
            word[len-1]=0x00, len--;        
            curr = addNode( curr, GetWordType(word) );
           
            if ( IsSentence(root.next) ) 
                printf("Good\n");
            else
                printf("Bad!\n");
            delNode(root.next);
            root.next = NULL ;
            curr = &root;
        }
        else
        {
            curr = addNode( curr, GetWordType(word) );
        }
    }
}
int main()
{
#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif
    process(fp);

#ifdef ONLINE_JUDGE
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}