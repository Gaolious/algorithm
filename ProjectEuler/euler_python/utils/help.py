import math
from typing import List


def factorial(n: int) -> int:
    ret = 1
    for i in range(1, n+1):
        ret *= i
    return ret


def gcd(a: int, b: int) -> int:
    while b > 0:
        a, b = b, a % b

    return a


def gcd3(a: int, b: int, c: int) -> int:
    return gcd(a, gcd(b, c))


def get_digits(a: int) -> int:
    if a < 0:
        a = -a

    cnt = 0
    while a > 0 :
        cnt += 1
        a //= 10
    return cnt

def number_to_list(n:int):
    """
    1231 => { 1:2, 2:1, 3:1 }
    :param n:
    :return:
    """
    ret = [0]*10

    while n > 0:
        ret[n % 10] += 1
        n //= 10

    return ret

class Prime(object):
    n: int
    _is_prime: bytearray
    number: List[int]
    def __init__(self, n):
        self.n = n

        self._is_prime = bytearray(n // 8 + 1)
        self.number = []

    def _set_false(self, n):
        idx = n // 8
        bit = 0x01 << (n % 8)
        self._is_prime[idx] |= bit

    def _is_set(self, n):
        idx = n // 8
        bit = 0x01 << (n % 8)
        return True if self._is_prime[idx] & bit > 0 else 0

    def sieve(self):
        for i in range(2, 2+1):
            self.number.append(i)

            for k in range(i*2, self.n+1, i):
                self._set_false(k)

        for i in range(3, self.n+1, 2):
            if self._is_set(i): continue

            self.number.append(i)
            for k in range(i*2, self.n+1, i):
                self._set_false(k)

    def factorization(self, n):
        idx = 0
        ret = {}
        if not self._is_set(n):
            return {n: 1}

        while n > 1 and idx < len(self.number):
            while n % self.number[idx] == 0:
                n //= self.number[idx]
                if self.number[idx] not in ret:
                    ret.update({
                        self.number[idx]: 1
                    })
                else:
                    ret[self.number[idx]] += 1

            idx += 1

        return ret

    def phi(self, n):
        fact = self.factorization(n)

        ret = n
        for p in fact:
            ret //= p
            ret *= (p-1)

        return ret

class Fraction(object):
    child: int
    parent: int

    def __init__(self, child: int, parent: int = 1):

        if parent < 0:
            self.child = -child
            self.parent = -parent
        else:
            self.child = child
            self.parent = parent

    def __eq__(self, other):
        if isinstance(other, Fraction):
            return self.child == other.child and self.parent == other.parent
        else:
            return self.__eq__(Fraction(other))

    def __add__(self, other):
        if isinstance(other, Fraction):
            parent = self.parent * other.parent
            child = self.child * other.parent + self.parent * other.child
            g = gcd(abs(parent), abs(child))

            t = Fraction(child // g, parent // g)
            return t
        else:
            return self + Fraction(other)

    def __sub__(self, other):
        if isinstance(other, Fraction):
            parent = self.parent * other.parent
            child = self.child * other.parent - self.parent * other.child

            g = gcd(abs(parent), abs(child))
            t = Fraction(child // g, parent // g)
            return t
        else:
            return self - Fraction(other)

    def __mul__(self, other):
        if isinstance(other, Fraction):
            parent = self.parent * other.parent
            child = self.child * other.child

            g = gcd(abs(parent), abs(child))
            t = Fraction(child // g, parent // g)
            return t
        else:
            return self * Fraction(other)

    def __truediv__(self, other):
        if isinstance(other, Fraction):
            parent = self.parent * other.child
            child = self.child * other.parent

            g = gcd(abs(parent), abs(child))
            t = Fraction(child // g, parent // g)
            return t
        else:
            return self / Fraction(other)

    def __abs__(self):
        if self.child < 0:
            return Fraction(-self.child, self.parent)
        else:
            return self

    def __str__(self):
        s = ''
        if self.child == 0:
            return '0'
        if self.parent == 1:
            return str(self.child)

        return f'{self.child}/{self.parent}'

    def __repr__(self):
        return self.__str__()

    def asNum(self):
        if self.child == 0:
            return 0
        elif self.parent == 1:
            return self.child
        else:
            return self.child / self.parent

    @property
    def len_child(self):
        return get_digits(self.child)

    @property
    def len_parent(self):
        return get_digits(self.parent)


class ContinuedFraction(object):
    """
        b * √(c) + d
        --------------
              e
    """
    b: int
    c: int
    d: int
    e: int

    def __init__(self, b=1, c=1, d=0, e=1):
        self.b = b
        self.c = c
        self.d = d
        self.e = e

    def extract(self):
        inSquareRoot = self.b * self.b * self.c

        maxA = int(math.sqrt(inSquareRoot))

        a = (self.d + maxA) // self.e
        """
            1 * sqrt(23) + 4 
            -----------------
                    7
        """

        """
                 b * sqrt(c) + d' 
            a + -------------------------
                          e

                          1
            a + -----------------------------------------------
                           e * (b * sqrt(c) - d')
                  -----------------------------------------
                   (b * sqrt(c) + d') * (b * sqrt(c) - d')
        """
        new_d = self.d - self.e * a
        new_e = self.b * self.b * self.c - new_d * new_d
        new_b = self.e * self.b
        new_d = -self.e * new_d

        m = gcd3(new_b, new_d, new_e)

        return a, ContinuedFraction(b=new_b // m, c=self.c, d=new_d // m, e=new_e // m)

    def __eq__(self, other):
        if other.b != self.b:
            return False
        if other.c != self.c:
            return False
        if other.d != self.d:
            return False
        if other.e != self.e:
            return False

        return True


def GetFractionByContinuedListA(list_a: List[int]):
    """
        cf = ContinuedFraction(c=2)
        list_a = []
        for i in range(100):
            a, cf = cf.extract()
            list_a.append(a)

            ret = GetFractionByContinuedListA(list_a)
            print("{} : {}".format(ret, ret.asNum()))

        1 : 1
        3/2 : 1.5
        7/5 : 1.4
        17/12 : 1.4166666666666667
        41/29 : 1.4137931034482758
        99/70 : 1.4142857142857144
        239/169 : 1.4142011834319526
        577/408 : 1.4142156862745099
        1393/985 : 1.4142131979695431
        3363/2378 : 1.4142136248948696
        8119/5741 : 1.4142135516460548
        19601/13860 : 1.4142135642135643
        47321/33461 : 1.414213562057320

    :param list_a:
    :return:
    """
    ret = Fraction(child=list_a[-1], parent=1)

    for i in range(len(list_a)-2, -1, -1):
        ret = Fraction(child=ret.parent, parent=ret.child) + list_a[i]
    return ret