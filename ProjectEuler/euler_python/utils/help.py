
def gcd(a: int, b: int) -> int:
    while b > 0:
        a, b = b, a % b

    return a

def get_digits(a: int) -> int:
    if a < 0:
        a = -a

    cnt = 0
    while a > 0 :
        cnt += 1
        a //= 10
    return cnt


class Number(object):
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
        if isinstance(other, Number):
            return self.child == other.child and self.parent == other.parent
        else:
            return self.__eq__(Number(other))

    def __add__(self, other):
        if isinstance(other, Number):
            parent = self.parent * other.parent
            child = self.child * other.parent + self.parent * other.child
            g = gcd(abs(parent), abs(child))

            t = Number(child // g, parent // g)
            return t
        else:
            return self + Number(other)

    def __sub__(self, other):
        if isinstance(other, Number):
            parent = self.parent * other.parent
            child = self.child * other.parent - self.parent * other.child

            g = gcd(abs(parent), abs(child))
            t = Number(child // g, parent // g)
            return t
        else:
            return self - Number(other)

    def __mul__(self, other):
        if isinstance(other, Number):
            parent = self.parent * other.parent
            child = self.child * other.child

            g = gcd(abs(parent), abs(child))
            t = Number(child // g, parent // g)
            return t
        else:
            return self * Number(other)

    def __truediv__(self, other):
        if isinstance(other, Number):
            parent = self.parent * other.child
            child = self.child * other.parent

            g = gcd(abs(parent), abs(child))
            t = Number(child // g, parent // g)
            return t
        else:
            return self / Number(other)

    def __abs__(self):
        if self.child < 0:
            return Number( -self.child, self.parent)
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

