import pytest

from utils.help import gcd, get_digits, ContinuedFraction, Prime


@pytest.mark.parametrize(
    'a, b, expected', [
        (1, 1, 1),
        (2, 3, 1),
        (3, 4, 1),
        (4, 2, 2),
        (2, 4, 2),
    ]
)
def test_gcd(a, b, expected):
    assert gcd(a, b) == expected


@pytest.mark.parametrize(
    'a, expected', [
        (1, 1),
        (2, 1),
        (3, 1),
        (4, 1),
        (10, 2),
        (99, 2),
        (100, 3),
        (999, 3),
    ]
)
def test_get_digits(a, expected):
    assert get_digits(a) == expected


@pytest.mark.parametrize(
    'b, c, d, e, expected_a', [
        (1, 23, 0, 1, 4),
        (1, 23, 4, 7, 1),
        (1, 23, -3, 7, 3),
        (1, 23, -3, 2, 1),
        (1, 23, -4, 7, 8),
    ]
)
def test_continued_fraction(b, c, d, e, expected_a):
    cf = ContinuedFraction(b=b, c=c, d=d, e=e)
    assert cf.extract() == expected_a

def test_prime():
    P = Prime (100000)
    P.sieve()
    assert P.phi(87109) == 79180